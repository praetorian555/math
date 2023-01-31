#pragma once

#include "math/base.h"

namespace math
{

// Forward declarations
class Point2;
class Point4;
class Vector3;

class Point3
{
public:
    union
    {
        struct
        {
            real X, Y, Z;
        };
        real Data[3];
    };

public:
    constexpr Point3() : X(0), Y(0), Z(0) {}
    constexpr Point3(real X, real Y, real Z) : X(X), Y(Y), Z(Z) {}

    explicit Point3(const Point2& P);
    explicit Point3(const Point4& P);

    void Set(real Value, int Index);
    real operator[](int Index) const;

    bool HasNaNs() const;

    bool operator==(const Point3& Other) const;
    bool operator!=(const Point3& Other) const;

    Point3 operator+(const Vector3& Vec) const;
    Point3& operator+=(const Vector3& Vec);
    Point3 operator+(const Point3& Other) const;
    Point3& operator+=(const Point3& Other);

    Point3 operator-(const Vector3& Vec) const;
    Vector3 operator-(const Point3& Other) const;
    Point3& operator-=(const Vector3& Vec);

    Point3 operator*(real Scalar) const;
    Point3& operator*=(real Scalar);

    Point3 operator/(real Scalar) const;
    Point3& operator/=(real Scalar);

    Point3 operator-() const;

    Point3 Abs() const;
};

Point3 operator*(real Scalar, const Point3& P);

real Distance(const Point3& P1, const Point3& P2);
real DistanceSquared(const Point3& P1, const Point3& P2);
Point3 Lerp(real Param, const Point3& P1, const Point3& P2);

Point3 Floor(const Point3& P);
Point3 Ceil(const Point3& P);
Point3 Round(const Point3& P);

Point3 Min(const Point3& P1, const Point3& P2);
Point3 Max(const Point3& P1, const Point3& P2);

Point3 Permute(const Point3& P, int X, int Y, int Z);

}  // namespace math
