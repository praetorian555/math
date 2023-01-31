#include "math/base.h"

#include <intrin.h>
#include <cmath>

bool math::IsNaN(real Value)
{
    return std::isnan(Value);
}

math::real math::Clamp(real Value, real Low, real High)
{
    return Value < Low ? Low : (Value > High ? High : Value);
}

math::real math::Mod(real A, real B)
{
    return std::fmodf(A, B);
}

math::real math::Radians(real Degrees)
{
    constexpr real kHalfCircleDegrees = 180.0f;
    return (kPi / kHalfCircleDegrees) * Degrees;
}

math::real math::Degrees(real Radians)
{
    constexpr real kHalfCircleDegrees = 180.0f;
    return (kHalfCircleDegrees / kPi) * Radians;
}

math::real math::Log2(real Value)
{
    constexpr real kInvLog2 = 1.442695040888963387004650940071f;
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

math::real math::Lerp(real Parameter, real P0, real P1)
{
    return (1 - Parameter) * P0 + Parameter * P1;
}

bool math::IsPowerOf2(int Value)
{
    return (Value != 0) && ((Value & (Value - 1)) == 0);
}

math::real math::Min(math::real A, math::real B)
{
    return std::min(A, B);
}

math::real math::Max(math::real A, math::real B)
{
    return std::max(A, B);
}

math::real math::Round(math::real Value)
{
#if MATH_REAL_AS_DOUBLE
    return std::round(Value);
#else
    return std::roundf(Value);
#endif
}

math::real math::Floor(math::real Value)
{
#if MATH_REAL_AS_DOUBLE
    return std::floor(Value);
#else
    return std::floorf(Value);
#endif
}

math::real math::Ceil(math::real Value)
{
#if MATH_REAL_AS_DOUBLE
    return std::ceil(Value);
#else
    return std::ceilf(Value);
#endif
}
