//#include "math/transform.h"
//
//#include <cassert>
//
//#include "math/normal3.h"
//#include "math/point4.h"
//#include "math/quaternion.h"
//
//math::Transform::Transform(const Math::Array2D<real, 4, 4>& Mat)
//    : m_Matrix(Mat), m_MatrixInverse(Math::Inverse(m_Matrix))
//{
//}
//
//math::Transform::Transform(const Math::Matrix4x4<float>& Mat)
//    : m_Matrix(Mat), m_MatrixInverse(Math::Inverse(m_Matrix))
//{
//}
//
//math::Transform::Transform(const Math::Matrix4x4<float>& Mat, const Math::Matrix4x4<float>& InvMat)
//    : m_Matrix(Mat), m_MatrixInverse(InvMat)
//{
//}
//
//math::Transform& math::Transform::operator=(const Math::Matrix4x4<float>& Mat)
//{
//    m_Matrix = Mat;
//    m_MatrixInverse = Math::Inverse(m_Matrix);
//    return *this;
//}
//
//math::Transform math::Inverse(const Transform& T)
//{
//    return {T.m_MatrixInverse, T.m_Matrix};
//}
//
//math::Transform math::Transpose(const Transform& T)
//{
//    return {Math::Transpose(T.m_Matrix), Math::Transpose(T.m_MatrixInverse)};
//}
//
//bool math::Transform::operator==(const Transform& Other) const
//{
//    return (m_Matrix == Other.m_Matrix) && (m_MatrixInverse == Other.m_MatrixInverse);
//}
//
//bool math::Transform::operator!=(const Transform& Other) const
//{
//    return !(*this == Other);
//}
//
//bool math::Transform::IsIdentity() const
//{
//    for (int Row = 0; Row < 4; Row++)
//    {
//        for (int Column = 0; Column < 4; Column++)
//        {
//            if (Row == Column)
//            {
//                if (m_Matrix.elements[Row][Column] != 1.0f)
//                {
//                    return false;
//                }
//            }
//            else
//            {
//                if (m_Matrix.elements[Row][Column] != 0.0f)
//                {
//                    return false;
//                }
//            }
//        }
//    }
//
//    return true;
//}
//
//static constexpr bool NotOne(math::real X)
//{
//    constexpr math::real k_low_bound = 0.999f;
//    constexpr math::real k_high_bound = 1.001f;
//    return (X < k_low_bound) || (X > k_high_bound);
//}
//
//bool math::Transform::HasScale() const
//{
//    const real LengthX2 = (*this)(Vector3(1, 0, 0)).LengthSquared();
//    const real LengthY2 = (*this)(Vector3(0, 1, 0)).LengthSquared();
//    const real LengthZ2 = (*this)(Vector3(0, 0, 1)).LengthSquared();
//    return (NotOne(LengthX2) || NotOne(LengthY2) || NotOne(LengthZ2));
//}
//
//math::Transform math::Transform::operator*(const Transform& Other) const
//{
//    const Math::Matrix4x4<float> Mat = m_Matrix * Other.m_Matrix;
//    const Math::Matrix4x4<float> MatInv = Other.m_MatrixInverse * m_MatrixInverse;
//
//    return {Mat, MatInv};
//}
//
//math::Transform math::Translate(const Vector3& Delta)
//{
//    // clang-format off
//    const Math::Matrix4x4<float> Mat(
//        1, 0, 0, Delta.X,
//        0, 1, 0, Delta.Y,
//        0, 0, 1, Delta.Z,
//        0, 0, 0,       1
//    );
//
//    const Math::Matrix4x4<float> MatInv(
//        1, 0, 0, -Delta.X,
//        0, 1, 0, -Delta.Y,
//        0, 0, 1, -Delta.Z,
//        0, 0, 0,        1
//    );
//    // clang-format on
//
//    return {Mat, MatInv};
//}
//
//math::Transform math::Translate(const math::Point3& Delta)
//{
//    // clang-format off
//    const Math::Matrix4x4<float> Mat(
//        1, 0, 0, Delta.X,
//        0, 1, 0, Delta.Y,
//        0, 0, 1, Delta.Z,
//        0, 0, 0,       1
//    );
//
//    const Math::Matrix4x4<float> MatInv(
//        1, 0, 0, -Delta.X,
//        0, 1, 0, -Delta.Y,
//        0, 0, 1, -Delta.Z,
//        0, 0, 0,        1
//    );
//    // clang-format on
//
//    return {Mat, MatInv};
//}
//
//math::Transform math::Scale(real X, real Y, real Z)
//{
//    // clang-format off
//    const Math::Matrix4x4<float> Mat(
//        X, 0, 0, 0,
//        0, Y, 0, 0,
//        0, 0, Z, 0,
//        0, 0, 0, 1
//    );
//
//    const Math::Matrix4x4<float> MatInv(
//        1 / X,     0,     0, 0,
//            0, 1 / Y,     0, 0,
//            0,     0, 1 / Z, 0,
//            0,     0,     0, 1
//    );
//    // clang-format on
//
//    return {Mat, MatInv};
//}
//
//math::Transform math::Scale(math::real V)
//{
//    // clang-format off
//    const Math::Matrix4x4<float> Mat(
//        V, 0, 0, 0,
//        0, V, 0, 0,
//        0, 0, V, 0,
//        0, 0, 0, 1
//    );
//
//    const Math::Matrix4x4<float> MatInv(
//        1 / V,     0,     0, 0,
//            0, 1 / V,     0, 0,
//            0,     0, 1 / V, 0,
//            0,     0,     0, 1
//    );
//    // clang-format on
//
//    return {Mat, MatInv};
//}
//
//math::Transform math::RotateX(real ThetaDegrees)
//{
//    const real SinTheta = math::Sin(math::Radians(ThetaDegrees));
//    const real CosTheta = math::Cos(math::Radians(ThetaDegrees));
//
//    // clang-format off
//    const Math::Matrix4x4<float> Mat(
//        1,        0,         0, 0,
//        0, CosTheta, -SinTheta, 0,
//        0, SinTheta,  CosTheta, 0,
//        0,        0,         0, 1);
//    // clang-format on
//
//    return {Mat, Math::Transpose(Mat)};
//}
//
//math::Transform math::RotateY(real ThetaDegrees)
//{
//    const real SinTheta = math::Sin(math::Radians(ThetaDegrees));
//    const real CosTheta = math::Cos(math::Radians(ThetaDegrees));
//
//    // clang-format off
//    const Math::Matrix4x4<float> Mat(
//         CosTheta, 0, SinTheta, 0,
//                0, 1,        0, 0,
//        -SinTheta, 0, CosTheta, 0,
//                0, 0,        0, 1);
//    // clang-format on
//
//    return {Mat, Math::Transpose(Mat)};
//}
//
//math::Transform math::RotateZ(real ThetaDegrees)
//{
//    const real SinTheta = math::Sin(math::Radians(ThetaDegrees));
//    const real CosTheta = math::Cos(math::Radians(ThetaDegrees));
//
//    // clang-format off
//    const Math::Matrix4x4<float> Mat(
//        CosTheta, -SinTheta, 0, 0,
//        SinTheta,  CosTheta, 0, 0,
//               0,         0, 1, 0,
//               0,         0, 0, 1);
//    // clang-format on
//
//    return {Mat, Math::Transpose(Mat)};
//}
//
//math::Transform math::Rotate(real ThetaDegrees, const Vector3& Axis)
//{
//    const Vector3 NormAxis = Normalize(Axis);
//    const real SinTheta = math::Sin(math::Radians(ThetaDegrees));
//    const real CosTheta = math::Cos(math::Radians(ThetaDegrees));
//
//    // Compute rotation of first basis vector
//    Math::Matrix4x4<float> Mat;
//    Mat.elements[0][0] = NormAxis.X * NormAxis.X + (1 - NormAxis.X * NormAxis.X) * CosTheta;
//    Mat.elements[0][1] = NormAxis.X * NormAxis.Y * (1 - CosTheta) - NormAxis.Z * SinTheta;
//    Mat.elements[0][2] = NormAxis.X * NormAxis.Z * (1 - CosTheta) + NormAxis.Y * SinTheta;
//    Mat.elements[0][3] = 0;
//
//    // Compute rotations of second and third basis vectors
//    Mat.elements[1][0] = NormAxis.X * NormAxis.Y * (1 - CosTheta) + NormAxis.Z * SinTheta;
//    Mat.elements[1][1] = NormAxis.Y * NormAxis.Y + (1 - NormAxis.Y * NormAxis.Y) * CosTheta;
//    Mat.elements[1][2] = NormAxis.Y * NormAxis.Z * (1 - CosTheta) - NormAxis.X * SinTheta;
//    Mat.elements[1][3] = 0;
//
//    Mat.elements[2][0] = NormAxis.X * NormAxis.Z * (1 - CosTheta) - NormAxis.Y * SinTheta;
//    Mat.elements[2][1] = NormAxis.Y * NormAxis.Z * (1 - CosTheta) + NormAxis.X * SinTheta;
//    Mat.elements[2][2] = NormAxis.Z * NormAxis.Z + (1 - NormAxis.Z * NormAxis.Z) * CosTheta;
//    Mat.elements[2][3] = 0;
//
//    return {Mat, Math::Transpose(Mat)};
//}
//
//math::Transform math::Rotate(math::Rotator Rotator)
//{
//    return RotateZ(Rotator.Pitch) * RotateY(Rotator.Yaw) * RotateX(Rotator.Roll);
//}
//
//math::Transform math::RotateAndTranslate(math::Rotator Rotator, const math::Point3& Translation)
//{
//    return Translate(Translation) * Rotate(Rotator);
//}
//
//math::Transform math::RotateAndTranslate(math::Rotator Rotator, const math::Vector3& Translation)
//{
//    return Translate(Translation) * Rotate(Rotator);
//}
//
//math::Transform math::Rotate(const math::Quaternion& Q)
//{
//    Math::Matrix4x4<float> Mat;
//    Mat.elements[0][0] = 1 - 2 * Q.Vec.Y * Q.Vec.Y - 2 * Q.Vec.Z * Q.Vec.Z;
//    Mat.elements[0][1] = 2 * Q.Vec.X * Q.Vec.Y - 2 * Q.Vec.Z * Q.W;
//    Mat.elements[0][2] = 2 * Q.Vec.X * Q.Vec.Z + 2 * Q.Vec.Y * Q.W;
//    Mat.elements[0][3] = 0;
//
//    Mat.elements[1][0] = 2 * Q.Vec.X * Q.Vec.Y + 2 * Q.Vec.Z * Q.W;
//    Mat.elements[1][1] = 1 - 2 * Q.Vec.X * Q.Vec.X - 2 * Q.Vec.Z * Q.Vec.Z;
//    Mat.elements[1][2] = 2 * Q.Vec.Y * Q.Vec.Z - 2 * Q.Vec.X * Q.W;
//    Mat.elements[1][3] = 0;
//
//    Mat.elements[2][0] = 2 * Q.Vec.X * Q.Vec.Z - 2 * Q.Vec.Y * Q.W;
//    Mat.elements[2][1] = 2 * Q.Vec.Y * Q.Vec.Z + 2 * Q.Vec.X * Q.W;
//    Mat.elements[2][2] = 1 - 2 * Q.Vec.X * Q.Vec.X - 2 * Q.Vec.Y * Q.Vec.Y;
//    Mat.elements[2][3] = 0;
//
//    math::Transform Ret(Mat, Math::Transpose(Mat));
//
//    return Ret;
//}
//
//Math::Bounds3<float> math::Transform::operator()(const Math::Bounds3<float>& B) const
//{
//    // TODO(Marko): Make this more efficient
//
//    const Transform& M = *this;
//    Math::Bounds3<float> Ret(M(B.min));
//    Ret = Math::Union(Ret, M(Point3(B.max.x, B.min.y, B.min.z)));
//    Ret = Math::Union(Ret, M(Point3(B.min.x, B.max.y, B.min.z)));
//    Ret = Math::Union(Ret, M(Point3(B.min.x, B.min.y, B.max.z)));
//    Ret = Math::Union(Ret, M(Point3(B.min.x, B.max.y, B.max.z)));
//    Ret = Math::Union(Ret, M(Point3(B.max.x, B.max.y, B.min.z)));
//    Ret = Math::Union(Ret, M(Point3(B.max.x, B.min.y, B.max.z)));
//    Ret = Math::Union(Ret, M(Point3(B.max.x, B.max.y, B.max.z)));
//    return Ret;
//}
//
//math::Vector3 math::Transform::operator()(const Vector3& Vec) const
//{
//    return {
//        m_Matrix.elements[0][0] * Vec.X + m_Matrix.elements[0][1] * Vec.Y + m_Matrix.elements[0][2] * Vec.Z,
//        m_Matrix.elements[1][0] * Vec.X + m_Matrix.elements[1][1] * Vec.Y + m_Matrix.elements[1][2] * Vec.Z,
//        m_Matrix.elements[2][0] * Vec.X + m_Matrix.elements[2][1] * Vec.Y + m_Matrix.elements[2][2] * Vec.Z};
//}
//
//math::Point3 math::Transform::operator()(const Point3& P) const
//{
//    const real X = m_Matrix.elements[0][0] * P.X + m_Matrix.elements[0][1] * P.Y +
//                   m_Matrix.elements[0][2] * P.Z + m_Matrix.elements[0][3];
//    const real Y = m_Matrix.elements[1][0] * P.X + m_Matrix.elements[1][1] * P.Y +
//                   m_Matrix.elements[1][2] * P.Z + m_Matrix.elements[1][3];
//    const real Z = m_Matrix.elements[2][0] * P.X + m_Matrix.elements[2][1] * P.Y +
//                   m_Matrix.elements[2][2] * P.Z + m_Matrix.elements[2][3];
//    const real W = m_Matrix.elements[3][0] * P.X + m_Matrix.elements[3][1] * P.Y +
//                   m_Matrix.elements[3][2] * P.Z + m_Matrix.elements[3][3];
//
//    assert(W != 0);
//    if (W == 1)
//    {
//        return {X, Y, Z};
//    }
//
//    return Point3(X, Y, Z) / W;
//}
//
//math::Point4 math::Transform::operator()(const Point4& P) const
//{
//    const real X = m_Matrix.elements[0][0] * P.X + m_Matrix.elements[0][1] * P.Y +
//                   m_Matrix.elements[0][2] * P.Z + m_Matrix.elements[0][3];
//    const real Y = m_Matrix.elements[1][0] * P.X + m_Matrix.elements[1][1] * P.Y +
//                   m_Matrix.elements[1][2] * P.Z + m_Matrix.elements[1][3];
//    const real Z = m_Matrix.elements[2][0] * P.X + m_Matrix.elements[2][1] * P.Y +
//                   m_Matrix.elements[2][2] * P.Z + m_Matrix.elements[2][3];
//    const real W = m_Matrix.elements[3][0] * P.X + m_Matrix.elements[3][1] * P.Y +
//                   m_Matrix.elements[3][2] * P.Z + m_Matrix.elements[3][3];
//
//    assert(W != 0);
//    return {X, Y, Z, W};
//}
//
//inline math::Normal3 math::Transform::operator()(const Normal3& N) const
//{
//    return {m_MatrixInverse.elements[0][0] * N.X + m_MatrixInverse.elements[1][0] * N.Y +
//                m_MatrixInverse.elements[2][0] * N.Z,
//            m_MatrixInverse.elements[0][1] * N.X + m_MatrixInverse.elements[1][1] * N.Y +
//                m_MatrixInverse.elements[2][1] * N.Z,
//            m_MatrixInverse.elements[0][2] * N.X + m_MatrixInverse.elements[1][2] * N.Y +
//                m_MatrixInverse.elements[2][2] * N.Z};
//}
