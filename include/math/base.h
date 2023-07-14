#pragma once

#include <cstdint>

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
#if MATH_REAL_AS_DOUBLE
static constexpr real kPi = 3.1415926535897932384626433832795028841971693993751058209749445923;
static constexpr real kInvPi = 0.3183098861837906715377675267450287240689192914809128974953346881;
static constexpr real kInVec2Pi = 0.1591549430918953357688837633725143620344596457404564487476673440;
static constexpr real kInv4Pi = 0.0795774715459476678844418816862571810172298228702282243738336720;
static constexpr real kPiOver2 = 1.5707963267948966192313216916397514420985846996875529104874722961;
static constexpr real kPiOver4 = 0.7853981633974483096156608458198757210492923498437764552437361480;
static constexpr real kSqrt2 = 1.4142135623730950488016887242096980785696718753769480731766797379;
#else
static constexpr real kPi = MATH_REALC(3.14159265358979323846);
static constexpr real kInvPi = MATH_REALC(0.31830988618379067154);
static constexpr real kInVec2Pi = MATH_REALC(0.15915494309189533577);
static constexpr real kInv4Pi = MATH_REALC(0.07957747154594766788);
static constexpr real kPiOver2 = MATH_REALC(1.57079632679489661923);
static constexpr real kPiOver4 = MATH_REALC(0.78539816339744830961);
static constexpr real kSqrt2 = MATH_REALC(1.41421356237309504880);
#endif

#if defined(_MSC_VER)
static constexpr real kInfinity = static_cast<real>(1e300 * 1e300);
static constexpr real kNegativeInfinity = -kInfinity;
#else
#error No definition for infinity constants!
#endif

#if MATH_REAL_AS_DOUBLE
static constexpr real kLargestReal = MATH_REALC(1.7976931348623158e308);
static constexpr real kSmallestReal = MATH_REALC(-1.7976931348623158e308);
#else
static constexpr real kLargestReal = MATH_REALC(3.4028234664e38);
static constexpr real kSmallestReal = MATH_REALC(-3.4028234664e38);
#endif

// Functions

// @brief Returns the absolute value of the given value.
// @param Value The value to take the absolute value of.
// @return The absolute value of the given value.
template <typename T>
T Abs(T value)
{
    return value >= 0 ? value : -value;
}

// @brief Returns true if value A is in the range [B - Epsilon, B + Epsilon].
// @param A The value to check.
// @param B The value to check against.
// @param Epsilon The epsilon value.
// @return True if value A is in the range [B - Epsilon, B + Epsilon], false otherwise.
template <typename T>
bool IsEqual(T a, T b, T epsilon)
{
    return Abs(a - b) <= epsilon;
}

// @brief Returns the minimum of the given values.
// @param A The first value.
// @param B The second value.
// @return The minimum of the given values.
template <typename T>
T Min(T A, T B)
{
    return A < B ? A : B;
}

// @brief Returns the maximum of the given values.
// @param A The first value.
// @param B The second value.
// @return The maximum of the given values.
template <typename T>
T Max(T A, T B)
{
    return A > B ? A : B;
}

// @brief Returns true if the given value is NaN.
// @param Value The value to check.
// @return True if the value is NaN, false otherwise.
template <typename T>
bool IsNaN(T value)
{
    return value != value;
}

// @brief Clamps the given value to the range [Low, High].
// @param Value The value to clamp.
// @param Low The lower bound of the range.
// @param High The upper bound of the range.
// @return The clamped value.
template <typename T>
T Clamp(T value, T low, T high)
{
    return Min(Max(value, low), high);
}

// @brief Returns the remainder of A / B.
// @param A The dividend.
// @param B The divisor.
// @return The remainder of A / B. Result will hava the same sign as A. If A or B is NAN or B is 0,
// NAN is returned.
real Mod(real A, real B);

// @brief Returns the square root of the given value.
// @param Value The value to take the square root of.
// @return The square root of the given value.
real Sqrt(real Value);

// @brief Returns the linear interpolation of P0 and P1 at the given parameter.
// @param Parameter The parameter to interpolate at.
// @param P0 The first point.
// @param P1 The second point.
// @return The linear interpolation of P0 and P1 at the given parameter.
real Lerp(real Parameter, real P0, real P1);

// @brief Returns the rounded value.
// @param Value The value to round.
// @return The rounded value. If the value is exactly halfway between two integers, the rounding is
// done away from zero.
real Round(real Value);

// @brief Returns the floor of the given value.
// @param Value The value to take the floor of.
// @return The floor of the given value.
real Floor(real Value);

// @brief Returns the ceiling of the given value.
// @param Value The value to take the ceiling of.
// @return The ceiling of the given value.
real Ceil(real Value);

// @brief Converts the given value from degrees to radians.
// @param Degrees The value to convert from degrees to radians.
// @return The given value converted from degrees to radians.
real Radians(real Degrees);

// @brief Converts the given value from radians to degrees.
// @param Radians The value to convert from radians to degrees.
// @return The given value converted from radians to degrees.
real Degrees(real Radians);

// @brief Returns the sine of the given value.
// @param Radians The value to take the sine of.
// @return The sine of the given value.
real Sin(real Radians);

// @brief Returns the cosine of the given value.
// @param Radians The value to take the cosine of.
// @return The cosine of the given value.
real Cos(real Radians);

// @brief Returns the tangent of the given value.
// @param Radians The value to take the tangent of.
// @return The tangent of the given value.
real Tan(real Radians);

// @brief Returns the power of the given base and exponent.
// @param Base The base of the power.
// @param Exponent The exponent of the power.
// @return The power of the given base and exponent.
real Power(real Base, real Exponent);

// @brief Returns the logarithm base e of the given value.
// @param Value The value to take the logarithm base e of.
// @return The logarithm base e of the given value. If value is 1 it returns 0. If value is 0 it
// returns negative infinity. If value is positive infinity, it returns positive infinity. If value
// is negative, negative infinity or NaN, it returns NaN.
real LogNatural(real Value);

// @brief Returns the logarithm base 2 of the given value.
// @param Value The value to take the logarithm base 2 of.
// @return The logarithm base 2 of the given value. If value is 1 it returns 0. If value is 0 it
// returns negative infinity. If value is positive infinity, it returns positive infinity. If value
// is negative, negative infinity or NaN, it returns NaN.
real Log2(real Value);

// @brief Returns the base 2 logarithm of the given value.
// @param Value The value to take the base 2 logarithm of.
// @return The base 2 logarithm of the given value. If value is 1 or less it returns 0.
int32_t Log2Int(uint32_t Value);

// @brief Returns true if the given value is a power of 2.
// @param Value The value to check.
// @return True if the given value is a power of 2, false otherwise.
bool IsPowerOf2(int Value);

// @brief Returns the next power of 2 greater than or equal to the given value.
// @param Value The value to round up to the next power of 2.
// @return The next power of 2 greater than or equal to the given value.
int32_t RoundUpPow2(int32_t Value);

// @brief Returns the number of leading zeros in the given value.
// @param Value The value to count the number of leading zeros in.
// @return The number of leading zeros in the given value.
int32_t CountTrailingZeros(uint32_t Value);

}  // namespace math
