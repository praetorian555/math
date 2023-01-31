#include "math/normal3.h"

#include <cassert>
#include <cmath>

#include "math/vector3.h"

math::Normal3::Normal3(const Vector3& Vec) : X(Vec.X), Y(Vec.Y), Z(Vec.Z) {}

void math::Normal3::Set(real Value, int Index)
{
    assert(Index >= 0 && Index < 3);
    Data[Index] = Value;
}

math::real math::Normal3::operator[](int Index) const
{
    assert(Index >= 0 && Index < 3);
    return Data[Index];
}

bool math::Normal3::HasNaNs() const
{
    return IsNaN(X) || IsNaN(Y) || IsNaN(Z);
}

bool math::Normal3::operator==(const Normal3& Other) const
{
    return X == Other.X && Y == Other.Y && Z == Other.Z;
}

bool math::Normal3::operator!=(const Normal3& Other) const
{
    return !(*this == Other);
}

math::Normal3 math::Normal3::operator+(const Normal3& Other) const
{
    return {X + Other.X, Y + Other.Y, Z + Other.Z};
}

math::Normal3& math::Normal3::operator+=(const Normal3& Other)
{
    X += Other.X;
    Y += Other.Y;
    Z += Other.Z;
    return *this;
}

math::Normal3 math::Normal3::operator-(const Normal3& Other) const
{
    return {X - Other.X, Y - Other.Y, Z - Other.Z};
}

math::Normal3& math::Normal3::operator-=(const Normal3& Other)
{
    X -= Other.X;
    Y -= Other.Y;
    Z -= Other.Z;
    return *this;
}

math::Normal3 math::Normal3::operator*(real Scalar) const
{
    return {X * Scalar, Y * Scalar, Z * Scalar};
}

math::Normal3& math::Normal3::operator*=(real Scalar)
{
    X *= Scalar;
    Y *= Scalar;
    Z *= Scalar;
    return *this;
}

math::Normal3 math::Normal3::operator/(real Scalar) const
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
    return {X * Rec, Y * Rec, Z * Rec};
}

math::Normal3& math::Normal3::operator/=(real Scalar)
{
    assert(Scalar != 0);
    const real Rec = 1.0f / Scalar;
    X *= Rec;
    Y *= Rec;
    Z *= Rec;
    return *this;
}

math::Normal3 math::Normal3::operator-() const
{
    return {-X, -Y, -Z};
}

math::Normal3 math::Normal3::Abs() const
{
    return {math::Abs(X), math::Abs(Y), math::Abs(Z)};
}

math::real math::Normal3::LengthSquared() const
{
    return X * X + Y * Y + Z * Z;
}
math::real math::Normal3::Length() const
{
    return std::sqrt(LengthSquared());
}

math::Normal3 math::operator*(real Scalar, const Normal3& N)
{
    return N * Scalar;
}

math::real math::Dot(const Normal3& N1, const Normal3& N2)
{
    return N1.X * N2.X + N1.Y * N2.Y + N1.Z * N2.Z;
}

math::real math::Dot(const Normal3& N, const Vector3& Vec)
{
    return N.X * Vec.X + N.Y * Vec.Y + N.Z * Vec.Z;
}

math::real math::Dot(const Vector3& Vec, const Normal3& N)
{
    return Vec.X * N.X + Vec.Y * N.Y + Vec.Z * N.Z;
}

math::real math::AbsDot(const Normal3& N1, const Normal3& N2)
{
    return math::Abs(Dot(N1, N2));
}

math::real math::AbsDot(const Normal3& N, const Vector3& Vec)
{
    return math::Abs(Dot(N, Vec));
}

math::real math::AbsDot(const Vector3& Vec, const Normal3& N)
{
    return math::Abs(Dot(Vec, N));
}

math::Normal3 math::Normalize(const Normal3& N)
{
    return N / N.Length();
}

math::real math::MinComponent(const Normal3& N)
{
    return Min(N.X, Min(N.Y, N.Z));
}

math::real math::MaxComponent(const Normal3& N)
{
    return math::Max(N.X, math::Max(N.Y, N.Z));
}

int math::MaxDimension(const Normal3& N)
{
    return (N.X > N.Y) ? (N.X > N.Z ? 0 : 2) : (N.Y > N.Z ? 1 : 2);
}

math::Normal3 math::Min(const Normal3& N1, const Normal3& N2)
{
    return {Min(N1.X, N2.X), Min(N1.Y, N2.Y), Min(N1.Z, N2.Z)};
}

math::Normal3 math::Max(const Normal3& N1, const Normal3& N2)
{
    return {math::Max(N1.X, N2.X), math::Max(N1.Y, N2.Y), math::Max(N1.Z, N2.Z)};
}

math::Normal3 math::Permute(const Normal3& N, int X, int Y, int Z)
{
    return {N[X], N[Y], N[Z]};
}

math::Normal3 math::FaceForward(const Normal3& N, const Vector3& Vec)
{
    return (Dot(N, Vec) < 0.f) ? -N : N;
}
