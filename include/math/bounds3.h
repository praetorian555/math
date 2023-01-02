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

    const Point3& operator[](int Index) const;
    Point3& operator[](int Index);

    bool operator==(const Bounds3& Other) const;
    bool operator!=(const Bounds3& Other) const;

    Point3 Corner(int Corner) const;
    Vector3 Diagonal() const;

    float SurfaceArea() const;
    float Volume() const;

    int MaximumExtent() const;

    Point3 Lerp(const Point3& Param) const;

    Vector3 Offset(const Point3& P) const;

    void BoundingSphere(Point3& Center, float& Radius) const;

    Vector3 Extent() const;
};

Bounds3 Union(const Bounds3& B, const Point3& P);
Bounds3 Union(const Bounds3& B1, const Bounds3& B2);

Bounds3 Intersect(const Bounds3& B1, const Bounds3& B2);

bool Overlaps(const Bounds3& B1, const Bounds3& B2);

bool Inside(const Point3& P, const Bounds3& B);

// The point is not counted if it is on the upper boundry of the box
bool InsideInclusive(const Point3& P, const Bounds3& B);

Bounds3 Expand(const Bounds3& B, float Delta);

}  // namespace math