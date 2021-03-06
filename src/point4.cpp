#include "math/point4.h"

#include <cassert>
#include <cmath>

#include "math/point3.h"
#include "math/vector4.h"

math::Point4::Point4(const Point3& P) : X(P.X), Y(P.Y), Z(P.Z), W(0) {}

void math::Point4::Set(float Value, int Index)
{
    assert(Index >= 0 && Index < 4);
    Data[Index] = Value;
}

float math::Point4::operator[](int Index) const
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
    return Point4(X + Vec.X, Y + Vec.Y, Z + Vec.Z, W + Vec.W);
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
    return Point4(X + Other.X, Y + Other.Y, Z + Other.Z, W + Other.W);
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
    return Point4(X - Vec.X, Y - Vec.Y, Z - Vec.Z, W - Vec.W);
}

math::Vector4 math::Point4::operator-(const Point4& Other) const
{
    return Vector4(X - Other.X, Y - Other.Y, Z - Other.Z, W - Other.W);
}

math::Point4& math::Point4::operator-=(const Vector4& Vec)
{
    X -= Vec.X;
    Y -= Vec.Y;
    Z -= Vec.Z;
    W -= Vec.W;
    return *this;
}

math::Point4 math::Point4::operator*(float Scalar) const
{
    return Point4(X * Scalar, Y * Scalar, Z * Scalar, W * Scalar);
}

math::Point4& math::Point4::operator*=(float Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    Z *= Scalar;
    W *= Scalar;
    return *this;
}

math::Point4 math::Point4::operator/(float Scalar) const
{
    assert(Scalar != 0);
    const float Rec = (float)1 / Scalar;
    return Point4(X * Rec, Y * Rec, Z * Rec, W * Rec);
}

math::Point4& math::Point4::operator/=(float Scalar)
{
    assert(Scalar != 0);
    const float Rec = (float)1 / Scalar;
    X *= Rec;
    Y *= Rec;
    Z *= Rec;
    W *= Rec;
    return *this;
}

math::Point4 math::Point4::operator-() const
{
    return Point4(-X, -Y, -Z, -W);
}

math::Point4 math::Point4::Abs() const
{
    return Point4(std::abs(X), std::abs(Y), std::abs(Z), std::abs(W));
}

math::Point4 math::Point4::ToEuclidean() const
{
    assert(W != 0);
    const float Div = 1 / W;
    return Point4(X * Div, Y * Div, Z * Div, 1);
}

math::Point4 math::operator*(float Scalar, const Point4& Vec)
{
    return Vec * Scalar;
}

float math::Distance(const Point4& P1, const Point4& P2)
{
    return (P1 - P2).Length();
}

float math::DistanceSquared(const Point4& P1, const Point4& P2)
{
    return (P1 - P2).LengthSquared();
}

math::Point4 math::Lerp(float t, const Point4& P1, const Point4& P2)
{
    return (1 - t) * P1 + t * P2;
}

math::Point4 math::Floor(const Point4& P)
{
    return Point4(std::floor(P.X), std::floor(P.Y), std::floor(P.Z), std::floor(P.W));
}

math::Point4 math::Ceil(const Point4& P)
{
    return Point4(std::ceil(P.X), std::ceil(P.Y), std::ceil(P.Z), std::ceil(P.W));
}

math::Point4 math::Round(const Point4& P)
{
    return Point4(std::roundf(P.X), std::roundf(P.Y), std::roundf(P.Z), std::roundf(P.W));
}

math::Point4 math::Min(const Point4& P1, const Point4& P2)
{
    return Point4(std::fmin(P1.X, P2.X), std::fmin(P1.Y, P2.Y), std::fmin(P1.Z, P2.Z),
                  std::fmin(P1.W, P2.W));
}

math::Point4 math::Max(const Point4& Vec1, const Point4& Vec2)
{
    return Point4(std::fmax(Vec1.X, Vec2.X), std::fmax(Vec1.Y, Vec2.Y), std::fmax(Vec1.Z, Vec2.Z),
                  std::fmax(Vec1.W, Vec2.W));
}

math::Point4 math::Permute(const Point4& Vec, int X, int Y, int Z, int W)
{
    return Point4(Vec[X], Vec[Y], Vec[Z], Vec[W]);
}
