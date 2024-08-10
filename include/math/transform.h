#pragma once

#include "math/matrix4x4.h"
#include "math/point4.h"
#include "math/quaternion.h"
#include "math/rotator.h"

namespace Math
{

/**
 * Create an identity transform.
 * @tparam T The data type.
 * @return The identity transform.
 */
template <typename T>
Matrix4x4<T> Identity();

/**
 * Create a translation matrix.
 * @tparam T The data type.
 * @param delta The translation vector.
 * @return The translation matrix.
 */
template <typename T>
Matrix4x4<T> Translate(const Point3<T>& delta);

/**
 * Create a translation matrix.
 * @tparam T The data type.
 * @param delta The translation vector.
 * @return The translation matrix.
 */
template <typename T>
Matrix4x4<T> Translate(const Vector3<T>& delta);

/**
 * Create a scale matrix.
 * @tparam T The data type.
 * @param x Amount to scale along the x-axis.
 * @param y Amount to scale along the y-axis.
 * @param z Amount to scale along the z-axis.
 * @return The scale matrix.
 */
template <typename T>
Matrix4x4<T> Scale(T x, T y, T z);

/**
 * Create a scale matrix.
 * @tparam T The data type.
 * @param scalar The amount to scale.
 * @return The scale matrix.
 */
template <typename T>
Matrix4x4<T> Scale(T scalar);

/**
 * Create a rotation matrix around the x-axis.
 * @tparam T The data type.
 * @param angle_degrees The angle in degrees.
 * @return The rotation matrix.
 */
template <typename T>
Matrix4x4<T> RotateX(T angle_degrees);

/**
 * Create a rotation matrix around the y-axis.
 * @tparam T The data type.
 * @param angle_degrees The angle in degrees.
 * @return The rotation matrix.
 */
template <typename T>
Matrix4x4<T> RotateY(T angle_degrees);

/**
 * Create a rotation matrix around the z-axis.
 * @tparam T The data type.
 * @param angle_degrees The angle in degrees.
 * @return The rotation matrix.
 */
template <typename T>
Matrix4x4<T> RotateZ(T angle_degrees);

/**
 * Create a rotation matrix around an arbitrary axis.
 * @tparam T The data type.
 * @param angle_degrees The angle in degrees.
 * @param axis The axis to rotate around.
 * @return The rotation matrix.
 */
template <typename T>
Matrix4x4<T> Rotate(T angle_degrees, const Vector3<T>& axis);

/**
 * Create a rotation matrix from a quaternion.
 * @tparam T The data type.
 * @param q The quaternion.
 * @return The rotation matrix.
 */
template <typename T>
Matrix4x4<T> Rotate(const Quaternion<T>& q);

/**
 * Create a rotation matrix from a rotator. This applies angle around x then around y and then
 * around z axis.
 * @tparam T The data type.
 * @param rot The rotator.
 * @return The rotation matrix.
 */
template <typename T>
Matrix4x4<T> Rotate(const Rotator<T>& rot);

/**
 * Create a rotation and translation matrix from a rotator and a translation vector.
 * @tparam T The data type.
 * @param rot Rotator. This applies angle around x then around y and then around z axis.
 * @param t Translation vector. This is applied after the rotation.
 * @return The rotation and translation matrix.
 */
template <typename T>
Matrix4x4<T> RotateAndTranslate(const Rotator<T>& rot, const Point3<T>& t);

/**
 * Create a rotation and translation matrix from a rotator and a translation vector.
 * @tparam T The data type.
 * @param rot Rotator. This applies angle around x then around y and then around z axis.
 * @param t Translation vector. This is applied after the rotation.
 * @return The rotation and translation matrix.
 */
template <typename T>
Matrix4x4<T> RotateAndTranslate(const Rotator<T>& rot, const Vector3<T>& t);

/**
 *  Create a world to camera (view) transform for a right-handed coordinate system.
 * @tparam T The data type.
 * @param eye The position of the camera.
 * @param target The position the camera is looking at.
 * @param up The up vector.
 * @return The view matrix.
 */
template <typename T>
Matrix4x4<T> LookAt_RH(const Point3<T>& eye, const Point3<T>& target, const Vector3<T>& up);

/**
 * Create a world to camera (view) transform for a left-handed coordinate system.
 * @tparam T The data type.
 * @param eye The position of the camera.
 * @param target The position the camera is looking at.
 * @param up The up vector.
 * @return The view matrix.
 */
template <typename T>
Matrix4x4<T> LookAt_LH(const Point3<T>& eye, const Point3<T>& target, const Vector3<T>& up);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
Math::Matrix4x4<T> Math::Identity()
{
    // clang-format off
    return Matrix4x4<T>{
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::Translate(const Point3<T>& delta)
{
    // clang-format off
    return Matrix4x4<T>{
        1, 0, 0, delta.x,
        0, 1, 0, delta.y,
        0, 0, 1, delta.z,
        0, 0, 0, 1
    };
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::Translate(const Vector3<T>& delta)
{
    // clang-format off
    return Matrix4x4<T>{
        1, 0, 0, delta.x,
        0, 1, 0, delta.y,
        0, 0, 1, delta.z,
        0, 0, 0, 1
    };
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::Scale(T x, T y, T z)
{
    // clang-format off
    return Matrix4x4<T>{
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    };
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::Scale(T scalar)
{
    return Scale(scalar, scalar, scalar);
}

template <typename T>
Math::Matrix4x4<T> Math::RotateX(T angle_degrees)
{
    const T angle_radians = Radians(angle_degrees);
    const T cos = std::cos(angle_radians);
    const T sin = std::sin(angle_radians);

    // clang-format off
    return Matrix4x4<T>{
        1,   0,    0, 0,
        0, cos, -sin, 0,
        0, sin,  cos, 0,
        0,   0,    0, 1
    };
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::RotateY(T angle_degrees)
{
    const T angle_radians = Radians(angle_degrees);
    const T cos = std::cos(angle_radians);
    const T sin = std::sin(angle_radians);

    // clang-format off
    return Matrix4x4<T>{
         cos, 0, sin, 0,
           0, 1,   0, 0,
        -sin, 0, cos, 0,
           0, 0,   0, 1
    };
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::RotateZ(T angle_degrees)
{
    const T angle_radians = Radians(angle_degrees);
    const T cos = std::cos(angle_radians);
    const T sin = std::sin(angle_radians);

    // clang-format off
    return Matrix4x4<T>{
        cos, -sin, 0, 0,
        sin,  cos, 0, 0,
          0,    0, 1, 0,
          0,    0, 0, 1
    };
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::Rotate(T angle_degrees, const Vector3<T>& axis)
{
    const T angle_radians = Radians(angle_degrees);
    const T cos = std::cos(angle_radians);
    const T sin = std::sin(angle_radians);
    const T one_minus_cos = 1 - cos;

    const Vector3<T> norm_axis = Normalize(axis);
    const T x = norm_axis.x;
    const T y = norm_axis.y;
    const T z = norm_axis.z;

    // clang-format off
    return Matrix4x4<T>{
            cos + x * x * one_minus_cos,  x * y * one_minus_cos - z * sin,  x * z * one_minus_cos + y * sin, 0,
        y * x * one_minus_cos + z * sin,      cos + y * y * one_minus_cos,  y * z * one_minus_cos - x * sin, 0,
        z * x * one_minus_cos - y * sin,  z * y * one_minus_cos + x * sin,      cos + z * z * one_minus_cos, 0,
                                      0,                                0,                                0, 1
    };
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::Rotate(const Quaternion<T>& q)
{
    const T x = q.vec.x;
    const T y = q.vec.y;
    const T z = q.vec.z;
    const T w = q.w;

    // clang-format off
    return Matrix4x4<T>{
        1 - 2 * y * y - 2 * z * z,      2 * x * y - 2 * z * w,      2 * x * z + 2 * y * w, 0,
            2 * x * y + 2 * z * w,  1 - 2 * x * x - 2 * z * z,      2 * y * z - 2 * x * w, 0,
            2 * x * z - 2 * y * w,      2 * y * z + 2 * x * w,  1 - 2 * x * x - 2 * y * y, 0,
                                0,                        0,                        0, 1
    };
    // clang-format on
}

template <typename T>
Math::Matrix4x4<T> Math::Rotate(const Rotator<T>& rot)
{
    return RotateZ(rot.pitch) * RotateY(rot.yaw) * RotateX(rot.roll);
}

template <typename T>
Math::Matrix4x4<T> Math::RotateAndTranslate(const Rotator<T>& rot, const Point3<T>& t)
{
    return Translate(t) * Rotate(rot);
}

template <typename T>
Math::Matrix4x4<T> Math::RotateAndTranslate(const Rotator<T>& rot, const Vector3<T>& t)
{
    return Translate(t) * Rotate(rot);
}

template <typename T>
Math::Matrix4x4<T> Math::LookAt_RH(const Point3<T>& eye,
                                   const Point3<T>& target,
                                   const Vector3<T>& up)
{
    const Vector3<T> forward = Normalize(eye - target);
    const Vector3<T> right = Normalize(Cross(up, forward));
    const Vector3<T> new_up = Cross(forward, right);
    const Vector3<T> eye_vector = eye - Point3<T>::Zero();

    Matrix4x4 result(1.0f);
    result(0, 0) = right.x;
    result(0, 1) = right.y;
    result(0, 2) = right.z;
    result(1, 0) = new_up.x;
    result(1, 1) = new_up.y;
    result(1, 2) = new_up.z;
    result(2, 0) = forward.x;
    result(2, 1) = forward.y;
    result(2, 2) = forward.z;
    result(0, 3) = -Dot(right, eye_vector);
    result(1, 3) = -Dot(new_up, eye_vector);
    result(2, 3) = -Dot(forward, eye_vector);

    return result;
}

template <typename T>
Math::Matrix4x4<T> Math::LookAt_LH(const Point3<T>& eye,
                                   const Point3<T>& target,
                                   const Vector3<T>& up)
{
    const Vector3<T> forward = Normalize(target - eye);
    const Vector3<T> right = Normalize(Cross(up, forward));
    const Vector3<T> new_up = Cross(forward, right);
    const Vector3<T> eye_vector = eye - Point3<T>::Zero();

    Matrix4x4 result(1.0f);
    result(0, 0) = right.x;
    result(0, 1) = right.y;
    result(0, 2) = right.z;
    result(1, 0) = new_up.x;
    result(1, 1) = new_up.y;
    result(1, 2) = new_up.z;
    result(2, 0) = forward.x;
    result(2, 1) = forward.y;
    result(2, 2) = forward.z;
    result(0, 3) = -Dot(right, eye_vector);
    result(1, 3) = -Dot(new_up, eye_vector);
    result(2, 3) = -Dot(forward, eye_vector);

    return result;
}

