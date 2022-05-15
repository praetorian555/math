#pragma once

#include "math/base.h"
#include "math/impl/vector3.h"

namespace math
{

/**
 * Orientation expressed in angle rotations around axes of coordinate system. Always in degrees.
 * Default orientation (all zeros) means that the forward vector is along the negative z-axis, right
 * vector is along x-axis and up vector is along the y-axis.
 */
struct Rotator
{
    /**
     * Rotation around the right axis (around Z axis), Looking up and down (0=Straight Ahead, +Up,
     * -Down).
     */
    float Pitch = 0;

    /** Rotation around the up axis (around Y axis), Running in circles +Left, -Right. */
    float Yaw = 0;

    /**
     * Rotation around the forward axis (around X axis), Tilting your head, 0=Straight, +CW, -CCW.
     */
    float Roll = 0;

    Rotator() = default;
    Rotator(float Pitch, float Yaw, float Roll);

    /**
     * Returns normalized vector in the direction defined by the rotator.
     */
    Vector3<float> ToVector();

    Rotator operator+(Rotator Other) const;
    Rotator& operator+=(Rotator Other);

    Rotator operator*(float Val) const;
    Rotator& operator*=(float Val);
};

Rotator operator*(float Val, const Rotator& Other);

}  // namespace math