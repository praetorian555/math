#include <gtest/gtest.h>

#include "math/normal3.h"
#include "math/vector3.h"

using Normal3f = math::Normal3;
using Vector3f = math::Vector3;

TEST(Normal3Tests, GettersSettersConstruction)
{
    {
        Normal3f n;
        EXPECT_EQ(n.X, 0);
        EXPECT_EQ(n.Y, 0);
        EXPECT_EQ(n.Z, 0);
    }

    {
        Normal3f n(10.0f, 15.0f, 20.0f);
        EXPECT_FLOAT_EQ(n.X, 10.0f);
        EXPECT_FLOAT_EQ(n.Y, 15.0f);
        EXPECT_FLOAT_EQ(n.Z, 20.0f);
    }

    {
        Normal3f n;
        n.X = 5.0f;
        EXPECT_FLOAT_EQ(n.Data[0], 5.0f);
        n.Y = 10.0f;
        EXPECT_FLOAT_EQ(n.Data[1], 10.0f);
        n.Z = 50.0f;
        EXPECT_FLOAT_EQ(n.Data[2], 50.0f);
        n.Set(15.0f, 0);
        EXPECT_FLOAT_EQ(n[0], 15.0f);
        n.Set(20.0f, 1);
        EXPECT_FLOAT_EQ(n[1], 20.0f);
        n.Set(55.0f, 2);
        EXPECT_FLOAT_EQ(n[2], 55.0f);
    }
}

TEST(Normal3Tests, Nans)
{
    Normal3f n1(nanf(""), 10, 15);
    EXPECT_TRUE(n1.HasNaNs());

    Normal3f n2(15, nanf(""), 10);
    EXPECT_TRUE(n2.HasNaNs());

    Normal3f n3(15, 10, nanf(""));
    EXPECT_TRUE(n3.HasNaNs());
}

TEST(Normal3Tests, Comparison)
{
    Normal3f n1(1, 2, 3);
    Normal3f n2(3, 4, 5);
    Normal3f n3(1, 2, 3);

    EXPECT_TRUE(n1 == n3);
    EXPECT_TRUE(n1 != n2);
}

TEST(Normal3Tests, Addition)
{
    Normal3f n1(1, 2, 3);
    Normal3f n2(3, 4, 5);

    Normal3f n3 = n1 + n2;
    EXPECT_FLOAT_EQ(n3.X, 4.0f);
    EXPECT_FLOAT_EQ(n3.Y, 6.0f);
    EXPECT_FLOAT_EQ(n3.Z, 8.0f);

    n3 += n1;
    EXPECT_FLOAT_EQ(n3.X, 5.0f);
    EXPECT_FLOAT_EQ(n3.Y, 8.0f);
    EXPECT_FLOAT_EQ(n3.Z, 11.0f);
}

TEST(Normal3Tests, Subtraction)
{
    Normal3f n1(1, 2, 3);
    Normal3f n2(3, 4, 5);

    Normal3f n3 = n2 - n1;
    EXPECT_FLOAT_EQ(n3.X, 2.0f);
    EXPECT_FLOAT_EQ(n3.Y, 2.0f);
    EXPECT_FLOAT_EQ(n3.Z, 2.0f);

    n3 -= n1;
    EXPECT_FLOAT_EQ(n3.X, 1.0f);
    EXPECT_FLOAT_EQ(n3.Y, 0.0f);
    EXPECT_FLOAT_EQ(n3.Z, -1.0f);
}

TEST(Normal3Tests, MultiplicationScalar)
{
    Normal3f n1(1, 2, 3);

    Normal3f n2 = n1 * 5.0f;

    EXPECT_FLOAT_EQ(n2.X, 5.0f);
    EXPECT_FLOAT_EQ(n2.Y, 10.0f);
    EXPECT_FLOAT_EQ(n2.Z, 15.0f);

    n2 *= 2.0f;
    EXPECT_FLOAT_EQ(n2.X, 10.0f);
    EXPECT_FLOAT_EQ(n2.Y, 20.0f);
    EXPECT_FLOAT_EQ(n2.Z, 30.0f);

    Normal3f n3 = 2.0f * n2;
    EXPECT_FLOAT_EQ(n3.X, 20.0f);
    EXPECT_FLOAT_EQ(n3.Y, 40.0f);
    EXPECT_FLOAT_EQ(n3.Z, 60.0f);
}

TEST(Normal3Tests, DivisionScalar)
{
    Normal3f n1(20.0f, 40.0f, 60.0f);

    Normal3f n2 = n1 / 2.0f;

    EXPECT_FLOAT_EQ(n2.X, 10.0f);
    EXPECT_FLOAT_EQ(n2.Y, 20.0f);
    EXPECT_FLOAT_EQ(n2.Z, 30.0f);

    n2 /= 2.0f;
    EXPECT_FLOAT_EQ(n2.X, 5.0f);
    EXPECT_FLOAT_EQ(n2.Y, 10.0f);
    EXPECT_FLOAT_EQ(n2.Z, 15.0f);
}

TEST(Normal3Tests, Negation)
{
    Normal3f n(5, -10, -15);
    Normal3f neg = -n;

    EXPECT_FLOAT_EQ(neg.X, -5.0f);
    EXPECT_FLOAT_EQ(neg.Y, 10.0f);
    EXPECT_FLOAT_EQ(neg.Z, 15.0f);
}

TEST(Normal3Tests, Abs)
{
    Normal3f n(5, -10, -15);
    Normal3f a = n.Abs();

    EXPECT_FLOAT_EQ(a.X, 5.0f);
    EXPECT_FLOAT_EQ(a.Y, 10.0f);
    EXPECT_FLOAT_EQ(a.Z, 15.0f);
}

TEST(Normal3Tests, Length)
{
    Normal3f n1(3, 4, 5);

    EXPECT_FLOAT_EQ(n1.Length(), std::sqrtf(50));
    EXPECT_FLOAT_EQ(n1.LengthSquared(), 50);
}

TEST(Normal3Tests, Dot)
{
    Normal3f n1(1, 2, 3);
    Normal3f n2(3, 4, 5);
    Normal3f n3(-3, -4, -5);
    Vector3f v1(3, 4, 5);
    Vector3f v2(-3, -4, -5);

    EXPECT_FLOAT_EQ(Dot(n1, n2), 26.0f);
    EXPECT_FLOAT_EQ(Dot(n1, v1), 26.0f);
    EXPECT_FLOAT_EQ(Dot(v1, n1), 26.0f);
    EXPECT_FLOAT_EQ(AbsDot(n1, n3), 26.0f);
    EXPECT_FLOAT_EQ(AbsDot(n1, v2), 26.0f);
    EXPECT_FLOAT_EQ(AbsDot(v2, n1), 26.0f);
}

TEST(Normal3Tests, Normalize)
{
    Normal3f n(2, 3, 5);
    Normal3f norm = Normalize(n);
    EXPECT_FLOAT_EQ(norm.Length(), 1.0f);
}

TEST(Normal3Tests, Misc)
{
    Normal3f n(1, 2, 3);

    EXPECT_FLOAT_EQ(MinComponent(n), 1.0f);
    EXPECT_FLOAT_EQ(MaxComponent(n), 3.0f);
    EXPECT_EQ(MaxDimension(n), 2);

    Normal3f n1(1, 2, 3);
    Normal3f n2(3, -2, 5);
    Normal3f min = Min(n1, n2);
    Normal3f max = Max(n1, n2);

    EXPECT_FLOAT_EQ(min.X, 1.0f);
    EXPECT_FLOAT_EQ(min.Y, -2.0f);
    EXPECT_FLOAT_EQ(min.Z, 3.0f);
    EXPECT_FLOAT_EQ(max.X, 3.0f);
    EXPECT_FLOAT_EQ(max.Y, 2.0f);
    EXPECT_FLOAT_EQ(max.Z, 5.0f);

    Normal3f perm = Permute(n, 1, 2, 0);
    EXPECT_FLOAT_EQ(perm.X, 2.0f);
    EXPECT_FLOAT_EQ(perm.Y, 3.0f);
    EXPECT_FLOAT_EQ(perm.Z, 1.0f);
}

TEST(Normal3Tests, Faceforward)
{
    Normal3f n1(1, 2, 3);
    Vector3f v1(1, 2, 5);
    Vector3f v2(-1, -2, -5);

    EXPECT_TRUE(Faceforward(n1, v1) == n1);
    EXPECT_TRUE(Faceforward(n1, v2) == -n1);
}
