#pragma once

#include "math/matrix4x4.h"

namespace Math
{

/**
 * Create an orthographic projection matrix for left-handed coordinate system where Z maps between 0
 * and 1 (DirectX style).
 *
 * @param near Distance from a viewer to the near clipping plane. Always positive or zero.
 * @param far Distance from a viewer to the far clipping plane. Always positive or zero.
 */
template <Math::FloatingPoint T>
Matrix4x4<T> Orthographic_LH_N0(T left, T right, T bottom, T top, T near, T far);

/**
 * Create an orthographic projection matrix for left-handed coordinate system where Z maps between
 * -1 and 1 (OpenGL style).
 *
 * @param near Distance from a viewer to the near clipping plane. Always positive or zero.
 * @param far Distance from a viewer to the far clipping plane. Always positive or zero.
 */
template <Math::FloatingPoint T>
Matrix4x4<T> Orthographic_LH_N1(T left, T right, T bottom, T top, T near, T far);

/**
 * Create an orthographic projection matrix for right-handed coordinate system where Z maps between
 * 0 and 1 (DirectX style).
 *
 * @param near Distance from a viewer to the near clipping plane. Always positive or zero.
 * @param far Distance from a viewer to the far clipping plane. Always positive or zero.
 */
template <Math::FloatingPoint T>
Matrix4x4<T> Orthographic_RH_N0(T left, T right, T bottom, T top, T near, T far);

/**
 * Create an orthographic projection matrix for right-handed coordinate system where Z maps between
 * -1 and 1 (OpenGL style).
 *
 * @param near Distance from a viewer to the near clipping plane. Always positive or zero.
 * @param far Distance from a viewer to the far clipping plane. Always positive or zero.
 */
template <Math::FloatingPoint T>
Matrix4x4<T> Orthographic_RH_N1(T left, T right, T bottom, T top, T near, T far);

/**
 * Create a perspective projection matrix for left-handed coordinate system where Z maps between 0
 * and 1 (DirectX style).
 *
 * @param vertical_fov Field of view angle in y direction. In degrees.
 * @param aspect_ratio Ratio used to calculate field of view angle in x direction. Defined as ratio
 * between width (x) and height (y).
 * @param near Distance from a viewer to the near clipping plane. Always positive.
 * @param far Distance from a viewer to the far clipping plane. Always positive.
 */
template <Math::FloatingPoint T>
Matrix4x4<T> Perspective_LH_N0(T vertical_fov, T aspect_ratio, T near, T far);

/**
 * Create a perspective projection matrix for left-handed coordinate system where Z maps between -1
 * and 1 (OpenGL style).
 *
 * @param vertical_fov Field of view angle in y direction. In degrees.
 * @param aspect_ratio Ratio used to calculate field of view angle in x direction. Defined as ratio
 * between width (x) and height (y).
 * @param near Distance from a viewer to the near clipping plane. Always positive.
 * @param far Distance from a viewer to the far clipping plane. Always positive.
 */
template <Math::FloatingPoint T>
Matrix4x4<T> Perspective_LH_N1(T vertical_fov, T aspect_ratio, T near, T far);

/**
 * Create a perspective projection matrix for right-handed coordinate system where Z maps between 0
 * and 1 (DirectX style).
 *
 * @param vertical_fov Field of view angle in y direction. In degrees.
 * @param aspect_ratio Ratio used to calculate field of view angle in x direction. Defined as ratio
 * between width (x) and height (y).
 * @param near Distance from a viewer to the near clipping plane. Always positive.
 * @param far Distance from a viewer to the far clipping plane. Always positive.
 */
template <Math::FloatingPoint T>
Matrix4x4<T> Perspective_RH_N0(T vertical_fov, T aspect_ratio, T near, T far);

/**
 * Create a perspective projection matrix for right-handed coordinate system where Z maps between -1
 * and 1 (OpenGL style).
 *
 * @param vertical_fov Field of view angle in y direction. In degrees.
 * @param aspect_ratio Ratio used to calculate field of view angle in x direction. Defined as ratio
 * between width (x) and height (y).
 * @param near Distance from a viewer to the near clipping plane. Always positive.
 * @param far Distance from a viewer to the far clipping plane. Always positive.
 */
template <Math::FloatingPoint T>
Matrix4x4<T> Perspective_RH_N1(T vertical_fov, T aspect_ratio, T near, T far);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <Math::FloatingPoint T>
Math::Matrix4x4<T> Math::Orthographic_LH_N0(T left, T right, T bottom, T top, T near, T far)
{
    Matrix4x4<T> mat(1);
    mat.elements[0][0] = 2 / (right - left);
    mat.elements[1][1] = 2 / (top - bottom);
    mat.elements[2][2] = 1 / (far - near);
    mat.elements[0][3] = -(right + left) / (right - left);
    mat.elements[1][3] = -(top + bottom) / (top - bottom);
    mat.elements[2][3] = -near / (far - near);
    return mat;
}

template <Math::FloatingPoint T>
Math::Matrix4x4<T> Math::Orthographic_LH_N1(T left, T right, T bottom, T top, T near, T far)
{
    Matrix4x4<T> mat(1);
    mat.elements[0][0] = 2 / (right - left);
    mat.elements[1][1] = 2 / (top - bottom);
    mat.elements[2][2] = 2 / (far - near);
    mat.elements[0][3] = -(right + left) / (right - left);
    mat.elements[1][3] = -(top + bottom) / (top - bottom);
    mat.elements[2][3] = -(near + far) / (far - near);
    return mat;
}

template <Math::FloatingPoint T>
Math::Matrix4x4<T> Math::Orthographic_RH_N0(T left, T right, T bottom, T top, T near, T far)
{
    Matrix4x4<T> mat(1);
    mat.elements[0][0] = 2 / (right - left);
    mat.elements[1][1] = 2 / (top - bottom);
    mat.elements[2][2] = -1 / (far - near);
    mat.elements[0][3] = -(right + left) / (right - left);
    mat.elements[1][3] = -(top + bottom) / (top - bottom);
    mat.elements[2][3] = -near / (far - near);
    return mat;
}

template <Math::FloatingPoint T>
Math::Matrix4x4<T> Math::Orthographic_RH_N1(T left, T right, T bottom, T top, T near, T far)
{
    Matrix4x4<T> mat(1);
    mat.elements[0][0] = 2 / (right - left);
    mat.elements[1][1] = 2 / (top - bottom);
    mat.elements[2][2] = -2 / (far - near);
    mat.elements[0][3] = -(right + left) / (right - left);
    mat.elements[1][3] = -(top + bottom) / (top - bottom);
    mat.elements[2][3] = -(near + far) / (far - near);
    return mat;
}

template <Math::FloatingPoint T>
Math::Matrix4x4<T> Math::Perspective_LH_N0(T vertical_fov, T aspect_ratio, T near, T far)
{
    assert(aspect_ratio != 0);

    const T inv_fov_y = 1.0f / Math::Tan(Math::Radians(vertical_fov) / 2);
    const T inv_aspect_ratio = 1 / aspect_ratio;

    Matrix4x4<T> mat(1);
    mat.elements[0][0] = inv_fov_y * inv_aspect_ratio;
    mat.elements[1][1] = inv_fov_y;
    mat.elements[2][2] = far / (far - near);
    mat.elements[2][3] = -(far * near) / (far - near);
    mat.elements[3][2] = 1;
    mat.elements[3][3] = 0;
    return mat;
}

template <Math::FloatingPoint T>
Math::Matrix4x4<T> Math::Perspective_LH_N1(T vertical_fov, T aspect_ratio, T near, T far)
{
    assert(aspect_ratio != 0);

    const T inv_fov_y = 1.0f / Math::Tan(Math::Radians(vertical_fov) / 2);
    const T inv_aspect_ratio = 1 / aspect_ratio;

    Matrix4x4<T> mat(1);
    mat.elements[0][0] = inv_fov_y * inv_aspect_ratio;
    mat.elements[1][1] = inv_fov_y;
    mat.elements[2][2] = (far + near) / (far - near);
    mat.elements[2][3] = -(2 * far * near) / (far - near);
    mat.elements[3][2] = 1;
    mat.elements[3][3] = 0;
    return mat;
}

template <Math::FloatingPoint T>
Math::Matrix4x4<T> Math::Perspective_RH_N0(T vertical_fov, T aspect_ratio, T near, T far)
{
    assert(aspect_ratio != 0);

    const T inv_fov_y = 1.0f / Math::Tan(Math::Radians(vertical_fov) / 2);
    const T inv_aspect_ratio = 1 / aspect_ratio;

    Matrix4x4<T> mat(1);
    mat.elements[0][0] = inv_fov_y * inv_aspect_ratio;
    mat.elements[1][1] = inv_fov_y;

    // NOTE(mkostic): Different from glm::perspectiveRH_ZO it looks like glm implementation doesn't
    // give correct results
    mat.elements[2][2] = -far / (far - near);

    mat.elements[2][3] = -(far * near) / (far - near);
    mat.elements[3][2] = -1;
    mat.elements[3][3] = 0;
    return mat;
}

template <Math::FloatingPoint T>
Math::Matrix4x4<T> Math::Perspective_RH_N1(T vertical_fov, T aspect_ratio, T near, T far)
{
    assert(aspect_ratio != 0);

    const T inv_fov_y = 1.0f / Math::Tan(Math::Radians(vertical_fov) / 2);
    const T inv_aspect_ratio = 1 / aspect_ratio;

    Matrix4x4<T> mat(1);
    mat.elements[0][0] = inv_fov_y * inv_aspect_ratio;
    mat.elements[1][1] = inv_fov_y;
    mat.elements[2][2] = -(far + near) / (far - near);
    mat.elements[2][3] = -(2 * far * near) / (far - near);
    mat.elements[3][2] = -1;
    mat.elements[3][3] = 0;
    return mat;
}
