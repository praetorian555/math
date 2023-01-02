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
    Point2(const Point2& P) : X(P.X), Y(P.Y) {}
    explicit Point2(const Point3& P);

    void Set(float Value, int Index);
    float operator[](int Index) const;

    bool HasNaNs() const;

    bool operator==(const Point2& Other) const;
    bool operator!=(const Point2& Other) const;

    Point2 operator+(const Vector2& Vec) const;
    Point2& operator+=(const Vector2& Vec);
    Point2 operator+(const Point2& Other) const;
    Point2& operator+=(const Point2& Other);

    Point2 operator-(const Vector2& Vec) const;
    Vector2 operator-(const Point2& Other) const;
    Point2& operator-=(const Vector2& Vec);

    Point2 operator*(float Scalar) const;
    Point2& operator*=(float Scalar);

    Point2 operator/(float Scalar) const;
    Point2& operator/=(float Scalar);

    Point2 operator-() const;

    Point2 Abs() const;
};

Point2 operator*(float Scalar, const Point2& P);

float Distance(const Point2& P1, const Point2& P2);
float DistanceSquared(const Point2& P1, const Point2& P2);
Point2 Lerp(float Param, const Point2& P1, const Point2& P2);

Point2 Floor(const Point2& P);
Point2 Ceil(const Point2& P);
Point2 Round(const Point2& P);

Point2 Min(const Point2& P1, const Point2& P2);
Point2 Max(const Point2& P1, const Point2& P2);

Point2 Permute(const Point2& P, int X, int Y);

}  // namespace math