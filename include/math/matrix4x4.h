#pragma once

#include <array>

#include "math/base.h"

namespace math
{

template <typename T, int N, int M>
using Array2D = std::array<std::array<T, M>, N>;

struct Matrix4x4
{
    Array2D<float, 4, 4> Data;

    Matrix4x4();
    explicit Matrix4x4(const Array2D<float, 4, 4>& Mat);

    // clang-format off
    Matrix4x4(float T00, float T01, float T02, float T03,
              float T10, float T11, float T12, float T13,
              float T20, float T21, float T22, float T23,
              float T30, float T31, float T32, float T33);
    // clang-format on

    bool operator==(const Matrix4x4& Other) const;
    bool operator!=(const Matrix4x4& Other) const;

    Matrix4x4 Transpose() const;

    Matrix4x4 Inverse() const;
};

Matrix4x4 Multiply(const Matrix4x4& M1, const Matrix4x4& M2);

}  // namespace math
