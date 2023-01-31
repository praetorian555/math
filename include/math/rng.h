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
    explicit RNG(uint64_t StartingIndex);

    void SetSequence(uint64_t StartingIndex);

    // Uniform number in range [0, UINT32_MAX - 1]
    uint32_t UniformUInt32();

    // Uniform number in range [0, limit - 1]
    uint32_t UniformUInt32(uint32_t Limit);

    // Uniform number in range [0, 1)
    real UniformReal();

    // Uniform number in range [Start, End)
    real UniformRealInRange(real Start, real End);

private:
    uint64_t m_State = 0;
    uint64_t m_Inc = 0;
};

}  // namespace math