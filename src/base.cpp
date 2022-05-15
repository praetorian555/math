#include "math/base.h"

#include "math/geometry.h"

template <>
bool math::IsNaN(const int Value)
{
    return false;
}

template <>
bool math::Point2<int>::HasNaNs() const
{
    return false;
}

template <>
bool math::Point3<int>::HasNaNs() const
{
    return false;
}

template <>
float math::Mod(float A, float B)
{
    return std::fmodf(A, B);
}

template <>
double math::Mod(double A, double B)
{
    return std::fmod(A, B);
}

template <>
bool math::IsPowerOf2(float Value)
{
    return false;
}

template <>
bool math::IsPowerOf2(double Value)
{
    return false;
}

float math::Radians(float Degrees)
{
    return (Pi / 180) * Degrees;
}

float math::Degrees(float Radians)
{
    return (180 / Pi) * Radians;
}

float math::Log2(float Value)
{
    constexpr float InvLog2 = 1.442695040888963387004650940071;
    return std::log(Value) * InvLog2;
}

int32_t math::Log2Int(uint32_t Value)
{
#if defined(_MSC_VER)
    unsigned long FirstOneIndex = 0;
    _BitScanReverse(&FirstOneIndex, Value);
    return FirstOneIndex;
#else
    return 31 - __builtin_clz(Value);
#endif
}

int32_t math::RoundUpPow2(int32_t Value)
{
    Value--;
    Value |= Value >> 1;
    Value |= Value >> 2;
    Value |= Value >> 4;
    Value |= Value >> 8;
    Value |= Value >> 16;
    return Value + 1;
}

int32_t math::CountTrailingZeros(uint32_t Value)
{
#if defined(_MSC_VER)
    unsigned long FirstOneIndex = 0;
    _BitScanReverse(&FirstOneIndex, Value);
    return 32 - FirstOneIndex;
#else
    return __builtin_ctz(Value);
#endif
}
