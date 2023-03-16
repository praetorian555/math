#include "math/vector3.h"

#include <cassert>
#include <cmath>

#include "math/normal3.h"
#include "math/point3.h"

const math::Vector3 math::Vector3::Zero{0, 0, 0};

math::Vector3::Vector3(const Normal3& N) : X(N.X), Y(N.Y), Z(N.Z) {}

math::Vector3::Vector3(const Point3& P) : X(P.X), Y(P.Y), Z(P.Z) {}

math::Vector3::Vector3(const Vector2& XY, real ZZ) : X(XY.X), Y(XY.Y), Z(ZZ) {}

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

void math::Vector3::Set(real Value, int Index)
{
    assert(Index >= 0 && Index < 3);
    Data[Index] = Value;
}

math::real math::Vector3::operator[](int Index) const
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

math::Vector3 math::Vector3::operator*(real Scalar) const
{
    return {X * Scalar, Y * Scalar, Z * Scalar};
}

math::Vector3& math::Vector3::operator*=(real Scalar)
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

math::Vector3 math::Vector3::operator/(real Scalar) const
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
    return {X * Rec, Y * Rec, Z * Rec};
}

math::Vector3& math::Vector3::operator/=(real Scalar)
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
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
    return {math::Abs(X), math::Abs(Y), math::Abs(Z)};
}

math::real math::Vector3::LengthSquared() const
{
    return X * X + Y * Y + Z * Z;
}

math::real math::Vector3::Length() const
{
    return Sqrt(LengthSquared());
}

bool math::IsEqual(const math::Vector3& Vec1, const math::Vector3& Vec2, math::real Epsilon)
{
    return math::IsEqual(Vec1.X, Vec2.X, Epsilon) && math::IsEqual(Vec1.Y, Vec2.Y, Epsilon) &&
           math::IsEqual(Vec1.Z, Vec2.Z, Epsilon);
}

math::Vector3 math::operator*(real Scalar, const Vector3& Vec)
{
    return Vec * Scalar;
}

math::real math::Dot(const Vector3& Vec1, const Vector3& Vec2)
{
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y + Vec1.Z * Vec2.Z;
}

math::real math::AbsDot(const Vector3& Vec1, const Vector3& Vec2)
{
    return math::Abs(Dot(Vec1, Vec2));
}

math::Vector3 math::Cross(const Vector3& Vec1, const Vector3& Vec2)
{
    const real Vec1X = Vec1.X;
    const real Vec1Y = Vec1.Y;
    const real Vec1Z = Vec1.Z;
    const real Vec2X = Vec2.X;
    const real Vec2Y = Vec2.Y;
    const real Vec2Z = Vec2.Z;
    return {(Vec1Y * Vec2Z) - (Vec1Z * Vec2Y), (Vec1Z * Vec2X) - (Vec1X * Vec2Z),
            (Vec1X * Vec2Y) - (Vec1Y * Vec2X)};
}

math::real math::Cross2D(const Vector3& Vec1, const Vector3& Vec2)
{
    return Vec1.X * Vec2.Y - Vec2.X * Vec1.Y;
}

math::Vector3 math::Normalize(const Vector3& Vec)
{
    return Vec / Vec.Length();
}

math::real math::MinComponent(const Vector3& Vec)
{
    return Min(Vec.X, Min(Vec.Y, Vec.Z));
}

math::real math::MaxComponent(const Vector3& Vec)
{
    return math::Max(Vec.X, math::Max(Vec.Y, Vec.Z));
}

int math::MaxDimension(const Vector3& Vec)
{
    return (Vec.X > Vec.Y) ? (Vec.X > Vec.Z ? 0 : 2) : (Vec.Y > Vec.Z ? 1 : 2);
}

math::Vector3 math::Min(const Vector3& Vec1, const Vector3& Vec2)
{
    return {Min(Vec1.X, Vec2.X), Min(Vec1.Y, Vec2.Y), Min(Vec1.Z, Vec2.Z)};
}

math::Vector3 math::Max(const Vector3& Vec1, const Vector3& Vec2)
{
    return {math::Max(Vec1.X, Vec2.X), math::Max(Vec1.Y, Vec2.Y), math::Max(Vec1.Z, Vec2.Z)};
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

math::Vector3 math::Clamp(const Vector3& Value, real Low, real High)
{
    return {Clamp(Value.X, Low, High), Clamp(Value.Y, Low, High), Clamp(Value.Z, Low, High)};
}
