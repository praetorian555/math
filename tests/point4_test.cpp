#include "math/point4.h"
#include "math/vector4.h"

#include "math/point3.h"
#include "realexpect.h"

using Point4f = math::Point4;
using Vector4f = math::Vector4;

TEST(Point4Tests, GettersSettersConstruction)
{
    {
        Point4f p;
        EXPECT_EQ(p.X, 0);
        EXPECT_EQ(p.Y, 0);
        EXPECT_EQ(p.Z, 0);
        EXPECT_EQ(p.W, 0);
    }

    {
        Point4f p(10.0f, 15.0f, 20.0f, 30.0f);
        EXPECT_REAL_EQ(p.Data[0], 10.0f);
        EXPECT_REAL_EQ(p.Data[1], 15.0f);
        EXPECT_REAL_EQ(p.Data[2], 20.0f);
        EXPECT_REAL_EQ(p.Data[3], 30.0f);
    }

    {
        Point4f p;
        p.X = 5.0f;
        EXPECT_REAL_EQ(p.X, 5.0f);
        p.Y = 10.0f;
        EXPECT_REAL_EQ(p.Y, 10.0f);
        p.Z = 50.0f;
        EXPECT_REAL_EQ(p.Z, 50.0f);
        p.W = 60.0f;
        EXPECT_REAL_EQ(p.W, 60.0f);
        p.Set(15.0f, 0);
        EXPECT_REAL_EQ(p[0], 15.0f);
        p.Set(20.0f, 1);
        EXPECT_REAL_EQ(p[1], 20.0f);
        p.Set(55.0f, 2);
        EXPECT_REAL_EQ(p[2], 55.0f);
        p.Set(75.0f, 3);
        EXPECT_REAL_EQ(p[3], 75.0f);
    }

    {
        math::Point3 p3(10.0f, 15.0f, 20.0f);
        math::Point4 p4(p3);
        EXPECT_REAL_EQ(p4.X, 10.0f);
        EXPECT_REAL_EQ(p4.Y, 15.0f);
        EXPECT_REAL_EQ(p4.Z, 20.0f);
        EXPECT_REAL_EQ(p4.W, 0.0f);
    }
}

TEST(Point4Tests, Nans)
{
    Point4f p1(nanf(""), 10.0f, 15.0f, 25.0f);
    EXPECT_TRUE(p1.HasNaNs());

    Point4f p2(15.0f, nanf(""), 10.0f, 25.0f);
    EXPECT_TRUE(p2.HasNaNs());

    Point4f p3(15.0f, 10.0f, nanf(""), 25.0f);
    EXPECT_TRUE(p3.HasNaNs());

    Point4f p4(15.0f, 10.0f, 25.0f, nanf(""));
    EXPECT_TRUE(p4.HasNaNs());
}

TEST(Point4Tests, Comparison)
{
    Point4f p1(1, 2, 3, 4);
    Point4f p2(3, 2, 5, 4);
    Point4f p3(1, 2, 3, 4);

    EXPECT_TRUE(p1 == p3);
    EXPECT_TRUE(p1 != p2);
}

TEST(Point4Tests, Addition)
{
    Point4f p1(1, 2, 3, 4);
    Point4f p2(3, 4, 5, 6);

    Point4f p3 = p1 + p2;
    EXPECT_REAL_EQ(p3.X, 4.0f);
    EXPECT_REAL_EQ(p3.Y, 6.0f);
    EXPECT_REAL_EQ(p3.Z, 8.0f);
    EXPECT_REAL_EQ(p3.W, 10.0f);

    p3 += p1;
    EXPECT_REAL_EQ(p3.X, 5.0f);
    EXPECT_REAL_EQ(p3.Y, 8.0f);
    EXPECT_REAL_EQ(p3.Z, 11.0f);
    EXPECT_REAL_EQ(p3.W, 14.0f);

    Vector4f v(3, 4, 5, 6);
    Point4f p4 = p1 + v;
    EXPECT_REAL_EQ(p4.X, 4.0f);
    EXPECT_REAL_EQ(p4.Y, 6.0f);
    EXPECT_REAL_EQ(p4.Z, 8.0f);
    EXPECT_REAL_EQ(p4.W, 10.0f);

    p4 += v;
    EXPECT_REAL_EQ(p4.X, 7.0f);
    EXPECT_REAL_EQ(p4.Y, 10.0f);
    EXPECT_REAL_EQ(p4.Z, 13.0f);
    EXPECT_REAL_EQ(p4.W, 16.0f);
}

TEST(Point4Tests, Subtraction)
{
    Point4f p1(10, 11, 12, 13);
    Point4f p2(3, 4, 5, 6);
    Vector4f v1(1, 2, 3, 4);

    Point4f p3 = p1 - v1;
    EXPECT_REAL_EQ(p3.X, 9.0f);
    EXPECT_REAL_EQ(p3.Y, 9.0f);
    EXPECT_REAL_EQ(p3.Z, 9.0f);
    EXPECT_REAL_EQ(p3.W, 9.0f);

    Vector4f v2 = p1 - p2;
    EXPECT_REAL_EQ(v2.X, 7.0f);
    EXPECT_REAL_EQ(v2.Y, 7.0f);
    EXPECT_REAL_EQ(v2.Z, 7.0f);
    EXPECT_REAL_EQ(v2.W, 7.0f);

    p1 -= v2;
    EXPECT_REAL_EQ(p1.X, 3.0f);
    EXPECT_REAL_EQ(p1.Y, 4.0f);
    EXPECT_REAL_EQ(p1.Z, 5.0f);
    EXPECT_REAL_EQ(p1.W, 6.0f);
}

TEST(Point4Tests, MultiplicationScalar)
{
    Point4f p1(1, 2, 3, 4);

    Point4f p2 = p1 * 5.0f;

    EXPECT_REAL_EQ(p2.X, 5.0f);
    EXPECT_REAL_EQ(p2.Y, 10.0f);
    EXPECT_REAL_EQ(p2.Z, 15.0f);
    EXPECT_REAL_EQ(p2.W, 20.0f);

    p2 *= 2.0f;
    EXPECT_REAL_EQ(p2.X, 10.0f);
    EXPECT_REAL_EQ(p2.Y, 20.0f);
    EXPECT_REAL_EQ(p2.Z, 30.0f);
    EXPECT_REAL_EQ(p2.W, 40.0f);

    Point4f p3 = 2.0f * p2;
    EXPECT_REAL_EQ(p3.X, 20.0f);
    EXPECT_REAL_EQ(p3.Y, 40.0f);
    EXPECT_REAL_EQ(p3.Z, 60.0f);
    EXPECT_REAL_EQ(p3.W, 80.0f);
}

TEST(Point4Tests, DivisionScalar)
{
    Point4f p1(20.0f, 40.0f, 60.0f, 80.0f);

    Point4f p2 = p1 / 2.0f;

    EXPECT_REAL_EQ(p2.X, 10.0f);
    EXPECT_REAL_EQ(p2.Y, 20.0f);
    EXPECT_REAL_EQ(p2.Z, 30.0f);
    EXPECT_REAL_EQ(p2.W, 40.0f);

    p2 /= 2.0f;
    EXPECT_REAL_EQ(p2.X, 5.0f);
    EXPECT_REAL_EQ(p2.Y, 10.0f);
    EXPECT_REAL_EQ(p2.Z, 15.0f);
    EXPECT_REAL_EQ(p2.W, 20.0f);
}

TEST(Point4Tests, Negation)
{
    Point4f p(5, -10, -15, 20);
    Point4f neg = -p;

    EXPECT_REAL_EQ(neg.X, -5.0f);
    EXPECT_REAL_EQ(neg.Y, 10.0f);
    EXPECT_REAL_EQ(neg.Z, 15.0f);
    EXPECT_REAL_EQ(neg.W, -20.0f);
}

TEST(Point4Tests, Abs)
{
    Point4f p(5, -10, -15, 20);
    Point4f a = p.Abs();

    EXPECT_REAL_EQ(a.X, 5.0f);
    EXPECT_REAL_EQ(a.Y, 10.0f);
    EXPECT_REAL_EQ(a.Z, 15.0f);
    EXPECT_REAL_EQ(a.W, 20.0f);
}

TEST(Point4Tests, Euclidian)
{
    Point4f p1(10, -10, -20, 2);
    Point4f p2 = p1.ToEuclidean();
    EXPECT_REAL_EQ(p2.X, 5.0f);
    EXPECT_REAL_EQ(p2.Y, -5.0f);
    EXPECT_REAL_EQ(p2.Z, -10.0f);
    EXPECT_REAL_EQ(p2.W, 1.0f);
}

TEST(Point4Tests, Distance)
{
    Point4f p1(2, 2, 2, 2);
    Point4f p2(2, 2, 4, 2);

    EXPECT_REAL_EQ(Distance(p1, p2), 2);
    EXPECT_REAL_EQ(DistanceSquared(p1, p2), 4);
}

TEST(Point4Tests, Lerp)
{
    Point4f p1(2, 2, 2, 1);
    Point4f p2(2, 2, 4, 10);

    Point4f p3 = Lerp(0.5f, p1, p2);
    EXPECT_REAL_EQ(p3.Z, 3.0f);
    EXPECT_REAL_EQ(p3.W, 5.5f);
}

TEST(Point4Tests, Floor)
{
    Point4f p1(2.3f, 2.67f, -2.5f, -1.2f);
    Point4f p2 = Floor(p1);

    EXPECT_REAL_EQ(p2.X, 2.0f);
    EXPECT_REAL_EQ(p2.Y, 2.0f);
    EXPECT_REAL_EQ(p2.Z, -3.0f);
    EXPECT_REAL_EQ(p2.W, -2.0f);
}

TEST(Point4Tests, Ceil)
{
    Point4f p1(2.3f, 2.67f, -2.5f, -1.2f);
    Point4f p2 = Ceil(p1);

    EXPECT_REAL_EQ(p2.X, 3.0f);
    EXPECT_REAL_EQ(p2.Y, 3.0f);
    EXPECT_REAL_EQ(p2.Z, -2.0f);
    EXPECT_REAL_EQ(p2.W, -1.0f);
}

TEST(Point4Tests, Round)
{
    Point4f p1(1.3f, 2.6f, 3.5f, -1.2f);
    Point4f p2 = Round(p1);
    EXPECT_REAL_EQ(p2.X, 1.0f);
    EXPECT_REAL_EQ(p2.Y, 3.0f);
    EXPECT_REAL_EQ(p2.Z, 4.0f);
    EXPECT_REAL_EQ(p2.W, -1.0f);
}

TEST(Point4Tests, Misc)
{
    Point4f p1(1, 2, 3, 5);
    Point4f p2(3, -2, 5, -5);
    Point4f min = Min(p1, p2);
    Point4f max = Max(p1, p2);

    EXPECT_REAL_EQ(min.X, 1.0f);
    EXPECT_REAL_EQ(min.Y, -2.0f);
    EXPECT_REAL_EQ(min.Z, 3.0f);
    EXPECT_REAL_EQ(min.W, -5.0f);
    EXPECT_REAL_EQ(max.X, 3.0f);
    EXPECT_REAL_EQ(max.Y, 2.0f);
    EXPECT_REAL_EQ(max.Z, 5.0f);
    EXPECT_REAL_EQ(max.W, 5.0f);

    Point4f p(1, 2, 3, 4);
    Point4f perm = Permute(p, 1, 2, 3, 0);
    EXPECT_REAL_EQ(perm.X, 2.0f);
    EXPECT_REAL_EQ(perm.Y, 3.0f);
    EXPECT_REAL_EQ(perm.Z, 4.0f);
    EXPECT_REAL_EQ(perm.W, 1.0f);
}
