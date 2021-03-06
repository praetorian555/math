#pragma once

#include "math/base.h"

namespace math
{

// Forward declarations
class Vector3;

class Normal3
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
    Normal3() { X = Y = Z = 0; }
    Normal3(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {}
    explicit Normal3(const Vector3& v);

    void Set(float val, int i);
    float operator[](int i) const;

    bool HasNaNs() const;

    bool operator==(const Normal3& Other) const;
    bool operator!=(const Normal3& Other) const;

    Normal3 operator+(const Normal3& Other) const;
    Normal3& operator+=(const Normal3& Other);
    Normal3 operator-(const Normal3& Other) const;
    Normal3& operator-=(const Normal3& Other);

    Normal3 operator*(float Scalar) const;
    Normal3& operator*=(float Scalar);

    Normal3 operator/(float Scalar) const;
    Normal3& operator/=(float Scalar);

    Normal3 operator-() const;

    Normal3 Abs() const;

    float LengthSquared() const;
    float Length() const;
};

Normal3 operator*(float Scalar, const Normal3& v);

float Dot(const Normal3& Vec1, const Normal3& Vec2);
float Dot(const Normal3& Vec1, const Vector3& Vec2);
float Dot(const Vector3& Vec1, const Normal3& Vec2);

float AbsDot(const Normal3& Vec1, const Normal3& Vec2);
float AbsDot(const Normal3& Vec1, const Vector3& Vec2);
float AbsDot(const Vector3& Vec1, const Normal3& Vec2);

Normal3 Normalize(const Normal3& v);

float MinComponent(const Normal3& v);
float MaxComponent(const Normal3& v);
int MaxDimension(const Normal3& v);

Normal3 Min(const Normal3& N1, const Normal3& N2);
Normal3 Max(const Normal3& Vec1, const Normal3& Vec2);

Normal3 Permute(const Normal3& v, int X, int Y, int Z);

Normal3 Faceforward(const Normal3& n, const Vector3& v);

}  // namespace math
