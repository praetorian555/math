#include <gtest/gtest.h>

#include "math/point4t.h"

using Point4f = Math::Point4T<float>;
using Point4d = Math::Point4T<double>;
using Point4i = Math::Point4T<int>;
using Vec4f = Math::Vector4T<float>;
using Vec4d = Math::Vector4T<double>;
using Vec4i = Math::Vector4T<int>;

TEST(Point4Tests, Construction)
{
    {
        const Point4f vec1(1, 2, 3, 4);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);
        EXPECT_EQ(vec1.z, 3);
        EXPECT_EQ(vec1.w, 4);

        const Point4f vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
        EXPECT_EQ(vec2.z, 1);
        EXPECT_EQ(vec2.w, 1);
    }
    {
        const Point4d vec1(1, 2, 3, 4);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);
        EXPECT_EQ(vec1.z, 3);
        EXPECT_EQ(vec1.w, 4);

        const Point4d vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
        EXPECT_EQ(vec2.z, 1);
        EXPECT_EQ(vec2.w, 1);
    }
    {
        const Point4i vec1(1, 2, 3, 4);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);
        EXPECT_EQ(vec1.z, 3);
        EXPECT_EQ(vec1.w, 4);

        const Point4i vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
        EXPECT_EQ(vec2.z, 1);
        EXPECT_EQ(vec2.w, 1);
    }
}

TEST(Point4Tests, AccessOperators)
{
    {
        Point4f p1(1, 2, 3, 4);
        EXPECT_FLOAT_EQ(p1[0], 1);
        EXPECT_FLOAT_EQ(p1[1], 2);
        EXPECT_FLOAT_EQ(p1[2], 3);
        EXPECT_FLOAT_EQ(p1[3], 4);

        p1[0] = 5;
        p1[1] = 6;
        p1[2] = 7;
        p1[3] = 8;
        EXPECT_FLOAT_EQ(p1[0], 5);
        EXPECT_FLOAT_EQ(p1[1], 6);
        EXPECT_FLOAT_EQ(p1[2], 7);
        EXPECT_FLOAT_EQ(p1[3], 8);
    }
    {
        Point4d p1(1, 2, 3, 4);
        EXPECT_DOUBLE_EQ(p1[0], 1);
        EXPECT_DOUBLE_EQ(p1[1], 2);
        EXPECT_DOUBLE_EQ(p1[2], 3);
        EXPECT_DOUBLE_EQ(p1[3], 4);

        p1[0] = 5;
        p1[1] = 6;
        p1[2] = 7;
        p1[3] = 8;
        EXPECT_DOUBLE_EQ(p1[0], 5);
        EXPECT_DOUBLE_EQ(p1[1], 6);
        EXPECT_DOUBLE_EQ(p1[2], 7);
        EXPECT_DOUBLE_EQ(p1[3], 8);
    }
    {
        Point4i p1(1, 2, 3, 4);
        EXPECT_EQ(p1[0], 1);
        EXPECT_EQ(p1[1], 2);
        EXPECT_EQ(p1[2], 3);
        EXPECT_EQ(p1[3], 4);

        p1[0] = 5;
        p1[1] = 6;
        p1[2] = 7;
        p1[3] = 8;
        EXPECT_EQ(p1[0], 5);
        EXPECT_EQ(p1[1], 6);
        EXPECT_EQ(p1[2], 7);
        EXPECT_EQ(p1[3], 8);
    }
}

TEST(Point4Tests, ContainsNonFinite)
{
    {
        const Point4f vec1(1, 2, 3, 4);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Point4f vec2(1, 2, 3, std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Point4f vec3(1, 2, 3, -std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Point4f vec4(1, 2, 3, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Point4f vec5(1, 2, 3, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Point4d vec1(1, 2, 3, 4);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Point4d vec2(1, 2, 3, std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Point4d vec3(1, 2, 3, -std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Point4d vec4(1, 2, 3, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Point4d vec5(1, 2, 3, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Point4d vec1(1, 2, 3, 4);
        EXPECT_FALSE(ContainsNonFinite(vec1));
    }
}

TEST(Point4Tests, ContainsNaN)
{
    {
        const Point4f vec1(1, 2, 3, 4);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Point4f vec2(1, 2, 3, std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Point4f vec3(1, 2, 3, -std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Point4f vec4(1, 2, 3, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Point4f vec5(1, 2, 3, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Point4d vec1(1, 2, 3, 4);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Point4d vec2(1, 2, 3, std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Point4d vec3(1, 2, 3, -std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Point4d vec4(1, 2, 3, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Point4d vec5(1, 2, 3, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Point4d vec1(1, 2, 3, 4);
        EXPECT_FALSE(ContainsNaN(vec1));
    }
}

TEST(Point4Tests, Comparisons)
{
    {
        const Point4f vec1(1, 2, 3, 4);
        const Point4f vec2(1, 2, 3, 4);
        const Point4f vec3(1, 2, 3, 5);
        const Point4f vec4(1, 2, 4, 4);
        const Point4f vec5(1, 3, 3, 4);
        const Point4f vec6(2, 2, 3, 4);

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
        const Point4d vec1(1, 2, 3, 4);
        const Point4d vec2(1, 2, 3, 4);
        const Point4d vec3(1, 2, 3, 5);
        const Point4d vec4(1, 2, 4, 4);
        const Point4d vec5(1, 3, 3, 4);
        const Point4d vec6(2, 2, 3, 4);

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
        const Point4i vec1(1, 2, 3, 4);
        const Point4i vec2(1, 2, 3, 4);
        const Point4i vec3(1, 2, 3, 5);
        const Point4i vec4(1, 2, 4, 4);
        const Point4i vec5(1, 3, 3, 4);
        const Point4i vec6(2, 2, 3, 4);

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

TEST(Point4Tests, Addition)
{
    {
        const Point4f vec1(1, 2, 3, 4);
        const Vec4f vec2(3, 4, 5, 6);

        Point4f vec3 = vec1 + vec2;
        EXPECT_FLOAT_EQ(vec3.x, 4.0f);
        EXPECT_FLOAT_EQ(vec3.y, 6.0f);
        EXPECT_FLOAT_EQ(vec3.z, 8.0f);
        EXPECT_FLOAT_EQ(vec3.w, 10.0f);

        vec3 += vec2;
        EXPECT_FLOAT_EQ(vec3.x, 7.0f);
        EXPECT_FLOAT_EQ(vec3.y, 10.0f);
        EXPECT_FLOAT_EQ(vec3.z, 13.0f);
        EXPECT_FLOAT_EQ(vec3.w, 16.0f);
    }
    {
        const Point4d vec1(1, 2, 3, 4);
        const Vec4d vec2(3, 4, 5, 6);

        Point4d vec3 = vec1 + vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 4.0);
        EXPECT_DOUBLE_EQ(vec3.y, 6.0);
        EXPECT_DOUBLE_EQ(vec3.z, 8.0);
        EXPECT_DOUBLE_EQ(vec3.w, 10.0);

        vec3 += vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 7.0);
        EXPECT_DOUBLE_EQ(vec3.y, 10.0);
        EXPECT_DOUBLE_EQ(vec3.z, 13.0);
        EXPECT_DOUBLE_EQ(vec3.w, 16.0);
    }
    {
        const Point4i vec1(1, 2, 3, 4);
        const Vec4i vec2(3, 4, 5, 6);

        Point4i vec3 = vec1 + vec2;
        EXPECT_EQ(vec3.x, 4);
        EXPECT_EQ(vec3.y, 6);
        EXPECT_EQ(vec3.z, 8);
        EXPECT_EQ(vec3.w, 10);

        vec3 += vec2;
        EXPECT_EQ(vec3.x, 7);
        EXPECT_EQ(vec3.y, 10);
        EXPECT_EQ(vec3.z, 13);
        EXPECT_EQ(vec3.w, 16);
    }
}

TEST(Point4Tests, Subtraction)
{
    {
        const Point4f vec1(1, 2, 3, 4);
        const Point4f vec2(3, 4, 5, 6);
        const Vec4f vec3(2, 2, 2, 2);

        const Point4f vec4 = vec2 - vec3;
        EXPECT_FLOAT_EQ(vec4.x, 1.0f);
        EXPECT_FLOAT_EQ(vec4.y, 2.0f);
        EXPECT_FLOAT_EQ(vec4.z, 3.0f);
        EXPECT_FLOAT_EQ(vec4.w, 4.0f);

        const Vec4f vec5 = vec2 - vec1;
        EXPECT_FLOAT_EQ(vec5.x, 2.0f);
        EXPECT_FLOAT_EQ(vec5.y, 2.0f);
        EXPECT_FLOAT_EQ(vec5.z, 2.0f);
        EXPECT_FLOAT_EQ(vec5.w, 2.0f);
    }
    {
        const Point4d vec1(1, 2, 3, 4);
        const Point4d vec2(3, 4, 5, 6);
        const Vec4d vec3(2, 2, 2, 2);

        const Point4d vec4 = vec2 - vec3;
        EXPECT_DOUBLE_EQ(vec4.x, 1.0f);
        EXPECT_DOUBLE_EQ(vec4.y, 2.0f);
        EXPECT_DOUBLE_EQ(vec4.z, 3.0f);
        EXPECT_DOUBLE_EQ(vec4.w, 4.0f);

        const Vec4d vec5 = vec2 - vec1;
        EXPECT_DOUBLE_EQ(vec5.x, 2.0f);
        EXPECT_DOUBLE_EQ(vec5.y, 2.0f);
        EXPECT_DOUBLE_EQ(vec5.z, 2.0f);
        EXPECT_DOUBLE_EQ(vec5.w, 2.0f);
    }
    {
        const Point4i vec1(1, 2, 3, 4);
        const Point4i vec2(3, 4, 5, 6);
        const Vec4i vec3(2, 2, 2, 2);

        const Point4i vec4 = vec2 - vec3;
        EXPECT_EQ(vec4.x, 1.0f);
        EXPECT_EQ(vec4.y, 2.0f);
        EXPECT_EQ(vec4.z, 3.0f);
        EXPECT_EQ(vec4.w, 4.0f);

        const Vec4i vec5 = vec2 - vec1;
        EXPECT_EQ(vec5.x, 2.0f);
        EXPECT_EQ(vec5.y, 2.0f);
        EXPECT_EQ(vec5.z, 2.0f);
        EXPECT_EQ(vec5.w, 2.0f);
    }
}

TEST(Point4Tests, Negation)
{
    {
        const Point4f vec(5, -10, -15, 20);
        const Point4f neg = -vec;

        EXPECT_FLOAT_EQ(neg.x, -5.0f);
        EXPECT_FLOAT_EQ(neg.y, 10.0f);
        EXPECT_FLOAT_EQ(neg.z, 15.0f);
        EXPECT_FLOAT_EQ(neg.w, -20.0f);
    }
    {
        const Point4d vec(5, -10, -15, 20);
        const Point4d neg = -vec;

        EXPECT_DOUBLE_EQ(neg.x, -5.0f);
        EXPECT_DOUBLE_EQ(neg.y, 10.0f);
        EXPECT_DOUBLE_EQ(neg.z, 15.0f);
        EXPECT_DOUBLE_EQ(neg.w, -20.0f);
    }
    {
        const Point4i vec(5, -10, -15, 20);
        const Point4i neg = -vec;

        EXPECT_EQ(neg.x, -5.0f);
        EXPECT_EQ(neg.y, 10.0f);
        EXPECT_EQ(neg.z, 15.0f);
        EXPECT_EQ(neg.w, -20.0f);
    }
}

TEST(Point4Tests, MultiplicationScalar)
{
    {
        const Point4f vec1(1, 2, 3, 4);

        Point4f vec2 = vec1 * 5.0f;

        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);
        EXPECT_FLOAT_EQ(vec2.z, 15.0f);
        EXPECT_FLOAT_EQ(vec2.w, 20.0f);

        vec2 *= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);
        EXPECT_FLOAT_EQ(vec2.z, 30.0f);
        EXPECT_FLOAT_EQ(vec2.w, 40.0f);

        const Point4f vec3 = 2.0f * vec2;
        EXPECT_FLOAT_EQ(vec3.x, 20.0f);
        EXPECT_FLOAT_EQ(vec3.y, 40.0f);
        EXPECT_FLOAT_EQ(vec3.z, 60.0f);
        EXPECT_FLOAT_EQ(vec3.w, 80.0f);
    }
    {
        const Point4d vec1(1, 2, 3, 4);

        Point4d vec2 = vec1 * 5.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 15.0f);
        EXPECT_DOUBLE_EQ(vec2.w, 20.0f);

        vec2 *= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 30.0f);
        EXPECT_DOUBLE_EQ(vec2.w, 40.0f);

        const Point4d vec3 = 2.0f * vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 20.0f);
        EXPECT_DOUBLE_EQ(vec3.y, 40.0f);
        EXPECT_DOUBLE_EQ(vec3.z, 60.0f);
        EXPECT_DOUBLE_EQ(vec3.w, 80.0f);
    }
    {
        const Point4i vec1(1, 2, 3, 4);

        Point4i vec2 = vec1 * 5.0f;

        EXPECT_EQ(vec2.x, 5.0f);
        EXPECT_EQ(vec2.y, 10.0f);
        EXPECT_EQ(vec2.z, 15.0f);
        EXPECT_EQ(vec2.w, 20.0f);

        vec2 *= 2.0f;
        EXPECT_EQ(vec2.x, 10.0f);
        EXPECT_EQ(vec2.y, 20.0f);
        EXPECT_EQ(vec2.z, 30.0f);
        EXPECT_EQ(vec2.w, 40.0f);

        const Point4i vec3 = 2.0f * vec2;
        EXPECT_EQ(vec3.x, 20.0f);
        EXPECT_EQ(vec3.y, 40.0f);
        EXPECT_EQ(vec3.z, 60.0f);
        EXPECT_EQ(vec3.w, 80.0f);
    }
}

TEST(Point4Tests, DivisionScalar)
{
    {
        const Point4f vec1(20.0f, 40.0f, 60.0f, 80);

        Point4f vec2 = vec1 / 2.0f;

        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);
        EXPECT_FLOAT_EQ(vec2.z, 30.0f);
        EXPECT_FLOAT_EQ(vec2.w, 40.0f);

        vec2 /= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);
        EXPECT_FLOAT_EQ(vec2.z, 15.0f);
        EXPECT_FLOAT_EQ(vec2.w, 20.0f);
    }
    {
        const Point4d vec1(20.0f, 40.0f, 60.0f, 80);

        Point4d vec2 = vec1 / 2.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 30.0f);
        EXPECT_DOUBLE_EQ(vec2.w, 40.0f);

        vec2 /= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.z, 15.0f);
        EXPECT_DOUBLE_EQ(vec2.w, 20.0f);
    }
    {
        const Point4i vec1(20, 40, 60, 80);

        Point4i vec2 = vec1 / 2.0f;

        EXPECT_EQ(vec2.x, 10.0f);
        EXPECT_EQ(vec2.y, 20.0f);
        EXPECT_EQ(vec2.z, 30.0f);
        EXPECT_EQ(vec2.w, 40.0f);

        vec2 /= 2.0f;
        EXPECT_EQ(vec2.x, 5.0f);
        EXPECT_EQ(vec2.y, 10.0f);
        EXPECT_EQ(vec2.z, 15.0f);
        EXPECT_EQ(vec2.w, 20.0f);
    }
}

TEST(Point4Tests, Abs)
{
    {
        const Point4f vec(5, -10, -15, 20);
        const Point4f a = Math::Abs(vec);

        EXPECT_FLOAT_EQ(a.x, 5.0f);
        EXPECT_FLOAT_EQ(a.y, 10.0f);
        EXPECT_FLOAT_EQ(a.z, 15.0f);
        EXPECT_FLOAT_EQ(a.w, 20.0f);
    }
    {
        const Point4d vec(5, -10, -15, 20);
        const Point4d a = Math::Abs(vec);

        EXPECT_DOUBLE_EQ(a.x, 5.0f);
        EXPECT_DOUBLE_EQ(a.y, 10.0f);
        EXPECT_DOUBLE_EQ(a.z, 15.0f);
        EXPECT_DOUBLE_EQ(a.w, 20.0f);
    }
    {
        const Point4i vec(5, -10, -15, 20);
        const Point4i a = Math::Abs(vec);

        EXPECT_EQ(a.x, 5.0f);
        EXPECT_EQ(a.y, 10.0f);
        EXPECT_EQ(a.z, 15.0f);
        EXPECT_EQ(a.w, 20.0f);
    }
}

TEST(Point4Tests, ToEuclidean)
{
{
        const Point4f vec(10, 20, 30, 2);
        const Point4f a = Math::ToEuclidean(vec);

        EXPECT_FLOAT_EQ(a.x, 5.0f);
        EXPECT_FLOAT_EQ(a.y, 10.0f);
        EXPECT_FLOAT_EQ(a.z, 15.0f);
        EXPECT_FLOAT_EQ(a.w, 1.0f);
    }
    {
        const Point4d vec(10, 20, 30, 2);
        const Point4d a = Math::ToEuclidean(vec);

        EXPECT_DOUBLE_EQ(a.x, 5.0);
        EXPECT_DOUBLE_EQ(a.y, 10.0);
        EXPECT_DOUBLE_EQ(a.z, 15.0);
        EXPECT_DOUBLE_EQ(a.w, 1.0);
    }
    {
        const Point4i vec(10, 20, 30, 2);
        const Point4i a = Math::ToEuclidean(vec);

        EXPECT_EQ(a.x, 5);
        EXPECT_EQ(a.y, 10);
        EXPECT_EQ(a.z, 15);
        EXPECT_EQ(a.w, 1);
    }
}

TEST(Point4Tests, IsEqual)
{
    {
        const Point4f v1(1, 2, 3, 4);
        const Point4f v2(2, 3, 4, 5);
        const Point4f v3(0, 1, 2, 3);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5f));
    }
    {
        const Point4d v1(1, 2, 3, 4);
        const Point4d v2(2, 3, 4, 5);
        const Point4d v3(0, 1, 2, 3);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5));
    }
    {
        const Point4i v1(1, 2, 3, 4);
        const Point4i v2(2, 3, 4, 5);
        const Point4i v3(0, 1, 2, 3);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0));
    }
}

TEST(Point4Tests, Distance)
{
    {
        const Point4f p1(3, 4, 5, 6);
        const Point4f p2(4, 5, 6, 7);

        EXPECT_DOUBLE_EQ(Math::Distance(p1, p2), 2.0f);
        EXPECT_FLOAT_EQ(Math::DistanceSquared(p1, p2), 4.0f);
    }
    {
        const Point4d p1(3, 4, 5, 6);
        const Point4d p2(4, 5, 6, 7);

        EXPECT_DOUBLE_EQ(Math::Distance(p1, p2), 2.0);
        EXPECT_DOUBLE_EQ(Math::DistanceSquared(p1, p2), 4.0);
    }
    {
        const Point4i p1(3, 4, 5, 6);
        const Point4i p2(4, 5, 6, 7);

        EXPECT_DOUBLE_EQ(Math::Distance(p1, p2), 2.0);
        EXPECT_EQ(Math::DistanceSquared(p1, p2), 4);
    }
}

TEST(Point4Tests, Lerp)
{
    {
        const Point4f p1(1, 2, 3, 4);
        const Point4f p2(3, 4, 5, 6);

        const Point4f lerp = Math::Lerp(0.5f, p1, p2);

        EXPECT_FLOAT_EQ(lerp.x, 2.0f);
        EXPECT_FLOAT_EQ(lerp.y, 3.0f);
        EXPECT_FLOAT_EQ(lerp.z, 4.0f);
        EXPECT_FLOAT_EQ(lerp.w, 5.0f);
    }
    {
        const Point4d p1(1, 2, 3, 4);
        const Point4d p2(3, 4, 5, 6);

        const Point4d lerp = Math::Lerp(0.5, p1, p2);

        EXPECT_DOUBLE_EQ(lerp.x, 2.0);
        EXPECT_DOUBLE_EQ(lerp.y, 3.0);
        EXPECT_DOUBLE_EQ(lerp.z, 4.0);
        EXPECT_DOUBLE_EQ(lerp.w, 5.0);
    }
    {
        const Point4i p1(1, 2, 3, 4);
        const Point4i p2(3, 4, 5, 6);

        const Point4i lerp = Math::Lerp(2, p1, p2);

        EXPECT_EQ(lerp.x, 5);
        EXPECT_EQ(lerp.y, 6);
        EXPECT_EQ(lerp.z, 7);
        EXPECT_EQ(lerp.w, 8);
    }
}

TEST(Point4Tests, MinMaxPermute)
{
    {
        const Point4f vec1(1, 2, 3, 4);
        const Point4f vec2(3, -2, 5, -3);
        const Point4f min = Min(vec1, vec2);
        const Point4f max = Max(vec1, vec2);

        EXPECT_FLOAT_EQ(min.x, 1.0f);
        EXPECT_FLOAT_EQ(min.y, -2.0f);
        EXPECT_FLOAT_EQ(min.z, 3.0f);
        EXPECT_FLOAT_EQ(min.w, -3.0f);
        EXPECT_FLOAT_EQ(max.x, 3.0f);
        EXPECT_FLOAT_EQ(max.y, 2.0f);
        EXPECT_FLOAT_EQ(max.z, 5.0f);
        EXPECT_FLOAT_EQ(max.w, 4.0f);

        const Point4f vec(1, 2, 3, 4);
        const Point4f perm = Math::Permute(vec, 1, 2, 3, 0);
        EXPECT_FLOAT_EQ(perm.x, 2.0f);
        EXPECT_FLOAT_EQ(perm.y, 3.0f);
        EXPECT_FLOAT_EQ(perm.z, 4.0f);
        EXPECT_FLOAT_EQ(perm.w, 1.0f);
    }
    {
        const Point4d vec1(1, 2, 3, 4);
        const Point4d vec2(3, -2, 5, -3);
        const Point4d min = Min(vec1, vec2);
        const Point4d max = Max(vec1, vec2);

        EXPECT_DOUBLE_EQ(min.x, 1.0f);
        EXPECT_DOUBLE_EQ(min.y, -2.0f);
        EXPECT_DOUBLE_EQ(min.z, 3.0f);
        EXPECT_DOUBLE_EQ(min.w, -3.0f);
        EXPECT_DOUBLE_EQ(max.x, 3.0f);
        EXPECT_DOUBLE_EQ(max.y, 2.0f);
        EXPECT_DOUBLE_EQ(max.z, 5.0f);
        EXPECT_DOUBLE_EQ(max.w, 4.0f);

        const Point4f vec(1, 2, 3, 4);
        const Point4f perm = Math::Permute(vec, 1, 2, 3, 0);
        EXPECT_DOUBLE_EQ(perm.x, 2.0f);
        EXPECT_DOUBLE_EQ(perm.y, 3.0f);
        EXPECT_DOUBLE_EQ(perm.z, 4.0f);
        EXPECT_DOUBLE_EQ(perm.w, 1.0f);
    }
    {
        const Point4i vec1(1, 2, 3, 4);
        const Point4i vec2(3, -2, 5, -3);
        const Point4i min = Min(vec1, vec2);
        const Point4i max = Max(vec1, vec2);

        EXPECT_EQ(min.x, 1.0f);
        EXPECT_EQ(min.y, -2.0f);
        EXPECT_EQ(min.z, 3.0f);
        EXPECT_EQ(min.w, -3.0f);
        EXPECT_EQ(max.x, 3.0f);
        EXPECT_EQ(max.y, 2.0f);
        EXPECT_EQ(max.z, 5.0f);
        EXPECT_EQ(max.w, 4.0f);

        const Point4f vec(1, 2, 3, 4);
        const Point4f perm = Math::Permute(vec, 1, 2, 3, 0);
        EXPECT_EQ(perm.x, 2.0f);
        EXPECT_EQ(perm.y, 3.0f);
        EXPECT_EQ(perm.z, 4.0f);
        EXPECT_EQ(perm.w, 1.0f);
    }
}

TEST(Point4Tests, Floor)
{
    {
        const Point4f vec(1.1f, 2.2f, 3.3f, 4.4f);
        const Point4f floor = Math::Floor(vec);
        EXPECT_FLOAT_EQ(floor.x, 1.0f);
        EXPECT_FLOAT_EQ(floor.y, 2.0f);
        EXPECT_FLOAT_EQ(floor.z, 3.0f);
        EXPECT_FLOAT_EQ(floor.w, 4.0f);
    }
    {
        const Point4d vec(1.1, 2.2, 3.3, 4.4);
        const Point4d floor = Math::Floor(vec);
        EXPECT_DOUBLE_EQ(floor.x, 1.0);
        EXPECT_DOUBLE_EQ(floor.y, 2.0);
        EXPECT_DOUBLE_EQ(floor.z, 3.0);
        EXPECT_DOUBLE_EQ(floor.w, 4.0);
    }
    {
        const Point4i vec(1, 2, 3, 4);
        const Point4i floor = Math::Floor(vec);
        EXPECT_EQ(floor.x, 1);
        EXPECT_EQ(floor.y, 2);
        EXPECT_EQ(floor.z, 3);
        EXPECT_EQ(floor.w, 4);
    }
}

TEST(Point4Tests, Ceil)
{
    {
        const Point4f vec(1.1f, 2.2f, 3.3f, 4.4f);
        const Point4f ceil = Math::Ceil(vec);
        EXPECT_FLOAT_EQ(ceil.x, 2.0f);
        EXPECT_FLOAT_EQ(ceil.y, 3.0f);
        EXPECT_FLOAT_EQ(ceil.z, 4.0f);
        EXPECT_FLOAT_EQ(ceil.w, 5.0f);
    }
    {
        const Point4d vec(1.1, 2.2, 3.3, 4.4);
        const Point4d ceil = Math::Ceil(vec);
        EXPECT_DOUBLE_EQ(ceil.x, 2.0);
        EXPECT_DOUBLE_EQ(ceil.y, 3.0);
        EXPECT_DOUBLE_EQ(ceil.z, 4.0);
        EXPECT_DOUBLE_EQ(ceil.w, 5.0);
    }
    {
        const Point4i vec(1, 2, 3, 4);
        const Point4i ceil = Math::Ceil(vec);
        EXPECT_EQ(ceil.x, 1);
        EXPECT_EQ(ceil.y, 2);
        EXPECT_EQ(ceil.z, 3);
        EXPECT_EQ(ceil.w, 4);
    }
}

TEST(Point4Tests, Round)
{
    {
        const Point4f vec(1.1f, 2.2f, 3.5f, 4.7f);
        const Point4f round = Math::Round(vec);
        EXPECT_FLOAT_EQ(round.x, 1.0f);
        EXPECT_FLOAT_EQ(round.y, 2.0f);
        EXPECT_FLOAT_EQ(round.z, 4.0f);
        EXPECT_FLOAT_EQ(round.w, 5.0f);
    }
    {
        const Point4d vec(1.1, 2.2, 3.5, 4.7);
        const Point4d round = Math::Round(vec);
        EXPECT_DOUBLE_EQ(round.x, 1.0);
        EXPECT_DOUBLE_EQ(round.y, 2.0);
        EXPECT_DOUBLE_EQ(round.z, 4.0);
        EXPECT_DOUBLE_EQ(round.w, 5.0);
    }
    {
        const Point4i vec(1, 2, 3, 4);
        const Point4i round = Math::Round(vec);
        EXPECT_EQ(round.x, 1);
        EXPECT_EQ(round.y, 2);
        EXPECT_EQ(round.z, 3);
        EXPECT_EQ(round.w, 4);
    }
}
