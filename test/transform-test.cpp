#include <gtest/gtest.h>

#include "math/transform.h"
#include "math/normal3.h"

using Vector3f = Math::Vector3<float>;
using Vector3d = Math::Vector3<double>;
using Vector3i = Math::Vector3<int>;
using Vector4f = Math::Vector4<float>;
using Vector4d = Math::Vector4<double>;
using Point3f = Math::Point3<float>;
using Point3d = Math::Point3<double>;
using Point3i = Math::Point3<int>;
using Point4f = Math::Point4<float>;
using Point4d = Math::Point4<double>;
using Matrix4f = Math::Matrix4x4<float>;
using Matrix4d = Math::Matrix4x4<double>;
using Matrix4i = Math::Matrix4x4<int>;
using Quatf = Math::Quaternion<float>;
using Quatd = Math::Quaternion<double>;
using Rotf = Math::Rotator<float>;
using Rotd = Math::Rotator<double>;
using Normal3f = Math::Normal3<float>;
using Normal3d = Math::Normal3<double>;

TEST(TransformTests, Identity)
{
    {
        const Matrix4f m = Math::Identity<float>();
        EXPECT_FLOAT_EQ(m.elements[0][0], 1.0f);
        EXPECT_FLOAT_EQ(m.elements[0][1], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[0][2], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[0][3], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[1][0], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[1][1], 1.0f);
        EXPECT_FLOAT_EQ(m.elements[1][2], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[1][3], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[2][0], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[2][1], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[2][2], 1.0f);
        EXPECT_FLOAT_EQ(m.elements[2][3], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(m.elements[3][3], 1.0f);
    }
    {
        const Matrix4d m = Math::Identity<double>();
        EXPECT_DOUBLE_EQ(m.elements[0][0], 1.0);
        EXPECT_DOUBLE_EQ(m.elements[0][1], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[0][2], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[0][3], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[1][0], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[1][1], 1.0);
        EXPECT_DOUBLE_EQ(m.elements[1][2], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[1][3], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[2][0], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[2][1], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[2][2], 1.0);
        EXPECT_DOUBLE_EQ(m.elements[2][3], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[3][0], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[3][1], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[3][2], 0.0);
        EXPECT_DOUBLE_EQ(m.elements[3][3], 1.0);
    }
    {
        const Matrix4i m = Math::Identity<int>();
        EXPECT_EQ(m.elements[0][0], 1);
        EXPECT_EQ(m.elements[0][1], 0);
        EXPECT_EQ(m.elements[0][2], 0);
        EXPECT_EQ(m.elements[0][3], 0);
        EXPECT_EQ(m.elements[1][0], 0);
        EXPECT_EQ(m.elements[1][1], 1);
        EXPECT_EQ(m.elements[1][2], 0);
        EXPECT_EQ(m.elements[1][3], 0);
        EXPECT_EQ(m.elements[2][0], 0);
        EXPECT_EQ(m.elements[2][1], 0);
        EXPECT_EQ(m.elements[2][2], 1);
        EXPECT_EQ(m.elements[2][3], 0);
        EXPECT_EQ(m.elements[3][0], 0);
        EXPECT_EQ(m.elements[3][1], 0);
        EXPECT_EQ(m.elements[3][2], 0);
        EXPECT_EQ(m.elements[3][3], 1);
    }
}

TEST(TransformTests, Translate)
{
    {
        const Matrix4f t1 = Math::Translate(Vector3f(2, 3, 5));
        EXPECT_FLOAT_EQ(t1.elements[0][0], 1.0f);
        EXPECT_FLOAT_EQ(t1.elements[0][1], 0.0f);
        EXPECT_FLOAT_EQ(t1.elements[0][2], 0.0f);
        EXPECT_FLOAT_EQ(t1.elements[0][3], 2.0f);
        EXPECT_FLOAT_EQ(t1.elements[1][0], 0.0f);
        EXPECT_FLOAT_EQ(t1.elements[1][1], 1.0f);
        EXPECT_FLOAT_EQ(t1.elements[1][2], 0.0f);
        EXPECT_FLOAT_EQ(t1.elements[1][3], 3.0f);
        EXPECT_FLOAT_EQ(t1.elements[2][0], 0.0f);
        EXPECT_FLOAT_EQ(t1.elements[2][1], 0.0f);
        EXPECT_FLOAT_EQ(t1.elements[2][2], 1.0f);
        EXPECT_FLOAT_EQ(t1.elements[2][3], 5.0f);
        EXPECT_FLOAT_EQ(t1.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(t1.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(t1.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(t1.elements[3][3], 1.0f);

        const Matrix4f t2 = Math::Translate(Point3f(2, 3, 5));
        EXPECT_FLOAT_EQ(t2.elements[0][0], 1.0f);
        EXPECT_FLOAT_EQ(t2.elements[0][1], 0.0f);
        EXPECT_FLOAT_EQ(t2.elements[0][2], 0.0f);
        EXPECT_FLOAT_EQ(t2.elements[0][3], 2.0f);
        EXPECT_FLOAT_EQ(t2.elements[1][0], 0.0f);
        EXPECT_FLOAT_EQ(t2.elements[1][1], 1.0f);
        EXPECT_FLOAT_EQ(t2.elements[1][2], 0.0f);
        EXPECT_FLOAT_EQ(t2.elements[1][3], 3.0f);
        EXPECT_FLOAT_EQ(t2.elements[2][0], 0.0f);
        EXPECT_FLOAT_EQ(t2.elements[2][1], 0.0f);
        EXPECT_FLOAT_EQ(t2.elements[2][2], 1.0f);
        EXPECT_FLOAT_EQ(t2.elements[2][3], 5.0f);
        EXPECT_FLOAT_EQ(t2.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(t2.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(t2.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(t2.elements[3][3], 1.0f);
    }
    {
        const Matrix4d t1 = Math::Translate(Vector3d(2, 3, 5));
        EXPECT_DOUBLE_EQ(t1.elements[0][0], 1.0);
        EXPECT_DOUBLE_EQ(t1.elements[0][1], 0.0);
        EXPECT_DOUBLE_EQ(t1.elements[0][2], 0.0);
        EXPECT_DOUBLE_EQ(t1.elements[0][3], 2.0);
        EXPECT_DOUBLE_EQ(t1.elements[1][0], 0.0);
        EXPECT_DOUBLE_EQ(t1.elements[1][1], 1.0);
        EXPECT_DOUBLE_EQ(t1.elements[1][2], 0.0);
        EXPECT_DOUBLE_EQ(t1.elements[1][3], 3.0);
        EXPECT_DOUBLE_EQ(t1.elements[2][0], 0.0);
        EXPECT_DOUBLE_EQ(t1.elements[2][1], 0.0);
        EXPECT_DOUBLE_EQ(t1.elements[2][2], 1.0);
        EXPECT_DOUBLE_EQ(t1.elements[2][3], 5.0);
        EXPECT_DOUBLE_EQ(t1.elements[3][0], 0.0);
        EXPECT_DOUBLE_EQ(t1.elements[3][1], 0.0);
        EXPECT_DOUBLE_EQ(t1.elements[3][2], 0.0);
        EXPECT_DOUBLE_EQ(t1.elements[3][3], 1.0);

        const Matrix4d t2 = Math::Translate(Point3d(2, 3, 5));
        EXPECT_DOUBLE_EQ(t2.elements[0][0], 1.0);
        EXPECT_DOUBLE_EQ(t2.elements[0][1], 0.0);
        EXPECT_DOUBLE_EQ(t2.elements[0][2], 0.0);
        EXPECT_DOUBLE_EQ(t2.elements[0][3], 2.0);
        EXPECT_DOUBLE_EQ(t2.elements[1][0], 0.0);
        EXPECT_DOUBLE_EQ(t2.elements[1][1], 1.0);
        EXPECT_DOUBLE_EQ(t2.elements[1][2], 0.0);
        EXPECT_DOUBLE_EQ(t2.elements[1][3], 3.0);
        EXPECT_DOUBLE_EQ(t2.elements[2][0], 0.0);
        EXPECT_DOUBLE_EQ(t2.elements[2][1], 0.0);
        EXPECT_DOUBLE_EQ(t2.elements[2][2], 1.0);
        EXPECT_DOUBLE_EQ(t2.elements[2][3], 5.0);
        EXPECT_DOUBLE_EQ(t2.elements[3][0], 0.0);
        EXPECT_DOUBLE_EQ(t2.elements[3][1], 0.0);
        EXPECT_DOUBLE_EQ(t2.elements[3][2], 0.0);
        EXPECT_DOUBLE_EQ(t2.elements[3][3], 1.0);
    }
    {
        const Matrix4i t1 = Math::Translate(Vector3i(2, 3, 5));
        EXPECT_EQ(t1.elements[0][0], 1);
        EXPECT_EQ(t1.elements[0][1], 0);
        EXPECT_EQ(t1.elements[0][2], 0);
        EXPECT_EQ(t1.elements[0][3], 2);
        EXPECT_EQ(t1.elements[1][0], 0);
        EXPECT_EQ(t1.elements[1][1], 1);
        EXPECT_EQ(t1.elements[1][2], 0);
        EXPECT_EQ(t1.elements[1][3], 3);
        EXPECT_EQ(t1.elements[2][0], 0);
        EXPECT_EQ(t1.elements[2][1], 0);
        EXPECT_EQ(t1.elements[2][2], 1);
        EXPECT_EQ(t1.elements[2][3], 5);
        EXPECT_EQ(t1.elements[3][0], 0);
        EXPECT_EQ(t1.elements[3][1], 0);
        EXPECT_EQ(t1.elements[3][2], 0);
        EXPECT_EQ(t1.elements[3][3], 1);

        const Matrix4i t2 = Math::Translate(Point3i(2, 3, 5));
        EXPECT_EQ(t2.elements[0][0], 1);
        EXPECT_EQ(t2.elements[0][1], 0);
        EXPECT_EQ(t2.elements[0][2], 0);
        EXPECT_EQ(t2.elements[0][3], 2);
        EXPECT_EQ(t2.elements[1][0], 0);
        EXPECT_EQ(t2.elements[1][1], 1);
        EXPECT_EQ(t2.elements[1][2], 0);
        EXPECT_EQ(t2.elements[1][3], 3);
        EXPECT_EQ(t2.elements[2][0], 0);
        EXPECT_EQ(t2.elements[2][1], 0);
        EXPECT_EQ(t2.elements[2][2], 1);
        EXPECT_EQ(t2.elements[2][3], 5);
        EXPECT_EQ(t2.elements[3][0], 0);
        EXPECT_EQ(t2.elements[3][1], 0);
        EXPECT_EQ(t2.elements[3][2], 0);
        EXPECT_EQ(t2.elements[3][3], 1);
    }
}

TEST(TransformTests, Scale)
{
    {
        const Matrix4f s1 = Math::Scale<float>(2, 3, 5);
        EXPECT_FLOAT_EQ(s1.elements[0][0], 2.0f);
        EXPECT_FLOAT_EQ(s1.elements[0][1], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[0][2], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[0][3], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[1][0], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[1][1], 3.0f);
        EXPECT_FLOAT_EQ(s1.elements[1][2], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[1][3], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[2][0], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[2][1], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[2][2], 5.0f);
        EXPECT_FLOAT_EQ(s1.elements[2][3], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(s1.elements[3][3], 1.0f);

        const Matrix4f s2 = Math::Scale<float>(2);
        EXPECT_FLOAT_EQ(s2.elements[0][0], 2.0f);
        EXPECT_FLOAT_EQ(s2.elements[0][1], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[0][2], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[0][3], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[1][0], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[1][1], 2.0f);
        EXPECT_FLOAT_EQ(s2.elements[1][2], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[1][3], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[2][0], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[2][1], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[2][2], 2.0f);
        EXPECT_FLOAT_EQ(s2.elements[2][3], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(s2.elements[3][3], 1.0f);
    }
    {
        const Matrix4d s1 = Math::Scale<double>(2, 3, 5);
        EXPECT_DOUBLE_EQ(s1.elements[0][0], 2.0);
        EXPECT_DOUBLE_EQ(s1.elements[0][1], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[0][2], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[0][3], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[1][0], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[1][1], 3.0);
        EXPECT_DOUBLE_EQ(s1.elements[1][2], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[1][3], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[2][0], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[2][1], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[2][2], 5.0);
        EXPECT_DOUBLE_EQ(s1.elements[2][3], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[3][0], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[3][1], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[3][2], 0.0);
        EXPECT_DOUBLE_EQ(s1.elements[3][3], 1.0);

        const Matrix4d s2 = Math::Scale<double>(2);
        EXPECT_DOUBLE_EQ(s2.elements[0][0], 2.0);
        EXPECT_DOUBLE_EQ(s2.elements[0][1], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[0][2], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[0][3], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[1][0], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[1][1], 2.0);
        EXPECT_DOUBLE_EQ(s2.elements[1][2], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[1][3], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[2][0], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[2][1], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[2][2], 2.0);
        EXPECT_DOUBLE_EQ(s2.elements[2][3], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[3][0], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[3][1], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[3][2], 0.0);
        EXPECT_DOUBLE_EQ(s2.elements[3][3], 1.0);
    }
    {
        const Matrix4i s1 = Math::Scale<int>(2, 3, 5);
        EXPECT_EQ(s1.elements[0][0], 2);
        EXPECT_EQ(s1.elements[0][1], 0);
        EXPECT_EQ(s1.elements[0][2], 0);
        EXPECT_EQ(s1.elements[0][3], 0);
        EXPECT_EQ(s1.elements[1][0], 0);
        EXPECT_EQ(s1.elements[1][1], 3);
        EXPECT_EQ(s1.elements[1][2], 0);
        EXPECT_EQ(s1.elements[1][3], 0);
        EXPECT_EQ(s1.elements[2][0], 0);
        EXPECT_EQ(s1.elements[2][1], 0);
        EXPECT_EQ(s1.elements[2][2], 5);
        EXPECT_EQ(s1.elements[2][3], 0);
        EXPECT_EQ(s1.elements[3][0], 0);
        EXPECT_EQ(s1.elements[3][1], 0);
        EXPECT_EQ(s1.elements[3][2], 0);
        EXPECT_EQ(s1.elements[3][3], 1);

        const Matrix4i s2 = Math::Scale<int>(2);
        EXPECT_EQ(s2.elements[0][0], 2);
        EXPECT_EQ(s2.elements[0][1], 0);
        EXPECT_EQ(s2.elements[0][2], 0);
        EXPECT_EQ(s2.elements[0][3], 0);
        EXPECT_EQ(s2.elements[1][0], 0);
        EXPECT_EQ(s2.elements[1][1], 2);
        EXPECT_EQ(s2.elements[1][2], 0);
        EXPECT_EQ(s2.elements[1][3], 0);
        EXPECT_EQ(s2.elements[2][0], 0);
        EXPECT_EQ(s2.elements[2][1], 0);
        EXPECT_EQ(s2.elements[2][2], 2);
        EXPECT_EQ(s2.elements[2][3], 0);
        EXPECT_EQ(s2.elements[3][0], 0);
        EXPECT_EQ(s2.elements[3][1], 0);
        EXPECT_EQ(s2.elements[3][2], 0);
        EXPECT_EQ(s2.elements[3][3], 1);
    }
}

TEST(TransformTests, Rotate)
{
    {
        const float degrees = 45.0f;
        const float s = Math::Sin(Math::Radians(degrees));
        const float c = Math::Cos(Math::Radians(degrees));

        const Matrix4f around_x = Math::RotateX(degrees);
        EXPECT_FLOAT_EQ(around_x.elements[0][0], 1.0f);
        EXPECT_FLOAT_EQ(around_x.elements[0][1], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[0][2], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[0][3], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[1][0], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[1][1], c);
        EXPECT_FLOAT_EQ(around_x.elements[1][2], -s);
        EXPECT_FLOAT_EQ(around_x.elements[1][3], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[2][0], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[2][1], s);
        EXPECT_FLOAT_EQ(around_x.elements[2][2], c);
        EXPECT_FLOAT_EQ(around_x.elements[2][3], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(around_x.elements[3][3], 1.0f);

        const Matrix4f around_y = Math::RotateY(degrees);
        EXPECT_FLOAT_EQ(around_y.elements[0][0], c);
        EXPECT_FLOAT_EQ(around_y.elements[0][1], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[0][2], s);
        EXPECT_FLOAT_EQ(around_y.elements[0][3], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[1][0], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[1][1], 1.0f);
        EXPECT_FLOAT_EQ(around_y.elements[1][2], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[1][3], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[2][0], -s);
        EXPECT_FLOAT_EQ(around_y.elements[2][1], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[2][2], c);
        EXPECT_FLOAT_EQ(around_y.elements[2][3], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(around_y.elements[3][3], 1.0f);

        const Matrix4f around_z = Math::RotateZ(degrees);
        EXPECT_FLOAT_EQ(around_z.elements[0][0], c);
        EXPECT_FLOAT_EQ(around_z.elements[0][1], -s);
        EXPECT_FLOAT_EQ(around_z.elements[0][2], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[0][3], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[1][0], s);
        EXPECT_FLOAT_EQ(around_z.elements[1][1], c);
        EXPECT_FLOAT_EQ(around_z.elements[1][2], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[1][3], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[2][0], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[2][1], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[2][2], 1.0f);
        EXPECT_FLOAT_EQ(around_z.elements[2][3], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(around_z.elements[3][3], 1.0f);

        const Matrix4f around_axis = Math::Rotate(degrees, Vector3f(0, 0, 1));
        EXPECT_TRUE(Math::IsEqual(around_axis, around_z, 0.00001f));
    }
    {
        const double degrees = 45.0;
        const double s = Math::Sin(Math::Radians(degrees));
        const double c = Math::Cos(Math::Radians(degrees));

        const Matrix4d around_x = Math::RotateX(degrees);
        EXPECT_DOUBLE_EQ(around_x.elements[0][0], 1.0);
        EXPECT_DOUBLE_EQ(around_x.elements[0][1], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[0][2], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[0][3], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[1][0], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[1][1], c);
        EXPECT_DOUBLE_EQ(around_x.elements[1][2], -s);
        EXPECT_DOUBLE_EQ(around_x.elements[1][3], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[2][0], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[2][1], s);
        EXPECT_DOUBLE_EQ(around_x.elements[2][2], c);
        EXPECT_DOUBLE_EQ(around_x.elements[2][3], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[3][0], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[3][1], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[3][2], 0.0);
        EXPECT_DOUBLE_EQ(around_x.elements[3][3], 1.0);

        const Matrix4d around_y = Math::RotateY(degrees);
        EXPECT_DOUBLE_EQ(around_y.elements[0][0], c);
        EXPECT_DOUBLE_EQ(around_y.elements[0][1], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[0][2], s);
        EXPECT_DOUBLE_EQ(around_y.elements[0][3], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[1][0], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[1][1], 1.0);
        EXPECT_DOUBLE_EQ(around_y.elements[1][2], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[1][3], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[2][0], -s);
        EXPECT_DOUBLE_EQ(around_y.elements[2][1], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[2][2], c);
        EXPECT_DOUBLE_EQ(around_y.elements[2][3], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[3][0], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[3][1], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[3][2], 0.0);
        EXPECT_DOUBLE_EQ(around_y.elements[3][3], 1.0);

        const Matrix4d around_z = Math::RotateZ(degrees);
        EXPECT_DOUBLE_EQ(around_z.elements[0][0], c);
        EXPECT_DOUBLE_EQ(around_z.elements[0][1], -s);
        EXPECT_DOUBLE_EQ(around_z.elements[0][2], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[0][3], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[1][0], s);
        EXPECT_DOUBLE_EQ(around_z.elements[1][1], c);
        EXPECT_DOUBLE_EQ(around_z.elements[1][2], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[1][3], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[2][0], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[2][1], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[2][2], 1.0);
        EXPECT_DOUBLE_EQ(around_z.elements[2][3], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[3][0], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[3][1], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[3][2], 0.0);
        EXPECT_DOUBLE_EQ(around_z.elements[3][3], 1.0);

        const Matrix4d around_axis = Math::Rotate(degrees, Vector3d(0, 0, 1));
        EXPECT_TRUE(Math::IsEqual(around_axis, around_z, 0.00000000001));
    }
}

TEST(TransformTests, RotateWithQuaternion)
{
    {
        const Quatf q = Quatf::FromAxisAngleDegrees(Vector3f(0, 0, 1), 45.0f);
        const Matrix4f t = Math::Rotate(q);
        const Matrix4f ref = Math::RotateZ(45.0f);
        EXPECT_TRUE(Math::IsEqual(t, ref, 0.0001f));
    }
    {
        const Quatd q = Quatd::FromAxisAngleDegrees(Vector3d(0, 0, 1), 45.0);
        const Matrix4d t = Math::Rotate(q);
        const Matrix4d ref = Math::RotateZ(45.0);
        EXPECT_TRUE(Math::IsEqual(t, ref, 0.000000001));
    }
}

TEST(TransformTests, RotateWithRotator)
{
    {
        const Rotf rot1(45.0f, 0.0f, 0.0f);
        const Matrix4f t1 = Math::Rotate(rot1);
        const Matrix4f ref1 = Math::RotateZ(45.0f);
        EXPECT_TRUE(Math::IsEqual(t1, ref1, 0.0001f));
        const Rotf rot2(0.0f, 45.0f, 0.0f);
        const Matrix4f t2 = Math::Rotate(rot2);
        const Matrix4f ref2 = Math::RotateY(45.0f);
        EXPECT_TRUE(Math::IsEqual(t2, ref2, 0.0001f));
        const Rotf rot3(0.0f, 0.0f, 45.0f);
        const Matrix4f t3 = Math::Rotate(rot3);
        const Matrix4f ref3 = Math::RotateX(45.0f);
        EXPECT_TRUE(Math::IsEqual(t3, ref3, 0.0001f));
    }
    {
        const Rotd rot1(45.0, 0.0, 0.0);
        const Matrix4d t1 = Math::Rotate(rot1);
        const Matrix4d ref1 = Math::RotateZ(45.0);
        EXPECT_TRUE(Math::IsEqual(t1, ref1, 0.000000001));
        const Rotd rot2(0.0, 45.0, 0.0);
        const Matrix4d t2 = Math::Rotate(rot2);
        const Matrix4d ref2 = Math::RotateY(45.0);
        EXPECT_TRUE(Math::IsEqual(t2, ref2, 0.000000001));
        const Rotd rot3(0.0, 0.0, 45.0);
        const Matrix4d t3 = Math::Rotate(rot3);
        const Matrix4d ref3 = Math::RotateX(45.0);
        EXPECT_TRUE(Math::IsEqual(t3, ref3, 0.000000001));
    }
}

TEST(TransformTests, RotateAndTranslate)
{
    {
        const float degrees = 45;
        const Rotf rot1(degrees, 0, 0);
        const float s1 = Math::Sin(Math::Radians(degrees));
        const float c1 = Math::Cos(Math::Radians(degrees));
        const Matrix4f t1 = Math::RotateAndTranslate(rot1, Vector3f(2, 3, 5));
        EXPECT_FLOAT_EQ(t1.elements[0][0], c1);
        EXPECT_FLOAT_EQ(t1.elements[0][1], -s1);
        EXPECT_FLOAT_EQ(t1.elements[0][2], 0);
        EXPECT_FLOAT_EQ(t1.elements[0][3], 2);
        EXPECT_FLOAT_EQ(t1.elements[1][0], s1);
        EXPECT_FLOAT_EQ(t1.elements[1][1], c1);
        EXPECT_FLOAT_EQ(t1.elements[1][2], 0);
        EXPECT_FLOAT_EQ(t1.elements[1][3], 3);
        EXPECT_FLOAT_EQ(t1.elements[2][0], 0);
        EXPECT_FLOAT_EQ(t1.elements[2][1], 0);
        EXPECT_FLOAT_EQ(t1.elements[2][2], 1);
        EXPECT_FLOAT_EQ(t1.elements[2][3], 5);
        EXPECT_FLOAT_EQ(t1.elements[3][0], 0);
        EXPECT_FLOAT_EQ(t1.elements[3][1], 0);
        EXPECT_FLOAT_EQ(t1.elements[3][2], 0);
        EXPECT_FLOAT_EQ(t1.elements[3][3], 1);

        const Matrix4f t2 = Math::RotateAndTranslate(rot1, Point3f(2, 3, 5));
        EXPECT_FLOAT_EQ(t2.elements[0][0], c1);
        EXPECT_FLOAT_EQ(t2.elements[0][1], -s1);
        EXPECT_FLOAT_EQ(t2.elements[0][2], 0);
        EXPECT_FLOAT_EQ(t2.elements[0][3], 2);
        EXPECT_FLOAT_EQ(t2.elements[1][0], s1);
        EXPECT_FLOAT_EQ(t2.elements[1][1], c1);
        EXPECT_FLOAT_EQ(t2.elements[1][2], 0);
        EXPECT_FLOAT_EQ(t2.elements[1][3], 3);
        EXPECT_FLOAT_EQ(t2.elements[2][0], 0);
        EXPECT_FLOAT_EQ(t2.elements[2][1], 0);
        EXPECT_FLOAT_EQ(t2.elements[2][2], 1);
        EXPECT_FLOAT_EQ(t2.elements[2][3], 5);
        EXPECT_FLOAT_EQ(t2.elements[3][0], 0);
        EXPECT_FLOAT_EQ(t2.elements[3][1], 0);
        EXPECT_FLOAT_EQ(t2.elements[3][2], 0);
        EXPECT_FLOAT_EQ(t2.elements[3][3], 1);
    }
    {
        const double degrees = 45;
        const Rotd rot1(degrees, 0, 0);
        const double s1 = Math::Sin(Math::Radians(degrees));
        const double c1 = Math::Cos(Math::Radians(degrees));
        const Matrix4d t1 = Math::RotateAndTranslate(rot1, Vector3d(2, 3, 5));
        EXPECT_DOUBLE_EQ(t1.elements[0][0], c1);
        EXPECT_DOUBLE_EQ(t1.elements[0][1], -s1);
        EXPECT_DOUBLE_EQ(t1.elements[0][2], 0);
        EXPECT_DOUBLE_EQ(t1.elements[0][3], 2);
        EXPECT_DOUBLE_EQ(t1.elements[1][0], s1);
        EXPECT_DOUBLE_EQ(t1.elements[1][1], c1);
        EXPECT_DOUBLE_EQ(t1.elements[1][2], 0);
        EXPECT_DOUBLE_EQ(t1.elements[1][3], 3);
        EXPECT_DOUBLE_EQ(t1.elements[2][0], 0);
        EXPECT_DOUBLE_EQ(t1.elements[2][1], 0);
        EXPECT_DOUBLE_EQ(t1.elements[2][2], 1);
        EXPECT_DOUBLE_EQ(t1.elements[2][3], 5);
        EXPECT_DOUBLE_EQ(t1.elements[3][0], 0);
        EXPECT_DOUBLE_EQ(t1.elements[3][1], 0);
        EXPECT_DOUBLE_EQ(t1.elements[3][2], 0);
        EXPECT_DOUBLE_EQ(t1.elements[3][3], 1);

        const Matrix4d t2 = Math::RotateAndTranslate(rot1, Point3d(2, 3, 5));
        EXPECT_DOUBLE_EQ(t2.elements[0][0], c1);
        EXPECT_DOUBLE_EQ(t2.elements[0][1], -s1);
        EXPECT_DOUBLE_EQ(t2.elements[0][2], 0);
        EXPECT_DOUBLE_EQ(t2.elements[0][3], 2);
        EXPECT_DOUBLE_EQ(t2.elements[1][0], s1);
        EXPECT_DOUBLE_EQ(t2.elements[1][1], c1);
        EXPECT_DOUBLE_EQ(t2.elements[1][2], 0);
        EXPECT_DOUBLE_EQ(t2.elements[1][3], 3);
        EXPECT_DOUBLE_EQ(t2.elements[2][0], 0);
        EXPECT_DOUBLE_EQ(t2.elements[2][1], 0);
        EXPECT_DOUBLE_EQ(t2.elements[2][2], 1);
        EXPECT_DOUBLE_EQ(t2.elements[2][3], 5);
        EXPECT_DOUBLE_EQ(t2.elements[3][0], 0);
        EXPECT_DOUBLE_EQ(t2.elements[3][1], 0);
        EXPECT_DOUBLE_EQ(t2.elements[3][2], 0);
        EXPECT_DOUBLE_EQ(t2.elements[3][3], 1);
    }
}

TEST(TransformTests, ApplyingTransforms)
{
    {
        const Matrix4f t1 = Math::Translate(Vector3f(2, 3, 5));
        const Matrix4f t2 = Math::Scale(2.0f);
        const Point3f p1(1, 1, 1);
        const Point3f p2 = t1 * p1;
        EXPECT_FLOAT_EQ(p2.x, 3);
        EXPECT_FLOAT_EQ(p2.y, 4);
        EXPECT_FLOAT_EQ(p2.z, 6);
        const Point4f p3 = t1 * Point4f(1, 1, 1, 1);
        EXPECT_FLOAT_EQ(p3.x, 3);
        EXPECT_FLOAT_EQ(p3.y, 4);
        EXPECT_FLOAT_EQ(p3.z, 6);
        EXPECT_FLOAT_EQ(p3.w, 1);
        const Vector3f v1(1, 1, 1);
        const Vector3f v2 = t1 * v1;
        EXPECT_FLOAT_EQ(v2.x, 1);
        EXPECT_FLOAT_EQ(v2.y, 1);
        EXPECT_FLOAT_EQ(v2.z, 1);
        const Vector4f v3 = t1 * Vector4f(1, 1, 1, 1);
        EXPECT_FLOAT_EQ(v3.x, 3);
        EXPECT_FLOAT_EQ(v3.y, 4);
        EXPECT_FLOAT_EQ(v3.z, 6);
        EXPECT_FLOAT_EQ(v3.w, 1);
        const Vector3f v4 = t2 * v1;
        EXPECT_FLOAT_EQ(v4.x, 2);
        EXPECT_FLOAT_EQ(v4.y, 2);
        EXPECT_FLOAT_EQ(v4.z, 2);
        const Vector4f v5 = t2 * Vector4f(1, 1, 1, 1);
        EXPECT_FLOAT_EQ(v5.x, 2);
        EXPECT_FLOAT_EQ(v5.y, 2);
        EXPECT_FLOAT_EQ(v5.z, 2);
        EXPECT_FLOAT_EQ(v5.w, 1);
        const Normal3f n1(1, 1, 1);
        const Normal3f n2 = t1 * n1;
        EXPECT_FLOAT_EQ(n2.x, 1);
        EXPECT_FLOAT_EQ(n2.y, 1);
        EXPECT_FLOAT_EQ(n2.z, 1);
    }
    {
        const Matrix4d t1 = Math::Translate(Vector3d(2, 3, 5));
        const Matrix4d t2 = Math::Scale(2.0);
        const Point3d p1(1, 1, 1);
        const Point3d p2 = t1 * p1;
        EXPECT_DOUBLE_EQ(p2.x, 3);
        EXPECT_DOUBLE_EQ(p2.y, 4);
        EXPECT_DOUBLE_EQ(p2.z, 6);
        const Point4d p3 = t1 * Point4d(1, 1, 1, 1);
        EXPECT_DOUBLE_EQ(p3.x, 3);
        EXPECT_DOUBLE_EQ(p3.y, 4);
        EXPECT_DOUBLE_EQ(p3.z, 6);
        EXPECT_DOUBLE_EQ(p3.w, 1);
        const Vector3d v1(1, 1, 1);
        const Vector3d v2 = t1 * v1;
        EXPECT_DOUBLE_EQ(v2.x, 1);
        EXPECT_DOUBLE_EQ(v2.y, 1);
        EXPECT_DOUBLE_EQ(v2.z, 1);
        const Vector4d v3 = t1 * Vector4d(1, 1, 1, 1);
        EXPECT_DOUBLE_EQ(v3.x, 3);
        EXPECT_DOUBLE_EQ(v3.y, 4);
        EXPECT_DOUBLE_EQ(v3.z, 6);
        EXPECT_DOUBLE_EQ(v3.w, 1);
        const Vector3d v4 = t2 * v1;
        EXPECT_DOUBLE_EQ(v4.x, 2);
        EXPECT_DOUBLE_EQ(v4.y, 2);
        EXPECT_DOUBLE_EQ(v4.z, 2);
        const Vector4d v5 = t2 * Vector4d(1, 1, 1, 1);
        EXPECT_DOUBLE_EQ(v5.x, 2);
        EXPECT_DOUBLE_EQ(v5.y, 2);
        EXPECT_DOUBLE_EQ(v5.z, 2);
        EXPECT_DOUBLE_EQ(v5.w, 1);
        const Normal3d n1(1, 1, 1);
        const Normal3d n2 = t1 * n1;
        EXPECT_DOUBLE_EQ(n2.x, 1);
        EXPECT_DOUBLE_EQ(n2.y, 1);
        EXPECT_DOUBLE_EQ(n2.z, 1);
    }
}
