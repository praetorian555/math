#include "math/matrix4x4.h"

#include <cassert>
#include <cmath>
#include <cstring>
#include <utility>

math::Matrix4x4::Matrix4x4() : Data{}
{
    Data[0][0] = 1.0f;
    Data[0][1] = 0.0f;
    Data[0][2] = 0.0f;
    Data[0][3] = 0.0f;

    Data[1][0] = 0.0f;
    Data[1][1] = 1.0f;
    Data[1][2] = 0.0f;
    Data[1][3] = 0.0f;

    Data[2][0] = 0.0f;
    Data[2][1] = 0.0f;
    Data[2][2] = 1.0f;
    Data[2][3] = 0.0f;

    Data[3][0] = 0.0f;
    Data[3][1] = 0.0f;
    Data[3][2] = 0.0f;
    Data[3][3] = 1.0f;
}

math::Matrix4x4::Matrix4x4(const Array2D<float, 4, 4>& Mat) : Data{}
{
    Data[0][0] = Mat[0][0];
    Data[0][1] = Mat[0][1];
    Data[0][2] = Mat[0][2];
    Data[0][3] = Mat[0][3];

    Data[1][0] = Mat[1][0];
    Data[1][1] = Mat[1][1];
    Data[1][2] = Mat[1][2];
    Data[1][3] = Mat[1][3];

    Data[2][0] = Mat[2][0];
    Data[2][1] = Mat[2][1];
    Data[2][2] = Mat[2][2];
    Data[2][3] = Mat[2][3];

    Data[3][0] = Mat[3][0];
    Data[3][1] = Mat[3][1];
    Data[3][2] = Mat[3][2];
    Data[3][3] = Mat[3][3];
}

// clang-format off
math::Matrix4x4::Matrix4x4(
    float t00, float t01, float t02, float t03,
    float t10, float t11, float t12, float t13,
    float t20, float t21, float t22, float t23,
    float t30, float t31, float t32, float t33) : Data{}
// clang-format on
{
    Data[0][0] = t00;
    Data[0][1] = t01;
    Data[0][2] = t02;
    Data[0][3] = t03;

    Data[1][0] = t10;
    Data[1][1] = t11;
    Data[1][2] = t12;
    Data[1][3] = t13;

    Data[2][0] = t20;
    Data[2][1] = t21;
    Data[2][2] = t22;
    Data[2][3] = t23;

    Data[3][0] = t30;
    Data[3][1] = t31;
    Data[3][2] = t32;
    Data[3][3] = t33;
}

bool math::Matrix4x4::operator==(const Matrix4x4& Other) const
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (Data[i][j] != Other.Data[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

bool math::Matrix4x4::operator!=(const Matrix4x4& Other) const
{
    return !(*this == Other);
}

math::Matrix4x4 math::Matrix4x4::Transpose() const
{
    // clang-format off
    return {
        Data[0][0], Data[1][0], Data[2][0], Data[3][0],
        Data[0][1], Data[1][1], Data[2][1], Data[3][1],
        Data[0][2], Data[1][2], Data[2][2], Data[3][2],
        Data[0][3], Data[1][3], Data[2][3], Data[3][3]
    };
    // clang-format on
}

math::Matrix4x4 math::Matrix4x4::Inverse() const
{
    // TODO(mkostic): Taken from the mmp\pbrt-v3 on GitHub, refactor this

    std::array<int, 4> Indxc = {0, 0, 0, 0};
    std::array<int, 4> Indxr = {0, 0, 0, 0};
    std::array<int, 4> Ipiv = {0, 0, 0, 0};
    Array2D<float, 4, 4> minv;
    minv = Data;
    for (int i = 0; i < 4; i++)
    {
        int irow = 0;
        int icol = 0;
        float big = 0.f;
        // Choose pivot
        for (int j = 0; j < 4; j++)
        {
            if (Ipiv[j] == 1)
            {
                continue;
            }
            for (int k = 0; k < 4; k++)
            {
                if (Ipiv[k] == 0)
                {
                    if (std::abs(minv[j][k]) >= big)
                    {
                        big = float(std::abs(minv[j][k]));
                        irow = j;
                        icol = k;
                    }
                }
                else if (Ipiv[k] > 1)
                {
                    // Singluar matrix
                    assert(false);
                }
            }
        }
        ++Ipiv[icol];
        // Swap rows _irow_ and _icol_ for pivot
        if (irow != icol)
        {
            for (int k = 0; k < 4; ++k)
            {
                std::swap(minv[irow][k], minv[icol][k]);
            }
        }
        Indxr[i] = irow;
        Indxc[i] = icol;
        if (minv[icol][icol] == 0.f)
        {
            // Singluar matrix
            assert(false);
        }

        // Set $m[icol][icol]$ to one by scaling row _icol_ appropriately
        const float pivinv = 1.0f / minv[icol][icol];
        minv[icol][icol] = 1.0f;
        for (int j = 0; j < 4; j++)
        {
            minv[icol][j] *= pivinv;
        }

        // Subtract this row from Others to zero out their columns
        for (int j = 0; j < 4; j++)
        {
            if (j != icol)
            {
                const float save = minv[j][icol];
                minv[j][icol] = 0;
                for (int k = 0; k < 4; k++)
                {
                    minv[j][k] -= minv[icol][k] * save;
                }
            }
        }
    }

    // Swap columns to reflect permutation
    for (int j = 3; j >= 0; j--)
    {
        if (Indxr[j] != Indxc[j])
        {
            for (int k = 0; k < 4; k++)
            {
                std::swap(minv[k][Indxr[j]], minv[k][Indxc[j]]);
            }
        }
    }

    return Matrix4x4(minv);
}

math::Matrix4x4 math::Multiply(const Matrix4x4& m1, const Matrix4x4& m2)
{
    Matrix4x4 r;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            // clang-format off
            r.Data[i][j] = m1.Data[i][0] * m2.Data[0][j] + 
                           m1.Data[i][1] * m2.Data[1][j] +
                           m1.Data[i][2] * m2.Data[2][j] +
                           m1.Data[i][3] * m2.Data[3][j];
            // clang-format on
        }
    }
    return r;
}
