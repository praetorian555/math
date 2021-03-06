#pragma once

#include "math/base.h"

namespace math
{

// Forward declarations
class Point3;
class Vector2;

class Point2
{
public:
    union
    {
        struct
        {
            float X, Y;
        };
        float Data[2];
    };

public:
    Point2() : X(0), Y(0) {}
    Point2(float X, float Y) : X(X), Y(Y) {}
    Point2(const Point2& p3) : X(p3.X), Y(p3.Y) {}
    explicit Point2(const Point3& p);

    void Set(float Val, int i);
    float operator[](int i) const;

    bool HasNaNs() const;

    bool operator==(const Point2& Other) const;
    bool operator!=(const Point2& Other) const;

    Point2 operator+(const Vector2& v) const;
    Point2& operator+=(const Vector2& v);
    Point2 operator+(const Point2& Other) const;
    Point2& operator+=(const Point2& Other);

    Point2 operator-(const Vector2& v) const;
    Vector2 operator-(const Point2& Other) const;
    Point2& operator-=(const Vector2& v);

    Point2 operator*(float Scalar) const;
    Point2& operator*=(float Scalar);

    Point2 operator/(float Scalar) const;
    Point2& operator/=(float Scalar);

    Point2 operator-() const;

    Point2 Abs() const;
};

Point2 operator*(float Scalar, const Point2& v);

float Distance(const Point2& Vec1, const Point2& Vec2);
float DistanceSquared(const Point2& Vec1, const Point2& Vec2);
Point2 Lerp(float t, const Point2& p0, const Point2& Vec1);

Point2 Floor(const Point2& p);
Point2 Ceil(const Point2& p);
Point2 Round(const Point2& p);

Point2 Min(const Point2& Vec1, const Point2& Vec2);
Point2 Max(const Point2& Vec1, const Point2& Vec2);

Point2 Permute(const Point2& v, int x, int y);

}  // namespace math