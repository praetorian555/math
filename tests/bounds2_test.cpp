#include "math/math.h"

#include "realexpect.h"

using Point2f = math::Point2;
using Vector2f = math::Vector2;
using Bounds2f = math::Bounds2;

TEST(Bounds2Tests, Creation)
{
    Point2f p1(2, 4);
    Point2f p2(4, -2);

    Bounds2f b1;
    Bounds2f b2(p1);
    Bounds2f b3(p1, p2);

    EXPECT_REAL_EQ(b1.Min.X, std::numeric_limits<math::real>::lowest());
    EXPECT_REAL_EQ(b1.Max.Y, std::numeric_limits<math::real>::max());

    EXPECT_TRUE(b2.Min == p1);
    EXPECT_TRUE(b2.Max == p1);

    EXPECT_TRUE(b3.Min == Point2f(2, -2));
    EXPECT_TRUE(b3.Max == Point2f(4, 4));

    Bounds2f b4(b3);
    EXPECT_TRUE(b4.Min == Point2f(2, -2));
    EXPECT_TRUE(b4.Max == Point2f(4, 4));
}

TEST(Bounds2Tests, AccessOperator)
{
    Point2f p1(2, 3);
    Point2f p2(4, 5);

    Bounds2f b1(p1, p2);

    EXPECT_TRUE(b1[0] == p1);
    EXPECT_TRUE(b1[1] == p2);
}

TEST(Bounds2Tests, Comparison)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);
    Point2f p3(2, 2);

    EXPECT_EQ(p1, p3);
    EXPECT_NE(p1, p2);
    EXPECT_NE(p2, p3);
}

TEST(Bounds2Tests, Corner)
{
    Point2f p1(2, 3);
    Point2f p2(4, 5);

    Bounds2f b1(p1, p2);

    EXPECT_TRUE(p1 == b1.Corner(0));
    EXPECT_TRUE(p2 == b1.Corner(3));
    EXPECT_TRUE(Point2f(2, 5) == b1.Corner(2));
}

TEST(Bounds2Tests, Diagonal)
{
    Point2f p1(2, 3);
    Point2f p2(4, 5);
    Vector2f v = p2 - p1;

    Bounds2f b1(p1, p2);

    EXPECT_TRUE(b1.Diagonal() == v);
}

TEST(Bounds2Tests, SurfaceArea)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);

    Bounds2f b1(p1, p2);

    EXPECT_REAL_EQ(b1.SurfaceArea(), MATH_REALC(4.0));
}

TEST(Bounds2Tests, MaximumExtent)
{
    Point2f p1(2, 3);
    Point2f p2(5, 5);

    Bounds2f b1(p1, p2);

    EXPECT_EQ(b1.MaximumExtent(), 0);
}

TEST(Bounds2Tests, Lerp)
{
    Point2f p1(2, 3);
    Point2f p2(5, 5);

    Bounds2f b1(p1, p2);
    Point2f p = b1.Lerp(Point2f(0.5f, 0.5f));
    EXPECT_TRUE(Point2f(3.5f, 4.0f) == p);
}

TEST(Bounds2Tests, Offset)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);
    Point2f p3(3, 3);

    Bounds2f b(p1, p2);

    EXPECT_TRUE(b.Offset(p3) == Vector2f(0.5f, 0.5f));
}

TEST(Bounds2Tests, BoundingSphere)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);

    Bounds2f b(p1, p2);

    Point2f center;
    math::real radius;

    b.BoundingSphere(center, radius);

    EXPECT_EQ(center, Point2f(3, 3));
    EXPECT_REAL_EQ(radius, math::Sqrt(2));
}

TEST(Bounds2Tests, Extent)
{
    Point2f p1(2, 2);
    Point2f p2(5, 5);

    Bounds2f b(p1, p2);
    Vector2f e = b.Extent();
    EXPECT_REAL_EQ(e.X, 3);
    EXPECT_REAL_EQ(e.Y, 3);
}

TEST(Bounds2Tests, Union)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);
    Point2f p3(0, 0);
    Point2f p4(-2, -2);

    Bounds2f b1(p1, p2);
    Bounds2f b2(p3, p4);

    Bounds2f b3 = Union(b1, p3);
    EXPECT_EQ(b3.Min, p3);
    EXPECT_EQ(b3.Max, p2);

    Bounds2f b4 = Union(b1, b2);
    EXPECT_EQ(b4.Min, p4);
    EXPECT_EQ(b4.Max, p2);
}

TEST(Bounds2Tests, Intersect)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);
    Point2f p3(3, 3);
    Point2f p4(5, 5);

    Bounds2f b1(p1, p2);
    Bounds2f b2(p3, p4);

    Bounds2f b3 = Intersect(b1, b2);
    EXPECT_EQ(b3.Min, p3);
    EXPECT_EQ(b3.Max, p2);
}

TEST(Bounds2Tests, Overlaps)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);
    Point2f p3(3, 3);
    Point2f p4(5, 5);

    Bounds2f b1(p1, p2);
    Bounds2f b2(p3, p4);

    EXPECT_TRUE(Overlaps(b1, b2));
}

TEST(Bounds2Tests, Inside)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);
    Point2f p3(3, 3);

    Bounds2f b1(p1, p2);

    EXPECT_TRUE(Inside(p3, b1));
    EXPECT_TRUE(Inside(p1, b1));
    EXPECT_FALSE(Inside(p2, b1));
}

TEST(Bounds2Tests, InsideInclusive)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);
    Point2f p3(3, 3);

    Bounds2f b1(p1, p2);

    EXPECT_TRUE(math::InsideInclusive(p3, b1));
    EXPECT_TRUE(math::InsideInclusive(p1, b1));
    EXPECT_TRUE(math::InsideInclusive(p2, b1));
}

TEST(Bounds2Tests, Expand)
{
    Point2f p1(2, 2);
    Point2f p2(4, 4);

    Bounds2f b1(p1, p2);

    Bounds2f b2 = Expand(b1, 2);

    EXPECT_EQ(b2.Min, Point2f(0, 0));
    EXPECT_EQ(b2.Max, Point2f(6, 6));
}
