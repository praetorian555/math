#include "math/projections.h"
#include "math/transform.h"

#include "realexpect.h"

using Point3f = math::Point3;

TEST(ProjectionsTests, Orthographic_LH_N0)
{
    Math::Matrix4x4<float> Mat = Math::Orthographic_LH_N0<float>(-500, 500, -200, 200, 0, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, 75));
        EXPECT_REAL_EQ(Res.X, MATH_REALC(0.4));
        EXPECT_REAL_EQ(Res.Y, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Res.Z, MATH_REALC(0.75));
    }

    {
        Point3f Res = T(Point3f(-200, 100, -120));
        EXPECT_REAL_EQ(Res.X, MATH_REALC(-0.4));
        EXPECT_REAL_EQ(Res.Y, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Res.Z, MATH_REALC(-1.2));
    }
}

TEST(ProjectionsTests, Orthographic_LH_N1)
{
    Math::Matrix4x4<float> Mat = Math::Orthographic_LH_N1<float>(-500, 500, -200, 200, 0, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, 75));
        EXPECT_REAL_EQ(Res.X, MATH_REALC(0.4));
        EXPECT_REAL_EQ(Res.Y, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Res.Z, MATH_REALC(0.5));
    }

    {
        Point3f Res = T(Point3f(-200, 100, -120));
        EXPECT_REAL_EQ(Res.X, MATH_REALC(-0.4));
        EXPECT_REAL_EQ(Res.Y, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Res.Z, MATH_REALC(-3.4));
    }
}

TEST(ProjectionsTests, Orthographic_RH_N0)
{
    Math::Matrix4x4<float> Mat = Math::Orthographic_RH_N0<float>(-500, 500, -200, 200, 0, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, -75));
        EXPECT_REAL_EQ(Res.X, MATH_REALC(0.4));
        EXPECT_REAL_EQ(Res.Y, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Res.Z, MATH_REALC(0.75));
    }

    {
        Point3f Res = T(Point3f(-200, 100, 120));
        EXPECT_REAL_EQ(Res.X, MATH_REALC(-0.4));
        EXPECT_REAL_EQ(Res.Y, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Res.Z, MATH_REALC(-1.2));
    }
}

TEST(ProjectionsTests, Orthographic_RH_N1)
{
    Math::Matrix4x4<float> Mat = Math::Orthographic_RH_N1<float>(-500, 500, -200, 200, 0, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, -75));
        EXPECT_REAL_EQ(Res.X, MATH_REALC(0.4));
        EXPECT_REAL_EQ(Res.Y, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Res.Z, MATH_REALC(0.5));
    }

    {
        Point3f Res = T(Point3f(-200, 100, 120));
        EXPECT_REAL_EQ(Res.X, MATH_REALC(-0.4));
        EXPECT_REAL_EQ(Res.Y, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Res.Z, MATH_REALC(-3.4));
    }
}

TEST(ProjectionsTests, Perspective_LH_N0)
{
    Math::Matrix4x4<float> Mat = Math::Perspective_LH_N0<float>(90, 1, 0.1f, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, 50));
        EXPECT_REAL_EQ(Res.X, 4);
        EXPECT_REAL_EQ(Res.Y, 2);
        EXPECT_GT(Res.Z, MATH_REALC(0.1));
        EXPECT_LT(Res.Z, 1.0f);
    }

    {
        Point3f Res = T(Point3f(-200, 100, 200));
        EXPECT_REAL_EQ(Res.X, -1);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_GT(Res.Z, 1.0f);
    }
}

TEST(ProjectionsTests, Perspective_LH_N1)
{
    Math::Matrix4x4<float> Mat = Math::Perspective_LH_N1<float>(90, 1, 0.1f, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, MATH_REALC(0.15)));
        EXPECT_REAL_EQ(Res.X, 200 / MATH_REALC(0.15));
        EXPECT_REAL_EQ(Res.Y, 100 / MATH_REALC(0.15));
        EXPECT_GT(Res.Z, -1.0f);
        EXPECT_LT(Res.Z, 0);
    }

    {
        Point3f Res = T(Point3f(-200, 100, 200));
        EXPECT_REAL_EQ(Res.X, -1);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_GT(Res.Z, 1.0f);
    }
}

TEST(ProjectionsTests, Perspective_RH_N0)
{
    Math::Matrix4x4<float> Mat = Math::Perspective_RH_N0<float>(90, 1, 0.1f, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, -50));
        EXPECT_REAL_EQ(Res.X, 4);
        EXPECT_REAL_EQ(Res.Y, 2);
        EXPECT_GT(Res.Z, 0.1f);
        EXPECT_LT(Res.Z, 1.0f);
    }

    {
        Point3f Res = T(Point3f(-200, 100, 50));
        EXPECT_REAL_EQ(Res.X, 4);
        EXPECT_REAL_EQ(Res.Y, -2);
        EXPECT_TRUE(Res.Z < 0 || Res.Z > 1);
    }

    {
        Point3f Res = T(Point3f(-200, 100, -200));
        EXPECT_REAL_EQ(Res.X, -1);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_TRUE(Res.Z < 0 || Res.Z > 1);
    }
}

TEST(ProjectionsTests, Perspective_RH_N1)
{
    Math::Matrix4x4<float> Mat = Math::Perspective_RH_N1<float>(90, 1, 0.1f, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, MATH_REALC(-0.15)));
        EXPECT_REAL_EQ(Res.X, 200 / MATH_REALC(0.15));
        EXPECT_REAL_EQ(Res.Y, 100 / MATH_REALC(0.15));
        EXPECT_GT(Res.Z, -1.0f);
        EXPECT_LT(Res.Z, 0);
    }

    {
        Point3f Res = T(Point3f(-200, 100, 200));
        EXPECT_REAL_EQ(Res.X, 1);
        EXPECT_REAL_EQ(Res.Y, -0.5f);
        EXPECT_TRUE(Res.Z < 0 || Res.Z > 1);
    }

    {
        Point3f Res = T(Point3f(-200, 100, -200));
        EXPECT_REAL_EQ(Res.X, -1);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_TRUE(Res.Z < 0 || Res.Z > 1);
    }
}
