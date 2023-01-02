#pragma once

#include "math/base.h"
#include "math/vector2.h"

namespace math
{

// Forward declarations
class Vector4;
class Normal3;
class Point3;

class Vector3
{
public:
    union
    {
        struct
        {
            float X, Y, Z;
        };
        struct
        {
            float R, G, B;
        };
        float Data[3];
    };

public:
    Vector3() { X = Y = Z = 0; }
    Vector3(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {}
    explicit Vector3(const Normal3& N);
    explicit Vector3(const Point3& P);
    explicit Vector3(const Vector2& XY, float ZZ = 0);

    Vector2 XY() const;
    Vector2 YZ() const;
    Vector2 XZ() const;

    void Set(float Value, int Index);
    float operator[](int Index) const;

    bool HasNaNs() const;

    bool operator==(const Vector3& Other) const;
    bool operator!=(const Vector3& Other) const;

    Vector3 operator+(const Vector3& Other) const;
    Vector3& operator+=(const Vector3& Other);
    Vector3 operator-(const Vector3& Other) const;
    Vector3& operator-=(const Vector3& Other);

    Vector3 operator*(float Scalar) const;
    Vector3& operator*=(float Scalar);
    Vector3 operator*(const Vector3& Other) const;
    Vector3& operator*=(const Vector3& Other);

    Vector3 operator/(float Scalar) const;
    Vector3& operator/=(float Scalar);

    Vector3 operator-() const;

    Vector3 Abs() const;

    float LengthSquared() const;
    float Length() const;
};

Vector3 operator*(float Scalar, const Vector3& Vec);
float Dot(const Vector3& Vec1, const Vector3& Vec2);
float AbsDot(const Vector3& Vec1, const Vector3& Vec2);

Vector3 Cross(const Vector3& Vec1, const Vector3& Vec2);
float Cross2D(const Vector3& Vec1, const Vector3& Vec2);
Vector3 Normalize(const Vector3& Vec);

float MinComponent(const Vector3& Vec);
float MaxComponent(const Vector3& Vec);
int MaxDimension(const Vector3& Vec);
Vector3 Min(const Vector3& Vec1, const Vector3& Vec2);
Vector3 Max(const Vector3& Vec1, const Vector3& Vec2);

Vector3 Permute(const Vector3& Vec, int X, int Y, int Z);
Vector3 Reflect(const Vector3& Incidence, const Vector3& Normal);
Vector3 Clamp(const Vector3& Value, float Low, float High);
}  // namespace math
