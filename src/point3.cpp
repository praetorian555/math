#include "math/point3.h"

#include <cassert>
#include <cmath>

#include "math/point2.h"
#include "math/point4.h"
#include "math/vector3.h"

math::Point3::Point3(const Point2& P) : X(P.X), Y(P.Y), Z(0) {}

math::Point3::Point3(const Point4& P) : X(P.X), Y(P.Y), Z(P.Z) {}

void math::Point3::Set(real Value, int Index)
{
    assert(Index >= 0 && Index < 3);
    Data[Index] = Value;
}

math::real math::Point3::operator[](int Index) const
{
    assert(Index >= 0 && Index < 3);
    return Data[Index];
}

bool math::Point3::HasNaNs() const
{
    return IsNaN(X) || IsNaN(Y) || IsNaN(Z);
}

bool math::Point3::operator==(const Point3& Other) const
{
    return X == Other.X && Y == Other.Y && Z == Other.Z;
}

bool math::Point3::operator!=(const Point3& Other) const
{
    return !(*this == Other);
}

math::Point3 math::Point3::operator+(const Vector3& Vec) const
{
    return {X + Vec.X, Y + Vec.Y, Z + Vec.Z};
}

math::Point3& math::Point3::operator+=(const Vector3& Vec)
{
    X += Vec.X;
    Y += Vec.Y;
    Z += Vec.Z;
    return *this;
}

math::Point3 math::Point3::operator+(const Point3& Other) const
{
    return {X + Other.X, Y + Other.Y, Z + Other.Z};
}

math::Point3& math::Point3::operator+=(const Point3& Other)
{
    X += Other.X;
    Y += Other.Y;
    Z += Other.Z;
    return *this;
}

math::Point3 math::Point3::operator-(const Vector3& Vec) const
{
    return {X - Vec.X, Y - Vec.Y, Z - Vec.Z};
}

math::Vector3 math::Point3::operator-(const Point3& Other) const
{
    return {X - Other.X, Y - Other.Y, Z - Other.Z};
}

math::Point3& math::Point3::operator-=(const Vector3& Vec)
{
    X -= Vec.X;
    Y -= Vec.Y;
    Z -= Vec.Z;
    return *this;
}

math::Point3 math::Point3::operator*(real Scalar) const
{
    return {X * Scalar, Y * Scalar, Z * Scalar};
}

math::Point3& math::Point3::operator*=(real Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    Z *= Scalar;
    return *this;
}

math::Point3 math::Point3::operator/(real Scalar) const
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
    return {X * Rec, Y * Rec, Z * Rec};
}

math::Point3& math::Point3::operator/=(real Scalar)
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
    X *= Rec;
    Y *= Rec;
    Z *= Rec;
    return *this;
}

math::Point3 math::Point3::operator-() const
{
    return {-X, -Y, -Z};
}

math::Point3 math::Point3::Abs() const
{
    return {math::Abs(X), math::Abs(Y), math::Abs(Z)};
}

math::Point3 math::operator*(real Scalar, const Point3& P)
{
    return P * Scalar;
}

math::real math::Distance(const Point3& P1, const Point3& P2)
{
    return (P1 - P2).Length();
}

math::real math::DistanceSquared(const Point3& P1, const Point3& P2)
{
    return (P1 - P2).LengthSquared();
}

math::Point3 math::Lerp(real Param, const Point3& P1, const Point3& P2)
{
    return (1 - Param) * P1 + Param * P2;
}

math::Point3 math::Floor(const Point3& P)
{
    return {Floor(P.X), Floor(P.Y), Floor(P.Z)};
}

math::Point3 math::Ceil(const Point3& P)
{
    return {Ceil(P.X), Ceil(P.Y), Ceil(P.Z)};
}

math::Point3 math::Round(const Point3& P)
{
    return {Round(P.X), Round(P.Y), Round(P.Z)};
}

math::Point3 math::Min(const Point3& P1, const Point3& P2)
{
    return {Min(P1.X, P2.X), Min(P1.Y, P2.Y), Min(P1.Z, P2.Z)};
}

math::Point3 math::Max(const Point3& P1, const Point3& P2)
{
    return {Max(P1.X, P2.X), Max(P1.Y, P2.Y), Max(P1.Z, P2.Z)};
}

math::Point3 math::Permute(const Point3& P, int X, int Y, int Z)
{
    return {P[X], P[Y], P[Z]};
}