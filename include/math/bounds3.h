#pragma once

#include "math/base.h"
#include "math/impl/point3.h"

namespace math
{

template <typename T>
class Bounds3
{
public:
    Point3<T> Min, Max;

public:
    Bounds3()
    {
        T minNum = std::numeric_limits<T>::lowest();
        T maxNum = std::numeric_limits<T>::max();
        Min = Point3<T>(minNum, minNum, minNum);
        Max = Point3<T>(maxNum, maxNum, maxNum);
    }

    explicit Bounds3(const Point3<T>& p) : Min(p), Max(p) {}

    Bounds3(const Point3<T>& p1, const Point3<T>& p2)
        : Min(std::min(p1.X, p2.X), std::min(p1.Y, p2.Y), std::min(p1.Z, p2.Z)),
          Max(std::max(p1.X, p2.X), std::max(p1.Y, p2.Y), std::max(p1.Z, p2.Z))
    {
    }

    const Point3<T>& operator[](int i) const
    {
        assert(i >= 0 && i < 2);
        if (i == 0)
        {
            return Min;
        }
        else
        {
            return Max;
        }
    }

    Point3<T>& operator[](int i)
    {
        assert(i >= 0 && i < 2);
        if (i == 0)
        {
            return Min;
        }
        else
        {
            return Max;
        }
    }

    bool operator==(const Bounds3<T>& other) const { return Min == other.Min && Max == other.Max; }

    bool operator!=(const Bounds3<T>& other) const { return !(*this == other); }

    Point3<T> Corner(int corner) const
    {
        return Point3<T>((*this)[(corner & 1)].X, (*this)[(corner & 2) ? 1 : 0].Y,
                         (*this)[(corner & 4) ? 1 : 0].Z);
    }

    Vector3<T> Diagonal() const { return Max - Min; }

    T SurfaceArea() const
    {
        Vector3<T> d = Diagonal();
        return 2 * (d.X * d.Y + d.X * d.Z + d.Y * d.Z);
    }

    T Volume() const
    {
        Vector3<T> d = Diagonal();
        return d.X * d.Y * d.Z;
    }

    int MaXimumExtent() const
    {
        Vector3<T> d = Diagonal();
        if (d.X > d.Y && d.X > d.Z)
            return 0;
        else if (d.Y > d.Z)
            return 1;
        else
            return 2;
    }

    Point3<T> Lerp(const Point3<float>& t) const
    {
        return Point3<T>(Lerp(t.X, Min.X, Max.X), Lerp(t.Y, Min.Y, Max.Y), Lerp(t.Z, Min.Z, Max.Z));
    }

    Vector3<T> Offset(const Point3<T>& p) const
    {
        Vector3<T> o = p - Min;
        if (Max.X > Min.X)
            o.X /= Max.X - Min.X;
        if (Max.Y > Min.Y)
            o.Y /= Max.Y - Min.Y;
        if (Max.Z > Min.Z)
            o.Z /= Max.Z - Min.Z;
        return o;
    }

    void BoundingSphere(Point3<T>* center, float* radius) const
    {
        *center = (Min + Max) / 2;
        *radius = Inside(*center, *this) ? Distance(*center, Max) : 0;
    }

    Vector3<T> Extent() const
    {
        Vector3<T> Extent{std::abs(Max.X - Min.X), std::abs(Max.Y - Min.Y),
                          std::abs(Max.Z - Min.Z)};
        return Extent;
    }
};

template <typename T>
Bounds3<T> Union(const Bounds3<T>& b, const Point3<T>& p)
{
    return Bounds3<T>(
        Point3<T>(std::min(b.Min.X, p.X), std::min(b.Min.Y, p.Y), std::min(b.Min.Z, p.Z)),
        Point3<T>(std::max(b.Max.X, p.X), std::max(b.Max.Y, p.Y), std::max(b.Max.Z, p.Z)));
}

template <typename T>
Bounds3<T> Union(const Bounds3<T>& b1, const Bounds3<T>& b2)
{
    return Bounds3<T>(Point3<T>(std::min(b1.Min.X, b2.Min.X), std::min(b1.Min.Y, b2.Min.Y),
                                std::min(b1.Min.Z, b2.Min.Z)),
                      Point3<T>(std::max(b1.Max.X, b2.Max.X), std::max(b1.Max.Y, b2.Max.Y),
                                std::max(b1.Max.Z, b2.Max.Z)));
}

template <typename T>
Bounds3<T> Intersect(const Bounds3<T>& b1, const Bounds3<T>& b2)
{
    return Bounds3<T>(Point3<T>(std::max(b1.Min.X, b2.Min.X), std::max(b1.Min.Y, b2.Min.Y),
                                std::max(b1.Min.Z, b2.Min.Z)),
                      Point3<T>(std::min(b1.Max.X, b2.Max.X), std::min(b1.Max.Y, b2.Max.Y),
                                std::min(b1.Max.Z, b2.Max.Z)));
}

template <typename T>
bool Overlaps(const Bounds3<T>& b1, const Bounds3<T>& b2)
{
    bool X = (b1.Max.X >= b2.Min.X) && (b1.Min.X < b2.Max.X);
    bool Y = (b1.Max.Y >= b2.Min.Y) && (b1.Min.Y < b2.Max.Y);
    bool Z = (b1.Max.Z >= b2.Min.Z) && (b1.Min.Z < b2.Max.Z);
    return (X && Y && Z);
}

template <typename T>
bool Inside(const Point3<T>& p, const Bounds3<T>& b)
{
    return (p.X >= b.Min.X && p.X < b.Max.X && p.Y >= b.Min.Y && p.Y < b.Max.Y && p.Z >= b.Min.Z &&
            p.Z < b.Max.Z);
}

// The point is not counted if it is on the upper boundry of the box
template <typename T>
bool InsideInclusive(const Point3<T>& p, const Bounds3<T>& b)
{
    return (p.X >= b.Min.X && p.X <= b.Max.X && p.Y >= b.Min.Y && p.Y <= b.Max.Y &&
            p.Z >= b.Min.Z && p.Z <= b.Max.Z);
}

template <typename T, typename U>
inline Bounds3<T> Expand(const Bounds3<T>& b, U delta)
{
    return Bounds3<T>(b.Min - Vector3<T>(delta, delta, delta),
                      b.Max + Vector3<T>(delta, delta, delta));
}

}  // namespace math