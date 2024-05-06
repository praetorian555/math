#include "math/bounds2.h"

#include <gtest/gtest.h>

using Point2f = Math::Point2<float>;
using Bounds2f = Math::Bounds2<float>;
using Vector2f = Math::Vector2<float>;
using Point2d = Math::Point2<double>;
using Bounds2d = Math::Bounds2<double>;
using Vector2d = Math::Vector2<double>;
using Point2i = Math::Point2<int32_t>;
using Bounds2i = Math::Bounds2<int32_t>;
using Vector2i = Math::Vector2<int32_t>;

TEST(Bounds2Tests, Creation)
{
    {
        const Point2f p1(2, 4);
        const Point2f p2(4, -2);

        const Bounds2f b1(p1);
        const Bounds2f b2(p1, p2);

        EXPECT_TRUE(b1.min == p1);
        EXPECT_TRUE(b1.max == p1);

        EXPECT_TRUE(b2.min == Point2f(2, -2));
        EXPECT_TRUE(b2.max == Point2f(4, 4));
    }
    {
        const Point2d p1(2, 4);
        const Point2d p2(4, -2);

        const Bounds2d b1(p1);
        const Bounds2d b2(p1, p2);

        EXPECT_TRUE(b1.min == p1);
        EXPECT_TRUE(b1.max == p1);

        EXPECT_TRUE(b2.min == Point2d(2, -2));
        EXPECT_TRUE(b2.max == Point2d(4, 4));
    }
    {
        const Point2i p1(2, 4);
        const Point2i p2(4, -2);

        const Bounds2i b1(p1);
        const Bounds2i b2(p1, p2);

        EXPECT_TRUE(b1.min == p1);
        EXPECT_TRUE(b1.max == p1);

        EXPECT_TRUE(b2.min == Point2i(2, -2));
        EXPECT_TRUE(b2.max == Point2i(4, 4));
    }
}

TEST(Bounds2Tests, AccessOperator)
{
    {
        const Point2f p1(2, 3);
        const Point2f p2(4, 5);
        Bounds2f b1(p1, p2);
        EXPECT_TRUE(b1[0] == p1);
        EXPECT_TRUE(b1[1] == p2);
        const Bounds2f b2(p1, p2);
        EXPECT_TRUE(b2[0] == p1);
        EXPECT_TRUE(b2[1] == p2);

        const Point2f p3(5, 6);
        b1[0] = p3;
        EXPECT_TRUE(b1[0] == p3);
        b1[1] = p3;
        EXPECT_TRUE(b1[1] == p3);
    }
    {
        const Point2d p1(2, 3);
        const Point2d p2(4, 5);
        Bounds2d b1(p1, p2);
        EXPECT_TRUE(b1[0] == p1);
        EXPECT_TRUE(b1[1] == p2);
        const Bounds2d b2(p1, p2);
        EXPECT_TRUE(b2[0] == p1);
        EXPECT_TRUE(b2[1] == p2);

        const Point2d p3(5, 6);
        b1[0] = p3;
        EXPECT_TRUE(b1[0] == p3);
        b1[1] = p3;
        EXPECT_TRUE(b1[1] == p3);
    }
    {
        const Point2i p1(2, 3);
        const Point2i p2(4, 5);
        Bounds2i b1(p1, p2);
        EXPECT_TRUE(b1[0] == p1);
        EXPECT_TRUE(b1[1] == p2);
        const Bounds2i b2(p1, p2);
        EXPECT_TRUE(b2[0] == p1);
        EXPECT_TRUE(b2[1] == p2);

        const Point2i p3(5, 6);
        b1[0] = p3;
        EXPECT_TRUE(b1[0] == p3);
        b1[1] = p3;
        EXPECT_TRUE(b1[1] == p3);
    }
}

TEST(Bounds2Tests, Comparison)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Point2f p3(2, 2);

        EXPECT_EQ(p1, p3);
        EXPECT_NE(p1, p2);
        EXPECT_NE(p2, p3);
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Point2d p3(2, 2);

        EXPECT_EQ(p1, p3);
        EXPECT_NE(p1, p2);
        EXPECT_NE(p2, p3);
    }
    {
        const Point2i p1(2, 2);
        const Point2i p2(4, 4);
        const Point2i p3(2, 2);

        EXPECT_EQ(p1, p3);
        EXPECT_NE(p1, p2);
        EXPECT_NE(p2, p3);
    }
}

TEST(Bounds2Tests, Corner)
{
    {
        const Point2f p1(2, 3);
        const Point2f p2(4, 5);
        const Bounds2f b1(p1, p2);

        EXPECT_TRUE(p1 == Corner(b1, 0b00));
        EXPECT_TRUE(p2 == Corner(b1, 0b11));
        EXPECT_TRUE(Point2f(2, 5) == Corner(b1, 0b10));
    }
    {
        const Point2d p1(2, 3);
        const Point2d p2(4, 5);
        const Bounds2d b1(p1, p2);

        EXPECT_TRUE(p1 == Corner(b1, 0b00));
        EXPECT_TRUE(p2 == Corner(b1, 0b11));
        EXPECT_TRUE(Point2d(2, 5) == Corner(b1, 0b10));
    }
    {
        const Point2i p1(2, 3);
        const Point2i p2(4, 5);
        const Bounds2i b1(p1, p2);

        EXPECT_TRUE(p1 == Corner(b1, 0b00));
        EXPECT_TRUE(p2 == Corner(b1, 0b11));
        EXPECT_TRUE(Point2i(2, 5) == Corner(b1, 0b10));
    }
}

TEST(Bounds2Tests, Diagonal)
{
    {
        const Point2f p1(2, 3);
        const Point2f p2(4, 5);
        const Bounds2f b1(p1, p2);
        const Vector2f v = p2 - p1;
        EXPECT_TRUE(Diagonal(b1) == v);
    }
    {
        const Point2d p1(2, 3);
        const Point2d p2(4, 5);
        const Bounds2d b1(p1, p2);
        const Vector2d v = p2 - p1;
        EXPECT_TRUE(Diagonal(b1) == v);
    }
    {
        const Point2i p1(2, 3);
        const Point2i p2(4, 5);
        const Bounds2i b1(p1, p2);
        const Vector2i v = p2 - p1;
        EXPECT_TRUE(Diagonal(b1) == v);
    }
}

TEST(Bounds2Tests, SurfaceArea)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Bounds2f b1(p1, p2);
        EXPECT_FLOAT_EQ(SurfaceArea(b1), 4.0f);
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Bounds2d b1(p1, p2);
        EXPECT_DOUBLE_EQ(SurfaceArea(b1), 4.0);
    }
    {
        const Point2i p1(2, 2);
        const Point2i p2(4, 4);
        const Bounds2i b1(p1, p2);
        EXPECT_EQ(SurfaceArea(b1), 4);
    }
}

TEST(Bounds2Tests, MaximumExtent)
{
    {
        const Point2f p1(2, 3);
        const Point2f p2(5, 5);
        const Bounds2f b1(p1, p2);
        EXPECT_EQ(MaximumExtent(b1), 0);
    }
    {
        const Point2d p1(2, 3);
        const Point2d p2(5, 5);
        const Bounds2d b1(p1, p2);
        EXPECT_EQ(MaximumExtent(b1), 0);
    }
    {
        const Point2i p1(2, 3);
        const Point2i p2(5, 5);
        const Bounds2i b1(p1, p2);
        EXPECT_EQ(MaximumExtent(b1), 0);
    }
}

TEST(Bounds2Tests, Lerp)
{
    {
        const Point2f p1(2, 3);
        const Point2f p2(5, 5);
        const Bounds2f b1(p1, p2);
        const Point2f p = Lerp(b1, Point2f(0.5f, 0.5f));
        EXPECT_TRUE(Point2f(3.5f, 4.0f) == p);
    }
    {
        const Point2d p1(2, 3);
        const Point2d p2(5, 5);
        const Bounds2d b1(p1, p2);
        const Point2d p = Lerp(b1, Point2d(0.5f, 0.5f));
        EXPECT_TRUE(Point2d(3.5f, 4.0f) == p);
    }
}

TEST(Bounds2Tests, Offset)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Point2f p3(3, 3);
        const Bounds2f b(p1, p2);
        EXPECT_TRUE(Offset(b, p3) == Vector2f(0.5f, 0.5f));
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Point2d p3(3, 3);
        const Bounds2d b(p1, p2);
        EXPECT_TRUE(Offset(b, p3) == Vector2d(0.5, 0.5));
    }
}

TEST(Bounds2Tests, BoundingSphere)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Bounds2f b(p1, p2);

        Point2f center;
        float radius = 0.0f;
        BoundingSphere(b, center, radius);

        EXPECT_EQ(center, Point2f(3, 3));
        EXPECT_FLOAT_EQ(radius, Math::Sqrt(2.0f));
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Bounds2d b(p1, p2);

        Point2d center;
        double radius = 0.0;
        BoundingSphere(b, center, radius);

        EXPECT_EQ(center, Point2d(3, 3));
        EXPECT_DOUBLE_EQ(radius, Math::Sqrt(2.0));
    }
}

TEST(Bounds2Tests, Extent)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(5, 5);
        const Bounds2f b(p1, p2);
        const Vector2f e = Extent(b);
        EXPECT_FLOAT_EQ(e.x, 3);
        EXPECT_FLOAT_EQ(e.y, 3);
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(5, 5);
        const Bounds2d b(p1, p2);
        const Vector2d e = Extent(b);
        EXPECT_DOUBLE_EQ(e.x, 3);
        EXPECT_DOUBLE_EQ(e.y, 3);
    }
    {
        const Point2i p1(2, 2);
        const Point2i p2(5, 5);
        const Bounds2i b(p1, p2);
        const Vector2i e = Extent(b);
        EXPECT_EQ(e.x, 3);
        EXPECT_EQ(e.y, 3);
    }
}

TEST(Bounds2Tests, Union)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Point2f p3(0, 0);
        const Point2f p4(-2, -2);
        const Bounds2f b1(p1, p2);
        const Bounds2f b2(p3, p4);
        const Bounds2f b3 = Union(b1, p3);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
        const Bounds2f b4 = Union(b1, b2);
        EXPECT_EQ(b4.min, p4);
        EXPECT_EQ(b4.max, p2);
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Point2d p3(0, 0);
        const Point2d p4(-2, -2);
        const Bounds2d b1(p1, p2);
        const Bounds2d b2(p3, p4);
        const Bounds2d b3 = Union(b1, p3);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
        const Bounds2d b4 = Union(b1, b2);
        EXPECT_EQ(b4.min, p4);
        EXPECT_EQ(b4.max, p2);
    }
    {
        const Point2i p1(2, 2);
        const Point2i p2(4, 4);
        const Point2i p3(0, 0);
        const Point2i p4(-2, -2);
        const Bounds2i b1(p1, p2);
        const Bounds2i b2(p3, p4);
        const Bounds2i b3 = Union(b1, p3);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
        const Bounds2i b4 = Union(b1, b2);
        EXPECT_EQ(b4.min, p4);
        EXPECT_EQ(b4.max, p2);
    }
}

TEST(Bounds2Tests, Expand)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Bounds2f b1(p1, p2);
        const Bounds2f b2 = Expand(b1, 2.0f);
        EXPECT_EQ(b2.min, Point2f(0, 0));
        EXPECT_EQ(b2.max, Point2f(6, 6));
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Bounds2d b1(p1, p2);
        const Bounds2d b2 = Expand(b1, 2.0);
        EXPECT_EQ(b2.min, Point2d(0, 0));
        EXPECT_EQ(b2.max, Point2d(6, 6));
    }
    {
        const Point2i p1(2, 2);
        const Point2i p2(4, 4);
        const Bounds2i b1(p1, p2);
        const Bounds2i b2 = Expand(b1, 2);
        EXPECT_EQ(b2.min, Point2i(0, 0));
        EXPECT_EQ(b2.max, Point2i(6, 6));
    }
}

TEST(Bounds2Tests, Overlaps)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Point2f p3(3, 3);
        const Point2f p4(5, 5);
        const Bounds2f b1(p1, p2);
        const Bounds2f b2(p3, p4);
        const Bounds2f b3(p2, p4);
        EXPECT_TRUE(Overlaps(b1, b2));
        EXPECT_TRUE(Overlaps(b1, b3));
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Point2d p3(3, 3);
        const Point2d p4(5, 5);
        const Bounds2d b1(p1, p2);
        const Bounds2d b2(p3, p4);
        const Bounds2d b3(p2, p4);
        EXPECT_TRUE(Overlaps(b1, b2));
        EXPECT_TRUE(Overlaps(b1, b3));
    }
    {
        const Point2i p1(2, 2);
        const Point2i p2(4, 4);
        const Point2i p3(3, 3);
        const Point2i p4(5, 5);
        const Bounds2i b1(p1, p2);
        const Bounds2i b2(p3, p4);
        const Bounds2i b3(p2, p4);
        EXPECT_TRUE(Overlaps(b1, b2));
        EXPECT_TRUE(Overlaps(b1, b3));
    }
}

TEST(Bounds2Tests, Intersect)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Point2f p3(3, 3);
        const Point2f p4(5, 5);
        const Bounds2f b1(p1, p2);
        const Bounds2f b2(p3, p4);
        const Bounds2f b3 = Intersect(b1, b2);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Point2d p3(3, 3);
        const Point2d p4(5, 5);
        const Bounds2d b1(p1, p2);
        const Bounds2d b2(p3, p4);
        const Bounds2d b3 = Intersect(b1, b2);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
    }
    {
        const Point2i p1(2, 2);
        const Point2i p2(4, 4);
        const Point2i p3(3, 3);
        const Point2i p4(5, 5);
        const Bounds2i b1(p1, p2);
        const Bounds2i b2(p3, p4);
        const Bounds2i b3 = Intersect(b1, b2);
        EXPECT_EQ(b3.min, p3);
        EXPECT_EQ(b3.max, p2);
    }
}

TEST(Bounds2Tests, Inside)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Point2f p3(3, 3);
        const Bounds2f b1(p1, p2);
        EXPECT_TRUE(Inside(b1, p3));
        EXPECT_TRUE(Inside(b1, p1));
        EXPECT_FALSE(Inside(b1, p2));
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Point2d p3(3, 3);
        const Bounds2d b1(p1, p2);
        EXPECT_TRUE(Inside(b1, p3));
        EXPECT_TRUE(Inside(b1, p1));
        EXPECT_FALSE(Inside(b1, p2));
    }
    {
        const Point2i p1(2, 2);
        const Point2i p2(4, 4);
        const Point2i p3(3, 3);
        const Bounds2i b1(p1, p2);
        EXPECT_TRUE(Inside(b1, p3));
        EXPECT_TRUE(Inside(b1, p1));
        EXPECT_FALSE(Inside(b1, p2));
    }
}

TEST(Bounds2Tests, InsideExclusive)
{
    {
        const Point2f p1(2, 2);
        const Point2f p2(4, 4);
        const Point2f p3(3, 3);
        const Bounds2f b1(p1, p2);
        EXPECT_TRUE(InsideInclusive(b1, p3));
        EXPECT_TRUE(InsideInclusive(b1, p1));
        EXPECT_TRUE(InsideInclusive(b1, p2));
    }
    {
        const Point2d p1(2, 2);
        const Point2d p2(4, 4);
        const Point2d p3(3, 3);
        const Bounds2d b1(p1, p2);
        EXPECT_TRUE(InsideInclusive(b1, p3));
        EXPECT_TRUE(InsideInclusive(b1, p1));
        EXPECT_TRUE(InsideInclusive(b1, p2));
    }
    {
        const Point2i p1(2, 2);
        const Point2i p2(4, 4);
        const Point2i p3(3, 3);
        const Bounds2i b1(p1, p2);
        EXPECT_TRUE(InsideInclusive(b1, p3));
        EXPECT_TRUE(InsideInclusive(b1, p1));
        EXPECT_TRUE(InsideInclusive(b1, p2));
    }
}
