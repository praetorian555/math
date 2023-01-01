#include "math/normal3.h"

#include <cassert>
#include <cmath>

#include "math/vector3.h"

math::Normal3::Normal3(const Vector3& Vec) : X(Vec.X), Y(Vec.Y), Z(Vec.Z) {}

void math::Normal3::Set(float Value, int Index)
{
    assert(Index >= 0 && Index < 3);
    Data[Index] = Value;
}

float math::Normal3::operator[](int Index) const
{
    assert(Index >= 0 && Index < 3);
    return Data[Index];
}

bool math::Normal3::HasNaNs() const
{
    return IsNaN(X) || IsNaN(Y) || IsNaN(Z);
}

bool math::Normal3::operator==(const Normal3& Other) const
{
    return X == Other.X && Y == Other.Y && Z == Other.Z;
}

bool math::Normal3::operator!=(const Normal3& Other) const
{
    return !(*this == Other);
}

math::Normal3 math::Normal3::operator+(const Normal3& Other) const
{
    return {X + Other.X, Y + Other.Y, Z + Other.Z};
}

math::Normal3& math::Normal3::operator+=(const Normal3& Other)
{
    X += Other.X;
    Y += Other.Y;
    Z += Other.Z;
    return *this;
}

math::Normal3 math::Normal3::operator-(const Normal3& Other) const
{
    return {X - Other.X, Y - Other.Y, Z - Other.Z};
}

math::Normal3& math::Normal3::operator-=(const Normal3& Other)
{
    X -= Other.X;
    Y -= Other.Y;
    Z -= Other.Z;
    return *this;
}

math::Normal3 math::Normal3::operator*(float Scalar) const
{
    return {X * Scalar, Y * Scalar, Z * Scalar};
}

math::Normal3& math::Normal3::operator*=(float Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    Z *= Scalar;
    return *this;
}

math::Normal3 math::Normal3::operator/(float Scalar) const
{
    assert(Scalar != 0);
    const float Rec = 1.0f / Scalar;
    return {X * Rec, Y * Rec, Z * Rec};
}

math::Normal3& math::Normal3::operator/=(float Scalar)
{
    assert(Scalar != 0);
    const float Rec = 1.0f / Scalar;
    X *= Rec;
    Y *= Rec;
    Z *= Rec;
    return *this;
}

math::Normal3 math::Normal3::operator-() const
{
    return {-X, -Y, -Z};
}

math::Normal3 math::Normal3::Abs() const
{
    return {std::abs(X), std::abs(Y), std::abs(Z)};
}

float math::Normal3::LengthSquared() const
{
    return X * X + Y * Y + Z * Z;
}
float math::Normal3::Length() const
{
    return std::sqrt(LengthSquared());
}

math::Normal3 math::operator*(float Scalar, const Normal3& Vec)
{
    return Vec * Scalar;
}

float math::Dot(const Normal3& Vec1, const Normal3& Vec2)
{
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y + Vec1.Z * Vec2.Z;
}

float math::Dot(const Normal3& Vec1, const Vector3& Vec2)
{
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y + Vec1.Z * Vec2.Z;
}

float math::Dot(const Vector3& Vec1, const Normal3& Vec2)
{
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y + Vec1.Z * Vec2.Z;
}

float math::AbsDot(const Normal3& Vec1, const Normal3& Vec2)
{
    return std::abs(Dot(Vec1, Vec2));
}

float math::AbsDot(const Normal3& Vec1, const Vector3& Vec2)
{
    return std::abs(Dot(Vec1, Vec2));
}

float math::AbsDot(const Vector3& Vec1, const Normal3& Vec2)
{
    return std::abs(Dot(Vec1, Vec2));
}

math::Normal3 math::Normalize(const Normal3& Vec)
{
    return Vec / Vec.Length();
}

float math::MinComponent(const Normal3& Vec)
{
    return std::fmin(Vec.X, std::fmin(Vec.Y, Vec.Z));
}

float math::MaxComponent(const Normal3& Vec)
{
    return std::fmax(Vec.X, std::fmax(Vec.Y, Vec.Z));
}

int math::MaxDimension(const Normal3& Vec)
{
    return (Vec.X > Vec.Y) ? (Vec.X > Vec.Z ? 0 : 2) : (Vec.Y > Vec.Z ? 1 : 2);
}

math::Normal3 math::Min(const Normal3& N1, const Normal3& N2)
{
    return {std::fmin(N1.X, N2.X), std::fmin(N1.Y, N2.Y), std::fmin(N1.Z, N2.Z)};
}

math::Normal3 math::Max(const Normal3& Vec1, const Normal3& Vec2)
{
    return {std::fmax(Vec1.X, Vec2.X), std::fmax(Vec1.Y, Vec2.Y), std::fmax(Vec1.Z, Vec2.Z)};
}

math::Normal3 math::Permute(const Normal3& N, int X, int Y, int Z)
{
    return {N[X], N[Y], N[Z]};
}

math::Normal3 math::Faceforward(const Normal3& N, const Vector3& Vec)
{
    return (Dot(N, Vec) < 0.f) ? -N : N;
}
