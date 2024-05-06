#include <gtest/gtest.h>

#include "math/math.h"

using Matrix4x4f = Math::Matrix4x4<float>;
using Matrix4x4d = Math::Matrix4x4<double>;
using Matrix4x4i = Math::Matrix4x4<int32_t>;

TEST(Matrix4x4Tests, Creation)
{
    {
        const Matrix4x4f m1(1);
        EXPECT_FLOAT_EQ(m1(0, 0), 1.0f);
        EXPECT_FLOAT_EQ(m1(1, 1), 1.0f);
        EXPECT_FLOAT_EQ(m1(2, 2), 1.0f);
        EXPECT_FLOAT_EQ(m1(3, 3), 1.0f);
        EXPECT_FLOAT_EQ(m1(0, 1), 0.0f);
        EXPECT_FLOAT_EQ(m1(0, 2), 0.0f);
        EXPECT_FLOAT_EQ(m1(0, 3), 0.0f);
        EXPECT_FLOAT_EQ(m1(1, 0), 0.0f);
        EXPECT_FLOAT_EQ(m1(1, 2), 0.0f);
        EXPECT_FLOAT_EQ(m1(1, 3), 0.0f);
        EXPECT_FLOAT_EQ(m1(2, 0), 0.0f);
        EXPECT_FLOAT_EQ(m1(2, 1), 0.0f);
        EXPECT_FLOAT_EQ(m1(2, 3), 0.0f);
        EXPECT_FLOAT_EQ(m1(3, 0), 0.0f);
        EXPECT_FLOAT_EQ(m1(3, 1), 0.0f);
        EXPECT_FLOAT_EQ(m1(3, 2), 0.0f);

        // clang-format off
        const Matrix4x4f m2(
            1.0f, 4.0f, -4.0f, 5.0f,
            3.0f, -2.0f, 1.0f, 10.0f,
            7.0f, 10.0f, -5.0f, -3.0f,
           -6.0f, -2.0f, -1.0f, 9.0f
        );
        // clang-format on

        EXPECT_FLOAT_EQ(m2(0, 0), 1.0f);
        EXPECT_FLOAT_EQ(m2(0, 1), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 2), -4.0f);
        EXPECT_FLOAT_EQ(m2(0, 3), 5.0f);
        EXPECT_FLOAT_EQ(m2(1, 0), 3.0f);
        EXPECT_FLOAT_EQ(m2(1, 1), -2.0f);
        EXPECT_FLOAT_EQ(m2(1, 2), 1.0f);
        EXPECT_FLOAT_EQ(m2(1, 3), 10.0f);
        EXPECT_FLOAT_EQ(m2(2, 0), 7.0f);
        EXPECT_FLOAT_EQ(m2(2, 1), 10.0f);
        EXPECT_FLOAT_EQ(m2(2, 2), -5.0f);
        EXPECT_FLOAT_EQ(m2(2, 3), -3.0f);
        EXPECT_FLOAT_EQ(m2(3, 0), -6.0f);
        EXPECT_FLOAT_EQ(m2(3, 1), -2.0f);
        EXPECT_FLOAT_EQ(m2(3, 2), -1.0f);
        EXPECT_FLOAT_EQ(m2(3, 3), 9.0f);

        Math::Array2D<float, 4, 4> init;
        init[0] = {1.0f, 4.0f, -4.0f, 5.0f};
        init[1] = {3.0f, -2.0f, 1.0f, 10.0f};
        init[2] = {7.0f, 10.0f, -5.0f, -3.0f};
        init[3] = {-6.0f, -2.0f, -1.0f, 9.0f};

        const Matrix4x4f m3(init);
        EXPECT_FLOAT_EQ(m3(0, 0), 1.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 4.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), -4.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 5.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 3.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), -2.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 1.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 10.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 7.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 10.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), -5.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), -3.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), -6.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), -2.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), -1.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 9.0f);
    }
    {
        const Matrix4x4d m1(1);
        EXPECT_DOUBLE_EQ(m1(0, 0), 1.0);
        EXPECT_DOUBLE_EQ(m1(1, 1), 1.0);
        EXPECT_DOUBLE_EQ(m1(2, 2), 1.0);
        EXPECT_DOUBLE_EQ(m1(3, 3), 1.0);
        EXPECT_DOUBLE_EQ(m1(0, 1), 0.0);
        EXPECT_DOUBLE_EQ(m1(0, 2), 0.0);
        EXPECT_DOUBLE_EQ(m1(0, 3), 0.0);
        EXPECT_DOUBLE_EQ(m1(1, 0), 0.0);
        EXPECT_DOUBLE_EQ(m1(1, 2), 0.0);
        EXPECT_DOUBLE_EQ(m1(1, 3), 0.0);
        EXPECT_DOUBLE_EQ(m1(2, 0), 0.0);
        EXPECT_DOUBLE_EQ(m1(2, 1), 0.0);
        EXPECT_DOUBLE_EQ(m1(2, 3), 0.0);
        EXPECT_DOUBLE_EQ(m1(3, 0), 0.0);
        EXPECT_DOUBLE_EQ(m1(3, 1), 0.0);
        EXPECT_DOUBLE_EQ(m1(3, 2), 0.0);

        // clang-format off
        const Matrix4x4d m2(
            1.0, 4.0, -4.0, 5.0,
            3.0, -2.0, 1.0, 10.0,
            7.0, 10.0, -5.0, -3.0,
           -6.0, -2.0, -1.0, 9.0
        );
        // clang-format on

        EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
        EXPECT_DOUBLE_EQ(m2(0, 1), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 2), -4.0);
        EXPECT_DOUBLE_EQ(m2(0, 3), 5.0);
        EXPECT_DOUBLE_EQ(m2(1, 0), 3.0);
        EXPECT_DOUBLE_EQ(m2(1, 1), -2.0);
        EXPECT_DOUBLE_EQ(m2(1, 2), 1.0);
        EXPECT_DOUBLE_EQ(m2(1, 3), 10.0);
        EXPECT_DOUBLE_EQ(m2(2, 0), 7.0);
        EXPECT_DOUBLE_EQ(m2(2, 1), 10.0);
        EXPECT_DOUBLE_EQ(m2(2, 2), -5.0);
        EXPECT_DOUBLE_EQ(m2(2, 3), -3.0);
        EXPECT_DOUBLE_EQ(m2(3, 0), -6.0);
        EXPECT_DOUBLE_EQ(m2(3, 1), -2.0);
        EXPECT_DOUBLE_EQ(m2(3, 2), -1.0);
        EXPECT_DOUBLE_EQ(m2(3, 3), 9.0);

        Math::Array2D<double, 4, 4> init;
        init[0] = {1.0, 4.0, -4.0, 5.0};
        init[1] = {3.0, -2.0, 1.0, 10.0};
        init[2] = {7.0, 10.0, -5.0, -3.0};
        init[3] = {-6.0, -2.0, -1.0, 9.0};

        const Matrix4x4d m3(init);
        EXPECT_DOUBLE_EQ(m3(0, 0), 1.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 4.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), -4.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 5.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 3.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), -2.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 1.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 10.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 7.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 10.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), -5.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), -3.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), -6.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), -2.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), -1.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 9.0);
    }
    {
        const Matrix4x4i m1(1);
        EXPECT_EQ(m1(0, 0), 1);
        EXPECT_EQ(m1(1, 1), 1);
        EXPECT_EQ(m1(2, 2), 1);
        EXPECT_EQ(m1(3, 3), 1);
        EXPECT_EQ(m1(0, 1), 0);
        EXPECT_EQ(m1(0, 2), 0);
        EXPECT_EQ(m1(0, 3), 0);
        EXPECT_EQ(m1(1, 0), 0);
        EXPECT_EQ(m1(1, 2), 0);
        EXPECT_EQ(m1(1, 3), 0);
        EXPECT_EQ(m1(2, 0), 0);
        EXPECT_EQ(m1(2, 1), 0);
        EXPECT_EQ(m1(2, 3), 0);
        EXPECT_EQ(m1(3, 0), 0);
        EXPECT_EQ(m1(3, 1), 0);
        EXPECT_EQ(m1(3, 2), 0);

        // clang-format off
        const Matrix4x4i m2(
            1, 4, -4, 5,
            3, -2, 1, 10,
            7, 10, -5, -3,
           -6, -2, -1, 9
        );
        // clang-format on

        EXPECT_EQ(m2(0, 0), 1);
        EXPECT_EQ(m2(0, 1), 4);
        EXPECT_EQ(m2(0, 2), -4);
        EXPECT_EQ(m2(0, 3), 5);
        EXPECT_EQ(m2(1, 0), 3);
        EXPECT_EQ(m2(1, 1), -2);
        EXPECT_EQ(m2(1, 2), 1);
        EXPECT_EQ(m2(1, 3), 10);
        EXPECT_EQ(m2(2, 0), 7);
        EXPECT_EQ(m2(2, 1), 10);
        EXPECT_EQ(m2(2, 2), -5);
        EXPECT_EQ(m2(2, 3), -3);
        EXPECT_EQ(m2(3, 0), -6);
        EXPECT_EQ(m2(3, 1), -2);
        EXPECT_EQ(m2(3, 2), -1);
        EXPECT_EQ(m2(3, 3), 9);

        Math::Array2D<int32_t, 4, 4> init;
        init[0] = {1, 4, -4, 5};
        init[1] = {3, -2, 1, 10};
        init[2] = {7, 10, -5, -3};
        init[3] = {-6, -2, -1, 9};

        const Matrix4x4i m3(init);
        EXPECT_EQ(m3(0, 0), 1);
        EXPECT_EQ(m3(0, 1), 4);
        EXPECT_EQ(m3(0, 2), -4);
        EXPECT_EQ(m3(0, 3), 5);
        EXPECT_EQ(m3(1, 0), 3);
        EXPECT_EQ(m3(1, 1), -2);
        EXPECT_EQ(m3(1, 2), 1);
        EXPECT_EQ(m3(1, 3), 10);
        EXPECT_EQ(m3(2, 0), 7);
        EXPECT_EQ(m3(2, 1), 10);
        EXPECT_EQ(m3(2, 2), -5);
        EXPECT_EQ(m3(2, 3), -3);
        EXPECT_EQ(m3(3, 0), -6);
        EXPECT_EQ(m3(3, 1), -2);
        EXPECT_EQ(m3(3, 2), -1);
        EXPECT_EQ(m3(3, 3), 9);
    }
}

TEST(Matrix4x4Tests, Comparison)
{
    {
        const Matrix4x4f m1(1);

        // clang-format off
        const Math::Matrix4x4<float> m2(
            1.0f, 4.0f, -4.0f, 5.0f,
            3.0f, -2.0f, 1.0f, 10.0f,
            7.0f, 10.0f, -5.0f, -3.0f,
           -6.0f, -2.0f, -1.0f, 9.0f
        );
        // clang-format on

        // clang-format off
        Math::Array2D<float, 4, 4> init;
        init[0] = {1.0f, 4.0f, -4.0f, 5.0f};
        init[1] = {3.0f, -2.0f, 1.0f, 10.0f};
        init[2] = {7.0f, 10.0f, -5.0f, -3.0f};
        init[3] = {-6.0f, -2.0f, -1.0f, 9.0f};
        // clang-format on

        const Matrix4x4f m3(init);

        EXPECT_TRUE(m1 != m2);
        EXPECT_TRUE(m2 == m3);
    }
    {
        const Matrix4x4d m1(1);

        // clang-format off
        const Matrix4x4d m2(
            1.0, 4.0, -4.0, 5.0,
            3.0, -2.0, 1.0, 10.0,
            7.0, 10.0, -5.0, -3.0,
           -6.0, -2.0, -1.0, 9.0
        );
        // clang-format on

        // clang-format off
        Math::Array2D<double, 4, 4> init;
        init[0] = {1.0, 4.0, -4.0, 5.0};
        init[1] = {3.0, -2.0, 1.0, 10.0};
        init[2] = {7.0, 10.0, -5.0, -3.0};
        init[3] = {-6.0, -2.0, -1.0, 9.0};
        // clang-format on

        const Matrix4x4d m3(init);

        EXPECT_TRUE(m1 != m2);
        EXPECT_TRUE(m2 == m3);
    }
    {
        const Matrix4x4i m1(1);

        // clang-format off
        const Matrix4x4i m2(
            1, 4, -4, 5,
            3, -2, 1, 10,
            7, 10, -5, -3,
           -6, -2, -1, 9
        );
        // clang-format on

        // clang-format off
        Math::Array2D<int32_t, 4, 4> init;
        init[0] = {1, 4, -4, 5};
        init[1] = {3, -2, 1, 10};
        init[2] = {7, 10, -5, -3};
        init[3] = {-6, -2, -1, 9};
        // clang-format on

        const Matrix4x4i m3(init);

        EXPECT_TRUE(m1 != m2);
        EXPECT_TRUE(m2 == m3);
    }
}

TEST(Matrix4x4Tests, MatrixMultiplication)
{
    {
        Math::Array2D<float, 4, 4> init1;
        init1[0] = {2, 2, 2, 2};
        init1[1] = {3, 3, 3, 3};
        init1[2] = {4, 4, 4, 4};
        init1[3] = {5, 5, 5, 5};
        Math::Array2D<float, 4, 4> init2;
        init2[0] = {2, 3, 4, 5};
        init2[1] = {2, 3, 4, 5};
        init2[2] = {2, 3, 4, 5};
        init2[3] = {2, 3, 4, 5};

        const Matrix4x4f m1(init1);
        const Matrix4x4f m2(init2);

        Matrix4x4f m3 = m1 * m2;
        EXPECT_FLOAT_EQ(m3(0, 0), 16.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 24.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), 32.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 40.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 24.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), 36.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 48.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 60.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 32.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 48.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), 64.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), 80.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), 40.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), 60.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), 80.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 100.0f);

        m3 = m1;
        EXPECT_FLOAT_EQ(m3(0, 0), 2.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 2.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), 2.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 2.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 3.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), 3.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 3.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 3.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 4.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 4.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), 4.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), 4.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), 5.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), 5.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), 5.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 5.0f);

        m3 *= m2;
        EXPECT_FLOAT_EQ(m3(0, 0), 16.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 24.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), 32.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 40.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 24.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), 36.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 48.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 60.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 32.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 48.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), 64.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), 80.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), 40.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), 60.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), 80.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 100.0f);
    }
    {
        Math::Array2D<float, 4, 4> init1;
        init1[0] = {2, 2, 2, 2};
        init1[1] = {3, 3, 3, 3};
        init1[2] = {4, 4, 4, 4};
        init1[3] = {5, 5, 5, 5};
        Math::Array2D<float, 4, 4> init2;
        init2[0] = {2, 3, 4, 5};
        init2[1] = {2, 3, 4, 5};
        init2[2] = {2, 3, 4, 5};
        init2[3] = {2, 3, 4, 5};

        const Matrix4x4f m1(init1);
        const Matrix4x4f m2(init2);

        Matrix4x4f m3 = m1 * m2;
        EXPECT_DOUBLE_EQ(m3(0, 0), 16.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 24.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), 32.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 40.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 24.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), 36.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 48.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 60.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 32.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 48.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), 64.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), 80.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), 40.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), 60.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), 80.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 100.0);

        m3 = m1;
        EXPECT_DOUBLE_EQ(m3(0, 0), 2.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 2.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), 2.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 2.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 3.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), 3.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 3.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 3.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 4.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 4.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), 4.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), 4.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), 5.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), 5.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), 5.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 5.0);

        m3 *= m2;
        EXPECT_DOUBLE_EQ(m3(0, 0), 16.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 24.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), 32.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 40.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 24.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), 36.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 48.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 60.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 32.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 48.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), 64.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), 80.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), 40.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), 60.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), 80.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 100.0);
    }
    {
        Math::Array2D<float, 4, 4> init1;
        init1[0] = {2, 2, 2, 2};
        init1[1] = {3, 3, 3, 3};
        init1[2] = {4, 4, 4, 4};
        init1[3] = {5, 5, 5, 5};
        Math::Array2D<float, 4, 4> init2;
        init2[0] = {2, 3, 4, 5};
        init2[1] = {2, 3, 4, 5};
        init2[2] = {2, 3, 4, 5};
        init2[3] = {2, 3, 4, 5};

        const Matrix4x4f m1(init1);
        const Matrix4x4f m2(init2);

        Matrix4x4f m3 = m1 * m2;
        EXPECT_EQ(m3(0, 0), 16);
        EXPECT_EQ(m3(0, 1), 24);
        EXPECT_EQ(m3(0, 2), 32);
        EXPECT_EQ(m3(0, 3), 40);
        EXPECT_EQ(m3(1, 0), 24);
        EXPECT_EQ(m3(1, 1), 36);
        EXPECT_EQ(m3(1, 2), 48);
        EXPECT_EQ(m3(1, 3), 60);
        EXPECT_EQ(m3(2, 0), 32);
        EXPECT_EQ(m3(2, 1), 48);
        EXPECT_EQ(m3(2, 2), 64);
        EXPECT_EQ(m3(2, 3), 80);
        EXPECT_EQ(m3(3, 0), 40);
        EXPECT_EQ(m3(3, 1), 60);
        EXPECT_EQ(m3(3, 2), 80);
        EXPECT_EQ(m3(3, 3), 100);

        m3 = m1;
        EXPECT_EQ(m3(0, 0), 2);
        EXPECT_EQ(m3(0, 1), 2);
        EXPECT_EQ(m3(0, 2), 2);
        EXPECT_EQ(m3(0, 3), 2);
        EXPECT_EQ(m3(1, 0), 3);
        EXPECT_EQ(m3(1, 1), 3);
        EXPECT_EQ(m3(1, 2), 3);
        EXPECT_EQ(m3(1, 3), 3);
        EXPECT_EQ(m3(2, 0), 4);
        EXPECT_EQ(m3(2, 1), 4);
        EXPECT_EQ(m3(2, 2), 4);
        EXPECT_EQ(m3(2, 3), 4);
        EXPECT_EQ(m3(3, 0), 5);
        EXPECT_EQ(m3(3, 1), 5);
        EXPECT_EQ(m3(3, 2), 5);
        EXPECT_EQ(m3(3, 3), 5);

        m3 *= m2;
        EXPECT_EQ(m3(0, 0), 16);
        EXPECT_EQ(m3(0, 1), 24);
        EXPECT_EQ(m3(0, 2), 32);
        EXPECT_EQ(m3(0, 3), 40);
        EXPECT_EQ(m3(1, 0), 24);
        EXPECT_EQ(m3(1, 1), 36);
        EXPECT_EQ(m3(1, 2), 48);
        EXPECT_EQ(m3(1, 3), 60);
        EXPECT_EQ(m3(2, 0), 32);
        EXPECT_EQ(m3(2, 1), 48);
        EXPECT_EQ(m3(2, 2), 64);
        EXPECT_EQ(m3(2, 3), 80);
        EXPECT_EQ(m3(3, 0), 40);
        EXPECT_EQ(m3(3, 1), 60);
        EXPECT_EQ(m3(3, 2), 80);
        EXPECT_EQ(m3(3, 3), 100);
    }
}

TEST(Matrix4x4Tests, MatrixAddition)
{
    {
        Math::Array2D<float, 4, 4> init1;
        init1[0] = {2, 2, 2, 2};
        init1[1] = {3, 3, 3, 3};
        init1[2] = {4, 4, 4, 4};
        init1[3] = {5, 5, 5, 5};
        Math::Array2D<float, 4, 4> init2;
        init2[0] = {2, 3, 4, 5};
        init2[1] = {2, 3, 4, 5};
        init2[2] = {2, 3, 4, 5};
        init2[3] = {2, 3, 4, 5};

        const Matrix4x4f m1(init1);
        const Matrix4x4f m2(init2);

        Matrix4x4f m3 = m1 + m2;
        EXPECT_FLOAT_EQ(m3(0, 0), 4.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 5.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), 6.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 7.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 5.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), 6.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 7.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 8.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 6.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 7.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), 8.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), 9.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), 7.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), 8.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), 9.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 10.0f);

        m3 = m1;
        EXPECT_FLOAT_EQ(m3(0, 0), 2.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 2.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), 2.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 2.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 3.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), 3.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 3.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 3.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 4.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 4.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), 4.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), 4.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), 5.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), 5.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), 5.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 5.0f);

        m3 += m2;
        EXPECT_FLOAT_EQ(m3(0, 0), 4.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 5.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), 6.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 7.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 5.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), 6.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 7.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 8.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 6.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 7.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), 8.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), 9.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), 7.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), 8.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), 9.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 10.0f);
    }
    {
        Math::Array2D<float, 4, 4> init1;
        init1[0] = {2, 2, 2, 2};
        init1[1] = {3, 3, 3, 3};
        init1[2] = {4, 4, 4, 4};
        init1[3] = {5, 5, 5, 5};
        Math::Array2D<float, 4, 4> init2;
        init2[0] = {2, 3, 4, 5};
        init2[1] = {2, 3, 4, 5};
        init2[2] = {2, 3, 4, 5};
        init2[3] = {2, 3, 4, 5};

        const Matrix4x4f m1(init1);
        const Matrix4x4f m2(init2);

        Matrix4x4f m3 = m1 + m2;
        EXPECT_DOUBLE_EQ(m3(0, 0), 4.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 5.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), 6.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 7.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 5.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), 6.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 7.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 8.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 6.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 7.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), 8.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), 9.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), 7.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), 8.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), 9.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 10.0);

        m3 = m1;
        EXPECT_DOUBLE_EQ(m3(0, 0), 2.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 2.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), 2.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 2.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 3.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), 3.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 3.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 3.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 4.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 4.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), 4.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), 4.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), 5.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), 5.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), 5.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 5.0);

        m3 += m2;
        EXPECT_DOUBLE_EQ(m3(0, 0), 4.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 5.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), 6.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 7.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 5.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), 6.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 7.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 8.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 6.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 7.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), 8.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), 9.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), 7.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), 8.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), 9.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 10.0);
    }
    {
        Math::Array2D<float, 4, 4> init1;
        init1[0] = {2, 2, 2, 2};
        init1[1] = {3, 3, 3, 3};
        init1[2] = {4, 4, 4, 4};
        init1[3] = {5, 5, 5, 5};
        Math::Array2D<float, 4, 4> init2;
        init2[0] = {2, 3, 4, 5};
        init2[1] = {2, 3, 4, 5};
        init2[2] = {2, 3, 4, 5};
        init2[3] = {2, 3, 4, 5};

        const Matrix4x4f m1(init1);
        const Matrix4x4f m2(init2);

        Matrix4x4f m3 = m1 + m2;
        EXPECT_EQ(m3(0, 0), 4);
        EXPECT_EQ(m3(0, 1), 5);
        EXPECT_EQ(m3(0, 2), 6);
        EXPECT_EQ(m3(0, 3), 7);
        EXPECT_EQ(m3(1, 0), 5);
        EXPECT_EQ(m3(1, 1), 6);
        EXPECT_EQ(m3(1, 2), 7);
        EXPECT_EQ(m3(1, 3), 8);
        EXPECT_EQ(m3(2, 0), 6);
        EXPECT_EQ(m3(2, 1), 7);
        EXPECT_EQ(m3(2, 2), 8);
        EXPECT_EQ(m3(2, 3), 9);
        EXPECT_EQ(m3(3, 0), 7);
        EXPECT_EQ(m3(3, 1), 8);
        EXPECT_EQ(m3(3, 2), 9);
        EXPECT_EQ(m3(3, 3), 10);

        m3 = m1;
        EXPECT_EQ(m3(0, 0), 2);
        EXPECT_EQ(m3(0, 1), 2);
        EXPECT_EQ(m3(0, 2), 2);
        EXPECT_EQ(m3(0, 3), 2);
        EXPECT_EQ(m3(1, 0), 3);
        EXPECT_EQ(m3(1, 1), 3);
        EXPECT_EQ(m3(1, 2), 3);
        EXPECT_EQ(m3(1, 3), 3);
        EXPECT_EQ(m3(2, 0), 4);
        EXPECT_EQ(m3(2, 1), 4);
        EXPECT_EQ(m3(2, 2), 4);
        EXPECT_EQ(m3(2, 3), 4);
        EXPECT_EQ(m3(3, 0), 5);
        EXPECT_EQ(m3(3, 1), 5);
        EXPECT_EQ(m3(3, 2), 5);
        EXPECT_EQ(m3(3, 3), 5);

        m3 += m2;
        EXPECT_EQ(m3(0, 0), 4);
        EXPECT_EQ(m3(0, 1), 5);
        EXPECT_EQ(m3(0, 2), 6);
        EXPECT_EQ(m3(0, 3), 7);
        EXPECT_EQ(m3(1, 0), 5);
        EXPECT_EQ(m3(1, 1), 6);
        EXPECT_EQ(m3(1, 2), 7);
        EXPECT_EQ(m3(1, 3), 8);
        EXPECT_EQ(m3(2, 0), 6);
        EXPECT_EQ(m3(2, 1), 7);
        EXPECT_EQ(m3(2, 2), 8);
        EXPECT_EQ(m3(2, 3), 9);
        EXPECT_EQ(m3(3, 0), 7);
        EXPECT_EQ(m3(3, 1), 8);
        EXPECT_EQ(m3(3, 2), 9);
        EXPECT_EQ(m3(3, 3), 10);
    }
}

TEST(Matrix4x4Tests, MatrixSubtraction)
{
    {
        Math::Array2D<float, 4, 4> init1;
        init1[0] = {6, 6, 6, 6};
        init1[1] = {7, 7, 7, 7};
        init1[2] = {8, 8, 8, 8};
        init1[3] = {9, 9, 9, 9};
        Math::Array2D<float, 4, 4> init2;
        init2[0] = {2, 3, 4, 5};
        init2[1] = {2, 3, 4, 5};
        init2[2] = {2, 3, 4, 5};
        init2[3] = {2, 3, 4, 5};

        const Matrix4x4f m1(init1);
        const Matrix4x4f m2(init2);

        Matrix4x4f m3 = m1 - m2;
        EXPECT_FLOAT_EQ(m3(0, 0), 4.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 3.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), 2.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 1.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 5.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), 4.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 3.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 2.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 6.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 5.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), 4.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), 3.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), 7.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), 6.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), 5.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 4.0f);

        m3 = m1;
        EXPECT_FLOAT_EQ(m3(0, 0), 6.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 6.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), 6.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 6.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 7.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), 7.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 7.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 7.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 8.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 8.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), 8.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), 8.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), 9.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), 9.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), 9.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 9.0f);

        m3 -= m2;
        EXPECT_FLOAT_EQ(m3(0, 0), 4.0f);
        EXPECT_FLOAT_EQ(m3(0, 1), 3.0f);
        EXPECT_FLOAT_EQ(m3(0, 2), 2.0f);
        EXPECT_FLOAT_EQ(m3(0, 3), 1.0f);
        EXPECT_FLOAT_EQ(m3(1, 0), 5.0f);
        EXPECT_FLOAT_EQ(m3(1, 1), 4.0f);
        EXPECT_FLOAT_EQ(m3(1, 2), 3.0f);
        EXPECT_FLOAT_EQ(m3(1, 3), 2.0f);
        EXPECT_FLOAT_EQ(m3(2, 0), 6.0f);
        EXPECT_FLOAT_EQ(m3(2, 1), 5.0f);
        EXPECT_FLOAT_EQ(m3(2, 2), 4.0f);
        EXPECT_FLOAT_EQ(m3(2, 3), 3.0f);
        EXPECT_FLOAT_EQ(m3(3, 0), 7.0f);
        EXPECT_FLOAT_EQ(m3(3, 1), 6.0f);
        EXPECT_FLOAT_EQ(m3(3, 2), 5.0f);
        EXPECT_FLOAT_EQ(m3(3, 3), 4.0f);
    }
    {
        Math::Array2D<float, 4, 4> init1;
        init1[0] = {6, 6, 6, 6};
        init1[1] = {7, 7, 7, 7};
        init1[2] = {8, 8, 8, 8};
        init1[3] = {9, 9, 9, 9};
        Math::Array2D<float, 4, 4> init2;
        init2[0] = {2, 3, 4, 5};
        init2[1] = {2, 3, 4, 5};
        init2[2] = {2, 3, 4, 5};
        init2[3] = {2, 3, 4, 5};

        const Matrix4x4f m1(init1);
        const Matrix4x4f m2(init2);

        Matrix4x4f m3 = m1 - m2;
        EXPECT_DOUBLE_EQ(m3(0, 0), 4.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 3.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), 2.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 1.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 5.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), 4.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 3.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 2.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 6.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 5.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), 4.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), 3.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), 7.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), 6.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), 5.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 4.0);

        m3 = m1;
        EXPECT_DOUBLE_EQ(m3(0, 0), 6.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 6.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), 6.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 6.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 7.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), 7.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 7.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 7.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 8.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 8.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), 8.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), 8.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), 9.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), 9.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), 9.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 9.0);

        m3 -= m2;
        EXPECT_DOUBLE_EQ(m3(0, 0), 4.0);
        EXPECT_DOUBLE_EQ(m3(0, 1), 3.0);
        EXPECT_DOUBLE_EQ(m3(0, 2), 2.0);
        EXPECT_DOUBLE_EQ(m3(0, 3), 1.0);
        EXPECT_DOUBLE_EQ(m3(1, 0), 5.0);
        EXPECT_DOUBLE_EQ(m3(1, 1), 4.0);
        EXPECT_DOUBLE_EQ(m3(1, 2), 3.0);
        EXPECT_DOUBLE_EQ(m3(1, 3), 2.0);
        EXPECT_DOUBLE_EQ(m3(2, 0), 6.0);
        EXPECT_DOUBLE_EQ(m3(2, 1), 5.0);
        EXPECT_DOUBLE_EQ(m3(2, 2), 4.0);
        EXPECT_DOUBLE_EQ(m3(2, 3), 3.0);
        EXPECT_DOUBLE_EQ(m3(3, 0), 7.0);
        EXPECT_DOUBLE_EQ(m3(3, 1), 6.0);
        EXPECT_DOUBLE_EQ(m3(3, 2), 5.0);
        EXPECT_DOUBLE_EQ(m3(3, 3), 4.0);
    }
    {
        Math::Array2D<float, 4, 4> init1;
        init1[0] = {6, 6, 6, 6};
        init1[1] = {7, 7, 7, 7};
        init1[2] = {8, 8, 8, 8};
        init1[3] = {9, 9, 9, 9};
        Math::Array2D<float, 4, 4> init2;
        init2[0] = {2, 3, 4, 5};
        init2[1] = {2, 3, 4, 5};
        init2[2] = {2, 3, 4, 5};
        init2[3] = {2, 3, 4, 5};

        const Matrix4x4f m1(init1);
        const Matrix4x4f m2(init2);

        Matrix4x4f m3 = m1 - m2;
        EXPECT_EQ(m3(0, 0), 4);
        EXPECT_EQ(m3(0, 1), 3);
        EXPECT_EQ(m3(0, 2), 2);
        EXPECT_EQ(m3(0, 3), 1);
        EXPECT_EQ(m3(1, 0), 5);
        EXPECT_EQ(m3(1, 1), 4);
        EXPECT_EQ(m3(1, 2), 3);
        EXPECT_EQ(m3(1, 3), 2);
        EXPECT_EQ(m3(2, 0), 6);
        EXPECT_EQ(m3(2, 1), 5);
        EXPECT_EQ(m3(2, 2), 4);
        EXPECT_EQ(m3(2, 3), 3);
        EXPECT_EQ(m3(3, 0), 7);
        EXPECT_EQ(m3(3, 1), 6);
        EXPECT_EQ(m3(3, 2), 5);
        EXPECT_EQ(m3(3, 3), 4);

        m3 = m1;
        EXPECT_EQ(m3(0, 0), 6);
        EXPECT_EQ(m3(0, 1), 6);
        EXPECT_EQ(m3(0, 2), 6);
        EXPECT_EQ(m3(0, 3), 6);
        EXPECT_EQ(m3(1, 0), 7);
        EXPECT_EQ(m3(1, 1), 7);
        EXPECT_EQ(m3(1, 2), 7);
        EXPECT_EQ(m3(1, 3), 7);
        EXPECT_EQ(m3(2, 0), 8);
        EXPECT_EQ(m3(2, 1), 8);
        EXPECT_EQ(m3(2, 2), 8);
        EXPECT_EQ(m3(2, 3), 8);
        EXPECT_EQ(m3(3, 0), 9);
        EXPECT_EQ(m3(3, 1), 9);
        EXPECT_EQ(m3(3, 2), 9);
        EXPECT_EQ(m3(3, 3), 9);

        m3 -= m2;
        EXPECT_EQ(m3(0, 0), 4);
        EXPECT_EQ(m3(0, 1), 3);
        EXPECT_EQ(m3(0, 2), 2);
        EXPECT_EQ(m3(0, 3), 1);
        EXPECT_EQ(m3(1, 0), 5);
        EXPECT_EQ(m3(1, 1), 4);
        EXPECT_EQ(m3(1, 2), 3);
        EXPECT_EQ(m3(1, 3), 2);
        EXPECT_EQ(m3(2, 0), 6);
        EXPECT_EQ(m3(2, 1), 5);
        EXPECT_EQ(m3(2, 2), 4);
        EXPECT_EQ(m3(2, 3), 3);
        EXPECT_EQ(m3(3, 0), 7);
        EXPECT_EQ(m3(3, 1), 6);
        EXPECT_EQ(m3(3, 2), 5);
        EXPECT_EQ(m3(3, 3), 4);
    }
}

TEST(Matrix4x4Tests, ScalarMultiplication)
{
    {
        Math::Array2D<float, 4, 4> init;
        init[0] = {2, 2, 2, 2};
        init[1] = {3, 3, 3, 3};
        init[2] = {4, 4, 4, 4};
        init[3] = {5, 5, 5, 5};

        const Matrix4x4f m(init);

        Matrix4x4f m2 = m * 2.0f;
        EXPECT_FLOAT_EQ(m2(0, 0), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 1), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 2), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 3), 4.0f);
        EXPECT_FLOAT_EQ(m2(1, 0), 6.0f);
        EXPECT_FLOAT_EQ(m2(1, 1), 6.0f);
        EXPECT_FLOAT_EQ(m2(1, 2), 6.0f);
        EXPECT_FLOAT_EQ(m2(1, 3), 6.0f);
        EXPECT_FLOAT_EQ(m2(2, 0), 8.0f);
        EXPECT_FLOAT_EQ(m2(2, 1), 8.0f);
        EXPECT_FLOAT_EQ(m2(2, 2), 8.0f);
        EXPECT_FLOAT_EQ(m2(2, 3), 8.0f);
        EXPECT_FLOAT_EQ(m2(3, 0), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 1), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 2), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 3), 10.0f);

        m2 = m;
        EXPECT_FLOAT_EQ(m2(0, 0), 2.0f);
        EXPECT_FLOAT_EQ(m2(0, 1), 2.0f);
        EXPECT_FLOAT_EQ(m2(0, 2), 2.0f);
        EXPECT_FLOAT_EQ(m2(0, 3), 2.0f);
        EXPECT_FLOAT_EQ(m2(1, 0), 3.0f);
        EXPECT_FLOAT_EQ(m2(1, 1), 3.0f);
        EXPECT_FLOAT_EQ(m2(1, 2), 3.0f);
        EXPECT_FLOAT_EQ(m2(1, 3), 3.0f);
        EXPECT_FLOAT_EQ(m2(2, 0), 4.0f);
        EXPECT_FLOAT_EQ(m2(2, 1), 4.0f);
        EXPECT_FLOAT_EQ(m2(2, 2), 4.0f);
        EXPECT_FLOAT_EQ(m2(2, 3), 4.0f);
        EXPECT_FLOAT_EQ(m2(3, 0), 5.0f);
        EXPECT_FLOAT_EQ(m2(3, 1), 5.0f);
        EXPECT_FLOAT_EQ(m2(3, 2), 5.0f);
        EXPECT_FLOAT_EQ(m2(3, 3), 5.0f);

        m2 *= 2.0f;
        EXPECT_FLOAT_EQ(m2(0, 0), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 1), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 2), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 3), 4.0f);
        EXPECT_FLOAT_EQ(m2(1, 0), 6.0f);
        EXPECT_FLOAT_EQ(m2(1, 1), 6.0f);
        EXPECT_FLOAT_EQ(m2(1, 2), 6.0f);
        EXPECT_FLOAT_EQ(m2(1, 3), 6.0f);
        EXPECT_FLOAT_EQ(m2(2, 0), 8.0f);
        EXPECT_FLOAT_EQ(m2(2, 1), 8.0f);
        EXPECT_FLOAT_EQ(m2(2, 2), 8.0f);
        EXPECT_FLOAT_EQ(m2(2, 3), 8.0f);
        EXPECT_FLOAT_EQ(m2(3, 0), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 1), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 2), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 3), 10.0f);

        m2 = 2.0f * m;
        EXPECT_FLOAT_EQ(m2(0, 0), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 1), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 2), 4.0f);
        EXPECT_FLOAT_EQ(m2(0, 3), 4.0f);
        EXPECT_FLOAT_EQ(m2(1, 0), 6.0f);
        EXPECT_FLOAT_EQ(m2(1, 1), 6.0f);
        EXPECT_FLOAT_EQ(m2(1, 2), 6.0f);
        EXPECT_FLOAT_EQ(m2(1, 3), 6.0f);
        EXPECT_FLOAT_EQ(m2(2, 0), 8.0f);
        EXPECT_FLOAT_EQ(m2(2, 1), 8.0f);
        EXPECT_FLOAT_EQ(m2(2, 2), 8.0f);
        EXPECT_FLOAT_EQ(m2(2, 3), 8.0f);
        EXPECT_FLOAT_EQ(m2(3, 0), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 1), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 2), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 3), 10.0f);
    }
    {
        Math::Array2D<double, 4, 4> init;
        init[0] = {2, 2, 2, 2};
        init[1] = {3, 3, 3, 3};
        init[2] = {4, 4, 4, 4};
        init[3] = {5, 5, 5, 5};

        const Matrix4x4d m(init);

        Matrix4x4d m2 = m * 2.0;
        EXPECT_DOUBLE_EQ(m2(0, 0), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 1), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 2), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 3), 4.0);
        EXPECT_DOUBLE_EQ(m2(1, 0), 6.0);
        EXPECT_DOUBLE_EQ(m2(1, 1), 6.0);
        EXPECT_DOUBLE_EQ(m2(1, 2), 6.0);
        EXPECT_DOUBLE_EQ(m2(1, 3), 6.0);
        EXPECT_DOUBLE_EQ(m2(2, 0), 8.0);
        EXPECT_DOUBLE_EQ(m2(2, 1), 8.0);
        EXPECT_DOUBLE_EQ(m2(2, 2), 8.0);
        EXPECT_DOUBLE_EQ(m2(2, 3), 8.0);
        EXPECT_DOUBLE_EQ(m2(3, 0), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 1), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 2), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 3), 10.0);

        m2 = m;
        EXPECT_DOUBLE_EQ(m2(0, 0), 2.0);
        EXPECT_DOUBLE_EQ(m2(0, 1), 2.0);
        EXPECT_DOUBLE_EQ(m2(0, 2), 2.0);
        EXPECT_DOUBLE_EQ(m2(0, 3), 2.0);
        EXPECT_DOUBLE_EQ(m2(1, 0), 3.0);
        EXPECT_DOUBLE_EQ(m2(1, 1), 3.0);
        EXPECT_DOUBLE_EQ(m2(1, 2), 3.0);
        EXPECT_DOUBLE_EQ(m2(1, 3), 3.0);
        EXPECT_DOUBLE_EQ(m2(2, 0), 4.0);
        EXPECT_DOUBLE_EQ(m2(2, 1), 4.0);
        EXPECT_DOUBLE_EQ(m2(2, 2), 4.0);
        EXPECT_DOUBLE_EQ(m2(2, 3), 4.0);
        EXPECT_DOUBLE_EQ(m2(3, 0), 5.0);
        EXPECT_DOUBLE_EQ(m2(3, 1), 5.0);
        EXPECT_DOUBLE_EQ(m2(3, 2), 5.0);
        EXPECT_DOUBLE_EQ(m2(3, 3), 5.0);

        m2 *= 2.0;
        EXPECT_DOUBLE_EQ(m2(0, 0), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 1), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 2), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 3), 4.0);
        EXPECT_DOUBLE_EQ(m2(1, 0), 6.0);
        EXPECT_DOUBLE_EQ(m2(1, 1), 6.0);
        EXPECT_DOUBLE_EQ(m2(1, 2), 6.0);
        EXPECT_DOUBLE_EQ(m2(1, 3), 6.0);
        EXPECT_DOUBLE_EQ(m2(2, 0), 8.0);
        EXPECT_DOUBLE_EQ(m2(2, 1), 8.0);
        EXPECT_DOUBLE_EQ(m2(2, 2), 8.0);
        EXPECT_DOUBLE_EQ(m2(2, 3), 8.0);
        EXPECT_DOUBLE_EQ(m2(3, 0), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 1), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 2), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 3), 10.0);

        m2 = 2.0 * m;
        EXPECT_DOUBLE_EQ(m2(0, 0), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 1), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 2), 4.0);
        EXPECT_DOUBLE_EQ(m2(0, 3), 4.0);
        EXPECT_DOUBLE_EQ(m2(1, 0), 6.0);
        EXPECT_DOUBLE_EQ(m2(1, 1), 6.0);
        EXPECT_DOUBLE_EQ(m2(1, 2), 6.0);
        EXPECT_DOUBLE_EQ(m2(1, 3), 6.0);
        EXPECT_DOUBLE_EQ(m2(2, 0), 8.0);
        EXPECT_DOUBLE_EQ(m2(2, 1), 8.0);
        EXPECT_DOUBLE_EQ(m2(2, 2), 8.0);
        EXPECT_DOUBLE_EQ(m2(2, 3), 8.0);
        EXPECT_DOUBLE_EQ(m2(3, 0), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 1), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 2), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 3), 10.0);
    }
    {
        Math::Array2D<int32_t, 4, 4> init;
        init[0] = {2, 2, 2, 2};
        init[1] = {3, 3, 3, 3};
        init[2] = {4, 4, 4, 4};
        init[3] = {5, 5, 5, 5};

        const Matrix4x4i m(init);

        Matrix4x4i m2 = m * 2;
        EXPECT_EQ(m2(0, 0), 4);
        EXPECT_EQ(m2(0, 1), 4);
        EXPECT_EQ(m2(0, 2), 4);
        EXPECT_EQ(m2(0, 3), 4);
        EXPECT_EQ(m2(1, 0), 6);
        EXPECT_EQ(m2(1, 1), 6);
        EXPECT_EQ(m2(1, 2), 6);
        EXPECT_EQ(m2(1, 3), 6);
        EXPECT_EQ(m2(2, 0), 8);
        EXPECT_EQ(m2(2, 1), 8);
        EXPECT_EQ(m2(2, 2), 8);
        EXPECT_EQ(m2(2, 3), 8);
        EXPECT_EQ(m2(3, 0), 10);
        EXPECT_EQ(m2(3, 1), 10);
        EXPECT_EQ(m2(3, 2), 10);
        EXPECT_EQ(m2(3, 3), 10);

        m2 = m;
        EXPECT_EQ(m2(0, 0), 2);
        EXPECT_EQ(m2(0, 1), 2);
        EXPECT_EQ(m2(0, 2), 2);
        EXPECT_EQ(m2(0, 3), 2);
        EXPECT_EQ(m2(1, 0), 3);
        EXPECT_EQ(m2(1, 1), 3);
        EXPECT_EQ(m2(1, 2), 3);
        EXPECT_EQ(m2(1, 3), 3);
        EXPECT_EQ(m2(2, 0), 4);
        EXPECT_EQ(m2(2, 1), 4);
        EXPECT_EQ(m2(2, 2), 4);
        EXPECT_EQ(m2(2, 3), 4);
        EXPECT_EQ(m2(3, 0), 5);
        EXPECT_EQ(m2(3, 1), 5);
        EXPECT_EQ(m2(3, 2), 5);
        EXPECT_EQ(m2(3, 3), 5);

        m2 *= 2;
        EXPECT_EQ(m2(0, 0), 4);
        EXPECT_EQ(m2(0, 1), 4);
        EXPECT_EQ(m2(0, 2), 4);
        EXPECT_EQ(m2(0, 3), 4);
        EXPECT_EQ(m2(1, 0), 6);
        EXPECT_EQ(m2(1, 1), 6);
        EXPECT_EQ(m2(1, 2), 6);
        EXPECT_EQ(m2(1, 3), 6);
        EXPECT_EQ(m2(2, 0), 8);
        EXPECT_EQ(m2(2, 1), 8);
        EXPECT_EQ(m2(2, 2), 8);
        EXPECT_EQ(m2(2, 3), 8);
        EXPECT_EQ(m2(3, 0), 10);
        EXPECT_EQ(m2(3, 1), 10);
        EXPECT_EQ(m2(3, 2), 10);
        EXPECT_EQ(m2(3, 3), 10);

        m2 = 2 * m;
        EXPECT_EQ(m2(0, 0), 4);
        EXPECT_EQ(m2(0, 1), 4);
        EXPECT_EQ(m2(0, 2), 4);
        EXPECT_EQ(m2(0, 3), 4);
        EXPECT_EQ(m2(1, 0), 6);
        EXPECT_EQ(m2(1, 1), 6);
        EXPECT_EQ(m2(1, 2), 6);
        EXPECT_EQ(m2(1, 3), 6);
        EXPECT_EQ(m2(2, 0), 8);
        EXPECT_EQ(m2(2, 1), 8);
        EXPECT_EQ(m2(2, 2), 8);
        EXPECT_EQ(m2(2, 3), 8);
        EXPECT_EQ(m2(3, 0), 10);
        EXPECT_EQ(m2(3, 1), 10);
        EXPECT_EQ(m2(3, 2), 10);
        EXPECT_EQ(m2(3, 3), 10);
    }
}

TEST(Matrix4x4Tests, ScalarDivision)
{
    {
        Math::Array2D<float, 4, 4> init;
        init[0] = {2, 2, 2, 2};
        init[1] = {4, 4, 4, 4};
        init[2] = {6, 6, 6, 6};
        init[3] = {8, 8, 8, 8};

        const Matrix4x4f m(init);

        Matrix4x4f m2 = m / 2.0f;
        EXPECT_FLOAT_EQ(m2(0, 0), 1.0f);
        EXPECT_FLOAT_EQ(m2(0, 1), 1.0f);
        EXPECT_FLOAT_EQ(m2(0, 2), 1.0f);
        EXPECT_FLOAT_EQ(m2(0, 3), 1.0f);
        EXPECT_FLOAT_EQ(m2(1, 0), 2.0f);
        EXPECT_FLOAT_EQ(m2(1, 1), 2.0f);
        EXPECT_FLOAT_EQ(m2(1, 2), 2.0f);
        EXPECT_FLOAT_EQ(m2(1, 3), 2.0f);
        EXPECT_FLOAT_EQ(m2(2, 0), 3.0f);
        EXPECT_FLOAT_EQ(m2(2, 1), 3.0f);
        EXPECT_FLOAT_EQ(m2(2, 2), 3.0f);
        EXPECT_FLOAT_EQ(m2(2, 3), 3.0f);
        EXPECT_FLOAT_EQ(m2(3, 0), 4.0f);
        EXPECT_FLOAT_EQ(m2(3, 1), 4.0f);
        EXPECT_FLOAT_EQ(m2(3, 2), 4.0f);
        EXPECT_FLOAT_EQ(m2(3, 3), 4.0f);

        m2 = m;
        EXPECT_FLOAT_EQ(m2(0, 0), 2.0f);
        EXPECT_FLOAT_EQ(m2(0, 1), 2.0f);
        EXPECT_FLOAT_EQ(m2(0, 2), 2.0f);
        EXPECT_FLOAT_EQ(m2(0, 3), 2.0f);
        EXPECT_FLOAT_EQ(m2(1, 0), 4.0f);
        EXPECT_FLOAT_EQ(m2(1, 1), 4.0f);
        EXPECT_FLOAT_EQ(m2(1, 2), 4.0f);
        EXPECT_FLOAT_EQ(m2(1, 3), 4.0f);
        EXPECT_FLOAT_EQ(m2(2, 0), 6.0f);
        EXPECT_FLOAT_EQ(m2(2, 1), 6.0f);
        EXPECT_FLOAT_EQ(m2(2, 2), 6.0f);
        EXPECT_FLOAT_EQ(m2(2, 3), 6.0f);
        EXPECT_FLOAT_EQ(m2(3, 0), 8.0f);
        EXPECT_FLOAT_EQ(m2(3, 1), 8.0f);
        EXPECT_FLOAT_EQ(m2(3, 2), 8.0f);
        EXPECT_FLOAT_EQ(m2(3, 3), 8.0f);

        m2 /= 2.0f;
        EXPECT_FLOAT_EQ(m2(0, 0), 1.0f);
        EXPECT_FLOAT_EQ(m2(0, 1), 1.0f);
        EXPECT_FLOAT_EQ(m2(0, 2), 1.0f);
        EXPECT_FLOAT_EQ(m2(0, 3), 1.0f);
        EXPECT_FLOAT_EQ(m2(1, 0), 2.0f);
        EXPECT_FLOAT_EQ(m2(1, 1), 2.0f);
        EXPECT_FLOAT_EQ(m2(1, 2), 2.0f);
        EXPECT_FLOAT_EQ(m2(1, 3), 2.0f);
        EXPECT_FLOAT_EQ(m2(2, 0), 3.0f);
        EXPECT_FLOAT_EQ(m2(2, 1), 3.0f);
        EXPECT_FLOAT_EQ(m2(2, 2), 3.0f);
        EXPECT_FLOAT_EQ(m2(2, 3), 3.0f);
        EXPECT_FLOAT_EQ(m2(3, 0), 4.0f);
        EXPECT_FLOAT_EQ(m2(3, 1), 4.0f);
        EXPECT_FLOAT_EQ(m2(3, 2), 4.0f);
        EXPECT_FLOAT_EQ(m2(3, 3), 4.0f);
    }
    {
        Math::Array2D<double, 4, 4> init;
        init[0] = {2, 2, 2, 2};
        init[1] = {4, 4, 4, 4};
        init[2] = {6, 6, 6, 6};
        init[3] = {8, 8, 8, 8};
        
        const Matrix4x4d m(init);

        Matrix4x4d m2 = m / 2.0;
        EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
        EXPECT_DOUBLE_EQ(m2(0, 1), 1.0);
        EXPECT_DOUBLE_EQ(m2(0, 2), 1.0);
        EXPECT_DOUBLE_EQ(m2(0, 3), 1.0);
        EXPECT_DOUBLE_EQ(m2(1, 0), 2.0);
        EXPECT_DOUBLE_EQ(m2(1, 1), 2.0);
        EXPECT_DOUBLE_EQ(m2(1, 2), 2.0);
        EXPECT_DOUBLE_EQ(m2(1, 3), 2.0);
        EXPECT_DOUBLE_EQ(m2(2, 0), 3.0);
        EXPECT_DOUBLE_EQ(m2(2, 1), 3.0);
        EXPECT_DOUBLE_EQ(m2(2, 2), 3.0);
        EXPECT_DOUBLE_EQ(m2(2, 3), 3.0);
        EXPECT_DOUBLE_EQ(m2(3, 0), 4.0);
        EXPECT_DOUBLE_EQ(m2(3, 1), 4.0);
        EXPECT_DOUBLE_EQ(m2(3, 2), 4.0);
        EXPECT_DOUBLE_EQ(m2(3, 3), 4.0);

        m2 = m;
        EXPECT_DOUBLE_EQ(m2(0, 0), 2.0);
        EXPECT_DOUBLE_EQ(m2(0, 1), 2.0);
        EXPECT_DOUBLE_EQ(m2(0, 2), 2.0);
        EXPECT_DOUBLE_EQ(m2(0, 3), 2.0);
        EXPECT_DOUBLE_EQ(m2(1, 0), 4.0);
        EXPECT_DOUBLE_EQ(m2(1, 1), 4.0);
        EXPECT_DOUBLE_EQ(m2(1, 2), 4.0);
        EXPECT_DOUBLE_EQ(m2(1, 3), 4.0);
        EXPECT_DOUBLE_EQ(m2(2, 0), 6.0);
        EXPECT_DOUBLE_EQ(m2(2, 1), 6.0);
        EXPECT_DOUBLE_EQ(m2(2, 2), 6.0);
        EXPECT_DOUBLE_EQ(m2(2, 3), 6.0);
        EXPECT_DOUBLE_EQ(m2(3, 0), 8.0);
        EXPECT_DOUBLE_EQ(m2(3, 1), 8.0);
        EXPECT_DOUBLE_EQ(m2(3, 2), 8.0);
        EXPECT_DOUBLE_EQ(m2(3, 3), 8.0);

        m2 /= 2.0;
        EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
        EXPECT_DOUBLE_EQ(m2(0, 1), 1.0);
        EXPECT_DOUBLE_EQ(m2(0, 2), 1.0);
        EXPECT_DOUBLE_EQ(m2(0, 3), 1.0);
        EXPECT_DOUBLE_EQ(m2(1, 0), 2.0);
        EXPECT_DOUBLE_EQ(m2(1, 1), 2.0);
        EXPECT_DOUBLE_EQ(m2(1, 2), 2.0);
        EXPECT_DOUBLE_EQ(m2(1, 3), 2.0);
        EXPECT_DOUBLE_EQ(m2(2, 0), 3.0);
        EXPECT_DOUBLE_EQ(m2(2, 1), 3.0);
        EXPECT_DOUBLE_EQ(m2(2, 2), 3.0);
        EXPECT_DOUBLE_EQ(m2(2, 3), 3.0);
        EXPECT_DOUBLE_EQ(m2(3, 0), 4.0);
        EXPECT_DOUBLE_EQ(m2(3, 1), 4.0);
        EXPECT_DOUBLE_EQ(m2(3, 2), 4.0);
        EXPECT_DOUBLE_EQ(m2(3, 3), 4.0);
    }
    {
        Math::Array2D<int32_t, 4, 4> init;
        init[0] = {2, 2, 2, 2};
        init[1] = {4, 4, 4, 4};
        init[2] = {6, 6, 6, 6};
        init[3] = {8, 8, 8, 8};

        const Matrix4x4i m(init);

        Matrix4x4i m2 = m / 2;
        EXPECT_EQ(m2(0, 0), 1);
        EXPECT_EQ(m2(0, 1), 1);
        EXPECT_EQ(m2(0, 2), 1);
        EXPECT_EQ(m2(0, 3), 1);
        EXPECT_EQ(m2(1, 0), 2);
        EXPECT_EQ(m2(1, 1), 2);
        EXPECT_EQ(m2(1, 2), 2);
        EXPECT_EQ(m2(1, 3), 2);
        EXPECT_EQ(m2(2, 0), 3);
        EXPECT_EQ(m2(2, 1), 3);
        EXPECT_EQ(m2(2, 2), 3);
        EXPECT_EQ(m2(2, 3), 3);
        EXPECT_EQ(m2(3, 0), 4);
        EXPECT_EQ(m2(3, 1), 4);
        EXPECT_EQ(m2(3, 2), 4);
        EXPECT_EQ(m2(3, 3), 4);

        m2 = m;
        EXPECT_EQ(m2(0, 0), 2);
        EXPECT_EQ(m2(0, 1), 2);
        EXPECT_EQ(m2(0, 2), 2);
        EXPECT_EQ(m2(0, 3), 2);
        EXPECT_EQ(m2(1, 0), 4);
        EXPECT_EQ(m2(1, 1), 4);
        EXPECT_EQ(m2(1, 2), 4);
        EXPECT_EQ(m2(1, 3), 4);
        EXPECT_EQ(m2(2, 0), 6);
        EXPECT_EQ(m2(2, 1), 6);
        EXPECT_EQ(m2(2, 2), 6);
        EXPECT_EQ(m2(2, 3), 6);
        EXPECT_EQ(m2(3, 0), 8);
        EXPECT_EQ(m2(3, 1), 8);
        EXPECT_EQ(m2(3, 2), 8);
        EXPECT_EQ(m2(3, 3), 8);

        m2 /= 2;
        EXPECT_EQ(m2(0, 0), 1);
        EXPECT_EQ(m2(0, 1), 1);
        EXPECT_EQ(m2(0, 2), 1);
        EXPECT_EQ(m2(0, 3), 1);
        EXPECT_EQ(m2(1, 0), 2);
        EXPECT_EQ(m2(1, 1), 2);
        EXPECT_EQ(m2(1, 2), 2);
        EXPECT_EQ(m2(1, 3), 2);
        EXPECT_EQ(m2(2, 0), 3);
        EXPECT_EQ(m2(2, 1), 3);
        EXPECT_EQ(m2(2, 2), 3);
        EXPECT_EQ(m2(2, 3), 3);
        EXPECT_EQ(m2(3, 0), 4);
        EXPECT_EQ(m2(3, 1), 4);
        EXPECT_EQ(m2(3, 2), 4);
        EXPECT_EQ(m2(3, 3), 4);
    }
}

 TEST(Matrix4x4Tests, Transpose)
{
    {
        // clang-format off
         const Matrix4x4f m1(
             1.0f, 4.0f, -4.0f, 5.0f,
             3.0f, -2.0f, 1.0f, 10.0f,
             7.0f, 10.0f, -5.0f, -3.0f,
            -6.0f, -2.0f, -1.0f, 9.0f
         );
        // clang-format on

        const Matrix4x4f m2 = Math::Transpose(m1);
        EXPECT_FLOAT_EQ(m2(0, 0), 1.0f);
        EXPECT_FLOAT_EQ(m2(0, 1), 3.0f);
        EXPECT_FLOAT_EQ(m2(0, 2), 7.0f);
        EXPECT_FLOAT_EQ(m2(0, 3), -6.0f);
        EXPECT_FLOAT_EQ(m2(1, 0), 4.0f);
        EXPECT_FLOAT_EQ(m2(1, 1), -2.0f);
        EXPECT_FLOAT_EQ(m2(1, 2), 10.0f);
        EXPECT_FLOAT_EQ(m2(1, 3), -2.0f);
        EXPECT_FLOAT_EQ(m2(2, 0), -4.0f);
        EXPECT_FLOAT_EQ(m2(2, 1), 1.0f);
        EXPECT_FLOAT_EQ(m2(2, 2), -5.0f);
        EXPECT_FLOAT_EQ(m2(2, 3), -1.0f);
        EXPECT_FLOAT_EQ(m2(3, 0), 5.0f);
        EXPECT_FLOAT_EQ(m2(3, 1), 10.0f);
        EXPECT_FLOAT_EQ(m2(3, 2), -3.0f);
        EXPECT_FLOAT_EQ(m2(3, 3), 9.0f);
    }
    {
        // clang-format off
         const Matrix4x4d m1(
             1.0, 4.0, -4.0, 5.0,
             3.0, -2.0, 1.0, 10.0,
             7.0, 10.0, -5.0, -3.0,
            -6.0, -2.0, -1.0, 9.0
         );
        // clang-format on

        const Matrix4x4d m2 = Math::Transpose(m1);
        EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
        EXPECT_DOUBLE_EQ(m2(0, 1), 3.0);
        EXPECT_DOUBLE_EQ(m2(0, 2), 7.0);
        EXPECT_DOUBLE_EQ(m2(0, 3), -6.0);
        EXPECT_DOUBLE_EQ(m2(1, 0), 4.0);
        EXPECT_DOUBLE_EQ(m2(1, 1), -2.0);
        EXPECT_DOUBLE_EQ(m2(1, 2), 10.0);
        EXPECT_DOUBLE_EQ(m2(1, 3), -2.0);
        EXPECT_DOUBLE_EQ(m2(2, 0), -4.0);
        EXPECT_DOUBLE_EQ(m2(2, 1), 1.0);
        EXPECT_DOUBLE_EQ(m2(2, 2), -5.0);
        EXPECT_DOUBLE_EQ(m2(2, 3), -1.0);
        EXPECT_DOUBLE_EQ(m2(3, 0), 5.0);
        EXPECT_DOUBLE_EQ(m2(3, 1), 10.0);
        EXPECT_DOUBLE_EQ(m2(3, 2), -3.0);
        EXPECT_DOUBLE_EQ(m2(3, 3), 9.0);
    }
    {
        // clang-format off
         const Matrix4x4i m1(
             1, 4, -4, 5,
             3, -2, 1, 10,
             7, 10, -5, -3,
            -6, -2, -1, 9
         );
        // clang-format on

        const Matrix4x4i m2 = Math::Transpose(m1);
        EXPECT_EQ(m2(0, 0), 1);
        EXPECT_EQ(m2(0, 1), 3);
        EXPECT_EQ(m2(0, 2), 7);
        EXPECT_EQ(m2(0, 3), -6);
        EXPECT_EQ(m2(1, 0), 4);
        EXPECT_EQ(m2(1, 1), -2);
        EXPECT_EQ(m2(1, 2), 10);
        EXPECT_EQ(m2(1, 3), -2);
        EXPECT_EQ(m2(2, 0), -4);
        EXPECT_EQ(m2(2, 1), 1);
        EXPECT_EQ(m2(2, 2), -5);
        EXPECT_EQ(m2(2, 3), -1);
        EXPECT_EQ(m2(3, 0), 5);
        EXPECT_EQ(m2(3, 1), 10);
        EXPECT_EQ(m2(3, 2), -3);
        EXPECT_EQ(m2(3, 3), 9);
    }
 }

 TEST(Matrix4x4Tests, Inverse)
{
    {
        Matrix4x4f m1(1);
        m1.elements[0][3] = 5.0f;
        m1.elements[1][3] = 10.0f;
        m1.elements[2][3] = -2.0f;

        const Matrix4x4f m2 = Math::Inverse(m1);
        EXPECT_FLOAT_EQ(m2.elements[0][0], 1.0f);
        EXPECT_FLOAT_EQ(m2.elements[0][1], 0.0f);
        EXPECT_FLOAT_EQ(m2.elements[0][2], 0.0f);
        EXPECT_FLOAT_EQ(m2.elements[0][3], -5.0f);
        EXPECT_FLOAT_EQ(m2.elements[1][0], 0.0f);
        EXPECT_FLOAT_EQ(m2.elements[1][1], 1.0f);
        EXPECT_FLOAT_EQ(m2.elements[1][2], 0.0f);
        EXPECT_FLOAT_EQ(m2.elements[1][3], -10.0f);
        EXPECT_FLOAT_EQ(m2.elements[2][0], 0.0f);
        EXPECT_FLOAT_EQ(m2.elements[2][1], 0.0f);
        EXPECT_FLOAT_EQ(m2.elements[2][2], 1.0f);
        EXPECT_FLOAT_EQ(m2.elements[2][3], 2.0f);
        EXPECT_FLOAT_EQ(m2.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(m2.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(m2.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(m2.elements[3][3], 1.0f);
    }
    {
        Matrix4x4d m1(1);
        m1.elements[0][3] = 5.0;
        m1.elements[1][3] = 10.0;
        m1.elements[2][3] = -2.0;

        const Matrix4x4d m2 = Math::Inverse(m1);
        EXPECT_DOUBLE_EQ(m2.elements[0][0], 1.0);
        EXPECT_DOUBLE_EQ(m2.elements[0][1], 0.0);
        EXPECT_DOUBLE_EQ(m2.elements[0][2], 0.0);
        EXPECT_DOUBLE_EQ(m2.elements[0][3], -5.0);
        EXPECT_DOUBLE_EQ(m2.elements[1][0], 0.0);
        EXPECT_DOUBLE_EQ(m2.elements[1][1], 1.0);
        EXPECT_DOUBLE_EQ(m2.elements[1][2], 0.0);
        EXPECT_DOUBLE_EQ(m2.elements[1][3], -10.0);
        EXPECT_DOUBLE_EQ(m2.elements[2][0], 0.0);
        EXPECT_DOUBLE_EQ(m2.elements[2][1], 0.0);
        EXPECT_DOUBLE_EQ(m2.elements[2][2], 1.0);
        EXPECT_DOUBLE_EQ(m2.elements[2][3], 2.0);
        EXPECT_DOUBLE_EQ(m2.elements[3][0], 0.0);
        EXPECT_DOUBLE_EQ(m2.elements[3][1], 0.0);
        EXPECT_DOUBLE_EQ(m2.elements[3][2], 0.0);
        EXPECT_DOUBLE_EQ(m2.elements[3][3], 1.0);
    }
 }
