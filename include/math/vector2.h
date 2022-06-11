#pragma once

#include "math/base.h"

namespace math
{

class Vector2
{
public:
    union
    {
        struct
        {
            float X, Y;
        };
        struct
        {
            float R, G;
        };
        float Data[2];
    };

public:
    Vector2() { X = Y = 0; }
    Vector2(float X, float Y) : X(X), Y(Y) {}

    void Set(float Val, int i);
    float operator[](int i) const;

    bool HasNaNs() const;

    bool operator==(const Vector2& Other) const;
    bool operator!=(const Vector2& Other) const;

    Vector2 operator+(const Vector2& Other) const;
    Vector2& operator+=(const Vector2& Other);
    Vector2 operator-(const Vector2& Other) const;
    Vector2& operator-=(const Vector2& Other);

    Vector2 operator*(float Scalar) const;
    Vector2& operator*=(float Scalar);

    Vector2 operator/(float Scalar) const;
    Vector2& operator/=(float Scalar);

    Vector2 operator-() const;

    Vector2 Abs() const;

    float LengthSquared() const;
    float Length() const;
};

Vector2 operator*(float Scalar, const Vector2& v);

float Dot(const Vector2& Vec1, const Vector2& Vec2);
float AbsDot(const Vector2& Vec1, const Vector2& Vec2);
float Cross(const Vector2& Vec1, const Vector2& Vec2);
Vector2 Normalize(const Vector2& v);

float MinComponent(const Vector2& v);
float MaxComponent(const Vector2& v);
int MaxDimension(const Vector2& v);

Vector2 Min(const Vector2& Vec1, const Vector2& Vec2);
Vector2 Max(const Vector2& Vec1, const Vector2& Vec2);

Vector2 Permute(const Vector2& v, int X, int Y);

}  // namespace math
