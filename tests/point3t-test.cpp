#include <gtest/gtest.h>

#include "math/point3.h"

using Point3f = Math::Point3<float>;
using Point3d = Math::Point3<double>;
using Point3i = Math::Point3<int>;
using Vec3f = Math::Vector3<float>;
using Vec3d = Math::Vector3<double>;
using Vec3i = Math::Vector3<int>;

TEST(Point3Tests, Construction)
{
    {
        const Point3f vec1(1, 2, 3);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);
        EXPECT_EQ(vec1.z, 3);

        const Point3f vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
        EXPECT_EQ(vec2.z, 1);
    }
    {
        const Point3d vec1(1, 2, 3);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);
        EXPECT_EQ(vec1.z, 3);

        const Point3d vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
        EXPECT_EQ(vec2.z, 1);
    }
    {
        const Point3i vec1(1, 2, 3);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);
        EXPECT_EQ(vec1.z, 3);

        const Point3i vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
        EXPECT_EQ(vec2.z, 1);
    }
}

TEST(Point3Tests, AccessOperators)
{
    {
        Point3f p1(1, 2, 3);
        EXPECT_FLOAT_EQ(p1[0], 1);
        EXPECT_FLOAT_EQ(p1[1], 2);
        EXPECT_FLOAT_EQ(p1[2], 3);

        p1[0] = 5;
        p1[1] = 6;
        p1[2] = 7;
        EXPECT_FLOAT_EQ(p1[0], 5);
        EXPECT_FLOAT_EQ(p1[1], 6);
        EXPECT_FLOAT_EQ(p1[2], 7);
    }
    {
        Point3d p1(1, 2, 3);
        EXPECT_DOUBLE_EQ(p1[0], 1);
        EXPECT_DOUBLE_EQ(p1[1], 2);
        EXPECT_DOUBLE_EQ(p1[2], 3);

        p1[0] = 5;
        p1[1] = 6;
        p1[2] = 7;
        EXPECT_DOUBLE_EQ(p1[0], 5);
        EXPECT_DOUBLE_EQ(p1[1], 6);
        EXPECT_DOUBLE_EQ(p1[2], 7);
    }
    {
        Point3i p1(1, 2, 3);
        EXPECT_EQ(p1[0], 1);
        EXPECT_EQ(p1[1], 2);
        EXPECT_EQ(p1[2], 3);

        p1[0] = 5;
        p1[1] = 6;
        p1[2] = 7;
        EXPECT_EQ(p1[0], 5);
        EXPECT_EQ(p1[1], 6);
        EXPECT_EQ(p1[2], 7);
    }
}

TEST(Point3Tests, ContainsNonFinite)
{
    {
        const Point3f vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Point3f vec2(1, 2, std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Point3f vec3(1, 2, -std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Point3f vec4(1, 2, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Point3f vec5(1, 2, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Point3d vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Point3d vec2(1, 2, std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Point3d vec3(1, 2, -std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Point3d vec4(1, 2, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Point3d vec5(1, 2, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Point3d vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNonFinite(vec1));
    }
}

TEST(Point3Tests, ContainsNaN)
{
    {
        const Point3f vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Point3f vec2(1, 2, std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Point3f vec3(1, 2, -std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Point3f vec4(1, 2, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Point3f vec5(1, 2, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Point3d vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Point3d vec2(1, 2, std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Point3d vec3(1, 2, -std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Point3d vec4(1, 2, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Point3d vec5(1, 2, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Point3d vec1(1, 2, 3);
        EXPECT_FALSE(ContainsNaN(vec1));
    }
}

TEST(Point3Tests, Comparisons)
{
    {
        const Point3f vec1(1, 2, 4);
        const Point3f vec2(1, 2, 4);
        const Point3f vec3(1, 2, 5);
        const Point3f vec4(1, 2, 4);
        const Point3f vec5(1, 3, 4);
        const Point3f vec6(2, 2, 4);

        EXPECT_TRUE(vec1 == vec2);
        EXPECT_FALSE(vec1 == vec3);
        EXPECT_FALSE(vec1 != vec4);
        EXPECT_FALSE(vec1 == vec5);
        EXPECT_FALSE(vec1 == vec6);

        EXPECT_FALSE(vec1 != vec2);
        EXPECT_TRUE(vec1 != vec3);
        EXPECT_TRUE(vec1 == vec4);
        EXPECT_TRUE(vec1 != vec5);
        EXPECT_TRUE(vec1 != vec6);
    }
    {
        const Point3d vec1(1, 2, 4);
        const Point3d vec2(1, 2, 4);
        const Point3d vec3(1, 2, 5);
        const Point3d vec4(1, 2, 4);
        const Point3d vec5(1, 3, 4);
        const Point3d vec6(2, 2, 4);

        EXPECT_TRUE(vec1 == vec2);
        EXPECT_FALSE(vec1 == vec3);
        EXPECT_FALSE(vec1 != vec4);
        EXPECT_FALSE(vec1 == vec5);
        EXPECT_FALSE(vec1 == vec6);

        EXPECT_FALSE(vec1 != vec2);
        EXPECT_TRUE(vec1 != vec3);
        EXPECT_TRUE(vec1 == vec4);
        EXPECT_TRUE(vec1 != vec5);
        EXPECT_TRUE(vec1 != vec6);
    }
    {
        const Point3i vec1(1, 2, 4);
        const Point3i vec2(1, 2, 4);
        const Point3i vec3(1, 2, 5);
        const Point3i vec4(1, 2, 4);
        const Point3i vec5(1, 3, 4);
        const Point3i vec6(2, 2, 4);

        EXPECT_TRUE(vec1 == vec2);
        EXPECT_FALSE(vec1 == vec3);
        EXPECT_FALSE(vec1 != vec4);
        EXPECT_FALSE(vec1 == vec5);
        EXPECT_FALSE(vec1 == vec6);

        EXPECT_FALSE(vec1 != vec2);
        EXPECT_TRUE(vec1 != vec3);
        EXPECT_TRUE(vec1 == vec4);
        EXPECT_TRUE(vec1 != vec5);
        EXPECT_TRUE(vec1 != vec6);
    }
}

TEST(Point3Tests, Addition)
{
    {
        const Point3f vec1(1, 2, 3);
        const Vec3f vec2(3, 4, 5);

        Point3f vec3 = vec1 + vec2;
        EXPECT_FLOAT_EQ(vec3.x, 4.0f);
        EXPECT_FLOAT_EQ(vec3.y, 6.0f);
        EXPECT_FLOAT_EQ(vec3.z, 8.0f);

        vec3 += vec2;
        EXPECT_FLOAT_EQ(vec3.x, 7.0f);
        EXPECT_FLOAT_EQ(vec3.y, 10.0f);
        EXPECT_FLOAT_EQ(vec3.z, 13.0f);
    }
    {
        const Point3d vec1(1, 2, 3);
        const Vec3d vec2(3, 4, 5);

        Point3d vec3 = vec1 + vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 4.0);
        EXPECT_DOUBLE_EQ(vec3.y, 6.0);
        EXPECT_DOUBLE_EQ(vec3.z, 8.0);

        vec3 += vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 7.0);
        EXPECT_DOUBLE_EQ(vec3.y, 10.0);
        EXPECT_DOUBLE_EQ(vec3.z, 13.0);
    }
    {
        const Point3i vec1(1, 2, 3);
        const Vec3i vec2(3, 4, 5);

        Point3i vec3 = vec1 + vec2;
        EXPECT_EQ(vec3.x, 4);
        EXPECT_EQ(vec3.y, 6);
        EXPECT_EQ(vec3.z, 8);

        vec3 += vec2;
        EXPECT_EQ(vec3.x, 7);
        EXPECT_EQ(vec3.y, 10);
        EXPECT_EQ(vec3.z, 13);
    }
}

TEST(Point3Tests, Subtraction)
{
    {
        const Point3f vec1(1, 2, 3);
        const Point3f vec2(3, 4, 5);
        const Vec3f vec3(2, 2, 2);

        const Point3f vec4 = vec2 - vec3;
        EXPECT_FLOAT_EQ(vec4.x, 1.0f);
        EXPECT_FLOAT_EQ(vec4.y, 2.0f);
        EXPECT_FLOAT_EQ(vec4.z, 3.0f);

        const Vec3f vec5 = vec2 - vec1;
        EXPECT_FLOAT_EQ(vec5.x, 2.0f);
        EXPECT_FLOAT_EQ(vec5.y, 2.0f);
        EXPECT_FLOAT_EQ(vec5.z, 2.0f);
    }
    {
        const Point3d vec1(1, 2, 3);
        const Point3d vec2(3, 4, 5);
        const Vec3d vec3(2, 2, 2);

        const Point3d vec4 = vec2 - vec3;
        EXPECT_DOUBLE_EQ(vec4.x, 1.0f);
        EXPECT_DOUBLE_EQ(vec4.y, 2.0f);
        EXPECT_DOUBLE_EQ(vec4.z, 3.0f);

        const Vec3d vec5 = vec2 - vec1;
        EXPECT_DOUBLE_EQ(vec5.x, 2.0f);
        EXPECT_DOUBLE_EQ(vec5.y, 2.0f);
        EXPECT_DOUBLE_EQ(vec5.z, 2.0f);
    }
    {
        const Point3i vec1(1, 2, 3);
        const Point3i vec2(3, 4, 5);
        const Vec3i vec3(2, 2, 2);

        const Point3i vec4 = vec2 - vec3;
        EXPECT_EQ(vec4.x, 1.0f);
        EXPECT_EQ(vec4.y, 2.0f);
        EXPECT_EQ(vec4.z, 3.0f);

        const Vec3i vec5 = vec2 - vec1;
        EXPECT_EQ(vec5.x, 2.0f);
        EXPECT_EQ(vec5.y, 2.0f);
        EXPECT_EQ(vec5.z, 2.0f);
    }
}

TEST(Point3Tests, Negation)
{
    {
        const Point3f vec(5, -10, -15);
        const Point3f neg = -vec;

        EXPECT_FLOAT_EQ(neg.x, -5.0f);
        EXPECT_FLOAT_EQ(neg.y, 10.0f);
        EXPECT_FLOAT_EQ(neg.z, 15.0f);
    }
    {
        const Point3d vec(5, -10, -15);
        const Point3d neg = -vec;

        EXPECT_DOUBLE_EQ(neg.x, -5.0f);
        EXPECT_DOUBLE_EQ(neg.y, 10.0f);
        EXPECT_DOUBLE_EQ(neg.z, 15.0f);
    }
    {
        const Point3i vec(5, -10, -15);
        const Point3i neg = -vec;

        EXPECT_EQ(neg.x, -5.0f);
        EXPECT_EQ(neg.y, 10.0f);
        EXPECT_EQ(neg.z, 15.0f);
    }
}

TEST(Point3Tests, MultiplicationScalar)
{
    {
        const Point3f vec1(1, 2, 3);

        Point3f vec2 = vec1 * 5.0f;

        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);
        EXPECT_FLOAT_EQ(vec2.z, 15.0f);

        vec2 *= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);
        EXPECT_FLOAT_EQ(vec2.z, 30.0f);

        const Point3f vec3 = 2.0f * vec2;
        EXPECT_FLOAT_EQ(vec3.x, 20.0f);
        EXPECT_FLOAT_EQ(vec3.y, 40.0f);
        EXPECT_FLOAT_EQ(vec3.z, 60.0f);
    }
    {
        const Point3d vec1(1, 2, 3);

        Point3d vec2 = vec1 * 5.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 15.0f);

        vec2 *= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 30.0f);

        const Point3d vec3 = 2.0f * vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 20.0f);
        EXPECT_DOUBLE_EQ(vec3.y, 40.0f);
        EXPECT_DOUBLE_EQ(vec3.z, 60.0f);
    }
    {
        const Point3i vec1(1, 2, 3);

        Point3i vec2 = vec1 * 5.0f;

        EXPECT_EQ(vec2.x, 5.0f);
        EXPECT_EQ(vec2.y, 10.0f);
        EXPECT_EQ(vec2.z, 15.0f);

        vec2 *= 2.0f;
        EXPECT_EQ(vec2.x, 10.0f);
        EXPECT_EQ(vec2.y, 20.0f);
        EXPECT_EQ(vec2.z, 30.0f);

        const Point3i vec3 = 2.0f * vec2;
        EXPECT_EQ(vec3.x, 20.0f);
        EXPECT_EQ(vec3.y, 40.0f);
        EXPECT_EQ(vec3.z, 60.0f);
    }
}

TEST(Point3Tests, DivisionScalar)
{
    {
        const Point3f vec1(20.0f, 40.0f, 60.0f);

        Point3f vec2 = vec1 / 2.0f;

        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);
        EXPECT_FLOAT_EQ(vec2.z, 30.0f);

        vec2 /= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);
        EXPECT_FLOAT_EQ(vec2.z, 15.0f);
    }
    {
        const Point3d vec1(20.0f, 40.0f, 60.0f);

        Point3d vec2 = vec1 / 2.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 30.0f);

        vec2 /= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 15.0f);
    }
    {
        const Point3i vec1(20, 40, 60);

        Point3i vec2 = vec1 / 2.0f;

        EXPECT_EQ(vec2.x, 10.0f);
        EXPECT_EQ(vec2.y, 20.0f);
        EXPECT_EQ(vec2.z, 30.0f);

        vec2 /= 2.0f;
        EXPECT_EQ(vec2.x, 5.0f);
        EXPECT_EQ(vec2.y, 10.0f);
        EXPECT_EQ(vec2.z, 15.0f);
    }
}

TEST(Point3Tests, Abs)
{
    {
        const Point3f vec(5, -10, -15);
        const Point3f a = Math::Abs(vec);

        EXPECT_FLOAT_EQ(a.x, 5.0f);
        EXPECT_FLOAT_EQ(a.y, 10.0f);
        EXPECT_FLOAT_EQ(a.z, 15.0f);
    }
    {
        const Point3d vec(5, -10, -15);
        const Point3d a = Math::Abs(vec);

        EXPECT_DOUBLE_EQ(a.x, 5.0f);
        EXPECT_DOUBLE_EQ(a.y, 10.0f);
        EXPECT_DOUBLE_EQ(a.z, 15.0f);
    }
    {
        const Point3i vec(5, -10, -15);
        const Point3i a = Math::Abs(vec);

        EXPECT_EQ(a.x, 5.0f);
        EXPECT_EQ(a.y, 10.0f);
        EXPECT_EQ(a.z, 15.0f);
    }
}

TEST(Point3Tests, IsEqual)
{
    {
        const Point3f v1(1, 2, 3);
        const Point3f v2(2, 3, 4);
        const Point3f v3(0, 1, 2);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5f));
    }
    {
        const Point3d v1(1, 2, 3);
        const Point3d v2(2, 3, 4);
        const Point3d v3(0, 1, 2);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5));
    }
    {
        const Point3i v1(1, 2, 3);
        const Point3i v2(2, 3, 4);
        const Point3i v3(0, 1, 2);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0));
    }
}

TEST(Point3Tests, Distance)
{
    {
        const Point3f p1(3, 4, 5);
        const Point3f p2(4, 6, 7);

        EXPECT_DOUBLE_EQ(Math::Distance(p1, p2), 3.0f);
        EXPECT_FLOAT_EQ(Math::DistanceSquared(p1, p2), 9.0f);
    }
    {
        const Point3d p1(3, 4, 5);
        const Point3d p2(4, 6, 7);

        EXPECT_DOUBLE_EQ(Math::Distance(p1, p2), 3.0);
        EXPECT_DOUBLE_EQ(Math::DistanceSquared(p1, p2), 9.0);
    }
    {
        const Point3i p1(3, 4, 5);
        const Point3i p2(4, 6, 7);

        EXPECT_DOUBLE_EQ(Math::Distance(p1, p2), 3.0);
        EXPECT_EQ(Math::DistanceSquared(p1, p2), 9);
    }
}

TEST(Point3Tests, Lerp)
{
    {
        const Point3f p1(1, 2, 3);
        const Point3f p2(3, 4, 5);

        const Point3f lerp = Math::Lerp(0.5f, p1, p2);

        EXPECT_FLOAT_EQ(lerp.x, 2.0f);
        EXPECT_FLOAT_EQ(lerp.y, 3.0f);
        EXPECT_FLOAT_EQ(lerp.z, 4.0f);
    }
    {
        const Point3d p1(1, 2, 3);
        const Point3d p2(3, 4, 5);

        const Point3d lerp = Math::Lerp(0.5, p1, p2);

        EXPECT_DOUBLE_EQ(lerp.x, 2.0);
        EXPECT_DOUBLE_EQ(lerp.y, 3.0);
        EXPECT_DOUBLE_EQ(lerp.z, 4.0);
    }
    {
        const Point3i p1(1, 2, 3);
        const Point3i p2(3, 4, 5);

        const Point3i lerp = Math::Lerp(2, p1, p2);

        EXPECT_EQ(lerp.x, 5);
        EXPECT_EQ(lerp.y, 6);
        EXPECT_EQ(lerp.z, 7);
    }
}

TEST(Point3Tests, MinMaxPermute)
{
    {
        const Point3f vec1(1, 2, 3);
        const Point3f vec2(3, -2, 5);
        const Point3f min = Min(vec1, vec2);
        const Point3f max = Max(vec1, vec2);

        EXPECT_FLOAT_EQ(min.x, 1.0f);
        EXPECT_FLOAT_EQ(min.y, -2.0f);
        EXPECT_FLOAT_EQ(min.z, 3.0f);
        EXPECT_FLOAT_EQ(max.x, 3.0f);
        EXPECT_FLOAT_EQ(max.y, 2.0f);
        EXPECT_FLOAT_EQ(max.z, 5.0f);

        const Point3f vec(1, 2, 3);
        const Point3f perm = Math::Permute(vec, 1, 2, 0);
        EXPECT_FLOAT_EQ(perm.x, 2.0f);
        EXPECT_FLOAT_EQ(perm.y, 3.0f);
        EXPECT_FLOAT_EQ(perm.z, 1.0f);
    }
    {
        const Point3d vec1(1, 2, 3);
        const Point3d vec2(3, -2, 5);
        const Point3d min = Min(vec1, vec2);
        const Point3d max = Max(vec1, vec2);

        EXPECT_DOUBLE_EQ(min.x, 1.0f);
        EXPECT_DOUBLE_EQ(min.y, -2.0f);
        EXPECT_DOUBLE_EQ(min.z, 3.0f);
        EXPECT_DOUBLE_EQ(max.x, 3.0f);
        EXPECT_DOUBLE_EQ(max.y, 2.0f);
        EXPECT_DOUBLE_EQ(max.z, 5.0f);

        const Point3f vec(1, 2, 3);
        const Point3f perm = Math::Permute(vec, 1, 2, 0);
        EXPECT_DOUBLE_EQ(perm.x, 2.0f);
        EXPECT_DOUBLE_EQ(perm.y, 3.0f);
        EXPECT_DOUBLE_EQ(perm.z, 1.0f);
    }
    {
        const Point3i vec1(1, 2, 3);
        const Point3i vec2(3, -2, 5);
        const Point3i min = Min(vec1, vec2);
        const Point3i max = Max(vec1, vec2);

        EXPECT_EQ(min.x, 1.0f);
        EXPECT_EQ(min.y, -2.0f);
        EXPECT_EQ(min.z, 3.0f);
        EXPECT_EQ(max.x, 3.0f);
        EXPECT_EQ(max.y, 2.0f);
        EXPECT_EQ(max.z, 5.0f);

        const Point3f vec(1, 2, 3);
        const Point3f perm = Math::Permute(vec, 1, 2, 0);
        EXPECT_EQ(perm.x, 2.0f);
        EXPECT_EQ(perm.y, 3.0f);
        EXPECT_EQ(perm.z, 1.0f);
    }
}

TEST(Point3Tests, Floor)
{
    {
        const Point3f vec(1.1f, 2.2f, 3.3f);
        const Point3f floor = Math::Floor(vec);
        EXPECT_FLOAT_EQ(floor.x, 1.0f);
        EXPECT_FLOAT_EQ(floor.y, 2.0f);
        EXPECT_FLOAT_EQ(floor.z, 3.0f);
    }
    {
        const Point3d vec(1.1, 2.2, 3.3);
        const Point3d floor = Math::Floor(vec);
        EXPECT_DOUBLE_EQ(floor.x, 1.0);
        EXPECT_DOUBLE_EQ(floor.y, 2.0);
        EXPECT_DOUBLE_EQ(floor.z, 3.0);
    }
    {
        const Point3i vec(1, 2, 3);
        const Point3i floor = Math::Floor(vec);
        EXPECT_EQ(floor.x, 1);
        EXPECT_EQ(floor.y, 2);
        EXPECT_EQ(floor.z, 3);
    }
}

TEST(Point3Tests, Ceil)
{
    {
        const Point3f vec(1.1f, 2.2f, 3.3f);
        const Point3f ceil = Math::Ceil(vec);
        EXPECT_FLOAT_EQ(ceil.x, 2.0f);
        EXPECT_FLOAT_EQ(ceil.y, 3.0f);
        EXPECT_FLOAT_EQ(ceil.z, 4.0f);
    }
    {
        const Point3d vec(1.1, 2.2, 3.3);
        const Point3d ceil = Math::Ceil(vec);
        EXPECT_DOUBLE_EQ(ceil.x, 2.0);
        EXPECT_DOUBLE_EQ(ceil.y, 3.0);
        EXPECT_DOUBLE_EQ(ceil.z, 4.0);
    }
    {
        const Point3i vec(1, 2, 3);
        const Point3i ceil = Math::Ceil(vec);
        EXPECT_EQ(ceil.x, 1);
        EXPECT_EQ(ceil.y, 2);
        EXPECT_EQ(ceil.z, 3);
    }
}

TEST(Point3Tests, Round)
{
    {
        const Point3f vec(1.1f, 2.2f, 3.5f);
        const Point3f round = Math::Round(vec);
        EXPECT_FLOAT_EQ(round.x, 1.0f);
        EXPECT_FLOAT_EQ(round.y, 2.0f);
        EXPECT_FLOAT_EQ(round.z, 4.0f);
    }
    {
        const Point3d vec(1.1, 2.2, 3.5);
        const Point3d round = Math::Round(vec);
        EXPECT_DOUBLE_EQ(round.x, 1.0);
        EXPECT_DOUBLE_EQ(round.y, 2.0);
        EXPECT_DOUBLE_EQ(round.z, 4.0);
    }
    {
        const Point3i vec(1, 2, 3);
        const Point3i round = Math::Round(vec);
        EXPECT_EQ(round.x, 1);
        EXPECT_EQ(round.y, 2);
        EXPECT_EQ(round.z, 3);
    }
}
