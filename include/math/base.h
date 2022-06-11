#pragma once

#include <stdint.h>

namespace math
{

// Constants

static constexpr float kPi = 3.14159265358979323846;
static constexpr float kInvPi = 0.31830988618379067154;
static constexpr float kInVec2Pi = 0.15915494309189533577;
static constexpr float kInv4Pi = 0.07957747154594766788;
static constexpr float kPiOver2 = 1.57079632679489661923;
static constexpr float kPiOver4 = 0.78539816339744830961;
static constexpr float kSqrt2 = 1.41421356237309504880;

#if defined(_MSC_VER)
static constexpr float kInfinity = (1e300 * 1e300);
static constexpr float kNegativeInfinity = -kInfinity;
#else
#error No definition for infinity constants!
#endif

static constexpr float kLargestFloat = 3.4028234664e38;
static constexpr float kSmallestFloat = -3.4028234664e38;

// Functions

bool IsNaN(float Value);
float Clamp(float Value, float Low, float High);

float Mod(float A, float B);

float Lerp(float Parameter, float P0, float P1);

bool IsPowerOf2(int Value);
float Radians(float Degrees);
float Degrees(float Radians);
float Log2(float Value);
int32_t Log2Int(uint32_t Value);
int32_t RoundUpPow2(int32_t Value);
int32_t CountTrailingZeros(uint32_t Value);

}  // namespace math
