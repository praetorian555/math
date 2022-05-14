#include <gtest/gtest.h>

#include "math/math.h"

using Vector3f = math::Vector3<float>;

TEST(Vector3Tests, GettersSettersConstruction)
{
    {
        Vector3f vec;
        EXPECT_EQ(vec.X, 0);
        EXPECT_EQ(vec.Y, 0);
        EXPECT_EQ(vec.Z, 0);
    }

    {
        Vector3f vec(10.0f, 15.0f, 20.0f);
        EXPECT_FLOAT_EQ(vec.X, 10.0f);
        EXPECT_FLOAT_EQ(vec.Y, 15.0f);
        EXPECT_FLOAT_EQ(vec.Z, 20.0f);
    }

    {
        Vector3f vec;
        vec.X = 5.0f;
        EXPECT_FLOAT_EQ(vec.X, 5.0f);
        vec.Y = 10.0f;
        EXPECT_FLOAT_EQ(vec.Y, 10.0f);
        vec.Z = 50.0f;
        EXPECT_FLOAT_EQ(vec.Z, 50.0f);
        vec.Set(15.0f, 0);
        EXPECT_FLOAT_EQ(vec[0], 15.0f);
        vec.Set(20.0f, 1);
        EXPECT_FLOAT_EQ(vec[1], 20.0f);
        vec.Set(55.0f, 2);
        EXPECT_FLOAT_EQ(vec[2], 55.0f);
    }
}

TEST(Vector3Tests, Comparison)
{
    Vector3f vec1(1, 2, 3);
    Vector3f vec2(3, 4, 5);
    Vector3f vec3(1, 2, 3);

    EXPECT_TRUE(vec1 == vec3);
    EXPECT_TRUE(vec1 != vec2);
}

TEST(Vector3Tests, Addition)
{
    Vector3f vec1(1, 2, 3);
    Vector3f vec2(3, 4, 5);

    Vector3f vec3 = vec1 + vec2;
    EXPECT_FLOAT_EQ(vec3.X, 4.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 6.0f);
    EXPECT_FLOAT_EQ(vec3.Z, 8.0f);

    vec3 += vec1;
    EXPECT_FLOAT_EQ(vec3.X, 5.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 8.0f);
    EXPECT_FLOAT_EQ(vec3.Z, 11.0f);
}

TEST(Vector3Tests, Subtraction)
{
    Vector3f vec1(1, 2, 3);
    Vector3f vec2(3, 4, 5);

    Vector3f vec3 = vec2 - vec1;
    EXPECT_FLOAT_EQ(vec3.X, 2.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 2.0f);
    EXPECT_FLOAT_EQ(vec3.Z, 2.0f);

    vec3 -= vec1;
    EXPECT_FLOAT_EQ(vec3.X, 1.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 0.0f);
    EXPECT_FLOAT_EQ(vec3.Z, -1.0f);
}

TEST(Vector3Tests, MultiplicationScalar)
{
    Vector3f vec1(1, 2, 3);

    Vector3f vec2 = vec1 * 5.0f;

    EXPECT_FLOAT_EQ(vec2.X, 5.0f);
    EXPECT_FLOAT_EQ(vec2.Y, 10.0f);
    EXPECT_FLOAT_EQ(vec2.Z, 15.0f);

    vec2 *= 2.0f;
    EXPECT_FLOAT_EQ(vec2.X, 10.0f);
    EXPECT_FLOAT_EQ(vec2.Y, 20.0f);
    EXPECT_FLOAT_EQ(vec2.Z, 30.0f);

    Vector3f vec3 = 2.0f * vec2;
    EXPECT_FLOAT_EQ(vec3.X, 20.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 40.0f);
    EXPECT_FLOAT_EQ(vec3.Z, 60.0f);
}

TEST(Vector3Tests, DivisionScalar)
{
    Vector3f vec1(20.0f, 40.0f, 60.0f);

    Vector3f vec2 = vec1 / 2.0f;

    EXPECT_FLOAT_EQ(vec2.X, 10.0f);
    EXPECT_FLOAT_EQ(vec2.Y, 20.0f);
    EXPECT_FLOAT_EQ(vec2.Z, 30.0f);

    vec2 /= 2.0f;
    EXPECT_FLOAT_EQ(vec2.X, 5.0f);
    EXPECT_FLOAT_EQ(vec2.Y, 10.0f);
    EXPECT_FLOAT_EQ(vec2.Z, 15.0f);
}

TEST(Vector3Tests, Negation)
{
    Vector3f vec(5, -10, -15);
    Vector3f neg = -vec;

    EXPECT_FLOAT_EQ(neg.X, -5.0f);
    EXPECT_FLOAT_EQ(neg.Y, 10.0f);
    EXPECT_FLOAT_EQ(neg.Z, 15.0f);
}

TEST(Vector3Tests, Abs)
{
    Vector3f vec(5, -10, -15);
    Vector3f a = vec.Abs();

    EXPECT_FLOAT_EQ(a.X, 5.0f);
    EXPECT_FLOAT_EQ(a.Y, 10.0f);
    EXPECT_FLOAT_EQ(a.Z, 15.0f);
}

TEST(Vector3Tests, Dot)
{
    Vector3f vec1(1, 2, 3);
    Vector3f vec2(3, 4, 5);
    Vector3f vec3(-3, -4, -5);

    EXPECT_FLOAT_EQ(Dot(vec1, vec2), 26.0f);
    EXPECT_FLOAT_EQ(AbsDot(vec1, vec3), 26.0f);
}

TEST(Vector3Tests, Cross)
{
    Vector3f x(1, 0, 0);
    Vector3f y(0, 1, 0);
    Vector3f z(0, 0, 1);

    Vector3f c = Cross(x, y);
    EXPECT_TRUE(c == z);
}

TEST(Vector3Tests, Normalize)
{
    Vector3f vec(2, 3, 5);
    Vector3f norm = Normalize(vec);
    EXPECT_FLOAT_EQ(norm.Length(), 1.0f);
}

TEST(Vector3Tests, Misc)
{
    Vector3f vec(1, 2, 3);

    EXPECT_FLOAT_EQ(MinComponent(vec), 1.0f);
    EXPECT_FLOAT_EQ(MaxComponent(vec), 3.0f);
    EXPECT_EQ(MaxDimension(vec), 2);

    Vector3f vec1(1, 2, 3);
    Vector3f vec2(3, -2, 5);
    Vector3f min = Min(vec1, vec2);
    Vector3f max = Max(vec1, vec2);

    EXPECT_FLOAT_EQ(min.X, 1.0f);
    EXPECT_FLOAT_EQ(min.Y, -2.0f);
    EXPECT_FLOAT_EQ(min.Z, 3.0f);
    EXPECT_FLOAT_EQ(max.X, 3.0f);
    EXPECT_FLOAT_EQ(max.Y, 2.0f);
    EXPECT_FLOAT_EQ(max.Z, 5.0f);

    Vector3f perm = Permute(vec, 1, 2, 0);
    EXPECT_FLOAT_EQ(perm.X, 2.0f);
    EXPECT_FLOAT_EQ(perm.Y, 3.0f);
    EXPECT_FLOAT_EQ(perm.Z, 1.0f);
}

TEST(Vector3Tests, CoordinateSystem)
{
    Vector3f x(1, 0, 0);
    Vector3f y, z;

    CoordinateSystem(x, &y, &z);

    EXPECT_FLOAT_EQ(Dot(x, y), 0);
    EXPECT_FLOAT_EQ(Dot(x, z), 0);
    EXPECT_FLOAT_EQ(Dot(z, y), 0);
}
