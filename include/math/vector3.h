#pragma once

#include "math/base.h"

namespace Math
{

template <typename T>
struct Vector3
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
    constexpr Vector3();

    /**
     * Constructs a vector where all components are initialized to the same value.
     * @param value The value to initialize the components to.
     */
    constexpr explicit Vector3(T value);

    /**
     * Constructs a vector from the given components.
     * @param xx The x component.
     * @param yy The y component.
     * @param zz The z component.
     */
    constexpr Vector3(T xx, T yy, T zz);

    /** Operators **/
    T& operator[](int index);
    const T& operator[](int index) const;

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;

    Vector3 operator+(const Vector3& other) const;
    Vector3& operator+=(const Vector3& other);
    Vector3 operator-(const Vector3& other) const;
    Vector3& operator-=(const Vector3& other);

    Vector3 operator*(const Vector3& other) const;
    Vector3& operator*=(const Vector3& other);

    Vector3 operator-() const;

    template <typename U>
    Vector3 operator*(U scalar) const;
    template <typename U>
    Vector3& operator*=(U scalar);
    template <typename U>
    Vector3 operator/(U scalar) const;
    template <typename U>
    Vector3& operator/=(U scalar);
};

template <typename T, typename U>
Vector3<T> operator*(U scalar, const Vector3<T>& vec);

/**
 * Checks if any of the components are NaN or infinite value.
 * @return True if any of the components are NaN or infinite value, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNonFinite(const Vector3<T>& vec);

/**
 * Checks if any of the components are NaN.
 * @return True if any of the components are NaN, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNaN(const Vector3<T>& vec);

/**
 * Returns a new vector with the absolute value of each component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the absolute value of.
 * @return A new vector with the absolute value of each component.
 */
template <typename T>
[[nodiscard]] Vector3<T> Abs(const Vector3<T>& vec);

/**
 * Returns the dot product of vector with himself.
 * @tparam T The type of the vector components.
 * @param vec  The vector to get the dot product of.
 * @return The dot product of vector with himself.
 */
template <typename T>
[[nodiscard]] T LengthSquared(const Vector3<T>& vec);

/**
 * Returns the length of the vector.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the length of.
 * @return The length of the vector.
 */
template <typename T>
[[nodiscard]] double Length(const Vector3<T>& vec);

/**
 * Checks if the vectors are equal within a given epsilon.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @param epsilon The epsilon to use.
 * @return True if the vectors are equal within a given epsilon, false otherwise.
 */
template <typename T>
bool IsEqual(const Vector3<T>& vec1, const Vector3<T>& vec2, T epsilon);

/**
 * Returns the dot product of two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The dot product of two vectors.
 */
template <typename T>
T Dot(const Vector3<T>& vec1, const Vector3<T>& vec2);

/**
 * Returns the absolute dot product of two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The absolute dot product of two vectors.
 */
template <typename T>
T AbsDot(const Vector3<T>& vec1, const Vector3<T>& vec2);

/**
 * Returns the cross product of two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The cross product of two vectors.
 */
template <typename T>
Vector3<T> Cross(const Vector3<T>& vec1, const Vector3<T>& vec2);

/**
 * Returns the cross product of two vectors in 2D. Ignores z component.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The cross product of two vectors in 2D.
 */
template <typename T>
T Cross2D(const Vector3<T>& vec1, const Vector3<T>& vec2);

/**
 * Returns the normalized vector.
 * @tparam T The type of the vector components.
 * @param vec The vector to normalize.
 * @return The normalized vector.
 */
template <typename T>
Vector3<T> Normalize(const Vector3<T>& vec);

/**
 * Returns the new vector with the minimum components of the two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The new vector with the minimum components of the two vectors.
 */
template <typename T>
Vector3<T> Min(const Vector3<T>& vec1, const Vector3<T>& vec2);

/**
 * Returns the new vector with the maximum components of the two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The new vector with the maximum components of the two vectors.
 */
template <typename T>
Vector3<T> Max(const Vector3<T>& vec1, const Vector3<T>& vec2);

/**
 * Return the new vector with permuted components.
 * @tparam T The type of the vector components.
 * @param vec The vector to permute.
 * @param x The index of the new x component.
 * @param y The index of the new y component.
 * @param z The index of the new z component.
 * @return The new vector with permuted components.
 */
template <typename T>
Vector3<T> Permute(const Vector3<T>& vec, int x, int y, int z);

/**
 * Returns the new vector with all the components clamped.
 * @tparam T The type of the vector components.
 * @param vec The vector to clamp.
 * @param low Bottom clamp value.
 * @param high Top clamp value.
 * @return The new vector with all the components clamped.
 */
template <typename T>
Vector3<T> Clamp(const Vector3<T>& vec, T low, T high);

/**
 * Reflect the incidence vector around the normal.
 * @param incidence The incidence vector.
 * @param normal The normal vector.
 * @return The reflected vector.
 */
template <typename T>
Vector3<T> Reflect(const Vector3<T>& incidence, const Vector3<T>& normal);

/**
 * Returns the value of the smallest component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the smallest component of.
 * @return The value of the smallest component.
 */
template <typename T>
T MinComponent(const Vector3<T>& vec);

/**
 * Returns the value of the largest component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the largest component of.
 * @return The value of the largest component.
 */
template <typename T>
T MaxComponent(const Vector3<T>& vec);

/**
 * Returns the index of the smallest component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the index of the smallest component of.
 * @return The index of the smallest component.
 */
template <typename T>
int MinDimension(const Vector3<T>& vec);

/**
 * Returns the index of the largest component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the index of the largest component of.
 * @return The index of the largest component.
 */
template <typename T>
int MaxDimension(const Vector3<T>& vec);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr Math::Vector3<T>::Vector3()
{
    // No initialization
}

template <typename T>
constexpr Math::Vector3<T>::Vector3(T value) : x(value), y(value), z(value)
{
}

template <typename T>
constexpr Math::Vector3<T>::Vector3(T xx, T yy, T zz) : x(xx), y(yy), z(zz)
{
}

template <typename T>
T& Math::Vector3<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
const T& Math::Vector3<T>::operator[](int index) const
{
    return data[index];
}

template <typename T>
bool Math::Vector3<T>::operator==(const Vector3& other) const
{
    return x == other.x && y == other.y && z == other.z;
}

template <typename T>
bool Math::Vector3<T>::operator!=(const Vector3& other) const
{
    return !(*this == other);
}

template <typename T>
Math::Vector3<T> Math::Vector3<T>::operator+(const Vector3& other) const
{
    return {x + other.x, y + other.y, z + other.z};
}

template <typename T>
Math::Vector3<T>& Math::Vector3<T>::operator+=(const Vector3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template <typename T>
Math::Vector3<T> Math::Vector3<T>::operator-(const Vector3& other) const
{
    return {x - other.x, y - other.y, z - other.z};
}

template <typename T>
Math::Vector3<T>& Math::Vector3<T>::operator-=(const Vector3& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template <typename T>
Math::Vector3<T> Math::Vector3<T>::operator*(const Vector3& other) const
{
    return {x * other.x, y * other.y, z * other.z};
}

template <typename T, typename U>
Math::Vector3<T> Math::operator*(U scalar, const Vector3<T>& vec)
{
    return vec * scalar;
}

template <typename T>
Math::Vector3<T>& Math::Vector3<T>::operator*=(const Vector3& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

template <typename T>
Math::Vector3<T> Math::Vector3<T>::operator-() const
{
    return {-x, -y, -z};
}

template <typename T>
template <typename U>
Math::Vector3<T> Math::Vector3<T>::operator*(U scalar) const
{
    T sc = static_cast<T>(scalar);
    return {x * sc, y * sc, z * sc};
}

template <typename T>
template <typename U>
Math::Vector3<T>& Math::Vector3<T>::operator*=(U scalar)
{
    T sc = static_cast<T>(scalar);
    x *= sc;
    y *= sc;
    z *= sc;
    return *this;
}

template <typename T>
template <typename U>
Math::Vector3<T> Math::Vector3<T>::operator/(U scalar) const
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
Math::Vector3<T>& Math::Vector3<T>::operator/=(U scalar)
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
bool Math::ContainsNonFinite(const Vector3<T>& vec)
{
    return !math::IsFinite(vec.x) || !math::IsFinite(vec.y) || !math::IsFinite(vec.z);
}

template <typename T>
bool Math::ContainsNaN(const Vector3<T>& vec)
{
    return math::IsNaN(vec.x) || math::IsNaN(vec.y) || math::IsNaN(vec.z);
}

template <typename T>
Math::Vector3<T> Math::Abs(const Vector3<T>& vec)
{
    return {math::Abs(vec.x), math::Abs(vec.y), math::Abs(vec.z)};
}

template <typename T>
T Math::LengthSquared(const Vector3<T>& vec)
{
    return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
}

template <typename T>
double Math::Length(const Vector3<T>& vec)
{
    return math::Sqrt(static_cast<double>(LengthSquared(vec)));
}

template <typename T>
bool Math::IsEqual(const Vector3<T>& vec1, const Vector3<T>& vec2, T epsilon)
{
    return math::Abs(vec1.x - vec2.x) <= epsilon && math::Abs(vec1.y - vec2.y) <= epsilon &&
           math::Abs(vec1.z - vec2.z) <= epsilon;
}

template <typename T>
T Math::Dot(const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

template <typename T>
T Math::AbsDot(const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return math::Abs(Dot(vec1, vec2));
}

template <typename T>
Math::Vector3<T> Math::Cross(const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return {vec1.y * vec2.z - vec1.z * vec2.y, vec1.z * vec2.x - vec1.x * vec2.z,
            vec1.x * vec2.y - vec1.y * vec2.x};
}

template <typename T>
T Math::Cross2D(const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return vec1.x * vec2.y - vec1.y * vec2.x;
}

template <typename T>
Math::Vector3<T> Math::Normalize(const Vector3<T>& vec)
{
    double length = Length(vec);
    assert(length > 0);
    return vec / length;
}

template <typename T>
Math::Vector3<T> Math::Min(const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return {math::Min(vec1.x, vec2.x), math::Min(vec1.y, vec2.y), math::Min(vec1.z, vec2.z)};
}

template <typename T>
Math::Vector3<T> Math::Max(const Vector3<T>& vec1, const Vector3<T>& vec2)
{
    return {math::Max(vec1.x, vec2.x), math::Max(vec1.y, vec2.y), math::Max(vec1.z, vec2.z)};
}

template <typename T>
Math::Vector3<T> Math::Permute(const Vector3<T>& vec, int x, int y, int z)
{
    return {vec[x], vec[y], vec[z]};
}

template <typename T>
Math::Vector3<T> Math::Clamp(const Vector3<T>& vec, T low, T high)
{
    return {math::Clamp(vec.x, low, high), math::Clamp(vec.y, low, high),
            math::Clamp(vec.z, low, high)};
}

template <typename T>
T Math::MinComponent(const Vector3<T>& vec)
{
    return math::Min(math::Min(vec.x, vec.y), vec.z);
}

template <typename T>
T Math::MaxComponent(const Vector3<T>& vec)
{
    return math::Max(math::Max(vec.x, vec.y), vec.z);
}

template <typename T>
int Math::MinDimension(const Vector3<T>& vec)
{
    return vec.x < vec.y ? (vec.x < vec.z ? 0 : 2) : (vec.y < vec.z ? 1 : 2);
}

template <typename T>
int Math::MaxDimension(const Vector3<T>& vec)
{
    return vec.x > vec.y ? (vec.x > vec.z ? 0 : 2) : (vec.y > vec.z ? 1 : 2);
}

template <typename T>
Math::Vector3<T> Math::Reflect(const Vector3<T>& incidence, const Vector3<T>& normal)
{
    assert(Dot(incidence, normal) >= 0);
    return 2 * Dot(incidence, normal) * normal - incidence;
}
