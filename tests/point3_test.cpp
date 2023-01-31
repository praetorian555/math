#include "math/math.h"

#include "realexpect.h"

using Point3f = math::Point3;
using Vector3f = math::Vector3;

TEST(Point3Tests, GettersSettersConstruction)
{
    {
        Point3f p;
        EXPECT_EQ(p.X, 0);
        EXPECT_EQ(p.Y, 0);
        EXPECT_EQ(p.Z, 0);
    }

    {
        Point3f p(10, 15, 20);
        EXPECT_REAL_EQ(p.Data[0], 10);
        EXPECT_REAL_EQ(p.Data[1], 15);
        EXPECT_REAL_EQ(p.Data[2], 20);
    }

    {
        Point3f p;
        p.X = 5;
        EXPECT_REAL_EQ(p.X, 5);
        p.Y = 10;
        EXPECT_REAL_EQ(p.Y, 10);
        p.Z = 50;
        EXPECT_REAL_EQ(p.Z, 50);
        p.Set(15, 0);
        EXPECT_REAL_EQ(p[0], 15);
        p.Set(20, 1);
        EXPECT_REAL_EQ(p[1], 20);
        p.Set(55, 2);
        EXPECT_REAL_EQ(p[2], 55);
    }
}

TEST(Point3Tests, Nans)
{
    Point3f p1(nanf(""), 10.0f, 15.0f);
    EXPECT_TRUE(p1.HasNaNs());

    Point3f p2(15.0f, nanf(""), 10.0f);
    EXPECT_TRUE(p2.HasNaNs());

    Point3f p3(15.0f, 10.0f, nanf(""));
    EXPECT_TRUE(p3.HasNaNs());
}

TEST(Point3Tests, Comparison)
{
    Point3f p1(1, 2, 3);
    Point3f p2(3, 4, 5);
    Point3f p3(1, 2, 3);

    EXPECT_TRUE(p1 == p3);
    EXPECT_TRUE(p1 != p2);
}

TEST(Point3Tests, Addition)
{
    Point3f p1(1, 2, 3);
    Point3f p2(3, 4, 5);

    Point3f p3 = p1 + p2;
    EXPECT_REAL_EQ(p3.X, 4.0f);
    EXPECT_REAL_EQ(p3.Y, 6.0f);
    EXPECT_REAL_EQ(p3.Z, 8.0f);

    p3 += p1;
    EXPECT_REAL_EQ(p3.X, 5.0f);
    EXPECT_REAL_EQ(p3.Y, 8.0f);
    EXPECT_REAL_EQ(p3.Z, 11.0f);

    Vector3f v(3, 4, 5);
    Point3f p4 = p1 + v;
    EXPECT_REAL_EQ(p4.X, 4.0f);
    EXPECT_REAL_EQ(p4.Y, 6.0f);
    EXPECT_REAL_EQ(p4.Z, 8.0f);

    p4 += v;
    EXPECT_REAL_EQ(p4.X, 7.0f);
    EXPECT_REAL_EQ(p4.Y, 10.0f);
    EXPECT_REAL_EQ(p4.Z, 13.0f);
}

TEST(Point3Tests, Subtraction)
{
    Point3f p1(10, 11, 12);
    Point3f p2(3, 4, 5);
    Vector3f v1(1, 2, 3);

    Point3f p3 = p1 - v1;
    EXPECT_REAL_EQ(p3.X, 9.0f);
    EXPECT_REAL_EQ(p3.Y, 9.0f);
    EXPECT_REAL_EQ(p3.Z, 9.0f);

    Vector3f v2 = p1 - p2;
    EXPECT_REAL_EQ(v2.X, 7.0f);
    EXPECT_REAL_EQ(v2.Y, 7.0f);
    EXPECT_REAL_EQ(v2.Z, 7.0f);

    p1 -= v2;
    EXPECT_REAL_EQ(p1.X, 3.0f);
    EXPECT_REAL_EQ(p1.Y, 4.0f);
    EXPECT_REAL_EQ(p1.Z, 5.0f);
}

TEST(Point3Tests, MultiplicationScalar)
{
    Point3f p1(1, 2, 3);

    Point3f p2 = p1 * 5.0f;

    EXPECT_REAL_EQ(p2.X, 5.0f);
    EXPECT_REAL_EQ(p2.Y, 10.0f);
    EXPECT_REAL_EQ(p2.Z, 15.0f);

    p2 *= 2.0f;
    EXPECT_REAL_EQ(p2.X, 10.0f);
    EXPECT_REAL_EQ(p2.Y, 20.0f);
    EXPECT_REAL_EQ(p2.Z, 30.0f);

    Point3f p3 = 2.0f * p2;
    EXPECT_REAL_EQ(p3.X, 20.0f);
    EXPECT_REAL_EQ(p3.Y, 40.0f);
    EXPECT_REAL_EQ(p3.Z, 60.0f);
}

TEST(Point3Tests, DivisionScalar)
{
    Point3f p1(20.0f, 40.0f, 60.0f);

    Point3f p2 = p1 / 2.0f;

    EXPECT_REAL_EQ(p2.X, 10.0f);
    EXPECT_REAL_EQ(p2.Y, 20.0f);
    EXPECT_REAL_EQ(p2.Z, 30.0f);

    p2 /= 2.0f;
    EXPECT_REAL_EQ(p2.X, 5.0f);
    EXPECT_REAL_EQ(p2.Y, 10.0f);
    EXPECT_REAL_EQ(p2.Z, 15.0f);
}

TEST(Point3Tests, Negation)
{
    Point3f p(5, -10, -15);
    Point3f neg = -p;

    EXPECT_REAL_EQ(neg.X, -5.0f);
    EXPECT_REAL_EQ(neg.Y, 10.0f);
    EXPECT_REAL_EQ(neg.Z, 15.0f);
}

TEST(Point3Tests, Abs)
{
    Point3f p(5, -10, -15);
    Point3f a = p.Abs();

    EXPECT_REAL_EQ(a.X, 5.0f);
    EXPECT_REAL_EQ(a.Y, 10.0f);
    EXPECT_REAL_EQ(a.Z, 15.0f);
}

TEST(Point3Tests, Distance)
{
    Point3f p1(2, 2, 2);
    Point3f p2(2, 2, 4);

    EXPECT_REAL_EQ(Distance(p1, p2), 2);
    EXPECT_REAL_EQ(DistanceSquared(p1, p2), 4);
}

TEST(Point3Tests, Lerp)
{
    Point3f p1(2, 2, 2);
    Point3f p2(2, 2, 4);

    Point3f p3 = Lerp(0.5f, p1, p2);
    EXPECT_REAL_EQ(p3.Z, 3.0f);
}

TEST(Point3Tests, Floor)
{
    Point3f p1(2.3f, 2.67f, -2.5f);
    Point3f p2 = Floor(p1);

    EXPECT_REAL_EQ(p2.X, 2.0f);
    EXPECT_REAL_EQ(p2.Y, 2.0f);
    EXPECT_REAL_EQ(p2.Z, -3.0f);
}

TEST(Point3Tests, Ceil)
{
    Point3f p1(2.3f, 2.67f, -2.5f);
    Point3f p2 = Ceil(p1);

    EXPECT_REAL_EQ(p2.X, 3.0f);
    EXPECT_REAL_EQ(p2.Y, 3.0f);
    EXPECT_REAL_EQ(p2.Z, -2.0f);
}

TEST(Point3Tests, Round)
{
    Point3f p1(1.3f, 2.6f, 3.5f);
    Point3f p2 = Round(p1);
    EXPECT_REAL_EQ(p2.X, 1.0f);
    EXPECT_REAL_EQ(p2.Y, 3.0f);
    EXPECT_REAL_EQ(p2.Z, 4.0f);
}

TEST(Point3Tests, Misc)
{
    Point3f p1(1, 2, 3);
    Point3f p2(3, -2, 5);
    Point3f min = Min(p1, p2);
    Point3f max = Max(p1, p2);

    EXPECT_REAL_EQ(min.X, 1.0f);
    EXPECT_REAL_EQ(min.Y, -2.0f);
    EXPECT_REAL_EQ(min.Z, 3.0f);
    EXPECT_REAL_EQ(max.X, 3.0f);
    EXPECT_REAL_EQ(max.Y, 2.0f);
    EXPECT_REAL_EQ(max.Z, 5.0f);

    Point3f p(1, 2, 3);
    Point3f perm = Permute(p, 1, 2, 0);
    EXPECT_REAL_EQ(perm.X, 2.0f);
    EXPECT_REAL_EQ(perm.Y, 3.0f);
    EXPECT_REAL_EQ(perm.Z, 1.0f);
}
