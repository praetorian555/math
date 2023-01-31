#include "math/rng.h"

#include <cassert>
#include <cmath>

static constexpr uint64_t kDefaultState = 0x853c49e6748fea9bULL;
static constexpr uint64_t kDefaultStream = 0xda3e39cb94b95bdbULL;
static constexpr uint64_t kMulFloat = 0x5851f42d4c957f2dULL;
// Largest realing-point constant less then 1
static constexpr math::real kOneMinusEpsilon = 0x1.fffffep-1;

math::RNG::RNG() : m_State(kDefaultState), m_Inc(kDefaultStream) {}

math::RNG::RNG(uint64_t StartingIndex)
{
    SetSequence(StartingIndex);
}

void math::RNG::SetSequence(uint64_t StartingIndex)
{
    m_State = 0u;
    m_Inc = (StartingIndex << 1u) | 1u;
    UniformUInt32();
    m_State += kDefaultState;
    UniformUInt32();
}

uint32_t math::RNG::UniformUInt32()
{
    const uint64_t OldState = m_State;
    m_State = OldState * kMulFloat + m_Inc;
    const auto XorShifted = static_cast<uint32_t>(((OldState >> 18u) ^ OldState) >> 27u);
    const auto Rot = static_cast<uint32_t>(OldState >> 59u);
    constexpr uint32_t kLowestFiveBits = 31u;
    return (XorShifted >> Rot) | (XorShifted << ((~Rot + 1u) & kLowestFiveBits));
}

uint32_t math::RNG::UniformUInt32(uint32_t Limit)
{
    const uint32_t Threshold = (~Limit + 1u) % Limit;
    while (true)
    {
        const uint32_t Random = UniformUInt32();
        if (Random >= Threshold)
        {
            return Random % Limit;
        }
    }
}

math::real math::RNG::UniformReal()
{
    constexpr real kScalar = 0x1p-32f;
    return Min(kOneMinusEpsilon, static_cast<real>(UniformUInt32()) * kScalar);
}

math::real math::RNG::UniformRealInRange(real Start, real End)
{
    assert(Start <= End);

    const real Value = UniformReal();
    return Start + Value * (End - Start);
}
