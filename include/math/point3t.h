#pragma once

#include "math/vector3t.h"

namespace Math
{

template <typename T>
struct Point3T
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
    constexpr Point3T();

    /**
     * Constructs a point where all components are initialized to the same value.
     * @param value The value to initialize the components to.
     */
    constexpr explicit Point3T(T value);

    /**
     * Constructs a point from the given components.
     * @param xx The x component.
     * @param yy The y component.
     * @param zz The z component.
     */
    constexpr Point3T(T xx, T yy, T zz);

    /** Operators **/
    T& operator[](int index);
    const T& operator[](int index) const;

    bool operator==(const Point3T& other) const;
    bool operator!=(const Point3T& other) const;

    Point3T operator+(const Vector3T<T>& vec) const;
    Point3T& operator+=(const Vector3T<T>& vec);

    Point3T operator-(const Vector3T<T>& vec) const;
    Vector3T<T> operator-(const Point3T& other) const;
    Point3T& operator-=(const Vector3T<T>& vec);

    Point3T operator-() const;

    template <typename U>
    Point3T operator*(U scalar) const;
    template <typename U>
    Point3T& operator*=(U scalar);
    template <typename U>
    Point3T operator/(U scalar) const;
    template <typename U>
    Point3T& operator/=(U scalar);
};

template <typename T, typename U>
Point3T<T> operator*(U scalar, const Point3T<T>& p);

/**
 * Checks if any of the components are NaN or infinite value.
 * @return True if any of the components are NaN or infinite value, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNonFinite(const Point3T<T>& p);

/**
 * Checks if any of the components are NaN.
 * @return True if any of the components are NaN, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNaN(const Point3T<T>& p);

/**
 * Returns a new point with the absolute value of each component.
 * @tparam T The type of the point components.
 * @param p The point to get the absolute value of.
 * @return A new point with the absolute value of each component.
 */
template <typename T>
[[nodiscard]] Point3T<T> Abs(const Point3T<T>& p);

/**
 * Converts the point to euclidean space by dividing each component by the w component.
 * @tparam T The type of the point components.
 * @param p The point to convert.
 * @return The point in euclidean space.
 */
template <typename T>
[[nodiscard]] Point3T<T> ToEuclidean(const Point3T<T>& p);

/**
 * Checks if the points are equal within a given epsilon.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @param epsilon The epsilon to use.
 * @return True if the points are equal within a given epsilon, false otherwise.
 */
template <typename T>
bool IsEqual(const Point3T<T>& p1, const Point3T<T>& p2, T epsilon);

/**
 * Calculates the distance between two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The distance between the two points.
 */
template <typename T>
double Distance(const Point3T<T>& p1, const Point3T<T>& p2);

/**
 * Calculates the squared distance between two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The squared distance between the two points.
 */
template <typename T>
T DistanceSquared(const Point3T<T>& p1, const Point3T<T>& p2);

/**
 * Calculates the linear interpolation between two points.
 * @tparam T The type of the point components.
 * @param t The interpolation factor.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The interpolated point.
 */
template <typename T>
Point3T<T> Lerp(T t, const Point3T<T>& p1, const Point3T<T>& p2);

/**
 * Returns the new point with the minimum components of the two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The new point with the minimum components of the two points.
 */
template <typename T>
Point3T<T> Min(const Point3T<T>& p1, const Point3T<T>& p2);

/**
 * Returns the new point with the maximum components of the two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The new point with the maximum components of the two points.
 */
template <typename T>
Point3T<T> Max(const Point3T<T>& p1, const Point3T<T>& p2);

/**
 * Return the new point with permuted components.
 * @tparam T The type of the point components.
 * @param p The point to permute.
 * @param x The index of the new x component.
 * @param y The index of the new y component.
 * @param z The index of the new z component.
 * @return The new point with permuted components.
 */
template <typename T>
Point3T<T> Permute(const Point3T<T>& p, int x, int y, int z);

/**
 * Returns the new point with each component floored.
 * @tparam T The type of the point components.
 * @param p The point to floor.
 * @return The new point with each component floored.
 */
template <typename T>
Point3T<T> Floor(const Point3T<T>& p);

/**
 * Returns the new point with each component ceilinged.
 * @tparam T The type of the point components.
 * @param p The point to ceiling.
 * @return The new point with each component ceilinged.
 */
template <typename T>
Point3T<T> Ceil(const Point3T<T>& p);

/**
 * Returns the new point with each component rounded.
 * @tparam T The type of the point components.
 * @param p The point to round.
 * @return The new point with each component rounded.
 */
template <typename T>
Point3T<T> Round(const Point3T<T>& p);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr Math::Point3T<T>::Point3T()
{
    // No initialization
}

template <typename T>
constexpr Math::Point3T<T>::Point3T(T value) : x(value), y(value), z(value)
{
}

template <typename T>
constexpr Math::Point3T<T>::Point3T(T xx, T yy, T zz) : x(xx), y(yy), z(zz)
{
}

template <typename T>
T& Math::Point3T<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
const T& Math::Point3T<T>::operator[](int index) const
{
    return data[index];
}

template <typename T>
bool Math::Point3T<T>::operator==(const Point3T& other) const
{
    return x == other.x && y == other.y && z == other.z;
}

template <typename T>
bool Math::Point3T<T>::operator!=(const Point3T& other) const
{
    return !(*this == other);
}

template <typename T>
Math::Point3T<T> Math::Point3T<T>::operator+(const Vector3T<T>& other) const
{
    return {x + other.x, y + other.y, z + other.z};
}

template <typename T>
Math::Point3T<T>& Math::Point3T<T>::operator+=(const Vector3T<T>& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template <typename T>
Math::Point3T<T> Math::Point3T<T>::operator-(const Vector3T<T>& other) const
{
    return {x - other.x, y - other.y, z - other.z};
}

template <typename T>
Math::Vector3T<T> Math::Point3T<T>::operator-(const Point3T& other) const
{
    return {x - other.x, y - other.y, z - other.z};
}

template <typename T>
Math::Point3T<T>& Math::Point3T<T>::operator-=(const Vector3T<T>& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template <typename T>
Math::Point3T<T> Math::Point3T<T>::operator-() const
{
    return {-x, -y, -z};
}

template <typename T, typename U>
Math::Point3T<T> Math::operator*(U scalar, const Point3T<T>& vec)
{
    return vec * scalar;
}

template <typename T>
template <typename U>
Math::Point3T<T> Math::Point3T<T>::operator*(U scalar) const
{
    T sc = static_cast<T>(scalar);
    return {x * sc, y * sc, z * sc};
}

template <typename T>
template <typename U>
Math::Point3T<T>& Math::Point3T<T>::operator*=(U scalar)
{
    T sc = static_cast<T>(scalar);
    x *= sc;
    y *= sc;
    z *= sc;
    return *this;
}

template <typename T>
template <typename U>
Math::Point3T<T> Math::Point3T<T>::operator/(U scalar) const
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
Math::Point3T<T>& Math::Point3T<T>::operator/=(U scalar)
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
bool Math::ContainsNonFinite(const Point3T<T>& vec)
{
    return !math::IsFinite(vec.x) || !math::IsFinite(vec.y) || !math::IsFinite(vec.z);
}

template <typename T>
bool Math::ContainsNaN(const Point3T<T>& vec)
{
    return math::IsNaN(vec.x) || math::IsNaN(vec.y) || math::IsNaN(vec.z);
}

template <typename T>
Math::Point3T<T> Math::Abs(const Point3T<T>& vec)
{
    return {math::Abs(vec.x), math::Abs(vec.y), math::Abs(vec.z)};
}

template <typename T>
bool Math::IsEqual(const Point3T<T>& vec1, const Point3T<T>& vec2, T epsilon)
{
    return math::Abs(vec1.x - vec2.x) <= epsilon && math::Abs(vec1.y - vec2.y) <= epsilon &&
           math::Abs(vec1.z - vec2.z) <= epsilon;
}

template <typename T>
double Math::Distance(const Point3T<T>& p1, const Point3T<T>& p2)
{
    return Length(p1 - p2);
}

template <typename T>
T Math::DistanceSquared(const Point3T<T>& p1, const Point3T<T>& p2)
{
    return LengthSquared(p1 - p2);
}

template <typename T>
Math::Point3T<T> Math::Lerp(T t, const Point3T<T>& p1, const Point3T<T>& p2)
{
    return p1 + t * (p2 - p1);
}

template <typename T>
Math::Point3T<T> Math::Min(const Point3T<T>& vec1, const Point3T<T>& vec2)
{
    return {math::Min(vec1.x, vec2.x), math::Min(vec1.y, vec2.y), math::Min(vec1.z, vec2.z)};
}

template <typename T>
Math::Point3T<T> Math::Max(const Point3T<T>& vec1, const Point3T<T>& vec2)
{
    return {math::Max(vec1.x, vec2.x), math::Max(vec1.y, vec2.y), math::Max(vec1.z, vec2.z)};
}

template <typename T>
Math::Point3T<T> Math::Permute(const Point3T<T>& vec, int x, int y, int z)
{
    return {vec[x], vec[y], vec[z]};
}

template <typename T>
Math::Point3T<T> Math::Floor(const Point3T<T>& p)
{
    if constexpr (std::is_integral_v<T>)
    {
        return p;
    }
    if constexpr (std::is_floating_point_v<T>)
    {
        return {math::Floor(p.x), math::Floor(p.y), math::Floor(p.z)};
    }
}

template <typename T>
Math::Point3T<T> Math::Ceil(const Point3T<T>& p)
{
    if constexpr (std::is_integral_v<T>)
    {
        return p;
    }
    if constexpr (std::is_floating_point_v<T>)
    {
        return {math::Ceil(p.x), math::Ceil(p.y), math::Ceil(p.z)};
    }
}

template <typename T>
Math::Point3T<T> Math::Round(const Point3T<T>& p)
{
    if constexpr (std::is_integral_v<T>)
    {
        return p;
    }
    if constexpr (std::is_floating_point_v<T>)
    {
        return {math::Round(p.x), math::Round(p.y), math::Round(p.z)};
    }
}
