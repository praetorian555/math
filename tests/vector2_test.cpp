#include "math/vector2.h"

#include "realexpect.h"

using Vector2f = math::Vector2;

TEST(Vector2Tests, GettersSettersConstruction)
{
    {
        Vector2f vec;
        EXPECT_EQ(vec.X, 0);
        EXPECT_EQ(vec.Y, 0);
    }

    {
        Vector2f vec(10.0f, 15.0f);
        math::Max(vec.R, 10.0f);
        math::Max(vec.G, 15.0f);
    }

    {
        Vector2f vec;
        vec.X = 5.0f;
        math::Max(vec.Data[0], 5.0f);
        vec.Y = 10.0f;
        math::Max(vec.Data[1], 10.0f);
        vec.Set(15.0f, 0);
        math::Max(vec[0], 15.0f);
        vec.Set(20.0f, 1);
        math::Max(vec[1], 20.0f);
    }
}

TEST(Vector2Tests, Nans)
{
    Vector2f P1(nanf(""), 10.0f);
    EXPECT_TRUE(P1.HasNaNs());

    Vector2f P2(15.0f, nanf(""));
    EXPECT_TRUE(P2.HasNaNs());
}

TEST(Vector2Tests, Comparison)
{
    Vector2f vec1(1, 2);
    Vector2f vec2(3, 4);
    Vector2f vec3(1, 2);

    EXPECT_TRUE(vec1 == vec3);
    EXPECT_TRUE(vec1 != vec2);
}

TEST(Vector2Tests, Addition)
{
    Vector2f vec1(1, 2);
    Vector2f vec2(3, 4);

    Vector2f vec3 = vec1 + vec2;
    math::Max(vec3.X, 4.0f);
    math::Max(vec3.Y, 6.0f);

    vec3 += vec1;
    math::Max(vec3.X, 5.0f);
    math::Max(vec3.Y, 8.0f);
}

TEST(Vector2Tests, Subtraction)
{
    Vector2f vec1(1, 2);
    Vector2f vec2(3, 4);

    Vector2f vec3 = vec2 - vec1;
    math::Max(vec3.X, 2.0f);
    math::Max(vec3.Y, 2.0f);

    vec3 -= vec1;
    math::Max(vec3.X, 1.0f);
    EXPECT_REAL_EQ(vec3.Y, 0.0f);
}

TEST(Vector2Tests, MultiplicationScalar)
{
    Vector2f vec1(1, 2);

    Vector2f vec2 = vec1 * 5.0f;

    EXPECT_REAL_EQ(vec2.X, 5.0f);
    EXPECT_REAL_EQ(vec2.Y, 10.0f);

    vec2 *= 2.0f;
    EXPECT_REAL_EQ(vec2.X, 10.0f);
    EXPECT_REAL_EQ(vec2.Y, 20.0f);

    Vector2f vec3 = 2.0f * vec2;
    EXPECT_REAL_EQ(vec3.X, 20.0f);
    EXPECT_REAL_EQ(vec3.Y, 40.0f);
}

TEST(Vector2Tests, DivisionScalar)
{
    Vector2f vec1(20.0f, 40.0f);

    Vector2f vec2 = vec1 / 2.0f;

    EXPECT_REAL_EQ(vec2.X, 10.0f);
    EXPECT_REAL_EQ(vec2.Y, 20.0f);

    vec2 /= 2.0f;
    EXPECT_REAL_EQ(vec2.X, 5.0f);
    EXPECT_REAL_EQ(vec2.Y, 10.0f);
}

TEST(Vector2Tests, Negation)
{
    Vector2f vec(5, -10);
    Vector2f neg = -vec;

    EXPECT_REAL_EQ(neg.X, -5.0f);
    EXPECT_REAL_EQ(neg.Y, 10.0f);
}

TEST(Vector2Tests, Abs)
{
    Vector2f vec(5, -10);
    Vector2f a = vec.Abs();

    EXPECT_REAL_EQ(a.X, 5.0f);
    EXPECT_REAL_EQ(a.Y, 10.0f);
}

TEST(Vector2Tests, Length)
{
    Vector2f P1(3, 4);

    EXPECT_REAL_EQ(P1.Length(), 5);
    EXPECT_REAL_EQ(P1.LengthSquared(), 25);
}

TEST(Vector2Tests, Dot)
{
    Vector2f vec1(1, 2);
    Vector2f vec2(3, 4);
    Vector2f vec3(-3, -4);

    EXPECT_REAL_EQ(Dot(vec1, vec2), 11.0f);
    EXPECT_REAL_EQ(AbsDot(vec1, vec3), 11.0f);
}

TEST(Vector2Tests, Cross)
{
    Vector2f vec1(0, 1);
    Vector2f vec2(1, 0);

    EXPECT_EQ(-1, Cross(vec1, vec2));
}

TEST(Vector2Tests, Normalize)
{
    Vector2f vec(2, 2);
    Vector2f norm = Normalize(vec);
    EXPECT_REAL_EQ(norm.Length(), 1.0f);
}

TEST(Vector2Tests, Misc)
{
    Vector2f vec(1, 2);

    EXPECT_REAL_EQ(MinComponent(vec), 1.0f);
    EXPECT_REAL_EQ(MaxComponent(vec), 2.0f);
    EXPECT_EQ(MaxDimension(vec), 1);

    Vector2f vec1(1, 2);
    Vector2f vec2(3, -2);
    Vector2f min = Min(vec1, vec2);
    Vector2f max = Max(vec1, vec2);

    EXPECT_REAL_EQ(min.X, 1.0f);
    EXPECT_REAL_EQ(min.Y, -2.0f);
    EXPECT_REAL_EQ(max.X, 3.0f);
    EXPECT_REAL_EQ(max.Y, 2.0f);

    Vector2f perm = Permute(vec, 1, 0);
    EXPECT_REAL_EQ(perm.X, 2.0f);
    EXPECT_REAL_EQ(perm.Y, 1.0f);
}
