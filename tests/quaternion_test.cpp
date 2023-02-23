#include "math/quaternion.h"

#include "realexpect.h"

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
}
