#pragma once

#include "math/point3.h"
#include "math/vector3.h"
#include "math/matrix4x4.h"

namespace Math
{

template <std::floating_point T>
class Quaternion
{
public:
    Vector3<T> vec;
    T w;

    /**
     * Default constructor. No initialization is done.
     */
    Quaternion();

    /**
     * @brief Construct a Quaternion using four T values.
     * @param x - The i part of the Quaternion.
     * @param y - The j part of the Quaternion.
     * @param z - The k part of the Quaternion.
     * @param w - The T part of the Quaternion.
     */
    Quaternion(T x, T y, T z, T w);

    /**
     * @brief Construct a Quaternion from a matrix. This uses only the upper left 3x3 part of the
     * matrix.
     * @param transform - The transform to construct the Quaternion from.
     */
    explicit Quaternion(const Matrix4x4<T>& transform);

    /**
     * @brief Construct a Quaternion from an axis and an angle.
     * @param axis - The axis to rotate around. It doesn't have to be normalized.
     * @param angle_degrees - The angle to rotate by in degrees.
     * @return The Quaternion representing the rotation.
     */
    static Quaternion FromAxisAngleDegrees(const Vector3<T>& axis, T angle_degrees);

    /**
     * @brief Construct a Quaternion from an axis and an angle.
     * @param axis - The axis to rotate around. It doesn't have to be normalized.
     * @param angle_radians - The angle to rotate by in radians.
     * @return The Quaternion representing the rotation.
     */
    static Quaternion FromAxisAngleRadians(const Vector3<T>& axis, T angle_radians);

    /**
     * @brief Construct an identity Quaternion.
     * @return The identity Quaternion.
     */
    static Quaternion Identity();

    /** Operator overloads. */

    bool operator==(const Quaternion& other) const;
    bool operator!=(const Quaternion& other) const;

    Quaternion& operator+=(const Quaternion& other);
    Quaternion& operator-=(const Quaternion& other);
    Quaternion& operator*=(const Quaternion& other);
    Quaternion& operator*=(T scalar);
    Quaternion& operator/=(T scalar);

    Quaternion operator*(T scalar) const;
    Quaternion operator/(T scalar) const;
};

template <std::floating_point T>
Quaternion<T> operator+(const Quaternion<T>& q1, const Quaternion<T>& q2);
template <std::floating_point T>
Quaternion<T> operator-(const Quaternion<T>& q1, const Quaternion<T>& q2);
template <std::floating_point T>
Quaternion<T> operator*(const Quaternion<T>& q1, const Quaternion<T>& q2);
template <std::floating_point T>
Quaternion<T> operator*(T scalar, const Quaternion<T>& q);

/**
 * Rotate vector by this Quaternion.
 * @tparam T Type of the Quaternion.
 * @param q Quaternion to rotate by.
 * @param vec Vector to rotate.
 * @return Returns a new Quaternion.
 */
template <std::floating_point T>
Vector3<T> operator*(const Quaternion<T>& q, const Vector3<T>& vec);

/**
 * Rotate point by this Quaternion.
 * @tparam T Type of the Quaternion.
 * @param q Quaternion to rotate by.
 * @param p point to rotate.
 * @return Returns a new Quaternion.
 */
template <std::floating_point T>
Point3<T> operator*(const Quaternion<T>& q, const Point3<T>& p);

/**
 * Checks if any of the components are NaN or infinite value.
 * @param q Quaternion to check.
 * @return True if any of the components are NaN or infinite value, false otherwise.
 */
template <std::floating_point T>
[[nodiscard]] bool ContainsNonFinite(const Quaternion<T>& q);

/**
 * Checks if any of the components are NaN.
 * @param q Quaternion to check.
 * @return True if any of the components are NaN, false otherwise.
 */
template <std::floating_point T>
[[nodiscard]] bool ContainsNaN(const Quaternion<T>& q);

/**
 * Calculate the length squared of a Quaternion.
 * @tparam T Type of the Quaternion.
 * @param q Quaternion to calculate the length squared of.
 * @return Returns the length squared of the Quaternion.
 */
template <std::floating_point T>
[[nodiscard]] T LengthSquared(const Quaternion<T>& q);

/**
 * Calculate the length of a Quaternion.
 * @tparam T Type of the Quaternion.
 * @param q Quaternion to calculate the length of.
 * @return Returns the length of the Quaternion.
 */
template <std::floating_point T>
[[nodiscard]] T Length(const Quaternion<T>& q);

/**
 * Calculate the dot product of two Quaternions.
 * @tparam T Type of the Quaternions.
 * @param q1 First Quaternion.
 * @param q2 Second Quaternion.
 * @return Returns the dot product of the two Quaternions.
 */
template <std::floating_point T>
T Dot(const Quaternion<T>& q1, const Quaternion<T>& q2);

/**
 * Normalize a Quaternion.
 * @tparam T Type of the Quaternion.
 * @param Q Quaternion to normalize. Can't have a magnitude of 0.
 * @return Returns the normalized Quaternion in a new object.
 */
template <std::floating_point T>
Quaternion<T> Normalize(const Quaternion<T>& q);

/**
 * Perform linear interpolation between two Quaternions.
 * @tparam T Type of the Quaternions.
 * @param q1 First Quaternion.
 * @param q2 Second Quaternion.
 * @param param Parameter to interpolate between the two Quaternions. Should be between 0 and 1.
 * @return Returns the interpolated Quaternion in a new object.
 * @note This operation is commutative but results in a non-constant angular velocity. If you want
 * absolute precision and constant angular velocity, use Slerp instead.
 * @see Slerp
 */
template <std::floating_point T>
Quaternion<T> Lerp(const Quaternion<T>& q1, const Quaternion<T>& q2, T param);

/**
 * Perform spherical linear interpolation between two Quaternions.
 * @tparam T Type of the Quaternions.
 * @param q1 First Quaternion.
 * @param q2 Second Quaternion.
 * @param param Parameter to interpolate between the two Quaternions. Should be between 0 and 1.
 * @return Returns the interpolated Quaternion in a new object.
 * @note This operation is not commutative but provides constant angular velocity. If you want less
 * precision and commutative interpolation but can live with non-constant angular velocity, use Lerp
 * instead.
 * @see Lerp
 */
template <std::floating_point T>
Quaternion<T> Slerp(const Quaternion<T>& q1, const Quaternion<T>& q2, T param);

/**
 * @brief Get the conjugate of a Quaternion.
 * @tparam T Type of the Quaternion.
 * @param Q - The Quaternion to get the conjugate of.
 * @return The conjugate of the Quaternion.
 */
template <std::floating_point T>
Quaternion<T> Conjugate(const Quaternion<T>& q);

/**
 * @brief Get the inverse of a Quaternion.
 * @tparam T Type of the Quaternion.
 * @param Q - The Quaternion to get the inverse of.
 * @return The inverse of the Quaternion.
 */
template <std::floating_point T>
Quaternion<T> Inverse(const Quaternion<T>& q);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <std::floating_point T>
Math::Quaternion<T>::Quaternion()
{
    // Do nothing.
}

template <std::floating_point T>
Math::Quaternion<T>::Quaternion(T x, T y, T z, T w) : vec(x, y, z), w(w)
{
}

template <std::floating_point T>
Math::Quaternion<T>::Quaternion(const Matrix4x4<T>& transform)
{
    const T trace = transform.elements[0][0] + transform.elements[1][1] + transform.elements[2][2] +
                    transform.elements[3][3];

    if (trace > static_cast<T>(0.0))
    {
        w = Math::Sqrt(trace) / 2;
        const T scalar = 1 / (4 * w);
        vec.x = (transform.elements[2][1] - transform.elements[1][2]) * scalar;
        vec.y = (transform.elements[0][2] - transform.elements[2][0]) * scalar;
        vec.z = (transform.elements[1][0] - transform.elements[0][1]) * scalar;
        return;
    }

    const int Next[3] = {1, 2, 0};

    // Figure out who is largest
    int i = 0;
    if (transform.elements[1][1] > transform.elements[0][0])
    {
        i = 1;
    }
    if (transform.elements[2][2] > transform.elements[i][i])
    {
        i = 2;
    }
    const int j = Next[i];
    const int k = Next[j];

    T scalar = Math::Sqrt(
        (transform.elements[i][i] - (transform.elements[j][j] + transform.elements[k][k])) +
        static_cast<T>(1.0));
    T dir[3];
    dir[i] = scalar * static_cast<T>(0.5);
    if (scalar != 0.f)
    {
        scalar = static_cast<T>(0.5) / scalar;
    }
    w = (transform.elements[k][j] - transform.elements[j][k]) * scalar;
    dir[j] = (transform.elements[j][i] + transform.elements[i][j]) * scalar;
    dir[k] = (transform.elements[k][i] + transform.elements[i][k]) * scalar;
    vec.x = dir[0];
    vec.y = dir[1];
    vec.z = dir[2];
}

template <std::floating_point T>
Math::Quaternion<T> Math::Quaternion<T>::FromAxisAngleDegrees(const Vector3<T>& axis,
                                                              T angle_degrees)
{
    return FromAxisAngleRadians(axis, Radians(angle_degrees));
}

template <std::floating_point T>
Math::Quaternion<T> Math::Quaternion<T>::FromAxisAngleRadians(const Vector3<T>& axis, T angle_radians)
{
    const T s = Sin(angle_radians / 2);
    const T c = Cos(angle_radians / 2);
    const Vector3 vec = Normalize(axis);
    return {vec.x * s, vec.y * s, vec.z * s, c};
}

template <std::floating_point T>
Math::Quaternion<T> Math::Quaternion<T>::Identity()
{
    return {0, 0, 0, 1};
}

template <std::floating_point T>
bool Math::Quaternion<T>::operator==(const Quaternion& other) const
{
    return vec == other.vec && w == other.w;
}

template <std::floating_point T>
bool Math::Quaternion<T>::operator!=(const Quaternion& other) const
{
    return !(*this == other);
}

template <std::floating_point T>
Math::Quaternion<T>& Math::Quaternion<T>::operator+=(const Quaternion& other)
{
    vec += other.vec;
    w += other.w;
    return *this;
}

template <std::floating_point T>
Math::Quaternion<T>& Math::Quaternion<T>::operator-=(const Quaternion& other)
{
    vec -= other.vec;
    w -= other.w;
    return *this;
}

template <std::floating_point T>
Math::Quaternion<T>& Math::Quaternion<T>::operator*=(const Quaternion& other)
{
    Quaternion q;
    q.vec.x = w * other.vec.x + vec.x * other.w + vec.y * other.vec.z - vec.z * other.vec.y;
    q.vec.y = w * other.vec.y + vec.y * other.w + vec.z * other.vec.x - vec.x * other.vec.z;
    q.vec.z = w * other.vec.z + vec.z * other.w + vec.x * other.vec.y - vec.y * other.vec.x;
    q.w = w * other.w - Dot(vec, other.vec);
    *this = q;
    return *this;
}

template <std::floating_point T>
Math::Quaternion<T>& Math::Quaternion<T>::operator*=(T scalar)
{
    vec *= scalar;
    w *= scalar;
    return *this;
}


template <std::floating_point T>
Math::Quaternion<T>& Math::Quaternion<T>::operator/=(T scalar)
{
    vec /= scalar;
    w /= scalar;
    return *this;
}

template <std::floating_point T>
Math::Quaternion<T> Math::Quaternion<T>::operator*(T scalar) const
{
    Quaternion q = *this;
    q *= scalar;
    return q;
}

template <std::floating_point T>
Math::Quaternion<T> Math::Quaternion<T>::operator/(T scalar) const
{
    Quaternion q = *this;
    q /= scalar;
    return q;
}

template <std::floating_point T>
Math::Quaternion<T> Math::operator+(const Quaternion<T>& q1, const Quaternion<T>& q2)
{
    Quaternion<T> q = q1;
    q += q2;
    return q;
}

template <std::floating_point T>
Math::Quaternion<T> Math::operator-(const Quaternion<T>& q1, const Quaternion<T>& q2)
{
    Quaternion<T> q = q1;
    q -= q2;
    return q;
}

template <std::floating_point T>
Math::Quaternion<T> Math::operator*(const Quaternion<T>& q1, const Quaternion<T>& q2)
{
    Quaternion<T> q = q1;
    q *= q2;
    return q;
}

template <std::floating_point T>
Math::Quaternion<T> Math::operator*(T scalar, const Quaternion<T>& q)
{
    Quaternion<T> result = q;
    result *= scalar;
    return result;
}

template <std::floating_point T>
Math::Vector3<T> Math::operator*(const Quaternion<T>& q, const Vector3<T>& vec)
{
    const Vector3<T> t = 2 * Cross(q.vec, vec);
    return vec + q.w * t + Cross(q.vec, t);
}

template <std::floating_point T>
Math::Point3<T> Math::operator*(const Quaternion<T>& q, const Point3<T>& p)
{
        const Quaternion<T> qp(p.x, p.y, p.z, 0);
        const Quaternion<T> result = q * qp * Inverse(q);
        return {result.vec.x, result.vec.y, result.vec.z};
}

template <std::floating_point T>
bool Math::ContainsNonFinite(const Quaternion<T>& q)
{
    return !std::isfinite(q.vec.x) || !std::isfinite(q.vec.y) || !std::isfinite(q.vec.z) ||
           !std::isfinite(q.w);
}

template <std::floating_point T>
bool Math::ContainsNaN(const Quaternion<T>& q)
{
    return std::isnan(q.vec.x) || std::isnan(q.vec.y) || std::isnan(q.vec.z) || std::isnan(q.w);
}

template <std::floating_point T>
T Math::LengthSquared(const Quaternion<T>& q)
{
    return q.vec.x * q.vec.x + q.vec.y * q.vec.y + q.vec.z * q.vec.z + q.w * q.w;
}

template <std::floating_point T>
T Math::Length(const Quaternion<T>& q)
{
    return Math::Sqrt(LengthSquared(q));
}

template <std::floating_point T>
T Math::Dot(const Quaternion<T>& q1, const Quaternion<T>& q2)
{
    return q1.vec.x * q2.vec.x + q1.vec.y * q2.vec.y + q1.vec.z * q2.vec.z + q1.w * q2.w;
}

template <std::floating_point T>
Math::Quaternion<T> Math::Normalize(const Quaternion<T>& q)
{
    const T length = Length(q);
    if (length == 0)
    {
        return q;
    }
    return q / length;
}

template <std::floating_point T>
Math::Quaternion<T> Math::Lerp(const Quaternion<T>& q1, const Quaternion<T>& q2, T param)
{
#if _DEBUG
    constexpr T k_epsilon = static_cast<T>(0.0001);
    assert(IsEqual(Length(q1), static_cast<T>(1.0), k_epsilon));
    assert(IsEqual(Length(q2), static_cast<T>(1.0), k_epsilon));
#endif

    const Quaternion q3 = q1 * (1 - param) + q2 * param;
    return Normalize(q3);
}

template <std::floating_point T>
Math::Quaternion<T> Math::Slerp(const Quaternion<T>& q1, const Quaternion<T>& q2, T param)
{
    // Implementation based on: Understanding Slerp, Then Not Using It, Jonathan Blow
    // http://number-none.com/product/Understanding%20Slerp,%20Then%20Not%20Using%20It/

    constexpr T k_epsilon = static_cast<T>(0.0001);
    assert(IsEqual(Length(q1), static_cast<T>(1.0), k_epsilon));
    assert(IsEqual(Length(q2), static_cast<T>(1.0), k_epsilon));

    const T cos_theta0 = Dot(q1, q2);
    if (cos_theta0 > static_cast<T>(1.0) - k_epsilon)
    {
        return Lerp(q1, q2, param);
    }

    const T theta0 = std::acos(cos_theta0);
    const T theta = theta0 * param;

    Quaternion q3 = q2 - q1 * cos_theta0;
    q3 = Normalize(q3);

    return q1 * Math::Cos(theta) + q3 * Math::Sin(theta);
}

template <std::floating_point T>
Math::Quaternion<T> Math::Conjugate(const Quaternion<T>& q)
{
    Quaternion<T> ret = q;
    ret.vec = -ret.vec;
    return ret;
}

template <std::floating_point T>
Math::Quaternion<T> Math::Inverse(const Quaternion<T>& q)
{
    const T length_squared = LengthSquared(q);
    assert(length_squared != 0);
    return Conjugate(q) / length_squared;
}
