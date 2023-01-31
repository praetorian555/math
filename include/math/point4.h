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
            real X, Y, Z, W;
        };
        real Data[4];
    };

    constexpr Point4() : X(0), Y(0), Z(0), W(0) {}
    constexpr Point4(real X, real Y, real Z, real W) : X(X), Y(Y), Z(Z), W(W) {}
    constexpr Point4(const Point4& P) : X(P.X), Y(P.Y), Z(P.Z), W(P.W) {}

    explicit Point4(const Point3& P);

    void Set(real Value, int Index);
    real operator[](int Index) const;

    [[nodiscard]] bool HasNaNs() const;
    bool operator==(const Point4& Other) const;
    bool operator!=(const Point4& Other) const;

    Point4 operator+(const Vector4& Vec) const;
    Point4& operator+=(const Vector4& Vec);
    Point4 operator+(const Point4& Other) const;
    Point4& operator+=(const Point4& Other);

    Point4 operator-(const Vector4& Vec) const;
    Vector4 operator-(const Point4& Other) const;
    Point4& operator-=(const Vector4& Vec);

    Point4 operator*(real Scalar) const;
    Point4& operator*=(real Scalar);

    Point4 operator/(real Scalar) const;
    Point4& operator/=(real Scalar);

    Point4 operator-() const;

    [[nodiscard]] Point4 Abs() const;

    [[nodiscard]] Point4 ToEuclidean() const;
};

Point4 operator*(real Scalar, const Point4& Vec);

real Distance(const Point4& P1, const Point4& P2);
real DistanceSquared(const Point4& P1, const Point4& P2);
Point4 Lerp(real Param, const Point4& P1, const Point4& P2);

Point4 Floor(const Point4& P);
Point4 Ceil(const Point4& P);
Point4 Round(const Point4& P);

Point4 Min(const Point4& P1, const Point4& P2);
Point4 Max(const Point4& P1, const Point4& P2);

Point4 Permute(const Point4& P, int X, int Y, int Z, int W);

}  // namespace math
