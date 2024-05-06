#include <gtest/gtest.h>

#include "math/point2.h"

using Point2f = Math::Point2<float>;
using Point2d = Math::Point2<double>;
using Point2i = Math::Point2<int>;
using Vec2f = Math::Vector2<float>;
using Vec2d = Math::Vector2<double>;
using Vec2i = Math::Vector2<int>;

TEST(Point2Tests, Construction)
{
    {
        const Point2f vec1(1, 2);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);

        const Point2f vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
    }
    {
        const Point2d vec1(1, 2);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);

        const Point2d vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
    }
    {
        const Point2i vec1(1, 2);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);

        const Point2i vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
    }
}

TEST(Point2Tests, AccessOperators)
{
    {
        Point2f p1(1, 2);
        EXPECT_FLOAT_EQ(p1[0], 1);
        EXPECT_FLOAT_EQ(p1[1], 2);

        p1[0] = 5;
        p1[1] = 6;
        EXPECT_FLOAT_EQ(p1[0], 5);
        EXPECT_FLOAT_EQ(p1[1], 6);
    }
    {
        Point2d p1(1, 2);
        EXPECT_DOUBLE_EQ(p1[0], 1);
        EXPECT_DOUBLE_EQ(p1[1], 2);

        p1[0] = 5;
        p1[1] = 6;
        EXPECT_DOUBLE_EQ(p1[0], 5);
        EXPECT_DOUBLE_EQ(p1[1], 6);
    }
    {
        Point2i p1(1, 2);
        EXPECT_EQ(p1[0], 1);
        EXPECT_EQ(p1[1], 2);

        p1[0] = 5;
        p1[1] = 6;
        EXPECT_EQ(p1[0], 5);
        EXPECT_EQ(p1[1], 6);
    }
}

TEST(Point2Tests, ContainsNonFinite)
{
    {
        const Point2f vec1(1, 2);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Point2f vec2(1, std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Point2f vec3(1, -std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Point2f vec4(1, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Point2f vec5(1, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Point2d vec1(1, 2);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Point2d vec2(1, std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Point2d vec3(1, -std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Point2d vec4(1, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Point2d vec5(1, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Point2d vec1(1, 2);
        EXPECT_FALSE(ContainsNonFinite(vec1));
    }
}

TEST(Point2Tests, ContainsNaN)
{
    {
        const Point2f vec1(1, 2);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Point2f vec2(1, std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Point2f vec3(1, -std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Point2f vec4(1, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Point2f vec5(1, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Point2d vec1(1, 2);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Point2d vec2(1, std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Point2d vec3(1, -std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Point2d vec4(1, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Point2d vec5(1, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Point2d vec1(1, 3);
        EXPECT_FALSE(ContainsNaN(vec1));
    }
}

TEST(Point2Tests, Comparisons)
{
    {
        const Point2f vec1(1, 4);
        const Point2f vec2(1, 4);
        const Point2f vec3(1, 5);
        const Point2f vec4(1, 4);
        const Point2f vec5(1, 4);
        const Point2f vec6(2, 4);

        EXPECT_TRUE(vec1 == vec2);
        EXPECT_FALSE(vec1 == vec3);
        EXPECT_FALSE(vec1 != vec4);
        EXPECT_FALSE(vec1 != vec5);
        EXPECT_FALSE(vec1 == vec6);

        EXPECT_FALSE(vec1 != vec2);
        EXPECT_TRUE(vec1 != vec3);
        EXPECT_TRUE(vec1 == vec4);
        EXPECT_TRUE(vec1 == vec5);
        EXPECT_TRUE(vec1 != vec6);
    }
    {
        const Point2d vec1(1, 4);
        const Point2d vec2(1, 4);
        const Point2d vec3(1, 5);
        const Point2d vec4(1, 4);
        const Point2d vec5(1, 4);
        const Point2d vec6(2, 4);

        EXPECT_TRUE(vec1 == vec2);
        EXPECT_FALSE(vec1 == vec3);
        EXPECT_FALSE(vec1 != vec4);
        EXPECT_FALSE(vec1 != vec5);
        EXPECT_FALSE(vec1 == vec6);

        EXPECT_FALSE(vec1 != vec2);
        EXPECT_TRUE(vec1 != vec3);
        EXPECT_TRUE(vec1 == vec4);
        EXPECT_TRUE(vec1 == vec5);
        EXPECT_TRUE(vec1 != vec6);
    }
    {
        const Point2i vec1(1, 4);
        const Point2i vec2(1, 4);
        const Point2i vec3(1, 5);
        const Point2i vec4(1, 4);
        const Point2i vec5(1, 4);
        const Point2i vec6(2, 4);

        EXPECT_TRUE(vec1 == vec2);
        EXPECT_FALSE(vec1 == vec3);
        EXPECT_FALSE(vec1 != vec4);
        EXPECT_FALSE(vec1 != vec5);
        EXPECT_FALSE(vec1 == vec6);

        EXPECT_FALSE(vec1 != vec2);
        EXPECT_TRUE(vec1 != vec3);
        EXPECT_TRUE(vec1 == vec4);
        EXPECT_TRUE(vec1 == vec5);
        EXPECT_TRUE(vec1 != vec6);
    }
}

TEST(Point2Tests, Addition)
{
    {
        const Point2f vec1(1, 2);
        const Vec2f vec2(3, 4);

        Point2f vec3 = vec1 + vec2;
        EXPECT_FLOAT_EQ(vec3.x, 4.0f);
        EXPECT_FLOAT_EQ(vec3.y, 6.0f);

        vec3 += vec2;
        EXPECT_FLOAT_EQ(vec3.x, 7.0f);
        EXPECT_FLOAT_EQ(vec3.y, 10.0f);
    }
    {
        const Point2d vec1(1, 2);
        const Vec2d vec2(3, 4);

        Point2d vec3 = vec1 + vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 4.0);
        EXPECT_DOUBLE_EQ(vec3.y, 6.0);

        vec3 += vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 7.0);
        EXPECT_DOUBLE_EQ(vec3.y, 10.0);
    }
    {
        const Point2i vec1(1, 2);
        const Vec2i vec2(3, 4);

        Point2i vec3 = vec1 + vec2;
        EXPECT_EQ(vec3.x, 4);
        EXPECT_EQ(vec3.y, 6);

        vec3 += vec2;
        EXPECT_EQ(vec3.x, 7);
        EXPECT_EQ(vec3.y, 10);
    }
}

TEST(Point2Tests, Subtraction)
{
    {
        const Point2f vec1(1, 2);
        const Point2f vec2(3, 4);
        const Vec2f vec3(2, 2);

        const Point2f vec4 = vec2 - vec3;
        EXPECT_FLOAT_EQ(vec4.x, 1.0f);
        EXPECT_FLOAT_EQ(vec4.y, 2.0f);

        const Vec2f vec5 = vec2 - vec1;
        EXPECT_FLOAT_EQ(vec5.x, 2.0f);
        EXPECT_FLOAT_EQ(vec5.y, 2.0f);
    }
    {
        const Point2d vec1(1, 2);
        const Point2d vec2(3, 4);
        const Vec2d vec3(2, 2);

        const Point2d vec4 = vec2 - vec3;
        EXPECT_DOUBLE_EQ(vec4.x, 1.0f);
        EXPECT_DOUBLE_EQ(vec4.y, 2.0f);

        const Vec2d vec5 = vec2 - vec1;
        EXPECT_DOUBLE_EQ(vec5.x, 2.0f);
        EXPECT_DOUBLE_EQ(vec5.y, 2.0f);
    }
    {
        const Point2i vec1(1, 2);
        const Point2i vec2(3, 4);
        const Vec2i vec3(2, 2);

        const Point2i vec4 = vec2 - vec3;
        EXPECT_EQ(vec4.x, 1.0f);
        EXPECT_EQ(vec4.y, 2.0f);

        const Vec2i vec5 = vec2 - vec1;
        EXPECT_EQ(vec5.x, 2.0f);
        EXPECT_EQ(vec5.y, 2.0f);
    }
}

TEST(Point2Tests, Negation)
{
    {
        const Point2f vec(5, -10);
        const Point2f neg = -vec;

        EXPECT_FLOAT_EQ(neg.x, -5.0f);
        EXPECT_FLOAT_EQ(neg.y, 10.0f);
    }
    {
        const Point2d vec(5, -10);
        const Point2d neg = -vec;

        EXPECT_DOUBLE_EQ(neg.x, -5.0f);
        EXPECT_DOUBLE_EQ(neg.y, 10.0f);
    }
    {
        const Point2i vec(5, -10);
        const Point2i neg = -vec;

        EXPECT_EQ(neg.x, -5.0f);
        EXPECT_EQ(neg.y, 10.0f);
    }
}

TEST(Point2Tests, MultiplicationScalar)
{
    {
        const Point2f vec1(1, 2);

        Point2f vec2 = vec1 * 5.0f;

        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);

        vec2 *= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);

        const Point2f vec3 = 2.0f * vec2;
        EXPECT_FLOAT_EQ(vec3.x, 20.0f);
        EXPECT_FLOAT_EQ(vec3.y, 40.0f);
    }
    {
        const Point2d vec1(1, 2);

        Point2d vec2 = vec1 * 5.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);

        vec2 *= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);

        const Point2d vec3 = 2.0f * vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 20.0f);
        EXPECT_DOUBLE_EQ(vec3.y, 40.0f);
    }
    {
        const Point2i vec1(1, 2);

        Point2i vec2 = vec1 * 5.0f;

        EXPECT_EQ(vec2.x, 5.0f);
        EXPECT_EQ(vec2.y, 10.0f);

        vec2 *= 2.0f;
        EXPECT_EQ(vec2.x, 10.0f);
        EXPECT_EQ(vec2.y, 20.0f);

        const Point2i vec3 = 2.0f * vec2;
        EXPECT_EQ(vec3.x, 20.0f);
        EXPECT_EQ(vec3.y, 40.0f);
    }
}

TEST(Point2Tests, DivisionScalar)
{
    {
        const Point2f vec1(20.0f, 40.0f);

        Point2f vec2 = vec1 / 2.0f;

        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);

        vec2 /= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);
    }
    {
        const Point2d vec1(20.0f, 40.0f);

        Point2d vec2 = vec1 / 2.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);

        vec2 /= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);
    }
    {
        const Point2i vec1(20, 40);

        Point2i vec2 = vec1 / 2.0f;

        EXPECT_EQ(vec2.x, 10.0f);
        EXPECT_EQ(vec2.y, 20.0f);

        vec2 /= 2.0f;
        EXPECT_EQ(vec2.x, 5.0f);
        EXPECT_EQ(vec2.y, 10.0f);
    }
}

TEST(Point2Tests, Abs)
{
    {
        const Point2f vec(5, -10);
        const Point2f a = Math::Abs(vec);

        EXPECT_FLOAT_EQ(a.x, 5.0f);
        EXPECT_FLOAT_EQ(a.y, 10.0f);
    }
    {
        const Point2d vec(5, -10);
        const Point2d a = Math::Abs(vec);

        EXPECT_DOUBLE_EQ(a.x, 5.0f);
        EXPECT_DOUBLE_EQ(a.y, 10.0f);
    }
    {
        const Point2i vec(5, -10);
        const Point2i a = Math::Abs(vec);

        EXPECT_EQ(a.x, 5.0f);
        EXPECT_EQ(a.y, 10.0f);
    }
}

TEST(Point2Tests, IsEqual)
{
    {
        const Point2f v1(1, 2);
        const Point2f v2(2, 3);
        const Point2f v3(0, 1);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5f));
    }
    {
        const Point2d v1(1, 2);
        const Point2d v2(2, 3);
        const Point2d v3(0, 1);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5));
    }
    {
        const Point2i v1(1, 2);
        const Point2i v2(2, 3);
        const Point2i v3(0, 1);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0));
    }
}

TEST(Point2Tests, Distance)
{
    {
        const Point2f p1(3, 4);
        const Point2f p2(6, 8);

        EXPECT_DOUBLE_EQ(Math::Distance(p1, p2), 5.0f);
        EXPECT_FLOAT_EQ(Math::DistanceSquared(p1, p2), 25.0f);
    }
    {
        const Point2d p1(3, 4);
        const Point2d p2(6, 8);

        EXPECT_DOUBLE_EQ(Math::Distance(p1, p2), 5.0);
        EXPECT_DOUBLE_EQ(Math::DistanceSquared(p1, p2), 25.0);
    }
    {
        const Point2i p1(3, 4);
        const Point2i p2(6, 8);

        EXPECT_DOUBLE_EQ(Math::Distance(p1, p2), 5.0);
        EXPECT_EQ(Math::DistanceSquared(p1, p2), 25);
    }
}

TEST(Point2Tests, Lerp)
{
    {
        const Point2f p1(1, 2);
        const Point2f p2(3, 4);

        const Point2f lerp = Math::Lerp(0.5f, p1, p2);

        EXPECT_FLOAT_EQ(lerp.x, 2.0f);
        EXPECT_FLOAT_EQ(lerp.y, 3.0f);
    }
    {
        const Point2d p1(1, 2);
        const Point2d p2(3, 4);

        const Point2d lerp = Math::Lerp(0.5, p1, p2);

        EXPECT_DOUBLE_EQ(lerp.x, 2.0);
        EXPECT_DOUBLE_EQ(lerp.y, 3.0);
    }
    {
        const Point2i p1(1, 2);
        const Point2i p2(3, 4);

        const Point2i lerp = Math::Lerp(2, p1, p2);

        EXPECT_EQ(lerp.x, 5);
        EXPECT_EQ(lerp.y, 6);
    }
}

TEST(Point2Tests, MinMaxPermute)
{
    {
        const Point2f vec1(1, 2);
        const Point2f vec2(3, -2);
        const Point2f min = Min(vec1, vec2);
        const Point2f max = Max(vec1, vec2);

        EXPECT_FLOAT_EQ(min.x, 1.0f);
        EXPECT_FLOAT_EQ(min.y, -2.0f);
        EXPECT_FLOAT_EQ(max.x, 3.0f);
        EXPECT_FLOAT_EQ(max.y, 2.0f);

        const Point2f vec(1, 2);
        const Point2f perm = Math::Permute(vec, 1, 0);
        EXPECT_FLOAT_EQ(perm.x, 2.0f);
        EXPECT_FLOAT_EQ(perm.y, 1.0f);
    }
    {
        const Point2d vec1(1, 2);
        const Point2d vec2(3, -2);
        const Point2d min = Min(vec1, vec2);
        const Point2d max = Max(vec1, vec2);

        EXPECT_DOUBLE_EQ(min.x, 1.0f);
        EXPECT_DOUBLE_EQ(min.y, -2.0f);
        EXPECT_DOUBLE_EQ(max.x, 3.0f);
        EXPECT_DOUBLE_EQ(max.y, 2.0f);

        const Point2f vec(1, 2);
        const Point2f perm = Math::Permute(vec, 1, 0);
        EXPECT_DOUBLE_EQ(perm.x, 2.0f);
        EXPECT_DOUBLE_EQ(perm.y, 1.0f);
    }
    {
        const Point2i vec1(1, 2);
        const Point2i vec2(3, -2);
        const Point2i min = Min(vec1, vec2);
        const Point2i max = Max(vec1, vec2);

        EXPECT_EQ(min.x, 1.0f);
        EXPECT_EQ(min.y, -2.0f);
        EXPECT_EQ(max.x, 3.0f);
        EXPECT_EQ(max.y, 2.0f);

        const Point2f vec(1, 2);
        const Point2f perm = Math::Permute(vec, 1, 0);
        EXPECT_EQ(perm.x, 2.0f);
        EXPECT_EQ(perm.y, 1.0f);
    }
}

TEST(Point2Tests, Floor)
{
    {
        const Point2f vec(1.1f, 2.2f);
        const Point2f floor = Math::Floor(vec);
        EXPECT_FLOAT_EQ(floor.x, 1.0f);
        EXPECT_FLOAT_EQ(floor.y, 2.0f);
    }
    {
        const Point2d vec(1.1, 2.2);
        const Point2d floor = Math::Floor(vec);
        EXPECT_DOUBLE_EQ(floor.x, 1.0);
        EXPECT_DOUBLE_EQ(floor.y, 2.0);
    }
    {
        const Point2i vec(1, 2);
        const Point2i floor = Math::Floor(vec);
        EXPECT_EQ(floor.x, 1);
        EXPECT_EQ(floor.y, 2);
    }
}

TEST(Point2Tests, Ceil)
{
    {
        const Point2f vec(1.1f, 2.2f);
        const Point2f ceil = Math::Ceil(vec);
        EXPECT_FLOAT_EQ(ceil.x, 2.0f);
        EXPECT_FLOAT_EQ(ceil.y, 3.0f);
    }
    {
        const Point2d vec(1.1, 2.2);
        const Point2d ceil = Math::Ceil(vec);
        EXPECT_DOUBLE_EQ(ceil.x, 2.0);
        EXPECT_DOUBLE_EQ(ceil.y, 3.0);
    }
    {
        const Point2i vec(1, 2);
        const Point2i ceil = Math::Ceil(vec);
        EXPECT_EQ(ceil.x, 1);
        EXPECT_EQ(ceil.y, 2);
    }
}

TEST(Point2Tests, Round)
{
    {
        const Point2f vec(1.1f, 3.5f);
        const Point2f round = Math::Round(vec);
        EXPECT_FLOAT_EQ(round.x, 1.0f);
        EXPECT_FLOAT_EQ(round.y, 4.0f);
    }
    {
        const Point2d vec(1.1, 3.5);
        const Point2d round = Math::Round(vec);
        EXPECT_DOUBLE_EQ(round.x, 1.0);
        EXPECT_DOUBLE_EQ(round.y, 4.0);
    }
    {
        const Point2i vec(1, 2);
        const Point2i round = Math::Round(vec);
        EXPECT_EQ(round.x, 1);
        EXPECT_EQ(round.y, 2);
    }
}
