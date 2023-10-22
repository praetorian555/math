#include <gtest/gtest.h>

#include "math/vector2.h"

using Vec2f = Math::Vector2<float>;
using Vec2d = Math::Vector2<double>;
using Vec2i = Math::Vector2<int>;

TEST(Vector2Tests, Construction)
{
    {
        const Vec2f vec1(1, 2);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);

        const Vec2f vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
    }
    {
        const Vec2d vec1(1, 2);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);

        const Vec2d vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
    }
    {
        const Vec2i vec1(1, 2);
        EXPECT_EQ(vec1.x, 1);
        EXPECT_EQ(vec1.y, 2);

        const Vec2i vec2(1);
        EXPECT_EQ(vec2.x, 1);
        EXPECT_EQ(vec2.y, 1);
    }
}

TEST(Vector2Tests, ContainsNonFinite)
{
    {
        const Vec2f vec1(1, 2);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Vec2f vec2(1, std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Vec2f vec3(1, -std::numeric_limits<float>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Vec2f vec4(1, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Vec2f vec5(1, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Vec2d vec1(1, 2);
        EXPECT_FALSE(ContainsNonFinite(vec1));

        const Vec2d vec2(1, std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec2));

        const Vec2d vec3(1, -std::numeric_limits<double>::infinity());
        EXPECT_TRUE(ContainsNonFinite(vec3));

        const Vec2d vec4(1, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec4));

        const Vec2d vec5(1, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNonFinite(vec5));
    }
    {
        const Vec2d vec1(1, 2);
        EXPECT_FALSE(ContainsNonFinite(vec1));
    }
}

TEST(Vector2Tests, ContainsNaN)
{
    {
        const Vec2f vec1(1, 2);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Vec2f vec2(1, std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Vec2f vec3(1, -std::numeric_limits<float>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Vec2f vec4(1, std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Vec2f vec5(1, -std::numeric_limits<float>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Vec2d vec1(1, 2);
        EXPECT_FALSE(ContainsNaN(vec1));

        const Vec2d vec2(1, std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec2));

        const Vec2d vec3(1, -std::numeric_limits<double>::infinity());
        EXPECT_FALSE(ContainsNaN(vec3));

        const Vec2d vec4(1, std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec4));

        const Vec2d vec5(1, -std::numeric_limits<double>::quiet_NaN());
        EXPECT_TRUE(ContainsNaN(vec5));
    }
    {
        const Vec2d vec1(1, 2);
        EXPECT_FALSE(ContainsNaN(vec1));
    }
}

TEST(Vector2Tests, Comparisons)
{
    {
        const Vec2f vec1(1, 2);
        const Vec2f vec2(1, 2);
        const Vec2f vec3(1, 3);
        const Vec2f vec4(1, 4);
        const Vec2f vec5(1, 5);
        const Vec2f vec6(2, 6);

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
        const Vec2d vec1(1, 2);
        const Vec2d vec2(1, 2);
        const Vec2d vec3(1, 3);
        const Vec2d vec4(1, 4);
        const Vec2d vec5(1, 5);
        const Vec2d vec6(2, 6);

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
        const Vec2i vec1(1, 2);
        const Vec2i vec2(1, 2);
        const Vec2i vec3(1, 3);
        const Vec2i vec4(1, 4);
        const Vec2i vec5(1, 5);
        const Vec2i vec6(2, 6);

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

TEST(Vector2Tests, Addition)
{
    {
        const Vec2f vec1(1, 2);
        const Vec2f vec2(3, 4);

        Vec2f vec3 = vec1 + vec2;
        EXPECT_FLOAT_EQ(vec3.x, 4.0f);
        EXPECT_FLOAT_EQ(vec3.y, 6.0f);

        vec3 += vec1;
        EXPECT_FLOAT_EQ(vec3.x, 5.0f);
        EXPECT_FLOAT_EQ(vec3.y, 8.0f);
    }
    {
        const Vec2d vec1(1, 2);
        const Vec2d vec2(3, 4);

        Vec2d vec3 = vec1 + vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 4.0);
        EXPECT_DOUBLE_EQ(vec3.y, 6.0);

        vec3 += vec1;
        EXPECT_DOUBLE_EQ(vec3.x, 5.0);
        EXPECT_DOUBLE_EQ(vec3.y, 8.0);
    }
    {
        const Vec2i vec1(1, 2);
        const Vec2i vec2(3, 4);

        Vec2i vec3 = vec1 + vec2;
        EXPECT_EQ(vec3.x, 4);
        EXPECT_EQ(vec3.y, 6);

        vec3 += vec1;
        EXPECT_EQ(vec3.x, 5);
        EXPECT_EQ(vec3.y, 8);
    }
}

TEST(Vector2Tests, Subtraction)
{
    {
        const Vec2f vec1(1, 2);
        const Vec2f vec2(3, 4);

        Vec2f vec3 = vec2 - vec1;
        EXPECT_FLOAT_EQ(vec3.x, 2.0f);
        EXPECT_FLOAT_EQ(vec3.y, 2.0f);

        vec3 -= vec1;
        EXPECT_FLOAT_EQ(vec3.x, 1.0f);
        EXPECT_FLOAT_EQ(vec3.y, 0.0f);
    }
    {
        const Vec2d vec1(1, 2);
        const Vec2d vec2(3, 4);

        Vec2d vec3 = vec2 - vec1;
        EXPECT_DOUBLE_EQ(vec3.x, 2.0);
        EXPECT_DOUBLE_EQ(vec3.y, 2.0);

        vec3 -= vec1;
        EXPECT_DOUBLE_EQ(vec3.x, 1.0);
        EXPECT_DOUBLE_EQ(vec3.y, 0.0);
    }
    {
        const Vec2i vec1(1, 2);
        const Vec2i vec2(3, 4);

        Vec2i vec3 = vec2 - vec1;
        EXPECT_EQ(vec3.x, 2);
        EXPECT_EQ(vec3.y, 2);

        vec3 -= vec1;
        EXPECT_EQ(vec3.x, 1);
        EXPECT_EQ(vec3.y, 0);
    }
}

TEST(Vector2Tests, MultiplicationScalar)
{
    {
        const Vec2f vec1(1, 2);

        Vec2f vec2 = vec1 * 5.0f;

        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);

        vec2 *= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);

        const Vec2f vec3 = 2.0f * vec2;
        EXPECT_FLOAT_EQ(vec3.x, 20.0f);
        EXPECT_FLOAT_EQ(vec3.y, 40.0f);
    }
    {
        const Vec2d vec1(1, 2);

        Vec2d vec2 = vec1 * 5.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);

        vec2 *= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);

        const Vec2d vec3 = 2.0f * vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 20.0f);
        EXPECT_DOUBLE_EQ(vec3.y, 40.0f);
    }
    {
        const Vec2i vec1(1, 2);

        Vec2i vec2 = vec1 * 5.0f;

        EXPECT_EQ(vec2.x, 5.0f);
        EXPECT_EQ(vec2.y, 10.0f);

        vec2 *= 2.0f;
        EXPECT_EQ(vec2.x, 10.0f);
        EXPECT_EQ(vec2.y, 20.0f);

        const Vec2i vec3 = 2.0f * vec2;
        EXPECT_EQ(vec3.x, 20.0f);
        EXPECT_EQ(vec3.y, 40.0f);
    }
}

TEST(Vector2Tests, Multiplication)
{
    {
        const Vec2f vec1(1, 2);
        Vec2f vec2(2, 3);

        const Vec2f vec3 = vec1 * vec2;
        EXPECT_FLOAT_EQ(vec3.x, 2.0f);
        EXPECT_FLOAT_EQ(vec3.y, 6.0f);

        vec2 *= vec1;
        EXPECT_FLOAT_EQ(vec2.x, 2.0f);
        EXPECT_FLOAT_EQ(vec2.y, 6.0f);
    }
    {
        const Vec2d vec1(1, 2);
        Vec2d vec2(2, 3);

        const Vec2d vec3 = vec1 * vec2;
        EXPECT_DOUBLE_EQ(vec3.x, 2.0f);
        EXPECT_DOUBLE_EQ(vec3.y, 6.0f);

        vec2 *= vec1;
        EXPECT_DOUBLE_EQ(vec2.x, 2.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 6.0f);
    }
    {
        const Vec2i vec1(1, 2);
        Vec2i vec2(2, 3);

        const Vec2i vec3 = vec1 * vec2;
        EXPECT_EQ(vec3.x, 2.0f);
        EXPECT_EQ(vec3.y, 6.0f);

        vec2 *= vec1;
        EXPECT_EQ(vec2.x, 2.0f);
        EXPECT_EQ(vec2.y, 6.0f);
    }
}

TEST(Vector2Tests, DivisionScalar)
{
    {
        const Vec2f vec1(20.0f, 40.0f);

        Vec2f vec2 = vec1 / 2.0f;

        EXPECT_FLOAT_EQ(vec2.x, 10.0f);
        EXPECT_FLOAT_EQ(vec2.y, 20.0f);

        vec2 /= 2.0f;
        EXPECT_FLOAT_EQ(vec2.x, 5.0f);
        EXPECT_FLOAT_EQ(vec2.y, 10.0f);
    }
    {
        const Vec2d vec1(20.0f, 40.0f);

        Vec2d vec2 = vec1 / 2.0f;

        EXPECT_DOUBLE_EQ(vec2.x, 10.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 20.0f);

        vec2 /= 2.0f;
        EXPECT_DOUBLE_EQ(vec2.x, 5.0f);
        EXPECT_DOUBLE_EQ(vec2.y, 10.0f);
    }
    {
        const Vec2i vec1(20, 40);

        Vec2i vec2 = vec1 / 2.0f;

        EXPECT_EQ(vec2.x, 10.0f);
        EXPECT_EQ(vec2.y, 20.0f);

        vec2 /= 2.0f;
        EXPECT_EQ(vec2.x, 5.0f);
        EXPECT_EQ(vec2.y, 10.0f);
    }
}

TEST(Vector2Tests, Negation)
{
    {
        const Vec2f vec(5, -10);
        const Vec2f neg = -vec;

        EXPECT_FLOAT_EQ(neg.x, -5.0f);
        EXPECT_FLOAT_EQ(neg.y, 10.0f);
    }
    {
        const Vec2d vec(5, -10);
        const Vec2d neg = -vec;

        EXPECT_DOUBLE_EQ(neg.x, -5.0f);
        EXPECT_DOUBLE_EQ(neg.y, 10.0f);
    }
    {
        const Vec2i vec(5, -10);
        const Vec2i neg = -vec;

        EXPECT_EQ(neg.x, -5.0f);
        EXPECT_EQ(neg.y, 10.0f);
    }
}

TEST(Vector2Tests, Abs)
{
    {
        const Vec2f vec(5, -10);
        const Vec2f a = Math::Abs(vec);

        EXPECT_FLOAT_EQ(a.x, 5.0f);
        EXPECT_FLOAT_EQ(a.y, 10.0f);
    }
    {
        const Vec2d vec(5, -10);
        const Vec2d a = Math::Abs(vec);

        EXPECT_DOUBLE_EQ(a.x, 5.0f);
        EXPECT_DOUBLE_EQ(a.y, 10.0f);
    }
    {
        const Vec2i vec(5, -10);
        const Vec2i a = Math::Abs(vec);

        EXPECT_EQ(a.x, 5.0f);
        EXPECT_EQ(a.y, 10.0f);
    }
}

TEST(Vector2Tests, Length)
{
    {
        const Vec2f v1(3, 4);

        EXPECT_DOUBLE_EQ(Math::Length(v1), std::sqrt(25.0));
        EXPECT_FLOAT_EQ(Math::LengthSquared(v1), 25);
    }
    {
        const Vec2d v1(3, 4);

        EXPECT_DOUBLE_EQ(Math::Length(v1), std::sqrt(25.0));
        EXPECT_DOUBLE_EQ(Math::LengthSquared(v1), 25);
    }
    {
        const Vec2i v1(3, 4);

        EXPECT_DOUBLE_EQ(Math::Length(v1), std::sqrt(25.0));
        EXPECT_EQ(Math::LengthSquared(v1), 25);
    }
}

TEST(Vector2Tests, Lerp)
{
    {
        const Vec2f v1(1, 2);
        const Vec2f v2(3, 4);

        const Vec2f v3 = Math::Lerp(0.5f, v1, v2);
        EXPECT_FLOAT_EQ(v3.x, 2.0f);
        EXPECT_FLOAT_EQ(v3.y, 3.0f);
    }
    {
        const Vec2d v1(1, 2);
        const Vec2d v2(3, 4);

        const Vec2d v3 = Math::Lerp(0.5, v1, v2);
        EXPECT_DOUBLE_EQ(v3.x, 2.0f);
        EXPECT_DOUBLE_EQ(v3.y, 3.0f);
    }
}

TEST(Vector2Tests, Dot)
{
    {
        const Vec2f vec1(1, 2);
        const Vec2f vec2(3, 4);
        const Vec2f vec3(-3, -4);

        EXPECT_FLOAT_EQ(Dot(vec1, vec2), 11.0f);
        EXPECT_FLOAT_EQ(AbsDot(vec1, vec3), 11.0f);
    }
    {
        const Vec2d vec1(1, 2);
        const Vec2d vec2(3, 4);
        const Vec2d vec3(-3, -4);

        EXPECT_DOUBLE_EQ(Dot(vec1, vec2), 11.0f);
        EXPECT_DOUBLE_EQ(AbsDot(vec1, vec3), 11.0f);
    }
    {
        const Vec2i vec1(1, 2);
        const Vec2i vec2(3, 4);
        const Vec2i vec3(-3, -4);

        EXPECT_EQ(Dot(vec1, vec2), 11.0f);
        EXPECT_EQ(AbsDot(vec1, vec3), 11.0f);
    }
}

TEST(Vector2Tests, Cross)
{
    {
        const Vec2f x(1, 2);
        const Vec2f y(2, 1);

        const float c = Cross(x, y);
        EXPECT_TRUE(c == -3.0f);
    }
    {
        const Vec2d x(1, 2);
        const Vec2d y(2, 1);

        const double c = Cross(x, y);
        EXPECT_TRUE(c == -3.0);
    }
    {
        const Vec2i x(1, 2);
        const Vec2i y(2, 1);

        const int c = Cross(x, y);
        EXPECT_TRUE(c == -3);
    }
}

TEST(Vector2Tests, Normalize)
{
    {
        const Vec2f vec(2, 3);
        const Vec2f norm = Normalize(vec);
        EXPECT_TRUE(Math::IsEqual(Math::Length(norm), 1.0, 0.00001));
    }
    {
        const Vec2d vec(2, 3);
        const Vec2d norm = Normalize(vec);
        EXPECT_TRUE(Math::IsEqual(Math::Length(norm), 1.0, 0.00001));
    }
}

TEST(Vector2Tests, Misc)
{
    {
        const Vec2f vec1(1, 2);
        const Vec2f vec2(3, -2);
        const Vec2f min = Min(vec1, vec2);
        const Vec2f max = Max(vec1, vec2);

        EXPECT_FLOAT_EQ(min.x, 1.0f);
        EXPECT_FLOAT_EQ(min.y, -2.0f);
        EXPECT_FLOAT_EQ(max.x, 3.0f);
        EXPECT_FLOAT_EQ(max.y, 2.0f);

        const Vec2f vec(1, 2);
        const Vec2f perm = Math::Permute(vec, 1, 0);
        EXPECT_FLOAT_EQ(perm.x, 2.0f);
        EXPECT_FLOAT_EQ(perm.y, 1.0f);
    }
    {
        const Vec2d vec1(1, 2);
        const Vec2d vec2(3, -2);
        const Vec2d min = Min(vec1, vec2);
        const Vec2d max = Max(vec1, vec2);

        EXPECT_DOUBLE_EQ(min.x, 1.0f);
        EXPECT_DOUBLE_EQ(min.y, -2.0f);
        EXPECT_DOUBLE_EQ(max.x, 3.0f);
        EXPECT_DOUBLE_EQ(max.y, 2.0f);

        const Vec2f vec(1, 2);
        const Vec2f perm = Math::Permute(vec, 1, 0);
        EXPECT_DOUBLE_EQ(perm.x, 2.0f);
        EXPECT_DOUBLE_EQ(perm.y, 1.0f);
    }
    {
        const Vec2i vec1(1, 2);
        const Vec2i vec2(3, -2);
        const Vec2i min = Min(vec1, vec2);
        const Vec2i max = Max(vec1, vec2);

        EXPECT_EQ(min.x, 1.0f);
        EXPECT_EQ(min.y, -2.0f);
        EXPECT_EQ(max.x, 3.0f);
        EXPECT_EQ(max.y, 2.0f);

        const Vec2f vec(1, 2);
        const Vec2f perm = Math::Permute(vec, 1, 0);
        EXPECT_EQ(perm.x, 2.0f);
        EXPECT_EQ(perm.y, 1.0f);
    }
}

TEST(Vector2Tests, Clamp)
{
    {
        const Vec2f v1(2, -5);
        const Vec2f v2 = Math::Clamp(v1, 0.0f, 5.0f);
        EXPECT_FLOAT_EQ(v2.x, 2);
        EXPECT_FLOAT_EQ(v2.y, 0);
    }
    {
        const Vec2d v1(2, -5);
        const Vec2d v2 = Math::Clamp(v1, 0.0, 5.0);
        EXPECT_DOUBLE_EQ(v2.x, 2);
        EXPECT_DOUBLE_EQ(v2.y, 0);
    }
    {
        const Vec2i v1(2, -5);
        const Vec2i v2 = Math::Clamp(v1, 0, 5);
        EXPECT_EQ(v2.x, 2);
        EXPECT_EQ(v2.y, 0);
    }
}

TEST(Vector2Tests, Reflection)
{
    {
        const Vec2f incidence(1, 0);
        const Vec2f normal(0, 1);
        const Vec2f reflection = Math::Reflect(incidence, normal);
        EXPECT_FLOAT_EQ(reflection.x, -1.0f);
        EXPECT_FLOAT_EQ(reflection.y, 0.0f);
    }
    {
        const Vec2d incidence(1, 0);
        const Vec2d normal(0, 1);
        const Vec2d reflection = Math::Reflect(incidence, normal);
        EXPECT_DOUBLE_EQ(reflection.x, -1.0f);
        EXPECT_DOUBLE_EQ(reflection.y, 0.0f);
    }
}

TEST(Vector2Tests, IsEqual)
{
    {
        const Vec2f v1(1, 2);
        const Vec2f v2(2, 3);
        const Vec2f v3(0, 1);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0f));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0f));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5f));
    }
    {
        const Vec2d v1(1, 2);
        const Vec2d v2(2, 3);
        const Vec2d v3(0, 1);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0.5));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1.0));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2.0));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0.5));
    }
    {
        const Vec2i v1(1, 2);
        const Vec2i v2(2, 3);
        const Vec2i v3(0, 1);

        EXPECT_TRUE(Math::IsEqual(v1, v2, 1));
        EXPECT_TRUE(Math::IsEqual(v1, v2, 2));
        EXPECT_FALSE(Math::IsEqual(v1, v2, 0));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 1));
        EXPECT_TRUE(Math::IsEqual(v1, v3, 2));
        EXPECT_FALSE(Math::IsEqual(v1, v3, 0));
    }
}

TEST(Vector2Tests, MinAndMaxComponent)
{
    {
        const Vec2f v(1, 2);
        EXPECT_FLOAT_EQ(Math::MinComponent(v), 1);
        EXPECT_FLOAT_EQ(Math::MaxComponent(v), 2);
    }
    {
        const Vec2d v(1, 2);
        EXPECT_DOUBLE_EQ(Math::MinComponent(v), 1);
        EXPECT_DOUBLE_EQ(Math::MaxComponent(v), 2);
    }
    {
        const Vec2i v(1, 2);
        EXPECT_EQ(Math::MinComponent(v), 1);
        EXPECT_EQ(Math::MaxComponent(v), 2);
    }
}

TEST(Vector2Tests, MinAndMaxDimension)
{
    {
        const Vec2f v(1, 2);
        EXPECT_EQ(Math::MinDimension(v), 0);
        EXPECT_EQ(Math::MaxDimension(v), 1);
    }
    {
        const Vec2d v(1, 2);
        EXPECT_EQ(Math::MinDimension(v), 0);
        EXPECT_EQ(Math::MaxDimension(v), 1);
    }
    {
        const Vec2i v(1, 2);
        EXPECT_EQ(Math::MinDimension(v), 0);
        EXPECT_EQ(Math::MaxDimension(v), 1);
    }
}
