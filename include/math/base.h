#pragma once

#include <stdint.h>

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

static constexpr real kPi = MATH_REALC(3.14159265358979323846);
static constexpr real kInvPi = MATH_REALC(0.31830988618379067154);
static constexpr real kInVec2Pi = MATH_REALC(0.15915494309189533577);
static constexpr real kInv4Pi = MATH_REALC(0.07957747154594766788);
static constexpr real kPiOver2 = MATH_REALC(1.57079632679489661923);
static constexpr real kPiOver4 = MATH_REALC(0.78539816339744830961);
static constexpr real kSqrt2 = MATH_REALC(1.41421356237309504880);

#if defined(_MSC_VER)
static constexpr real kInfinity = static_cast<real>(1e300 * 1e300);
static constexpr real kNegativeInfinity = -kInfinity;
#else
#error No definition for infinity constants!
#endif

static constexpr real kLargestFloat = MATH_REALC(3.4028234664e38);
static constexpr real kSmallestFloat = MATH_REALC(-3.4028234664e38);

// Functions

bool IsNaN(real Value);
real Clamp(real Value, real Low, real High);

real Mod(real A, real B);

real Lerp(real Parameter, real P0, real P1);

bool IsPowerOf2(int Value);
real Radians(real Degrees);
real Degrees(real Radians);
real Log2(real Value);
int32_t Log2Int(uint32_t Value);
int32_t RoundUpPow2(int32_t Value);
int32_t CountTrailingZeros(uint32_t Value);

real Min(real A, real B);
real Max(real A, real B);
real Round(real Value);
real Floor(real Value);
real Ceil(real Value);
real Abs(real Value);

}  // namespace math
