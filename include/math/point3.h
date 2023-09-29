#pragma once

#include "math/vector3.h"

namespace Math
{

template <typename T>
struct Point3
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
    constexpr Point3();

    /**
     * Constructs a point where all components are initialized to the same value.
     * @param value The value to initialize the components to.
     */
    constexpr explicit Point3(T value);

    /**
     * Constructs a point from the given components.
     * @param xx The x component.
     * @param yy The y component.
     * @param zz The z component.
     */
    constexpr Point3(T xx, T yy, T zz);

    /** Operators **/
    T& operator[](int index);
    const T& operator[](int index) const;

    bool operator==(const Point3& other) const;
    bool operator!=(const Point3& other) const;

    Point3 operator+(const Vector3<T>& vec) const;
    Point3& operator+=(const Vector3<T>& vec);

    Point3 operator-(const Vector3<T>& vec) const;
    Vector3<T> operator-(const Point3& other) const;
    Point3& operator-=(const Vector3<T>& vec);

    Point3 operator-() const;

    template <typename U>
    Point3 operator*(U scalar) const;
    template <typename U>
    Point3& operator*=(U scalar);
    template <typename U>
    Point3 operator/(U scalar) const;
    template <typename U>
    Point3& operator/=(U scalar);
};

template <typename T, typename U>
Point3<T> operator*(U scalar, const Point3<T>& p);

/**
 * Checks if any of the components are NaN or infinite value.
 * @return True if any of the components are NaN or infinite value, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNonFinite(const Point3<T>& p);

/**
 * Checks if any of the components are NaN.
 * @return True if any of the components are NaN, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNaN(const Point3<T>& p);

/**
 * Returns a new point with the absolute value of each component.
 * @tparam T The type of the point components.
 * @param p The point to get the absolute value of.
 * @return A new point with the absolute value of each component.
 */
template <typename T>
[[nodiscard]] Point3<T> Abs(const Point3<T>& p);

/**
 * Converts the point to euclidean space by dividing each component by the w component.
 * @tparam T The type of the point components.
 * @param p The point to convert.
 * @return The point in euclidean space.
 */
template <typename T>
[[nodiscard]] Point3<T> ToEuclidean(const Point3<T>& p);

/**
 * Checks if the points are equal within a given epsilon.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @param epsilon The epsilon to use.
 * @return True if the points are equal within a given epsilon, false otherwise.
 */
template <typename T>
bool IsEqual(const Point3<T>& p1, const Point3<T>& p2, T epsilon);

/**
 * Calculates the distance between two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The distance between the two points.
 */
template <typename T>
double Distance(const Point3<T>& p1, const Point3<T>& p2);

/**
 * Calculates the squared distance between two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The squared distance between the two points.
 */
template <typename T>
T DistanceSquared(const Point3<T>& p1, const Point3<T>& p2);

/**
 * Calculates the linear interpolation between two points.
 * @tparam T The type of the point components.
 * @param t The interpolation factor.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The interpolated point.
 */
template <typename T>
Point3<T> Lerp(T t, const Point3<T>& p1, const Point3<T>& p2);

/**
 * Returns the new point with the minimum components of the two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The new point with the minimum components of the two points.
 */
template <typename T>
Point3<T> Min(const Point3<T>& p1, const Point3<T>& p2);

/**
 * Returns the new point with the maximum components of the two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The new point with the maximum components of the two points.
 */
template <typename T>
Point3<T> Max(const Point3<T>& p1, const Point3<T>& p2);

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
Point3<T> Permute(const Point3<T>& p, int x, int y, int z);

/**
 * Returns the new point with each component floored.
 * @tparam T The type of the point components.
 * @param p The point to floor.
 * @return The new point with each component floored.
 */
template <typename T>
Point3<T> Floor(const Point3<T>& p);

/**
 * Returns the new point with each component ceilinged.
 * @tparam T The type of the point components.
 * @param p The point to ceiling.
 * @return The new point with each component ceilinged.
 */
template <typename T>
Point3<T> Ceil(const Point3<T>& p);

/**
 * Returns the new point with each component rounded.
 * @tparam T The type of the point components.
 * @param p The point to round.
 * @return The new point with each component rounded.
 */
template <typename T>
Point3<T> Round(const Point3<T>& p);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr Math::Point3<T>::Point3()
{
    // No initialization
}

template <typename T>
constexpr Math::Point3<T>::Point3(T value) : x(value), y(value), z(value)
{
}

template <typename T>
constexpr Math::Point3<T>::Point3(T xx, T yy, T zz) : x(xx), y(yy), z(zz)
{
}

template <typename T>
T& Math::Point3<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
const T& Math::Point3<T>::operator[](int index) const
{
    return data[index];
}

template <typename T>
bool Math::Point3<T>::operator==(const Point3& other) const
{
    return x == other.x && y == other.y && z == other.z;
}

template <typename T>
bool Math::Point3<T>::operator!=(const Point3& other) const
{
    return !(*this == other);
}

template <typename T>
Math::Point3<T> Math::Point3<T>::operator+(const Vector3<T>& other) const
{
    return {x + other.x, y + other.y, z + other.z};
}

template <typename T>
Math::Point3<T>& Math::Point3<T>::operator+=(const Vector3<T>& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template <typename T>
Math::Point3<T> Math::Point3<T>::operator-(const Vector3<T>& other) const
{
    return {x - other.x, y - other.y, z - other.z};
}

template <typename T>
Math::Vector3<T> Math::Point3<T>::operator-(const Point3& other) const
{
    return {x - other.x, y - other.y, z - other.z};
}

template <typename T>
Math::Point3<T>& Math::Point3<T>::operator-=(const Vector3<T>& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template <typename T>
Math::Point3<T> Math::Point3<T>::operator-() const
{
    return {-x, -y, -z};
}

template <typename T, typename U>
Math::Point3<T> Math::operator*(U scalar, const Point3<T>& vec)
{
    return vec * scalar;
}

template <typename T>
template <typename U>
Math::Point3<T> Math::Point3<T>::operator*(U scalar) const
{
    T sc = static_cast<T>(scalar);
    return {x * sc, y * sc, z * sc};
}

template <typename T>
template <typename U>
Math::Point3<T>& Math::Point3<T>::operator*=(U scalar)
{
    T sc = static_cast<T>(scalar);
    x *= sc;
    y *= sc;
    z *= sc;
    return *this;
}

template <typename T>
template <typename U>
Math::Point3<T> Math::Point3<T>::operator/(U scalar) const
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
Math::Point3<T>& Math::Point3<T>::operator/=(U scalar)
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
bool Math::ContainsNonFinite(const Point3<T>& vec)
{
    return !Math::IsFinite(vec.x) || !Math::IsFinite(vec.y) || !Math::IsFinite(vec.z);
}

template <typename T>
bool Math::ContainsNaN(const Point3<T>& vec)
{
    return Math::IsNaN(vec.x) || Math::IsNaN(vec.y) || Math::IsNaN(vec.z);
}

template <typename T>
Math::Point3<T> Math::Abs(const Point3<T>& vec)
{
    return {Math::Abs(vec.x), Math::Abs(vec.y), Math::Abs(vec.z)};
}

template <typename T>
bool Math::IsEqual(const Point3<T>& vec1, const Point3<T>& vec2, T epsilon)
{
    return Math::Abs(vec1.x - vec2.x) <= epsilon && Math::Abs(vec1.y - vec2.y) <= epsilon &&
           Math::Abs(vec1.z - vec2.z) <= epsilon;
}

template <typename T>
double Math::Distance(const Point3<T>& p1, const Point3<T>& p2)
{
    return Length(p1 - p2);
}

template <typename T>
T Math::DistanceSquared(const Point3<T>& p1, const Point3<T>& p2)
{
    return LengthSquared(p1 - p2);
}

template <typename T>
Math::Point3<T> Math::Lerp(T t, const Point3<T>& p1, const Point3<T>& p2)
{
    return p1 + t * (p2 - p1);
}

template <typename T>
Math::Point3<T> Math::Min(const Point3<T>& vec1, const Point3<T>& vec2)
{
    return {Math::Min(vec1.x, vec2.x), Math::Min(vec1.y, vec2.y), Math::Min(vec1.z, vec2.z)};
}

template <typename T>
Math::Point3<T> Math::Max(const Point3<T>& vec1, const Point3<T>& vec2)
{
    return {Math::Max(vec1.x, vec2.x), Math::Max(vec1.y, vec2.y), Math::Max(vec1.z, vec2.z)};
}

template <typename T>
Math::Point3<T> Math::Permute(const Point3<T>& vec, int x, int y, int z)
{
    return {vec[x], vec[y], vec[z]};
}

template <typename T>
Math::Point3<T> Math::Floor(const Point3<T>& p)
{
    if constexpr (std::is_integral_v<T>)
    {
        return p;
    }
    if constexpr (std::is_floating_point_v<T>)
    {
        return {Math::Floor(p.x), Math::Floor(p.y), Math::Floor(p.z)};
    }
}

template <typename T>
Math::Point3<T> Math::Ceil(const Point3<T>& p)
{
    if constexpr (std::is_integral_v<T>)
    {
        return p;
    }
    if constexpr (std::is_floating_point_v<T>)
    {
        return {Math::Ceil(p.x), Math::Ceil(p.y), Math::Ceil(p.z)};
    }
}

template <typename T>
Math::Point3<T> Math::Round(const Point3<T>& p)
{
    if constexpr (std::is_integral_v<T>)
    {
        return p;
    }
    if constexpr (std::is_floating_point_v<T>)
    {
        return {Math::Round(p.x), Math::Round(p.y), Math::Round(p.z)};
    }
}
