#include "math/vector2.h"

#include <cassert>
#include <cmath>

const math::Vector2 math::Vector2::Zero{0, 0};

void math::Vector2::Set(real Value, int Index)
{
    assert(Index >= 0 && Index < 2);
    Data[Index] = Value;
}

math::real math::Vector2::operator[](int Index) const
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
    return {X + Other.X, Y + Other.Y};
}

math::Vector2& math::Vector2::operator+=(const Vector2& Other)
{
    X += Other.X;
    Y += Other.Y;
    return *this;
}

math::Vector2 math::Vector2::operator-(const Vector2& Other) const
{
    return {X - Other.X, Y - Other.Y};
}

math::Vector2& math::Vector2::operator-=(const Vector2& Other)
{
    X -= Other.X;
    Y -= Other.Y;
    return *this;
}

math::Vector2 math::Vector2::operator*(real Scalar) const
{
    return {X * Scalar, Y * Scalar};
}

math::Vector2& math::Vector2::operator*=(real Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    return *this;
}

math::Vector2 math::Vector2::operator/(real Scalar) const
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
    return {X * Rec, Y * Rec};
}

math::Vector2& math::Vector2::operator/=(real Scalar)
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
    X *= Rec;
    Y *= Rec;
    return *this;
}

math::Vector2 math::Vector2::operator-() const
{
    return {-X, -Y};
}

math::Vector2 math::Vector2::Abs() const
{
    return {math::Abs(X), math::Abs(Y)};
}

math::real math::Vector2::LengthSquared() const
{
    return X * X + Y * Y;
}

math::real math::Vector2::Length() const
{
    return std::sqrt(LengthSquared());
}

math::Vector2 math::operator*(real Scalar, const Vector2& Vec)
{
    return Vec * Scalar;
}

math::real math::Dot(const Vector2& Vec1, const Vector2& Vec2)
{
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y;
}

math::real math::AbsDot(const Vector2& Vec1, const Vector2& Vec2)
{
    return math::Abs(Dot(Vec1, Vec2));
}

math::real math::Cross(const Vector2& Vec1, const Vector2& Vec2)
{
    return Vec1.X * Vec2.Y - Vec2.X * Vec1.Y;
}

math::Vector2 math::Normalize(const Vector2& Vec)
{
    return Vec / Vec.Length();
}

math::real math::MinComponent(const Vector2& Vec)
{
    return Min(Vec.X, Vec.Y);
}

math::real math::MaxComponent(const Vector2& Vec)
{
    return Max(Vec.X, Vec.Y);
}

int math::MaxDimension(const Vector2& Vec)
{
    return (Vec.X > Vec.Y) ? 0 : 1;
}

math::Vector2 math::Min(const Vector2& Vec1, const Vector2& Vec2)
{
    return {Min(Vec1.X, Vec2.X), Min(Vec1.Y, Vec2.Y)};
}

math::Vector2 math::Max(const Vector2& Vec1, const Vector2& Vec2)
{
    return {Max(Vec1.X, Vec2.X), Max(Vec1.Y, Vec2.Y)};
}

math::Vector2 math::Permute(const Vector2& Vec, int X, int Y)
{
    return {Vec[X], Vec[Y]};
}
