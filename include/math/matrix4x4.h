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
    Matrix4x4(float t00, float t01, float t02, float t03,
              float t10, float t11, float t12, float t13,
              float t20, float t21, float t22, float t23,
              float t30, float t31, float t32, float t33);
    // clang-format on

    bool operator==(const Matrix4x4& other) const;
    bool operator!=(const Matrix4x4& other) const;

    Matrix4x4 Transpose() const;

    Matrix4x4 Inverse() const;
};

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

}  // namespace math
