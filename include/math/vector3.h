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
            real X, Y, Z;
        };
        struct
        {
            real R, G, B;
        };
        real Data[3];
    };

    constexpr Vector3() { X = Y = Z = 0; }
    constexpr Vector3(real X, real Y, real Z) : X(X), Y(Y), Z(Z) {}
    explicit Vector3(const Normal3& N);
    explicit Vector3(const Point3& P);
    explicit Vector3(const Vector2& XY, real ZZ = 0);

    [[nodiscard]] Vector2 XY() const;
    [[nodiscard]] Vector2 YZ() const;
    [[nodiscard]] Vector2 XZ() const;

    void Set(real Value, int Index);
    real operator[](int Index) const;

    [[nodiscard]] bool HasNaNs() const;

    bool operator==(const Vector3& Other) const;
    bool operator!=(const Vector3& Other) const;

    Vector3 operator+(const Vector3& Other) const;
    Vector3& operator+=(const Vector3& Other);
    Vector3 operator-(const Vector3& Other) const;
    Vector3& operator-=(const Vector3& Other);

    Vector3 operator*(real Scalar) const;
    Vector3& operator*=(real Scalar);
    Vector3 operator*(const Vector3& Other) const;
    Vector3& operator*=(const Vector3& Other);

    Vector3 operator/(real Scalar) const;
    Vector3& operator/=(real Scalar);

    Vector3 operator-() const;

    [[nodiscard]] Vector3 Abs() const;

    [[nodiscard]] real LengthSquared() const;
    [[nodiscard]] real Length() const;

    static const Vector3 Zero;
};

/**
 * @brief Compare two vectors if all components are equal within a given epsilon.
 * @param Vec1 First vector.
 * @param Vec2 Second vector.
 * @param Epsilon Epsilon value.
 * @return Returns true if all components are equal within a given epsilon.
 */
bool IsEqual(const Vector3& Vec1, const Vector3& Vec2, real Epsilon);

Vector3 operator*(real Scalar, const Vector3& Vec);
real Dot(const Vector3& Vec1, const Vector3& Vec2);
real AbsDot(const Vector3& Vec1, const Vector3& Vec2);

Vector3 Cross(const Vector3& Vec1, const Vector3& Vec2);
real Cross2D(const Vector3& Vec1, const Vector3& Vec2);
Vector3 Normalize(const Vector3& Vec);

real MinComponent(const Vector3& Vec);
real MaxComponent(const Vector3& Vec);
int MaxDimension(const Vector3& Vec);
Vector3 Min(const Vector3& Vec1, const Vector3& Vec2);
Vector3 Max(const Vector3& Vec1, const Vector3& Vec2);

Vector3 Permute(const Vector3& Vec, int X, int Y, int Z);
Vector3 Reflect(const Vector3& Incidence, const Vector3& Normal);
Vector3 Clamp(const Vector3& Value, real Low, real High);
}  // namespace math
