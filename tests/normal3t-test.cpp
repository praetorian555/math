#include <gtest/gtest.h>

#include "Math/normal3.h"

using Normal3f = Math::Normal3<float>;
using Normal3d = Math::Normal3<double>;
using Vec3f = Math::Vector3<float>;
using Vec3d = Math::Vector3<double>;

TEST(Normal3Tests, Construction)
{
    {
        const Normal3f vec1(1, 2, 3);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);
        EXPECT_EQ(vec1.z, 3);

        const Normal3f vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
        EXPECT_EQ(vec2.z, 1);

        const Normal3f vec3(Vec3f(1, 2, 3));
        EXPECT_EQ(vec3.x, 1);
        EXPECT_EQ(vec3.y, 2);
        EXPECT_EQ(vec3.z, 3);
    }
    {
        const Normal3d vec1(1, 2, 3);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);
        EXPECT_EQ(vec1.z, 3);

        const Normal3d vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
        EXPECT_EQ(vec2.z, 1);

        const Normal3d vec3(Vec3d(1, 2, 3));
        EXPECT_EQ(vec3.x, 1);
        EXPECT_EQ(vec3.y, 2);
        EXPECT_EQ(vec3.z, 3);
    }
}

TEST(Normal3Tests, ContainsNonFinite)
{
    {
        const Normal3f vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Normal3f vec2(1, 2, std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Normal3f vec3(1, 2, -std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Normal3f vec4(1, 2, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Normal3f vec5(1, 2, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Normal3d vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Normal3d vec2(1, 2, std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Normal3d vec3(1, 2, -std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Normal3d vec4(1, 2, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Normal3d vec5(1, 2, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Normal3d vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNonFinite(vec1));
    }
}

TEST(Normal3Tests, ContainsNaN)
{
    {
        const Normal3f vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Normal3f vec2(1, 2, std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Normal3f vec3(1, 2, -std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Normal3f vec4(1, 2, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Normal3f vec5(1, 2, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Normal3d vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Normal3d vec2(1, 2, std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Normal3d vec3(1, 2, -std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Normal3d vec4(1, 2, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Normal3d vec5(1, 2, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Normal3d vec1(1, 2, 4);
        EXPECT_FALSE(ContainsNaN(vec1));
    }
}

TEST(Normal3Tests, Comparisons)
{
    {
        const Normal3f vec1(1, 2, 3);
        const Normal3f vec2(1, 2, 3);
        const Normal3f vec3(1, 2, 4);
        const Normal3f vec4(1, 2, 4);
        const Normal3f vec5(1, 3, 3);
        const Normal3f vec6(2, 2, 3);

        EXPECT_TRUE(vec1 == vec2);
        EXPECT_FALSE(vec1 == vec3);
        EXPECT_FALSE(vec1 == vec4);
        EXPECT_FALSE(vec1 == vec5);
        EXPECT_FALSE(vec1 == vec6);

        EXPECT_FALSE(vec1 != vec2);
        EXPECT_TRUE(vec1 != vec3);
        EXPECT_TRUE(vec1 != vec4);
        EXPECT_TRUE(vec1 != vec5);
        EXPECT_TRUE(vec1 != vec6);
    }
    {
        const Normal3d vec1(1, 2, 3);
        const Normal3d vec2(1, 2, 3);
        const Normal3d vec3(1, 2, 4);
        const Normal3d vec4(1, 2, 4);
        const Normal3d vec5(1, 3, 3);
        const Normal3d vec6(2, 2, 3);

        EXPECT_TRUE(vec1 == vec2);
        EXPECT_FALSE(vec1 == vec3);
        EXPECT_FALSE(vec1 == vec4);
        EXPECT_FALSE(vec1 == vec5);
        EXPECT_FALSE(vec1 == vec6);

        EXPECT_FALSE(vec1 != vec2);
        EXPECT_TRUE(vec1 != vec3);
        EXPECT_TRUE(vec1 != vec4);
        EXPECT_TRUE(vec1 != vec5);
        EXPECT_TRUE(vec1 != vec6);
    }
}

TEST(Normal3Tests, Addition)
{
    {
        const Normal3f vec1(1, 2, 3);
        const Normal3f vec2(3, 4, 5);

        Normal3f vec3 = vec1 + vec2;
        EXPECT_FLOAT_EQ(vec3.x, 4.0f);
        EXPECT_FLOAT_EQ(vec3.y, 6.0f);
        EXPECT_FLOAT_EQ(vec3.z, 8.0f);

        vec3 += vec1;
        EXPECT_FLOAT_EQ(vec3.x, 5.0f);
        EXPECT_FLOAT_EQ(vec3.y, 8.0f);
        EXPECT_FLOAT_EQ(vec3.z, 11.0f);
    }
    {
        const Normal3d vec1(1, 2, 3);
        const Normal3d vec2(3, 4, 5);

        Normal3d vec3 = vec1 + vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 4.0);
        EXPECT_DOUBLE_EQ(vec3.y, 6.0);
        EXPECT_DOUBLE_EQ(vec3.z, 8.0);

        vec3 += vec1;
        EXPECT_DOUBLE_EQ(vec3.x, 5.0);
        EXPECT_DOUBLE_EQ(vec3.y, 8.0);
        EXPECT_DOUBLE_EQ(vec3.z, 11.0);
    }
}

TEST(Normal3Tests, Subtraction)
{
    {
        const Normal3f vec1(1, 2, 3);
        const Normal3f vec2(3, 4, 5);

        Normal3f vec3 = vec2 - vec1;
        EXPECT_FLOAT_EQ(vec3.x, 2.0f);
        EXPECT_FLOAT_EQ(vec3.y, 2.0f);
        EXPECT_FLOAT_EQ(vec3.z, 2.0f);

        vec3 -= vec1;
        EXPECT_FLOAT_EQ(vec3.x, 1.0f);
        EXPECT_FLOAT_EQ(vec3.y, 0.0f);
        EXPECT_FLOAT_EQ(vec3.z, -1.0f);
    }
    {
        const Normal3d vec1(1, 2, 3);
        const Normal3d vec2(3, 4, 5);

        Normal3d vec3 = vec2 - vec1;
        EXPECT_DOUBLE_EQ(vec3.x, 2.0);
        EXPECT_DOUBLE_EQ(vec3.y, 2.0);
        EXPECT_DOUBLE_EQ(vec3.z, 2.0);

        vec3 -= vec1;
        EXPECT_DOUBLE_EQ(vec3.x, 1.0);
        EXPECT_DOUBLE_EQ(vec3.y, 0.0);
        EXPECT_DOUBLE_EQ(vec3.z, -1.0);
    }
}

TEST(Normal3Tests, MultiplicationScalar)
{
    {
        const Normal3f vec1(1, 2, 3);

        Normal3f vec2 = vec1 * 5.0f;

        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);
        EXPECT_FLOAT_EQ(vec2.z, 15.0f);

        vec2 *= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);
        EXPECT_FLOAT_EQ(vec2.z, 30.0f);

        const Normal3f vec3 = 2.0f * vec2;
        EXPECT_FLOAT_EQ(vec3.x, 20.0f);
        EXPECT_FLOAT_EQ(vec3.y, 40.0f);
        EXPECT_FLOAT_EQ(vec3.z, 60.0f);
    }
    {
        const Normal3d vec1(1, 2, 3);

        Normal3d vec2 = vec1 * 5.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 15.0f);

        vec2 *= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 30.0f);

        const Normal3d vec3 = 2.0f * vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 20.0f);
        EXPECT_DOUBLE_EQ(vec3.y, 40.0f);
        EXPECT_DOUBLE_EQ(vec3.z, 60.0f);
    }
}

TEST(Normal3Tests, Multiplication)
{
    {
        const Normal3f vec1(1, 2, 3);
        Normal3f vec2(2, 3, 4);

        const Normal3f vec3 = vec1 * vec2;
        EXPECT_FLOAT_EQ(vec3.x, 2.0f);
        EXPECT_FLOAT_EQ(vec3.y, 6.0f);
        EXPECT_FLOAT_EQ(vec3.z, 12.0f);

        vec2 *= vec1;
        EXPECT_FLOAT_EQ(vec2.x, 2.0f);
        EXPECT_FLOAT_EQ(vec2.y, 6.0f);
        EXPECT_FLOAT_EQ(vec2.z, 12.0f);
    }
    {
        const Normal3d vec1(1, 2, 3);
        Normal3d vec2(2, 3, 4);

        const Normal3d vec3 = vec1 * vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 2.0f);
        EXPECT_DOUBLE_EQ(vec3.y, 6.0f);
        EXPECT_DOUBLE_EQ(vec3.z, 12.0f);

        vec2 *= vec1;
        EXPECT_DOUBLE_EQ(vec2.x, 2.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 6.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 12.0f);
    }
}

TEST(Normal3Tests, DivisionScalar)
{
    {
        const Normal3f vec1(20.0f, 40.0f, 60.0f);

        Normal3f vec2 = vec1 / 2.0f;

        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);
        EXPECT_FLOAT_EQ(vec2.z, 30.0f);

        vec2 /= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);
        EXPECT_FLOAT_EQ(vec2.z, 15.0f);
    }
    {
        const Normal3d vec1(20.0f, 40.0f, 60.0f);

        Normal3d vec2 = vec1 / 2.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 30.0f);

        vec2 /= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 15.0f);
    }
}

TEST(Normal3Tests, Negation)
{
    {
        const Normal3f vec(5, -10, -15);
        const Normal3f neg = -vec;

        EXPECT_FLOAT_EQ(neg.x, -5.0f);
        EXPECT_FLOAT_EQ(neg.y, 10.0f);
        EXPECT_FLOAT_EQ(neg.z, 15.0f);
    }
    {
        const Normal3d vec(5, -10, -15);
        const Normal3d neg = -vec;

        EXPECT_DOUBLE_EQ(neg.x, -5.0f);
        EXPECT_DOUBLE_EQ(neg.y, 10.0f);
        EXPECT_DOUBLE_EQ(neg.z, 15.0f);
    }
}

TEST(Normal3Tests, Abs)
{
    {
        const Normal3f vec(5, -10, -15);
        const Normal3f a = Math::Abs(vec);

        EXPECT_FLOAT_EQ(a.x, 5.0f);
        EXPECT_FLOAT_EQ(a.y, 10.0f);
        EXPECT_FLOAT_EQ(a.z, 15.0f);
    }
    {
        const Normal3d vec(5, -10, -15);
        const Normal3d a = Math::Abs(vec);

        EXPECT_DOUBLE_EQ(a.x, 5.0f);
        EXPECT_DOUBLE_EQ(a.y, 10.0f);
        EXPECT_DOUBLE_EQ(a.z, 15.0f);
    }
}

TEST(Normal3Tests, Length)
{
    {
        const Normal3f v1(3, 4, 5);

        EXPECT_DOUBLE_EQ(Math::Length(v1), std::sqrt(50.0));
        EXPECT_FLOAT_EQ(Math::LengthSquared(v1), 50);
    }
    {
        const Normal3d v1(3, 4, 5);

        EXPECT_DOUBLE_EQ(Math::Length(v1), std::sqrt(50.0));
        EXPECT_DOUBLE_EQ(Math::LengthSquared(v1), 50);
    }
}

TEST(Normal3Tests, Dot)
{
    {
        const Normal3f vec1(1, 2, 3);
        const Normal3f vec2(3, 4, 5);
        const Normal3f vec3(-3, -4, -5);
        const Vec3f vec4(3, 4, 5);
        const Vec3f vec5(-3, -4, -5);

        EXPECT_FLOAT_EQ(Dot(vec1, vec2), 26.0f);
        EXPECT_FLOAT_EQ(Dot(vec1, vec4), 26.0f);
        EXPECT_FLOAT_EQ(Dot(vec4, vec1), 26.0f);
        EXPECT_FLOAT_EQ(AbsDot(vec1, vec3), 26.0f);
        EXPECT_FLOAT_EQ(AbsDot(vec1, vec5), 26.0f);
        EXPECT_FLOAT_EQ(AbsDot(vec5, vec1), 26.0f);
    }
    {
        const Normal3d vec1(1, 2, 3);
        const Normal3d vec2(3, 4, 5);
        const Normal3d vec3(-3, -4, -5);
        const Vec3d vec4(3, 4, 5);
        const Vec3d vec5(-3, -4, -5);

        EXPECT_DOUBLE_EQ(Dot(vec1, vec2), 26.0f);
        EXPECT_DOUBLE_EQ(Dot(vec1, vec4), 26.0f);
        EXPECT_DOUBLE_EQ(Dot(vec4, vec1), 26.0f);
        EXPECT_DOUBLE_EQ(AbsDot(vec1, vec3), 26.0f);
        EXPECT_DOUBLE_EQ(AbsDot(vec1, vec5), 26.0f);
        EXPECT_DOUBLE_EQ(AbsDot(vec5, vec1), 26.0f);
    }
}

TEST(Normal3Tests, Normalize)
{
    {
        const Normal3f vec(2, 3, 5);
        const Normal3f norm = Normalize(vec);
        EXPECT_TRUE(Math::IsEqual(Math::Length(norm), 1.0, 0.00001));
    }
    {
        const Normal3d vec(2, 3, 5);
        const Normal3d norm = Normalize(vec);
        EXPECT_TRUE(Math::IsEqual(Math::Length(norm), 1.0, 0.00001));
    }
}

TEST(Normal3Tests, Misc)
{
    {
        const Normal3f vec1(1, 2, 3);
        const Normal3f vec2(3, -2, 5);
        const Normal3f min = Min(vec1, vec2);
        const Normal3f max = Max(vec1, vec2);

        EXPECT_FLOAT_EQ(min.x, 1.0f);
        EXPECT_FLOAT_EQ(min.y, -2.0f);
        EXPECT_FLOAT_EQ(min.z, 3.0f);
        EXPECT_FLOAT_EQ(max.x, 3.0f);
        EXPECT_FLOAT_EQ(max.y, 2.0f);
        EXPECT_FLOAT_EQ(max.z, 5.0f);

        const Normal3f vec(1, 2, 3);
        const Normal3f perm = Math::Permute(vec, 1, 2, 0);
        EXPECT_FLOAT_EQ(perm.x, 2.0f);
        EXPECT_FLOAT_EQ(perm.y, 3.0f);
        EXPECT_FLOAT_EQ(perm.z, 1.0f);
    }
    {
        const Normal3d vec1(1, 2, 3);
        const Normal3d vec2(3, -2, 5);
        const Normal3d min = Min(vec1, vec2);
        const Normal3d max = Max(vec1, vec2);

        EXPECT_DOUBLE_EQ(min.x, 1.0f);
        EXPECT_DOUBLE_EQ(min.y, -2.0f);
        EXPECT_DOUBLE_EQ(min.z, 3.0f);
        EXPECT_DOUBLE_EQ(max.x, 3.0f);
        EXPECT_DOUBLE_EQ(max.y, 2.0f);
        EXPECT_DOUBLE_EQ(max.z, 5.0f);

        const Normal3f vec(1, 2, 3);
        const Normal3f perm = Math::Permute(vec, 1, 2, 0);
        EXPECT_DOUBLE_EQ(perm.x, 2.0f);
        EXPECT_DOUBLE_EQ(perm.y, 3.0f);
        EXPECT_DOUBLE_EQ(perm.z, 1.0f);
    }
}

TEST(Normal3Tests, IsEqual)
{
    {
        const Normal3f v1(1, 2, 3);
        const Normal3f v2(2, 3, 4);
        const Normal3f v3(0, 1, 2);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5f));
    }
    {
        const Normal3d v1(1, 2, 3);
        const Normal3d v2(2, 3, 4);
        const Normal3d v3(0, 1, 2);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5));
    }
}

TEST(Normal3Tests, MinAndMaxComponent)
{
    {
        const Normal3f v(1, 2, 3);
        EXPECT_FLOAT_EQ(Math::MinComponent(v), 1);
        EXPECT_FLOAT_EQ(Math::MaxComponent(v), 3);
    }
    {
        const Normal3d v(1, 2, 3);
        EXPECT_DOUBLE_EQ(Math::MinComponent(v), 1);
        EXPECT_DOUBLE_EQ(Math::MaxComponent(v), 3);
    }
}

TEST(Normal3Tests, MinAndMaxDimension)
{
    {
        const Normal3f v(1, 2, 3);
        EXPECT_EQ(Math::MinDimension(v), 0);
        EXPECT_EQ(Math::MaxDimension(v), 2);
    }
    {
        const Normal3d v(1, 2, 3);
        EXPECT_EQ(Math::MinDimension(v), 0);
        EXPECT_EQ(Math::MaxDimension(v), 2);
    }
}

TEST(Normal3Tests, Faceforward)
{
    {
        const Normal3f n1(1, 2, 3);
        const Vec3f v1(1, 2, 5);
        const Vec3f v2(-1, -2, -5);

        EXPECT_TRUE(FaceForward(n1, v1) == n1);
        EXPECT_TRUE(FaceForward(n1, v2) == -n1);
    }
    {
        const Normal3d n1(1, 2, 3);
        const Vec3d v1(1, 2, 5);
        const Vec3d v2(-1, -2, -5);

        EXPECT_TRUE(FaceForward(n1, v1) == n1);
        EXPECT_TRUE(FaceForward(n1, v2) == -n1);
    }
}
