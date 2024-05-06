#include <gtest/gtest.h>

#include "math/rng.h"
#include "math/rotator.h"

using Rotf = Math::Rotator<float>;
using Vector3f = Math::Vector3<float>;
using Rotd = Math::Rotator<double>;
using Vector3d = Math::Vector3<double>;

TEST(RotatorTests, Constructors)
{
    {
        const Rotf rot1 = Rotf::Zero();
        EXPECT_FLOAT_EQ(rot1.pitch, 0.0f);
        EXPECT_FLOAT_EQ(rot1.yaw, 0.0f);
        EXPECT_FLOAT_EQ(rot1.roll, 0.0f);
        const Rotf rot2(10, 50, -30);
        EXPECT_FLOAT_EQ(rot2.pitch, 10.0f);
        EXPECT_FLOAT_EQ(rot2.yaw, 50.0f);
        EXPECT_FLOAT_EQ(rot2.roll, -30.0f);
    }
    {
        const Rotd rot1 = Rotd::Zero();
        EXPECT_DOUBLE_EQ(rot1.pitch, 0.0);
        EXPECT_DOUBLE_EQ(rot1.yaw, 0.0);
        EXPECT_DOUBLE_EQ(rot1.roll, 0.0);
        const Rotd rot2(10, 50, -30);
        EXPECT_DOUBLE_EQ(rot2.pitch, 10.0);
        EXPECT_DOUBLE_EQ(rot2.yaw, 50.0);
        EXPECT_DOUBLE_EQ(rot2.roll, -30.0);
    }
}

TEST(RotatorTests, Compare)
{
    {
        const Rotf rot1(10, 15, 20);
        const Rotf rot2(15, 10, 20);
        const Rotf rot3(10, 15, 20);
        EXPECT_TRUE(rot1 == rot3);
        EXPECT_TRUE(rot1 != rot2);
    }
    {
        const Rotd rot1(10, 15, 20);
        const Rotd rot2(15, 10, 20);
        const Rotd rot3(10, 15, 20);
        EXPECT_TRUE(rot1 == rot3);
        EXPECT_TRUE(rot1 != rot2);
    }
}

TEST(RotatorTests, Addition)
{
    {
        Rotf rot1(10, 15, 34);
        const Rotf rot2(12, 23, 64);

        const Rotf rot3 = rot1 + rot2;
        EXPECT_FLOAT_EQ(rot3.pitch, 22);
        EXPECT_FLOAT_EQ(rot3.yaw, 38);
        EXPECT_FLOAT_EQ(rot3.roll, 98);

        rot1 += rot2;
        EXPECT_FLOAT_EQ(rot1.pitch, 22);
        EXPECT_FLOAT_EQ(rot1.yaw, 38);
        EXPECT_FLOAT_EQ(rot1.roll, 98);
    }
    {
        Rotd rot1(10, 15, 34);
        const Rotd rot2(12, 23, 64);

        const Rotd rot3 = rot1 + rot2;
        EXPECT_DOUBLE_EQ(rot3.pitch, 22);
        EXPECT_DOUBLE_EQ(rot3.yaw, 38);
        EXPECT_DOUBLE_EQ(rot3.roll, 98);

        rot1 += rot2;
        EXPECT_DOUBLE_EQ(rot1.pitch, 22);
        EXPECT_DOUBLE_EQ(rot1.yaw, 38);
        EXPECT_DOUBLE_EQ(rot1.roll, 98);
    }
}

TEST(RotatorTests, Subtraction)
{
    {
        Rotf rot1(10, 15, 34);
        const Rotf rot2(12, 23, 64);

        const Rotf rot3 = rot1 - rot2;
        EXPECT_FLOAT_EQ(rot3.pitch, -2);
        EXPECT_FLOAT_EQ(rot3.yaw, -8);
        EXPECT_FLOAT_EQ(rot3.roll, -30);

        rot1 -= rot2;
        EXPECT_FLOAT_EQ(rot1.pitch, -2);
        EXPECT_FLOAT_EQ(rot1.yaw, -8);
        EXPECT_FLOAT_EQ(rot1.roll, -30);
    }
    {
        Rotd rot1(10, 15, 34);
        const Rotd rot2(12, 23, 64);

        const Rotd rot3 = rot1 - rot2;
        EXPECT_DOUBLE_EQ(rot3.pitch, -2);
        EXPECT_DOUBLE_EQ(rot3.yaw, -8);
        EXPECT_DOUBLE_EQ(rot3.roll, -30);

        rot1 -= rot2;
        EXPECT_DOUBLE_EQ(rot1.pitch, -2);
        EXPECT_DOUBLE_EQ(rot1.yaw, -8);
        EXPECT_DOUBLE_EQ(rot1.roll, -30);
    }
}

TEST(RotatorTests, MultiplicationScalar)
{
    {
        Rotf rot1(10, 15, 34);

        const Rotf rot2 = 2.0f * rot1;
        EXPECT_FLOAT_EQ(rot2.pitch, 20);
        EXPECT_FLOAT_EQ(rot2.yaw, 30);
        EXPECT_FLOAT_EQ(rot2.roll, 68);

        rot1 *= 2;
        EXPECT_FLOAT_EQ(rot1.pitch, 20);
        EXPECT_FLOAT_EQ(rot1.yaw, 30);
        EXPECT_FLOAT_EQ(rot1.roll, 68);
    }
    {
        Rotd rot1(10, 15, 34);

        const Rotd rot2 = 2.0 * rot1;
        EXPECT_DOUBLE_EQ(rot2.pitch, 20);
        EXPECT_DOUBLE_EQ(rot2.yaw, 30);
        EXPECT_DOUBLE_EQ(rot2.roll, 68);

        rot1 *= 2;
        EXPECT_DOUBLE_EQ(rot1.pitch, 20);
        EXPECT_DOUBLE_EQ(rot1.yaw, 30);
        EXPECT_DOUBLE_EQ(rot1.roll, 68);
    }
}

TEST(RotatorTests, ToVector)
{
    {
        const Rotf rot1(90, 0, 0);
        const Vector3f vec1 = Math::RotatorToVector(rot1);
        const Vector3f ref1 = Vector3f{0, 1, 0};
        EXPECT_TRUE(Math::IsEqual(vec1.x, ref1.x, 0.00001f));
        EXPECT_TRUE(Math::IsEqual(vec1.y, ref1.y, 0.00001f));
        EXPECT_TRUE(Math::IsEqual(vec1.z, ref1.z, 0.00001f));

        const Rotf rot2(0, 270, 0);
        const Vector3f vec2 = Math::RotatorToVector(rot2);
        const Vector3f ref2 = Vector3f{0, 0, 1};
        EXPECT_TRUE(Math::IsEqual(vec2.x, ref2.x, 0.00001f));
        EXPECT_TRUE(Math::IsEqual(vec2.y, ref2.y, 0.00001f));
        EXPECT_TRUE(Math::IsEqual(vec2.z, ref2.z, 0.00001f));

        const Rotf rot3(0, 0, 35);
        const Vector3f vec3 = Math::RotatorToVector(rot3);
        const Vector3f ref3 = Vector3f{1, 0, 0};
        EXPECT_TRUE(Math::IsEqual(vec3.x, ref3.x, 0.00001f));
        EXPECT_TRUE(Math::IsEqual(vec3.y, ref3.y, 0.00001f));
        EXPECT_TRUE(Math::IsEqual(vec3.z, ref3.z, 0.00001f));
    }
    {
        const Rotd rot1(90, 0, 0);
        const Vector3d vec1 = Math::RotatorToVector(rot1);
        const Vector3d ref1 = Vector3d{0, 1, 0};
        EXPECT_TRUE(Math::IsEqual(vec1.x, ref1.x, 0.00001));
        EXPECT_TRUE(Math::IsEqual(vec1.y, ref1.y, 0.00001));
        EXPECT_TRUE(Math::IsEqual(vec1.z, ref1.z, 0.00001));

        const Rotd rot2(0, 270, 0);
        const Vector3d vec2 = Math::RotatorToVector(rot2);
        const Vector3d ref2 = Vector3d{0, 0, 1};
        EXPECT_TRUE(Math::IsEqual(vec2.x, ref2.x, 0.00001));
        EXPECT_TRUE(Math::IsEqual(vec2.y, ref2.y, 0.00001));
        EXPECT_TRUE(Math::IsEqual(vec2.z, ref2.z, 0.00001));

        const Rotd rot3(0, 0, 35);
        const Vector3d vec3 = Math::RotatorToVector(rot3);
        const Vector3d ref3 = Vector3d{1, 0, 0};
        EXPECT_TRUE(Math::IsEqual(vec3.x, ref3.x, 0.00001));
        EXPECT_TRUE(Math::IsEqual(vec3.y, ref3.y, 0.00001));
        EXPECT_TRUE(Math::IsEqual(vec3.z, ref3.z, 0.00001));
    }
}

TEST(RotatorTests, Euler)
{
    {
        const Rotf rot(10, 15, 20);
        const Vector3f euler = Math::RotatorToEuler(rot);
        EXPECT_FLOAT_EQ(rot.roll, euler.x);
        EXPECT_FLOAT_EQ(rot.yaw, euler.y);
        EXPECT_FLOAT_EQ(rot.pitch, euler.z);
    }
    {
        const Rotd rot(10, 15, 20);
        Vector3d euler = Math::RotatorToEuler(rot);
        EXPECT_DOUBLE_EQ(rot.roll, euler.x);
        EXPECT_DOUBLE_EQ(rot.yaw, euler.y);
        EXPECT_DOUBLE_EQ(rot.pitch, euler.z);
    }
}

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
