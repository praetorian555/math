#pragma once

#include <array>

#include "math/base.h"

namespace math
{

template <typename T, int N, int M>
using Array2D = std::array<std::array<T, M>, N>;

struct Matrix4x4
{
    Array2D<real, 4, 4> Data;

    Matrix4x4();
    explicit Matrix4x4(const Array2D<math::real, 4, 4>& Mat);

    // clang-format off
    Matrix4x4(real T00, real T01, real T02, real T03,
              real T10, real T11, real T12, real T13,
              real T20, real T21, real T22, real T23,
              real T30, real T31, real T32, real T33);
    // clang-format on

    bool operator==(const Matrix4x4& Other) const;
    bool operator!=(const Matrix4x4& Other) const;

    [[nodiscard]] Matrix4x4 Transpose() const;

    [[nodiscard]] Matrix4x4 Inverse() const;
};

Matrix4x4 Multiply(const Matrix4x4& M1, const Matrix4x4& M2);

}  // namespace math
