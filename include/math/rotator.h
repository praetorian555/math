#pragma once

#include "math/vector3.h"

namespace Math
{

/**
 * Orientation expressed in angle rotations around axes of coordinate system. Always in degrees.
 * Default orientation (all zeros) means that the forward vector is along the x-axis, up vector is
 * along the y-axis and right vector is along the z-axis.
 */
template <Math::FloatingPoint T>
struct Rotator
{
    /**
     * Rotation around the right axis (around Z axis), Looking up and down (0=Straight Ahead, +Up,
     * -Down).
     */
    T pitch;

    /**
     * Rotation around the up axis (around Y axis), Running in circles +Left, -Right.
     */
    T yaw;

    /**
     * Rotation around the forward axis (around X axis), Tilting your head, 0=Straight, +CW, -CCW.
     */
    T roll;

    /**
     * Default constructor. No initialization.
     */
    constexpr Rotator();

    /**
     * Constructor. Angles are in degrees.
     */
    constexpr Rotator(T pitch, T yaw, T roll);

    /**
     * Returns rotator with zero rotation.
     * @return Rotator with zero rotation.
     */
    static Rotator Zero();

    /** Operator overloads. */

    bool operator==(const Rotator& other) const;
    bool operator!=(const Rotator& other) const;

    Rotator operator+(const Rotator& other) const;
    Rotator& operator+=(const Rotator& other);
    Rotator operator-(const Rotator& other) const;
    Rotator& operator-=(const Rotator& other);

    Rotator operator*(T val) const;
    Rotator& operator*=(T val);
};

template <Math::FloatingPoint T>
Rotator<T> operator*(T val, const Rotator<T>& rot);

/**
 * Returns a normalized vector defined by the angles in the rotator.
 * @tparam T Rotator data type.
 * @param rot Rotator.
 * @return Normalized vector.
 */
template <Math::FloatingPoint T>
[[nodiscard]] Vector3<T> RotatorToVector(const Rotator<T>& rot);

/**
 * Returns a vector where each component stores the rotation angle in degrees around
 * corresponding axis.
 * @tparam T Rotator data type.
 * @param rot Rotator.
 * @return Vector with rotation angles.
 */
template <Math::FloatingPoint T>
[[nodiscard]] Vector3<T> RotatorToEuler(const Rotator<T>& rot);

}  // namespace Math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <Math::FloatingPoint T>
constexpr Math::Rotator<T>::Rotator()
{
    // Do nothing.
}

template <Math::FloatingPoint T>
constexpr Math::Rotator<T>::Rotator(T pitch, T yaw, T roll)
    : pitch(pitch), yaw(yaw), roll(roll)
{
}

template <Math::FloatingPoint T>
Math::Rotator<T> Math::Rotator<T>::Zero()
{
    return Rotator<T>{0, 0, 0};
}

template <Math::FloatingPoint T>
bool Math::Rotator<T>::operator==(const Rotator& other) const
{
    return pitch == other.pitch && yaw == other.yaw && roll == other.roll;
}

template <Math::FloatingPoint T>
bool Math::Rotator<T>::operator!=(const Rotator& other) const
{
    return !(*this == other);
}

template <Math::FloatingPoint T>
Math::Rotator<T> Math::Rotator<T>::operator+(const Rotator& other) const
{
    return Rotator<T>{pitch + other.pitch, yaw + other.yaw, roll + other.roll};
}

template <Math::FloatingPoint T>
Math::Rotator<T>& Math::Rotator<T>::operator+=(const Rotator& other)
{
    pitch += other.pitch;
    yaw += other.yaw;
    roll += other.roll;
    return *this;
}

template <Math::FloatingPoint T>
Math::Rotator<T> Math::Rotator<T>::operator-(const Rotator& other) const
{
    return Rotator<T>{pitch - other.pitch, yaw - other.yaw, roll - other.roll};
}

template <Math::FloatingPoint T>
Math::Rotator<T>& Math::Rotator<T>::operator-=(const Rotator& other)
{
    pitch -= other.pitch;
    yaw -= other.yaw;
    roll -= other.roll;
    return *this;
}

template <Math::FloatingPoint T>
Math::Rotator<T> Math::Rotator<T>::operator*(T val) const
{
    return Rotator<T>{pitch * val, yaw * val, roll * val};
}

template <Math::FloatingPoint T>
Math::Rotator<T>& Math::Rotator<T>::operator*=(T val)
{
    pitch *= val;
    yaw *= val;
    roll *= val;
    return *this;
}

template <Math::FloatingPoint T>
Math::Rotator<T> Math::operator*(T val, const Rotator<T>& rot)
{
    return rot * val;
}

template <Math::FloatingPoint T>
Math::Vector3<T> Math::RotatorToVector(const Rotator<T>& rot)
{
    const T pitch_no_winding = Mod(rot.pitch, static_cast<T>(360.0));
    const T yaw_no_winding = Mod(rot.yaw, static_cast<T>(360.0));

    const T sp = Sin(Radians(pitch_no_winding));
    const T cp = Cos(Radians(pitch_no_winding));
    const T sy = Sin(Radians(yaw_no_winding));
    const T cy = Cos(Radians(yaw_no_winding));
    return Vector3{cp * cy, sp, -cp * sy};
}

template <Math::FloatingPoint T>
Math::Vector3<T> Math::RotatorToEuler(const Rotator<T>& rot)
{
    return Vector3<T>{rot.roll, rot.yaw, rot.pitch};
}
