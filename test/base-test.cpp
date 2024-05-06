#include <gtest/gtest.h>

#include "math/base.h"


TEST(BaseTests, Constants)
{
    EXPECT_FLOAT_EQ(Math::k_inf_float, std::numeric_limits<float>::infinity());
    EXPECT_FLOAT_EQ(Math::k_neg_inf_float, -std::numeric_limits<float>::infinity());
    EXPECT_FLOAT_EQ(Math::k_smallest_float, std::numeric_limits<float>::lowest());
    EXPECT_FLOAT_EQ(Math::k_largest_float, std::numeric_limits<float>::max());

    EXPECT_DOUBLE_EQ(Math::k_inf_double, std::numeric_limits<double>::infinity());
    EXPECT_DOUBLE_EQ(Math::k_neg_inf_double, -std::numeric_limits<double>::infinity());
    EXPECT_DOUBLE_EQ(Math::k_smallest_double, std::numeric_limits<double>::lowest());
    EXPECT_DOUBLE_EQ(Math::k_largest_double, std::numeric_limits<double>::max());
}

TEST(BaseTests, NaN)
{
    {
        const float a = 5;
        const float b = 10.2f;
        const float c = nanf("");
        EXPECT_FALSE(Math::IsNaN(a));
        EXPECT_FALSE(Math::IsNaN(b));
        EXPECT_TRUE(Math::IsNaN(c));
    }
    {
        const double a = 5;
        const double b = 10.2f;
        const double c = nanf("");
        EXPECT_FALSE(Math::IsNaN(a));
        EXPECT_FALSE(Math::IsNaN(b));
        EXPECT_TRUE(Math::IsNaN(c));
    }
    {
        const int a = 5;
        EXPECT_FALSE(Math::IsNaN(a));
    }
}

TEST(BaseTests, IsFinite)
{
    {
        const float a = 5;
        const float b = 10.2f;
        const float c = nanf("");
        EXPECT_TRUE(Math::IsFinite(a));
        EXPECT_TRUE(Math::IsFinite(b));
        EXPECT_FALSE(Math::IsFinite(c));
    }
    {
        const double a = 5;
        const double b = 10.2f;
        const double c = nanf("");
        EXPECT_TRUE(Math::IsFinite(a));
        EXPECT_TRUE(Math::IsFinite(b));
        EXPECT_FALSE(Math::IsFinite(c));
    }
}

TEST(BaseTests, Clamp)
{
    {
        const int V1 = Math::Clamp(10, -2, 5);
        EXPECT_EQ(V1, 5);
        const int V2 = Math::Clamp(-3, -2, 5);
        EXPECT_EQ(V2, -2);
        const int V3 = Math::Clamp(0, -2, 5);
        EXPECT_EQ(V3, 0);
        const int V4 = Math::Clamp(0, -2, -2);
        EXPECT_EQ(V4, -2);
    }
    {
        const float V1 = Math::Clamp(10.0f, -2.0f, 5.0f);
        EXPECT_FLOAT_EQ(V1, 5.0f);
        const float V2 = Math::Clamp(-3.0f, -2.0f, 5.0f);
        EXPECT_FLOAT_EQ(V2, -2.0f);
        const float V3 = Math::Clamp(0.0f, -2.0f, 5.0f);
        EXPECT_FLOAT_EQ(V3, 0);
        const float V4 = Math::Clamp(0.0f, -2.0f, -2.0f);
        EXPECT_FLOAT_EQ(V4, -2.0f);
    }
    {
        const double V1 = Math::Clamp(10.0, -2.0, 5.0);
        EXPECT_DOUBLE_EQ(V1, 5);
        const double V2 = Math::Clamp(-3.0, -2.0, 5.0);
        EXPECT_DOUBLE_EQ(V2, -2);
        const double V3 = Math::Clamp(0.0, -2.0, 5.0);
        EXPECT_DOUBLE_EQ(V3, 0);
        const double V4 = Math::Clamp(0.0, -2.0, -2.0);
        EXPECT_DOUBLE_EQ(V4, -2);
    }
}

TEST(BaseTests, Mod)
{
    {
        const float R1 = Math::Mod(2.5f, 2.0f);
        EXPECT_FLOAT_EQ(R1, 0.5f);
        const float R7 = Math::Mod(3.9f, 2.0f);
        EXPECT_FLOAT_EQ(R7, 1.9f);
        const float R2 = Math::Mod(-2.5f, 2.0f);
        EXPECT_FLOAT_EQ(R2, -0.5f);
        const float R3 = Math::Mod(2.5f, -2.0f);
        EXPECT_FLOAT_EQ(R3, 0.5f);
        const float R4 = Math::Mod(NAN, -2.0f);
        EXPECT_TRUE(Math::IsNaN(R4));
        const float R5 = Math::Mod(2.5f, NAN);
        EXPECT_TRUE(Math::IsNaN(R5));
        const float R6 = Math::Mod(2.5f, 0.0f);
        EXPECT_TRUE(Math::IsNaN(R6));
    }
    {
        const double R1 = Math::Mod(2.5, 2.0);
        EXPECT_DOUBLE_EQ(R1, 0.5);
        const double R7 = Math::Mod(3.9, 2.0);
        EXPECT_DOUBLE_EQ(R7, 1.9);
        const double R2 = Math::Mod(-2.5, 2.0);
        EXPECT_DOUBLE_EQ(R2, -0.5);
        const double R3 = Math::Mod(2.5, -2.0);
        EXPECT_DOUBLE_EQ(R3, 0.5);
        const double R4 = Math::Mod(static_cast<double>(NAN), -2.0);
        EXPECT_TRUE(Math::IsNaN(R4));
        const double R5 = Math::Mod(2.5, static_cast<double>(NAN));
        EXPECT_TRUE(Math::IsNaN(R5));
        const double R6 = Math::Mod(2.5, 0.0);
        EXPECT_TRUE(Math::IsNaN(R6));
    }
    {
        const int R1 = Math::Mod(3, 2);
        EXPECT_EQ(R1, 1);
        const int R2 = Math::Mod(-3, 2);
        EXPECT_EQ(R2, -1);
        const int R3 = Math::Mod(3, -2);
        EXPECT_EQ(R3, 1);
        const int R4 = Math::Mod(5, 3);
        EXPECT_EQ(R4, 2);
    }
}

TEST(BaseTests, Lerp)
{
    {
        const float R1 = Math::Lerp(0.0f, 1.0f, 5.0f);
        EXPECT_FLOAT_EQ(R1, 1.0f);
        const float R2 = Math::Lerp(0.0f, 1.0f, 0.0f);
        EXPECT_FLOAT_EQ(R2, 1.0f);
        const float R3 = Math::Lerp(0.5f, 1.0f, 5.0f);
        EXPECT_FLOAT_EQ(R3, 3.0f);
        const float R4 = Math::Lerp(1.0f, 1.0f, 0.0f);
        EXPECT_FLOAT_EQ(R4, 0.0f);
    }
    {
        const double R1 = Math::Lerp(0.0, 1.0, 5.0);
        EXPECT_DOUBLE_EQ(R1, 1.0);
        const double R2 = Math::Lerp(0.5, 1.0, 5.0);
        EXPECT_DOUBLE_EQ(R2, 3.0);
        const double R3 = Math::Lerp(0.0, 1.0, 0.0);
        EXPECT_DOUBLE_EQ(R3, 1.0);
        const double R4 = Math::Lerp(1.0, 1.0, 0.0);
        EXPECT_DOUBLE_EQ(R4, 0.0);
    }
}

TEST(BaseTests, Radians)
{
    {
        EXPECT_FLOAT_EQ(Math::k_pi_float, Math::Radians(180.0f));
        EXPECT_FLOAT_EQ(Math::k_pi_over_2_float, Math::Radians(90.0f));
    }
    {
        EXPECT_DOUBLE_EQ(Math::k_pi_double, Math::Radians(180.0));
        EXPECT_DOUBLE_EQ(Math::k_pi_over_2_double, Math::Radians(90.0));
    }
}

TEST(BaseTests, Degrees)
{
    {
        EXPECT_FLOAT_EQ(180.0f, Math::Degrees(Math::k_pi_float));
        EXPECT_FLOAT_EQ(90.0f, Math::Degrees(Math::k_pi_over_2_float));
    }
    {
        EXPECT_DOUBLE_EQ(180.0, Math::Degrees(Math::k_pi_double));
        EXPECT_DOUBLE_EQ(90.0, Math::Degrees(Math::k_pi_over_2_double));
    }
}

TEST(BaseTests, Min)
{
    {
        EXPECT_EQ(1, Math::Min(1, 2));
        EXPECT_EQ(1, Math::Min(2, 1));
    }
    {
        EXPECT_FLOAT_EQ(1.0f, Math::Min(1.0f, 2.0f));
        EXPECT_FLOAT_EQ(1.0f, Math::Min(2.0f, 1.0f));
    }
    {
        EXPECT_DOUBLE_EQ(1.0, Math::Min(1.0, 2.0));
        EXPECT_DOUBLE_EQ(1.0, Math::Min(2.0, 1.0));
    }
}

TEST(BaseTests, Max)
{
    {
        EXPECT_EQ(2, Math::Max(1, 2));
        EXPECT_EQ(2, Math::Max(2, 1));
    }
    {
        EXPECT_FLOAT_EQ(2.0f, Math::Max(1.0f, 2.0f));
        EXPECT_FLOAT_EQ(2.0f, Math::Max(2.0f, 1.0f));
    }
    {
        EXPECT_DOUBLE_EQ(2.0, Math::Max(1.0, 2.0));
        EXPECT_DOUBLE_EQ(2.0, Math::Max(2.0, 1.0));
    }
}

TEST(BaseTests, Round)
{
    {
        EXPECT_FLOAT_EQ(1, Math::Round(0.5f));
        EXPECT_FLOAT_EQ(2, Math::Round(1.5f));
        EXPECT_FLOAT_EQ(2, Math::Round(1.6f));
        EXPECT_FLOAT_EQ(3, Math::Round(2.5f));
        EXPECT_FLOAT_EQ(-3, Math::Round(-2.5f));
        EXPECT_FLOAT_EQ(3, Math::Round(2.6f));
    }
    {
        EXPECT_DOUBLE_EQ(1, Math::Round(0.5));
        EXPECT_DOUBLE_EQ(2, Math::Round(1.5));
        EXPECT_DOUBLE_EQ(2, Math::Round(1.6));
        EXPECT_DOUBLE_EQ(3, Math::Round(2.5));
        EXPECT_DOUBLE_EQ(-3, Math::Round(-2.5));
        EXPECT_DOUBLE_EQ(3, Math::Round(2.6));
    }
}

TEST(BaseTests, Floor)
{
    {
        EXPECT_FLOAT_EQ(1, Math::Floor(1.5f));
        EXPECT_FLOAT_EQ(-2, Math::Floor(-1.5f));
        EXPECT_FLOAT_EQ(2, Math::Floor(2.5f));
    }
    {
        EXPECT_DOUBLE_EQ(1, Math::Floor(1.5));
        EXPECT_DOUBLE_EQ(-2, Math::Floor(-1.5));
        EXPECT_DOUBLE_EQ(2, Math::Floor(2.5));
    }
}

TEST(BaseTests, Ceil)
{
    {
        EXPECT_FLOAT_EQ(2, Math::Ceil(1.5f));
        EXPECT_FLOAT_EQ(3, Math::Ceil(2.5f));
    }
    {
        EXPECT_DOUBLE_EQ(2, Math::Ceil(1.5));
        EXPECT_DOUBLE_EQ(3, Math::Ceil(2.5));
    }
}

TEST(BaseTests, Abs)
{
    {
        EXPECT_EQ(1, Math::Abs(-1));
        EXPECT_EQ(1, Math::Abs(1));
    }
    {
        EXPECT_FLOAT_EQ(1.0f, Math::Abs(-1.0f));
        EXPECT_FLOAT_EQ(1.0f, Math::Abs(1.0f));
    }
    {
        EXPECT_DOUBLE_EQ(1.0, Math::Abs(-1.0));
        EXPECT_DOUBLE_EQ(1.0, Math::Abs(1.0));
    }
}

TEST(BaseTests, Sqrt)
{
    {
        EXPECT_FLOAT_EQ(1.0f, Math::Sqrt(1.0f));
        EXPECT_FLOAT_EQ(2.0f, Math::Sqrt(4.0f));
    }
    {
        EXPECT_DOUBLE_EQ(1.0, Math::Sqrt(1.0));
        EXPECT_DOUBLE_EQ(2.0, Math::Sqrt(4.0));
    }
}

TEST(BaseTests, Trigonometry)
{
    {
        constexpr float k_epsilon = 1e-6f;
        EXPECT_FLOAT_EQ(0, Math::Sin(0.0f));
        EXPECT_FLOAT_EQ(1, Math::Sin(Math::k_pi_over_2_float));
        EXPECT_FLOAT_EQ(-1, Math::Sin(Math::k_pi_float + Math::k_pi_over_2_float));
        EXPECT_TRUE(Math::IsEqual(0.0f, Math::Sin(Math::k_pi_float), k_epsilon));
        EXPECT_TRUE(Math::IsEqual(0.0f, Math::Sin(Math::k_pi_float * 2), k_epsilon));

        EXPECT_FLOAT_EQ(1, Math::Cos(0.0f));
        EXPECT_FLOAT_EQ(1, Math::Cos(Math::k_pi_float * 2));
        EXPECT_FLOAT_EQ(-1, Math::Cos(Math::k_pi_float));
        EXPECT_TRUE(
            Math::IsEqual(0.0f, Math::Cos(Math::k_pi_float + Math::k_pi_over_2_float), k_epsilon));
        EXPECT_TRUE(Math::IsEqual(0.0f, Math::Cos(Math::k_pi_over_2_float), k_epsilon));

        EXPECT_FLOAT_EQ(0, Math::Tan(0.0f));
        EXPECT_FLOAT_EQ(1, Math::Tan(Math::k_pi_over_4_float));
        EXPECT_TRUE(
            Math::IsEqual(1.0f, Math::Tan(Math::k_pi_float + Math::k_pi_over_4_float), k_epsilon));
        EXPECT_TRUE(Math::IsEqual(0.0f, Math::Tan(Math::k_pi_float * 2), k_epsilon));
    }
    {
        constexpr double k_epsilon = 1e-15;
        EXPECT_DOUBLE_EQ(0, Math::Sin(0.0));
        EXPECT_DOUBLE_EQ(1, Math::Sin(Math::k_pi_over_2_double));
        EXPECT_DOUBLE_EQ(-1, Math::Sin(Math::k_pi_double + Math::k_pi_over_2_double));
        EXPECT_TRUE(Math::IsEqual(0.0, Math::Sin(Math::k_pi_double), k_epsilon));
        EXPECT_TRUE(Math::IsEqual(0.0, Math::Sin(Math::k_pi_double * 2), k_epsilon));

        EXPECT_DOUBLE_EQ(1, Math::Cos(0.0));
        EXPECT_DOUBLE_EQ(1, Math::Cos(Math::k_pi_double * 2));
        EXPECT_DOUBLE_EQ(-1, Math::Cos(Math::k_pi_double));
        EXPECT_TRUE(
            Math::IsEqual(0.0, Math::Cos(Math::k_pi_double + Math::k_pi_over_2_double), k_epsilon));
        EXPECT_TRUE(Math::IsEqual(0.0, Math::Cos(Math::k_pi_over_2_double), k_epsilon));

        EXPECT_DOUBLE_EQ(0, Math::Tan(0.0));
        EXPECT_DOUBLE_EQ(1, Math::Tan(Math::k_pi_over_4_double));
        EXPECT_TRUE(
            Math::IsEqual(1.0, Math::Tan(Math::k_pi_double + Math::k_pi_over_4_double), k_epsilon));
        EXPECT_TRUE(Math::IsEqual(0.0, Math::Tan(Math::k_pi_double * 2), k_epsilon));
    }
}

TEST(BaseTests, LogNatural)
{
    {
        EXPECT_FLOAT_EQ(Math::LogNatural(128.0f), 4.852030263919617f);
        EXPECT_FLOAT_EQ(Math::LogNatural(1024.0f), 6.931471805599453f);
        EXPECT_FLOAT_EQ(Math::LogNatural(1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::LogNatural(0.0f), -Math::k_inf_float);
        EXPECT_TRUE(Math::IsNaN(Math::LogNatural(-1.0f)));
        EXPECT_FLOAT_EQ(Math::LogNatural(Math::k_inf_float), Math::k_inf_float);
        EXPECT_TRUE(Math::IsNaN(Math::LogNatural(Math::k_neg_inf_float)));
        EXPECT_TRUE(Math::IsNaN(Math::LogNatural(NAN)));
    }
    {
        EXPECT_DOUBLE_EQ(Math::LogNatural(128.0), 4.852030263919617);
        EXPECT_DOUBLE_EQ(Math::LogNatural(1024.0), 6.931471805599453);
        EXPECT_DOUBLE_EQ(Math::LogNatural(1.0), 0.0);
        EXPECT_DOUBLE_EQ(Math::LogNatural(0.0), -Math::k_inf_double);
        EXPECT_TRUE(Math::IsNaN(Math::LogNatural(-1.0)));
        EXPECT_DOUBLE_EQ(Math::LogNatural(Math::k_inf_double), Math::k_inf_double);
        EXPECT_TRUE(Math::IsNaN(Math::LogNatural(Math::k_neg_inf_double)));
        EXPECT_TRUE(Math::IsNaN(Math::LogNatural(NAN)));
    }
}

TEST(BaseTests, Log2)
{
    {
        EXPECT_FLOAT_EQ(Math::Log2(128.0f), 7.0f);
        EXPECT_FLOAT_EQ(Math::Log2(1024.0f), 10.0f);
        EXPECT_FLOAT_EQ(Math::Log2(1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::Log2(0.0f), -Math::k_inf_float);
        EXPECT_TRUE(Math::IsNaN(Math::Log2(-1.0f)));
        EXPECT_FLOAT_EQ(Math::Log2(Math::k_inf_float), Math::k_inf_float);
        EXPECT_TRUE(Math::IsNaN(Math::Log2(Math::k_neg_inf_float)));
        EXPECT_TRUE(Math::IsNaN(Math::Log2(NAN)));
    }
    {
        EXPECT_DOUBLE_EQ(Math::Log2(128.0), 7.0);
        EXPECT_DOUBLE_EQ(Math::Log2(1024.0), 10.0);
        EXPECT_DOUBLE_EQ(Math::Log2(1.0), 0.0);
        EXPECT_DOUBLE_EQ(Math::Log2(0.0), -Math::k_inf_double);
        EXPECT_TRUE(Math::IsNaN(Math::Log2(-1.0)));
        EXPECT_DOUBLE_EQ(Math::Log2(Math::k_inf_double), Math::k_inf_double);
        EXPECT_TRUE(Math::IsNaN(Math::Log2(Math::k_neg_inf_double)));
        EXPECT_TRUE(Math::IsNaN(Math::Log2(NAN)));
    }
}

TEST(BaseTests, Power)
{
    {
        EXPECT_FLOAT_EQ(4, Math::Power(2.0f, 2.0f));
        EXPECT_FLOAT_EQ(8, Math::Power(2.0f, 3.0f));
    }
    {
        EXPECT_DOUBLE_EQ(4, Math::Power(2.0, 2.0));
        EXPECT_DOUBLE_EQ(8, Math::Power(2.0, 3.0));
    }
}

