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
            real X, Y, Z, W;
        };
        struct
        {
            real R, G, B, A;
        };
        real Data[4];
    };

    constexpr Vector4() { X = Y = Z = W = 0; }
    constexpr Vector4(real X, real Y, real Z, real W) : X(X), Y(Y), Z(Z), W(W) {}

    explicit Vector4(const Point4& P);
    explicit Vector4(const Vector2& XY, real ZZ = 0, real WW = 0);
    explicit Vector4(const Vector3& XYZ, real WW = 0);

    [[nodiscard]] Vector2 XY() const;
    [[nodiscard]] Vector2 XZ() const;
    [[nodiscard]] Vector2 XW() const;
    [[nodiscard]] Vector2 YZ() const;
    [[nodiscard]] Vector2 YW() const;
    [[nodiscard]] Vector2 ZW() const;

    [[nodiscard]] Vector3 XYZ() const;
    [[nodiscard]] Vector3 XYW() const;
    [[nodiscard]] Vector3 XZW() const;
    [[nodiscard]] Vector3 YZW() const;

    void Set(real Value, int Index);
    real operator[](int Index) const;
    [[nodiscard]] bool HasNaNs() const;

    bool operator==(const Vector4& Other) const;
    bool operator!=(const Vector4& Other) const;

    Vector4 operator+(const Vector4& Other) const;
    Vector4& operator+=(const Vector4& Other);
    Vector4 operator-(const Vector4& Other) const;
    Vector4& operator-=(const Vector4& Other);

    Vector4 operator*(real Scalar) const;
    Vector4 operator*(const Vector4& Other) const;
    Vector4& operator*=(real Scalar);
    Vector4& operator*=(const Vector4& Other);

    Vector4 operator/(real Scalar) const;
    Vector4& operator/=(real Scalar);

    Vector4 operator-() const;

    [[nodiscard]] Vector4 Abs() const;

    [[nodiscard]] real LengthSquared() const;
    [[nodiscard]] real Length() const;

    static const Vector4 Zero;
};

/**
 * Check if the components of two vectors are equal within a given epsilon.
 * @param Vec1 First vector.
 * @param Vec2 Second vector.
 * @param Epsilon Epsilon value.
 * @return True if the vectors are equal, false otherwise.
 */
bool IsEqual(const Vector4& Vec1, const Vector4& Vec2, real Epsilon);

Vector4 operator*(real Scalar, const Vector4& Vec);

real Dot(const Vector4& Vec1, const Vector4& Vec2);
real AbsDot(const Vector4& Vec1, const Vector4& Vec2);

Vector4 Normalize(const Vector4& Vec);

Vector4 Min(const Vector4& Vec1, const Vector4& Vec2);
Vector4 Max(const Vector4& Vec1, const Vector4& Vec2);

Vector4 Permute(const Vector4& Vec, int X, int Y, int Z, int W);
Vector4 Clamp(const Vector4& Val, real Low, real High);

}  // namespace math
