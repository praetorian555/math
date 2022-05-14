#pragma once

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <numeric>

#define MATH_ASSERT(Condition) assert(Condition)

namespace math
{

// Constants

static constexpr float Pi = 3.14159265358979323846;
static constexpr float InvPi = 0.31830988618379067154;
static constexpr float Inv2Pi = 0.15915494309189533577;
static constexpr float Inv4Pi = 0.07957747154594766788;
static constexpr float PiOver2 = 1.57079632679489661923;
static constexpr float PiOver4 = 0.78539816339744830961;
static constexpr float Sqrt2 = 1.41421356237309504880;
static constexpr float Infinity = std::numeric_limits<float>::infinity();

// Functions

template <typename T>
bool IsNaN(const T v);
template <typename T, typename V, typename U>
T Clamp(T val, V low, U high);
template <typename T>
T Mod(T a, T b);
template <typename T>
T Lerp(float t, T p0, T p1);
template <typename T>
bool IsPowerOf2(T v);
float Radians(float deg);
float Degrees(float rad);
float Log2(float x);
int32_t Log2Int(uint32_t v);
int32_t RoundUpPow2(int32_t v);
int32_t CountTrailingZeros(uint32_t v);

}  // namespace math

///////////////////////////////////////////////////////////////////////////////////////////////////
// Implementations
///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
inline bool math::IsNaN(const T v)
{
    return std::isnan(v);
}

template <typename T, typename V, typename U>
T Clamp(T val, V low, U high)
{
    return val < low ? low : (val > high ? high : val);
}

template <typename T>
T Mod(T a, T b)
{
    T result = a - (a / b) * b;
    return (T)((result < 0) ? result + b : result);
}

template <typename T>
T Lerp(float t, T p0, T p1)
{
    return (1 - t) * p0 + t * p1;
}

template <typename T>
inline bool IsPowerOf2(T v)
{
    return v && !(v & (v - 1));
}
