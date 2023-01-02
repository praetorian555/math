#pragma once

#include "math/base.h"

namespace math
{

// Forward declarations
class Vector2;
class Vector3;
class Normal3;
class Point4;

class Vector4
{
public:
    union
    {
        struct
        {
            float X, Y, Z, W;
        };
        struct
        {
            float R, G, B, A;
        };
        float Data[4];
    };

public:
    Vector4() { X = Y = Z = W = 0; }
    Vector4(float X, float Y, float Z, float W) : X(X), Y(Y), Z(Z), W(W) {}

    explicit Vector4(const Point4& P);
    explicit Vector4(const Vector2& XY, float ZZ = 0, float WW = 0);
    explicit Vector4(const Vector3& XYZ, float WW = 0);

    Vector2 XY() const;
    Vector2 XZ() const;
    Vector2 XW() const;
    Vector2 YZ() const;
    Vector2 YW() const;
    Vector2 ZW() const;

    Vector3 XYZ() const;
    Vector3 XYW() const;
    Vector3 XZW() const;
    Vector3 YZW() const;

    void Set(float Value, int Index);
    float operator[](int Index) const;
    bool HasNaNs() const;

    bool operator==(const Vector4& Other) const;
    bool operator!=(const Vector4& Other) const;

    Vector4 operator+(const Vector4& Other) const;
    Vector4& operator+=(const Vector4& Other);
    Vector4 operator-(const Vector4& Other) const;
    Vector4& operator-=(const Vector4& Other);

    Vector4 operator*(float Scalar) const;
    Vector4 operator*(const Vector4& Other) const;
    Vector4& operator*=(float Scalar);
    Vector4& operator*=(const Vector4& Other);

    Vector4 operator/(float Scalar) const;
    Vector4& operator/=(float Scalar);

    Vector4 operator-() const;

    Vector4 Abs() const;

    float LengthSquared() const;
    float Length() const;
};

Vector4 operator*(float Scalar, const Vector4& Vec);

float Dot(const Vector4& Vec1, const Vector4& Vec2);
float AbsDot(const Vector4& Vec1, const Vector4& Vec2);

Vector4 Normalize(const Vector4& Vec);

Vector4 Min(const Vector4& Vec1, const Vector4& Vec2);
Vector4 Max(const Vector4& Vec1, const Vector4& Vec2);

Vector4 Permute(const Vector4& Vec, int X, int Y, int Z, int W);
Vector4 Clamp(const Vector4& Val, float Low, float High);

}  // namespace math
