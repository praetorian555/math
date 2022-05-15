#pragma once

#include "math/base.h"
#include "math/impl/point2.h"

namespace math
{

template <typename T>
class Bounds2
{
public:
    Point2<T> Min, Max;

public:
    Bounds2()
    {
        T minNum = std::numeric_limits<T>::lowest();
        T maxNum = std::numeric_limits<T>::max();
        Min = Point2<T>(minNum, minNum);
        Max = Point2<T>(maxNum, maxNum);
    }

    explicit Bounds2(const Point2<T>& p) : Min(p), Max(p) {}

    Bounds2(const Point2<T>& p1, const Point2<T>& p2)
        : Min(std::min(p1.X, p2.X), std::min(p1.Y, p2.Y)),
          Max(std::max(p1.X, p2.X), std::max(p1.Y, p2.Y))
    {
    }

    template <typename U>
    explicit Bounds2(const Bounds2<U>& other) : Min((Point2<T>)other.Min), Max((Point2<T>)other.Max)
    {
    }

    const Point2<T>& operator[](int i) const
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

    Point2<T>& operator[](int i)
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

    Point2<T> Corner(int corner) const
    {
        return Point2<T>((*this)[(corner & 1)].X, (*this)[(corner & 2) ? 1 : 0].Y);
    }

    Vector2<T> Diagonal() const { return Max - Min; }

    T SurfaceArea() const
    {
        Vector2<T> d = Diagonal();
        return d.X * d.Y;
    }

    int MaximumExtent() const
    {
        Vector2<T> d = Diagonal();
        return d.X > d.Y ? 0 : 1;
    }

    Point2<T> Lerp(const Point2<float>& t) const
    {
        return Point2<T>(math::Lerp(t.X, Min.X, Max.X), math::Lerp(t.Y, Min.Y, Max.Y));
    }

    Vector2<T> Offset(const Point2<T>& p) const
    {
        Vector2<T> o = p - Min;
        if (Max.X > Min.X)
            o.X /= Max.X - Min.X;
        if (Max.Y > Min.Y)
            o.Y /= Max.Y - Min.Y;
        return o;
    }

    void BoundingSphere(Point2<T>* center, float* radius) const
    {
        *center = (Min + Max) / 2;
        *radius = Inside(*center, *this) ? Distance(*center, Max) : 0;
    }

    Vector2<T> Extent() const
    {
        Vector2<T> Extent{std::abs(Max.X - Min.X), std::abs(Max.Y - Min.Y)};
        return Extent;
    }
};

template <typename T>
Bounds2<T> Union(const Bounds2<T>& b, const Point2<T>& p)
{
    return Bounds2<T>(Point2<T>(std::min(b.Min.X, p.X), std::min(b.Min.Y, p.Y)),
                      Point2<T>(std::max(b.Max.X, p.X), std::max(b.Max.Y, p.Y)));
}

template <typename T>
Bounds2<T> Union(const Bounds2<T>& b1, const Bounds2<T>& b2)
{
    return Bounds2<T>(Point2<T>(std::min(b1.Min.X, b2.Min.X), std::min(b1.Min.Y, b2.Min.Y)),
                      Point2<T>(std::max(b1.Max.X, b2.Max.X), std::max(b1.Max.Y, b2.Max.Y)));
}

template <typename T>
Bounds2<T> Intersect(const Bounds2<T>& b1, const Bounds2<T>& b2)
{
    return Bounds2<T>(Point2<T>(std::max(b1.Min.X, b2.Min.X), std::max(b1.Min.Y, b2.Min.Y)),
                      Point2<T>(std::min(b1.Max.X, b2.Max.X), std::min(b1.Max.Y, b2.Max.Y)));
}

template <typename T>
bool Overlaps(const Bounds2<T>& b1, const Bounds2<T>& b2)
{
    bool X = (b1.Max.X >= b2.Min.X) && (b1.Min.X < b2.Max.X);
    bool Y = (b1.Max.Y >= b2.Min.Y) && (b1.Min.Y < b2.Max.Y);
    return (X && Y);
}

template <typename T>
bool Inside(const Point2<T>& p, const Bounds2<T>& b)
{
    return (p.X >= b.Min.X && p.X < b.Max.X && p.Y >= b.Min.Y && p.Y < b.Max.Y);
}

// The point is not counted if it is on the upper boundrY of the boX
template <typename T>
bool InsideInclusive(const Point2<T>& p, const Bounds2<T>& b)
{
    return (p.X >= b.Min.X && p.X <= b.Max.X && p.Y >= b.Min.Y && p.Y <= b.Max.Y);
}

template <typename T, typename U>
inline Bounds2<T> Expand(const Bounds2<T>& b, U delta)
{
    return Bounds2<T>(b.Min - Vector2<T>(delta, delta), b.Max + Vector2<T>(delta, delta));
}

}  // namespace math