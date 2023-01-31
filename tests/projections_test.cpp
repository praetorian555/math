#include "math/projections.h"
#include "math/transform.h"

#include "realexpect.h"

using Point3f = math::Point3;

TEST(ProjectionsTests, Orthographic_LH_N0)
{
    math::Matrix4x4 Mat = math::Orhographic_LH_N0(-500, 500, -200, 200, 0, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, 75));
        EXPECT_REAL_EQ(Res.X, 0.4f);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_REAL_EQ(Res.Z, 0.75f);
    }

    {
        Point3f Res = T(Point3f(-200, 100, -120));
        EXPECT_REAL_EQ(Res.X, -0.4f);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_REAL_EQ(Res.Z, -1.2f);
    }
}

TEST(ProjectionsTests, Orthographic_LH_N1)
{
    math::Matrix4x4 Mat = math::Orhographic_LH_N1(-500, 500, -200, 200, 0, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, 75));
        EXPECT_REAL_EQ(Res.X, 0.4f);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_REAL_EQ(Res.Z, 0.5f);
    }

    {
        Point3f Res = T(Point3f(-200, 100, -120));
        EXPECT_REAL_EQ(Res.X, -0.4f);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_REAL_EQ(Res.Z, -3.4f);
    }
}

TEST(ProjectionsTests, Orthographic_RH_N0)
{
    math::Matrix4x4 Mat = math::Orhographic_RH_N0(-500, 500, -200, 200, 0, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, -75));
        EXPECT_REAL_EQ(Res.X, 0.4f);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_REAL_EQ(Res.Z, 0.75f);
    }

    {
        Point3f Res = T(Point3f(-200, 100, 120));
        EXPECT_REAL_EQ(Res.X, -0.4f);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_REAL_EQ(Res.Z, -1.2f);
    }
}

TEST(ProjectionsTests, Orthographic_RH_N1)
{
    math::Matrix4x4 Mat = math::Orhographic_RH_N1(-500, 500, -200, 200, 0, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, -75));
        EXPECT_REAL_EQ(Res.X, 0.4f);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_REAL_EQ(Res.Z, 0.5f);
    }

    {
        Point3f Res = T(Point3f(-200, 100, 120));
        EXPECT_REAL_EQ(Res.X, -0.4f);
        EXPECT_REAL_EQ(Res.Y, 0.5f);
        EXPECT_REAL_EQ(Res.Z, -3.4f);
    }
}

TEST(ProjectionsTests, Perspective_LH_N0)
{
    math::Matrix4x4 Mat = math::Perspective_LH_N0(90, 1, 0.1f, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, 50));
        EXPECT_REAL_EQ(Res.X, 4);
        EXPECT_REAL_EQ(Res.Y, 2);
        EXPECT_GT(Res.Z, 0.1f);
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
    math::Matrix4x4 Mat = math::Perspective_LH_N1(90, 1, 0.1f, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, 0.15f));
        EXPECT_REAL_EQ(Res.X, 200 / 0.15f);
        EXPECT_REAL_EQ(Res.Y, 100 / 0.15f);
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
    math::Matrix4x4 Mat = math::Perspective_RH_N0(90, 1, 0.1f, 100);
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
    math::Matrix4x4 Mat = math::Perspective_RH_N1(90, 1, 0.1f, 100);
    math::Transform T(Mat);

    {
        Point3f Res = T(Point3f(200, 100, -0.15f));
        EXPECT_REAL_EQ(Res.X, 200 / 0.15f);
        EXPECT_REAL_EQ(Res.Y, 100 / 0.15f);
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
