#include "math/bounds3.h"

#include <cassert>
#include <cmath>

math::Bounds3::Bounds3()
    : Min(kSmallestFloat, kSmallestFloat, kSmallestFloat),
      Max(kLargestFloat, kLargestFloat, kLargestFloat)
{
}

math::Bounds3::Bounds3(const Point3& P) : Min(P), Max(P) {}

math::Bounds3::Bounds3(const Point3& P1, const Point3& P2)
    : Min(std::fmin(P1.X, P2.X), std::fmin(P1.Y, P2.Y), std::fmin(P1.Z, P2.Z)),
      Max(std::fmax(P1.X, P2.X), std::fmax(P1.Y, P2.Y), std::fmax(P1.Z, P2.Z))
{
}

const math::Point3& math::Bounds3::operator[](int Index) const
{
    assert(Index >= 0 && Index < 2);
    return Index == 0 ? Min : Max;
}

math::Point3& math::Bounds3::operator[](int Index)
{
    assert(Index >= 0 && Index < 2);
    return Index == 0 ? Min : Max;
}

bool math::Bounds3::operator==(const Bounds3& Other) const
{
    return Min == Other.Min && Max == Other.Max;
}

bool math::Bounds3::operator!=(const Bounds3& Other) const
{
    return !(*this == Other);
}

math::Point3 math::Bounds3::Corner(int Corner) const
{
    return {(*this)[(Corner & 1)].X, (*this)[(Corner & 2) >> 1].Y, (*this)[(Corner & 4) >> 2].Z};
}

math::Vector3 math::Bounds3::Diagonal() const
{
    return Max - Min;
}

float math::Bounds3::SurfaceArea() const
{
    const Vector3 Diag = Diagonal();
    return 2 * (Diag.X * Diag.Y + Diag.X * Diag.Z + Diag.Y * Diag.Z);
}

float math::Bounds3::Volume() const
{
    const Vector3 Diag = Diagonal();
    return Diag.X * Diag.Y * Diag.Z;
}

int math::Bounds3::MaximumExtent() const
{
    const Vector3 Diag = Diagonal();
    if (Diag.X > Diag.Y && Diag.X > Diag.Z)
    {
        return 0;
    }
    if (Diag.Y > Diag.Z)
    {
        return 1;
    }

    return 2;
}

math::Point3 math::Bounds3::Lerp(const Point3& t) const
{
    return {math::Lerp(t.X, Min.X, Max.X), math::Lerp(t.Y, Min.Y, Max.Y),
            math::Lerp(t.Z, Min.Z, Max.Z)};
}

math::Vector3 math::Bounds3::Offset(const Point3& P) const
{
    Vector3 Off = P - Min;
    if (Max.X > Min.X)
    {
        Off.X /= Max.X - Min.X;
    }
    if (Max.Y > Min.Y)
    {
        Off.Y /= Max.Y - Min.Y;
    }
    if (Max.Z > Min.Z)
    {
        Off.Z /= Max.Z - Min.Z;
    }
    return Off;
}

void math::Bounds3::BoundingSphere(Point3& Center, float& Radius) const
{
    Center = (Min + Max) / 2;
    Radius = Inside(Center, *this) ? Distance(Center, Max) : 0;
}

math::Vector3 math::Bounds3::Extent() const
{
    Vector3 Extent{std::abs(Max.X - Min.X), std::abs(Max.Y - Min.Y), std::abs(Max.Z - Min.Z)};
    return Extent;
}

math::Bounds3 math::Union(const Bounds3& B, const Point3& P)
{
    return {Point3(std::fmin(B.Min.X, P.X), std::fmin(B.Min.Y, P.Y), std::fmin(B.Min.Z, P.Z)),
            Point3(std::fmax(B.Max.X, P.X), std::fmax(B.Max.Y, P.Y), std::fmax(B.Max.Z, P.Z))};
}

math::Bounds3 math::Union(const Bounds3& B1, const Bounds3& B2)
{
    return {Point3(std::fmin(B1.Min.X, B2.Min.X), std::fmin(B1.Min.Y, B2.Min.Y),
                   std::fmin(B1.Min.Z, B2.Min.Z)),
            Point3(std::fmax(B1.Max.X, B2.Max.X), std::fmax(B1.Max.Y, B2.Max.Y),
                   std::fmax(B1.Max.Z, B2.Max.Z))};
}

math::Bounds3 math::Intersect(const Bounds3& B1, const Bounds3& B2)
{
    return {Point3(std::fmax(B1.Min.X, B2.Min.X), std::fmax(B1.Min.Y, B2.Min.Y),
                   std::fmax(B1.Min.Z, B2.Min.Z)),
            Point3(std::fmin(B1.Max.X, B2.Max.X), std::fmin(B1.Max.Y, B2.Max.Y),
                   std::fmin(B1.Max.Z, B2.Max.Z))};
}

bool math::Overlaps(const Bounds3& B1, const Bounds3& B2)
{
    const bool X = (B1.Max.X >= B2.Min.X) && (B1.Min.X < B2.Max.X);
    const bool Y = (B1.Max.Y >= B2.Min.Y) && (B1.Min.Y < B2.Max.Y);
    const bool Z = (B1.Max.Z >= B2.Min.Z) && (B1.Min.Z < B2.Max.Z);
    return (X && Y && Z);
}

bool math::Inside(const Point3& P, const Bounds3& B)
{
    return (P.X >= B.Min.X && P.X < B.Max.X && P.Y >= B.Min.Y && P.Y < B.Max.Y && P.Z >= B.Min.Z &&
            P.Z < B.Max.Z);
}

bool math::InsideInclusive(const Point3& P, const Bounds3& B)
{
    return (P.X >= B.Min.X && P.X <= B.Max.X && P.Y >= B.Min.Y && P.Y <= B.Max.Y &&
            P.Z >= B.Min.Z && P.Z <= B.Max.Z);
}

math::Bounds3 math::Expand(const Bounds3& B, float Delta)
{
    return {B.Min - Vector3(Delta, Delta, Delta), B.Max + Vector3(Delta, Delta, Delta)};
}
