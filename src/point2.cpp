#include "math/point2.h"

#include <cassert>
#include <cmath>

#include "math/point3.h"
#include "math/vector2.h"

math::Point2::Point2(const Point3& P) : X(P.X), Y(P.Y) {}

void math::Point2::Set(float Value, int Index)
{
    assert(Index >= 0 && Index < 2);
    Data[Index] = Value;
}

float math::Point2::operator[](int Index) const
{
    assert(Index >= 0 && Index < 2);
    return Data[Index];
}

bool math::Point2::HasNaNs() const
{
    return IsNaN(X) || IsNaN(Y);
}

bool math::Point2::operator==(const Point2& Other) const
{
    return X == Other.X && Y == Other.Y;
}

bool math::Point2::operator!=(const Point2& Other) const
{
    return !(*this == Other);
}

math::Point2 math::Point2::operator+(const Vector2& Vec) const
{
    return Point2(X + Vec.X, Y + Vec.Y);
}

math::Point2& math::Point2::operator+=(const Vector2& Vec)
{
    X += Vec.X;
    Y += Vec.Y;
    return *this;
}

math::Point2 math::Point2::operator+(const Point2& Other) const
{
    return Point2(X + Other.X, Y + Other.Y);
}

math::Point2& math::Point2::operator+=(const Point2& Other)
{
    X += Other.X;
    Y += Other.Y;
    return *this;
}

math::Point2 math::Point2::operator-(const Vector2& Vec) const
{
    return Point2(X - Vec.X, Y - Vec.Y);
}

math::Vector2 math::Point2::operator-(const Point2& Other) const
{
    return Vector2(X - Other.X, Y - Other.Y);
}

math::Point2& math::Point2::operator-=(const Vector2& Vec)
{
    X -= Vec.X;
    Y -= Vec.Y;
    return *this;
}

math::Point2 math::Point2::operator*(float Scalar) const
{
    return Point2(X * Scalar, Y * Scalar);
}

math::Point2& math::Point2::operator*=(float Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    return *this;
}

math::Point2 math::Point2::operator/(float Scalar) const
{
    assert(Scalar != 0);
    float Rec = 1 / Scalar;
    return Point2(X * Rec, Y * Rec);
}

math::Point2& math::Point2::operator/=(float Scalar)
{
    assert(Scalar != 0);
    float Rec = 1 / Scalar;
    X *= Rec;
    Y *= Rec;
    return *this;
}

math::Point2 math::Point2::operator-() const
{
    return Point2(-X, -Y);
}

math::Point2 math::Point2::Abs() const
{
    return Point2(std::abs(X), std::abs(Y));
}

math::Point2 math::operator*(float Scalar, const Point2& P)
{
    return P * Scalar;
}

float math::Distance(const Point2& P1, const Point2& P2)
{
    return (P1 - P2).Length();
}

float math::DistanceSquared(const Point2& P1, const Point2& P2)
{
    return (P1 - P2).LengthSquared();
}

math::Point2 math::Lerp(float t, const Point2& P1, const Point2& P2)
{
    return (1 - t) * P1 + t * P2;
}

math::Point2 math::Floor(const Point2& P)
{
    return Point2(std::floor(P.X), std::floor(P.Y));
}

math::Point2 math::Ceil(const Point2& P)
{
    return Point2(std::ceil(P.X), std::ceil(P.Y));
}

math::Point2 math::Round(const Point2& P)
{
    return Point2(std::roundf(P.X), std::roundf(P.Y));
}

math::Point2 math::Min(const Point2& P1, const Point2& P2)
{
    return Point2(std::fmin(P1.X, P2.X), std::fmin(P1.Y, P2.Y));
}

math::Point2 math::Max(const Point2& P1, const Point2& P2)
{
    return Point2(std::fmax(P1.X, P2.X), std::fmax(P1.Y, P2.Y));
}

math::Point2 math::Permute(const Point2& P, int X, int Y)
{
    return Point2(P[X], P[Y]);
}
