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
            real X, Y, Z;
        };
        real Data[3];
    };

    constexpr Normal3() { X = Y = Z = 0; }
    constexpr Normal3(real X, real Y, real Z) : X(X), Y(Y), Z(Z) {}
    explicit Normal3(const Vector3& Vec);

    void Set(real Value, int Index);
    real operator[](int Index) const;

    [[nodiscard]] bool HasNaNs() const;

    bool operator==(const Normal3& Other) const;
    bool operator!=(const Normal3& Other) const;

    Normal3 operator+(const Normal3& Other) const;
    Normal3& operator+=(const Normal3& Other);
    Normal3 operator-(const Normal3& Other) const;
    Normal3& operator-=(const Normal3& Other);

    Normal3 operator*(real Scalar) const;
    Normal3& operator*=(real Scalar);

    Normal3 operator/(real Scalar) const;
    Normal3& operator/=(real Scalar);

    Normal3 operator-() const;

    [[nodiscard]] Normal3 Abs() const;

    [[nodiscard]] real LengthSquared() const;
    [[nodiscard]] real Length() const;

    static const Normal3 Zero;
};

Normal3 operator*(real Scalar, const Normal3& N);

real Dot(const Normal3& N1, const Normal3& N2);
real Dot(const Normal3& N, const Vector3& Vec);
real Dot(const Vector3& Vec, const Normal3& N);

real AbsDot(const Normal3& N1, const Normal3& N2);
real AbsDot(const Normal3& N, const Vector3& Vec);
real AbsDot(const Vector3& Vec, const Normal3& N);

Normal3 Normalize(const Normal3& N);

real MinComponent(const Normal3& N);
real MaxComponent(const Normal3& N);
int MaxDimension(const Normal3& N);

Normal3 Min(const Normal3& N1, const Normal3& N2);
Normal3 Max(const Normal3& N1, const Normal3& N2);

Normal3 Permute(const Normal3& N, int X, int Y, int Z);

Normal3 FaceForward(const Normal3& N, const Vector3& Vec);

}  // namespace math
