﻿#pragma once

#include "math/base.h"
#include "math/impl/point3.h"
#include "math/impl/vector2.h"

namespace math
{

// Forward declarations
template <typename T>
class Point3;

template <typename T>
class Point2
{
public:
    union
    {
        struct
        {
            T X, Y;
        };
        T Data[2];
    };

public:
    Point2() : X(0), Y(0) {}
    Point2(T X, T Y) : X(X), Y(Y) { MATH_ASSERT(!HasNaNs()); }
    Point2(const Point2<T>& p3) : X(p3.X), Y(p3.Y) { MATH_ASSERT(!HasNaNs()); }

    template <typename U>
    explicit Point2(const Point2<U>& p) : X((T)p.X), Y((T)p.Y)
    {
        MATH_ASSERT(!HasNaNs());
    }

    template <typename U>
    explicit Point2(const Point3<U>& p);

    void Set(T val, int i)
    {
        MATH_ASSERT(i >= 0 && i < 2);
        if (i == 0)
            X = val;
        if (i == 1)
            Y = val;
    }

    T operator[](int i) const
    {
        MATH_ASSERT(i >= 0 && i < 2);
        if (i == 0)
            return X;
        else
            return Y;
    }

    bool HasNaNs() const { return IsNaN(X) || IsNaN(Y); }

    bool operator==(const Point2<T>& other) const { return X == other.X && Y == other.Y; }

    bool operator!=(const Point2<T>& other) const { return !(*this == other); }

    Point2<T> operator+(const Vector2<T>& v) const { return Point2(X + v.X, Y + v.Y); }

    Point2<T>& operator+=(const Vector2<T>& v)
    {
        X += v.X;
        Y += v.Y;
        return *this;
    }

    Point2<T> operator+(const Point2<T>& other) const { return Point2(X + other.X, Y + other.Y); }

    Point2<T>& operator+=(const Point2<T>& other)
    {
        X += other.X;
        Y += other.Y;
        return *this;
    }

    template <typename U>
    Point2<T> operator+(const U& Value) const
    {
        return Point2(X + Value, Y + Value);
    }

    template <typename U>
    Point2<T>& operator+=(const U& Value)
    {
        X += Value;
        Y += Value;
        return *this;
    }

    Point2<T> operator-(const Vector2<T>& v) const { return Point2(X - v.X, Y - v.Y); }

    Vector2<T> operator-(const Point2<T>& other) const { return Vector2(X - other.X, Y - other.Y); }

    Point2<T>& operator-=(const Vector2<T>& v)
    {
        X -= v.X;
        Y -= v.Y;
        return *this;
    }

    Point2<T> operator*(T scalar) const { return Point2(X * scalar, Y * scalar); }

    Point2<T>& operator*=(T scalar)
    {
        X *= scalar;
        Y *= scalar;
        return *this;
    }

    template <typename S>
    Point2<T> operator/(S scalar) const
    {
        MATH_ASSERT(scalar != 0);
        float rec = (float)1 / scalar;
        return Point2(X * rec, Y * rec);
    }

    template <typename S>
    Point2<T>& operator/=(S scalar)
    {
        MATH_ASSERT(scalar != 0);
        float rec = (float)1 / scalar;
        X *= rec;
        Y *= rec;
        return *this;
    }

    Point2<T> operator-() const { return Point2(-X, -Y); }

    Point2<T> Abs() const { return Point2(std::abs(X), std::abs(Y)); }
};

template <typename T>
inline Point2<T> operator*(T scalar, const Point2<T>& v)
{
    return v * scalar;
}

template <typename T>
inline float Distance(const Point2<T>& p1, const Point2<T>& p2)
{
    return (p1 - p2).Length();
}
template <typename T>
inline float DistanceSquared(const Point2<T>& p1, const Point2<T>& p2)
{
    return (p1 - p2).LengthSquared();
}

template <typename T>
Point2<T> Lerp(float t, const Point2<T>& p0, const Point2<T>& p1)
{
    return (1 - t) * p0 + t * p1;
}

template <typename T>
Point2<T> Floor(const Point2<T>& p)
{
    return Point2<T>(std::floor(p.X), std::floor(p.Y));
}
template <typename T>
Point2<T> Ceil(const Point2<T>& p)
{
    return Point2<T>(std::ceil(p.X), std::ceil(p.Y));
}

template <typename T>
Point2<T> Round(const Point2<T>& p)
{
    return Point2<T>(std::roundf(p.X), std::roundf(p.Y));
}

template <typename T>
Point2<T> Min(const Point2<T>& v1, const Point2<T>& v2)
{
    return Point2<T>(std::min(v1.X, v2.X), std::min(v1.Y, v2.Y));
}

template <typename T>
Point2<T> Max(const Point2<T>& v1, const Point2<T>& v2)
{
    return Point2<T>(std::max(v1.X, v2.X), std::max(v1.Y, v2.Y));
}

template <typename T>
Point2<T> Permute(const Point2<T>& v, int x, int y)
{
    return Point2<T>(v[x], v[y]);
}

}  // namespace math