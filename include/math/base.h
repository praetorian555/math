#pragma once

#include <cmath>
#include <cstdint>
#include <cassert>

namespace math
{

#if MATH_REAL_AS_DOUBLE
using real = double;
#define MATH_REALC(X) X
#else
using real = float;
#define MATH_REALC(X) X##f
#endif

// Constants
static constexpr float k_pi_float = 3.14159265358979323846f;
static constexpr float k_inv_pi_float = 0.31830988618379067154f;
static constexpr float k_inv_2pi_float = 0.15915494309189533577f;
static constexpr float k_inv_4pi_float = 0.07957747154594766788f;
static constexpr float k_pi_over_2_float = 1.57079632679489661923f;
static constexpr float k_pi_over_4_float = 0.78539816339744830961f;
static constexpr float k_sqrt_2_float = 1.41421356237309504880f;
static constexpr double k_pi_double =
    3.1415926535897932384626433832795028841971693993751058209749445923;
static constexpr double k_inv_pi_double =
    0.3183098861837906715377675267450287240689192914809128974953346881;
static constexpr double k_inv_2pi_double =
    0.1591549430918953357688837633725143620344596457404564487476673440;
static constexpr double k_inv_4pi_double =
    0.0795774715459476678844418816862571810172298228702282243738336720;
static constexpr double k_pi_over_2_double =
    1.5707963267948966192313216916397514420985846996875529104874722961;
static constexpr double k_pi_over_4_double =
    0.7853981633974483096156608458198757210492923498437764552437361480;
static constexpr double k_sqrt_2_double =
    1.4142135623730950488016887242096980785696718753769480731766797379;

#if defined(_MSC_VER)
static constexpr float k_inf_float = static_cast<float>(1e300 * 1e300);
static constexpr float k_neg_inf_float = -k_inf_float;
static constexpr double k_inf_double = 1e300 * 1e300;
static constexpr double k_neg_inf_double = -k_inf_double;
#else
#error No definition for infinity constants!
#endif

static constexpr float k_largest_float = 3.4028234664e38f;
static constexpr float k_smallest_float = -3.4028234664e38f;
static constexpr double k_largest_double = 1.7976931348623158e308;
static constexpr double k_smallest_double = -1.7976931348623158e308;

/**
 * @brief Returns the absolute value of the given value.
 * @tparam T Value type.
 * @param value The value to take the absolute value of.
 * @return The absolute value of the given value.
 */
template <typename T>
T Abs(T value);

/**
 * @brief Checks if the given values are equal within the given epsilon.
 * @tparam T Value type.
 * @param a First value.
 * @param b Second value.
 * @param epsilon Epsilon.
 * @return True if the values are equal within the given epsilon, false otherwise.
 */
template <typename T>
bool IsEqual(T a, T b, T epsilon);

/**
 * @brief Returns the minimum of the given values.
 * @tparam T Value type.
 * @param A First value.
 * @param B Second value.
 * @return Returns the minimum of the given values.
 */
template <typename T>
T Min(T A, T B);

/**
 * @brief Returns the maximum of the given values.
 * @tparam T Value type.
 * @param A First value.
 * @param B Second value.
 * @return Returns the maximum of the given values.
 */
template <typename T>
T Max(T A, T B);

/**
 * Checks if the given value is NaN.
 * @tparam T Value type.
 * @param value The value to check.
 * @return True if the given value is NaN, false otherwise.
 */
template <typename T>
bool IsNaN(T value);

/**
 * @brief Checks if the given value is finite.
 * @tparam T Value type.
 * @param value The value to check.
 * @return True if the given value is finite, false otherwise.
 */
template <typename T>
bool IsFinite(T value);

/**
 * @brief Converts the given degrees to radians.
 * @tparam T Value type. Must be a floating point type.
 * @param degrees The degrees to convert.
 * @return The given degrees in radians.
 */
template <std::floating_point T>
T Radians(T degrees);

/**
 * @brief Converts the given radians to degrees.
 * @tparam T Value type. Must be a floating point type.
 * @param radians The radians to convert.
 * @return The given radians in degrees.
 */
template <std::floating_point T>
T Degrees(T radians);

/**
 * Clamps the given value between the given low and high values.
 * @tparam T Value type.
 * @param value Value to clamp.
 * @param low Low value.
 * @param high High value.
 * @return The clamped value.
 */
template <typename T>
T Clamp(T value, T low, T high);

/**
 * @brief Returns the remainder of A / B.
 * @param a The dividend.
 * @param b The divisor.
 * @return The remainder of A / B. Result will have the same sign as A. If A or B is NAN or B is 0,
 * NAN is returned.
 */
template <typename T>
T Mod(T a, T b);

/**
 * @brief Returns the square root of the given value.
 * @tparam T Value type. Must be a floating point type.
 * @param value The value to take the square root of.
 * @return The square root of the given value.
 */
template <std::floating_point T>
T Sqrt(T value);

/**
 * Returns the linear interpolation between the given values.
 * @tparam T Value type. Must be a floating point type.
 * @param t The interpolation factor.
 * @param p0 The first value.
 * @param p1 The second value.
 * @return The linear interpolation between the given values.
 */
template <std::floating_point T>
T Lerp(T t, T p0, T p1);

/**
 * @brief Returns the rounded value.
 * @tparam T Value type. Must be a floating point type.
 * @param value The value to round.
 * @return The rounded value. If the value is exactly halfway between two integers, the rounding is
 * done away from zero.
 */
template <std::floating_point T>
T Round(T value);

/**
 * @brief Returns the floor of the given value.
 * @tparam T Value type. Must be a floating point type.
 * @param value The value to take the floor of.
 * @return The floor of the given value.
 */
template <std::floating_point T>
T Floor(T value);

/**
 * @brief Returns the ceil of the given value.
 * @tparam T Value type. Must be a floating point type.
 * @param value The value to take the ceil of.
 * @return The ceil of the given value.
 */
template <std::floating_point T>
T Ceil(T value);

/**
 * @brief Returns the sine of the given value.
 * @tparam T Value type. Must be a floating point type.
 * @param radians The value to take the sine of in radians.
 * @return The sine of the given value.
 */
template <std::floating_point T>
T Sin(T radians);

/**
 * @brief Returns the cosine of the given value.
 * @tparam T Value type. Must be a floating point type.
 * @param radians The value to take the cosine of in radians.
 * @return The cosine of the given value.
 */
template <std::floating_point T>
T Cos(T radians);

/**
 * @brief Returns the tangent of the given value.
 * @tparam T Value type. Must be a floating point type.
 * @param radians The value to take the tangent of in radians.
 * @return The tangent of the given value.
 */
template <std::floating_point T>
T Tan(T radians);

/**
 * @brief Returns the base raised to the exponent power.
 * @tparam T Value type. Must be a floating point type.
 * @param base The base.
 * @param exponent The exponent.
 * @return The base raised to the exponent power.
 */
template <std::floating_point T>
T Power(T base, T exponent);

/**
 * @brief Returns the logarithm base e of the given value.
 * @tparam T Value type. Must be a floating point type.
 * @param value The value to take the logarithm base e of.
 * @return The logarithm base e of the given value. If value is 1 it returns 0. If value is 0 it
 * returns negative infinity. If value is positive infinity, it returns positive infinity. If value
 * is negative, negative infinity or NaN, it returns NaN.
 */
template <std::floating_point T>
T LogNatural(T value);

/**
 * @brief Returns the logarithm base 2 of the given value.
 * @param value The value to take the logarithm base 2 of.
 * @return The logarithm base 2 of the given value. If value is 1 it returns 0. If value is 0 it
 * returns negative infinity. If value is positive infinity, it returns positive infinity. If value
 * is negative, negative infinity or NaN, it returns NaN.
 */
template <std::floating_point T>
T Log2(T value);

}  // namespace math

// Implementation //////////////////////////////////////////////////////////////////////////////////

template <typename T>
T math::Abs(T value)
{
    return value >= 0 ? value : -value;
}

template <typename T>
bool math::IsEqual(T a, T b, T epsilon)
{
    return Abs(a - b) <= epsilon;
}

template <typename T>
T math::Min(T A, T B)
{
    return A < B ? A : B;
}

template <typename T>
T math::Max(T A, T B)
{
    return A > B ? A : B;
}

template <typename T>
bool math::IsNaN(T value)
{
    return value != value;
}

template <typename T>
bool math::IsFinite(T value)
{
    return std::isfinite(value);
}

template <std::floating_point T>
T math::Radians(T degrees)
{
    constexpr T k_half_circle_degrees = static_cast<T>(180.0);
    constexpr T k_pi = static_cast<T>(k_pi_double);
    return (k_pi / k_half_circle_degrees) * degrees;
}

template <std::floating_point T>
T math::Degrees(T radians)
{
    constexpr T k_half_circle_degrees = static_cast<T>(180.0);
    constexpr T k_pi = static_cast<T>(k_pi_double);
    return (k_half_circle_degrees / k_pi) * radians;
}

template <typename T>
T math::Clamp(T value, T low, T high)
{
    return Min(Max(value, low), high);
}

template <typename T>
T math::Mod(T a, T b)
{
    if constexpr (std::is_integral_v<T>)
    {
        return a % b;
    }
    else
    {
        if (IsNaN(a) || IsNaN(b) || b == 0)
        {
            return NAN;
        }
        return std::remainder(a, b);
    }
}

template <std::floating_point T>
T math::Sqrt(T value)
{
    return std::sqrt(value);
}

template <std::floating_point T>
T math::Lerp(T t, T p0, T p1)
{
    return (1 - t) * p0 + t * p1;
}

template <std::floating_point T>
T math::Round(T value)
{
    return std::round(value);
}

template <std::floating_point T>
T math::Floor(T value)
{
    return std::floor(value);
}

template <std::floating_point T>
T math::Ceil(T value)
{
    return std::ceil(value);
}

template <std::floating_point T>
T math::Sin(T radians)
{
    return std::sin(radians);
}

template <std::floating_point T>
T math::Cos(T radians)
{
    return std::cos(radians);
}

template <std::floating_point T>
T math::Tan(T radians)
{
    return std::tan(radians);
}

template <std::floating_point T>
T math::Power(T base, T exponent)
{
    return std::pow(base, exponent);
}

template <std::floating_point T>
T math::LogNatural(T value)
{
    return std::log(value);
}

template <std::floating_point T>
T math::Log2(T value)
{
    constexpr T k_inv_log2 =
        static_cast<T>(1.4426950408889634073599246810018921374266459541529859341354494069);
    return std::log(value) * k_inv_log2;
}
