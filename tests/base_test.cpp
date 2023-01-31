#include "math/base.h"

#include "realexpect.h"

TEST(BaseTests, NaN)
{
    math::real a = 5;
    math::real b = MATH_REALC(10.2);
    math::real c = nanf("");
    EXPECT_FALSE(math::IsNaN(a));
    EXPECT_FALSE(math::IsNaN(b));
    EXPECT_TRUE(math::IsNaN(c));
}

TEST(BaseTests, Constants)
{
    EXPECT_REAL_EQ(math::kInfinity, std::numeric_limits<math::real>::infinity());
    EXPECT_REAL_EQ(math::kNegativeInfinity, -std::numeric_limits<math::real>::infinity());
    EXPECT_REAL_EQ(math::kSmallestFloat, std::numeric_limits<math::real>::lowest());
    EXPECT_REAL_EQ(math::kLargestFloat, std::numeric_limits<math::real>::max());
}

TEST(BaseTests, Clamp)
{
    const math::real V1 = math::Clamp(10, -2, 5);
    EXPECT_EQ(V1, 5);

    const math::real V2 = math::Clamp(-3, -2, 5);
    EXPECT_EQ(V2, -2);

    const math::real V3 = math::Clamp(0, -2, 5);
    EXPECT_EQ(V3, 0);

    const math::real V4 = math::Clamp(0, -2, -2);
    EXPECT_EQ(V4, -2);
}

TEST(BaseTests, Mod)
{
    math::real R1 = math::Mod(MATH_REALC(2.5), MATH_REALC(2.0));
    EXPECT_REAL_EQ(R1, 0.5f);
}

TEST(BaseTests, Lerp)
{
    math::real V1 = math::Lerp(MATH_REALC(0.5), 1, 4);
    EXPECT_REAL_EQ(V1, MATH_REALC(2.5));
}

TEST(BaseTests, Power2)
{
    EXPECT_TRUE(math::IsPowerOf2(4));
    EXPECT_TRUE(math::IsPowerOf2(128));
    EXPECT_FALSE(math::IsPowerOf2(125));
}

TEST(BaseTests, Radians)
{
    EXPECT_REAL_EQ(math::kPi, math::Radians(180));
    EXPECT_REAL_EQ(math::kPiOver2, math::Radians(90));
}

TEST(BaseTests, Degrees)
{
    EXPECT_REAL_EQ(180, math::Degrees(math::kPi));
    EXPECT_REAL_EQ(90, math::Degrees(math::kPiOver2));
}

TEST(BaseTests, Log2)
{
    EXPECT_REAL_EQ(math::Log2(128), 7);
    EXPECT_REAL_EQ(math::Log2(1024), 10);
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
