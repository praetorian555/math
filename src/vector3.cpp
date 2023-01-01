#include "math/vector3.h"

#include <cassert>
#include <cmath>

#include "math/normal3.h"
#include "math/point3.h"

math::Vector3::Vector3(const Normal3& N) : X(N.X), Y(N.Y), Z(N.Z) {}

math::Vector3::Vector3(const Point3& P) : X(P.X), Y(P.Y), Z(P.Z) {}

math::Vector3::Vector3(const Vector2& XY, float ZZ) : X(XY.X), Y(XY.Y), Z(ZZ) {}

math::Vector2 math::Vector3::XY() const
{
    return Vector2{X, Y};
}

math::Vector2 math::Vector3::YZ() const
{
    return Vector2{Y, Z};
}

math::Vector2 math::Vector3::XZ() const
{
    return Vector2{X, Z};
}

void math::Vector3::Set(float Value, int Index)
{
    assert(Index >= 0 && Index < 3);
    Data[Index] = Value;
}

float math::Vector3::operator[](int Index) const
{
    assert(Index >= 0 && Index < 3);
    return Data[Index];
}

bool math::Vector3::HasNaNs() const
{
    return IsNaN(X) || IsNaN(Y) || IsNaN(Z);
}

bool math::Vector3::operator==(const Vector3& Other) const
{
    return X == Other.X && Y == Other.Y && Z == Other.Z;
}

bool math::Vector3::operator!=(const Vector3& Other) const
{
    return !(*this == Other);
}

math::Vector3 math::Vector3::operator+(const Vector3& Other) const
{
    return {X + Other.X, Y + Other.Y, Z + Other.Z};
}

math::Vector3& math::Vector3::operator+=(const Vector3& Other)
{
    X += Other.X;
    Y += Other.Y;
    Z += Other.Z;
    return *this;
}

math::Vector3 math::Vector3::operator-(const Vector3& Other) const
{
    return {X - Other.X, Y - Other.Y, Z - Other.Z};
}

math::Vector3& math::Vector3::operator-=(const Vector3& Other)
{
    X -= Other.X;
    Y -= Other.Y;
    Z -= Other.Z;
    return *this;
}

math::Vector3 math::Vector3::operator*(float Scalar) const
{
    return {X * Scalar, Y * Scalar, Z * Scalar};
}

math::Vector3& math::Vector3::operator*=(float Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    Z *= Scalar;
    return *this;
}

math::Vector3 math::Vector3::operator*(const Vector3& Other) const
{
    return {X * Other.X, Y * Other.Y, Z * Other.Z};
}

math::Vector3& math::Vector3::operator*=(const Vector3& Other)
{
    X *= Other.X;
    Y *= Other.Y;
    Z *= Other.Z;
    return *this;
}

math::Vector3 math::Vector3::operator/(float Scalar) const
{
    assert(Scalar != 0);
    const float Rec = (float)1 / Scalar;
    return {X * Rec, Y * Rec, Z * Rec};
}

math::Vector3& math::Vector3::operator/=(float Scalar)
{
    assert(Scalar != 0);
    const float Rec = (float)1 / Scalar;
    X *= Rec;
    Y *= Rec;
    Z *= Rec;
    return *this;
}

math::Vector3 math::Vector3::operator-() const
{
    return {-X, -Y, -Z};
}

math::Vector3 math::Vector3::Abs() const
{
    return {std::abs(X), std::abs(Y), std::abs(Z)};
}

float math::Vector3::LengthSquared() const
{
    return X * X + Y * Y + Z * Z;
}
float math::Vector3::Length() const
{
    return std::sqrt(LengthSquared());
}

math::Vector3 math::operator*(float Scalar, const Vector3& Vec)
{
    return Vec * Scalar;
}

float math::Dot(const Vector3& Vec1, const Vector3& Vec2)
{
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y + Vec1.Z * Vec2.Z;
}

float math::AbsDot(const Vector3& Vec1, const Vector3& Vec2)
{
    return std::abs(Dot(Vec1, Vec2));
}

math::Vector3 math::Cross(const Vector3& Vec1, const Vector3& Vec2)
{
    const float Vec1X = Vec1.X;
    const float Vec1Y = Vec1.Y;
    const float Vec1Z = Vec1.Z;
    const float Vec2X = Vec2.X;
    const float Vec2Y = Vec2.Y;
    const float Vec2Z = Vec2.Z;
    return {(Vec1Y * Vec2Z) - (Vec1Z * Vec2Y), (Vec1Z * Vec2X) - (Vec1X * Vec2Z),
            (Vec1X * Vec2Y) - (Vec1Y * Vec2X)};
}

float math::Cross2D(const Vector3& Vec1, const Vector3& Vec2)
{
    return Vec1.X * Vec2.Y - Vec2.X * Vec1.Y;
}

math::Vector3 math::Normalize(const Vector3& Vec)
{
    return Vec / Vec.Length();
}

float math::MinComponent(const Vector3& Vec)
{
    return std::fmin(Vec.X, std::fmin(Vec.Y, Vec.Z));
}

float math::MaxComponent(const Vector3& Vec)
{
    return std::fmax(Vec.X, std::fmax(Vec.Y, Vec.Z));
}

int math::MaxDimension(const Vector3& Vec)
{
    return (Vec.X > Vec.Y) ? (Vec.X > Vec.Z ? 0 : 2) : (Vec.Y > Vec.Z ? 1 : 2);
}

math::Vector3 math::Min(const Vector3& Vec1, const Vector3& Vec2)
{
    return {std::fmin(Vec1.X, Vec2.X), std::fmin(Vec1.Y, Vec2.Y), std::fmin(Vec1.Z, Vec2.Z)};
}

math::Vector3 math::Max(const Vector3& Vec1, const Vector3& Vec2)
{
    return {std::fmax(Vec1.X, Vec2.X), std::fmax(Vec1.Y, Vec2.Y), std::fmax(Vec1.Z, Vec2.Z)};
}

math::Vector3 math::Permute(const Vector3& Vec, int X, int Y, int Z)
{
    return {Vec[X], Vec[Y], Vec[Z]};
}

math::Vector3 math::Reflect(const Vector3& Incidence, const Vector3& Normal)
{
    assert(Dot(Incidence, Normal) >= 0);
    return 2 * Dot(Incidence, Normal) * Normal - Incidence;
}

math::Vector3 math::Clamp(const Vector3& Value, float Low, float High)
{
    return {Clamp(Value.X, Low, High), Clamp(Value.Y, Low, High), Clamp(Value.Z, Low, High)};
}
