#include <gtest/gtest.h>

#include "math/base.h"


TEST(BaseTests, Constants)
{
    EXPECT_FLOAT_EQ(math::k_inf_float, std::numeric_limits<float>::infinity());
    EXPECT_FLOAT_EQ(math::k_neg_inf_float, -std::numeric_limits<float>::infinity());
    EXPECT_FLOAT_EQ(math::k_smallest_float, std::numeric_limits<float>::lowest());
    EXPECT_FLOAT_EQ(math::k_largest_float, std::numeric_limits<float>::max());

    EXPECT_DOUBLE_EQ(math::k_inf_double, std::numeric_limits<double>::infinity());
    EXPECT_DOUBLE_EQ(math::k_neg_inf_double, -std::numeric_limits<double>::infinity());
    EXPECT_DOUBLE_EQ(math::k_smallest_double, std::numeric_limits<double>::lowest());
    EXPECT_DOUBLE_EQ(math::k_largest_double, std::numeric_limits<double>::max());
}

TEST(BaseTests, NaN)
{
    {
        const float a = 5;
        const float b = 10.2f;
        const float c = nanf("");
        EXPECT_FALSE(math::IsNaN(a));
        EXPECT_FALSE(math::IsNaN(b));
        EXPECT_TRUE(math::IsNaN(c));
    }
    {
        const double a = 5;
        const double b = 10.2f;
        const double c = nanf("");
        EXPECT_FALSE(math::IsNaN(a));
        EXPECT_FALSE(math::IsNaN(b));
        EXPECT_TRUE(math::IsNaN(c));
    }
    {
        const int a = 5;
        EXPECT_FALSE(math::IsNaN(a));
    }
}

TEST(BaseTests, Clamp)
{
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
    {
        const float V1 = math::Clamp(10.0f, -2.0f, 5.0f);
        EXPECT_FLOAT_EQ(V1, 5.0f);
        const float V2 = math::Clamp(-3.0f, -2.0f, 5.0f);
        EXPECT_FLOAT_EQ(V2, -2.0f);
        const float V3 = math::Clamp(0.0f, -2.0f, 5.0f);
        EXPECT_FLOAT_EQ(V3, 0);
        const float V4 = math::Clamp(0.0f, -2.0f, -2.0f);
        EXPECT_FLOAT_EQ(V4, -2.0f);
    }
    {
        const double V1 = math::Clamp(10.0, -2.0, 5.0);
        EXPECT_DOUBLE_EQ(V1, 5);
        const double V2 = math::Clamp(-3.0, -2.0, 5.0);
        EXPECT_DOUBLE_EQ(V2, -2);
        const double V3 = math::Clamp(0.0, -2.0, 5.0);
        EXPECT_DOUBLE_EQ(V3, 0);
        const double V4 = math::Clamp(0.0, -2.0, -2.0);
        EXPECT_DOUBLE_EQ(V4, -2);
    }
}

TEST(BaseTests, Mod)
{
    {
        const float R1 = math::Mod(2.5f, 2.0f);
        EXPECT_FLOAT_EQ(R1, 0.5f);
        const float R2 = math::Mod(-2.5f, 2.0f);
        EXPECT_FLOAT_EQ(R2, -0.5f);
        const float R3 = math::Mod(2.5f, -2.0f);
        EXPECT_FLOAT_EQ(R3, 0.5f);
        const float R4 = math::Mod(NAN, -2.0f);
        EXPECT_TRUE(math::IsNaN(R4));
        const float R5 = math::Mod(2.5f, NAN);
        EXPECT_TRUE(math::IsNaN(R5));
        const float R6 = math::Mod(2.5f, 0.0f);
        EXPECT_TRUE(math::IsNaN(R6));
    }
    {
        const double R1 = math::Mod(2.5, 2.0);
        EXPECT_DOUBLE_EQ(R1, 0.5);
        const double R2 = math::Mod(-2.5, 2.0);
        EXPECT_DOUBLE_EQ(R2, -0.5);
        const double R3 = math::Mod(2.5, -2.0);
        EXPECT_DOUBLE_EQ(R3, 0.5);
        const double R4 = math::Mod(static_cast<double>(NAN), -2.0);
        EXPECT_TRUE(math::IsNaN(R4));
        const double R5 = math::Mod(2.5, static_cast<double>(NAN));
        EXPECT_TRUE(math::IsNaN(R5));
        const double R6 = math::Mod(2.5, 0.0);
        EXPECT_TRUE(math::IsNaN(R6));
    }
    {
        const int R1 = math::Mod(3, 2);
        EXPECT_EQ(R1, 1);
        const int R2 = math::Mod(-3, 2);
        EXPECT_EQ(R2, -1);
        const int R3 = math::Mod(3, -2);
        EXPECT_EQ(R3, 1);
    }
}

TEST(BaseTests, Lerp)
{
    {
        const float R1 = math::Lerp(0.0f, 1.0f, 5.0f);
        EXPECT_FLOAT_EQ(R1, 1.0f);
        const float R2 = math::Lerp(0.0f, 1.0f, 0.0f);
        EXPECT_FLOAT_EQ(R2, 1.0f);
        const float R3 = math::Lerp(0.5f, 1.0f, 5.0f);
        EXPECT_FLOAT_EQ(R3, 3.0f);
        const float R4 = math::Lerp(1.0f, 1.0f, 0.0f);
        EXPECT_FLOAT_EQ(R4, 0.0f);
    }
    {
        const double R1 = math::Lerp(0.0, 1.0, 5.0);
        EXPECT_DOUBLE_EQ(R1, 1.0);
        const double R2 = math::Lerp(0.5, 1.0, 5.0);
        EXPECT_DOUBLE_EQ(R2, 3.0);
        const double R3 = math::Lerp(0.0, 1.0, 0.0);
        EXPECT_DOUBLE_EQ(R3, 1.0);
        const double R4 = math::Lerp(1.0, 1.0, 0.0);
        EXPECT_DOUBLE_EQ(R4, 0.0);
    }
}

TEST(BaseTests, Radians)
{
    {
        EXPECT_FLOAT_EQ(math::k_pi_float, math::Radians(180.0f));
        EXPECT_FLOAT_EQ(math::k_pi_over_2_float, math::Radians(90.0f));
    }
    {
        EXPECT_DOUBLE_EQ(math::k_pi_double, math::Radians(180.0));
        EXPECT_DOUBLE_EQ(math::k_pi_over_2_double, math::Radians(90.0));
    }
}

TEST(BaseTests, Degrees)
{
    {
        EXPECT_FLOAT_EQ(180.0f, math::Degrees(math::k_pi_float));
        EXPECT_FLOAT_EQ(90.0f, math::Degrees(math::k_pi_over_2_float));
    }
    {
        EXPECT_DOUBLE_EQ(180.0, math::Degrees(math::k_pi_double));
        EXPECT_DOUBLE_EQ(90.0, math::Degrees(math::k_pi_over_2_double));
    }
}

TEST(BaseTests, Min)
{
    {
        EXPECT_EQ(1, math::Min(1, 2));
        EXPECT_EQ(1, math::Min(2, 1));
    }
    {
        EXPECT_FLOAT_EQ(1.0f, math::Min(1.0f, 2.0f));
        EXPECT_FLOAT_EQ(1.0f, math::Min(2.0f, 1.0f));
    }
    {
        EXPECT_DOUBLE_EQ(1.0, math::Min(1.0, 2.0));
        EXPECT_DOUBLE_EQ(1.0, math::Min(2.0, 1.0));
    }
}

TEST(BaseTests, Max)
{
    {
        EXPECT_EQ(2, math::Max(1, 2));
        EXPECT_EQ(2, math::Max(2, 1));
    }
    {
        EXPECT_FLOAT_EQ(2.0f, math::Max(1.0f, 2.0f));
        EXPECT_FLOAT_EQ(2.0f, math::Max(2.0f, 1.0f));
    }
    {
        EXPECT_DOUBLE_EQ(2.0, math::Max(1.0, 2.0));
        EXPECT_DOUBLE_EQ(2.0, math::Max(2.0, 1.0));
    }
}

TEST(BaseTests, Round)
{
    {
        EXPECT_FLOAT_EQ(1, math::Round(0.5f));
        EXPECT_FLOAT_EQ(2, math::Round(1.5f));
        EXPECT_FLOAT_EQ(2, math::Round(1.6f));
        EXPECT_FLOAT_EQ(3, math::Round(2.5f));
        EXPECT_FLOAT_EQ(-3, math::Round(-2.5f));
        EXPECT_FLOAT_EQ(3, math::Round(2.6f));
    }
    {
        EXPECT_DOUBLE_EQ(1, math::Round(0.5));
        EXPECT_DOUBLE_EQ(2, math::Round(1.5));
        EXPECT_DOUBLE_EQ(2, math::Round(1.6));
        EXPECT_DOUBLE_EQ(3, math::Round(2.5));
        EXPECT_DOUBLE_EQ(-3, math::Round(-2.5));
        EXPECT_DOUBLE_EQ(3, math::Round(2.6));
    }
}

TEST(BaseTests, Floor)
{
    {
        EXPECT_FLOAT_EQ(1, math::Floor(1.5f));
        EXPECT_FLOAT_EQ(-2, math::Floor(-1.5f));
        EXPECT_FLOAT_EQ(2, math::Floor(2.5f));
    }
    {
        EXPECT_DOUBLE_EQ(1, math::Floor(1.5));
        EXPECT_DOUBLE_EQ(-2, math::Floor(-1.5));
        EXPECT_DOUBLE_EQ(2, math::Floor(2.5));
    }
}

TEST(BaseTests, Ceil)
{
    {
        EXPECT_FLOAT_EQ(2, math::Ceil(1.5f));
        EXPECT_FLOAT_EQ(3, math::Ceil(2.5f));
    }
    {
        EXPECT_DOUBLE_EQ(2, math::Ceil(1.5));
        EXPECT_DOUBLE_EQ(3, math::Ceil(2.5));
    }
}

TEST(BaseTests, Abs)
{
    {
        EXPECT_EQ(1, math::Abs(-1));
        EXPECT_EQ(1, math::Abs(1));
    }
    {
        EXPECT_FLOAT_EQ(1.0f, math::Abs(-1.0f));
        EXPECT_FLOAT_EQ(1.0f, math::Abs(1.0f));
    }
    {
        EXPECT_DOUBLE_EQ(1.0, math::Abs(-1.0));
        EXPECT_DOUBLE_EQ(1.0, math::Abs(1.0));
    }
}

TEST(BaseTests, Sqrt)
{
    {
        EXPECT_FLOAT_EQ(1.0f, math::Sqrt(1.0f));
        EXPECT_FLOAT_EQ(2.0f, math::Sqrt(4.0f));
    }
    {
        EXPECT_DOUBLE_EQ(1.0, math::Sqrt(1.0));
        EXPECT_DOUBLE_EQ(2.0, math::Sqrt(4.0));
    }
}

TEST(BaseTests, Trigonometry)
{
    {
        constexpr float k_epsilon = 1e-6f;
        EXPECT_FLOAT_EQ(0, math::Sin(0.0f));
        EXPECT_FLOAT_EQ(1, math::Sin(math::k_pi_over_2_float));
        EXPECT_FLOAT_EQ(-1, math::Sin(math::k_pi_float + math::k_pi_over_2_float));
        EXPECT_TRUE(math::IsEqual(0.0f, math::Sin(math::k_pi_float), k_epsilon));
        EXPECT_TRUE(math::IsEqual(0.0f, math::Sin(math::k_pi_float * 2), k_epsilon));

        EXPECT_FLOAT_EQ(1, math::Cos(0.0f));
        EXPECT_FLOAT_EQ(1, math::Cos(math::k_pi_float * 2));
        EXPECT_FLOAT_EQ(-1, math::Cos(math::k_pi_float));
        EXPECT_TRUE(
            math::IsEqual(0.0f, math::Cos(math::k_pi_float + math::k_pi_over_2_float), k_epsilon));
        EXPECT_TRUE(math::IsEqual(0.0f, math::Cos(math::k_pi_over_2_float), k_epsilon));

        EXPECT_FLOAT_EQ(0, math::Tan(0.0f));
        EXPECT_FLOAT_EQ(1, math::Tan(math::k_pi_over_4_float));
        EXPECT_TRUE(
            math::IsEqual(1.0f, math::Tan(math::k_pi_float + math::k_pi_over_4_float), k_epsilon));
        EXPECT_TRUE(math::IsEqual(0.0f, math::Tan(math::k_pi_float * 2), k_epsilon));
    }
    {
        constexpr double k_epsilon = 1e-15;
        EXPECT_DOUBLE_EQ(0, math::Sin(0.0));
        EXPECT_DOUBLE_EQ(1, math::Sin(math::k_pi_over_2_double));
        EXPECT_DOUBLE_EQ(-1, math::Sin(math::k_pi_double + math::k_pi_over_2_double));
        EXPECT_TRUE(math::IsEqual(0.0, math::Sin(math::k_pi_double), k_epsilon));
        EXPECT_TRUE(math::IsEqual(0.0, math::Sin(math::k_pi_double * 2), k_epsilon));

        EXPECT_DOUBLE_EQ(1, math::Cos(0.0));
        EXPECT_DOUBLE_EQ(1, math::Cos(math::k_pi_double * 2));
        EXPECT_DOUBLE_EQ(-1, math::Cos(math::k_pi_double));
        EXPECT_TRUE(
            math::IsEqual(0.0, math::Cos(math::k_pi_double + math::k_pi_over_2_double), k_epsilon));
        EXPECT_TRUE(math::IsEqual(0.0, math::Cos(math::k_pi_over_2_double), k_epsilon));

        EXPECT_DOUBLE_EQ(0, math::Tan(0.0));
        EXPECT_DOUBLE_EQ(1, math::Tan(math::k_pi_over_4_double));
        EXPECT_TRUE(
            math::IsEqual(1.0, math::Tan(math::k_pi_double + math::k_pi_over_4_double), k_epsilon));
        EXPECT_TRUE(math::IsEqual(0.0, math::Tan(math::k_pi_double * 2), k_epsilon));
    }
}

TEST(BaseTests, LogNatural)
{
    {
        EXPECT_FLOAT_EQ(math::LogNatural(128.0f), 4.852030263919617f);
        EXPECT_FLOAT_EQ(math::LogNatural(1024.0f), 6.931471805599453f);
        EXPECT_FLOAT_EQ(math::LogNatural(1.0f), 0.0f);
        EXPECT_FLOAT_EQ(math::LogNatural(0.0f), -math::k_inf_float);
        EXPECT_TRUE(math::IsNaN(math::LogNatural(-1.0f)));
        EXPECT_FLOAT_EQ(math::LogNatural(math::k_inf_float), math::k_inf_float);
        EXPECT_TRUE(math::IsNaN(math::LogNatural(math::k_neg_inf_float)));
        EXPECT_TRUE(math::IsNaN(math::LogNatural(NAN)));
    }
    {
        EXPECT_DOUBLE_EQ(math::LogNatural(128.0), 4.852030263919617);
        EXPECT_DOUBLE_EQ(math::LogNatural(1024.0), 6.931471805599453);
        EXPECT_DOUBLE_EQ(math::LogNatural(1.0), 0.0);
        EXPECT_DOUBLE_EQ(math::LogNatural(0.0), -math::k_inf_double);
        EXPECT_TRUE(math::IsNaN(math::LogNatural(-1.0)));
        EXPECT_DOUBLE_EQ(math::LogNatural(math::k_inf_double), math::k_inf_double);
        EXPECT_TRUE(math::IsNaN(math::LogNatural(math::k_neg_inf_double)));
        EXPECT_TRUE(math::IsNaN(math::LogNatural(NAN)));
    }
}

TEST(BaseTests, Log2)
{
    {
        EXPECT_FLOAT_EQ(math::Log2(128.0f), 7.0f);
        EXPECT_FLOAT_EQ(math::Log2(1024.0f), 10.0f);
        EXPECT_FLOAT_EQ(math::Log2(1.0f), 0.0f);
        EXPECT_FLOAT_EQ(math::Log2(0.0f), -math::k_inf_float);
        EXPECT_TRUE(math::IsNaN(math::Log2(-1.0f)));
        EXPECT_FLOAT_EQ(math::Log2(math::k_inf_float), math::k_inf_float);
        EXPECT_TRUE(math::IsNaN(math::Log2(math::k_neg_inf_float)));
        EXPECT_TRUE(math::IsNaN(math::Log2(NAN)));
    }
    {
        EXPECT_DOUBLE_EQ(math::Log2(128.0), 7.0);
        EXPECT_DOUBLE_EQ(math::Log2(1024.0), 10.0);
        EXPECT_DOUBLE_EQ(math::Log2(1.0), 0.0);
        EXPECT_DOUBLE_EQ(math::Log2(0.0), -math::k_inf_double);
        EXPECT_TRUE(math::IsNaN(math::Log2(-1.0)));
        EXPECT_DOUBLE_EQ(math::Log2(math::k_inf_double), math::k_inf_double);
        EXPECT_TRUE(math::IsNaN(math::Log2(math::k_neg_inf_double)));
        EXPECT_TRUE(math::IsNaN(math::Log2(NAN)));
    }
}

TEST(BaseTests, Power)
{
    {
        EXPECT_FLOAT_EQ(4, math::Power(2.0f, 2.0f));
        EXPECT_FLOAT_EQ(8, math::Power(2.0f, 3.0f));
    }
    {
        EXPECT_DOUBLE_EQ(4, math::Power(2.0, 2.0));
        EXPECT_DOUBLE_EQ(8, math::Power(2.0, 3.0));
    }
}

