#include "math/rng.h"

#include <cassert>
#include <cmath>

static constexpr auto DEFAULT_STATE = 0x853c49e6748fea9bULL;
static constexpr auto DEFAULT_STREAM = 0xda3e39cb94b95bdbULL;
static constexpr auto MULfloat = 0x5851f42d4c957f2dULL;
// Largest floating-point constant less then 1
static constexpr float ONE_MINUS_EPSILON = 0x1.fffffep-1;

math::RNG::RNG() : m_State(DEFAULT_STATE), m_Inc(DEFAULT_STREAM) {}

math::RNG::RNG(uint64_t StartingIndex)
{
    SetSequence(StartingIndex);
}

void math::RNG::SetSequence(uint64_t StartingIndex)
{
    m_State = 0u;
    m_Inc = (StartingIndex << 1u) | 1u;
    UniformUInt32();
    m_State += DEFAULT_STATE;
    UniformUInt32();
}

uint32_t math::RNG::UniformUInt32()
{
    const uint64_t OldState = m_State;
    m_State = OldState * MULfloat + m_Inc;
    const auto XorShifted = static_cast<uint32_t>(((OldState >> 18u) ^ OldState) >> 27u);
    const auto Rot = static_cast<uint32_t>(OldState >> 59u);
    constexpr uint32_t IgnoreHighestBitMask = 31u;
    return (XorShifted >> Rot) | (XorShifted << ((~Rot + 1u) & IgnoreHighestBitMask));
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

float math::RNG::UniformReal()
{
    constexpr float Scalar = 0x1p-32f;
    return std::fmin(ONE_MINUS_EPSILON, static_cast<float>(UniformUInt32()) * Scalar);
}

float math::RNG::UniformRealInRange(float Start, float End)
{
    assert(Start <= End);

    const float Value = UniformReal();
    return Start + Value * (End - Start);
}
