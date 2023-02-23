#pragma once

#include "math/base.h"
#include "math/bounds3.h"
#include "math/matrix4x4.h"
#include "math/rotator.h"

namespace math
{

class Quaternion;

class Transform
{
public:
    Transform() = default;
    explicit Transform(const Array2D<real, 4, 4>& Mat);
    explicit Transform(const Matrix4x4& Mat);
    Transform(const Matrix4x4& Mat, const Matrix4x4& InvMat);

    Transform& operator=(const Matrix4x4& Mat);

    [[nodiscard]] const Matrix4x4& GetMatrix() const { return m_Matrix; }
    [[nodiscard]] const Matrix4x4& GetInverse() const { return m_MatrixInverse; }

    friend Transform Inverse(const Transform& T);
    friend Transform Transpose(const Transform& T);

    bool operator==(const Transform& Other) const;
    bool operator!=(const Transform& Other) const;

    [[nodiscard]] bool IsIdentity() const;

    [[nodiscard]] bool HasScale() const;

    Transform operator*(const Transform& Other) const;

    Vector3 operator()(const Vector3& Vec) const;

    Point3 operator()(const Point3& P) const;

    Point4 operator()(const Point4& P) const;

    inline Normal3 operator()(const Normal3& N) const;
    Bounds3 operator()(const Bounds3& B) const;

private:
    Matrix4x4 m_Matrix;
    Matrix4x4 m_MatrixInverse;
};

Transform Translate(const Point3& Delta);
Transform Translate(const Vector3& Delta);
Transform Scale(real X, real Y, real Z);
Transform Scale(real V);
Transform RotateX(real Theta);
Transform RotateY(real Theta);
Transform RotateZ(real Theta);
Transform Rotate(real Theta, const Vector3& Axis);
Transform Rotate(const Quaternion& Q);
// This applies angle around x then around y and then around z axis
Transform Rotate(Rotator Rotator);
Transform RotateAndTranslate(Rotator Rotator, const Point3& Translation);
Transform RotateAndTranslate(Rotator Rotator, const Vector3& Translation);
Transform Inverse(const Transform& T);
Transform Transpose(const Transform& T);

///////////////////////////////////////////////////////////////////////////////////////////////////

}  // namespace math
