#include <gtest/gtest.h>

#include "math/vector2.h"
#include "math/vector3.h"
#include "math/vector4.h"
#include "math/point4.h"


using Vector4f = math::Vector4;
using Vector2f = math::Vector2;
using Vector3f = math::Vector3;
using Point4f = math::Point4;

TEST(Vector4Tests, GettersSettersConstruction)
{
    {
        Vector4f vec;
        EXPECT_EQ(vec.X, 0);
        EXPECT_EQ(vec.Y, 0);
        EXPECT_EQ(vec.Z, 0);
        EXPECT_EQ(vec.W, 0);
    }

    {
        Vector4f vec(10.0f, 15.0f, 20.0f, 25);
        EXPECT_FLOAT_EQ(vec.R, 10.0f);
        EXPECT_FLOAT_EQ(vec.G, 15.0f);
        EXPECT_FLOAT_EQ(vec.B, 20.0f);
        EXPECT_FLOAT_EQ(vec.A, 25.0f);
    }

    {
        Vector4f vec;
        vec.X = 5.0f;
        EXPECT_FLOAT_EQ(vec.Data[0], 5.0f);
        vec.Y = 10.0f;
        EXPECT_FLOAT_EQ(vec.Data[1], 10.0f);
        vec.Z = 50.0f;
        EXPECT_FLOAT_EQ(vec.Data[2], 50.0f);
        vec.W = 75.0f;
        EXPECT_FLOAT_EQ(vec.Data[3], 75.0f);
        vec.Set(15.0f, 0);
        EXPECT_FLOAT_EQ(vec[0], 15.0f);
        vec.Set(20.0f, 1);
        EXPECT_FLOAT_EQ(vec[1], 20.0f);
        vec.Set(55.0f, 2);
        EXPECT_FLOAT_EQ(vec[2], 55.0f);
        vec.Set(70.0f, 3);
        EXPECT_FLOAT_EQ(vec[3], 70.0f);
    }

    {
        Vector2f vec2(10, 15);
        Vector4f vec4(vec2, 20, 25);
        EXPECT_FLOAT_EQ(vec4.X, 10);
        EXPECT_FLOAT_EQ(vec4.Y, 15);
        EXPECT_FLOAT_EQ(vec4.Z, 20);
        EXPECT_FLOAT_EQ(vec4.W, 25);
    }

    {
        Vector3f vec3(10, 15, 20);
        Vector4f vec4(vec3, 25);
        EXPECT_FLOAT_EQ(vec4.X, 10);
        EXPECT_FLOAT_EQ(vec4.Y, 15);
        EXPECT_FLOAT_EQ(vec4.Z, 20);
        EXPECT_FLOAT_EQ(vec4.W, 25);
    }

    {
        Point4f p(10, 15, 20, 25);
        Vector4f v(p);
        EXPECT_FLOAT_EQ(v.X, 10);
        EXPECT_FLOAT_EQ(v.Y, 15);
        EXPECT_FLOAT_EQ(v.Z, 20);
        EXPECT_FLOAT_EQ(v.W, 25);
    }
}

TEST(Vector4Tests, ToVector2)
{
    Vector4f v(10, 15, 20, 25);

    Vector2f v1 = v.XY();
    Vector2f v2 = v.XZ();
    Vector2f v3 = v.XW();
    Vector2f v4 = v.YZ();
    Vector2f v5 = v.YW();
    Vector2f v6 = v.ZW();
    EXPECT_FLOAT_EQ(v1.X, 10);
    EXPECT_FLOAT_EQ(v1.Y, 15);
    EXPECT_FLOAT_EQ(v2.X, 10);
    EXPECT_FLOAT_EQ(v2.Y, 20);
    EXPECT_FLOAT_EQ(v3.X, 10);
    EXPECT_FLOAT_EQ(v3.Y, 25);
    EXPECT_FLOAT_EQ(v4.X, 15);
    EXPECT_FLOAT_EQ(v4.Y, 20);
    EXPECT_FLOAT_EQ(v5.X, 15);
    EXPECT_FLOAT_EQ(v5.Y, 25);
    EXPECT_FLOAT_EQ(v6.X, 20);
    EXPECT_FLOAT_EQ(v6.Y, 25);
}

TEST(Vector4Tests, ToVector3)
{
    Vector4f v(10, 15, 20, 25);

    Vector3f v1 = v.XYZ();
    Vector3f v2 = v.XYW();
    Vector3f v3 = v.XZW();
    Vector3f v4 = v.YZW();

    EXPECT_FLOAT_EQ(v1.X, 10);
    EXPECT_FLOAT_EQ(v1.Y, 15);
    EXPECT_FLOAT_EQ(v1.Z, 20);
    EXPECT_FLOAT_EQ(v2.X, 10);
    EXPECT_FLOAT_EQ(v2.Y, 15);
    EXPECT_FLOAT_EQ(v2.Z, 25);
    EXPECT_FLOAT_EQ(v3.X, 10);
    EXPECT_FLOAT_EQ(v3.Y, 20);
    EXPECT_FLOAT_EQ(v3.Z, 25);
    EXPECT_FLOAT_EQ(v4.X, 15);
    EXPECT_FLOAT_EQ(v4.Y, 20);
    EXPECT_FLOAT_EQ(v4.Z, 25);
}

TEST(Vector4Tests, Nans)
{
    Vector4f v1(nanf(""), 10, 15, 20);
    EXPECT_TRUE(v1.HasNaNs());

    Vector4f v2(15, nanf(""), 10, 20);
    EXPECT_TRUE(v2.HasNaNs());

    Vector4f v3(15, 10, nanf(""), 20);
    EXPECT_TRUE(v3.HasNaNs());

    Vector4f v4(15, 10, 20, nanf(""));
    EXPECT_TRUE(v4.HasNaNs());
}

TEST(Vector4Tests, Comparison)
{
    Vector4f vec1(1, 2, 3, 2);
    Vector4f vec2(3, 4, 5, 6);
    Vector4f vec3(1, 2, 3, 2);

    EXPECT_TRUE(vec1 == vec3);
    EXPECT_TRUE(vec1 != vec2);
}

TEST(Vector4Tests, Addition)
{
    Vector4f vec1(1, 2, 3, 4);
    Vector4f vec2(3, 4, 5, 6);

    Vector4f vec3 = vec1 + vec2;
    EXPECT_FLOAT_EQ(vec3.X, 4.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 6.0f);
    EXPECT_FLOAT_EQ(vec3.Z, 8.0f);
    EXPECT_FLOAT_EQ(vec3.W, 10.0f);

    vec3 += vec1;
    EXPECT_FLOAT_EQ(vec3.X, 5.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 8.0f);
    EXPECT_FLOAT_EQ(vec3.Z, 11.0f);
    EXPECT_FLOAT_EQ(vec3.W, 14.0f);
}

TEST(Vector4Tests, Subtraction)
{
    Vector4f vec1(1, 2, 3, 4);
    Vector4f vec2(3, 4, 5, 6);

    Vector4f vec3 = vec2 - vec1;
    EXPECT_FLOAT_EQ(vec3.X, 2.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 2.0f);
    EXPECT_FLOAT_EQ(vec3.Z, 2.0f);
    EXPECT_FLOAT_EQ(vec3.W, 2.0f);

    vec3 -= vec1;
    EXPECT_FLOAT_EQ(vec3.X, 1.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 0.0f);
    EXPECT_FLOAT_EQ(vec3.Z, -1.0f);
    EXPECT_FLOAT_EQ(vec3.W, -2.0f);
}

TEST(Vector4Tests, MultiplicationScalar)
{
    Vector4f vec1(1, 2, 3, 4);

    Vector4f vec2 = vec1 * 5.0f;

    EXPECT_FLOAT_EQ(vec2.X, 5.0f);
    EXPECT_FLOAT_EQ(vec2.Y, 10.0f);
    EXPECT_FLOAT_EQ(vec2.Z, 15.0f);
    EXPECT_FLOAT_EQ(vec2.W, 20.0f);

    vec2 *= 2.0f;
    EXPECT_FLOAT_EQ(vec2.X, 10.0f);
    EXPECT_FLOAT_EQ(vec2.Y, 20.0f);
    EXPECT_FLOAT_EQ(vec2.Z, 30.0f);
    EXPECT_FLOAT_EQ(vec2.W, 40.0f);

    Vector4f vec3 = 2.0f * vec2;
    EXPECT_FLOAT_EQ(vec3.X, 20.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 40.0f);
    EXPECT_FLOAT_EQ(vec3.Z, 60.0f);
    EXPECT_FLOAT_EQ(vec3.W, 80.0f);
}

TEST(Vector4Tests, Multiplication)
{
    Vector4f vec1(1, 2, 3, 4);
    Vector4f vec2(2, 3, 4, 5);

    Vector4f vec3 = vec1 * vec2;
    EXPECT_FLOAT_EQ(vec3.X, 2.0f);
    EXPECT_FLOAT_EQ(vec3.Y, 6.0f);
    EXPECT_FLOAT_EQ(vec3.Z, 12.0f);
    EXPECT_FLOAT_EQ(vec3.W, 20.0f);

    vec2 *= vec1;
    EXPECT_FLOAT_EQ(vec2.X, 2.0f);
    EXPECT_FLOAT_EQ(vec2.Y, 6.0f);
    EXPECT_FLOAT_EQ(vec2.Z, 12.0f);
    EXPECT_FLOAT_EQ(vec2.W, 20.0f);
}

TEST(Vector4Tests, DivisionScalar)
{
    Vector4f vec1(20.0f, 40.0f, 60.0f, 80);

    Vector4f vec2 = vec1 / 2.0f;

    EXPECT_FLOAT_EQ(vec2.X, 10.0f);
    EXPECT_FLOAT_EQ(vec2.Y, 20.0f);
    EXPECT_FLOAT_EQ(vec2.Z, 30.0f);
    EXPECT_FLOAT_EQ(vec2.W, 40.0f);

    vec2 /= 2.0f;
    EXPECT_FLOAT_EQ(vec2.X, 5.0f);
    EXPECT_FLOAT_EQ(vec2.Y, 10.0f);
    EXPECT_FLOAT_EQ(vec2.Z, 15.0f);
    EXPECT_FLOAT_EQ(vec2.W, 20.0f);
}

TEST(Vector4Tests, Negation)
{
    Vector4f vec(5, -10, -15, 20);
    Vector4f neg = -vec;

    EXPECT_FLOAT_EQ(neg.X, -5.0f);
    EXPECT_FLOAT_EQ(neg.Y, 10.0f);
    EXPECT_FLOAT_EQ(neg.Z, 15.0f);
    EXPECT_FLOAT_EQ(neg.W, -20.0f);
}

TEST(Vector4Tests, Abs)
{
    Vector4f vec(5, -10, -15, 20);
    Vector4f a = vec.Abs();

    EXPECT_FLOAT_EQ(a.X, 5.0f);
    EXPECT_FLOAT_EQ(a.Y, 10.0f);
    EXPECT_FLOAT_EQ(a.Z, 15.0f);
    EXPECT_FLOAT_EQ(a.W, 20.0f);
}

TEST(Vector4Tests, Length)
{
    Vector4f v1(3, 4, 5, 6);

    EXPECT_FLOAT_EQ(v1.Length(), std::sqrt(86));
    EXPECT_FLOAT_EQ(v1.LengthSquared(), 86);
}

TEST(Vector4Tests, Dot)
{
    Vector4f vec1(1, 2, 3, 4);
    Vector4f vec2(3, 4, 5, 6);
    Vector4f vec3(-3, -4, -5, -6);

    EXPECT_FLOAT_EQ(Dot(vec1, vec2), 50.0f);
    EXPECT_FLOAT_EQ(AbsDot(vec1, vec3), 50.0f);
}

TEST(Vector4Tests, Normalize)
{
    Vector4f vec(2, 3, 5, 6);
    Vector4f norm = Normalize(vec);
    EXPECT_FLOAT_EQ(norm.Length(), 1.0f);
}

TEST(Vector4Tests, Misc)
{
    Vector4f vec1(1, 2, 3, 4);
    Vector4f vec2(3, -2, 5, -3);
    Vector4f min = Min(vec1, vec2);
    Vector4f max = Max(vec1, vec2);

    EXPECT_FLOAT_EQ(min.X, 1.0f);
    EXPECT_FLOAT_EQ(min.Y, -2.0f);
    EXPECT_FLOAT_EQ(min.Z, 3.0f);
    EXPECT_FLOAT_EQ(min.W, -3.0f);
    EXPECT_FLOAT_EQ(max.X, 3.0f);
    EXPECT_FLOAT_EQ(max.Y, 2.0f);
    EXPECT_FLOAT_EQ(max.Z, 5.0f);
    EXPECT_FLOAT_EQ(max.W, 4.0f);

    Vector4f vec(1, 2, 3, 4);
    Vector4f perm = Permute(vec, 1, 2, 3, 0);
    EXPECT_FLOAT_EQ(perm.X, 2.0f);
    EXPECT_FLOAT_EQ(perm.Y, 3.0f);
    EXPECT_FLOAT_EQ(perm.Z, 4.0f);
    EXPECT_FLOAT_EQ(perm.W, 1.0f);
}

TEST(Vector4Tests, Clamp)
{
    Vector4f v1(2, -5, 10, -4);
    Vector4f v2 = math::Clamp(v1, 0, 5);
    EXPECT_FLOAT_EQ(v2.X, 2);
    EXPECT_FLOAT_EQ(v2.Y, 0);
    EXPECT_FLOAT_EQ(v2.Z, 5);
    EXPECT_FLOAT_EQ(v2.W, 0);
}
