#include <gtest/gtest.h>

#include "math/math.h"

TEST(Matrix4x4Tests, Creation)
{
    math::Matrix4x4 m1;

    EXPECT_FLOAT_EQ(m1.Data[0][0], 1.0f);
    EXPECT_FLOAT_EQ(m1.Data[2][2], 1.0f);
    EXPECT_FLOAT_EQ(m1.Data[2][3], 0.0f);
    EXPECT_FLOAT_EQ(m1.Data[0][2], 0.0f);
    EXPECT_FLOAT_EQ(m1.Data[1][3], 0.0f);
    EXPECT_FLOAT_EQ(m1.Data[1][0], 0.0f);

    // clang-format off
    math::Matrix4x4 m2(
        1.0f, 4.0f, -4.0f, 5.0f,
        3.0f, -2.0f, 1.0f, 10.0f,
        7.0f, 10.0f, -5.0f, -3.0f,
       -6.0f, -2.0f, -1.0f, 9.0f
    );
    // clang-format on

    EXPECT_FLOAT_EQ(m2.Data[0][0], 1.0f);
    EXPECT_FLOAT_EQ(m2.Data[2][2], -5.0f);
    EXPECT_FLOAT_EQ(m2.Data[2][3], -3.0f);
    EXPECT_FLOAT_EQ(m2.Data[0][2], -4.0f);
    EXPECT_FLOAT_EQ(m2.Data[1][3], 10.0f);
    EXPECT_FLOAT_EQ(m2.Data[1][0], 3.0f);

    // clang-format off
   const math::Array2D<float, 4, 4>& init = {
        1.0f, 4.0f, -4.0f, 5.0f,
        3.0f, -2.0f, 1.0f, 10.0f,
        7.0f, 10.0f, -5.0f, -3.0f,
       -6.0f, -2.0f, -1.0f, 9.0f
    };
    // clang-format on

    math::Matrix4x4 m3(init);

    EXPECT_FLOAT_EQ(m3.Data[0][0], 1.0f);
    EXPECT_FLOAT_EQ(m3.Data[2][2], -5.0f);
    EXPECT_FLOAT_EQ(m3.Data[2][3], -3.0f);
    EXPECT_FLOAT_EQ(m3.Data[0][2], -4.0f);
    EXPECT_FLOAT_EQ(m3.Data[1][3], 10.0f);
    EXPECT_FLOAT_EQ(m3.Data[1][0], 3.0f);
}

TEST(Matrix4x4Tests, Comparison)
{
    math::Matrix4x4 m1;

    // clang-format off
    math::Matrix4x4 m2(
        1.0f, 4.0f, -4.0f, 5.0f,
        3.0f, -2.0f, 1.0f, 10.0f,
        7.0f, 10.0f, -5.0f, -3.0f,
       -6.0f, -2.0f, -1.0f, 9.0f
    );
    // clang-format on

    // clang-format off
    const math::Array2D<float, 4, 4>& init  = {
        1.0f, 4.0f, -4.0f, 5.0f,
        3.0f, -2.0f, 1.0f, 10.0f,
        7.0f, 10.0f, -5.0f, -3.0f,
       -6.0f, -2.0f, -1.0f, 9.0f
    };
    // clang-format on

    math::Matrix4x4 m3(init);

    EXPECT_TRUE(m1 != m2);
    EXPECT_TRUE(m2 == m3);
}

TEST(Matrix4x4Tests, Transpose)
{
    // clang-format off
    math::Matrix4x4 m1(
        1.0f, 4.0f, -4.0f, 5.0f,
        3.0f, -2.0f, 1.0f, 10.0f,
        7.0f, 10.0f, -5.0f, -3.0f,
       -6.0f, -2.0f, -1.0f, 9.0f
    );
    // clang-format on

    math::Matrix4x4 m2 = m1.Transpose();

    EXPECT_FLOAT_EQ(m2.Data[0][0], 1.0f);
    EXPECT_FLOAT_EQ(m2.Data[2][2], -5.0f);
    EXPECT_FLOAT_EQ(m2.Data[2][3], -1.0f);
    EXPECT_FLOAT_EQ(m2.Data[0][2], 7.0f);
    EXPECT_FLOAT_EQ(m2.Data[1][3], -2.0f);
    EXPECT_FLOAT_EQ(m2.Data[1][0], 4.0f);
}

TEST(Matrix4x4Tests, Inverse)
{
    math::Matrix4x4 m1;

    m1.Data[0][3] = 5.0f;
    m1.Data[1][3] = 10.0f;
    m1.Data[2][3] = -2.0f;

    math::Matrix4x4 m2 = m1.Inverse();

    EXPECT_FLOAT_EQ(m2.Data[0][3], -5.0f);
    EXPECT_FLOAT_EQ(m2.Data[1][3], -10.0f);
    EXPECT_FLOAT_EQ(m2.Data[2][3], 2.0f);
}

TEST(Matrix4x4Tests, Multiply)
{
    math::Matrix4x4 m1;

    m1.Data[0][3] = 5.0f;
    m1.Data[1][3] = 10.0f;
    m1.Data[2][3] = -2.0f;

    math::Matrix4x4 m2;

    math::Matrix4x4 m3 = Multiply(m1, m2);

    EXPECT_FLOAT_EQ(m3.Data[0][3], 5.0f);
    EXPECT_FLOAT_EQ(m3.Data[1][3], 10.0f);
    EXPECT_FLOAT_EQ(m3.Data[2][3], -2.0f);
}
