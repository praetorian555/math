#include "math/matrix4x4.h"

#include <cassert>
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

math::Matrix4x4::Matrix4x4(const Array2D<real, 4, 4>& Mat) : Data{}
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
    real T00, real T01, real T02, real T03,
    real T10, real T11, real T12, real T13,
    real T20, real T21, real T22, real T23,
    real T30, real T31, real T32, real T33) : Data{}
// clang-format on
{
    Data[0][0] = T00;
    Data[0][1] = T01;
    Data[0][2] = T02;
    Data[0][3] = T03;

    Data[1][0] = T10;
    Data[1][1] = T11;
    Data[1][2] = T12;
    Data[1][3] = T13;

    Data[2][0] = T20;
    Data[2][1] = T21;
    Data[2][2] = T22;
    Data[2][3] = T23;

    Data[3][0] = T30;
    Data[3][1] = T31;
    Data[3][2] = T32;
    Data[3][3] = T33;
}

bool math::Matrix4x4::operator==(const Matrix4x4& Other) const
{
    for (int Row = 0; Row < 4; Row++)
    {
        for (int Column = 0; Column < 4; Column++)
        {
            if (Data[Row][Column] != Other.Data[Row][Column])
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
    std::array<int, 4> Indxc = {0, 0, 0, 0};
    std::array<int, 4> Indxr = {0, 0, 0, 0};
    std::array<int, 4> Ipiv = {0, 0, 0, 0};
    Array2D<real, 4, 4> MatInv;
    MatInv = Data;
    for (int It = 0; It < 4; It++)
    {
        int IndexRow = 0;
        int IndexColumn = 0;
        real Big = 0.f;
        // Choose pivot
        for (int Row = 0; Row < 4; Row++)
        {
            if (Ipiv[Row] == 1)
            {
                continue;
            }
            for (int Column = 0; Column < 4; Column++)
            {
                if (Ipiv[Column] == 0)
                {
                    if (math::Abs(MatInv[Row][Column]) >= Big)
                    {
                        Big = math::Abs(MatInv[Row][Column]);
                        IndexRow = Row;
                        IndexColumn = Column;
                    }
                }
                else if (Ipiv[Column] > 1)
                {
                    // Singluar matrix
                    assert(false);
                }
            }
        }
        ++Ipiv[IndexColumn];
        // Swap rows _irow_ and _icol_ for pivot
        if (IndexRow != IndexColumn)
        {
            for (int Column = 0; Column < 4; Column++)
            {
                std::swap(MatInv[IndexRow][Column], MatInv[IndexColumn][Column]);
            }
        }
        Indxr[It] = IndexRow;
        Indxc[It] = IndexColumn;
        if (MatInv[IndexColumn][IndexColumn] == 0.f)
        {
            // Singluar matrix
            assert(false);
        }

        // Set $m[icol][icol]$ to one by scaling row _icol_ appropriately
        const real Pivinv = 1.0f / MatInv[IndexColumn][IndexColumn];
        MatInv[IndexColumn][IndexColumn] = 1.0f;
        for (int Column = 0; Column < 4; Column++)
        {
            MatInv[IndexColumn][Column] *= Pivinv;
        }

        // Subtract this row from Others to zero out their columns
        for (int Row = 0; Row < 4; Row++)
        {
            if (Row != IndexColumn)
            {
                const real Save = MatInv[Row][IndexColumn];
                MatInv[Row][IndexColumn] = 0;
                for (int Column = 0; Column < 4; Column++)
                {
                    MatInv[Row][Column] -= MatInv[IndexColumn][Column] * Save;
                }
            }
        }
    }

    // Swap columns to reflect permutation
    for (int Column = 3; Column >= 0; Column--)
    {
        if (Indxr[Column] != Indxc[Column])
        {
            for (int Row = 0; Row < 4; Row++)
            {
                std::swap(MatInv[Row][Indxr[Column]], MatInv[Row][Indxc[Column]]);
            }
        }
    }

    return Matrix4x4(MatInv);
}

math::Matrix4x4 math::Multiply(const Matrix4x4& M1, const Matrix4x4& M2)
{
    Matrix4x4 Res;
    for (int Row = 0; Row < 4; Row++)
    {
        for (int Column = 0; Column < 4; Column++)
        {
            Res.Data[Row][Column] =
                M1.Data[Row][0] * M2.Data[0][Column] + M1.Data[Row][1] * M2.Data[1][Column] +
                M1.Data[Row][2] * M2.Data[2][Column] + M1.Data[Row][3] * M2.Data[3][Column];
        }
    }
    return Res;
}
