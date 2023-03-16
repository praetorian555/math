#include "math/normal3.h"
#include "math/point3.h"
#include "math/vector2.h"
#include "math/vector3.h"

#include "realexpect.h"

using Vector3f = math::Vector3;
using Vector2f = math::Vector2;
using Point3f = math::Point3;
using Normal3f = math::Normal3;

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
        EXPECT_REAL_EQ(vec.R, 10.0f);
        EXPECT_REAL_EQ(vec.G, 15.0f);
        EXPECT_REAL_EQ(vec.B, 20.0f);
    }

    {
        Vector3f vec;
        vec.X = 5.0f;
        EXPECT_REAL_EQ(vec.Data[0], 5.0f);
        vec.Y = 10.0f;
        EXPECT_REAL_EQ(vec.Data[1], 10.0f);
        vec.Z = 50.0f;
        EXPECT_REAL_EQ(vec.Data[2], 50.0f);
        vec.Set(15.0f, 0);
        EXPECT_REAL_EQ(vec[0], 15.0f);
        vec.Set(20.0f, 1);
        EXPECT_REAL_EQ(vec[1], 20.0f);
        vec.Set(55.0f, 2);
        EXPECT_REAL_EQ(vec[2], 55.0f);
    }

    {
        Vector2f vec2(10, 15);
        Vector3f vec3(vec2, 20);
        EXPECT_REAL_EQ(vec3.X, 10);
        EXPECT_REAL_EQ(vec3.Y, 15);
        EXPECT_REAL_EQ(vec3.Z, 20);
    }

    {
        Point3f p(10, 15, 20);
        Vector3f v(p);
        EXPECT_REAL_EQ(v.X, 10);
        EXPECT_REAL_EQ(v.Y, 15);
        EXPECT_REAL_EQ(v.Z, 20);
    }

    {
        Normal3f n(10, 15, 20);
        Vector3f v(n);
        EXPECT_REAL_EQ(v.X, 10);
        EXPECT_REAL_EQ(v.Y, 15);
        EXPECT_REAL_EQ(v.Z, 20);
    }
}

TEST(Vector3Tests, ToVector2)
{
    Vector3f v(10, 15, 20);

    Vector2f v1 = v.XY();
    Vector2f v2 = v.XZ();
    Vector2f v3 = v.YZ();
    EXPECT_REAL_EQ(v1.X, 10);
    EXPECT_REAL_EQ(v1.Y, 15);
    EXPECT_REAL_EQ(v2.X, 10);
    EXPECT_REAL_EQ(v2.Y, 20);
    EXPECT_REAL_EQ(v3.X, 15);
    EXPECT_REAL_EQ(v3.Y, 20);
}

TEST(Vector3Tests, Nans)
{
    Vector3f v1(nanf(""), 10, 15);
    EXPECT_TRUE(v1.HasNaNs());

    Vector3f v2(15, nanf(""), 10);
    EXPECT_TRUE(v2.HasNaNs());

    Vector3f v3(15, 10, nanf(""));
    EXPECT_TRUE(v3.HasNaNs());
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
    EXPECT_REAL_EQ(vec3.X, 4.0f);
    EXPECT_REAL_EQ(vec3.Y, 6.0f);
    EXPECT_REAL_EQ(vec3.Z, 8.0f);

    vec3 += vec1;
    EXPECT_REAL_EQ(vec3.X, 5.0f);
    EXPECT_REAL_EQ(vec3.Y, 8.0f);
    EXPECT_REAL_EQ(vec3.Z, 11.0f);
}

TEST(Vector3Tests, Subtraction)
{
    Vector3f vec1(1, 2, 3);
    Vector3f vec2(3, 4, 5);

    Vector3f vec3 = vec2 - vec1;
    EXPECT_REAL_EQ(vec3.X, 2.0f);
    EXPECT_REAL_EQ(vec3.Y, 2.0f);
    EXPECT_REAL_EQ(vec3.Z, 2.0f);

    vec3 -= vec1;
    EXPECT_REAL_EQ(vec3.X, 1.0f);
    EXPECT_REAL_EQ(vec3.Y, 0.0f);
    EXPECT_REAL_EQ(vec3.Z, -1.0f);
}

TEST(Vector3Tests, MultiplicationScalar)
{
    Vector3f vec1(1, 2, 3);

    Vector3f vec2 = vec1 * 5.0f;

    EXPECT_REAL_EQ(vec2.X, 5.0f);
    EXPECT_REAL_EQ(vec2.Y, 10.0f);
    EXPECT_REAL_EQ(vec2.Z, 15.0f);

    vec2 *= 2.0f;
    EXPECT_REAL_EQ(vec2.X, 10.0f);
    EXPECT_REAL_EQ(vec2.Y, 20.0f);
    EXPECT_REAL_EQ(vec2.Z, 30.0f);

    Vector3f vec3 = 2.0f * vec2;
    EXPECT_REAL_EQ(vec3.X, 20.0f);
    EXPECT_REAL_EQ(vec3.Y, 40.0f);
    EXPECT_REAL_EQ(vec3.Z, 60.0f);
}

TEST(Vector3Tests, Multiplication)
{
    Vector3f vec1(1, 2, 3);
    Vector3f vec2(2, 3, 4);

    Vector3f vec3 = vec1 * vec2;
    EXPECT_REAL_EQ(vec3.X, 2.0f);
    EXPECT_REAL_EQ(vec3.Y, 6.0f);
    EXPECT_REAL_EQ(vec3.Z, 12.0f);

    vec2 *= vec1;
    EXPECT_REAL_EQ(vec2.X, 2.0f);
    EXPECT_REAL_EQ(vec2.Y, 6.0f);
    EXPECT_REAL_EQ(vec2.Z, 12.0f);
}

TEST(Vector3Tests, DivisionScalar)
{
    Vector3f vec1(20.0f, 40.0f, 60.0f);

    Vector3f vec2 = vec1 / 2.0f;

    EXPECT_REAL_EQ(vec2.X, 10.0f);
    EXPECT_REAL_EQ(vec2.Y, 20.0f);
    EXPECT_REAL_EQ(vec2.Z, 30.0f);

    vec2 /= 2.0f;
    EXPECT_REAL_EQ(vec2.X, 5.0f);
    EXPECT_REAL_EQ(vec2.Y, 10.0f);
    EXPECT_REAL_EQ(vec2.Z, 15.0f);
}

TEST(Vector3Tests, Negation)
{
    Vector3f vec(5, -10, -15);
    Vector3f neg = -vec;

    EXPECT_REAL_EQ(neg.X, -5.0f);
    EXPECT_REAL_EQ(neg.Y, 10.0f);
    EXPECT_REAL_EQ(neg.Z, 15.0f);
}

TEST(Vector3Tests, Abs)
{
    Vector3f vec(5, -10, -15);
    Vector3f a = vec.Abs();

    EXPECT_REAL_EQ(a.X, 5.0f);
    EXPECT_REAL_EQ(a.Y, 10.0f);
    EXPECT_REAL_EQ(a.Z, 15.0f);
}

TEST(Vector3Tests, Length)
{
    Vector3f v1(3, 4, 5);

    EXPECT_REAL_EQ(v1.Length(), math::Sqrt(50));
    EXPECT_REAL_EQ(v1.LengthSquared(), 50);
}

TEST(Vector3Tests, Dot)
{
    Vector3f vec1(1, 2, 3);
    Vector3f vec2(3, 4, 5);
    Vector3f vec3(-3, -4, -5);

    EXPECT_REAL_EQ(Dot(vec1, vec2), 26.0f);
    EXPECT_REAL_EQ(AbsDot(vec1, vec3), 26.0f);
}

TEST(Vector3Tests, Cross)
{
    Vector3f x(1, 0, 0);
    Vector3f y(0, 1, 0);
    Vector3f z(0, 0, 1);

    Vector3f c = Cross(x, y);
    EXPECT_TRUE(c == z);
}

TEST(Vector2Tests, Cross2D)
{
    Vector3f vec1(0, 1, 1);
    Vector3f vec2(1, 0, 2);

    EXPECT_EQ(-1, Cross2D(vec1, vec2));
}

TEST(Vector3Tests, Normalize)
{
    Vector3f vec(2, 3, 5);
    Vector3f norm = Normalize(vec);
    EXPECT_REAL_EQ(norm.Length(), 1.0f);
}

TEST(Vector3Tests, Misc)
{
    Vector3f vec(1, 2, 3);

    EXPECT_REAL_EQ(MinComponent(vec), 1.0f);
    EXPECT_REAL_EQ(MaxComponent(vec), 3.0f);
    EXPECT_EQ(MaxDimension(vec), 2);

    Vector3f vec1(1, 2, 3);
    Vector3f vec2(3, -2, 5);
    Vector3f min = Min(vec1, vec2);
    Vector3f max = Max(vec1, vec2);

    EXPECT_REAL_EQ(min.X, 1.0f);
    EXPECT_REAL_EQ(min.Y, -2.0f);
    EXPECT_REAL_EQ(min.Z, 3.0f);
    EXPECT_REAL_EQ(max.X, 3.0f);
    EXPECT_REAL_EQ(max.Y, 2.0f);
    EXPECT_REAL_EQ(max.Z, 5.0f);

    Vector3f perm = Permute(vec, 1, 2, 0);
    EXPECT_REAL_EQ(perm.X, 2.0f);
    EXPECT_REAL_EQ(perm.Y, 3.0f);
    EXPECT_REAL_EQ(perm.Z, 1.0f);
}

TEST(Vector3Tests, Reflection)
{
    Vector3f Incidence(1, 0, 0);
    Vector3f Normal(0, 1, 0);
    Vector3f Reflection = math::Reflect(Incidence, Normal);
    EXPECT_REAL_EQ(Reflection.X, -1.0f);
    EXPECT_REAL_EQ(Reflection.Y, 0.0f);
    EXPECT_REAL_EQ(Reflection.Z, 0.0f);
}

TEST(Vector3Tests, Clamp)
{
    Vector3f v1(2, -5, 10);
    Vector3f v2 = math::Clamp(v1, 0, 5);
    EXPECT_REAL_EQ(v2.X, 2);
    EXPECT_REAL_EQ(v2.Y, 0);
    EXPECT_REAL_EQ(v2.Z, 5);
}

TEST(Vector3Tests, IsEqual)
{
    Vector3f v1(1, 2, 3);
    Vector3f v2(2, 3, 4);
    Vector3f v3(0, 1, 2);

    EXPECT_TRUE(math::IsEqual(v1, v2, 1));
    EXPECT_TRUE(math::IsEqual(v1, v2, 2));
    EXPECT_FALSE(math::IsEqual(v1, v2, MATH_REALC(0.5)));
    EXPECT_TRUE(math::IsEqual(v1, v3, 1));
    EXPECT_TRUE(math::IsEqual(v1, v3, 2));
    EXPECT_FALSE(math::IsEqual(v1, v3, MATH_REALC(0.5)));
}
