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
            float X, Y, Z;
        };
        float Data[3];
    };

public:
    constexpr Point3() : X(0), Y(0), Z(0) {}
    constexpr Point3(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {}

    explicit Point3(const Point2& P);
    explicit Point3(const Point4& P);

    void Set(float Value, int Index);
    float operator[](int Index) const;

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

    Point3 operator*(float Scalar) const;
    Point3& operator*=(float Scalar);

    Point3 operator/(float Scalar) const;
    Point3& operator/=(float Scalar);

    Point3 operator-() const;

    Point3 Abs() const;
};

Point3 operator*(float Scalar, const Point3& P);

float Distance(const Point3& P1, const Point3& P2);
float DistanceSquared(const Point3& P1, const Point3& P2);
Point3 Lerp(float Param, const Point3& P1, const Point3& P2);

Point3 Floor(const Point3& P);
Point3 Ceil(const Point3& P);
Point3 Round(const Point3& P);

Point3 Min(const Point3& P1, const Point3& P2);
Point3 Max(const Point3& P1, const Point3& P2);

Point3 Permute(const Point3& P, int X, int Y, int Z);

}  // namespace math
