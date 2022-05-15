#include <gtest/gtest.h>

#include "math/base.h"

TEST(BaseTests, NaN)
{
    int a = 5;
    float b = 10.2;
    float c = nanf("");
    EXPECT_FALSE(math::IsNaN(a));
    EXPECT_FALSE(math::IsNaN(b));
    EXPECT_TRUE(math::IsNaN(c));
}

TEST(BaseTests, Clamp)
{
    const int V1 = math::Clamp(10, -2, 5);
    EXPECT_EQ(V1, 5);

    const int V2 = math::Clamp(-3, -2, 5);
    EXPECT_EQ(V2, -2);

    const int V3 = math::Clamp(0, -2, 5);
    EXPECT_EQ(V3, 0);

    const int V4 = math::Clamp(0, -2, -2);
    EXPECT_EQ(V4, -2);
}

TEST(BaseTests, Mod)
{
    float R1 = math::Mod(2.5f, 2.0f);
    EXPECT_FLOAT_EQ(R1, 0.5f);

    double R2 = math::Mod(2.5, 2.0);
    EXPECT_FLOAT_EQ(R2, 0.5);

    int R3 = math::Mod(3, 2);
    EXPECT_EQ(R3, 1);
}

TEST(BaseTests, Lerp)
{
    float V1 = math::Lerp(0.5, 1, 4);
    EXPECT_FLOAT_EQ(V1, 2.5);
}

TEST(BaseTests, Power2)
{
    EXPECT_TRUE(math::IsPowerOf2(4));
    EXPECT_TRUE(math::IsPowerOf2(128));
    EXPECT_FALSE(math::IsPowerOf2(125));
    EXPECT_FALSE(math::IsPowerOf2(2.5));
    EXPECT_FALSE(math::IsPowerOf2(10.5f));
}

TEST(BaseTests, Radians)
{
    EXPECT_FLOAT_EQ(math::Pi, math::Radians(180));
    EXPECT_FLOAT_EQ(math::PiOver2, math::Radians(90));
}

TEST(BaseTests, Degrees)
{
    EXPECT_FLOAT_EQ(180, math::Degrees(math::Pi));
    EXPECT_FLOAT_EQ(90, math::Degrees(math::PiOver2));
}

TEST(BaseTests, Log2)
{
    EXPECT_FLOAT_EQ(math::Log2(128), 7);
    EXPECT_FLOAT_EQ(math::Log2(1024), 10);
}

TEST(BaseTests, Log2Int)
{
    EXPECT_FLOAT_EQ(math::Log2Int(128), 7);
    EXPECT_FLOAT_EQ(math::Log2Int(1024), 10);
}

TEST(BaseTests, RoundUpPow2)
{
    EXPECT_EQ(128, math::RoundUpPow2(98));
}

TEST(BaseTests, TrailingZeros)
{
    EXPECT_EQ(29, math::CountTrailingZeros(8));
}
