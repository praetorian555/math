#include "math/bounds2.h"

#include <cassert>

math::Bounds2::Bounds2()
    : Min(Point2(kSmallestFloat, kSmallestFloat)), Max(Point2(kLargestFloat, kLargestFloat))
{
}

math::Bounds2::Bounds2(const Point2& P) : Min(P), Max(P) {}

math::Bounds2::Bounds2(const Point2& Vec1, const Point2& Vec2)
    : Min(math::Min(Vec1.X, Vec2.X), math::Min(Vec1.Y, Vec2.Y)),
      Max(math::Max(Vec1.X, Vec2.X), math::Max(Vec1.Y, Vec2.Y))
{
}

const math::Point2& math::Bounds2::operator[](int Index) const
{
    assert(Index >= 0 && Index < 2);
    return Index == 0 ? Min : Max;
}

math::Point2& math::Bounds2::operator[](int Index)
{
    assert(Index >= 0 && Index < 2);
    return Index == 0 ? Min : Max;
}

math::Point2 math::Bounds2::Corner(int Corner) const
{
    return {(*this)[(Corner & 1)].X, (*this)[(Corner & 2) >> 1].Y};
}

math::Vector2 math::Bounds2::Diagonal() const
{
    return Max - Min;
}

math::real math::Bounds2::SurfaceArea() const
{
    const Vector2 Diag = Diagonal();
    return Diag.X * Diag.Y;
}

int math::Bounds2::MaximumExtent() const
{
    const Vector2 Diag = Diagonal();
    return Diag.X > Diag.Y ? 0 : 1;
}

math::Point2 math::Bounds2::Lerp(const Point2& Param) const
{
    return {math::Lerp(Param.X, Min.X, Max.X), math::Lerp(Param.Y, Min.Y, Max.Y)};
}

math::Vector2 math::Bounds2::Offset(const Point2& P) const
{
    Vector2 Off = P - Min;
    if (Max.X > Min.X)
    {
        Off.X /= Max.X - Min.X;
    }
    if (Max.Y > Min.Y)
    {
        Off.Y /= Max.Y - Min.Y;
    }
    return Off;
}

void math::Bounds2::BoundingSphere(Point2& Center, real& Radius) const
{
    Center = (Min + Max) / 2;
    Radius = Inside(Center, *this) ? Distance(Center, Max) : 0;
}

math::Vector2 math::Bounds2::Extent() const
{
    return {math::Abs(Max.X - Min.X), math::Abs(Max.Y - Min.Y)};
}

math::Bounds2 math::Union(const Bounds2& B, const Point2& P)
{
    return {Point2(Min(B.Min.X, P.X), Min(B.Min.Y, P.Y)),
            Point2(math::Max(B.Max.X, P.X), math::Max(B.Max.Y, P.Y))};
}

math::Bounds2 math::Union(const Bounds2& B1, const Bounds2& B2)
{
    return {Point2(Min(B1.Min.X, B2.Min.X), Min(B1.Min.Y, B2.Min.Y)),
            Point2(math::Max(B1.Max.X, B2.Max.X), math::Max(B1.Max.Y, B2.Max.Y))};
}

math::Bounds2 math::Intersect(const Bounds2& B1, const Bounds2& B2)
{
    return {Point2(math::Max(B1.Min.X, B2.Min.X), math::Max(B1.Min.Y, B2.Min.Y)),
            Point2(Min(B1.Max.X, B2.Max.X), Min(B1.Max.Y, B2.Max.Y))};
}

bool math::Overlaps(const Bounds2& B1, const Bounds2& B2)
{
    const bool X = (B1.Max.X >= B2.Min.X) && (B1.Min.X < B2.Max.X);
    const bool Y = (B1.Max.Y >= B2.Min.Y) && (B1.Min.Y < B2.Max.Y);
    return (X && Y);
}

bool math::Inside(const Point2& P, const Bounds2& B)
{
    return (P.X >= B.Min.X && P.X < B.Max.X && P.Y >= B.Min.Y && P.Y < B.Max.Y);
}

bool math::InsideInclusive(const Point2& P, const Bounds2& B)
{
    return (P.X >= B.Min.X && P.X <= B.Max.X && P.Y >= B.Min.Y && P.Y <= B.Max.Y);
}

math::Bounds2 math::Expand(const Bounds2& B, real Delta)
{
    return {B.Min - Vector2(Delta, Delta), B.Max + Vector2(Delta, Delta)};
}
