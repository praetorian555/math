#pragma once

#include "math/base.h"

namespace math
{

// Forward declarations
class Point3;
class Vector4;

class Point4
{
public:
    union
    {
        struct
        {
            float X, Y, Z, W;
        };
        float Data[4];
    };

public:
    Point4() : X(0), Y(0), Z(0), W(0) {}
    Point4(float X, float Y, float Z, float W) : X(X), Y(Y), Z(Z), W(W) {}
    Point4(const Point4& P) : X(P.X), Y(P.Y), Z(P.Z), W(P.W) {}

    explicit Point4(const Point3& P);

    void Set(float Val, int i);
    float operator[](int i) const;

    bool HasNaNs() const;
    bool operator==(const Point4& Other) const;
    bool operator!=(const Point4& Other) const;

    Point4 operator+(const Vector4& Vec) const;
    Point4& operator+=(const Vector4& Vec);
    Point4 operator+(const Point4& Other) const;
    Point4& operator+=(const Point4& Other);

    Point4 operator-(const Vector4& Vec) const;
    Vector4 operator-(const Point4& Other) const;
    Point4& operator-=(const Vector4& Vec);

    Point4 operator*(float Scalar) const;
    Point4& operator*=(float Scalar);

    Point4 operator/(float Scalar) const;
    Point4& operator/=(float Scalar);

    Point4 operator-() const;

    Point4 Abs() const;

    Point4 ToEuclidean() const;
};

Point4 operator*(float Scalar, const Point4& Vec);

float Distance(const Point4& Vec1, const Point4& Vec2);
float DistanceSquared(const Point4& Vec1, const Point4& Vec2);
Point4 Lerp(float t, const Point4& p0, const Point4& Vec1);

Point4 Floor(const Point4& p);
Point4 Ceil(const Point4& p);
Point4 Round(const Point4& p);

Point4 Min(const Point4& Vec1, const Point4& Vec2);
Point4 Max(const Point4& Vec1, const Point4& Vec2);

Point4 Permute(const Point4& Vec, int X, int Y, int Z, int W);

}  // namespace math
