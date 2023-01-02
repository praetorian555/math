#include "math/base.h"

#include <intrin.h>
#include <cmath>

bool math::IsNaN(float Value)
{
    return std::isnan(Value);
}

float math::Clamp(float Value, float Low, float High)
{
    return Value < Low ? Low : (Value > High ? High : Value);
}

float math::Mod(float A, float B)
{
    return std::fmodf(A, B);
}

float math::Radians(float Degrees)
{
    constexpr float kHalfCircleDegrees = 180.0f;
    return (kPi / kHalfCircleDegrees) * Degrees;
}

float math::Degrees(float Radians)
{
    constexpr float kHalfCircleDegrees = 180.0f;
    return (kHalfCircleDegrees / kPi) * Radians;
}

float math::Log2(float Value)
{
    constexpr float kInvLog2 = 1.442695040888963387004650940071f;
    return std::log(Value) * kInvLog2;
}

int32_t math::Log2Int(uint32_t Value)
{
#if defined(_MSC_VER)
    unsigned long FirstOneIndex = 0; // NOLINT
    _BitScanReverse(&FirstOneIndex, Value);
    return static_cast<int32_t>(FirstOneIndex);
#else
    return 31 - __builtin_clz(Value);
#endif
}

int32_t math::RoundUpPow2(int32_t Value)
{
    constexpr int kShiftHalfByte = 4;
    constexpr int kShiftByte = 8;
    constexpr int kShiftTwoBytes = 16;

    Value--;
    Value |= Value >> 1;
    Value |= Value >> 2;
    Value |= Value >> kShiftHalfByte;
    Value |= Value >> kShiftByte;
    Value |= Value >> kShiftTwoBytes;
    return Value + 1;
}

int32_t math::CountTrailingZeros(uint32_t Value)
{
#if defined(_MSC_VER)
    unsigned long FirstOneIndex = 0; // NOLINT
    _BitScanReverse(&FirstOneIndex, Value);
    constexpr int32_t kBitsInInt32 = 32;
    return kBitsInInt32 - static_cast<int32_t>(FirstOneIndex);
#else
    return __builtin_ctz(Value);
#endif
}

float math::Lerp(float Parameter, float P0, float P1)
{
    return (1 - Parameter) * P0 + Parameter * P1;
}

bool math::IsPowerOf2(int Value)
{
    return (Value != 0) && ((Value & (Value - 1)) == 0);
}
