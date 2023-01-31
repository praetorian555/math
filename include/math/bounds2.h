#pragma once

#include "math/point2.h"
#include "math/vector2.h"

namespace math
{

class Bounds2
{
public:
    Point2 Min, Max;

    Bounds2();
    explicit Bounds2(const Point2& P);
    Bounds2(const Point2& Vec1, const Point2& Vec2);

    const Point2& operator[](int Index) const;
    Point2& operator[](int Index);

    [[nodiscard]] Point2 Corner(int Corner) const;

    [[nodiscard]] Vector2 Diagonal() const;
    [[nodiscard]] real SurfaceArea() const;

    [[nodiscard]] int MaximumExtent() const;

    [[nodiscard]] Point2 Lerp(const Point2& Param) const;
    [[nodiscard]] Vector2 Offset(const Point2& P) const;

    void BoundingSphere(Point2& Center, real& Radius) const;

    [[nodiscard]] Vector2 Extent() const;
};

Bounds2 Union(const Bounds2& B, const Point2& P);
Bounds2 Union(const Bounds2& B1, const Bounds2& B2);

Bounds2 Intersect(const Bounds2& B1, const Bounds2& B2);
bool Overlaps(const Bounds2& B1, const Bounds2& B2);

bool Inside(const Point2& P, const Bounds2& B);
// The point is not counted if it is on the upper boundry of the box
bool InsideInclusive(const Point2& P, const Bounds2& B);

Bounds2 Expand(const Bounds2& B, real Delta);

}  // namespace math
