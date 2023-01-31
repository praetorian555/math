#include "math/point2.h"
#include "math/vector2.h"

#include "realexpect.h"

using Point2f = math::Point2;
using Vector2f = math::Vector2;

TEST(Point2Tests, GettersSettersConstruction)
{
    {
        Point2f p;
        EXPECT_EQ(p.X, 0);
        EXPECT_EQ(p.Y, 0);
    }

    {
        Point2f p(10, 15);
        EXPECT_REAL_EQ(p.Data[0], 10);
        EXPECT_REAL_EQ(p.Data[1], 15);
    }

    {
        Point2f p;
        p.X = 5;
        EXPECT_REAL_EQ(p.X, 5);
        p.Y = 10;
        EXPECT_REAL_EQ(p.Y, 10);
        p.Set(15, 0);
        EXPECT_REAL_EQ(p[0], 15);
        p.Set(20, 1);
        EXPECT_REAL_EQ(p[1], 20);
    }

    {
        Point2f p1;
        p1.Data[0] = 10;
        p1.Data[1] = 15;

        Point2f p2(p1);
        EXPECT_REAL_EQ(p2.X, 10);
        EXPECT_REAL_EQ(p2.Y, 15);
    }
}

TEST(Point2Tests, Nans)
{
    Point2f p1(nanf(""), 10);
    EXPECT_TRUE(p1.HasNaNs());

    Point2f p2(15, nanf(""));
    EXPECT_TRUE(p2.HasNaNs());
}

TEST(Point2Tests, Comparison)
{
    Point2f p1(1, 2);
    Point2f p2(3, 4);
    Point2f p3(1, 2);

    EXPECT_TRUE(p1 == p3);
    EXPECT_TRUE(p1 != p2);
}

TEST(Point2Tests, Addition)
{
    Point2f p1(1, 2);
    Point2f p2(3, 4);

    Point2f p3 = p1 + p2;
    EXPECT_REAL_EQ(p3.X, 4);
    EXPECT_REAL_EQ(p3.Y, 6);

    p3 += p1;
    EXPECT_REAL_EQ(p3.X, 5);
    EXPECT_REAL_EQ(p3.Y, 8);

    Vector2f v(3, 4);
    Point2f p4 = p1 + v;
    EXPECT_REAL_EQ(p4.X, 4);
    EXPECT_REAL_EQ(p4.Y, 6);

    p4 += v;
    EXPECT_REAL_EQ(p4.X, 7);
    EXPECT_REAL_EQ(p4.Y, 10);
}

TEST(Point2Tests, Subtraction)
{
    Point2f p1(10, 11);
    Point2f p2(3, 4);
    Vector2f v1(1, 2);

    Point2f p3 = p1 - v1;
    EXPECT_REAL_EQ(p3.X, 9);
    EXPECT_REAL_EQ(p3.Y, 9);

    Vector2f v2 = p1 - p2;
    EXPECT_REAL_EQ(v2.X, 7);
    EXPECT_REAL_EQ(v2.Y, 7);

    p1 -= v2;
    EXPECT_REAL_EQ(p1.X, 3);
    EXPECT_REAL_EQ(p1.Y, 4);
}

TEST(Point2Tests, MultiplicationScalar)
{
    Point2f p1(1, 2);

    Point2f p2 = p1 * 5;

    EXPECT_REAL_EQ(p2.X, 5);
    EXPECT_REAL_EQ(p2.Y, 10);

    p2 *= 2;
    EXPECT_REAL_EQ(p2.X, 10);
    EXPECT_REAL_EQ(p2.Y, 20);

    Point2f p3 = 2 * p2;
    EXPECT_REAL_EQ(p3.X, 20);
    EXPECT_REAL_EQ(p3.Y, 40);
}

TEST(Point2Tests, DivisionScalar)
{
    Point2f p1(20, 40);

    Point2f p2 = p1 / 2;

    EXPECT_REAL_EQ(p2.X, 10);
    EXPECT_REAL_EQ(p2.Y, 20);

    p2 /= 2;
    EXPECT_REAL_EQ(p2.X, 5);
    EXPECT_REAL_EQ(p2.Y, 10);
}

TEST(Point2Tests, Negation)
{
    Point2f p(5, -10);
    Point2f neg = -p;

    EXPECT_REAL_EQ(neg.X, -5);
    EXPECT_REAL_EQ(neg.Y, 10);
}

TEST(Point2Tests, Abs)
{
    Point2f p(5, -10);
    Point2f a = p.Abs();

    EXPECT_REAL_EQ(a.X, 5);
    EXPECT_REAL_EQ(a.Y, 10);
}

TEST(Point2Tests, Distance)
{
    Point2f p1(2, 2);
    Point2f p2(2, 4);

    EXPECT_REAL_EQ(Distance(p1, p2), 2);
    EXPECT_REAL_EQ(DistanceSquared(p1, p2), 4);
}

TEST(Point2Tests, Lerp)
{
    Point2f p1(2, 2);
    Point2f p2(2, 4);

    Point2f p3 = Lerp(MATH_REALC(0.5), p1, p2);
    EXPECT_REAL_EQ(p3.Y, 3.0);
}

TEST(Point2Tests, Floor)
{
    Point2f p1(MATH_REALC(2.3), MATH_REALC(-2.5));
    Point2f p2 = Floor(p1);

    EXPECT_REAL_EQ(p2.X, 2);
    EXPECT_REAL_EQ(p2.Y, -3);
}

TEST(Point2Tests, Ceil)
{
    Point2f p1(MATH_REALC(2.3), MATH_REALC(-2.5));
    Point2f p2 = Ceil(p1);

    EXPECT_REAL_EQ(p2.X, 3);
    EXPECT_REAL_EQ(p2.Y, -2);
}

TEST(Point2Tests, Round)
{
    Point2f p1(MATH_REALC(1.3), MATH_REALC(3.5));
    Point2f p2 = Round(p1);
    EXPECT_REAL_EQ(p2.X, 1);
    EXPECT_REAL_EQ(p2.Y, 4);

    Point2f p3(MATH_REALC(1.5), MATH_REALC(2.5));
    Point2f p4 = Round(p3);
    EXPECT_REAL_EQ(p4.X, 2);
    EXPECT_REAL_EQ(p4.Y, 3);
}

TEST(Point2Tests, Misc)
{
    Point2f p1(1, 2);
    Point2f p2(3, -2);
    Point2f min = Min(p1, p2);
    Point2f max = Max(p1, p2);

    EXPECT_REAL_EQ(min.X, 1);
    EXPECT_REAL_EQ(min.Y, -2);
    EXPECT_REAL_EQ(max.X, 3);
    EXPECT_REAL_EQ(max.Y, 2);

    Point2f p(1, 2);
    Point2f perm = Permute(p, 1, 0);
    EXPECT_REAL_EQ(perm.X, 2);
    EXPECT_REAL_EQ(perm.Y, 1);
}
