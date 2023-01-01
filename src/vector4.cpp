#include "math/vector4.h"

#include <cassert>
#include <cmath>

#include "math/point4.h"
#include "math/vector2.h"
#include "math/vector3.h"

math::Vector4::Vector4(const Point4& P) : X(P.X), Y(P.Y), Z(P.Z), W(P.W) {}

math::Vector4::Vector4(const Vector2& XY, float ZZ, float WW) : X(XY.X), Y(XY.Y), Z(ZZ), W(WW) {}

math::Vector4::Vector4(const Vector3& XYZ, float WW) : X(XYZ.X), Y(XYZ.Y), Z(XYZ.Z), W(WW) {}

math::Vector2 math::Vector4::XY() const
{
    return Vector2{X, Y};
}

math::Vector2 math::Vector4::XZ() const
{
    return Vector2{X, Z};
}

math::Vector2 math::Vector4::XW() const
{
    return Vector2{X, W};
}

math::Vector2 math::Vector4::YZ() const
{
    return Vector2{Y, Z};
}

math::Vector2 math::Vector4::YW() const
{
    return Vector2{Y, W};
}

math::Vector2 math::Vector4::ZW() const
{
    return Vector2{Z, W};
}

math::Vector3 math::Vector4::XYZ() const
{
    return Vector3{X, Y, Z};
}

math::Vector3 math::Vector4::XYW() const
{
    return Vector3{X, Y, W};
}

math::Vector3 math::Vector4::XZW() const
{
    return Vector3{X, Z, W};
}

math::Vector3 math::Vector4::YZW() const
{
    return Vector3{Y, Z, W};
}

void math::Vector4::Set(float Value, int Index)
{
    assert(Index >= 0 && Index < 4);
    Data[Index] = Value;
}

float math::Vector4::operator[](int Index) const
{
    assert(Index >= 0 && Index < 4);
    return Data[Index];
}

bool math::Vector4::HasNaNs() const
{
    return IsNaN(X) || IsNaN(Y) || IsNaN(Z) || IsNaN(W);
}

bool math::Vector4::operator==(const Vector4& Other) const
{
    return X == Other.X && Y == Other.Y && Z == Other.Z && W == Other.W;
}

bool math::Vector4::operator!=(const Vector4& Other) const
{
    return !(*this == Other);
}

math::Vector4 math::Vector4::operator+(const Vector4& Other) const
{
    return {X + Other.X, Y + Other.Y, Z + Other.Z, W + Other.W};
}

math::Vector4& math::Vector4::operator+=(const Vector4& Other)
{
    X += Other.X;
    Y += Other.Y;
    Z += Other.Z;
    W += Other.W;
    return *this;
}

math::Vector4 math::Vector4::operator-(const Vector4& Other) const
{
    return {X - Other.X, Y - Other.Y, Z - Other.Z, W - Other.W};
}

math::Vector4& math::Vector4::operator-=(const Vector4& Other)
{
    X -= Other.X;
    Y -= Other.Y;
    Z -= Other.Z;
    W -= Other.W;
    return *this;
}

math::Vector4 math::Vector4::operator*(float Scalar) const
{
    return {X * Scalar, Y * Scalar, Z * Scalar, W * Scalar};
}

math::Vector4 math::Vector4::operator*(const Vector4& Other) const
{
    return {X * Other.X, Y * Other.Y, Z * Other.Z, W * Other.W};
}

math::Vector4& math::Vector4::operator*=(float Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    Z *= Scalar;
    W *= Scalar;
    return *this;
}

math::Vector4& math::Vector4::operator*=(const Vector4& Other)
{
    X *= Other.X;
    Y *= Other.Y;
    Z *= Other.Z;
    W *= Other.W;
    return *this;
}

math::Vector4 math::Vector4::operator/(float Scalar) const
{
    assert(Scalar != 0);
    const float Rec = 1.0f / Scalar;
    return {X * Rec, Y * Rec, Z * Rec, W * Rec};
}

math::Vector4& math::Vector4::operator/=(float Scalar)
{
    assert(Scalar != 0);
    const float Rec = 1.0f / Scalar;
    X *= Rec;
    Y *= Rec;
    Z *= Rec;
    W *= Rec;
    return *this;
}

math::Vector4 math::Vector4::operator-() const
{
    return {-X, -Y, -Z, -W};
}

math::Vector4 math::Vector4::Abs() const
{
    return {std::abs(X), std::abs(Y), std::abs(Z), std::abs(W)};
}

float math::Vector4::LengthSquared() const
{
    return X * X + Y * Y + Z * Z + W * W;
}
float math::Vector4::Length() const
{
    return std::sqrt(LengthSquared());
}

math::Vector4 math::operator*(float Scalar, const Vector4& Vec)
{
    return Vec * Scalar;
}

float math::Dot(const Vector4& Vec1, const Vector4& Vec2)
{
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y + Vec1.Z * Vec2.Z + Vec1.W * Vec2.W;
}

float math::AbsDot(const Vector4& Vec1, const Vector4& Vec2)
{
    return std::abs(Dot(Vec1, Vec2));
}

math::Vector4 math::Normalize(const Vector4& Vec)
{
    return Vec / Vec.Length();
}

math::Vector4 math::Min(const Vector4& Vec1, const Vector4& Vec2)
{
    return {std::fmin(Vec1.X, Vec2.X), std::fmin(Vec1.Y, Vec2.Y), std::fmin(Vec1.Z, Vec2.Z),
            std::fmin(Vec1.W, Vec2.W)};
}

math::Vector4 math::Max(const Vector4& Vec1, const Vector4& Vec2)
{
    return {std::fmax(Vec1.X, Vec2.X), std::fmax(Vec1.Y, Vec2.Y), std::fmax(Vec1.Z, Vec2.Z),
            std::fmax(Vec1.W, Vec2.W)};
}

math::Vector4 math::Permute(const Vector4& Vec, int X, int Y, int Z, int W)
{
    return {Vec[X], Vec[Y], Vec[Z], Vec[W]};
}

math::Vector4 math::Clamp(const Vector4& Val, float Low, float High)
{
    return {Clamp(Val.X, Low, High), Clamp(Val.Y, Low, High), Clamp(Val.Z, Low, High),
            Clamp(Val.W, Low, High)};
}
