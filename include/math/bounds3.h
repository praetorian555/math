#pragma once

#include "math/base.h"
#include "math/point3.h"
#include "math/vector3.h"

namespace math
{

class Bounds3
{
public:
    Point3 Min, Max;

public:
    Bounds3();
    explicit Bounds3(const Point3& P);
    Bounds3(const Point3& P1, const Point3& P2);

    const Point3& operator[](int i) const;
    Point3& operator[](int i);

    bool operator==(const Bounds3& Other) const;
    bool operator!=(const Bounds3& Other) const;

    Point3 Corner(int Corner) const;
    Vector3 Diagonal() const;

    float SurfaceArea() const;
    float Volume() const;

    int MaximumExtent() const;

    Point3 Lerp(const Point3& t) const;

    Vector3 Offset(const Point3& P) const;

    void BoundingSphere(Point3& center, float& radius) const;

    Vector3 Extent() const;
};

Bounds3 Union(const Bounds3& b, const Point3& p);
Bounds3 Union(const Bounds3& B1, const Bounds3& B2);

Bounds3 Intersect(const Bounds3& B1, const Bounds3& B2);

bool Overlaps(const Bounds3& B1, const Bounds3& B2);

bool Inside(const Point3& p, const Bounds3& b);

// The point is not counted if it is on the upper boundry of the box
bool InsideInclusive(const Point3& p, const Bounds3& b);

Bounds3 Expand(const Bounds3& b, float Delta);

}  // namespace math