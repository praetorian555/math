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
bool IsNaN(const T Value);
template <typename T, typename V, typename U>
T Clamp(T Value, V Low, U High);
template <typename T>
T Mod(T A, T B);
template <typename T>
float Lerp(float Parameter, T P0, T P1);
template <typename T>
bool IsPowerOf2(T Value);
float Radians(float Degrees);
float Degrees(float Radians);
float Log2(float Value);
int32_t Log2Int(uint32_t Value);
int32_t RoundUpPow2(int32_t Value);
int32_t CountTrailingZeros(uint32_t Value);

}  // namespace math

///////////////////////////////////////////////////////////////////////////////////////////////////
// Implementations
///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
inline bool math::IsNaN(const T Value)
{
    return std::isnan(Value);
}

template <>
bool math::IsNaN(const int Value);

template <typename T, typename V, typename U>
T math::Clamp(T Value, V Low, U High)
{
    return Value < Low ? Low : (Value > High ? High : Value);
}

template <typename T>
T math::Mod(T A, T B)
{
    T Result = A - (A / B) * B;
    return (T)((Result < 0) ? Result + B : Result);
}

template <>
float math::Mod(float A, float B);
template <>
double math::Mod(double A, double B);

template <typename T>
float math::Lerp(float Parameter, T P0, T P1)
{
    return (1 - Parameter) * P0 + Parameter * P1;
}

template <typename T>
bool math::IsPowerOf2(T Value)
{
    return Value && !(Value & (Value - 1));
}

template <>
bool math::IsPowerOf2(float Value);
template <>
bool math::IsPowerOf2(double Value);
