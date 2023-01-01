#include <gtest/gtest.h>

#include "math/base.h"

TEST(BaseTests, NaN)
{
    float a = 5.0f;
    float b = 10.2f;
    float c = nanf("");
    EXPECT_FALSE(math::IsNaN(a));
    EXPECT_FALSE(math::IsNaN(b));
    EXPECT_TRUE(math::IsNaN(c));
}

TEST(BaseTests, Constants)
{
    EXPECT_FLOAT_EQ(math::kInfinity, std::numeric_limits<float>::infinity());
    EXPECT_FLOAT_EQ(math::kNegativeInfinity, -std::numeric_limits<float>::infinity());
    EXPECT_FLOAT_EQ(math::kSmallestFloat, std::numeric_limits<float>::lowest());
    EXPECT_FLOAT_EQ(math::kLargestFloat, std::numeric_limits<float>::max());
}

TEST(BaseTests, Clamp)
{
    const float V1 = math::Clamp(10, -2, 5);
    EXPECT_EQ(V1, 5);

    const float V2 = math::Clamp(-3, -2, 5);
    EXPECT_EQ(V2, -2);

    const float V3 = math::Clamp(0, -2, 5);
    EXPECT_EQ(V3, 0);

    const float V4 = math::Clamp(0, -2, -2);
    EXPECT_EQ(V4, -2);
}

TEST(BaseTests, Mod)
{
    float R1 = math::Mod(2.5f, 2.0f);
    EXPECT_FLOAT_EQ(R1, 0.5f);
}

TEST(BaseTests, Lerp)
{
    float V1 = math::Lerp(0.5f, 1, 4);
    EXPECT_FLOAT_EQ(V1, 2.5);
}

TEST(BaseTests, Power2)
{
    EXPECT_TRUE(math::IsPowerOf2(4));
    EXPECT_TRUE(math::IsPowerOf2(128));
    EXPECT_FALSE(math::IsPowerOf2(125));
}

TEST(BaseTests, Radians)
{
    EXPECT_FLOAT_EQ(math::kPi, math::Radians(180));
    EXPECT_FLOAT_EQ(math::kPiOver2, math::Radians(90));
}

TEST(BaseTests, Degrees)
{
    EXPECT_FLOAT_EQ(180, math::Degrees(math::kPi));
    EXPECT_FLOAT_EQ(90, math::Degrees(math::kPiOver2));
}

TEST(BaseTests, Log2)
{
    EXPECT_FLOAT_EQ(math::Log2(128), 7);
    EXPECT_FLOAT_EQ(math::Log2(1024), 10);
}

TEST(BaseTests, Log2Int)
{
    EXPECT_EQ(math::Log2Int(128), 7);
    EXPECT_EQ(math::Log2Int(1024), 10);
}

TEST(BaseTests, RoundUpPow2)
{
    EXPECT_EQ(128, math::RoundUpPow2(98));
}

TEST(BaseTests, TrailingZeros)
{
    EXPECT_EQ(29, math::CountTrailingZeros(8));
}
