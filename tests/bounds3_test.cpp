#include "math/bounds3.h"

#include "realexpect.h"

using Point3f = math::Point3;
using Bounds3f = math::Bounds3;
using Vector3f = math::Vector3;

TEST(Bounds3Tests, Creation)
{
    Point3f p1(2, 4, 10);
    Point3f p2(4, -2, 11);

    Bounds3f b1;
    Bounds3f b2(p1);
    Bounds3f b3(p1, p2);

    EXPECT_REAL_EQ(b1.Min.X, std::numeric_limits<float>::lowest());
    EXPECT_REAL_EQ(b1.Max.Z, std::numeric_limits<float>::max());

    EXPECT_TRUE(b2.Min == p1);
    EXPECT_TRUE(b2.Max == p1);

    EXPECT_TRUE(b3.Min == Point3f(2, -2, 10));
    EXPECT_TRUE(b3.Max == Point3f(4, 4, 11));
}

TEST(Bounds3Tests, AccessOperator)
{
    Point3f p1(2, 3, 10);
    Point3f p2(4, 5, 11);

    Bounds3f b1(p1, p2);

    EXPECT_TRUE(b1[0] == p1);
    EXPECT_TRUE(b1[1] == p2);
}

TEST(Bounds3Tests, Comparison)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);
    Point3f p3(2, 2, 2);

    EXPECT_EQ(p1, p3);
    EXPECT_NE(p1, p2);
    EXPECT_NE(p2, p3);
}

TEST(Bounds3Tests, Corner)
{
    Point3f p1(2, 3, 10);
    Point3f p2(4, 5, 11);

    Bounds3f b1(p1, p2);

    EXPECT_TRUE(p1 == b1.Corner(0));
    EXPECT_TRUE(p2 == b1.Corner(7));
    EXPECT_TRUE(Point3f(2, 5, 10) == b1.Corner(2));
}

TEST(Bounds3Tests, Diagonal)
{
    Point3f p1(2, 3, 10);
    Point3f p2(4, 5, 11);
    Vector3f v = p2 - p1;

    Bounds3f b1(p1, p2);

    EXPECT_TRUE(b1.Diagonal() == v);
}

TEST(Bounds3Tests, SurfaceArea)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);

    Bounds3f b1(p1, p2);

    EXPECT_REAL_EQ(b1.SurfaceArea(), 24.0f);
}

TEST(Bounds3Tests, Volume)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);

    Bounds3f b1(p1, p2);

    EXPECT_REAL_EQ(b1.Volume(), 8.0f);
}

TEST(Bounds3Tests, MaximumExtent)
{
    Point3f p1(2, 3, 10);
    Point3f p2(5, 5, 11);

    Bounds3f b1(p1, p2);

    EXPECT_EQ(b1.MaximumExtent(), 0);
}

TEST(Bounds3Tests, Lerp)
{
    Point3f p1(2, 3, 10);
    Point3f p2(5, 5, 11);

    Bounds3f b1(p1, p2);
    Point3f p = b1.Lerp(Point3f(0.5f, 0.5f, 0.5f));
    EXPECT_TRUE(Point3f(3.5f, 4.0f, 10.5f) == p);
}

TEST(Bounds3Tests, Offset)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);
    Point3f p3(3, 3, 3);

    Bounds3f b(p1, p2);

    EXPECT_TRUE(b.Offset(p3) == Vector3f(0.5f, 0.5f, 0.5f));
}

TEST(Bounds3Tests, BoundingSphere)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);

    Bounds3f b(p1, p2);

    Point3f center;
    float radius;

    b.BoundingSphere(center, radius);

    EXPECT_EQ(center, Point3f(3, 3, 3));
    EXPECT_REAL_EQ(radius, std::sqrtf(3));
}

TEST(Bounds3Tests, Extent)
{
    Point3f p1(2, 2, 3);
    Point3f p2(5, 5, 4);

    Bounds3f b(p1, p2);
    Vector3f e = b.Extent();
    EXPECT_REAL_EQ(e.X, 3);
    EXPECT_REAL_EQ(e.Y, 3);
    EXPECT_REAL_EQ(e.Z, 1);
}

TEST(Bounds3Tests, Union)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);
    Point3f p3(0, 0, 0);
    Point3f p4(-2, -2, -2);

    Bounds3f b1(p1, p2);
    Bounds3f b2(p3, p4);

    Bounds3f b3 = Union(b1, p3);
    EXPECT_EQ(b3.Min, p3);
    EXPECT_EQ(b3.Max, p2);

    Bounds3f b4 = Union(b1, b2);
    EXPECT_EQ(b4.Min, p4);
    EXPECT_EQ(b4.Max, p2);
}

TEST(Bounds3Tests, Intersect)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);
    Point3f p3(3, 3, 3);
    Point3f p4(5, 5, 5);

    Bounds3f b1(p1, p2);
    Bounds3f b2(p3, p4);

    Bounds3f b3 = Intersect(b1, b2);
    EXPECT_EQ(b3.Min, p3);
    EXPECT_EQ(b3.Max, p2);
}

TEST(Bounds3Tests, Overlaps)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);
    Point3f p3(3, 3, 3);
    Point3f p4(5, 5, 5);

    Bounds3f b1(p1, p2);
    Bounds3f b2(p3, p4);

    EXPECT_TRUE(Overlaps(b1, b2));
}

TEST(Bounds3Tests, Inside)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);
    Point3f p3(3, 3, 3);

    Bounds3f b1(p1, p2);

    EXPECT_TRUE(Inside(p3, b1));
    EXPECT_TRUE(Inside(p1, b1));
    EXPECT_FALSE(Inside(p2, b1));
}

TEST(Bounds3Tests, InsideExclusive)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);
    Point3f p3(3, 3, 3);

    Bounds3f b1(p1, p2);

    EXPECT_TRUE(InsideInclusive(p3, b1));
    EXPECT_TRUE(InsideInclusive(p1, b1));
    EXPECT_TRUE(InsideInclusive(p2, b1));
}

TEST(Bounds3Tests, Expand)
{
    Point3f p1(2, 2, 2);
    Point3f p2(4, 4, 4);

    Bounds3f b1(p1, p2);

    Bounds3f b2 = Expand(b1, 2);

    EXPECT_EQ(b2.Min, Point3f(0, 0, 0));
    EXPECT_EQ(b2.Max, Point3f(6, 6, 6));
}
