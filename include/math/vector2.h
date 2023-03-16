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
            real X, Y;
        };
        struct
        {
            real R, G;
        };
        real Data[2];
    };

    constexpr Vector2() { X = Y = 0; }
    constexpr Vector2(real X, real Y) : X(X), Y(Y) {}

    void Set(real Value, int Index);
    real operator[](int Index) const;

    [[nodiscard]] bool HasNaNs() const;

    bool operator==(const Vector2& Other) const;
    bool operator!=(const Vector2& Other) const;

    Vector2 operator+(const Vector2& Other) const;
    Vector2& operator+=(const Vector2& Other);
    Vector2 operator-(const Vector2& Other) const;
    Vector2& operator-=(const Vector2& Other);

    Vector2 operator*(real Scalar) const;
    Vector2& operator*=(real Scalar);

    Vector2 operator/(real Scalar) const;
    Vector2& operator/=(real Scalar);

    Vector2 operator-() const;

    [[nodiscard]] Vector2 Abs() const;

    [[nodiscard]] real LengthSquared() const;
    [[nodiscard]] real Length() const;

    static const Vector2 Zero;
};

/**
 * @brief Compare two vectors if all components are equal within a given epsilon.
 * @param Vec1 First vector.
 * @param Vec2 Second vector.
 * @param Epsilon Epsilon value.
 * @return Returns true if all components are equal within the given epsilon.
 */
bool IsEqual(const Vector2& Vec1, const Vector2& Vec2, real Epsilon);

Vector2 operator*(real Scalar, const Vector2& Vec);

real Dot(const Vector2& Vec1, const Vector2& Vec2);
real AbsDot(const Vector2& Vec1, const Vector2& Vec2);
real Cross(const Vector2& Vec1, const Vector2& Vec2);
Vector2 Normalize(const Vector2& Vec);

real MinComponent(const Vector2& Vec);
real MaxComponent(const Vector2& Vec);
int MaxDimension(const Vector2& Vec);

Vector2 Min(const Vector2& Vec1, const Vector2& Vec2);
Vector2 Max(const Vector2& Vec1, const Vector2& Vec2);

Vector2 Permute(const Vector2& Vec, int X, int Y);

}  // namespace math
