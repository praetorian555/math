#include <gtest/gtest.h>

#include "math/matrix4x4.h"
#include "math/quaternion.h"
#include "math/transform.h"

using Quatf = Math::Quaternion<float>;
using Quatd = Math::Quaternion<double>;
using Vector3f = Math::Vector3<float>;
using Vector3d = Math::Vector3<double>;
using Point3f = Math::Point3<float>;
using Point3d = Math::Point3<double>;
using Matrix4x4f = Math::Matrix4x4<float>;
using Matrix4x4d = Math::Matrix4x4<double>;

TEST(QuaternionTests, Creation)
{
    {
        const Quatf q1(4, 1, 2, 3);
        EXPECT_FLOAT_EQ(q1.vec.x, 1);
        EXPECT_FLOAT_EQ(q1.vec.y, 2);
        EXPECT_FLOAT_EQ(q1.vec.z, 3);
        EXPECT_FLOAT_EQ(q1.w, 4);
        const Quatf q2 = Quatf::FromAxisAngleDegrees(Vector3f(0, 0, 2), 60);
        EXPECT_FLOAT_EQ(q2.vec.x, 0);
        EXPECT_FLOAT_EQ(q2.vec.y, 0);
        EXPECT_FLOAT_EQ(q2.vec.z, 0.5f);
        EXPECT_FLOAT_EQ(q2.w, 0.866025403784438646763723170752f);
        const Quatf q3 = Quatf::FromAxisAngleRadians(Vector3f(0, 0, 2), Math::Radians(60.0f));
        EXPECT_FLOAT_EQ(q3.vec.x, 0);
        EXPECT_FLOAT_EQ(q3.vec.y, 0);
        EXPECT_FLOAT_EQ(q3.vec.z, 0.5f);
        EXPECT_FLOAT_EQ(q2.w, 0.866025403784438646763723170752f);
        const Quatf q4 = Quatf::Identity();
        EXPECT_FLOAT_EQ(q4.vec.x, 0);
        EXPECT_FLOAT_EQ(q4.vec.y, 0);
        EXPECT_FLOAT_EQ(q4.vec.z, 0);
        EXPECT_FLOAT_EQ(q4.w, 1);
    }
    {
        const Quatd q1(4, 1, 2, 3);
        EXPECT_DOUBLE_EQ(q1.vec.x, 1);
        EXPECT_DOUBLE_EQ(q1.vec.y, 2);
        EXPECT_DOUBLE_EQ(q1.vec.z, 3);
        EXPECT_DOUBLE_EQ(q1.w, 4);
        const Quatd q2 = Quatd::FromAxisAngleDegrees(Vector3d(0, 0, 2), 60);
        EXPECT_DOUBLE_EQ(q2.vec.x, 0);
        EXPECT_DOUBLE_EQ(q2.vec.y, 0);
        EXPECT_DOUBLE_EQ(q2.vec.z, 0.5);
        EXPECT_DOUBLE_EQ(q2.w, 0.866025403784438646763723170752);
        const Quatd q3 = Quatd::FromAxisAngleRadians(Vector3d(0, 0, 2), Math::Radians(60.0));
        EXPECT_DOUBLE_EQ(q3.vec.x, 0);
        EXPECT_DOUBLE_EQ(q3.vec.y, 0);
        EXPECT_DOUBLE_EQ(q3.vec.z, 0.5);
        EXPECT_DOUBLE_EQ(q2.w, 0.866025403784438646763723170752);
        const Quatd q4 = Quatd::Identity();
        EXPECT_DOUBLE_EQ(q4.vec.x, 0);
        EXPECT_DOUBLE_EQ(q4.vec.y, 0);
        EXPECT_DOUBLE_EQ(q4.vec.z, 0);
        EXPECT_DOUBLE_EQ(q4.w, 1);
    }

    // TODO: Test this once the transform is refactored
    //    const Math::Transform T = Math::RotateZ(MATH_REALC(60.0));
    //    const Math::Quaternion Q(T);
    //    const Math::Quaternion Ref =
    //        Math::Quaternion::FromAxisAngleRadians(Math::Vector3(0, 0, 1),
    //        Math::Radians(60.0f));
    //    EXPECT_REAL_EQ(q.vec.x, Ref.vec.x);
    //    EXPECT_REAL_EQ(q.vec.y, Ref.vec.y);
    //    EXPECT_REAL_EQ(q.vec.z, Ref.vec.z);
    //    EXPECT_REAL_EQ(q.w, Ref.w);
}

TEST(QuaternionTests, Compare)
{
    {
        const Quatf q1(4, 1, 2, 3);
        const Quatf q2(4, 1, 2, 3);
        const Quatf q3(5, 1, 2, 3);
        const Quatf q4(4, 1, 5, 3);
        EXPECT_TRUE(q1 == q2);
        EXPECT_FALSE(q1 != q2);
        EXPECT_FALSE(q1 == q3);
        EXPECT_TRUE(q1 != q3);
        EXPECT_FALSE(q1 == q4);
        EXPECT_TRUE(q1 != q4);
    }
    {
        const Quatd q1(4, 1, 2, 3);
        const Quatd q2(4, 1, 2, 3);
        const Quatd q3(5, 1, 2, 3);
        const Quatd q4(4, 1, 5, 3);
        EXPECT_TRUE(q1 == q2);
        EXPECT_FALSE(q1 != q2);
        EXPECT_FALSE(q1 == q3);
        EXPECT_TRUE(q1 != q3);
        EXPECT_FALSE(q1 == q4);
        EXPECT_TRUE(q1 != q4);
    }
}

TEST(QuaternionTests, Addition)
{
    {
        {
            const Quatf q1(4, 1, 2, 3);
            const Quatf q2(4, 1, 2, 3);
            const Quatf q3 = q1 + q2;
            EXPECT_FLOAT_EQ(q3.vec.x, 2);
            EXPECT_FLOAT_EQ(q3.vec.y, 4);
            EXPECT_FLOAT_EQ(q3.vec.z, 6);
            EXPECT_FLOAT_EQ(q3.w, 8);
        }
        {
            Quatf q1(4, 1, 2, 3);
            const Quatf q2(4, 1, 2, 3);
            q1 += q2;
            EXPECT_FLOAT_EQ(q1.vec.x, 2);
            EXPECT_FLOAT_EQ(q1.vec.y, 4);
            EXPECT_FLOAT_EQ(q1.vec.z, 6);
            EXPECT_FLOAT_EQ(q1.w, 8);
        }
    }
    {
        {
            const Quatd q1(4, 1, 2, 3);
            const Quatd q2(4, 1, 2, 3);
            const Quatd q3 = q1 + q2;
            EXPECT_DOUBLE_EQ(q3.vec.x, 2);
            EXPECT_DOUBLE_EQ(q3.vec.y, 4);
            EXPECT_DOUBLE_EQ(q3.vec.z, 6);
            EXPECT_DOUBLE_EQ(q3.w, 8);
        }
        {
            Quatd q1(4, 1, 2, 3);
            const Quatd q2(4, 1, 2, 3);
            q1 += q2;
            EXPECT_DOUBLE_EQ(q1.vec.x, 2);
            EXPECT_DOUBLE_EQ(q1.vec.y, 4);
            EXPECT_DOUBLE_EQ(q1.vec.z, 6);
            EXPECT_DOUBLE_EQ(q1.w, 8);
        }
    }
}

TEST(QuaternionTests, Subtraction)
{
    {
        {
            const Quatf q1(4, 1, 2, 3);
            const Quatf q2(4, 1, 2, 3);
            const Quatf q3 = q1 - q2;
            EXPECT_FLOAT_EQ(q3.vec.x, 0);
            EXPECT_FLOAT_EQ(q3.vec.y, 0);
            EXPECT_FLOAT_EQ(q3.vec.z, 0);
            EXPECT_FLOAT_EQ(q3.w, 0);
        }
        {
            Quatf q1(4, 1, 2, 3);
            const Quatf q2(4, 1, 2, 3);
            q1 -= q2;
            EXPECT_FLOAT_EQ(q1.vec.x, 0);
            EXPECT_FLOAT_EQ(q1.vec.y, 0);
            EXPECT_FLOAT_EQ(q1.vec.z, 0);
            EXPECT_FLOAT_EQ(q1.w, 0);
        }
    }
    {
        {
            const Quatd q1(4, 1, 2, 3);
            const Quatd q2(4, 1, 2, 3);
            const Quatd q3 = q1 - q2;
            EXPECT_DOUBLE_EQ(q3.vec.x, 0);
            EXPECT_DOUBLE_EQ(q3.vec.y, 0);
            EXPECT_DOUBLE_EQ(q3.vec.z, 0);
            EXPECT_DOUBLE_EQ(q3.w, 0);
        }
        {
            Quatd q1(4, 1, 2, 3);
            const Quatd q2(4, 1, 2, 3);
            q1 -= q2;
            EXPECT_DOUBLE_EQ(q1.vec.x, 0);
            EXPECT_DOUBLE_EQ(q1.vec.y, 0);
            EXPECT_DOUBLE_EQ(q1.vec.z, 0);
            EXPECT_DOUBLE_EQ(q1.w, 0);
        }
    }
}

TEST(QuaternionTests, Multiplication)
{
    {
        {
            const Quatf q1(4, 1, 2, 3);
            const Quatf q2(4, 1, 2, 3);
            const Quatf q3 = q1 * q2;
            EXPECT_FLOAT_EQ(q3.vec.x, 8);
            EXPECT_FLOAT_EQ(q3.vec.y, 16);
            EXPECT_FLOAT_EQ(q3.vec.z, 24);
            EXPECT_FLOAT_EQ(q3.w, 2);
        }
        {
            Quatf q1(4, 1, 2, 3);
            const Quatf q2(4, 1, 2, 3);
            q1 *= q2;
            EXPECT_FLOAT_EQ(q1.vec.x, 8);
            EXPECT_FLOAT_EQ(q1.vec.y, 16);
            EXPECT_FLOAT_EQ(q1.vec.z, 24);
            EXPECT_FLOAT_EQ(q1.w, 2);
        }
        {
            const Quatf q1(4, 1, 2, 3);
            const Quatf q2 = q1 * 2;
            EXPECT_FLOAT_EQ(q2.vec.x, 2);
            EXPECT_FLOAT_EQ(q2.vec.y, 4);
            EXPECT_FLOAT_EQ(q2.vec.z, 6);
            EXPECT_FLOAT_EQ(q2.w, 8);
        }
        {
            const Quatf q1(4, 1, 2, 3);
            const Quatf q2 = 2.0f * q1;
            EXPECT_FLOAT_EQ(q2.vec.x, 2);
            EXPECT_FLOAT_EQ(q2.vec.y, 4);
            EXPECT_FLOAT_EQ(q2.vec.z, 6);
            EXPECT_FLOAT_EQ(q2.w, 8);
        }
        {
            Quatf q1(4, 1, 2, 3);
            q1 *= 2;
            EXPECT_FLOAT_EQ(q1.vec.x, 2);
            EXPECT_FLOAT_EQ(q1.vec.y, 4);
            EXPECT_FLOAT_EQ(q1.vec.z, 6);
            EXPECT_FLOAT_EQ(q1.w, 8);
        }
        {
            const Quatf q1 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 90);
            const Vector3f Res = q1 * Vector3f(0, 1, 0);
            EXPECT_FLOAT_EQ(Res.x, 0);
            EXPECT_TRUE(Math::IsEqual(Res.y, 0.0f, 0.0001f));
            EXPECT_FLOAT_EQ(Res.z, 1);
        }
        {
            const Quatf q1 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 90);
            const Point3f Res = q1 * Point3f(0, 0, 1);
            EXPECT_FLOAT_EQ(Res.x, 0);
            EXPECT_FLOAT_EQ(Res.y, -1);
            EXPECT_FLOAT_EQ(Res.z, 0);
        }
    }
    {
        {
            const Quatd q1(4, 1, 2, 3);
            const Quatd q2(4, 1, 2, 3);
            const Quatd q3 = q1 * q2;
            EXPECT_DOUBLE_EQ(q3.vec.x, 8);
            EXPECT_DOUBLE_EQ(q3.vec.y, 16);
            EXPECT_DOUBLE_EQ(q3.vec.z, 24);
            EXPECT_DOUBLE_EQ(q3.w, 2);
        }
        {
            Quatd q1(4, 1, 2, 3);
            const Quatd q2(4, 1, 2, 3);
            q1 *= q2;
            EXPECT_DOUBLE_EQ(q1.vec.x, 8);
            EXPECT_DOUBLE_EQ(q1.vec.y, 16);
            EXPECT_DOUBLE_EQ(q1.vec.z, 24);
            EXPECT_DOUBLE_EQ(q1.w, 2);
        }
        {
            const Quatd q1(4, 1, 2, 3);
            const Quatd q2 = q1 * 2;
            EXPECT_DOUBLE_EQ(q2.vec.x, 2);
            EXPECT_DOUBLE_EQ(q2.vec.y, 4);
            EXPECT_DOUBLE_EQ(q2.vec.z, 6);
            EXPECT_DOUBLE_EQ(q2.w, 8);
        }
        {
            const Quatd q1(4, 1, 2, 3);
            const Quatd q2 = 2.0 * q1;
            EXPECT_DOUBLE_EQ(q2.vec.x, 2);
            EXPECT_DOUBLE_EQ(q2.vec.y, 4);
            EXPECT_DOUBLE_EQ(q2.vec.z, 6);
            EXPECT_DOUBLE_EQ(q2.w, 8);
        }
        {
            Quatd q1(4, 1, 2, 3);
            q1 *= 2;
            EXPECT_DOUBLE_EQ(q1.vec.x, 2);
            EXPECT_DOUBLE_EQ(q1.vec.y, 4);
            EXPECT_DOUBLE_EQ(q1.vec.z, 6);
            EXPECT_DOUBLE_EQ(q1.w, 8);
        }
        {
            const Quatd q1 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 90);
            const Vector3d Res = q1 * Vector3d(0, 1, 0);
            EXPECT_DOUBLE_EQ(Res.x, 0);
            EXPECT_TRUE(Math::IsEqual(Res.y, 0.0, 0.0001));
            EXPECT_DOUBLE_EQ(Res.z, 1);
        }
        {
            const Quatd q1 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 90);
            const Point3d Res = q1 * Point3d(0, 0, 1);
            EXPECT_DOUBLE_EQ(Res.x, 0);
            EXPECT_DOUBLE_EQ(Res.y, -1);
            EXPECT_DOUBLE_EQ(Res.z, 0);
        }
    }
}

TEST(QuaternionTests, Division)
{
    {
        {
            const Quatf Q1(4, 1, 2, 3);
            const Quatf Q2 = Q1 / 2;
            EXPECT_FLOAT_EQ(Q2.vec.x, 0.5f);
            EXPECT_FLOAT_EQ(Q2.vec.y, 1);
            EXPECT_FLOAT_EQ(Q2.vec.z, 1.5f);
            EXPECT_FLOAT_EQ(Q2.w, 2);
        }
        {
            Quatf Q1(4, 1, 2, 3);
            Q1 /= 2;
            EXPECT_FLOAT_EQ(Q1.vec.x, 0.5f);
            EXPECT_FLOAT_EQ(Q1.vec.y, 1);
            EXPECT_FLOAT_EQ(Q1.vec.z, 1.5f);
            EXPECT_FLOAT_EQ(Q1.w, 2);
        }
    }
    {
        {
            const Quatd Q1(4, 1, 2, 3);
            const Quatd Q2 = Q1 / 2;
            EXPECT_DOUBLE_EQ(Q2.vec.x, 0.5);
            EXPECT_DOUBLE_EQ(Q2.vec.y, 1);
            EXPECT_DOUBLE_EQ(Q2.vec.z, 1.5);
            EXPECT_DOUBLE_EQ(Q2.w, 2);
        }
        {
            Quatd Q1(4, 1, 2, 3);
            Q1 /= 2;
            EXPECT_DOUBLE_EQ(Q1.vec.x, 0.5);
            EXPECT_DOUBLE_EQ(Q1.vec.y, 1);
            EXPECT_DOUBLE_EQ(Q1.vec.z, 1.5);
            EXPECT_DOUBLE_EQ(Q1.w, 2);
        }
    }
}

TEST(QuaternionTests, NaNAndNonFinite)
{
    {
        const Quatf q1(1, 1, NAN, 3);
        EXPECT_TRUE(Math::ContainsNaN(q1));
        EXPECT_TRUE(Math::ContainsNonFinite(q1));
        const Quatf q2(NAN, 1, 2, 3);
        EXPECT_TRUE(Math::ContainsNaN(q2));
        EXPECT_TRUE(Math::ContainsNonFinite(q2));
        const Quatf q3(1, 1, INFINITY, 3);
        EXPECT_TRUE(Math::ContainsNonFinite(q3));
        const Quatf q4(INFINITY, 1, 2, 3);
        EXPECT_TRUE(Math::ContainsNonFinite(q4));
    }
    {
        const Quatd q1(1, 1, NAN, 3);
        EXPECT_TRUE(Math::ContainsNaN(q1));
        EXPECT_TRUE(Math::ContainsNonFinite(q1));
        const Quatd q2(NAN, 1, 2, 3);
        EXPECT_TRUE(Math::ContainsNaN(q2));
        EXPECT_TRUE(Math::ContainsNonFinite(q2));
        const Quatd q3(1, 1, INFINITY, 3);
        EXPECT_TRUE(Math::ContainsNonFinite(q3));
        const Quatd q4(INFINITY, 1, 2, 3);
        EXPECT_TRUE(Math::ContainsNonFinite(q4));
    }
}

TEST(QuaternionTests, Length)
{
    {
        const Quatf q(4, 1, 2, 3);
        EXPECT_FLOAT_EQ(Length(q), 5.477225575051661134569124887f);
        EXPECT_FLOAT_EQ(LengthSquared(q), 30.0f);
    }
    {
        const Quatd q(4, 1, 2, 3);
        EXPECT_DOUBLE_EQ(Length(q), 5.477225575051661134569124887);
        EXPECT_DOUBLE_EQ(LengthSquared(q), 30.0);
    }
}

TEST(QuaternionTests, Dot)
{
    {
        const Quatf q1(4, 1, 2, 3);
        const Quatf q2(4, 1, 2, 3);
        EXPECT_FLOAT_EQ(Dot(q1, q2), 30);
    }
    {
        const Quatd q1(4, 1, 2, 3);
        const Quatd q2(4, 1, 2, 3);
        EXPECT_DOUBLE_EQ(Dot(q1, q2), 30);
    }
}

TEST(QuaternionTests, Normalize)
{
    {
        const Quatf q1(4, 1, 2, 3);
        const Quatf q2 = Normalize(q1);
        EXPECT_FLOAT_EQ(Length(q2), 1.0f);
    }
    {
        const Quatd q1(4, 1, 2, 3);
        const Quatd q2 = Normalize(q1);
        EXPECT_DOUBLE_EQ(Length(q2), 1.0);
    }
}

TEST(QuaternionTests, Lerp)
{
    {
        const Quatf q1 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 30);
        const Quatf q2 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 90);
        const Quatf q3 = Lerp(0.5f, q1, q2);
        const Quatf q4 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 60);
        EXPECT_FLOAT_EQ(q3.vec.x, q4.vec.x);
        EXPECT_FLOAT_EQ(q3.vec.y, q4.vec.y);
        EXPECT_FLOAT_EQ(q3.vec.z, q4.vec.z);
        EXPECT_FLOAT_EQ(q3.w, q4.w);
    }
    {
        const Quatf q1 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 30);
        const Quatf q2 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 90);
        const Quatf q3 = Lerp(0.4f, q1, q2);
        const Quatf q4 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 54);
        EXPECT_TRUE(Math::IsEqual(q3.vec.x, q4.vec.x, 0.01f));
        EXPECT_FLOAT_EQ(q3.vec.y, q4.vec.y);
        EXPECT_FLOAT_EQ(q3.vec.z, q4.vec.z);
        EXPECT_TRUE(Math::IsEqual(q3.w, q4.w, 0.001f));
    }
    {
        const Quatd q1 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 30);
        const Quatd q2 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 90);
        const Quatd q3 = Lerp(0.5, q1, q2);
        const Quatd q4 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 60);
        EXPECT_DOUBLE_EQ(q3.vec.x, q4.vec.x);
        EXPECT_DOUBLE_EQ(q3.vec.y, q4.vec.y);
        EXPECT_DOUBLE_EQ(q3.vec.z, q4.vec.z);
        EXPECT_DOUBLE_EQ(q3.w, q4.w);
    }
}

TEST(QuaternionTests, Slerp)
{
    {
        {
            const Quatf q1 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 30);
            const Quatf q2 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 90);
            const Quatf q3 = Math::Slerp(0.5f, q1, q2);
            const Quatf q4 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 60);
            EXPECT_FLOAT_EQ(q3.vec.x, q4.vec.x);
            EXPECT_FLOAT_EQ(q3.vec.y, q4.vec.y);
            EXPECT_FLOAT_EQ(q3.vec.z, q4.vec.z);
            EXPECT_FLOAT_EQ(q3.w, q4.w);
        }
        {
            const Quatf q1 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 30);
            const Quatf q2 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 90);
            const Quatf q3 = Math::Slerp(0.4f, q1, q2);
            const Quatf q4 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 54);
            EXPECT_FLOAT_EQ(q3.vec.x, q4.vec.x);
            EXPECT_FLOAT_EQ(q3.vec.y, q4.vec.y);
            EXPECT_FLOAT_EQ(q3.vec.z, q4.vec.z);
            EXPECT_FLOAT_EQ(q3.w, q4.w);
        }
    }
    {
        {
            const Quatd q1 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 30);
            const Quatd q2 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 90);
            const Quatd q3 = Math::Slerp(0.5, q1, q2);
            const Quatd q4 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 60);
            EXPECT_DOUBLE_EQ(q3.vec.x, q4.vec.x);
            EXPECT_DOUBLE_EQ(q3.vec.y, q4.vec.y);
            EXPECT_DOUBLE_EQ(q3.vec.z, q4.vec.z);
            EXPECT_DOUBLE_EQ(q3.w, q4.w);
        }
        {
            const Quatd q1 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 30);
            const Quatd q2 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 90);
            const Quatd q3 = Math::Slerp(0.4, q1, q2);
            const Quatd q4 = Quatd::FromAxisAngleDegrees(Vector3d(1, 0, 0), 54);
            EXPECT_DOUBLE_EQ(q3.vec.x, q4.vec.x);
            EXPECT_DOUBLE_EQ(q3.vec.y, q4.vec.y);
            EXPECT_DOUBLE_EQ(q3.vec.z, q4.vec.z);
            EXPECT_DOUBLE_EQ(q3.w, q4.w);
        }
    }
}

TEST(QuaternionTests, Conjugate)
{
    {
        const Quatf q1(4, 1, 2, 3);
        const Quatf q2 = Conjugate(q1);
        EXPECT_FLOAT_EQ(q2.vec.x, -1);
        EXPECT_FLOAT_EQ(q2.vec.y, -2);
        EXPECT_FLOAT_EQ(q2.vec.z, -3);
        EXPECT_FLOAT_EQ(q2.w, 4);
    }
    {
        const Quatd q1(4, 1, 2, 3);
        const Quatd q2 = Conjugate(q1);
        EXPECT_DOUBLE_EQ(q2.vec.x, -1);
        EXPECT_DOUBLE_EQ(q2.vec.y, -2);
        EXPECT_DOUBLE_EQ(q2.vec.z, -3);
        EXPECT_DOUBLE_EQ(q2.w, 4);
    }
}

TEST(QuaternionTests, Inverse)
{
    {
        const Quatf q1(4, 1, 2, 3);
        const Quatf q2 = Inverse(q1);
        EXPECT_FLOAT_EQ(q2.w, 2.0f / 15.0f);
        EXPECT_FLOAT_EQ(q2.vec.x, -1.0f / 30.0f);
        EXPECT_FLOAT_EQ(q2.vec.y, -1.0f / 15.0f);
        EXPECT_FLOAT_EQ(q2.vec.z, -1.0f / 10.0f);
    }
    {
        const Quatd q1(4, 1, 2, 3);
        const Quatd q2 = Inverse(q1);
        EXPECT_DOUBLE_EQ(q2.w, 2.0 / 15.0);
        EXPECT_DOUBLE_EQ(q2.vec.x, -1.0 / 30.0);
        EXPECT_DOUBLE_EQ(q2.vec.y, -1.0 / 15.0);
        EXPECT_DOUBLE_EQ(q2.vec.z, -1.0 / 10.0);
    }
}

TEST(QuaternionTests, RotatePoint)
{
    {
        // Rotate point around an axis
        const Quatf q = Quatf::FromAxisAngleDegrees(Vector3f(0, 0, 1), 90);
        const Point3f p = q * Point3f(1, 0, 0);
        EXPECT_FLOAT_EQ(p.x, 0);
        EXPECT_FLOAT_EQ(p.y, 1);
        EXPECT_FLOAT_EQ(p.z, 0);
        // Rotate using an inverse, should be in the opposite direction by the same amount
        const Quatf q_inv = Inverse(q);
        const Point3f p_inv = q_inv * Point3f(1, 0, 0);
        EXPECT_FLOAT_EQ(p_inv.x, 0);
        EXPECT_FLOAT_EQ(p_inv.y, -1);
        EXPECT_FLOAT_EQ(p_inv.z, 0);
    }
    {
        // Rotate point using a composition of two rotations
        const Quatf q1 = Quatf::FromAxisAngleDegrees(Vector3f(0, 0, 1), 90);
        const Quatf q2 = Quatf::FromAxisAngleDegrees(Vector3f(1, 0, 0), 90);
        const Quatf q_comp = q2 * q1;
        const Point3f p = q_comp * Point3f(1, 0, 0);
        EXPECT_TRUE(Math::IsEqual(p.x, 0.0f, 0.0001f));
        EXPECT_TRUE(Math::IsEqual(p.y, 0.0f, 0.0001f));
        EXPECT_TRUE(Math::IsEqual(p.z, 1.0f, 0.0001f));
    }
    {
        const Quatf q1 = Quatf::FromAxisAngleDegrees(Vector3f(0, 0, 1), 45);
        const Quatf q2 = -1.0f * q1;
        const Point3f p1 = q1 * Point3f(1, 0, 0);
        const Point3f p2 = q2 * Point3f(1, 0, 0);
        EXPECT_TRUE(Math::IsEqual(p1.x, 0.7071068f, 0.0001f));
        EXPECT_TRUE(Math::IsEqual(p1.y, 0.7071068f, 0.0001f));
        EXPECT_TRUE(Math::IsEqual(p1.z, 0.0f, 0.0001f));
        EXPECT_TRUE(Math::IsEqual(p2.x, 0.7071068f, 0.0001f));
        EXPECT_TRUE(Math::IsEqual(p2.y, 0.7071068f, 0.0001f));
        EXPECT_TRUE(Math::IsEqual(p2.z, 0.0f, 0.0001f));
    }
}
