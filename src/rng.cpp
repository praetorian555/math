#include "math/rng.h"

#include <cassert>

static constexpr uint64_t k_default_state = 0x853c49e6748fea9bULL;
static constexpr uint64_t k_default_stream = 0xda3e39cb94b95bdbULL;
static constexpr uint64_t k_mul_float = 0x5851f42d4c957f2dULL;
// Largest floating-point constant less then 1
static constexpr float k_one_minus_epsilon = 0x1.fffffep-1;

Math::RNG::RNG() : m_state(k_default_state), m_inc(k_default_stream) {}

Math::RNG::RNG(uint64_t starting_index)
{
    SetSequence(starting_index);
}

void Math::RNG::SetSequence(uint64_t starting_index)
{
    m_state = 0u;
    m_inc = (starting_index << 1u) | 1u;
    UniformUInt32();
    m_state += k_default_state;
    UniformUInt32();
}

uint32_t Math::RNG::UniformUInt32()
{
    const uint64_t old_state = m_state;
    m_state = old_state * k_mul_float + m_inc;
    const auto xor_shifted = static_cast<uint32_t>(((old_state >> 18u) ^ old_state) >> 27u);
    const auto Rot = static_cast<uint32_t>(old_state >> 59u);
    constexpr uint32_t k_lowest_five_bits = 31u;
    return (xor_shifted >> Rot) | (xor_shifted << ((~Rot + 1u) & k_lowest_five_bits));
}

uint32_t Math::RNG::UniformUInt32(uint32_t limit)
{
    const uint32_t threshold = (~limit + 1u) % limit;
    while (true)
    {
        const uint32_t random = UniformUInt32();
        if (random >= threshold)
        {
            return random % limit;
        }
    }
}

float Math::RNG::UniformFloat()
{
    constexpr float k_scalar = 0x1p-32f;
    return Min(k_one_minus_epsilon, static_cast<float>(UniformUInt32()) * k_scalar);
}

float Math::RNG::UniformFloatInRange(float start, float end)
{
    assert(start <= end);

    const float value = UniformFloat();
    return start + value * (end - start);
}
