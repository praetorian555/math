#include "math/bounds3.h"

#include <gtest/gtest.h>

using Point3f = Math::Point3<float>;
using Bounds3f = Math::Bounds3<float>;
using Vector3f = Math::Vector3<float>;
using Point3d = Math::Point3<double>;
using Bounds3d = Math::Bounds3<double>;
using Vector3d = Math::Vector3<double>;
using Point3i = Math::Point3<int32_t>;
using Bounds3i = Math::Bounds3<int32_t>;
using Vector3i = Math::Vector3<int32_t>;

TEST(Bounds3Tests, Creation)
{
    {
        const Point3f p1(2, 4, 10);
        const Point3f p2(4, -2, 11);

        const Bounds3f b1(p1);
        const Bounds3f b2(p1, p2);

        EXPECT_TRUE(b1.min == p1);
        EXPECT_TRUE(b1.max == p1);

        EXPECT_TRUE(b2.min == Point3f(2, -2, 10));
        EXPECT_TRUE(b2.max == Point3f(4, 4, 11));
    }
    {
        const Point3d p1(2, 4, 10);
        const Point3d p2(4, -2, 11);

        const Bounds3d b1(p1);
        const Bounds3d b2(p1, p2);

        EXPECT_TRUE(b1.min == p1);
        EXPECT_TRUE(b1.max == p1);

        EXPECT_TRUE(b2.min == Point3d(2, -2, 10));
        EXPECT_TRUE(b2.max == Point3d(4, 4, 11));
    }
    {
        const Point3i p1(2, 4, 10);
        const Point3i p2(4, -2, 11);

        const Bounds3i b1(p1);
        const Bounds3i b2(p1, p2);

        EXPECT_TRUE(b1.min == p1);
        EXPECT_TRUE(b1.max == p1);

        EXPECT_TRUE(b2.min == Point3i(2, -2, 10));
        EXPECT_TRUE(b2.max == Point3i(4, 4, 11));
    }
}

TEST(Bounds3Tests, AccessOperator)
{
    {
        const Point3f p1(2, 3, 10);
        const Point3f p2(4, 5, 11);
        Bounds3f b1(p1, p2);
        EXPECT_TRUE(b1[0] == p1);
        EXPECT_TRUE(b1[1] == p2);
        const Bounds3f b2(p1, p2);
        EXPECT_TRUE(b2[0] == p1);
        EXPECT_TRUE(b2[1] == p2);

        const Point3f p3(5, 6, 7);
        b1[0] = p3;
        EXPECT_TRUE(b1[0] == p3);
        b1[1] = p3;
        EXPECT_TRUE(b1[1] == p3);
    }
    {
        const Point3d p1(2, 3, 10);
        const Point3d p2(4, 5, 11);
        Bounds3d b1(p1, p2);
        EXPECT_TRUE(b1[0] == p1);
        EXPECT_TRUE(b1[1] == p2);
        const Bounds3d b2(p1, p2);
        EXPECT_TRUE(b2[0] == p1);
        EXPECT_TRUE(b2[1] == p2);

        const Point3d p3(5, 6, 7);
        b1[0] = p3;
        EXPECT_TRUE(b1[0] == p3);
        b1[1] = p3;
        EXPECT_TRUE(b1[1] == p3);
    }
    {
        const Point3i p1(2, 3, 10);
        const Point3i p2(4, 5, 11);
        Bounds3i b1(p1, p2);
        EXPECT_TRUE(b1[0] == p1);
        EXPECT_TRUE(b1[1] == p2);
        const Bounds3i b2(p1, p2);
        EXPECT_TRUE(b2[0] == p1);
        EXPECT_TRUE(b2[1] == p2);

        const Point3i p3(5, 6, 7);
        b1[0] = p3;
        EXPECT_TRUE(b1[0] == p3);
        b1[1] = p3;
        EXPECT_TRUE(b1[1] == p3);
    }
}

TEST(Bounds3Tests, Comparison)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Point3f p3(2, 2, 2);

        EXPECT_EQ(p1, p3);
        EXPECT_NE(p1, p2);
        EXPECT_NE(p2, p3);
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Point3d p3(2, 2, 2);

        EXPECT_EQ(p1, p3);
        EXPECT_NE(p1, p2);
        EXPECT_NE(p2, p3);
    }
    {
        const Point3i p1(2, 2, 2);
        const Point3i p2(4, 4, 4);
        const Point3i p3(2, 2, 2);

        EXPECT_EQ(p1, p3);
        EXPECT_NE(p1, p2);
        EXPECT_NE(p2, p3);
    }
}

TEST(Bounds3Tests, Corner)
{
    {
        const Point3f p1(2, 3, 10);
        const Point3f p2(4, 5, 11);
        const Bounds3f b1(p1, p2);

        EXPECT_TRUE(p1 == Corner(b1, 0b000));
        EXPECT_TRUE(p2 == Corner(b1, 0b111));
        EXPECT_TRUE(Point3f(2, 5, 10) == Corner(b1, 0b010));
    }
    {
        const Point3d p1(2, 3, 10);
        const Point3d p2(4, 5, 11);
        const Bounds3d b1(p1, p2);

        EXPECT_TRUE(p1 == Corner(b1, 0b000));
        EXPECT_TRUE(p2 == Corner(b1, 0b111));
        EXPECT_TRUE(Point3d(2, 5, 10) == Corner(b1, 0b010));
    }
    {
        const Point3i p1(2, 3, 10);
        const Point3i p2(4, 5, 11);
        const Bounds3i b1(p1, p2);

        EXPECT_TRUE(p1 == Corner(b1, 0b000));
        EXPECT_TRUE(p2 == Corner(b1, 0b111));
        EXPECT_TRUE(Point3i(2, 5, 10) == Corner(b1, 0b010));
    }
}

TEST(Bounds3Tests, Diagonal)
{
    {
        const Point3f p1(2, 3, 10);
        const Point3f p2(4, 5, 11);
        const Bounds3f b1(p1, p2);
        const Vector3f v = p2 - p1;
        EXPECT_TRUE(Diagonal(b1) == v);
    }
    {
        const Point3d p1(2, 3, 10);
        const Point3d p2(4, 5, 11);
        const Bounds3d b1(p1, p2);
        const Vector3d v = p2 - p1;
        EXPECT_TRUE(Diagonal(b1) == v);
    }
    {
        const Point3i p1(2, 3, 10);
        const Point3i p2(4, 5, 11);
        const Bounds3i b1(p1, p2);
        const Vector3i v = p2 - p1;
        EXPECT_TRUE(Diagonal(b1) == v);
    }
}

TEST(Bounds3Tests, SurfaceArea)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Bounds3f b1(p1, p2);
        EXPECT_FLOAT_EQ(SurfaceArea(b1), 24.0f);
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Bounds3d b1(p1, p2);
        EXPECT_DOUBLE_EQ(SurfaceArea(b1), 24.0);
    }
    {
        const Point3i p1(2, 2, 2);
        const Point3i p2(4, 4, 4);
        const Bounds3i b1(p1, p2);
        EXPECT_EQ(SurfaceArea(b1), 24);
    }
}

TEST(Bounds3Tests, Volume)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Bounds3f b1(p1, p2);
        EXPECT_FLOAT_EQ(Volume(b1), 8.0f);
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Bounds3d b1(p1, p2);
        EXPECT_DOUBLE_EQ(Volume(b1), 8.0);
    }
    {
        const Point3i p1(2, 2, 2);
        const Point3i p2(4, 4, 4);
        const Bounds3i b1(p1, p2);
        EXPECT_EQ(Volume(b1), 8);
    }
}

TEST(Bounds3Tests, MaximumExtent)
{
    {
        const Point3f p1(2, 3, 10);
        const Point3f p2(5, 5, 11);
        const Bounds3f b1(p1, p2);
        EXPECT_EQ(MaximumExtent(b1), 0);
    }
    {
        const Point3d p1(2, 3, 10);
        const Point3d p2(5, 5, 11);
        const Bounds3d b1(p1, p2);
        EXPECT_EQ(MaximumExtent(b1), 0);
    }
    {
        const Point3i p1(2, 3, 10);
        const Point3i p2(5, 5, 11);
        const Bounds3i b1(p1, p2);
        EXPECT_EQ(MaximumExtent(b1), 0);
    }
}

TEST(Bounds3Tests, Lerp)
{
    {
        const Point3f p1(2, 3, 10);
        const Point3f p2(5, 5, 11);
        const Bounds3f b1(p1, p2);
        const Point3f p = Lerp(b1, Point3f(0.5f, 0.5f, 0.5f));
        EXPECT_TRUE(Point3f(3.5f, 4.0f, 10.5f) == p);
    }
    {
        const Point3d p1(2, 3, 10);
        const Point3d p2(5, 5, 11);
        const Bounds3d b1(p1, p2);
        const Point3d p = Lerp(b1, Point3d(0.5f, 0.5f, 0.5f));
        EXPECT_TRUE(Point3d(3.5f, 4.0f, 10.5f) == p);
    }
}

TEST(Bounds3Tests, Offset)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Point3f p3(3, 3, 3);
        const Bounds3f b(p1, p2);
        EXPECT_TRUE(Offset(b, p3) == Vector3f(0.5f, 0.5f, 0.5f));
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Point3d p3(3, 3, 3);
        const Bounds3d b(p1, p2);
        EXPECT_TRUE(Offset(b, p3) == Vector3d(0.5, 0.5, 0.5));
    }
}

TEST(Bounds3Tests, BoundingSphere)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Bounds3f b(p1, p2);

        Point3f center;
        float radius = 0.0f;
        BoundingSphere(b, center, radius);

        EXPECT_EQ(center, Point3f(3, 3, 3));
        EXPECT_FLOAT_EQ(radius, Math::Sqrt(3.0f));
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Bounds3d b(p1, p2);

        Point3d center;
        double radius = 0.0;
        BoundingSphere(b, center, radius);

        EXPECT_EQ(center, Point3d(3, 3, 3));
        EXPECT_DOUBLE_EQ(radius, Math::Sqrt(3.0));
    }
}

TEST(Bounds3Tests, Extent)
{
    {
        const Point3f p1(2, 2, 3);
        const Point3f p2(5, 5, 4);
        const Bounds3f b(p1, p2);
        const Vector3f e = Extent(b);
        EXPECT_FLOAT_EQ(e.x, 3);
        EXPECT_FLOAT_EQ(e.y, 3);
        EXPECT_FLOAT_EQ(e.z, 1);
    }
    {
        const Point3d p1(2, 2, 3);
        const Point3d p2(5, 5, 4);
        const Bounds3d b(p1, p2);
        const Vector3d e = Extent(b);
        EXPECT_DOUBLE_EQ(e.x, 3);
        EXPECT_DOUBLE_EQ(e.y, 3);
        EXPECT_DOUBLE_EQ(e.z, 1);
    }
    {
        const Point3i p1(2, 2, 3);
        const Point3i p2(5, 5, 4);
        const Bounds3i b(p1, p2);
        const Vector3i e = Extent(b);
        EXPECT_EQ(e.x, 3);
        EXPECT_EQ(e.y, 3);
        EXPECT_EQ(e.z, 1);
    }
}

TEST(Bounds3Tests, Union)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Point3f p3(0, 0, 0);
        const Point3f p4(-2, -2, -2);
        const Bounds3f b1(p1, p2);
        const Bounds3f b2(p3, p4);
        const Bounds3f b3 = Union(b1, p3);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
        const Bounds3f b4 = Union(b1, b2);
        EXPECT_EQ(b4.min, p4);
        EXPECT_EQ(b4.max, p2);
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Point3d p3(0, 0, 0);
        const Point3d p4(-2, -2, -2);
        const Bounds3d b1(p1, p2);
        const Bounds3d b2(p3, p4);
        const Bounds3d b3 = Union(b1, p3);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
        const Bounds3d b4 = Union(b1, b2);
        EXPECT_EQ(b4.min, p4);
        EXPECT_EQ(b4.max, p2);
    }
    {
        const Point3i p1(2, 2, 2);
        const Point3i p2(4, 4, 4);
        const Point3i p3(0, 0, 0);
        const Point3i p4(-2, -2, -2);
        const Bounds3i b1(p1, p2);
        const Bounds3i b2(p3, p4);
        const Bounds3i b3 = Union(b1, p3);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
        const Bounds3i b4 = Union(b1, b2);
        EXPECT_EQ(b4.min, p4);
        EXPECT_EQ(b4.max, p2);
    }
}

TEST(Bounds3Tests, Expand)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Bounds3f b1(p1, p2);
        const Bounds3f b2 = Expand(b1, 2.0f);
        EXPECT_EQ(b2.min, Point3f(0, 0, 0));
        EXPECT_EQ(b2.max, Point3f(6, 6, 6));
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Bounds3d b1(p1, p2);
        const Bounds3d b2 = Expand(b1, 2.0);
        EXPECT_EQ(b2.min, Point3d(0, 0, 0));
        EXPECT_EQ(b2.max, Point3d(6, 6, 6));
    }
    {
        const Point3i p1(2, 2, 2);
        const Point3i p2(4, 4, 4);
        const Bounds3i b1(p1, p2);
        const Bounds3i b2 = Expand(b1, 2);
        EXPECT_EQ(b2.min, Point3i(0, 0, 0));
        EXPECT_EQ(b2.max, Point3i(6, 6, 6));
    }
}

TEST(Bounds3Tests, Overlaps)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Point3f p3(3, 3, 3);
        const Point3f p4(5, 5, 5);
        const Bounds3f b1(p1, p2);
        const Bounds3f b2(p3, p4);
        const Bounds3f b3(p2, p4);
        EXPECT_TRUE(Overlaps(b1, b2));
        EXPECT_TRUE(Overlaps(b1, b3));
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Point3d p3(3, 3, 3);
        const Point3d p4(5, 5, 5);
        const Bounds3d b1(p1, p2);
        const Bounds3d b2(p3, p4);
        const Bounds3d b3(p2, p4);
        EXPECT_TRUE(Overlaps(b1, b2));
        EXPECT_TRUE(Overlaps(b1, b3));
    }
    {
        const Point3i p1(2, 2, 2);
        const Point3i p2(4, 4, 4);
        const Point3i p3(3, 3, 3);
        const Point3i p4(5, 5, 5);
        const Bounds3i b1(p1, p2);
        const Bounds3i b2(p3, p4);
        const Bounds3i b3(p2, p4);
        EXPECT_TRUE(Overlaps(b1, b2));
        EXPECT_TRUE(Overlaps(b1, b3));
    }
}

TEST(Bounds3Tests, Intersect)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Point3f p3(3, 3, 3);
        const Point3f p4(5, 5, 5);
        const Bounds3f b1(p1, p2);
        const Bounds3f b2(p3, p4);
        const Bounds3f b3 = Intersect(b1, b2);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Point3d p3(3, 3, 3);
        const Point3d p4(5, 5, 5);
        const Bounds3d b1(p1, p2);
        const Bounds3d b2(p3, p4);
        const Bounds3d b3 = Intersect(b1, b2);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
    }
    {
        const Point3i p1(2, 2, 2);
        const Point3i p2(4, 4, 4);
        const Point3i p3(3, 3, 3);
        const Point3i p4(5, 5, 5);
        const Bounds3i b1(p1, p2);
        const Bounds3i b2(p3, p4);
        const Bounds3i b3 = Intersect(b1, b2);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
    }
}

TEST(Bounds3Tests, Inside)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Point3f p3(3, 3, 3);
        const Bounds3f b1(p1, p2);
        EXPECT_TRUE(Inside(b1, p3));
        EXPECT_TRUE(Inside(b1, p1));
        EXPECT_FALSE(Inside(b1, p2));
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Point3d p3(3, 3, 3);
        const Bounds3d b1(p1, p2);
        EXPECT_TRUE(Inside(b1, p3));
        EXPECT_TRUE(Inside(b1, p1));
        EXPECT_FALSE(Inside(b1, p2));
    }
    {
        const Point3i p1(2, 2, 2);
        const Point3i p2(4, 4, 4);
        const Point3i p3(3, 3, 3);
        const Bounds3i b1(p1, p2);
        EXPECT_TRUE(Inside(b1, p3));
        EXPECT_TRUE(Inside(b1, p1));
        EXPECT_FALSE(Inside(b1, p2));
    }
}

TEST(Bounds3Tests, InsideExclusive)
{
    {
        const Point3f p1(2, 2, 2);
        const Point3f p2(4, 4, 4);
        const Point3f p3(3, 3, 3);
        const Bounds3f b1(p1, p2);
        EXPECT_TRUE(InsideInclusive(b1, p3));
        EXPECT_TRUE(InsideInclusive(b1, p1));
        EXPECT_TRUE(InsideInclusive(b1, p2));
    }
    {
        const Point3d p1(2, 2, 2);
        const Point3d p2(4, 4, 4);
        const Point3d p3(3, 3, 3);
        const Bounds3d b1(p1, p2);
        EXPECT_TRUE(InsideInclusive(b1, p3));
        EXPECT_TRUE(InsideInclusive(b1, p1));
        EXPECT_TRUE(InsideInclusive(b1, p2));
    }
    {
        const Point3i p1(2, 2, 2);
        const Point3i p2(4, 4, 4);
        const Point3i p3(3, 3, 3);
        const Bounds3i b1(p1, p2);
        EXPECT_TRUE(InsideInclusive(b1, p3));
        EXPECT_TRUE(InsideInclusive(b1, p1));
        EXPECT_TRUE(InsideInclusive(b1, p2));
    }
}
