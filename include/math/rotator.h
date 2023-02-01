#pragma once

#include "math/vector3.h"

namespace math
{

/**
 * Orientation expressed in angle rotations around axes of coordinate system. Always in degrees.
 * Default orientation (all zeros) means that the forward vector is along the x-axis, up vector is
 * along the y-axis and right vector is along the z-axis.
 */
struct Rotator
{
    /**
     * Rotation around the right axis (around Z axis), Looking up and down (0=Straight Ahead, +Up,
     * -Down).
     */
    real Pitch = 0;

    /**
     * Rotation around the up axis (around Y axis), Running in circles +Left, -Right.
     */
    real Yaw = 0;

    /**
     * Rotation around the forward axis (around X axis), Tilting your head, 0=Straight, +CW, -CCW.
     */
    real Roll = 0;

    Rotator() = default;

    /**
     * Constructor. Angles are in degrees.
     */
    Rotator(real Pitch, real Yaw, real Roll);

    /**
     * Returns normalized vector in the direction defined by the rotator.
     */
    [[nodiscard]] Vector3 ToVector() const;

    /**
     * Returns a vector where each component stores the rotation angle in degrees around
     * corresponding axis.
     */
    [[nodiscard]] Vector3 ToEuler() const;

    bool operator==(const Rotator& Other) const;
    bool operator!=(const Rotator& Other) const;

    Rotator operator+(const Rotator& Other) const;
    Rotator& operator+=(const Rotator& Other);
    Rotator operator-(const Rotator& Other) const;
    Rotator& operator-=(const Rotator& Other);

    Rotator operator*(real Val) const;
    Rotator& operator*=(real Val);

    void Add(real DeltaPitch, real DeltaYaw, real DeltaRoll);

    [[nodiscard]] Vector3 RotateVector(const Vector3& Vec) const;

    static const Rotator Zero;
};

Rotator operator*(real Val, const Rotator& Other);

}  // namespace math