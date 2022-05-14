#include <gtest/gtest.h>

#include "math/math.h"

using Point2f = math::Point2<float>;
using Vector2f = math::Vector2<float>;

TEST(Point2Tests, GettersSettersConstruction)
{
    {
        Point2f p;
        EXPECT_EQ(p.X, 0);
        EXPECT_EQ(p.Y, 0);
    }

    {
        Point2f p(10.0f, 15.0f);
        EXPECT_FLOAT_EQ(p.X, 10.0f);
        EXPECT_FLOAT_EQ(p.Y, 15.0f);
    }

    {
        Point2f p;
        p.X = 5.0f;
        EXPECT_FLOAT_EQ(p.X, 5.0f);
        p.Y = 10.0f;
        EXPECT_FLOAT_EQ(p.Y, 10.0f);
        p.Set(15.0f, 0);
        EXPECT_FLOAT_EQ(p[0], 15.0f);
        p.Set(20.0f, 1);
        EXPECT_FLOAT_EQ(p[1], 20.0f);
    }
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
    EXPECT_FLOAT_EQ(p3.X, 4.0f);
    EXPECT_FLOAT_EQ(p3.Y, 6.0f);

    p3 += p1;
    EXPECT_FLOAT_EQ(p3.X, 5.0f);
    EXPECT_FLOAT_EQ(p3.Y, 8.0f);

    Vector2f v(3, 4);
    Point2f p4 = p1 + v;
    EXPECT_FLOAT_EQ(p4.X, 4.0f);
    EXPECT_FLOAT_EQ(p4.Y, 6.0f);

    p4 += v;
    EXPECT_FLOAT_EQ(p4.X, 7.0f);
    EXPECT_FLOAT_EQ(p4.Y, 10.0f);
}

TEST(Point2Tests, Subtraction)
{
    Point2f p1(10, 11);
    Point2f p2(3, 4);
    Vector2f v1(1, 2);

    Point2f p3 = p1 - v1;
    EXPECT_FLOAT_EQ(p3.X, 9.0f);
    EXPECT_FLOAT_EQ(p3.Y, 9.0f);

    Vector2f v2 = p1 - p2;
    EXPECT_FLOAT_EQ(v2.X, 7.0f);
    EXPECT_FLOAT_EQ(v2.Y, 7.0f);

    p1 -= v2;
    EXPECT_FLOAT_EQ(p1.X, 3.0f);
    EXPECT_FLOAT_EQ(p1.Y, 4.0f);
}

TEST(Point2Tests, MultiplicationScalar)
{
    Point2f p1(1, 2);

    Point2f p2 = p1 * 5.0f;

    EXPECT_FLOAT_EQ(p2.X, 5.0f);
    EXPECT_FLOAT_EQ(p2.Y, 10.0f);

    p2 *= 2.0f;
    EXPECT_FLOAT_EQ(p2.X, 10.0f);
    EXPECT_FLOAT_EQ(p2.Y, 20.0f);

    Point2f p3 = 2.0f * p2;
    EXPECT_FLOAT_EQ(p3.X, 20.0f);
    EXPECT_FLOAT_EQ(p3.Y, 40.0f);
}

TEST(Point2Tests, DivisionScalar)
{
    Point2f p1(20.0f, 40.0f);

    Point2f p2 = p1 / 2.0f;

    EXPECT_FLOAT_EQ(p2.X, 10.0f);
    EXPECT_FLOAT_EQ(p2.Y, 20.0f);

    p2 /= 2.0f;
    EXPECT_FLOAT_EQ(p2.X, 5.0f);
    EXPECT_FLOAT_EQ(p2.Y, 10.0f);
}

TEST(Point2Tests, Negation)
{
    Point2f p(5, -10);
    Point2f neg = -p;

    EXPECT_FLOAT_EQ(neg.X, -5.0f);
    EXPECT_FLOAT_EQ(neg.Y, 10.0f);
}

TEST(Point2Tests, Abs)
{
    Point2f p(5, -10);
    Point2f a = p.Abs();

    EXPECT_FLOAT_EQ(a.X, 5.0f);
    EXPECT_FLOAT_EQ(a.Y, 10.0f);
}

TEST(Point2Tests, Distance)
{
    Point2f p1(2, 2);
    Point2f p2(2, 4);

    EXPECT_FLOAT_EQ(Distance(p1, p2), 2);
    EXPECT_FLOAT_EQ(DistanceSquared(p1, p2), 4);
}

TEST(Point2Tests, Lerp)
{
    Point2f p1(2, 2);
    Point2f p2(2, 4);

    Point2f p3 = Lerp(0.5f, p1, p2);
    EXPECT_FLOAT_EQ(p3.Y, 3.0f);
}

TEST(Point2Tests, Floor)
{
    Point2f p1(2.3, -2.5);
    Point2f p2 = Floor(p1);

    EXPECT_FLOAT_EQ(p2.X, 2.0f);
    EXPECT_FLOAT_EQ(p2.Y, -3.0f);
}

TEST(Point2Tests, Ceil)
{
    Point2f p1(2.3, -2.5);
    Point2f p2 = Ceil(p1);

    EXPECT_FLOAT_EQ(p2.X, 3.0f);
    EXPECT_FLOAT_EQ(p2.Y, -2.0f);
}

TEST(Point2Tests, Misc)
{
    Point2f p1(1, 2);
    Point2f p2(3, -2);
    Point2f min = Min(p1, p2);
    Point2f max = Max(p1, p2);

    EXPECT_FLOAT_EQ(min.X, 1.0f);
    EXPECT_FLOAT_EQ(min.Y, -2.0f);
    EXPECT_FLOAT_EQ(max.X, 3.0f);
    EXPECT_FLOAT_EQ(max.Y, 2.0f);

    Point2f p(1, 2);
    Point2f perm = Permute(p, 1, 0);
    EXPECT_FLOAT_EQ(perm.X, 2.0f);
    EXPECT_FLOAT_EQ(perm.Y, 1.0f);
}
