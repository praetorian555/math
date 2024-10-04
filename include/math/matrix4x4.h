#pragma once

#include <array>

#include "math/base.h"
#include "math/normal3.h"
#include "math/point3.h"
#include "math/point4.h"
#include "math/vector3.h"
#include "math/vector4.h"

namespace Math
{

template <typename T, int N, int M>
using Array2D = std::array<std::array<T, M>, N>;

/**
 * A 4x4 matrix.
 * @tparam T The type of the matrix elements.
 */
template <typename T>
struct Matrix4x4
{
    constexpr static int32_t k_row_count = 4;
    constexpr static int32_t k_column_count = 4;

    Array2D<T, k_row_count, k_column_count> elements;

    /**
     * Constructs a 4x4 matrix with elements not initialized.
     */
    constexpr Matrix4x4();

    /**
     * Constructs a 4x4 matrix with elements on the main diagonal equal to the value while other
     * elements are set to 0.
     * @param value The value to set the main diagonal elements to.
     */
    constexpr explicit Matrix4x4(T value);

    /**
     * Constructs a 4x4 matrix with elements set to the values in the array. The array is expected
     * to be in row-major order.
     * @param mat_elements The array of values to set the matrix elements to.
     */
    explicit Matrix4x4(const Array2D<T, 4, 4>& mat_elements);

    // clang-format off
    /**
     * Constructs a 4x4 matrix with elements set to the values passed in.
     */
    constexpr Matrix4x4(T t00, T t01, T t02, T t03,
                        T t10, T t11, T t12, T t13,
                        T t20, T t21, T t22, T t23,
                        T t30, T t31, T t32, T t33);
    // clang-format on

    /**
     * Create a 4x4 zero matrix.
     * @return The zero matrix.
     */
    static Matrix4x4 Zero();

    /** Operators **/
    T& operator()(int32_t row, int32_t column);
    const T& operator()(int32_t row, int32_t column) const;

    bool operator==(const Matrix4x4& other) const;
    bool operator!=(const Matrix4x4& other) const;

    Matrix4x4 operator*(const Matrix4x4<T>& other) const;
    Matrix4x4& operator*=(const Matrix4x4<T>& other);
    Matrix4x4 operator+(const Matrix4x4<T>& other) const;
    Matrix4x4& operator+=(const Matrix4x4<T>& other);
    Matrix4x4 operator-(const Matrix4x4<T>& other) const;
    Matrix4x4& operator-=(const Matrix4x4<T>& other);

    template <typename U>
    Matrix4x4 operator*(U scalar) const;
    template <typename U>
    Matrix4x4& operator*=(U scalar);
    template <typename U>
    Matrix4x4 operator/(U scalar) const;
    template <typename U>
    Matrix4x4& operator/=(U scalar);

    Point3<T> operator*(const Point3<T>& p) const;
    Point4<T> operator*(const Point4<T>& p) const;
    Vector3<T> operator*(const Vector3<T>& v) const;
    Vector4<T> operator*(const Vector4<T>& v) const;
    Normal3<T> operator*(const Normal3<T>& n) const;
};

template <typename T>
concept integral_or_floating_point = std::integral<T> || Math::FloatingPoint<T>;

template <typename T, integral_or_floating_point U>
Matrix4x4<T> operator*(U scalar, const Matrix4x4<T>& m);

/**
 * Check if two matrices are equal.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @param epsilon The epsilon value to use for comparison.
 * @return True if the matrices are equal, false otherwise.
 */
template <typename T>
bool IsEqual(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2, T epsilon);

/**
 * Transpose the matrix.
 * @param m The matrix to transpose.
 * @return The transposed matrix.
 */
template <typename T>
[[nodiscard]] Matrix4x4<T> Transpose(const Matrix4x4<T>& m);

/**
 * Invert the matrix.
 * @param m The matrix to invert.
 * @return The inverted matrix.
 */
template <Math::FloatingPoint T>
[[nodiscard]] Matrix4x4<T> Inverse(const Matrix4x4<T>& m);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr Math::Matrix4x4<T>::Matrix4x4()
{
    // Do nothing
}

template <typename T>
constexpr Math::Matrix4x4<T>::Matrix4x4(T value)
{
    for (int32_t i = 0; i < k_row_count; ++i)
    {
        for (int32_t j = 0; j < k_column_count; ++j)
        {
            elements[i][j] = (i == j) ? value : 0;
        }
    }
}

template <typename T>
Math::Matrix4x4<T>::Matrix4x4(const Array2D<T, 4, 4>& mat_elements)
{
    for (int32_t i = 0; i < k_row_count; ++i)
    {
        for (int32_t j = 0; j < k_column_count; ++j)
        {
            elements[i][j] = mat_elements[i][j];
        }
    }
}

template <typename T>
constexpr Math::Matrix4x4<T>::Matrix4x4(T t00,
                                        T t01,
                                        T t02,
                                        T t03,
                                        T t10,
                                        T t11,
                                        T t12,
                                        T t13,
                                        T t20,
                                        T t21,
                                        T t22,
                                        T t23,
                                        T t30,
                                        T t31,
                                        T t32,
                                        T t33)
{
    // clang-format off
    elements[0][0] = t00; elements[0][1] = t01; elements[0][2] = t02; elements[0][3] = t03;
    elements[1][0] = t10; elements[1][1] = t11; elements[1][2] = t12; elements[1][3] = t13;
    elements[2][0] = t20; elements[2][1] = t21; elements[2][2] = t22; elements[2][3] = t23;
    elements[3][0] = t30; elements[3][1] = t31; elements[3][2] = t32; elements[3][3] = t33;
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::Matrix4x4<T>::Zero()
{
    return Matrix4x4<T>(0);
}

template <typename T>
bool Math::Matrix4x4<T>::operator==(const Matrix4x4& other) const
{
    for (int32_t i = 0; i < k_row_count; ++i)
    {
        for (int32_t j = 0; j < k_column_count; ++j)
        {
            if (elements[i][j] != other.elements[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool Math::Matrix4x4<T>::operator!=(const Matrix4x4& other) const
{
    return !(*this == other);
}

template <typename T>
T& Math::Matrix4x4<T>::operator()(int32_t row, int32_t column)
{
    assert(row >= 0 && row < k_row_count);
    assert(column >= 0 && column < k_column_count);
    return elements[row][column];
}

template <typename T>
const T& Math::Matrix4x4<T>::operator()(int32_t row, int32_t column) const
{
    assert(row >= 0 && row < k_row_count);
    assert(column >= 0 && column < k_column_count);
    return elements[row][column];
}

template <typename T>
Math::Matrix4x4<T> Math::Matrix4x4<T>::operator*(const Matrix4x4<T>& other) const
{
    Matrix4x4<T> result;
    for (int32_t i = 0; i < k_row_count; ++i)
    {
        for (int32_t j = 0; j < k_column_count; ++j)
        {
            result.elements[i][j] = 0;
            for (int32_t k = 0; k < k_column_count; ++k)
            {
                result.elements[i][j] += elements[i][k] * other.elements[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Math::Matrix4x4<T>& Math::Matrix4x4<T>::operator*=(const Matrix4x4<T>& other)
{
    *this = *this * other;
    return *this;
}

template <typename T>
Math::Matrix4x4<T> Math::Matrix4x4<T>::operator+(const Matrix4x4<T>& other) const
{
    Matrix4x4<T> result;
    for (int32_t i = 0; i < k_row_count; ++i)
    {
        for (int32_t j = 0; j < k_column_count; ++j)
        {
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
        }
    }
    return result;
}

template <typename T>
Math::Matrix4x4<T>& Math::Matrix4x4<T>::operator+=(const Matrix4x4<T>& other)
{
    *this = *this + other;
    return *this;
}

template <typename T>
Math::Matrix4x4<T> Math::Matrix4x4<T>::operator-(const Matrix4x4<T>& other) const
{
    Matrix4x4<T> result;
    for (int32_t i = 0; i < k_row_count; ++i)
    {
        for (int32_t j = 0; j < k_column_count; ++j)
        {
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
        }
    }
    return result;
}

template <typename T>
Math::Matrix4x4<T>& Math::Matrix4x4<T>::operator-=(const Matrix4x4<T>& other)
{
    *this = *this - other;
    return *this;
}

template <typename T>
template <typename U>
Math::Matrix4x4<T> Math::Matrix4x4<T>::operator*(U scalar) const
{
    Matrix4x4<T> result;
    for (int32_t i = 0; i < k_row_count; ++i)
    {
        for (int32_t j = 0; j < k_column_count; ++j)
        {
            result.elements[i][j] = elements[i][j] * static_cast<T>(scalar);
        }
    }
    return result;
}

template <typename T>
template <typename U>
Math::Matrix4x4<T>& Math::Matrix4x4<T>::operator*=(U scalar)
{
    *this = *this * scalar;
    return *this;
}

template <typename T>
template <typename U>
Math::Matrix4x4<T> Math::Matrix4x4<T>::operator/(U scalar) const
{
    Matrix4x4<T> result;
    for (int32_t i = 0; i < k_row_count; ++i)
    {
        for (int32_t j = 0; j < k_column_count; ++j)
        {
            result.elements[i][j] = elements[i][j] / static_cast<T>(scalar);
        }
    }
    return result;
}

template <typename T>
template <typename U>
Math::Matrix4x4<T>& Math::Matrix4x4<T>::operator/=(U scalar)
{
    *this = *this / scalar;
    return *this;
}

template <typename T>
Math::Point3<T> Math::Matrix4x4<T>::operator*(const Point3<T>& p) const
{
    const T x = elements[0][0] * p.x + elements[0][1] * p.y + elements[0][2] * p.z + elements[0][3];
    const T y = elements[1][0] * p.x + elements[1][1] * p.y + elements[1][2] * p.z + elements[1][3];
    const T z = elements[2][0] * p.x + elements[2][1] * p.y + elements[2][2] * p.z + elements[2][3];
    const T w = elements[3][0] * p.x + elements[3][1] * p.y + elements[3][2] * p.z + elements[3][3];
    return Point3<T>(x / w, y / w, z / w);
}

template <typename T>
Math::Point4<T> Math::Matrix4x4<T>::operator*(const Point4<T>& p) const
{
    const T x =
        elements[0][0] * p.x + elements[0][1] * p.y + elements[0][2] * p.z + elements[0][3] * p.w;
    const T y =
        elements[1][0] * p.x + elements[1][1] * p.y + elements[1][2] * p.z + elements[1][3] * p.w;
    const T z =
        elements[2][0] * p.x + elements[2][1] * p.y + elements[2][2] * p.z + elements[2][3] * p.w;
    const T w =
        elements[3][0] * p.x + elements[3][1] * p.y + elements[3][2] * p.z + elements[3][3] * p.w;
    return Point4<T>(x, y, z, w);
}

template <typename T>
Math::Vector3<T> Math::Matrix4x4<T>::operator*(const Vector3<T>& v) const
{
    const T x = elements[0][0] * v.x + elements[0][1] * v.y + elements[0][2] * v.z;
    const T y = elements[1][0] * v.x + elements[1][1] * v.y + elements[1][2] * v.z;
    const T z = elements[2][0] * v.x + elements[2][1] * v.y + elements[2][2] * v.z;
    return Vector3<T>(x, y, z);
}

template <typename T>
Math::Vector4<T> Math::Matrix4x4<T>::operator*(const Vector4<T>& v) const
{
    const T x =
        elements[0][0] * v.x + elements[0][1] * v.y + elements[0][2] * v.z + elements[0][3] * v.w;
    const T y =
        elements[1][0] * v.x + elements[1][1] * v.y + elements[1][2] * v.z + elements[1][3] * v.w;
    const T z =
        elements[2][0] * v.x + elements[2][1] * v.y + elements[2][2] * v.z + elements[2][3] * v.w;
    const T w =
        elements[3][0] * v.x + elements[3][1] * v.y + elements[3][2] * v.z + elements[3][3] * v.w;
    return Vector4<T>(x, y, z, w);
}

template <typename T>
Math::Normal3<T> Math::Matrix4x4<T>::operator*(const Normal3<T>& n) const
{
    const T x = elements[0][0] * n.x + elements[1][0] * n.y + elements[2][0] * n.z;
    const T y = elements[0][1] * n.x + elements[1][1] * n.y + elements[2][1] * n.z;
    const T z = elements[0][2] * n.x + elements[1][2] * n.y + elements[2][2] * n.z;
    return Normal3<T>(x, y, z);
}

template <typename T, Math::integral_or_floating_point U>
Math::Matrix4x4<T> Math::operator*(U scalar, const Matrix4x4<T>& m)
{
    return m * static_cast<T>(scalar);
}

template <typename T>
bool Math::IsEqual(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2, T epsilon)
{
    for (int32_t i = 0; i < Matrix4x4<T>::k_row_count; ++i)
    {
        for (int32_t j = 0; j < Matrix4x4<T>::k_column_count; ++j)
        {
            if (!Math::IsEqual(m1.elements[i][j], m2.elements[i][j], epsilon))
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
Math::Matrix4x4<T> Math::Transpose(const Matrix4x4<T>& m)
{
    Matrix4x4<T> result;
    for (int32_t i = 0; i < Matrix4x4<T>::k_row_count; ++i)
    {
        for (int32_t j = 0; j < Matrix4x4<T>::k_column_count; ++j)
        {
            result.elements[i][j] = m.elements[j][i];
        }
    }
    return result;
}

template <Math::FloatingPoint T>
Math::Matrix4x4<T> Math::Inverse(const Matrix4x4<T>& m)
{
    std::array<int, 4> indxc = {0, 0, 0, 0};
    std::array<int, 4> indxr = {0, 0, 0, 0};
    std::array<int, 4> ipiv = {0, 0, 0, 0};
    Array2D<T, Matrix4x4<T>::k_row_count, Matrix4x4<T>::k_column_count> mat_inv;
    mat_inv = m.elements;
    for (int it = 0; it < 4; it++)
    {
        int index_row = 0;
        int index_column = 0;
        T big = 0;
        // Choose pivot
        for (int row = 0; row < 4; row++)
        {
            if (ipiv[row] == 1)
            {
                continue;
            }
            for (int column = 0; column < 4; column++)
            {
                if (ipiv[column] == 0)
                {
                    if (Math::Abs(mat_inv[row][column]) >= big)
                    {
                        big = Math::Abs(mat_inv[row][column]);
                        index_row = row;
                        index_column = column;
                    }
                }
                else if (ipiv[column] > 1)
                {
                    // Singular matrix
                    assert(false);
                }
            }
        }
        ++ipiv[index_column];
        // Swap rows _irow_ and _icol_ for pivot
        if (index_row != index_column)
        {
            for (int column = 0; column < 4; column++)
            {
                std::swap(mat_inv[index_row][column], mat_inv[index_column][column]);
            }
        }
        indxr[it] = index_row;
        indxc[it] = index_column;
        if (mat_inv[index_column][index_column] == 0)
        {
            // Singular matrix
            assert(false);
        }

        // Set m[icol][icol] to one by scaling row _icol_ appropriately
        const T pivinv = 1 / mat_inv[index_column][index_column];
        mat_inv[index_column][index_column] = 1;
        for (int Column = 0; Column < 4; Column++)
        {
            mat_inv[index_column][Column] *= pivinv;
        }

        // Subtract this row from Others to zero out their columns
        for (int row = 0; row < 4; row++)
        {
            if (row != index_column)
            {
                const T save = mat_inv[row][index_column];
                mat_inv[row][index_column] = 0;
                for (int Column = 0; Column < 4; Column++)
                {
                    mat_inv[row][Column] -= mat_inv[index_column][Column] * save;
                }
            }
        }
    }

    // Swap columns to reflect permutation
    for (int column = 3; column >= 0; column--)
    {
        if (indxr[column] != indxc[column])
        {
            for (int row = 0; row < 4; row++)
            {
                std::swap(mat_inv[row][indxr[column]], mat_inv[row][indxc[column]]);
            }
        }
    }

    return Matrix4x4(mat_inv);
}
