#pragma once

#include "math/base.h"
#include "math/bounds3.h"
#include "math/impl/vector3.h"
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

    const Matrix4x4& GetMatrix() const { return m_Matrix; }
    const Matrix4x4& GetInverse() const { return m_MatrixInverse; }

    friend Transform Inverse(const Transform& t);
    friend Transform Transpose(const Transform& t);

    bool operator==(const Transform& other) const;
    bool operator!=(const Transform& other) const;

    bool IsIdentity() const;

    bool HasScale() const;

    Transform operator*(const Transform& other) const;

    template <typename T>
    Vector3<T> operator()(const Vector3<T>& v) const;
    template <typename T>
    Point3<T> operator()(const Point3<T>& p) const;
    template <typename T>
    Point4<T> operator()(const Point4<T>& p) const;
    template <typename T>
    inline Normal3<T> operator()(const Normal3<T>& n) const;
    Bounds3<float> operator()(const Bounds3<float>& b) const;

    template <typename T>
    inline Point3<T> operator()(const Point3<T>& pt, Vector3<T>* absError) const;
    template <typename T>
    inline Point3<T> operator()(const Point3<T>& p,
                                const Vector3<T>& pError,
                                Vector3<T>* absError) const;
    template <typename T>
    inline Vector3<T> operator()(const Vector3<T>& v, Vector3<T>* absError) const;
    template <typename T>
    inline Vector3<T> operator()(const Vector3<T>& v,
                                 const Vector3<T>& vError,
                                 Vector3<T>* absError) const;

private:
    Matrix4x4 m_Matrix;
    Matrix4x4 m_MatrixInverse;
};

Transform Translate(const Vector3<float>& delta);
Transform Scale(float x, float y, float z);
Transform RotateX(float theta);
Transform RotateY(float theta);
Transform RotateZ(float theta);
Transform Rotate(float theta, const Vector3<float>& axis);
Transform Rotate(Rotator Rotator);

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
Vector3<T> Transform::operator()(const Vector3<T>& v) const
{
    T x = v.X, y = v.Y, z = v.Z;
    return Vector3<T>(m_Matrix.Data[0][0] * x + m_Matrix.Data[0][1] * y + m_Matrix.Data[0][2] * z,
                      m_Matrix.Data[1][0] * x + m_Matrix.Data[1][1] * y + m_Matrix.Data[1][2] * z,
                      m_Matrix.Data[2][0] * x + m_Matrix.Data[2][1] * y + m_Matrix.Data[2][2] * z);
}

template <typename T>
Point3<T> Transform::operator()(const Point3<T>& p) const
{
    T x = p.X, y = p.Y, z = p.Z;

    T xp = m_Matrix.Data[0][0] * x + m_Matrix.Data[0][1] * y + m_Matrix.Data[0][2] * z +
           m_Matrix.Data[0][3];
    T yp = m_Matrix.Data[1][0] * x + m_Matrix.Data[1][1] * y + m_Matrix.Data[1][2] * z +
           m_Matrix.Data[1][3];
    T zp = m_Matrix.Data[2][0] * x + m_Matrix.Data[2][1] * y + m_Matrix.Data[2][2] * z +
           m_Matrix.Data[2][3];
    T wp = m_Matrix.Data[3][0] * x + m_Matrix.Data[3][1] * y + m_Matrix.Data[3][2] * z +
           m_Matrix.Data[3][3];

    assert(wp != 0);

    if (wp == 1)
    {
        return Point3<T>(xp, yp, zp);
    }
    else
    {
        return Point3<T>(xp, yp, zp) / wp;
    }
}

template <typename T>
Point4<T> Transform::operator()(const Point4<T>& p) const
{
    T x = p.X, y = p.Y, z = p.Z;

    T xp = m_Matrix.Data[0][0] * x + m_Matrix.Data[0][1] * y + m_Matrix.Data[0][2] * z +
           m_Matrix.Data[0][3];
    T yp = m_Matrix.Data[1][0] * x + m_Matrix.Data[1][1] * y + m_Matrix.Data[1][2] * z +
           m_Matrix.Data[1][3];
    T zp = m_Matrix.Data[2][0] * x + m_Matrix.Data[2][1] * y + m_Matrix.Data[2][2] * z +
           m_Matrix.Data[2][3];
    T wp = m_Matrix.Data[3][0] * x + m_Matrix.Data[3][1] * y + m_Matrix.Data[3][2] * z +
           m_Matrix.Data[3][3];

    assert(wp != 0);
    return Point4<T>(xp, yp, zp, wp);
}

template <typename T>
inline Normal3<T> Transform::operator()(const Normal3<T>& n) const
{
    T x = n.X, y = n.Y, z = n.Z;
    return Normal3<T>(m_MatrixInverse.Data[0][0] * x + m_MatrixInverse.Data[1][0] * y +
                          m_MatrixInverse.Data[2][0] * z,
                      m_MatrixInverse.Data[0][1] * x + m_MatrixInverse.Data[1][1] * y +
                          m_MatrixInverse.Data[2][1] * z,
                      m_MatrixInverse.Data[0][2] * x + m_MatrixInverse.Data[1][2] * y +
                          m_MatrixInverse.Data[2][2] * z);
}

}  // namespace math