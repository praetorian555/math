#include "math/vector2.h"

#include <cassert>
#include <cmath>

void math::Vector2::Set(float Value, int Index)
{
    assert(Index >= 0 && Index < 2);
    Data[Index] = Value;
}

float math::Vector2::operator[](int Index) const
{
    assert(Index >= 0 && Index < 2);
    return Data[Index];
}

bool math::Vector2::HasNaNs() const
{
    return IsNaN(X) || IsNaN(Y);
}

bool math::Vector2::operator==(const Vector2& Other) const
{
    return X == Other.X && Y == Other.Y;
}

bool math::Vector2::operator!=(const Vector2& Other) const
{
    return !(*this == Other);
}

math::Vector2 math::Vector2::operator+(const Vector2& Other) const
{
    return Vector2(X + Other.X, Y + Other.Y);
}

math::Vector2& math::Vector2::operator+=(const Vector2& Other)
{
    X += Other.X;
    Y += Other.Y;
    return *this;
}

math::Vector2 math::Vector2::operator-(const Vector2& Other) const
{
    return Vector2(X - Other.X, Y - Other.Y);
}

math::Vector2& math::Vector2::operator-=(const Vector2& Other)
{
    X -= Other.X;
    Y -= Other.Y;
    return *this;
}

math::Vector2 math::Vector2::operator*(float Scalar) const
{
    return Vector2(X * Scalar, Y * Scalar);
}

math::Vector2& math::Vector2::operator*=(float Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    return *this;
}

math::Vector2 math::Vector2::operator/(float Scalar) const
{
    assert(Scalar != 0);
    const float Rec = (float)1 / Scalar;
    return Vector2(X * Rec, Y * Rec);
}

math::Vector2& math::Vector2::operator/=(float Scalar)
{
    assert(Scalar != 0);
    const float Rec = (float)1 / Scalar;
    X *= Rec;
    Y *= Rec;
    return *this;
}

math::Vector2 math::Vector2::operator-() const
{
    return Vector2(-X, -Y);
}

math::Vector2 math::Vector2::Abs() const
{
    return Vector2(std::abs(X), std::abs(Y));
}

float math::Vector2::LengthSquared() const
{
    return X * X + Y * Y;
}

float math::Vector2::Length() const
{
    return std::sqrt(LengthSquared());
}

math::Vector2 math::operator*(float Scalar, const Vector2& Vec)
{
    return Vec * Scalar;
}

float math::Dot(const Vector2& Vec1, const Vector2& Vec2)
{
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y;
}

float math::AbsDot(const Vector2& Vec1, const Vector2& Vec2)
{
    return std::abs(Dot(Vec1, Vec2));
}

float math::Cross(const Vector2& Vec1, const Vector2& Vec2)
{
    return Vec1.X * Vec2.Y - Vec2.X * Vec1.Y;
}

math::Vector2 math::Normalize(const Vector2& Vec)
{
    return Vec / Vec.Length();
}

float math::MinComponent(const Vector2& Vec)
{
    return std::fmin(Vec.X, Vec.Y);
}

float math::MaxComponent(const Vector2& Vec)
{
    return std::fmax(Vec.X, Vec.Y);
}

int math::MaxDimension(const Vector2& Vec)
{
    return (Vec.X > Vec.Y) ? 0 : 1;
}

math::Vector2 math::Min(const Vector2& Vec1, const Vector2& Vec2)
{
    return Vector2(std::fmin(Vec1.X, Vec2.X), std::fmin(Vec1.Y, Vec2.Y));
}

math::Vector2 math::Max(const Vector2& Vec1, const Vector2& Vec2)
{
    return Vector2(std::fmax(Vec1.X, Vec2.X), std::fmax(Vec1.Y, Vec2.Y));
}

math::Vector2 math::Permute(const Vector2& Vec, int X, int Y)
{
    return Vector2(Vec[X], Vec[Y]);
}
