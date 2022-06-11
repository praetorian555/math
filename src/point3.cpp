#include "math/point3.h"

#include <cassert>
#include <cmath>

#include "math/point2.h"
#include "math/point4.h"
#include "math/vector3.h"

math::Point3::Point3(const Point2& P) : X(P.X), Y(P.Y), Z(0) {}

math::Point3::Point3(const Point4& P) : X(P.X), Y(P.Y), Z(P.Z) {}

void math::Point3::Set(float Value, int Index)
{
    assert(Index >= 0 && Index < 3);
    Data[Index] = Value;
}

float math::Point3::operator[](int Index) const
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
    return Point3(X + Vec.X, Y + Vec.Y, Z + Vec.Z);
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
    return Point3(X + Other.X, Y + Other.Y, Z + Other.Z);
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
    return Point3(X - Vec.X, Y - Vec.Y, Z - Vec.Z);
}

math::Vector3 math::Point3::operator-(const Point3& Other) const
{
    return Vector3(X - Other.X, Y - Other.Y, Z - Other.Z);
}

math::Point3& math::Point3::operator-=(const Vector3& Vec)
{
    X -= Vec.X;
    Y -= Vec.Y;
    Z -= Vec.Z;
    return *this;
}

math::Point3 math::Point3::operator*(float Scalar) const
{
    return Point3(X * Scalar, Y * Scalar, Z * Scalar);
}

math::Point3& math::Point3::operator*=(float Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    Z *= Scalar;
    return *this;
}

math::Point3 math::Point3::operator/(float Scalar) const
{
    assert(Scalar != 0);
    float Rec = (float)1 / Scalar;
    return Point3(X * Rec, Y * Rec, Z * Rec);
}

math::Point3& math::Point3::operator/=(float Scalar)
{
    assert(Scalar != 0);
    float Rec = (float)1 / Scalar;
    X *= Rec;
    Y *= Rec;
    Z *= Rec;
    return *this;
}

math::Point3 math::Point3::operator-() const
{
    return Point3(-X, -Y, -Z);
}

math::Point3 math::Point3::Abs() const
{
    return Point3(std::abs(X), std::abs(Y), std::abs(Z));
}

math::Point3 math::operator*(float Scalar, const Point3& P)
{
    return P * Scalar;
}

float math::Distance(const Point3& P1, const Point3& P2)
{
    return (P1 - P2).Length();
}

float math::DistanceSquared(const Point3& P1, const Point3& P2)
{
    return (P1 - P2).LengthSquared();
}

math::Point3 math::Lerp(float t, const Point3& P1, const Point3& P2)
{
    return (1 - t) * P1 + t * P2;
}

math::Point3 math::Floor(const Point3& P)
{
    return Point3(std::floor(P.X), std::floor(P.Y), std::floor(P.Z));
}

math::Point3 math::Ceil(const Point3& P)
{
    return Point3(std::ceil(P.X), std::ceil(P.Y), std::ceil(P.Z));
}

math::Point3 math::Round(const Point3& P)
{
    return Point3(std::roundf(P.X), std::roundf(P.Y), std::roundf(P.Z));
}

math::Point3 math::Min(const Point3& P1, const Point3& P2)
{
    return Point3(std::fmin(P1.X, P2.X), std::fmin(P1.Y, P2.Y), std::fmin(P1.Z, P2.Z));
}

math::Point3 math::Max(const Point3& P1, const Point3& P2)
{
    return Point3(std::fmax(P1.X, P2.X), std::fmax(P1.Y, P2.Y), std::fmax(P1.Z, P2.Z));
}

math::Point3 math::Permute(const Point3& P, int X, int Y, int Z)
{
    return Point3(P[X], P[Y], P[Z]);
}