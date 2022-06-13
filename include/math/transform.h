#pragma once

#include "math/base.h"
#include "math/bounds3.h"
#include "math/matrix4x4.h"
#include "math/rotator.h"

namespace math
{

class Transform
{
public:
    Transform() = default;
    explicit Transform(const float mat[4][4]);
    explicit Transform(const Matrix4x4& mat);
    Transform(const Matrix4x4& mat, const Matrix4x4& invMat);

    Transform& operator=(const Matrix4x4& Matrix);

    const Matrix4x4& GetMatrix() const { return m_Matrix; }
    const Matrix4x4& GetInverse() const { return m_MatrixInverse; }

    friend Transform Inverse(const Transform& t);
    friend Transform Transpose(const Transform& t);

    bool operator==(const Transform& other) const;
    bool operator!=(const Transform& other) const;

    bool IsIdentity() const;

    bool HasScale() const;

    Transform operator*(const Transform& other) const;

    Vector3 operator()(const Vector3& v) const;

    Point3 operator()(const Point3& p) const;

    Point4 operator()(const Point4& p) const;

    inline Normal3 operator()(const Normal3& n) const;
    Bounds3 operator()(const Bounds3& b) const;

    inline Point3 operator()(const Point3& pt, Vector3* absError) const;

    inline Point3 operator()(const Point3& p, const Vector3& pError, Vector3* absError) const;

    inline Vector3 operator()(const Vector3& v, Vector3* absError) const;

    inline Vector3 operator()(const Vector3& v, const Vector3& vError, Vector3* absError) const;

private:
    Matrix4x4 m_Matrix;
    Matrix4x4 m_MatrixInverse;
};

Transform Translate(const Vector3& delta);
Transform Scale(float x, float y, float z);
Transform RotateX(float theta);
Transform RotateY(float theta);
Transform RotateZ(float theta);
Transform Rotate(float theta, const Vector3& axis);
// This applies angle around x then around y and then around z axis
Transform Rotate(Rotator Rotator);

///////////////////////////////////////////////////////////////////////////////////////////////////

}  // namespace math
