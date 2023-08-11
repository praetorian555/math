#pragma once

#include "math/vector4t.h"

namespace Math
{

template <typename T>
struct Point4T
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
    constexpr Point4T();

    /**
     * Constructs a point where all components are initialized to the same value.
     * @param value The value to initialize the components to.
     */
    constexpr explicit Point4T(T value);

    /**
     * Constructs a point from the given components.
     * @param xx The x component.
     * @param yy The y component.
     * @param zz The z component.
     * @param ww The w component.
     */
    constexpr Point4T(T xx, T yy, T zz, T ww);

    /** Operators **/
    T& operator[](int index);
    const T& operator[](int index) const;

    bool operator==(const Point4T& other) const;
    bool operator!=(const Point4T& other) const;

    Point4T operator+(const Vector4T<T>& vec) const;
    Point4T& operator+=(const Vector4T<T>& vec);

    Point4T operator-(const Vector4T<T>& vec) const;
    Vector4T<T> operator-(const Point4T& other) const;
    Point4T& operator-=(const Vector4T<T>& vec);

    Point4T operator-() const;

    template <typename U>
    Point4T operator*(U scalar) const;
    template <typename U>
    Point4T& operator*=(U scalar);
    template <typename U>
    Point4T operator/(U scalar) const;
    template <typename U>
    Point4T& operator/=(U scalar);
};

template <typename T, typename U>
Point4T<T> operator*(U scalar, const Point4T<T>& p);

/**
 * Checks if any of the components are NaN or infinite value.
 * @return True if any of the components are NaN or infinite value, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNonFinite(const Point4T<T>& p);

/**
 * Checks if any of the components are NaN.
 * @return True if any of the components are NaN, false otherwise.
 */
template <typename T>
[[nodiscard]] bool ContainsNaN(const Point4T<T>& p);

/**
 * Returns a new point with the absolute value of each component.
 * @tparam T The type of the point components.
 * @param p The point to get the absolute value of.
 * @return A new point with the absolute value of each component.
 */
template <typename T>
[[nodiscard]] Point4T<T> Abs(const Point4T<T>& p);

/**
 * Converts the point to euclidean space by dividing each component by the w component.
 * @tparam T The type of the point components.
 * @param p The point to convert.
 * @return The point in euclidean space.
 */
template <typename T>
[[nodiscard]] Point4T<T> ToEuclidean(const Point4T<T>& p);

/**
 * Checks if the points are equal within a given epsilon.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @param epsilon The epsilon to use.
 * @return True if the points are equal within a given epsilon, false otherwise.
 */
template <typename T>
bool IsEqual(const Point4T<T>& p1, const Point4T<T>& p2, T epsilon);

/**
 * Calculates the distance between two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The distance between the two points.
 */
template <typename T>
double Distance(const Point4T<T>& p1, const Point4T<T>& p2);

/**
 * Calculates the squared distance between two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The squared distance between the two points.
 */
template <typename T>
T DistanceSquared(const Point4T<T>& p1, const Point4T<T>& p2);

/**
 * Calculates the linear interpolation between two points.
 * @tparam T The type of the point components.
 * @param t The interpolation factor.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The interpolated point.
 */
template <typename T>
Point4T<T> Lerp(T t, const Point4T<T>& p1, const Point4T<T>& p2);

/**
 * Returns the new point with the minimum components of the two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The new point with the minimum components of the two points.
 */
template <typename T>
Point4T<T> Min(const Point4T<T>& p1, const Point4T<T>& p2);

/**
 * Returns the new point with the maximum components of the two points.
 * @tparam T The type of the point components.
 * @param p1 The first point.
 * @param p2 The second point.
 * @return The new point with the maximum components of the two points.
 */
template <typename T>
Point4T<T> Max(const Point4T<T>& p1, const Point4T<T>& p2);

/**
 * Return the new point with permuted components.
 * @tparam T The type of the point components.
 * @param p The point to permute.
 * @param x The index of the new x component.
 * @param y The index of the new y component.
 * @param z The index of the new z component.
 * @param w The index of the new w component.
 * @return The new point with permuted components.
 */
template <typename T>
Point4T<T> Permute(const Point4T<T>& p, int x, int y, int z, int w);

/**
 * Returns the new point with each component floored.
 * @tparam T The type of the point components.
 * @param p The point to floor.
 * @return The new point with each component floored.
 */
template <typename T>
Point4T<T> Floor(const Point4T<T>& p);

/**
 * Returns the new point with each component ceilinged.
 * @tparam T The type of the point components.
 * @param p The point to ceiling.
 * @return The new point with each component ceilinged.
 */
template <typename T>
Point4T<T> Ceil(const Point4T<T>& p);

/**
 * Returns the new point with each component rounded.
 * @tparam T The type of the point components.
 * @param p The point to round.
 * @return The new point with each component rounded.
 */
template <typename T>
Point4T<T> Round(const Point4T<T>& p);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr Math::Point4T<T>::Point4T()
{
    // No initialization
}

template <typename T>
constexpr Math::Point4T<T>::Point4T(T value) : x(value), y(value), z(value), w(value)
{
}

template <typename T>
constexpr Math::Point4T<T>::Point4T(T xx, T yy, T zz, T ww) : x(xx), y(yy), z(zz), w(ww)
{
}

template <typename T>
T& Math::Point4T<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
const T& Math::Point4T<T>::operator[](int index) const
{
    return data[index];
}

template <typename T>
bool Math::Point4T<T>::operator==(const Point4T& other) const
{
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

template <typename T>
bool Math::Point4T<T>::operator!=(const Point4T& other) const
{
    return !(*this == other);
}

template <typename T>
Math::Point4T<T> Math::Point4T<T>::operator+(const Vector4T<T>& other) const
{
    return {x + other.x, y + other.y, z + other.z, w + other.w};
}

template <typename T>
Math::Point4T<T>& Math::Point4T<T>::operator+=(const Vector4T<T>& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

template <typename T>
Math::Point4T<T> Math::Point4T<T>::operator-(const Vector4T<T>& other) const
{
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}

template <typename T>
Math::Vector4T<T> Math::Point4T<T>::operator-(const Point4T& other) const
{
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}

template <typename T>
Math::Point4T<T>& Math::Point4T<T>::operator-=(const Vector4T<T>& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

template <typename T>
Math::Point4T<T> Math::Point4T<T>::operator-() const
{
    return {-x, -y, -z, -w};
}

template <typename T, typename U>
Math::Point4T<T> Math::operator*(U scalar, const Point4T<T>& vec)
{
    return vec * scalar;
}

template <typename T>
template <typename U>
Math::Point4T<T> Math::Point4T<T>::operator*(U scalar) const
{
    T sc = static_cast<T>(scalar);
    return {x * sc, y * sc, z * sc, w * sc};
}

template <typename T>
template <typename U>
Math::Point4T<T>& Math::Point4T<T>::operator*=(U scalar)
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
Math::Point4T<T> Math::Point4T<T>::operator/(U scalar) const
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
Math::Point4T<T>& Math::Point4T<T>::operator/=(U scalar)
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
bool Math::ContainsNonFinite(const Point4T<T>& vec)
{
    return !math::IsFinite(vec.x) || !math::IsFinite(vec.y) || !math::IsFinite(vec.z) ||
           !math::IsFinite(vec.w);
}

template <typename T>
bool Math::ContainsNaN(const Point4T<T>& vec)
{
    return math::IsNaN(vec.x) || math::IsNaN(vec.y) || math::IsNaN(vec.z) || math::IsNaN(vec.w);
}

template <typename T>
Math::Point4T<T> Math::Abs(const Point4T<T>& vec)
{
    return {math::Abs(vec.x), math::Abs(vec.y), math::Abs(vec.z), math::Abs(vec.w)};
}

template <typename T>
Math::Point4T<T> Math::ToEuclidean(const Point4T<T>& p)
{
    if constexpr (std::is_floating_point_v<T>)
    {
        const T div = 1 / p.w;
        return {p.x * div, p.y * div, p.z * div, 1};
    }
    if constexpr (std::is_integral_v<T>)
    {
        return {p.x / p.w, p.y / p.w, p.z / p.w, 1};
    }
}

template <typename T>
bool Math::IsEqual(const Point4T<T>& vec1, const Point4T<T>& vec2, T epsilon)
{
    return math::Abs(vec1.x - vec2.x) <= epsilon && math::Abs(vec1.y - vec2.y) <= epsilon &&
           math::Abs(vec1.z - vec2.z) <= epsilon && math::Abs(vec1.w - vec2.w) <= epsilon;
}

template <typename T>
double Math::Distance(const Point4T<T>& p1, const Point4T<T>& p2)
{
    return Length(p1 - p2);
}

template <typename T>
T Math::DistanceSquared(const Point4T<T>& p1, const Point4T<T>& p2)
{
    return LengthSquared(p1 - p2);
}

template <typename T>
Math::Point4T<T> Math::Lerp(T t, const Point4T<T>& p1, const Point4T<T>& p2)
{
    return p1 + t * (p2 - p1);
}

template <typename T>
Math::Point4T<T> Math::Min(const Point4T<T>& vec1, const Point4T<T>& vec2)
{
    return {math::Min(vec1.x, vec2.x), math::Min(vec1.y, vec2.y), math::Min(vec1.z, vec2.z),
            math::Min(vec1.w, vec2.w)};
}

template <typename T>
Math::Point4T<T> Math::Max(const Point4T<T>& vec1, const Point4T<T>& vec2)
{
    return {math::Max(vec1.x, vec2.x), math::Max(vec1.y, vec2.y), math::Max(vec1.z, vec2.z),
            math::Max(vec1.w, vec2.w)};
}

template <typename T>
Math::Point4T<T> Math::Permute(const Point4T<T>& vec, int x, int y, int z, int w)
{
    return {vec[x], vec[y], vec[z], vec[w]};
}

template <typename T>
Math::Point4T<T> Math::Floor(const Point4T<T>& p)
{
    if constexpr (std::is_integral_v<T>)
    {
        return p;
    }
    if constexpr (std::is_floating_point_v<T>)
    {
        return {math::Floor(p.x), math::Floor(p.y), math::Floor(p.z), math::Floor(p.w)};
    }
}

template <typename T>
Math::Point4T<T> Math::Ceil(const Point4T<T>& p)
{
    if constexpr (std::is_integral_v<T>)
    {
        return p;
    }
    if constexpr (std::is_floating_point_v<T>)
    {
        return {math::Ceil(p.x), math::Ceil(p.y), math::Ceil(p.z), math::Ceil(p.w)};
    }
}

template <typename T>
Math::Point4T<T> Math::Round(const Point4T<T>& p)
{
    if constexpr (std::is_integral_v<T>)
    {
        return p;
    }
    if constexpr (std::is_floating_point_v<T>)
    {
        return {math::Round(p.x), math::Round(p.y), math::Round(p.z), math::Round(p.w)};
    }
}
