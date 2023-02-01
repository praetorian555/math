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
    EXPECT_REAL_EQ(math::kSmallestReal, std::numeric_limits<math::real>::lowest());
    EXPECT_REAL_EQ(math::kLargestReal, std::numeric_limits<math::real>::max());
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
    math::real R2 = math::Mod(MATH_REALC(-2.5), MATH_REALC(2.0));
    EXPECT_REAL_EQ(R2, -0.5f);
    math::real R3 = math::Mod(MATH_REALC(2.5), MATH_REALC(-2.0));
    EXPECT_REAL_EQ(R3, 0.5f);
    math::real R4 = math::Mod(NAN, MATH_REALC(-2.0));
    EXPECT_TRUE(math::IsNaN(R4));
    math::real R5 = math::Mod(MATH_REALC(2.5), NAN);
    EXPECT_TRUE(math::IsNaN(R5));
    math::real R6 = math::Mod(MATH_REALC(2.5), MATH_REALC(0.0));
    EXPECT_TRUE(math::IsNaN(R6));
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

TEST(BaseTests, LogNatural)
{
    EXPECT_REAL_EQ(math::LogNatural(128), MATH_REALC(4.852030263919617));
    EXPECT_REAL_EQ(math::LogNatural(1024), MATH_REALC(6.931471805599453));
    EXPECT_REAL_EQ(math::LogNatural(1), MATH_REALC(0.0));
    EXPECT_REAL_EQ(math::LogNatural(0), -math::kInfinity);
    EXPECT_TRUE(math::IsNaN(math::LogNatural(-1)));
    EXPECT_REAL_EQ(math::LogNatural(math::kInfinity), math::kInfinity);
    EXPECT_TRUE(math::IsNaN(math::LogNatural(math::kNegativeInfinity)));
    EXPECT_TRUE(math::IsNaN(math::LogNatural(NAN)));
}

TEST(BaseTests, Log2)
{
    EXPECT_REAL_EQ(math::Log2(128), MATH_REALC(7.0));
    EXPECT_REAL_EQ(math::Log2(1024), MATH_REALC(10.0));
    EXPECT_REAL_EQ(math::Log2(1), MATH_REALC(0.0));
    EXPECT_REAL_EQ(math::Log2(0), -math::kInfinity);
    EXPECT_TRUE(math::IsNaN(math::Log2(-1)));
    EXPECT_REAL_EQ(math::Log2(math::kInfinity), math::kInfinity);
    EXPECT_TRUE(math::IsNaN(math::Log2(math::kNegativeInfinity)));
    EXPECT_TRUE(math::IsNaN(math::Log2(NAN)));
}

TEST(BaseTests, Log2Int)
{
    EXPECT_EQ(math::Log2Int(128), 7);
    EXPECT_EQ(math::Log2Int(1024), 10);
    EXPECT_EQ(math::Log2Int(1), 0);
}

TEST(BaseTests, RoundUpPow2)
{
    EXPECT_EQ(128, math::RoundUpPow2(98));
}

TEST(BaseTests, TrailingZeros)
{
    EXPECT_EQ(28, math::CountTrailingZeros(8));
}

TEST(BaseTests, Min)
{
    EXPECT_EQ(1, math::Min(1, 2));
    EXPECT_EQ(1, math::Min(2, 1));
}

TEST(BaseTests, Max)
{
    EXPECT_EQ(2, math::Max(1, 2));
    EXPECT_EQ(2, math::Max(2, 1));
}

TEST(BaseTests, Round)
{
    EXPECT_EQ(1, math::Round(MATH_REALC(0.5)));
    EXPECT_EQ(2, math::Round(MATH_REALC(1.5)));
    EXPECT_EQ(2, math::Round(MATH_REALC(1.6)));
    EXPECT_EQ(3, math::Round(MATH_REALC(2.5)));
    EXPECT_EQ(-3, math::Round(MATH_REALC(-2.5)));
    EXPECT_EQ(3, math::Round(MATH_REALC(2.6)));
}

TEST(BaseTests, Floor)
{
    EXPECT_EQ(1, math::Floor(MATH_REALC(1.5)));
    EXPECT_EQ(-2, math::Floor(MATH_REALC(-1.5)));
    EXPECT_EQ(2, math::Floor(MATH_REALC(2.5)));
}

TEST(BaseTests, Ceil)
{
    EXPECT_EQ(2, math::Ceil(MATH_REALC(1.5)));
    EXPECT_EQ(3, math::Ceil(MATH_REALC(2.5)));
}

TEST(BaseTests, Abs)
{
    EXPECT_EQ(1, math::Abs(-1));
    EXPECT_EQ(1, math::Abs(1));
}

TEST(BaseTests, Sqrt)
{
    EXPECT_REAL_EQ(2, math::Sqrt(4));
    EXPECT_REAL_EQ(3, math::Sqrt(9));
}

TEST(BaseTests, Power)
{
    EXPECT_REAL_EQ(4, math::Power(2, 2));
    EXPECT_REAL_EQ(8, math::Power(2, 3));
}
