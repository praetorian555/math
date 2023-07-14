#pragma once

#include "math/base.h"

namespace Math
{

template <typename T>
struct Vector4T
{
    union
    {
        struct
        {
            T x, y, z, w;
        };
        struct
        {
            T r, g, b, a;
        };
        struct
        {
            T s, t, p, q;
        };
        T data[4];
    };

    /**
     * Default constructor. No initialization is performed.
     */
    constexpr Vector4T();

    /**
     * Constructs a vector where all components are initialized to the same value.
     * @param value The value to initialize the components to.
     */
    constexpr explicit Vector4T(T value);

    /**
     * Constructs a vector from the given components.
     * @param xx The x component.
     * @param yy The y component.
     * @param zz The z component.
     * @param ww The w component.
     */
    constexpr Vector4T(T xx, T yy, T zz, T ww);

    /** Operators **/
    T& operator[](int index);
    const T& operator[](int index) const;

    bool operator==(const Vector4T& other) const;
    bool operator!=(const Vector4T& other) const;

    Vector4T operator+(const Vector4T& other) const;
    Vector4T& operator+=(const Vector4T& other);
    Vector4T operator-(const Vector4T& other) const;
    Vector4T& operator-=(const Vector4T& other);

    Vector4T operator*(const Vector4T& other) const;
    Vector4T& operator*=(const Vector4T& other);

    Vector4T operator-() const;

    template <typename U>
    Vector4T operator*(U scalar) const;
    template <typename U>
    Vector4T& operator*=(U scalar);
    template <typename U>
    Vector4T operator/(U scalar) const;
    template <typename U>
    Vector4T& operator/=(U scalar);
};

template <typename T, typename U>
Vector4T<T> operator*(U scalar, const Vector4T<T>& vec);

/**
 * Checks if any of the components are NaN or infinite value.
 * @return True if any of the components are NaN or infinite value, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNonFinite(const Vector4T<T>& vec);

/**
 * Checks if any of the components are NaN.
 * @return True if any of the components are NaN, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNaN(const Vector4T<T>& vec);

/**
 * Returns a new vector with the absolute value of each component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the absolute value of.
 * @return A new vector with the absolute value of each component.
 */
template <typename T>
[[nodiscard]] Vector4T<T> Abs(const Vector4T<T>& vec);

/**
 * Returns the dot product of vector with himself.
 * @tparam T The type of the vector components.
 * @param vec  The vector to get the dot product of.
 * @return The dot product of vector with himself.
 */
template <typename T>
[[nodiscard]] T LengthSquared(const Vector4T<T>& vec);

/**
 * Returns the length of the vector.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the length of.
 * @return The length of the vector.
 */
template <typename T>
[[nodiscard]] double Length(const Vector4T<T>& vec);

/**
 * Checks if the vectors are equal within a given epsilon.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @param epsilon The epsilon to use.
 * @return True if the vectors are equal within a given epsilon, false otherwise.
 */
template <typename T>
bool IsEqual(const Vector4T<T>& vec1, const Vector4T<T>& vec2, T epsilon);

/**
 * Returns the dot product of two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The dot product of two vectors.
 */
template <typename T>
T Dot(const Vector4T<T>& vec1, const Vector4T<T>& vec2);

/**
 * Returns the absolute dot product of two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The absolute dot product of two vectors.
 */
template <typename T>
T AbsDot(const Vector4T<T>& vec1, const Vector4T<T>& vec2);

/**
 * Returns the normalized vector.
 * @tparam T The type of the vector components.
 * @param vec The vector to normalize.
 * @return The normalized vector.
 */
template <typename T>
Vector4T<T> Normalize(const Vector4T<T>& vec);

/**
 * Returns the new vector with the minimum components of the two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The new vector with the minimum components of the two vectors.
 */
template <typename T>
Vector4T<T> Min(const Vector4T<T>& vec1, const Vector4T<T>& vec2);

/**
 * Returns the new vector with the maximum components of the two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The new vector with the maximum components of the two vectors.
 */
template <typename T>
Vector4T<T> Max(const Vector4T<T>& vec1, const Vector4T<T>& vec2);

/**
 * Return the new vector with permuted components.
 * @tparam T The type of the vector components.
 * @param vec The vector to permute.
 * @param x The index of the new x component.
 * @param y The index of the new y component.
 * @param z The index of the new z component.
 * @param w The index of the new w component.
 * @return The new vector with permuted components.
 */
template <typename T>
Vector4T<T> Permute(const Vector4T<T>& vec, int x, int y, int z, int w);

/**
 * Returns the new vector with all the components clamped.
 * @tparam T The type of the vector components.
 * @param vec The vector to clamp.
 * @param low Bottom clamp value.
 * @param high Top clamp value.
 * @return The new vector with all the components clamped.
 */
template <typename T>
Vector4T<T> Clamp(const Vector4T<T>& vec, T low, T high);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr Math::Vector4T<T>::Vector4T()
{
    // No initialization
}

template <typename T>
constexpr Math::Vector4T<T>::Vector4T(T value) : x(value), y(value), z(value), w(value)
{
}

template <typename T>
constexpr Math::Vector4T<T>::Vector4T(T xx, T yy, T zz, T ww) : x(xx), y(yy), z(zz), w(ww)
{
}

template <typename T>
T& Math::Vector4T<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
const T& Math::Vector4T<T>::operator[](int index) const
{
    return data[index];
}

template <typename T>
bool Math::Vector4T<T>::operator==(const Vector4T& other) const
{
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

template <typename T>
bool Math::Vector4T<T>::operator!=(const Vector4T& other) const
{
    return !(*this == other);
}

template <typename T>
Math::Vector4T<T> Math::Vector4T<T>::operator+(const Vector4T& other) const
{
    return {x + other.x, y + other.y, z + other.z, w + other.w};
}

template <typename T>
Math::Vector4T<T>& Math::Vector4T<T>::operator+=(const Vector4T& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

template <typename T>
Math::Vector4T<T> Math::Vector4T<T>::operator-(const Vector4T& other) const
{
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}

template <typename T>
Math::Vector4T<T>& Math::Vector4T<T>::operator-=(const Vector4T& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

template <typename T>
Math::Vector4T<T> Math::Vector4T<T>::operator*(const Vector4T& other) const
{
    return {x * other.x, y * other.y, z * other.z, w * other.w};
}

template <typename T, typename U>
Math::Vector4T<T> Math::operator*(U scalar, const Vector4T<T>& vec)
{
    return vec * scalar;
}

template <typename T>
Math::Vector4T<T>& Math::Vector4T<T>::operator*=(const Vector4T& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
}

template <typename T>
Math::Vector4T<T> Math::Vector4T<T>::operator-() const
{
    return {-x, -y, -z, -w};
}

template <typename T>
template <typename U>
Math::Vector4T<T> Math::Vector4T<T>::operator*(U scalar) const
{
    T sc = static_cast<T>(scalar);
    return {x * sc, y * sc, z * sc, w * sc};
}

template <typename T>
template <typename U>
Math::Vector4T<T>& Math::Vector4T<T>::operator*=(U scalar)
{
    T sc = static_cast<T>(scalar);
    x *= sc;
    y *= sc;
    z *= sc;
    w *= sc;
    return *this;
}

template <typename T>
template <typename U>
Math::Vector4T<T> Math::Vector4T<T>::operator/(U scalar) const
{
    if constexpr (std::is_integral_v<T>)
    {
        T sc = static_cast<T>(scalar);
        return {x / sc, y / sc, z / sc, w / sc};
    }
    else
    {
        T sc = static_cast<T>(1 / scalar);
        return {x * sc, y * sc, z * sc, w * sc};
    }
}

template <typename T>
template <typename U>
Math::Vector4T<T>& Math::Vector4T<T>::operator/=(U scalar)
{
    if constexpr (std::is_integral_v<T>)
    {
        T sc = static_cast<T>(scalar);
        x /= sc;
        y /= sc;
        z /= sc;
        w /= sc;
        return *this;
    }
    else
    {
        T sc = static_cast<T>(1 / scalar);
        x *= sc;
        y *= sc;
        z *= sc;
        w *= sc;
        return *this;
    }
}

template <typename T>
bool Math::ContainsNonFinite(const Vector4T<T>& vec)
{
    return !std::isfinite(vec.x) || !std::isfinite(vec.y) || !std::isfinite(vec.z) ||
           !std::isfinite(vec.w);
}

template <typename T>
bool Math::ContainsNaN(const Vector4T<T>& vec)
{
    return std::isnan(vec.x) || std::isnan(vec.y) || std::isnan(vec.z) || std::isnan(vec.w);
}

template <typename T>
Math::Vector4T<T> Math::Abs(const Vector4T<T>& vec)
{
    return {std::abs(vec.x), std::abs(vec.y), std::abs(vec.z), std::abs(vec.w)};
}

template <typename T>
T Math::LengthSquared(const Vector4T<T>& vec)
{
    return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w;
}

template <typename T>
double Math::Length(const Vector4T<T>& vec)
{
    return std::sqrt(static_cast<double>(LengthSquared(vec)));
}

template <typename T>
bool Math::IsEqual(const Vector4T<T>& vec1, const Vector4T<T>& vec2, T epsilon)
{
    return std::abs(vec1.x - vec2.x) <= epsilon && std::abs(vec1.y - vec2.y) <= epsilon &&
           std::abs(vec1.z - vec2.z) <= epsilon && std::abs(vec1.w - vec2.w) <= epsilon;
}

template <typename T>
T Math::Dot(const Vector4T<T>& vec1, const Vector4T<T>& vec2)
{
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
}

template <typename T>
T Math::AbsDot(const Vector4T<T>& vec1, const Vector4T<T>& vec2)
{
    return std::abs(Dot(vec1, vec2));
}

template <typename T>
Math::Vector4T<T> Math::Normalize(const Vector4T<T>& vec)
{
    double length = Length(vec);
    assert(length > 0);
    return vec / Length(vec);
}

template <typename T>
Math::Vector4T<T> Math::Min(const Vector4T<T>& vec1, const Vector4T<T>& vec2)
{
    return {std::min(vec1.x, vec2.x), std::min(vec1.y, vec2.y), std::min(vec1.z, vec2.z),
            std::min(vec1.w, vec2.w)};
}

template <typename T>
Math::Vector4T<T> Math::Max(const Vector4T<T>& vec1, const Vector4T<T>& vec2)
{
    return {std::max(vec1.x, vec2.x), std::max(vec1.y, vec2.y), std::max(vec1.z, vec2.z),
            std::max(vec1.w, vec2.w)};
}

template <typename T>
Math::Vector4T<T> Math::Permute(const Vector4T<T>& vec, int x, int y, int z, int w)
{
    return {vec[x], vec[y], vec[z], vec[w]};
}

template <typename T>
Math::Vector4T<T> Math::Clamp(const Vector4T<T>& vec, T low, T high)
{
    return {math::Clamp(vec.x, low, high), math::Clamp(vec.y, low, high),
            math::Clamp(vec.z, low, high), math::Clamp(vec.w, low, high)};
}
