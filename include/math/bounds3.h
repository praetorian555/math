#pragma once

#include "math/base.h"
#include "math/point3.h"
#include "math/vector3.h"

namespace Math
{

/**
 * Axis aligned bounding box in 3D.
 */
template <typename T>
struct Bounds3
{
    Point3<T> min;
    Point3<T> max;

    /**
     * Default constructor. No initialization is done.
     */
    constexpr Bounds3();

    /**
     * Construct consisting of a single point.
     * @param p The point to initialize the bounds with.
     */
    constexpr explicit Bounds3(const Point3<T>& p);

    /**
     * Constructs a bounding box by specifying any two points. The points do not need to be in any
     * particular order.
     * @param p1 First point.
     * @param p2 Second point.
     */
    Bounds3(const Point3<T>& p1, const Point3<T>& p2);

    /**
     * Access min or max by index.
     * @param index 0 for min, 1 for max.
     * @return The min or max point.
     */
    Point3<T>& operator[](int32_t index);
    const Point3<T>& operator[](int32_t index) const;

    /** Operators. */
    bool operator==(const Bounds3& other) const;
    bool operator!=(const Bounds3& other) const;
};

/**
 * Returns the corner of the bounding box specified by the mask.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @param mask Bit mask specifying the corner. The least significant bit is the x coordinate, the
 * second least significant bit is the y coordinate, and the third least significant bit is the z. A
 * value of 0 means the minimum corner, a value of 1 means the maximum corner.
 * @return The corner of the bounding box specified by the mask.
 */
template <typename T>
[[nodiscard]] Point3<T> Corner(const Bounds3<T>& b, uint8_t mask);

/**
 * Returns the diagonal of the bounding box.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @return The diagonal of the bounding box pointing from min to max point.
 */
template <typename T>
[[nodiscard]] Vector3<T> Diagonal(const Bounds3<T>& b);

/**
 * Calculates the surface area of the bounding box.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @return The surface area of the bounding box.
 */
template <typename T>
[[nodiscard]] T SurfaceArea(const Bounds3<T>& b);

/**
 * Calculates the volume of the bounding box.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @return The volume of the bounding box.
 */
template <typename T>
[[nodiscard]] T Volume(const Bounds3<T>& b);

/**
 * Returns the index of the axis with the maximum extent.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @return The index of the axis with the maximum extent.
 */
template <typename T>
[[nodiscard]] int32_t MaximumExtent(const Bounds3<T>& b);

/**
 * Calculate linear interpolation between the min and max point of the bounding box.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @param t The interpolation factor. 0 returns the min point, 1 returns the max point.
 * @return The interpolated point.
 */
template <std::floating_point T>
[[nodiscard]] Point3<T> Lerp(const Bounds3<T>& b, const Point3<T>& t);

/**
 * Calculate the offset of a point from the minimum corner of the bounding box scaled by
 * the inverse of the bounding box extent.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @param p The point.
 * @return The offset of the point from the minimum corner of the bounding box scaled by the inverse
 * of the bounding box extent.
 */
template <std::floating_point T>
[[nodiscard]] Vector3<T> Offset(const Bounds3<T>& b, const Point3<T>& p);

/**
 * Calculates a sphere that bounds the bounding box.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @param out_center The center of the sphere.
 * @param out_radius The radius of the sphere.
 */
template <std::floating_point T>
void BoundingSphere(const Bounds3<T>& b, Point3<T>& out_center, T& out_radius);

/**
 * Calculates the extent of the bounding box.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @return The extent of the bounding box.
 */
template <typename T>
[[nodiscard]] Vector3<T> Extent(const Bounds3<T>& b);

/**
 * Calculates the union of a bounding box and a point.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @param p The point.
 * @return The union of the bounding box and the point.
 */
template <typename T>
[[nodiscard]] Bounds3<T> Union(const Bounds3<T>& b, const Point3<T>& p);

/**
 * Calculates the union of two bounding boxes.
 * @tparam T Data type of the bounding boxes.
 * @param b1 First bounding box.
 * @param b2 Second bounding box.
 * @return The union of the two bounding boxes.
 */
template <typename T>
[[nodiscard]] Bounds3<T> Union(const Bounds3<T>& b1, const Bounds3<T>& b2);

/**
 * Expands the bounding box by a constant amount in all directions.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @param delta The amount to expand the bounding box by.
 * @return The expanded bounding box.
 */
template <typename T>
[[nodiscard]] Bounds3<T> Expand(const Bounds3<T>& b, T delta);

/**
 * Checks if two bounding boxes overlap.
 * @tparam T Data type of the bounding boxes.
 * @param b1 First bounding box.
 * @param b2 Second bounding box.
 * @return True if the bounding boxes overlap, false otherwise.
 */
template <typename T>
bool Overlaps(const Bounds3<T>& b1, const Bounds3<T>& b2);

/**
 * Calculates the intersection of two bounding boxes.
 * @tparam T Data type of the bounding boxes.
 * @param b1 First bounding box.
 * @param b2 Second bounding box.
 * @return The intersection of the two bounding boxes. If the bounding boxes do not overlap, the
 * result is undefined. Use Overlaps() to check if the bounding boxes overlap.
 */
template <typename T>
[[nodiscard]] Bounds3<T> Intersect(const Bounds3<T>& b1, const Bounds3<T>& b2);

/**
 * Checks if a point is inside a bounding box. Note that the point is not counted if it is on the
 * upper boundary of the box.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @param p The point.
 * @return True if the point is inside the bounding box, false otherwise.
 */
template <typename T>
bool Inside(const Bounds3<T>& b, const Point3<T>& p);

/**
 * Checks if a point is inside a bounding box. Note that the point is counted if it is on the
 * upper boundary of the box as well.
 * @tparam T Data type of the bounding box.
 * @param b The bounding box.
 * @param p The point.
 * @return True if the point is inside the bounding box, false otherwise.
 */
template <typename T>
bool InsideInclusive(const Bounds3<T>& b, const Point3<T>& p);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr Math::Bounds3<T>::Bounds3()
{
    // Do nothing.
}

template <typename T>
constexpr Math::Bounds3<T>::Bounds3(const Point3<T>& p) : min(p), max(p)
{
}

template <typename T>
Math::Bounds3<T>::Bounds3(const Point3<T>& p1, const Point3<T>& p2)
{
    min = Point3<T>(Math::Min(p1.x, p2.x), Math::Min(p1.y, p2.y), Math::Min(p1.z, p2.z));
    max = Point3<T>(Math::Max(p1.x, p2.x), Math::Max(p1.y, p2.y), Math::Max(p1.z, p2.z));
}

template <typename T>
Math::Point3<T>& Math::Bounds3<T>::operator[](int32_t index)
{
    return (&min)[index];
}

template <typename T>
const Math::Point3<T>& Math::Bounds3<T>::operator[](int32_t index) const
{
    return (&min)[index];
}

template <typename T>
bool Math::Bounds3<T>::operator==(const Bounds3& other) const
{
    return min == other.min && max == other.max;
}

template <typename T>
bool Math::Bounds3<T>::operator!=(const Bounds3& other) const
{
    return min != other.min || max != other.max;
}

template <typename T>
Math::Point3<T> Math::Corner(const Bounds3<T>& b, uint8_t mask)
{
    return Point3<T>((mask & 1) ? b.max.x : b.min.x, (mask & 2) ? b.max.y : b.min.y,
                      (mask & 4) ? b.max.z : b.min.z);
}

template <typename T>
Math::Vector3<T> Math::Diagonal(const Bounds3<T>& b)
{
    return b.max - b.min;
}

template <typename T>
T Math::SurfaceArea(const Bounds3<T>& b)
{
    const Vector3<T> diag = Diagonal(b);
    return 2 * (diag.x * diag.y + diag.x * diag.z + diag.y * diag.z);
}

template <typename T>
T Math::Volume(const Bounds3<T>& b)
{
    const Vector3<T> diag = Diagonal(b);
    return diag.x * diag.y * diag.z;
}

template <typename T>
int32_t Math::MaximumExtent(const Bounds3<T>& b)
{
    const Vector3<T> diag = Diagonal(b);
    if (diag.x > diag.y && diag.x > diag.z)
    {
        return 0;
    }
    if (diag.y > diag.z)
    {
        return 1;
    }
    return 2;
}

template <std::floating_point T>
Math::Point3<T> Math::Lerp(const Bounds3<T>& b, const Point3<T>& t)
{
    return Point3<T>(Math::Lerp(t.x, b.min.x, b.max.x), Math::Lerp(t.y, b.min.y, b.max.y),
                      Math::Lerp(t.z, b.min.z, b.max.z));
}

template <std::floating_point T>
Math::Vector3<T> Math::Offset(const Bounds3<T>& b, const Point3<T>& p)
{
    Vector3<T> o = p - b.min;
    if (b.max.x > b.min.x)
    {
        o.x /= b.max.x - b.min.x;
    }
    if (b.max.y > b.min.y)
    {
        o.y /= b.max.y - b.min.y;
    }
    if (b.max.z > b.min.z)
    {
        o.z /= b.max.z - b.min.z;
    }
    return o;
}

template <std::floating_point T>
void Math::BoundingSphere(const Bounds3<T>& b, Point3<T>& out_center, T& out_radius)
{
    out_center = b.min + (b.max - b.min) / static_cast<T>(2);
    out_radius = Inside(b, out_center) ? static_cast<T>(Distance(out_center, b.max)) : 0;
}

template <typename T>
Math::Vector3<T> Math::Extent(const Bounds3<T>& b)
{
    return Math::Abs(b.max - b.min);
}

template <typename T>
Math::Bounds3<T> Math::Union(const Bounds3<T>& b, const Point3<T>& p)
{
    return Bounds3<T>(
        Point3<T>(Math::Min(b.min.x, p.x), Math::Min(b.min.y, p.y),
                                 Math::Min(b.min.z, p.z)),
        Point3<T>(Math::Max(b.max.x, p.x), Math::Max(b.max.y, p.y),
                                 Math::Max(b.max.z, p.z)));
}

template <typename T>
Math::Bounds3<T> Math::Union(const Bounds3<T>& b1, const Bounds3<T>& b2)
{
    return Bounds3<T>(Point3<T>(Math::Min(b1.min.x, b2.min.x), Math::Min(b1.min.y, b2.min.y),
                                 Math::Min(b1.min.z, b2.min.z)),
                      Point3<T>(Math::Max(b1.max.x, b2.max.x), Math::Max(b1.max.y, b2.max.y),
                                 Math::Max(b1.max.z, b2.max.z)));
}

template <typename T>
Math::Bounds3<T> Math::Expand(const Bounds3<T>& b, T delta)
{
    return Bounds3<T>(b.min - Vector3<T>(delta, delta, delta),
                      b.max + Vector3<T>(delta, delta, delta));
}

template <typename T>
bool Math::Overlaps(const Bounds3<T>& b1, const Bounds3<T>& b2)
{
    bool x = (b1.max.x >= b2.min.x) && (b1.min.x <= b2.max.x);
    bool y = (b1.max.y >= b2.min.y) && (b1.min.y <= b2.max.y);
    bool z = (b1.max.z >= b2.min.z) && (b1.min.z <= b2.max.z);
    return x && y && z;
}

template <typename T>
Math::Bounds3<T> Math::Intersect(const Bounds3<T>& b1, const Bounds3<T>& b2)
{
    return Bounds3<T>(Point3<T>(Math::Max(b1.min.x, b2.min.x), Math::Max(b1.min.y, b2.min.y),
                                 Math::Max(b1.min.z, b2.min.z)),
                      Point3<T>(Math::Min(b1.max.x, b2.max.x), Math::Min(b1.max.y, b2.max.y),
                                 Math::Min(b1.max.z, b2.max.z)));
}

template <typename T>
bool Math::Inside(const Bounds3<T>& b, const Point3<T>& p)
{
    return (p.x >= b.min.x && p.x < b.max.x && p.y >= b.min.y && p.y < b.max.y &&
            p.z >= b.min.z && p.z < b.max.z);
}

template <typename T>
bool Math::InsideInclusive(const Bounds3<T>& b, const Point3<T>& p)
{
    return (p.x >= b.min.x && p.x <= b.max.x && p.y >= b.min.y && p.y <= b.max.y &&
            p.z >= b.min.z && p.z <= b.max.z);
}
