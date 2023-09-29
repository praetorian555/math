#pragma once

#include "math/vector3.h"
#include "math/point3.h"

namespace math
{

class Transform;

class Quaternion
{
public:
    Math::Vector3<float> Vec;
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
    static Quaternion FromAxisAngleDegrees(const Math::Vector3<float>& Axis, real AngleDegrees);

    /**
     * @brief Construct a Quaternion from an axis and an angle.
     * @param Axis - The axis to rotate around. It doesn't have to be normalized.
     * @param AngleRadians - The angle to rotate by in radians.
     * @return The Quaternion representing the rotation.
     */
    static Quaternion FromAxisAngleRadians(const Math::Vector3<float>& Axis, real AngleRadians);

    /**
     * @brief Check if any of the components of the Quaternion are NaN.
     * @return True if any of the components are NaN, false otherwise.
     */
    [[nodiscard]] bool HasNaNs() const;

    /**
     * @brief Get the length of the Quaternion.
     * @return The length of the Quaternion.
     */
    [[nodiscard]] real Length() const;

    /**
     * @brief Get the squared length of the Quaternion.
     * @return The squared length of the Quaternion.
     */
    [[nodiscard]] real LengthSquared() const;

    /**
     * Add a Quaternion to this one. Store the result in this Quaternion.
     * @param Other Quaternion to add.
     * @return Returns a reference to this Quaternion.
     */
    Quaternion& operator+=(const Quaternion& Other);

    /**
     * Subtract a Quaternion from this one. Store the result in this Quaternion.
     * @param Other Quaternion to subtract.
     * @return Returns a reference to this Quaternion.
     */
    Quaternion& operator-=(const Quaternion& Other);

    /**
     * Multiply this Quaternion by another one. Store the result in this Quaternion.
     * @param Other Quaternion to multiply by.
     * @return Returns a reference to this Quaternion.
     * @note This has effect of rotating by Other and then by this Quaternion.
     */
    Quaternion& operator*=(const Quaternion& Other);

    /**
     * Multiply this Quaternion by a scalar. Store the result in this Quaternion.
     * @param Scalar Scalar to multiply by.
     * @return Returns a reference to this Quaternion.
     */
    Quaternion& operator*=(real Scalar);

    /**
     * Multiply this Quaternion by a scalar. Store the result in new Quaternion.
     * @param Scalar Scalar to multiply by.
     * @return Returns a new Quaternion.
     */
    Quaternion operator*(real Scalar) const;

    /**
     * Divide this Quaternion by a scalar. Store the result in this Quaternion.
     * @param Scalar Scalar to divide by.
     * @return Returns a reference to this Quaternion.
     */
    Quaternion& operator/=(real Scalar);

    /**
     * Divide this Quaternion by a scalar. Store the result in new Quaternion.
     * @param Scalar Scalar to divide by.
     * @return Returns a new Quaternion.
     */
    Quaternion operator/(real Scalar) const;

    /**
     * Rotate vector by this Quaternion.
     * @param Vec Vector to rotate.
     * @return Returns a new Quaternion.
     */
    Math::Vector3<float> operator*(const Math::Vector3<float>& V) const;

    /**
     * Rotate point by this Quaternion.
     * @param Point Point to rotate.
     * @return Returns a new Quaternion.
     */
    Math::Point3<float> operator*(const Math::Point3<float>& P) const;

    /**
     * Check if this Quaternion is equal to another one.
     * @param Other Quaternion to compare to.
     * @return True if the Quaternions are equal, false otherwise.
     */
    bool operator==(const Quaternion& Other) const;

    /**
     * Check if this Quaternion is not equal to another one.
     * @param Other Quaternion to compare to.
     * @return True if the Quaternions are not equal, false otherwise.
     */
    bool operator!=(const Quaternion& Other) const;
};

/**
 * @brief Add two Quaternions.
 * @param Q1 First Quaternion.
 * @param Q2 Second Quaternion.
 * @return Returns the sum of the two Quaternions in a new Quaternion.
 */
Quaternion operator+(const Quaternion& Q1, const Quaternion& Q2);

/**
 * @brief Subtract two Quaternions.
 * @param Q1 First Quaternion.
 * @param Q2 Second Quaternion.
 * @return Returns the difference of the two Quaternions in a new Quaternion.
 */
Quaternion operator-(const Quaternion& Q1, const Quaternion& Q2);

/**
 * @brief Multiply two Quaternions.
 * @param Q1 First Quaternion.
 * @param Q2 Second Quaternion.
 * @return Returns the product of the two Quaternions in a new Quaternion.
 * @note Multiplication of quaternions is not commutative. Order matters here.
 */
Quaternion operator*(const Quaternion& Q1, const Quaternion& Q2);

/**
 * @brief Multiply a Quaternion by a scalar.
 * @param Scalar Scalar to multiply by.
 * @param Q Quaternion to multiply.
 * @return Returns the product of the Quaternion and the scalar in a new Quaternion.
 */
Quaternion operator*(real Scalar, const Quaternion& Q);

/**
 * Calculate the dot product of two Quaternions.
 * @param Q1 First Quaternion.
 * @param Q2 Second Quaternion.
 * @return Returns the dot product of the two Quaternions.
 */
real Dot(const Quaternion& Q1, const Quaternion& Q2);

/**
 * Normalize a Quaternion.
 * @param Q Quaternion to normalize. Can't have a magnitude of 0.
 * @return Returns the normalized Quaternion in a new object.
 */
Quaternion Normalize(const Quaternion& Q);

/**
 * Perform spherical linear interpolation between two Quaternions.
 * @param Q1 First Quaternion.
 * @param Q2 Second Quaternion.
 * @param Param Parameter to interpolate between the two Quaternions. Should be between 0 and 1.
 * @return Returns the interpolated Quaternion in a new object.
 * @note This operation is not commutative but provides constant angular velocity. If you want less
 * precision and commutative interpolation but can live with non-constant angular velocity, use Lerp
 * instead.
 * @see Lerp
 */
Quaternion Slerp(const Quaternion& Q1, const Quaternion& Q2, real Param);

/**
 * Perform linear interpolation between two Quaternions.
 * @param Q1 First Quaternion.
 * @param Q2 Second Quaternion.
 * @param Param Parameter to interpolate between the two Quaternions. Should be between 0 and 1.
 * @return Returns the interpolated Quaternion in a new object.
 * @note This operation is commutative but results in a non-constant angular velocity. If you want
 * absolute precision and constant angular velocity, use Slerp instead.
 * @see Slerp
 */
Quaternion Lerp(const Quaternion& Q1, const Quaternion& Q2, real Param);

/**
 * @brief Get the conjugate of a Quaternion.
 * @param Q - The Quaternion to get the conjugate of.
 * @return The conjugate of the Quaternion.
 */
Quaternion Conjugate(const Quaternion& Q);

/**
 * @brief Get the inverse of a Quaternion.
 * @param Q - The Quaternion to get the inverse of.
 * @return The inverse of the Quaternion.
 */
Quaternion Inverse(const Quaternion& Q);

}  // namespace math
