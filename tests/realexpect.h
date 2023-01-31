#pragma once

#include <gtest/gtest.h>

#if MATH_REAL_AS_DOUBLE
#define EXPECT_REAL_EQ(a, b) EXPECT_DOUBLE_EQ(a, b)
#else
#define EXPECT_REAL_EQ(a, b) EXPECT_FLOAT_EQ(a, b)
#endif