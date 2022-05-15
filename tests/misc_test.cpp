#include <gtest/gtest.h>

#include "math/rng.h"
#include "math/rotator.h"

using Vector3f = math::Vector3<float>;

TEST(RotatorTests, Constructors)
{
    {
        math::Rotator R;
        EXPECT_FLOAT_EQ(R.Pitch, 0);
        EXPECT_FLOAT_EQ(R.Yaw, 0);
        EXPECT_FLOAT_EQ(R.Roll, 0);
    }

    {
        math::Rotator R(10, 50, -30);
        EXPECT_FLOAT_EQ(R.Pitch, 10);
        EXPECT_FLOAT_EQ(R.Yaw, 50);
        EXPECT_FLOAT_EQ(R.Roll, -30);
    }
}

TEST(RotatorTests, ToVector)
{
    {
        math::Rotator R(90, 0, 0);
        Vector3f V = R.ToVector();
        Vector3f Ref = Vector3f{0, 1, 0};
        EXPECT_LT(V.X, 10e-5);
        EXPECT_FLOAT_EQ(V.Y, Ref.Y);
        EXPECT_LT(V.Z, 10e-5);
    }

    {
        math::Rotator R(0, 270, 0);
        Vector3f V = R.ToVector();
        Vector3f Ref = Vector3f{0, 0, 1};
        EXPECT_LT(V.X, 10e-5);
        EXPECT_LT(V.Y, 10e-5);
        EXPECT_FLOAT_EQ(V.Z, Ref.Z);
    }

    {
        math::Rotator R(0, 0, 35);
        Vector3f V = R.ToVector();
        Vector3f Ref = Vector3f{1, 0, 0};
        EXPECT_FLOAT_EQ(V.X, Ref.X);
        EXPECT_LT(V.Y, 10e-5);
        EXPECT_LT(V.Z, 10e-5);
    }
}

TEST(RotatorTests, Addition)
{
    math::Rotator R1(10, 15, 34);
    math::Rotator R2(12, 23, 64);

    math::Rotator R3 = R1 + R2;
    EXPECT_FLOAT_EQ(R3.Pitch, 22);
    EXPECT_FLOAT_EQ(R3.Yaw, 38);
    EXPECT_FLOAT_EQ(R3.Roll, 98);

    R1 += R2;
    EXPECT_FLOAT_EQ(R1.Pitch, 22);
    EXPECT_FLOAT_EQ(R1.Yaw, 38);
    EXPECT_FLOAT_EQ(R1.Roll, 98);
}

TEST(RotatorTests, MultiplicationScalar)
{
    math::Rotator R1(10, 15, 34);

    math::Rotator R2 = 2 * R1;
    EXPECT_FLOAT_EQ(R2.Pitch, 20);
    EXPECT_FLOAT_EQ(R2.Yaw, 30);
    EXPECT_FLOAT_EQ(R2.Roll, 68);

    R1 *= 2;
    EXPECT_FLOAT_EQ(R1.Pitch, 20);
    EXPECT_FLOAT_EQ(R1.Yaw, 30);
    EXPECT_FLOAT_EQ(R1.Roll, 68);
}

TEST(RNGTests, UniformLimit)
{
    constexpr int CASE_COUNT = 1'000'000;
    math::RNG Gen(5);

    for (int i = 0; i < CASE_COUNT; i++)
    {
        uint32_t Num = Gen.UniformUInt32(100);
        EXPECT_LT(Num, 100);
        EXPECT_GE(Num, 0);
    }
}

TEST(RNGTests, UniformReal)
{
    constexpr int CASE_COUNT = 1'000'000;
    math::RNG Gen(5);

    for (int i = 0; i < CASE_COUNT; i++)
    {
        float Num = Gen.UniformReal();
        EXPECT_LT(Num, 1);
        EXPECT_GE(Num, 0);
    }
}

TEST(RNGTests, UniformRealInRange)
{
    constexpr int CASE_COUNT = 1'000'000;
    math::RNG Gen(5);
    float Low = 10;
    float High = 50;

    for (int i = 0; i < CASE_COUNT; i++)
    {
        float Num = Gen.UniformRealInRange(Low, High);
        EXPECT_LT(Num, High);
        EXPECT_GE(Num, Low);
    }
}

TEST(RNGTests, SameStartIndexSameSequence)
{
    constexpr int CASE_COUNT = 1'000'000;
    math::RNG Gen1(5);
    math::RNG Gen2(5);

    for (int i = 0; i < CASE_COUNT; i++)
    {
        float Num1 = Gen1.UniformReal();
        float Num2 = Gen2.UniformReal();
        EXPECT_FLOAT_EQ(Num1, Num2);
    }
}
