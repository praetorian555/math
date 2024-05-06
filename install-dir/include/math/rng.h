#pragma once

#include "math/base.h"
#include "math/export.h"

namespace Math
{

/**
 * Pseudo-random number generator based on the paper PCG: A Family of Simple Fast
 * Space-Efficient Statistically Good Algorithms for Random Number Generation by O'Neill (2014).
 */
class MATH_EXPORT RNG
{
public:
    /**
     * RNG with default seed.
     */
    RNG();

    /**
     * RNG with custom seed.
     */
    explicit RNG(uint64_t starting_index);

    /**
     * Configure the RNG seed.
     * @param starting_index Seed.
     */
    void SetSequence(uint64_t starting_index);

    /**
     * @brief Generate a uniform random number in range [0, UINT32_MAX - 1].
     * @return Random number.
     */
    uint32_t UniformUInt32();

    /**
     * @brief Generate a uniform random number in range [0, limit - 1].
     * @param limit Upper bound.
     * @return Random number.
     */
    uint32_t UniformUInt32(uint32_t limit);

    /**
     * @brief Generate a uniform random number in range [0, 1).
     * @return Random number.
     */
    float UniformFloat();

    /**
     * @brief Generate a uniform random number in range [start, end).
     * @param start Lower bound.
     * @param end Upper bound.
     * @return Random number.
     */
    float UniformFloatInRange(float start, float end);

private:
    uint64_t m_state = 0;
    uint64_t m_inc = 0;
};

}  // namespace Math