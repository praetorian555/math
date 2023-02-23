#pragma once

#include "math/vector3.h"

namespace math
{

class Transform;

class Quaternion
{
public:
    Vector3 Vec;
    real W;

    /**
     * @brief Construct a unit Quaternion.
     */
    Quaternion() : Vec(0, 0, 0), W(1) {}

    /**
     * @brief Construct a Quaternion using four real values.
     * @param X - The i part of the Quaternion.
     * @param Y - The j part of the Quaternion.
     * @param Z - The k part of the Quaternion.
     * @param W - The real part of the Quaternion.
     */
    Quaternion(real X, real Y, real Z, real W) : Vec(X, Y, Z), W(W) {}

    /**
     * @brief Construct a Quaternion from a transform. This uses only the upper left 3x3 part of the
     * matrix.
     * @param T - The transform to construct the Quaternion from.
     */
    explicit Quaternion(const Transform& T);

    /**
     * @brief Construct a Quaternion from an axis and an angle.
     * @param Axis - The axis to rotate around. It doesn't have to be normalized.
     * @param AngleDegrees - The angle to rotate by in degrees.
     * @return The Quaternion representing the rotation.
     */
    static Quaternion FromAxisAngleDegrees(const Vector3& Axis, real AngleDegrees);

    /**
     * @brief Construct a Quaternion from an axis and an angle.
     * @param Axis - The axis to rotate around. It doesn't have to be normalized.
     * @param AngleRadians - The angle to rotate by in radians.
     * @return The Quaternion representing the rotation.
     */
    static Quaternion FromAxisAngleRadians(const Vector3& Axis, real AngleRadians);

    [[nodiscard]] bool HasNaNs() const;

    [[nodiscard]] real Length() const;
    [[nodiscard]] real LengthSquared() const;

    Quaternion& operator+=(const Quaternion& Other);
    Quaternion& operator-=(const Quaternion& Other);
    Quaternion& operator*=(const Quaternion& Other);

    Quaternion& operator*=(real Scalar);
    Quaternion operator*(real Scalar) const;
    Quaternion& operator/=(real Scalar);
    Quaternion operator/(real Scalar) const;

    bool operator==(const Quaternion& Other) const;
    bool operator!=(const Quaternion& Other) const;
};

Quaternion operator+(const Quaternion& Q1, const Quaternion& Q2);
Quaternion operator-(const Quaternion& Q1, const Quaternion& Q2);
Quaternion operator*(const Quaternion& Q1, const Quaternion& Q2);
Quaternion Normalize(const Quaternion& Q);
Quaternion Slerp(real Param, const Quaternion& Q1, const Quaternion& Q2);
Quaternion Conjugate(const Quaternion& Q);
Quaternion Inverse(const Quaternion& Q);

}  // namespace math
