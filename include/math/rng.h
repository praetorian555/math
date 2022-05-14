#pragma once

#include "math/base.h"

namespace math
{

// Pseudo-random number generator based on the paper PCG: A Family of Simple Fast
// Space-Efficient Statistically Good Algorithms for Random Number Generation by O'Neill (2014).
class RNG
{
public:
    RNG();
    RNG(uint64_t startingIndex);

    void SetSequence(uint64_t startingIndex);

    // Uniform number in range [0, UINT32_MAX - 1]
    uint32_t UniformUInt32();

    // Uniform number in range [0, limit - 1]
    uint32_t UniformUInt32(uint32_t limit);

    // Uniform number in range [0, 1)
    float UniformReal();

    // Uniform number in range [Start, End)
    float UniformRealInRange(float Start, float End);

private:
    uint64_t m_State, m_Inc;
};

}  // namespace math