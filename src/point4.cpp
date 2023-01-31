#include "math/point4.h"

#include <cassert>
#include <cmath>

#include "math/point3.h"
#include "math/vector4.h"

math::Point4::Point4(const Point3& P) : X(P.X), Y(P.Y), Z(P.Z), W(0) {}

void math::Point4::Set(real Value, int Index)
{
    assert(Index >= 0 && Index < 4);
    Data[Index] = Value;
}

math::real math::Point4::operator[](int Index) const
{
    assert(Index >= 0 && Index < 4);
    return Data[Index];
}

bool math::Point4::HasNaNs() const
{
    return IsNaN(X) || IsNaN(Y) || IsNaN(Z) || IsNaN(W);
}

bool math::Point4::operator==(const Point4& Other) const
{
    return X == Other.X && Y == Other.Y && Z == Other.Z && W == Other.W;
}

bool math::Point4::operator!=(const Point4& Other) const
{
    return !(*this == Other);
}

math::Point4 math::Point4::operator+(const Vector4& Vec) const
{
    return {X + Vec.X, Y + Vec.Y, Z + Vec.Z, W + Vec.W};
}

math::Point4& math::Point4::operator+=(const Vector4& Vec)
{
    X += Vec.X;
    Y += Vec.Y;
    Z += Vec.Z;
    W += Vec.W;
    return *this;
}

math::Point4 math::Point4::operator+(const Point4& Other) const
{
    return {X + Other.X, Y + Other.Y, Z + Other.Z, W + Other.W};
}

math::Point4& math::Point4::operator+=(const Point4& Other)
{
    X += Other.X;
    Y += Other.Y;
    Z += Other.Z;
    W += Other.W;
    return *this;
}

math::Point4 math::Point4::operator-(const Vector4& Vec) const
{
    return {X - Vec.X, Y - Vec.Y, Z - Vec.Z, W - Vec.W};
}

math::Vector4 math::Point4::operator-(const Point4& Other) const
{
    return {X - Other.X, Y - Other.Y, Z - Other.Z, W - Other.W};
}

math::Point4& math::Point4::operator-=(const Vector4& Vec)
{
    X -= Vec.X;
    Y -= Vec.Y;
    Z -= Vec.Z;
    W -= Vec.W;
    return *this;
}

math::Point4 math::Point4::operator*(real Scalar) const
{
    return {X * Scalar, Y * Scalar, Z * Scalar, W * Scalar};
}

math::Point4& math::Point4::operator*=(real Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    Z *= Scalar;
    W *= Scalar;
    return *this;
}

math::Point4 math::Point4::operator/(real Scalar) const
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
    return {X * Rec, Y * Rec, Z * Rec, W * Rec};
}

math::Point4& math::Point4::operator/=(real Scalar)
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
    X *= Rec;
    Y *= Rec;
    Z *= Rec;
    W *= Rec;
    return *this;
}

math::Point4 math::Point4::operator-() const
{
    return {-X, -Y, -Z, -W};
}

math::Point4 math::Point4::Abs() const
{
    return {math::Abs(X), math::Abs(Y), math::Abs(Z), math::Abs(W)};
}

math::Point4 math::Point4::ToEuclidean() const
{
    assert(W != 0);
    const real Div = 1 / W;
    return {X * Div, Y * Div, Z * Div, 1};
}

math::Point4 math::operator*(real Scalar, const Point4& Vec)
{
    return Vec * Scalar;
}

math::real math::Distance(const Point4& P1, const Point4& P2)
{
    return (P1 - P2).Length();
}

math::real math::DistanceSquared(const Point4& P1, const Point4& P2)
{
    return (P1 - P2).LengthSquared();
}

math::Point4 math::Lerp(real Param, const Point4& P1, const Point4& P2)
{
    return (1 - Param) * P1 + Param * P2;
}

math::Point4 math::Floor(const Point4& P)
{
    return {Floor(P.X), Floor(P.Y), Floor(P.Z), Floor(P.W)};
}

math::Point4 math::Ceil(const Point4& P)
{
    return {Ceil(P.X), Ceil(P.Y), Ceil(P.Z), Ceil(P.W)};
}

math::Point4 math::Round(const Point4& P)
{
    return {Round(P.X), Round(P.Y), Round(P.Z), Round(P.W)};
}

math::Point4 math::Min(const Point4& P1, const Point4& P2)
{
    return {Min(P1.X, P2.X), Min(P1.Y, P2.Y), Min(P1.Z, P2.Z), Min(P1.W, P2.W)};
}

math::Point4 math::Max(const Point4& P1, const Point4& P2)
{
    return {Max(P1.X, P2.X), Max(P1.Y, P2.Y), Max(P1.Z, P2.Z), Max(P1.W, P2.W)};
}

math::Point4 math::Permute(const Point4& P, int X, int Y, int Z, int W)
{
    return {P[X], P[Y], P[Z], P[W]};
}
