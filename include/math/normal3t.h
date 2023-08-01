#pragma once

#include "math/vector3t.h"

namespace Math
{

template <typename T>
struct Normal3T
{
    union
    {
        struct
        {
            T x, y, z;
        };
        struct
        {
            T r, g, b;
        };
        struct
        {
            T s, t, p;
        };
        T data[3];
    };
    /**
     * Default constructor. No initialization is performed.
     */
    constexpr Normal3T();

    /**
     * Constructs a normal where all components are initialized to the same value.
     * @param value The value to initialize the components to.
     */
    constexpr explicit Normal3T(T value);

    /**
     * Constructs a normal from the given components.
     * @param xx The x component.
     * @param yy The y component.
     * @param zz The z component.
     */
    constexpr Normal3T(T xx, T yy, T zz);

    /**
     * Converts a given ntor to a normal.
     * @param n The ntor to convert.
     */
    constexpr explicit Normal3T(const Vector3T<T>& vec);

    /** Operators **/
    T& operator[](int index);
    const T& operator[](int index) const;

    bool operator==(const Normal3T& other) const;
    bool operator!=(const Normal3T& other) const;

    Normal3T operator+(const Normal3T& other) const;
    Normal3T& operator+=(const Normal3T& other);
    Normal3T operator-(const Normal3T& other) const;
    Normal3T& operator-=(const Normal3T& other);

    Normal3T operator*(const Normal3T& other) const;
    Normal3T& operator*=(const Normal3T& other);

    Normal3T operator-() const;

    template <typename U>
    Normal3T operator*(U scalar) const;
    template <typename U>
    Normal3T& operator*=(U scalar);
    template <typename U>
    Normal3T operator/(U scalar) const;
    template <typename U>
    Normal3T& operator/=(U scalar);
};

template <typename T, typename U>
Normal3T<T> operator*(U scalar, const Normal3T<T>& n);

/**
 * Checks if any of the components are NaN or infinite value.
 * @return True if any of the components are NaN or infinite value, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNonFinite(const Normal3T<T>& n);

/**
 * Checks if any of the components are NaN.
 * @return True if any of the components are NaN, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNaN(const Normal3T<T>& n);

/**
 * Returns a new normal with the absolute value of each component.
 * @tparam T The type of the normal components.
 * @param n The normal to get the absolute value of.
 * @return A new normal with the absolute value of each component.
 */
template <typename T>
[[nodiscard]] Normal3T<T> Abs(const Normal3T<T>& n);

/**
 * Returns the dot product of normal with himself.
 * @tparam T The type of the normal components.
 * @param n  The normal to get the dot product of.
 * @return The dot product of normal with himself.
 */
template <typename T>
[[nodiscard]] T LengthSquared(const Normal3T<T>& n);

/**
 * Returns the length of the normal.
 * @tparam T The type of the normal components.
 * @param n The normal to get the length of.
 * @return The length of the normal.
 */
template <typename T>
[[nodiscard]] double Length(const Normal3T<T>& n);

/**
 * Checks if the normals are equal within a given epsilon.
 * @tparam T The type of the normal components.
 * @param n1 The first normal.
 * @param n2 The second normal.
 * @param epsilon The epsilon to use.
 * @return True if the normals are equal within a given epsilon, false otherwise.
 */
template <typename T>
bool IsEqual(const Normal3T<T>& n1, const Normal3T<T>& n2, T epsilon);

/**
 * Returns the dot product of two normals.
 * @tparam T The type of the normal components.
 * @param n1 The first normal.
 * @param n2 The second normal.
 * @return The dot product of two normals.
 */
template <typename T>
T Dot(const Normal3T<T>& n1, const Normal3T<T>& n2);

/**
 * Returns the dot product of a vector and a normal.
 * @tparam T The type of the normal components.
 * @param n The normal.
 * @param vec The vector.
 * @return The dot product of a normal and a vector.
 */
template <typename T>
T Dot(const Normal3T<T>& n, const Vector3T<T>& vec);
template <typename T>
T Dot(const Vector3T<T>& vec, const Normal3T<T>& n);

/**
 * Returns the absolute dot product of two normals.
 * @tparam T The type of the normal components.
 * @param n1 The first normal.
 * @param n2 The second normal.
 * @return The absolute dot product of two normals.
 */
template <typename T>
T AbsDot(const Normal3T<T>& n1, const Normal3T<T>& n2);

/**
 * Returns the absolute dot product of a normal and a vector.
 * @tparam T The type of the normal components.
 * @param n The normal.
 * @param n The vector.
 * @return The absolute dot product of a normal and a vector.
 */
template <typename T>
T AbsDot(const Normal3T<T>& n, const Vector3T<T>& vec);
template <typename T>
T AbsDot(const Vector3T<T>& vec, const Normal3T<T>& n);

/**
 * Returns the normalized normal.
 * @tparam T The type of the normal components.
 * @param n The normal to normalize.
 * @return The normalized normal.
 */
template <typename T>
Normal3T<T> Normalize(const Normal3T<T>& n);

/**
 * Returns the new normal with the minimum components of the two normals.
 * @tparam T The type of the normal components.
 * @param n1 The first normal.
 * @param n2 The second normal.
 * @return The new normal with the minimum components of the two normals.
 */
template <typename T>
Normal3T<T> Min(const Normal3T<T>& n1, const Normal3T<T>& n2);

/**
 * Returns the new normal with the maximum components of the two normals.
 * @tparam T The type of the normal components.
 * @param n1 The first normal.
 * @param n2 The second normal.
 * @return The new normal with the maximum components of the two normals.
 */
template <typename T>
Normal3T<T> Max(const Normal3T<T>& n1, const Normal3T<T>& n2);

/**
 * Return the new normal with permuted components.
 * @tparam T The type of the normal components.
 * @param n The normal to permute.
 * @param x The index of the new x component.
 * @param y The index of the new y component.
 * @param z The index of the new z component.
 * @return The new normal with permuted components.
 */
template <typename T>
Normal3T<T> Permute(const Normal3T<T>& n, int x, int y, int z);

/**
 * Returns the value of the smallest component.
 * @tparam T The type of the normal components.
 * @param n The normal to get the smallest component of.
 * @return The value of the smallest component.
 */
template <typename T>
T MinComponent(const Normal3T<T>& n);

/**
 * Returns the value of the largest component.
 * @tparam T The type of the normal components.
 * @param n The normal to get the largest component of.
 * @return The value of the largest component.
 */
template <typename T>
T MaxComponent(const Normal3T<T>& n);

/**
 * Returns the index of the smallest component.
 * @tparam T The type of the normal components.
 * @param n The normal to get the index of the smallest component of.
 * @return The index of the smallest component.
 */
template <typename T>
int MinDimension(const Normal3T<T>& n);

/**
 * Returns the index of the largest component.
 * @tparam T The type of the normal components.
 * @param n The normal to get the index of the largest component of.
 * @return The index of the largest component.
 */
template <typename T>
int MaxDimension(const Normal3T<T>& n);

/**
 * Turn normal to look in the same hemisphere as a vector.
 * @param n The normal to face forward.
 * @param vec The reference vector.
 * @return If its already looking in the same hemisphere, return the normal. Otherwise, return the
 * negated normal.
 */
template <typename T>
Normal3T<T> FaceForward(const Normal3T<T>& n, const Vector3T<T>& vec);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr Math::Normal3T<T>::Normal3T()
{
    // No initialization
}

template <typename T>
constexpr Math::Normal3T<T>::Normal3T(T value) : x(value), y(value), z(value)
{
}

template <typename T>
constexpr Math::Normal3T<T>::Normal3T(T xx, T yy, T zz) : x(xx), y(yy), z(zz)
{
}

template <typename T>
constexpr Math::Normal3T<T>::Normal3T(const Vector3T<T>& n) : x(n.x), y(n.y), z(n.z)
{
}

template <typename T>
T& Math::Normal3T<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
const T& Math::Normal3T<T>::operator[](int index) const
{
    return data[index];
}

template <typename T>
bool Math::Normal3T<T>::operator==(const Normal3T& other) const
{
    return x == other.x && y == other.y && z == other.z;
}

template <typename T>
bool Math::Normal3T<T>::operator!=(const Normal3T& other) const
{
    return !(*this == other);
}

template <typename T>
Math::Normal3T<T> Math::Normal3T<T>::operator+(const Normal3T& other) const
{
    return {x + other.x, y + other.y, z + other.z};
}

template <typename T>
Math::Normal3T<T>& Math::Normal3T<T>::operator+=(const Normal3T& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template <typename T>
Math::Normal3T<T> Math::Normal3T<T>::operator-(const Normal3T& other) const
{
    return {x - other.x, y - other.y, z - other.z};
}

template <typename T>
Math::Normal3T<T>& Math::Normal3T<T>::operator-=(const Normal3T& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template <typename T>
Math::Normal3T<T> Math::Normal3T<T>::operator*(const Normal3T& other) const
{
    return {x * other.x, y * other.y, z * other.z};
}

template <typename T, typename U>
Math::Normal3T<T> Math::operator*(U scalar, const Normal3T<T>& n)
{
    return n * scalar;
}

template <typename T>
Math::Normal3T<T>& Math::Normal3T<T>::operator*=(const Normal3T& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

template <typename T>
Math::Normal3T<T> Math::Normal3T<T>::operator-() const
{
    return {-x, -y, -z};
}

template <typename T>
template <typename U>
Math::Normal3T<T> Math::Normal3T<T>::operator*(U scalar) const
{
    T sc = static_cast<T>(scalar);
    return {x * sc, y * sc, z * sc};
}

template <typename T>
template <typename U>
Math::Normal3T<T>& Math::Normal3T<T>::operator*=(U scalar)
{
    T sc = static_cast<T>(scalar);
    x *= sc;
    y *= sc;
    z *= sc;
    return *this;
}

template <typename T>
template <typename U>
Math::Normal3T<T> Math::Normal3T<T>::operator/(U scalar) const
{
    if constexpr (std::is_integral_v<T>)
    {
        T sc = static_cast<T>(scalar);
        return {x / sc, y / sc, z / sc};
    }
    else
    {
        T sc = static_cast<T>(1 / scalar);
        return {x * sc, y * sc, z * sc};
    }
}

template <typename T>
template <typename U>
Math::Normal3T<T>& Math::Normal3T<T>::operator/=(U scalar)
{
    if constexpr (std::is_integral_v<T>)
    {
        T sc = static_cast<T>(scalar);
        x /= sc;
        y /= sc;
        z /= sc;
        return *this;
    }
    else
    {
        T sc = static_cast<T>(1 / scalar);
        x *= sc;
        y *= sc;
        z *= sc;
        return *this;
    }
}

template <typename T>
bool Math::ContainsNonFinite(const Normal3T<T>& n)
{
    return !math::IsFinite(n.x) || !math::IsFinite(n.y) || !math::IsFinite(n.z);
}

template <typename T>
bool Math::ContainsNaN(const Normal3T<T>& n)
{
    return math::IsNaN(n.x) || math::IsNaN(n.y) || math::IsNaN(n.z);
}

template <typename T>
Math::Normal3T<T> Math::Abs(const Normal3T<T>& n)
{
    return {math::Abs(n.x), math::Abs(n.y), math::Abs(n.z)};
}

template <typename T>
T Math::LengthSquared(const Normal3T<T>& n)
{
    return n.x * n.x + n.y * n.y + n.z * n.z;
}

template <typename T>
double Math::Length(const Normal3T<T>& n)
{
    return math::Sqrt(static_cast<double>(LengthSquared(n)));
}

template <typename T>
bool Math::IsEqual(const Normal3T<T>& n1, const Normal3T<T>& n2, T epsilon)
{
    return math::Abs(n1.x - n2.x) <= epsilon && math::Abs(n1.y - n2.y) <= epsilon &&
           math::Abs(n1.z - n2.z) <= epsilon;
}

template <typename T>
T Math::Dot(const Normal3T<T>& n1, const Normal3T<T>& n2)
{
    return n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
}

template <typename T>
T Math::Dot(const Normal3T<T>& n, const Vector3T<T>& vec)
{
    return n.x * vec.x + n.y * vec.y + n.z * vec.z;
}

template <typename T>
T Math::Dot(const Vector3T<T>& vec, const Normal3T<T>& n)
{
    return n.x * vec.x + n.y * vec.y + n.z * vec.z;
}

template <typename T>
T Math::AbsDot(const Normal3T<T>& n1, const Normal3T<T>& n2)
{
    return math::Abs(Dot(n1, n2));
}

template <typename T>
T Math::AbsDot(const Normal3T<T>& n, const Vector3T<T>& vec)
{
    return math::Abs(Dot(n, vec));
}

template <typename T>
T Math::AbsDot(const Vector3T<T>& vec, const Normal3T<T>& n)
{
    return math::Abs(Dot(vec, n));
}

template <typename T>
Math::Normal3T<T> Math::Normalize(const Normal3T<T>& n)
{
    double length = Length(n);
    assert(length > 0);
    return n / length;
}

template <typename T>
Math::Normal3T<T> Math::Min(const Normal3T<T>& n1, const Normal3T<T>& n2)
{
    return {math::Min(n1.x, n2.x), math::Min(n1.y, n2.y), math::Min(n1.z, n2.z)};
}

template <typename T>
Math::Normal3T<T> Math::Max(const Normal3T<T>& n1, const Normal3T<T>& n2)
{
    return {math::Max(n1.x, n2.x), math::Max(n1.y, n2.y), math::Max(n1.z, n2.z)};
}

template <typename T>
Math::Normal3T<T> Math::Permute(const Normal3T<T>& n, int x, int y, int z)
{
    return {n[x], n[y], n[z]};
}

template <typename T>
T Math::MinComponent(const Normal3T<T>& n)
{
    return math::Min(math::Min(n.x, n.y), n.z);
}

template <typename T>
T Math::MaxComponent(const Normal3T<T>& n)
{
    return math::Max(math::Max(n.x, n.y), n.z);
}

template <typename T>
int Math::MinDimension(const Normal3T<T>& n)
{
    return n.x < n.y ? (n.x < n.z ? 0 : 2) : (n.y < n.z ? 1 : 2);
}

template <typename T>
int Math::MaxDimension(const Normal3T<T>& n)
{
    return n.x > n.y ? (n.x > n.z ? 0 : 2) : (n.y > n.z ? 1 : 2);
}

template <typename T>
Math::Normal3T<T> Math::FaceForward(const Normal3T<T>& n, const Vector3T<T>& vec)
{
    return (Dot(n, vec) < 0) ? -n : n;
}
