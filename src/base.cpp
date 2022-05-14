#include "math/base.h"

#include "math/geometry.h"

template <>
inline bool math::IsNaN<int>(const int v)
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
float math::Mod(float a, float b)
{
    return std::fmod(a, b);
}

float math::Radians(float deg)
{
    return (Pi / 180) * deg;
}

float math::Degrees(float rad)
{
    return (180 / Pi) * rad;
}

float math::Log2(float x)
{
    const float invLog2 = 1.442695040888963387004650940071;
    return std::log(x) * invLog2;
}

int32_t math::Log2Int(uint32_t v)
{
#if defined(_MSC_VER)
    unsigned long firstOneIndex = 0;
    _BitScanReverse(&firstOneIndex, v);
    return firstOneIndex;
#else
    return 31 - __builtin_clz(v);
#endif
}

int32_t math::RoundUpPow2(int32_t v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    return v + 1;
}

int32_t math::CountTrailingZeros(uint32_t v)
{
#if defined(_MSC_VER)
    unsigned long firstOneIndex = 0;
    _BitScanReverse(&firstOneIndex, v);
    return 32 - firstOneIndex;
#else
    return __builtin_ctz(v);
#endif
}
