#pragma once

#include "math/base.h"

namespace Math
{

template <typename T>
struct Vector2T
{
    union
    {
        struct
        {
            T x, y;
        };
        struct
        {
            T r, g;
        };
        struct
        {
            T s, t;
        };
        T data[2];
    };

    /**
     * Default constructor. No initialization is performed.
     */
    constexpr Vector2T();

    /**
     * Constructs a vector where all components are initialized to the same value.
     * @param value The value to initialize the components to.
     */
    constexpr explicit Vector2T(T value);

    /**
     * Constructs a vector from the given components.
     * @param xx The x component.
     * @param yy The y component.
     */
    constexpr Vector2T(T xx, T yy);

    /** Operators **/
    T& operator[](int index);
    const T& operator[](int index) const;

    bool operator==(const Vector2T& other) const;
    bool operator!=(const Vector2T& other) const;

    Vector2T operator+(const Vector2T& other) const;
    Vector2T& operator+=(const Vector2T& other);
    Vector2T operator-(const Vector2T& other) const;
    Vector2T& operator-=(const Vector2T& other);

    Vector2T operator*(const Vector2T& other) const;
    Vector2T& operator*=(const Vector2T& other);

    Vector2T operator-() const;

    template <typename U>
    Vector2T operator*(U scalar) const;
    template <typename U>
    Vector2T& operator*=(U scalar);
    template <typename U>
    Vector2T operator/(U scalar) const;
    template <typename U>
    Vector2T& operator/=(U scalar);
};

template <typename T, typename U>
Vector2T<T> operator*(U scalar, const Vector2T<T>& vec);

/**
 * Checks if any of the components are NaN or infinite value.
 * @return True if any of the components are NaN or infinite value, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNonFinite(const Vector2T<T>& vec);

/**
 * Checks if any of the components are NaN.
 * @return True if any of the components are NaN, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNaN(const Vector2T<T>& vec);

/**
 * Returns a new vector with the absolute value of each component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the absolute value of.
 * @return A new vector with the absolute value of each component.
 */
template <typename T>
[[nodiscard]] Vector2T<T> Abs(const Vector2T<T>& vec);

/**
 * Returns the dot product of vector with himself.
 * @tparam T The type of the vector components.
 * @param vec  The vector to get the dot product of.
 * @return The dot product of vector with himself.
 */
template <typename T>
[[nodiscard]] T LengthSquared(const Vector2T<T>& vec);

/**
 * Returns the length of the vector.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the length of.
 * @return The length of the vector.
 */
template <typename T>
[[nodiscard]] double Length(const Vector2T<T>& vec);

/**
 * Checks if the vectors are equal within a given epsilon.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @param epsilon The epsilon to use.
 * @return True if the vectors are equal within a given epsilon, false otherwise.
 */
template <typename T>
bool IsEqual(const Vector2T<T>& vec1, const Vector2T<T>& vec2, T epsilon);

/**
 * Returns the dot product of two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The dot product of two vectors.
 */
template <typename T>
T Dot(const Vector2T<T>& vec1, const Vector2T<T>& vec2);

/**
 * Returns the absolute dot product of two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The absolute dot product of two vectors.
 */
template <typename T>
T AbsDot(const Vector2T<T>& vec1, const Vector2T<T>& vec2);

/**
 * Returns the cross product of two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The cross product of two vectors.
 */
template <typename T>
T Cross(const Vector2T<T>& vec1, const Vector2T<T>& vec2);

/**
 * Returns the normalized vector.
 * @tparam T The type of the vector components.
 * @param vec The vector to normalize.
 * @return The normalized vector.
 */
template <typename T>
Vector2T<T> Normalize(const Vector2T<T>& vec);

/**
 * Returns the new vector with the minimum components of the two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The new vector with the minimum components of the two vectors.
 */
template <typename T>
Vector2T<T> Min(const Vector2T<T>& vec1, const Vector2T<T>& vec2);

/**
 * Returns the new vector with the maximum components of the two vectors.
 * @tparam T The type of the vector components.
 * @param vec1 The first vector.
 * @param vec2 The second vector.
 * @return The new vector with the maximum components of the two vectors.
 */
template <typename T>
Vector2T<T> Max(const Vector2T<T>& vec1, const Vector2T<T>& vec2);

/**
 * Return the new vector with permuted components.
 * @tparam T The type of the vector components.
 * @param vec The vector to permute.
 * @param x The index of the new x component.
 * @param y The index of the new y component.
 * @return The new vector with permuted components.
 */
template <typename T>
Vector2T<T> Permute(const Vector2T<T>& vec, int x, int y);

/**
 * Returns the new vector with all the components clamped.
 * @tparam T The type of the vector components.
 * @param vec The vector to clamp.
 * @param low Bottom clamp value.
 * @param high Top clamp value.
 * @return The new vector with all the components clamped.
 */
template <typename T>
Vector2T<T> Clamp(const Vector2T<T>& vec, T low, T high);

/**
 * Reflect the incidence vector around the normal.
 * @param incidence The incidence vector.
 * @param normal The normal vector.
 * @return The reflected vector.
 */
template <typename T>
Vector2T<T> Reflect(const Vector2T<T>& incidence, const Vector2T<T>& normal);

/**
 * Returns the value of the smallest component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the smallest component of.
 * @return The value of the smallest component.
 */
template <typename T>
T MinComponent(const Vector2T<T>& vec);

/**
 * Returns the value of the largest component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the largest component of.
 * @return The value of the largest component.
 */
template <typename T>
T MaxComponent(const Vector2T<T>& vec);

/**
 * Returns the index of the smallest component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the index of the smallest component of.
 * @return The index of the smallest component.
 */
template <typename T>
int MinDimension(const Vector2T<T>& vec);

/**
 * Returns the index of the largest component.
 * @tparam T The type of the vector components.
 * @param vec The vector to get the index of the largest component of.
 * @return The index of the largest component.
 */
template <typename T>
int MaxDimension(const Vector2T<T>& vec);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr Math::Vector2T<T>::Vector2T()
{
    // No initialization
}

template <typename T>
constexpr Math::Vector2T<T>::Vector2T(T value) : x(value), y(value)
{
}

template <typename T>
constexpr Math::Vector2T<T>::Vector2T(T xx, T yy) : x(xx), y(yy)
{
}

template <typename T>
T& Math::Vector2T<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
const T& Math::Vector2T<T>::operator[](int index) const
{
    return data[index];
}

template <typename T>
bool Math::Vector2T<T>::operator==(const Vector2T& other) const
{
    return x == other.x && y == other.y;
}

template <typename T>
bool Math::Vector2T<T>::operator!=(const Vector2T& other) const
{
    return !(*this == other);
}

template <typename T>
Math::Vector2T<T> Math::Vector2T<T>::operator+(const Vector2T& other) const
{
    return {x + other.x, y + other.y};
}

template <typename T>
Math::Vector2T<T>& Math::Vector2T<T>::operator+=(const Vector2T& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
Math::Vector2T<T> Math::Vector2T<T>::operator-(const Vector2T& other) const
{
    return {x - other.x, y - other.y};
}

template <typename T>
Math::Vector2T<T>& Math::Vector2T<T>::operator-=(const Vector2T& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

template <typename T>
Math::Vector2T<T> Math::Vector2T<T>::operator*(const Vector2T& other) const
{
    return {x * other.x, y * other.y};
}

template <typename T, typename U>
Math::Vector2T<T> Math::operator*(U scalar, const Vector2T<T>& vec)
{
    return vec * scalar;
}

template <typename T>
Math::Vector2T<T>& Math::Vector2T<T>::operator*=(const Vector2T& other)
{
    x *= other.x;
    y *= other.y;
    return *this;
}

template <typename T>
Math::Vector2T<T> Math::Vector2T<T>::operator-() const
{
    return {-x, -y};
}

template <typename T>
template <typename U>
Math::Vector2T<T> Math::Vector2T<T>::operator*(U scalar) const
{
    T sc = static_cast<T>(scalar);
    return {x * sc, y * sc};
}

template <typename T>
template <typename U>
Math::Vector2T<T>& Math::Vector2T<T>::operator*=(U scalar)
{
    T sc = static_cast<T>(scalar);
    x *= sc;
    y *= sc;
    return *this;
}

template <typename T>
template <typename U>
Math::Vector2T<T> Math::Vector2T<T>::operator/(U scalar) const
{
    if constexpr (std::is_integral_v<T>)
    {
        T sc = static_cast<T>(scalar);
        return {x / sc, y / sc};
    }
    else
    {
        T sc = static_cast<T>(1 / scalar);
        return {x * sc, y * sc};
    }
}

template <typename T>
template <typename U>
Math::Vector2T<T>& Math::Vector2T<T>::operator/=(U scalar)
{
    if constexpr (std::is_integral_v<T>)
    {
        T sc = static_cast<T>(scalar);
        x /= sc;
        y /= sc;
        return *this;
    }
    else
    {
        T sc = static_cast<T>(1 / scalar);
        x *= sc;
        y *= sc;
        return *this;
    }
}

template <typename T>
bool Math::ContainsNonFinite(const Vector2T<T>& vec)
{
    return !math::IsFinite(vec.x) || !math::IsFinite(vec.y);
}

template <typename T>
bool Math::ContainsNaN(const Vector2T<T>& vec)
{
    return math::IsNaN(vec.x) || math::IsNaN(vec.y);
}

template <typename T>
Math::Vector2T<T> Math::Abs(const Vector2T<T>& vec)
{
    return {math::Abs(vec.x), math::Abs(vec.y)};
}

template <typename T>
T Math::LengthSquared(const Vector2T<T>& vec)
{
    return vec.x * vec.x + vec.y * vec.y;
}

template <typename T>
double Math::Length(const Vector2T<T>& vec)
{
    return math::Sqrt(static_cast<double>(LengthSquared(vec)));
}

template <typename T>
bool Math::IsEqual(const Vector2T<T>& vec1, const Vector2T<T>& vec2, T epsilon)
{
    return math::Abs(vec1.x - vec2.x) <= epsilon && math::Abs(vec1.y - vec2.y) <= epsilon;
}

template <typename T>
T Math::Dot(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

template <typename T>
T Math::AbsDot(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
    return math::Abs(Dot(vec1, vec2));
}

template <typename T>
T Math::Cross(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
    return vec1.x * vec2.y - vec1.y * vec2.x;
}

template <typename T>
Math::Vector2T<T> Math::Normalize(const Vector2T<T>& vec)
{
    double length = Length(vec);
    assert(length > 0);
    return vec / length;
}

template <typename T>
Math::Vector2T<T> Math::Min(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
    return {math::Min(vec1.x, vec2.x), math::Min(vec1.y, vec2.y)};
}

template <typename T>
Math::Vector2T<T> Math::Max(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
    return {math::Max(vec1.x, vec2.x), math::Max(vec1.y, vec2.y)};
}

template <typename T>
Math::Vector2T<T> Math::Permute(const Vector2T<T>& vec, int x, int y)
{
    return {vec[x], vec[y]};
}

template <typename T>
Math::Vector2T<T> Math::Clamp(const Vector2T<T>& vec, T low, T high)
{
    return {math::Clamp(vec.x, low, high), math::Clamp(vec.y, low, high)};
}

template <typename T>
T Math::MinComponent(const Vector2T<T>& vec)
{
    return math::Min(vec.x, vec.y);
}

template <typename T>
T Math::MaxComponent(const Vector2T<T>& vec)
{
    return math::Max(vec.x, vec.y);
}

template <typename T>
int Math::MinDimension(const Vector2T<T>& vec)
{
    return vec.x < vec.y ? 0 : 1;
}

template <typename T>
int Math::MaxDimension(const Vector2T<T>& vec)
{
    return vec.x > vec.y ? 0 : 1;
}

template <typename T>
Math::Vector2T<T> Math::Reflect(const Vector2T<T>& incidence, const Vector2T<T>& normal)
{
    assert(Dot(incidence, normal) >= 0);
    return 2 * Dot(incidence, normal) * normal - incidence;
}
