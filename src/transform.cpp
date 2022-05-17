#include "math/transform.h"

math::Transform::Transform(const float mat[4][4])
    : m_Matrix(mat), m_MatrixInverse(m_Matrix.Inverse())
{
}

math::Transform::Transform(const math::Matrix4x4& mat)
    : m_Matrix(mat), m_MatrixInverse(m_Matrix.Inverse())
{
}

math::Transform::Transform(const math::Matrix4x4& mat, const math::Matrix4x4& invMat)
    : m_Matrix(mat), m_MatrixInverse(invMat)
{
}

math::Transform& math::Transform::operator=(const Matrix4x4& Matrix)
{
    m_Matrix = Matrix;
    m_MatrixInverse = Matrix.Inverse();
    return *this;
}

math::Transform math::Inverse(const Transform& t)
{
    return Transform(t.m_MatrixInverse, t.m_Matrix);
}

math::Transform math::Transpose(const Transform& t)
{
    return Transform(t.m_Matrix.Transpose(), t.m_MatrixInverse.Transpose());
}

bool math::Transform::operator==(const Transform& other) const
{
    return m_Matrix == other.m_Matrix && other.m_MatrixInverse == other.m_MatrixInverse;
}

bool math::Transform::operator!=(const Transform& other) const
{
    return !(*this == other);
}

bool math::Transform::IsIdentity() const
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                if (m_Matrix.Data[i][j] != 1.0f)
                {
                    return false;
                }
            }
            else
            {
                if (m_Matrix.Data[i][j] != 0.0f)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool math::Transform::HasScale() const
{
    float la2 = (*this)(Vector3<float>(1, 0, 0)).LengthSquared();
    float lb2 = (*this)(Vector3<float>(0, 1, 0)).LengthSquared();
    float lc2 = (*this)(Vector3<float>(0, 0, 1)).LengthSquared();
#define NOT_ONE(x) ((x) < .999f || (x) > 1.001f)
    return (NOT_ONE(la2) || NOT_ONE(lb2) || NOT_ONE(lc2));
#undef NOT_ONE
}

math::Transform math::Transform::operator*(const Transform& other) const
{
    math::Matrix4x4 m = Multiply(m_Matrix, other.m_Matrix);
    math::Matrix4x4 minv = Multiply(other.m_MatrixInverse, m_MatrixInverse);

    return Transform(m, minv);
}

math::Transform math::Translate(const Vector3<float>& delta)
{
    // clang-format off
    math::Matrix4x4 m(
        1, 0, 0, delta.X,
        0, 1, 0, delta.Y,
        0, 0, 1, delta.Z,
        0, 0, 0,       1
    );

    math::Matrix4x4 minv(
        1, 0, 0, -delta.X,
        0, 1, 0, -delta.Y,
        0, 0, 1, -delta.Z,
        0, 0, 0,        1
    );
    // clang-format on

    return Transform(m, minv);
}

math::Transform math::Scale(float x, float y, float z)
{
    // clang-format off
    math::Matrix4x4 m(
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    );

    math::Matrix4x4 minv(
        1 / x,     0,     0, 0,
            0, 1 / y,     0, 0,
            0,     0, 1 / z, 0,
            0,     0,     0, 1
    );
    // clang-format on

    return Transform(m, minv);
}

math::Transform math::RotateX(float theta)
{
    float sinTheta = std::sin(math::Radians(theta));
    float cosTheta = std::cos(math::Radians(theta));

    // clang-format off
    math::Matrix4x4 m(
        1,        0,         0, 0, 
        0, cosTheta, -sinTheta, 0,
        0, sinTheta,  cosTheta, 0,
        0,        0,         0, 1);
    // clang-format on

    return Transform(m, m.Transpose());
}

math::Transform math::RotateY(float theta)
{
    float sinTheta = std::sin(math::Radians(theta));
    float cosTheta = std::cos(math::Radians(theta));

    // clang-format off
    math::Matrix4x4 m(
         cosTheta, 0, sinTheta, 0, 
                0, 1,        0, 0,
        -sinTheta, 0, cosTheta, 0,
                0, 0,        0, 1);
    // clang-format on

    return Transform(m, m.Transpose());
}

math::Transform math::RotateZ(float theta)
{
    float sinTheta = std::sin(math::Radians(theta));
    float cosTheta = std::cos(math::Radians(theta));

    // clang-format off
    math::Matrix4x4 m(
        cosTheta, -sinTheta, 0, 0, 
        sinTheta,  cosTheta, 0, 0,
               0,         0, 1, 0,
               0,         0, 0, 1);
    // clang-format on

    return Transform(m, m.Transpose());
}

math::Transform math::Rotate(float theta, const Vector3<float>& axis)
{
    Vector3<float> a = Normalize(axis);
    float sinTheta = std::sin(math::Radians(theta));
    float cosTheta = std::cos(math::Radians(theta));
    math::Matrix4x4 m;

    // Compute rotation of first basis vector
    m.Data[0][0] = a.X * a.X + (1 - a.X * a.X) * cosTheta;
    m.Data[0][1] = a.X * a.Y * (1 - cosTheta) - a.Z * sinTheta;
    m.Data[0][2] = a.X * a.Z * (1 - cosTheta) + a.Y * sinTheta;
    m.Data[0][3] = 0;

    // Compute rotations of second and third basis vectors
    m.Data[1][0] = a.X * a.Y * (1 - cosTheta) + a.Z * sinTheta;
    m.Data[1][1] = a.Y * a.Y + (1 - a.Y * a.Y) * cosTheta;
    m.Data[1][2] = a.Y * a.Z * (1 - cosTheta) - a.X * sinTheta;
    m.Data[1][3] = 0;

    m.Data[2][0] = a.X * a.Z * (1 - cosTheta) - a.Y * sinTheta;
    m.Data[2][1] = a.Y * a.Z * (1 - cosTheta) + a.X * sinTheta;
    m.Data[2][2] = a.Z * a.Z + (1 - a.Z * a.Z) * cosTheta;
    m.Data[2][3] = 0;

    return Transform(m, m.Transpose());
}

math::Transform math::Rotate(math::Rotator Rotator)
{
    return RotateY(Rotator.Yaw) * RotateZ(Rotator.Pitch) * RotateX(Rotator.Roll);
}

math::Bounds3<float> math::Transform::operator()(const Bounds3<float>& b) const
{
    // TODO(mkostic): Make this more efficient

    const Transform& M = *this;
    Bounds3<float> ret(M(Point3<float>(b.Min.X, b.Min.Y, b.Min.Z)));
    ret = Union(ret, M(Point3<float>(b.Max.X, b.Min.Y, b.Min.Z)));
    ret = Union(ret, M(Point3<float>(b.Min.X, b.Max.Y, b.Min.Z)));
    ret = Union(ret, M(Point3<float>(b.Min.X, b.Min.Y, b.Max.Z)));
    ret = Union(ret, M(Point3<float>(b.Min.X, b.Max.Y, b.Max.Z)));
    ret = Union(ret, M(Point3<float>(b.Max.X, b.Max.Y, b.Min.Z)));
    ret = Union(ret, M(Point3<float>(b.Max.X, b.Min.Y, b.Max.Z)));
    ret = Union(ret, M(Point3<float>(b.Max.X, b.Max.Y, b.Max.Z)));
    return ret;
}
