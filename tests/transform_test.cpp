#include <gtest/gtest.h>

#include "math/transform.h"

using Vector3f = math::Vector3;

TEST(TransformTests, Creation)
{
    // clang-format off
    float init[4][4] = {
        1.0f, 4.0f, -4.0f, 5.0f,
        3.0f, -2.0f, 1.0f, 10.0f,
        7.0f, 10.0f, -5.0f, -3.0f,
       -6.0f, -2.0f, -1.0f, 9.0f
    };
    // clang-format on

    math::Matrix4x4 m1(init);

    math::Transform t1;
    math::Transform t2(init);
    math::Transform t3(m1);

    EXPECT_EQ(t1.GetMatrix(), math::Matrix4x4());
    EXPECT_EQ(t2.GetMatrix(), m1);
    EXPECT_EQ(t3.GetMatrix(), m1);
}

TEST(TransformTests, Inverse)
{
    math::Matrix4x4 m1;

    m1.Data[0][3] = 5.0f;
    m1.Data[1][3] = 10.0f;
    m1.Data[2][3] = -2.0f;

    math::Transform t1(m1);
    math::Transform t2 = Inverse(t1);

    EXPECT_FLOAT_EQ(t2.GetInverse().Data[0][3], 5.0f);
    EXPECT_FLOAT_EQ(t2.GetInverse().Data[1][3], 10.0f);
    EXPECT_FLOAT_EQ(t2.GetInverse().Data[2][3], -2.0f);

    EXPECT_FLOAT_EQ(t2.GetMatrix().Data[0][3], -5.0f);
    EXPECT_FLOAT_EQ(t2.GetMatrix().Data[1][3], -10.0f);
    EXPECT_FLOAT_EQ(t2.GetMatrix().Data[2][3], 2.0f);
}

TEST(TransformTests, Transpose)
{
    // clang-format off
    math::Matrix4x4 m1(
        1.0f, 4.0f, -4.0f, 5.0f,
        3.0f, -2.0f, 1.0f, 10.0f,
        7.0f, 10.0f, -5.0f, -3.0f,
       -6.0f, -2.0f, -1.0f, 9.0f
    );
    // clang-format on

    math::Transform t1(m1);
    math::Transform t2 = Transpose(t1);

    EXPECT_FLOAT_EQ(t2.GetMatrix().Data[0][0], 1.0f);
    EXPECT_FLOAT_EQ(t2.GetMatrix().Data[2][2], -5.0f);
    EXPECT_FLOAT_EQ(t2.GetMatrix().Data[2][3], -1.0f);
    EXPECT_FLOAT_EQ(t2.GetMatrix().Data[0][2], 7.0f);
    EXPECT_FLOAT_EQ(t2.GetMatrix().Data[1][3], -2.0f);
    EXPECT_FLOAT_EQ(t2.GetMatrix().Data[1][0], 4.0f);
}

TEST(TransformTests, Comparison)
{
    // clang-format off
    math::Matrix4x4 m1(
        1.0f, 4.0f, -4.0f, 5.0f,
        3.0f, -2.0f, 1.0f, 10.0f,
        7.0f, 10.0f, -5.0f, -3.0f,
       -6.0f, -2.0f, -1.0f, 9.0f
    );
    // clang-format on

    math::Transform t1;
    math::Transform t2(m1);
    math::Transform t3;

    EXPECT_EQ(t1, t3);
    EXPECT_NE(t2, t3);
    EXPECT_NE(t1, t2);
}

TEST(TransformTests, IsIdentity)
{
    // clang-format off
    math::Matrix4x4 m1(
        1.0f, 4.0f, -4.0f, 5.0f,
        3.0f, -2.0f, 1.0f, 10.0f,
        7.0f, 10.0f, -5.0f, -3.0f,
       -6.0f, -2.0f, -1.0f, 9.0f
    );
    // clang-format on

    math::Transform t1;
    math::Transform t2(m1);

    EXPECT_TRUE(t1.IsIdentity());
    EXPECT_FALSE(t2.IsIdentity());
}

TEST(TransformTests, HasScale)
{
    math::Matrix4x4 m;

    m.Data[0][0] = 3;
    m.Data[1][1] = 5;
    m.Data[2][2] = 7;

    math::Transform t1(m);
    math::Transform t2;

    EXPECT_TRUE(t1.HasScale());
    EXPECT_FALSE(t2.HasScale());
}

TEST(TransformTests, Translate)
{
    math::Transform t = math::Translate(Vector3f(2, 3, 5));

    EXPECT_FLOAT_EQ(t.GetMatrix().Data[0][3], 2);
    EXPECT_FLOAT_EQ(t.GetMatrix().Data[1][3], 3);
    EXPECT_FLOAT_EQ(t.GetMatrix().Data[2][3], 5);

    EXPECT_FLOAT_EQ(t.GetInverse().Data[0][3], -2);
    EXPECT_FLOAT_EQ(t.GetInverse().Data[1][3], -3);
    EXPECT_FLOAT_EQ(t.GetInverse().Data[2][3], -5);
}

TEST(TransformTests, Scale)
{
    math::Transform t = math::Scale(2, 3, 5);

    EXPECT_FLOAT_EQ(t.GetMatrix().Data[0][0], 2);
    EXPECT_FLOAT_EQ(t.GetMatrix().Data[1][1], 3);
    EXPECT_FLOAT_EQ(t.GetMatrix().Data[2][2], 5);

    EXPECT_FLOAT_EQ(t.GetInverse().Data[0][0], 1 / 2.0f);
    EXPECT_FLOAT_EQ(t.GetInverse().Data[1][1], 1 / 3.0f);
    EXPECT_FLOAT_EQ(t.GetInverse().Data[2][2], 1 / 5.0f);
}

TEST(TransformTests, Rotate)
{
    float degrees = 45.0f;
    float sinTheta = std::sin(math::Radians(degrees));
    float cosTheta = std::cos(math::Radians(degrees));

    math::Transform aroundX = math::RotateX(degrees);
    EXPECT_FLOAT_EQ(aroundX.GetMatrix().Data[1][1], cosTheta);
    EXPECT_FLOAT_EQ(aroundX.GetMatrix().Data[2][2], cosTheta);
    EXPECT_FLOAT_EQ(aroundX.GetMatrix().Data[1][2], -sinTheta);
    EXPECT_FLOAT_EQ(aroundX.GetMatrix().Data[2][1], sinTheta);

    math::Transform aroundY = math::RotateY(degrees);
    EXPECT_FLOAT_EQ(aroundY.GetMatrix().Data[0][0], cosTheta);
    EXPECT_FLOAT_EQ(aroundY.GetMatrix().Data[2][2], cosTheta);
    EXPECT_FLOAT_EQ(aroundY.GetMatrix().Data[0][2], sinTheta);
    EXPECT_FLOAT_EQ(aroundY.GetMatrix().Data[2][0], -sinTheta);

    math::Transform aroundZ = math::RotateZ(degrees);
    EXPECT_FLOAT_EQ(aroundZ.GetMatrix().Data[0][0], cosTheta);
    EXPECT_FLOAT_EQ(aroundZ.GetMatrix().Data[1][1], cosTheta);
    EXPECT_FLOAT_EQ(aroundZ.GetMatrix().Data[0][1], -sinTheta);
    EXPECT_FLOAT_EQ(aroundZ.GetMatrix().Data[1][0], sinTheta);

    math::Transform custom = math::Rotate(degrees, Vector3f(0, 0, 1));
    EXPECT_FLOAT_EQ(custom.GetMatrix().Data[0][0], cosTheta);
    EXPECT_FLOAT_EQ(custom.GetMatrix().Data[1][1], cosTheta);
    EXPECT_FLOAT_EQ(custom.GetMatrix().Data[0][1], -sinTheta);
    EXPECT_FLOAT_EQ(custom.GetMatrix().Data[1][0], sinTheta);
}
