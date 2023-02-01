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
            real X;
            real Y;
        };
        real Data[2];
    };

    constexpr Point2() : X(MATH_REALC(0.0)), Y(MATH_REALC(0.0)) {}
    constexpr Point2(real X, real Y) : X(X), Y(Y) {}
    constexpr Point2(const Point2& P) : X(P.X), Y(P.Y) {}
    explicit Point2(const Point3& P);

    void Set(real Value, int Index);
    real operator[](int Index) const;

    [[nodiscard]] bool HasNaNs() const;

    bool operator==(const Point2& Other) const;
    bool operator!=(const Point2& Other) const;

    Point2 operator+(const Vector2& Vec) const;
    Point2& operator+=(const Vector2& Vec);
    Point2 operator+(const Point2& Other) const;
    Point2& operator+=(const Point2& Other);

    Point2 operator-(const Vector2& Vec) const;
    Vector2 operator-(const Point2& Other) const;
    Point2& operator-=(const Vector2& Vec);

    Point2 operator*(real Scalar) const;
    Point2& operator*=(real Scalar);

    Point2 operator/(real Scalar) const;
    Point2& operator/=(real Scalar);

    Point2 operator-() const;

    [[nodiscard]] Point2 Abs() const;

    static const Point2 Zero;
};

Point2 operator*(real Scalar, const Point2& P);

real Distance(const Point2& P1, const Point2& P2);
real DistanceSquared(const Point2& P1, const Point2& P2);
Point2 Lerp(real Param, const Point2& P1, const Point2& P2);

Point2 Floor(const Point2& P);
Point2 Ceil(const Point2& P);
Point2 Round(const Point2& P);

Point2 Min(const Point2& P1, const Point2& P2);
Point2 Max(const Point2& P1, const Point2& P2);

Point2 Permute(const Point2& P, int X, int Y);

}  // namespace math