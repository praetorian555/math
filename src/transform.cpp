#include "math/transform.h"

#include <cassert>
#include <cmath>

#include "math/normal3.h"
#include "math/point4.h"

math::Transform::Transform(const Array2D<float, 4, 4>& Mat)
    : m_Matrix(Mat), m_MatrixInverse(m_Matrix.Inverse())
{
}

math::Transform::Transform(const math::Matrix4x4& Mat)
    : m_Matrix(Mat), m_MatrixInverse(m_Matrix.Inverse())
{
}

math::Transform::Transform(const math::Matrix4x4& Mat, const math::Matrix4x4& InvMat)
    : m_Matrix(Mat), m_MatrixInverse(InvMat)
{
}

math::Transform& math::Transform::operator=(const Matrix4x4& Mat)
{
    m_Matrix = Mat;
    m_MatrixInverse = Mat.Inverse();
    return *this;
}

math::Transform math::Inverse(const Transform& T)
{
    return {T.m_MatrixInverse, T.m_Matrix};
}

math::Transform math::Transpose(const Transform& T)
{
    return {T.m_Matrix.Transpose(), T.m_MatrixInverse.Transpose()};
}

bool math::Transform::operator==(const Transform& Other) const
{
    return (m_Matrix == Other.m_Matrix) && (m_MatrixInverse == Other.m_MatrixInverse);
}

bool math::Transform::operator!=(const Transform& Other) const
{
    return !(*this == Other);
}

bool math::Transform::IsIdentity() const
{
    for (int Row = 0; Row < 4; Row++)
    {
        for (int Column = 0; Column < 4; Column++)
        {
            if (Row == Column)
            {
                if (m_Matrix.Data[Row][Column] != 1.0f)
                {
                    return false;
                }
            }
            else
            {
                if (m_Matrix.Data[Row][Column] != 0.0f)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

static constexpr bool NotOne(float X)
{
    constexpr float kLowBound = 0.999f;
    constexpr float kHighBound = 1.001f;
    return (X < kLowBound) || (X > kHighBound);
}

bool math::Transform::HasScale() const
{
    const float LengthX2 = (*this)(Vector3(1, 0, 0)).LengthSquared();
    const float LengthY2 = (*this)(Vector3(0, 1, 0)).LengthSquared();
    const float LengthZ2 = (*this)(Vector3(0, 0, 1)).LengthSquared();
    return (NotOne(LengthX2) || NotOne(LengthY2) || NotOne(LengthZ2));
}

math::Transform math::Transform::operator*(const Transform& Other) const
{
    const math::Matrix4x4 Mat = Multiply(m_Matrix, Other.m_Matrix);
    const math::Matrix4x4 MatInv = Multiply(Other.m_MatrixInverse, m_MatrixInverse);

    return {Mat, MatInv};
}

math::Transform math::Translate(const Vector3& Delta)
{
    // clang-format off
    const math::Matrix4x4 Mat(
        1, 0, 0, Delta.X,
        0, 1, 0, Delta.Y,
        0, 0, 1, Delta.Z,
        0, 0, 0,       1
    );

    const math::Matrix4x4 MatInv(
        1, 0, 0, -Delta.X,
        0, 1, 0, -Delta.Y,
        0, 0, 1, -Delta.Z,
        0, 0, 0,        1
    );
    // clang-format on

    return {Mat, MatInv};
}

math::Transform math::Scale(float X, float Y, float Z)
{
    // clang-format off
    const math::Matrix4x4 Mat(
        X, 0, 0, 0,
        0, Y, 0, 0,
        0, 0, Z, 0,
        0, 0, 0, 1
    );

    const math::Matrix4x4 MatInv(
        1 / X,     0,     0, 0,
            0, 1 / Y,     0, 0,
            0,     0, 1 / Z, 0,
            0,     0,     0, 1
    );
    // clang-format on

    return {Mat, MatInv};
}

math::Transform math::RotateX(float Theta)
{
    const float SinTheta = std::sin(math::Radians(Theta));
    const float CosTheta = std::cos(math::Radians(Theta));

    // clang-format off
    const math::Matrix4x4 Mat(
        1,        0,         0, 0, 
        0, CosTheta, -SinTheta, 0,
        0, SinTheta,  CosTheta, 0,
        0,        0,         0, 1);
    // clang-format on

    return {Mat, Mat.Transpose()};
}

math::Transform math::RotateY(float Theta)
{
    const float SinTheta = std::sin(math::Radians(Theta));
    const float CosTheta = std::cos(math::Radians(Theta));

    // clang-format off
    const math::Matrix4x4 Mat(
         CosTheta, 0, SinTheta, 0, 
                0, 1,        0, 0,
        -SinTheta, 0, CosTheta, 0,
                0, 0,        0, 1);
    // clang-format on

    return {Mat, Mat.Transpose()};
}

math::Transform math::RotateZ(float Theta)
{
    const float SinTheta = std::sin(math::Radians(Theta));
    const float CosTheta = std::cos(math::Radians(Theta));

    // clang-format off
    const math::Matrix4x4 Mat(
        CosTheta, -SinTheta, 0, 0, 
        SinTheta,  CosTheta, 0, 0,
               0,         0, 1, 0,
               0,         0, 0, 1);
    // clang-format on

    return {Mat, Mat.Transpose()};
}

math::Transform math::Rotate(float Theta, const Vector3& Axis)
{
    const Vector3 NormAxis = Normalize(Axis);
    const float SinTheta = std::sin(math::Radians(Theta));
    const float CosTheta = std::cos(math::Radians(Theta));

    // Compute rotation of first basis vector
    math::Matrix4x4 Mat;
    Mat.Data[0][0] = NormAxis.X * NormAxis.X + (1 - NormAxis.X * NormAxis.X) * CosTheta;
    Mat.Data[0][1] = NormAxis.X * NormAxis.Y * (1 - CosTheta) - NormAxis.Z * SinTheta;
    Mat.Data[0][2] = NormAxis.X * NormAxis.Z * (1 - CosTheta) + NormAxis.Y * SinTheta;
    Mat.Data[0][3] = 0;

    // Compute rotations of second and third basis vectors
    Mat.Data[1][0] = NormAxis.X * NormAxis.Y * (1 - CosTheta) + NormAxis.Z * SinTheta;
    Mat.Data[1][1] = NormAxis.Y * NormAxis.Y + (1 - NormAxis.Y * NormAxis.Y) * CosTheta;
    Mat.Data[1][2] = NormAxis.Y * NormAxis.Z * (1 - CosTheta) - NormAxis.X * SinTheta;
    Mat.Data[1][3] = 0;

    Mat.Data[2][0] = NormAxis.X * NormAxis.Z * (1 - CosTheta) - NormAxis.Y * SinTheta;
    Mat.Data[2][1] = NormAxis.Y * NormAxis.Z * (1 - CosTheta) + NormAxis.X * SinTheta;
    Mat.Data[2][2] = NormAxis.Z * NormAxis.Z + (1 - NormAxis.Z * NormAxis.Z) * CosTheta;
    Mat.Data[2][3] = 0;

    return {Mat, Mat.Transpose()};
}

math::Transform math::Rotate(math::Rotator Rotator)
{
    return RotateZ(Rotator.Pitch) * RotateY(Rotator.Yaw) * RotateX(Rotator.Roll);
}

math::Bounds3 math::Transform::operator()(const Bounds3& B) const
{
    // TODO(mkostic): Make this more efficient

    const Transform& M = *this;
    Bounds3 Ret(M(B.Min));
    Ret = Union(Ret, M(Point3(B.Max.X, B.Min.Y, B.Min.Z)));
    Ret = Union(Ret, M(Point3(B.Min.X, B.Max.Y, B.Min.Z)));
    Ret = Union(Ret, M(Point3(B.Min.X, B.Min.Y, B.Max.Z)));
    Ret = Union(Ret, M(Point3(B.Min.X, B.Max.Y, B.Max.Z)));
    Ret = Union(Ret, M(Point3(B.Max.X, B.Max.Y, B.Min.Z)));
    Ret = Union(Ret, M(Point3(B.Max.X, B.Min.Y, B.Max.Z)));
    Ret = Union(Ret, M(Point3(B.Max.X, B.Max.Y, B.Max.Z)));
    return Ret;
}

math::Vector3 math::Transform::operator()(const Vector3& Vec) const
{
    return {
        m_Matrix.Data[0][0] * Vec.X + m_Matrix.Data[0][1] * Vec.Y + m_Matrix.Data[0][2] * Vec.Z,
        m_Matrix.Data[1][0] * Vec.X + m_Matrix.Data[1][1] * Vec.Y + m_Matrix.Data[1][2] * Vec.Z,
        m_Matrix.Data[2][0] * Vec.X + m_Matrix.Data[2][1] * Vec.Y + m_Matrix.Data[2][2] * Vec.Z};
}

math::Point3 math::Transform::operator()(const Point3& P) const
{
    const float X = m_Matrix.Data[0][0] * P.X + m_Matrix.Data[0][1] * P.Y +
                    m_Matrix.Data[0][2] * P.Z + m_Matrix.Data[0][3];
    const float Y = m_Matrix.Data[1][0] * P.X + m_Matrix.Data[1][1] * P.Y +
                    m_Matrix.Data[1][2] * P.Z + m_Matrix.Data[1][3];
    const float Z = m_Matrix.Data[2][0] * P.X + m_Matrix.Data[2][1] * P.Y +
                    m_Matrix.Data[2][2] * P.Z + m_Matrix.Data[2][3];
    const float W = m_Matrix.Data[3][0] * P.X + m_Matrix.Data[3][1] * P.Y +
                    m_Matrix.Data[3][2] * P.Z + m_Matrix.Data[3][3];

    assert(W != 0);
    if (W == 1)
    {
        return {X, Y, Z};
    }

    return Point3(X, Y, Z) / W;
}

math::Point4 math::Transform::operator()(const Point4& P) const
{
    const float X = m_Matrix.Data[0][0] * P.X + m_Matrix.Data[0][1] * P.Y +
                    m_Matrix.Data[0][2] * P.Z + m_Matrix.Data[0][3];
    const float Y = m_Matrix.Data[1][0] * P.X + m_Matrix.Data[1][1] * P.Y +
                    m_Matrix.Data[1][2] * P.Z + m_Matrix.Data[1][3];
    const float Z = m_Matrix.Data[2][0] * P.X + m_Matrix.Data[2][1] * P.Y +
                    m_Matrix.Data[2][2] * P.Z + m_Matrix.Data[2][3];
    const float W = m_Matrix.Data[3][0] * P.X + m_Matrix.Data[3][1] * P.Y +
                    m_Matrix.Data[3][2] * P.Z + m_Matrix.Data[3][3];

    assert(W != 0);
    return {X, Y, Z, W};
}

inline math::Normal3 math::Transform::operator()(const Normal3& N) const
{
    return {m_MatrixInverse.Data[0][0] * N.X + m_MatrixInverse.Data[1][0] * N.Y +
                m_MatrixInverse.Data[2][0] * N.Z,
            m_MatrixInverse.Data[0][1] * N.X + m_MatrixInverse.Data[1][1] * N.Y +
                m_MatrixInverse.Data[2][1] * N.Z,
            m_MatrixInverse.Data[0][2] * N.X + m_MatrixInverse.Data[1][2] * N.Y +
                m_MatrixInverse.Data[2][2] * N.Z};
}
