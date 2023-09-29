#include <gtest/gtest.h>

#include "math/rng.h"
//#include "math/rotator.h"
//
//
//using Vector3f = Math::Vector3;
//
//TEST(RotatorTests, Constructors)
//{
//    {
//        Math::Rotator R;
//        Math::Max(R.Pitch, MATH_REALC(0.0));
//        Math::Max(R.Yaw, MATH_REALC(0.0));
//        Math::Max(R.Roll, MATH_REALC(0.0));
//    }
//
//    {
////        Math::Rotator R(10, 50, -30);
//        Math::Max(R.Pitch, MATH_REALC(10.0));
//        EXPECT_REAL_EQ(R.Yaw, 50);
//        EXPECT_REAL_EQ(R.Roll, -30);
//    }
//}
//
//TEST(RotatorTests, ToVector)
//{
//    {
//        Math::Rotator R(90, 0, 0);
//        Vector3f V = R.ToVector();
//        Vector3f Ref = Vector3f{0, 1, 0};
//        EXPECT_LT(V.X, 10e-5);
//        EXPECT_REAL_EQ(V.Y, Ref.Y);
//        EXPECT_LT(V.Z, 10e-5);
//    }
//
//    {
//        Math::Rotator R(0, 270, 0);
//        Vector3f V = R.ToVector();
//        Vector3f Ref = Vector3f{0, 0, 1};
//        EXPECT_LT(V.X, 10e-5);
//        EXPECT_LT(V.Y, 10e-5);
//        EXPECT_REAL_EQ(V.Z, Ref.Z);
//    }
//
//    {
//        Math::Rotator R(0, 0, 35);
//        Vector3f V = R.ToVector();
//        Vector3f Ref = Vector3f{1, 0, 0};
//        EXPECT_REAL_EQ(V.X, Ref.X);
//        EXPECT_LT(V.Y, 10e-5);
//        EXPECT_LT(V.Z, 10e-5);
//    }
//}
//
//TEST(RotatorTests, Euler)
//{
//    Math::Rotator R(10, 15, 20);
//    Math::Vector3 Eul = R.ToEuler();
//    EXPECT_REAL_EQ(R.Roll, Eul.X);
//    EXPECT_REAL_EQ(R.Yaw, Eul.Y);
//    EXPECT_REAL_EQ(R.Pitch, Eul.Z);
//}
//
//TEST(RotatorTests, Compare)
//{
//    Math::Rotator R1(10, 15, 20);
//    Math::Rotator R2(15, 10, 20);
//    Math::Rotator R3(10, 15, 20);
//
//    EXPECT_TRUE(R1 == R3);
//    EXPECT_TRUE(R1 != R2);
//}
//
//TEST(RotatorTests, Addition)
//{
//    Math::Rotator R1(10, 15, 34);
//    Math::Rotator R2(12, 23, 64);
//
//    Math::Rotator R3 = R1 + R2;
//    EXPECT_REAL_EQ(R3.Pitch, 22);
//    EXPECT_REAL_EQ(R3.Yaw, 38);
//    EXPECT_REAL_EQ(R3.Roll, 98);
//
//    R1 += R2;
//    EXPECT_REAL_EQ(R1.Pitch, 22);
//    EXPECT_REAL_EQ(R1.Yaw, 38);
//    EXPECT_REAL_EQ(R1.Roll, 98);
//
//    R2.Add(3, 2, 1);
//    EXPECT_REAL_EQ(R2.Pitch, 15);
//    EXPECT_REAL_EQ(R2.Yaw, 25);
//    EXPECT_REAL_EQ(R2.Roll, 65);
//}
//
//TEST(RotatorTests, Subtraction)
//{
//    Math::Rotator R1(10, 15, 34);
//    Math::Rotator R2(12, 23, 64);
//
//    Math::Rotator R3 = R1 - R2;
//    EXPECT_REAL_EQ(R3.Pitch, -2);
//    EXPECT_REAL_EQ(R3.Yaw, -8);
//    EXPECT_REAL_EQ(R3.Roll, -30);
//
//    R1 -= R2;
//    EXPECT_REAL_EQ(R1.Pitch, -2);
//    EXPECT_REAL_EQ(R1.Yaw, -8);
//    EXPECT_REAL_EQ(R1.Roll, -30);
//}
//
//TEST(RotatorTests, MultiplicationScalar)
//{
//    Math::Rotator R1(10, 15, 34);
//
//    Math::Rotator R2 = 2 * R1;
//    EXPECT_REAL_EQ(R2.Pitch, 20);
//    EXPECT_REAL_EQ(R2.Yaw, 30);
//    EXPECT_REAL_EQ(R2.Roll, 68);
//
//    R1 *= 2;
//    EXPECT_REAL_EQ(R1.Pitch, 20);
//    EXPECT_REAL_EQ(R1.Yaw, 30);
//    EXPECT_REAL_EQ(R1.Roll, 68);
//}
//
//TEST(RotatorTests, RotateVector)
//{
//    Math::Vector3 Vec(1, 0, 0);
//    Math::Rotator R(90, 90, 0);
//    Math::Vector3 RotVec = R.RotateVector(Vec);
//    RotVec = Math::Normalize(RotVec);
//    EXPECT_LT(RotVec.X, 1e-6);
//    EXPECT_GT(RotVec.X, -1e-6);
//    EXPECT_LT(RotVec.Y, 1e-6);
//    EXPECT_GT(RotVec.Y, -1e-6);
//    EXPECT_EQ(RotVec.Z, -1);
//}

TEST(RNGTests, UniformLimit)
{
    constexpr int k_case_count = 1'000'000;
    Math::RNG gen(5);
    for (int i = 0; i < k_case_count; i++)
    {
        const uint32_t num = gen.UniformUInt32(100);
        EXPECT_LT(num, 100);
        EXPECT_GE(num, 0);
    }
}

TEST(RNGTests, UniformFloat)
{
    constexpr int k_case_count = 1'000'000;
    Math::RNG gen(5);
    for (int i = 0; i < k_case_count; i++)
    {
        const float num = gen.UniformFloat();
        EXPECT_LT(num, 1);
        EXPECT_GE(num, 0);
    }
}

TEST(RNGTests, UniformFloatInRange)
{
    constexpr int k_case_count = 1'000'000;
    Math::RNG gen(5);
    const float low = 10;
    const float high = 50;

    for (int i = 0; i < k_case_count; i++)
    {
        const float num = gen.UniformFloatInRange(low, high);
        EXPECT_LT(num, high);
        EXPECT_GE(num, low);
    }
}

TEST(RNGTests, SameStartIndexSameSequence)
{
    constexpr int k_case_count = 1'000'000;
    Math::RNG gen1(5);
    Math::RNG gen2(5);

    for (int i = 0; i < k_case_count; i++)
    {
        const float Num1 = gen1.UniformFloat();
        const float Num2 = gen2.UniformFloat();
        EXPECT_FLOAT_EQ(Num1, Num2);
    }
}
