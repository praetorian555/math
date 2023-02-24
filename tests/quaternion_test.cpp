#include "math/quaternion.h"

#include "realexpect.h"

#include "math/transform.h"

TEST(QuaternionTests, Creation)
{
    {
        const math::Quaternion Q;
        EXPECT_EQ(Q.W, 1);
        EXPECT_EQ(Q.Vec.X, 0);
        EXPECT_EQ(Q.Vec.Y, 0);
        EXPECT_EQ(Q.Vec.Z, 0);
    }
    {
        const math::Quaternion Q(1, 2, 3, 4);
        EXPECT_EQ(Q.Vec.X, 1);
        EXPECT_EQ(Q.Vec.Y, 2);
        EXPECT_EQ(Q.Vec.Z, 3);
        EXPECT_EQ(Q.W, 4);
    }
    {
        const math::Quaternion Q =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(0, 0, 2), 60);
        EXPECT_EQ(Q.Vec.X, 0);
        EXPECT_EQ(Q.Vec.Y, 0);
        EXPECT_REAL_EQ(Q.Vec.Z, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Q.W, MATH_REALC(0.866025403784438646763723170752));
    }
    {
        const math::Quaternion Q =
            math::Quaternion::FromAxisAngleRadians(math::Vector3(0, 0, 2), math::Radians(60));
        EXPECT_EQ(Q.Vec.X, 0);
        EXPECT_EQ(Q.Vec.Y, 0);
        EXPECT_REAL_EQ(Q.Vec.Z, MATH_REALC(0.5));
        EXPECT_REAL_EQ(Q.W, MATH_REALC(0.866025403784438646763723170752));
    }
    {
        const math::Transform T = math::RotateZ(MATH_REALC(60.0));
        const math::Quaternion Q(T);
        const math::Quaternion Ref =
            math::Quaternion::FromAxisAngleRadians(math::Vector3(0, 0, 1), math::Radians(60));
        EXPECT_REAL_EQ(Q.Vec.X, Ref.Vec.X);
        EXPECT_REAL_EQ(Q.Vec.Y, Ref.Vec.Y);
        EXPECT_REAL_EQ(Q.Vec.Z, Ref.Vec.Z);
        EXPECT_REAL_EQ(Q.W, Ref.W);
    }
}

TEST(QuaternionTests, NaN)
{
    const math::Quaternion Q1(1, NAN, 3, 1);
    EXPECT_TRUE(Q1.HasNaNs());

    const math::Quaternion Q2(1, 2, 3, NAN);
    EXPECT_TRUE(Q2.HasNaNs());
}

TEST(QuaternionTests, Length)
{
    const math::Quaternion Q(1, 2, 3, 4);
    EXPECT_REAL_EQ(Q.Length(), MATH_REALC(5.477225575051661134569124887));
    EXPECT_REAL_EQ(Q.LengthSquared(), MATH_REALC(30.0));
}

TEST(QuaternionTests, Compare)
{
    const math::Quaternion Q1(1, 2, 3, 4);
    const math::Quaternion Q2(1, 2, 3, 4);
    EXPECT_TRUE(Q1 == Q2);
    EXPECT_FALSE(Q1 != Q2);
}

TEST(QuaternionTests, Addition)
{
    {
        const math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2(1, 2, 3, 4);
        const math::Quaternion Q3 = Q1 + Q2;
        EXPECT_EQ(Q3.Vec.X, 2);
        EXPECT_EQ(Q3.Vec.Y, 4);
        EXPECT_EQ(Q3.Vec.Z, 6);
        EXPECT_EQ(Q3.W, 8);
    }
    {
        math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2(1, 2, 3, 4);
        Q1 += Q2;
        EXPECT_EQ(Q1.Vec.X, 2);
        EXPECT_EQ(Q1.Vec.Y, 4);
        EXPECT_EQ(Q1.Vec.Z, 6);
        EXPECT_EQ(Q1.W, 8);
    }
}

TEST(QuaternionTests, Subtraction)
{
    {
        const math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2(1, 2, 3, 4);
        const math::Quaternion Q3 = Q1 - Q2;
        EXPECT_EQ(Q3.Vec.X, 0);
        EXPECT_EQ(Q3.Vec.Y, 0);
        EXPECT_EQ(Q3.Vec.Z, 0);
        EXPECT_EQ(Q3.W, 0);
    }
    {
        math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2(1, 2, 3, 4);
        Q1 -= Q2;
        EXPECT_EQ(Q1.Vec.X, 0);
        EXPECT_EQ(Q1.Vec.Y, 0);
        EXPECT_EQ(Q1.Vec.Z, 0);
        EXPECT_EQ(Q1.W, 0);
    }
}

TEST(QuaternionTests, Multiplication)
{
    {
        const math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2(1, 2, 3, 4);
        const math::Quaternion Q3 = Q1 * Q2;
        EXPECT_EQ(Q3.Vec.X, 8);
        EXPECT_EQ(Q3.Vec.Y, 16);
        EXPECT_EQ(Q3.Vec.Z, 24);
        EXPECT_EQ(Q3.W, 2);
    }
    {
        math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2(1, 2, 3, 4);
        Q1 *= Q2;
        EXPECT_EQ(Q1.Vec.X, 8);
        EXPECT_EQ(Q1.Vec.Y, 16);
        EXPECT_EQ(Q1.Vec.Z, 24);
        EXPECT_EQ(Q1.W, 2);
    }
    {
        const math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2 = Q1 * 2;
        EXPECT_EQ(Q2.Vec.X, 2);
        EXPECT_EQ(Q2.Vec.Y, 4);
        EXPECT_EQ(Q2.Vec.Z, 6);
        EXPECT_EQ(Q2.W, 8);
    }
    {
        const math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2 = 2 * Q1;
        EXPECT_EQ(Q2.Vec.X, 2);
        EXPECT_EQ(Q2.Vec.Y, 4);
        EXPECT_EQ(Q2.Vec.Z, 6);
        EXPECT_EQ(Q2.W, 8);
    }
    {
        math::Quaternion Q1(1, 2, 3, 4);
        Q1 *= 2;
        EXPECT_EQ(Q1.Vec.X, 2);
        EXPECT_EQ(Q1.Vec.Y, 4);
        EXPECT_EQ(Q1.Vec.Z, 6);
        EXPECT_EQ(Q1.W, 8);
    }
}

TEST(QuaternionTests, Division)
{
    {
        const math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2 = Q1 / 2;
        EXPECT_EQ(Q2.Vec.X, 0.5);
        EXPECT_EQ(Q2.Vec.Y, 1);
        EXPECT_EQ(Q2.Vec.Z, 1.5);
        EXPECT_EQ(Q2.W, 2);
    }
    {
        math::Quaternion Q1(1, 2, 3, 4);
        Q1 /= 2;
        EXPECT_EQ(Q1.Vec.X, 0.5);
        EXPECT_EQ(Q1.Vec.Y, 1);
        EXPECT_EQ(Q1.Vec.Z, 1.5);
        EXPECT_EQ(Q1.W, 2);
    }
}

TEST(QuaternionTests, Dot)
{
    const math::Quaternion Q1(1, 2, 3, 4);
    const math::Quaternion Q2(1, 2, 3, 4);
    EXPECT_EQ(Dot(Q1, Q2), 30);
}

TEST(QuaternionTests, Normalize)
{
    {
        const math::Quaternion Q1(1, 2, 3, 4);
        const math::Quaternion Q2 = Normalize(Q1);
        EXPECT_REAL_EQ(Q2.Length(), MATH_REALC(1.0));
    }
}

TEST(QuaternionTests, Conjugate)
{
    const math::Quaternion Q1(1, 2, 3, 4);
    const math::Quaternion Q2 = Conjugate(Q1);
    EXPECT_EQ(Q2.Vec.X, -1);
    EXPECT_EQ(Q2.Vec.Y, -2);
    EXPECT_EQ(Q2.Vec.Z, -3);
    EXPECT_EQ(Q2.W, 4);
}

TEST(QuaternionTests, Inverse)
{
    const math::Quaternion Q1(1, 2, 3, 4);
    const math::Quaternion Q2 = Inverse(Q1);
    EXPECT_REAL_EQ(Q2.W, MATH_REALC(2.0) / MATH_REALC(15.0));
    EXPECT_REAL_EQ(Q2.Vec.X, -MATH_REALC(1.0) / MATH_REALC(30.0));
    EXPECT_REAL_EQ(Q2.Vec.Y, -MATH_REALC(1.0) / MATH_REALC(15.0));
    EXPECT_REAL_EQ(Q2.Vec.Z, -MATH_REALC(1.0) / MATH_REALC(10.0));
}

TEST(QuaternionTests, Lerp)
{
    {
        const math::Quaternion Q1 =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(1, 0, 0), 30);
        const math::Quaternion Q2 =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(1, 0, 0), 90);
        const math::Quaternion Q3 = math::Lerp(Q1, Q2, MATH_REALC(0.5));
        const math::Quaternion Q4 =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(1, 0, 0), 60);
        EXPECT_REAL_EQ(Q3.Vec.X, Q4.Vec.X);
        EXPECT_REAL_EQ(Q3.Vec.Y, Q4.Vec.Y);
        EXPECT_REAL_EQ(Q3.Vec.Z, Q4.Vec.Z);
        EXPECT_REAL_EQ(Q3.W, Q4.W);
    }
}

TEST(QuaternionTests, Slerp)
{
    {
        const math::Quaternion Q1 =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(1, 0, 0), 30);
        const math::Quaternion Q2 =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(1, 0, 0), 90);
        const math::Quaternion Q3 = math::Slerp(Q1, Q2, MATH_REALC(0.5));
        const math::Quaternion Q4 =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(1, 0, 0), 60);
        EXPECT_REAL_EQ(Q3.Vec.X, Q4.Vec.X);
        EXPECT_REAL_EQ(Q3.Vec.Y, Q4.Vec.Y);
        EXPECT_REAL_EQ(Q3.Vec.Z, Q4.Vec.Z);
        EXPECT_REAL_EQ(Q3.W, Q4.W);
    }
    {
        const math::Quaternion Q1 =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(1, 0, 0), 30);
        const math::Quaternion Q2 =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(1, 0, 0), 90);
        const math::Quaternion Q3 = math::Slerp(Q1, Q2, MATH_REALC(0.4));
        const math::Quaternion Q4 =
            math::Quaternion::FromAxisAngleDegrees(math::Vector3(1, 0, 0), 54);
        EXPECT_REAL_EQ(Q3.Vec.X, Q4.Vec.X);
        EXPECT_REAL_EQ(Q3.Vec.Y, Q4.Vec.Y);
        EXPECT_REAL_EQ(Q3.Vec.Z, Q4.Vec.Z);
        EXPECT_REAL_EQ(Q3.W, Q4.W);
    }
}
