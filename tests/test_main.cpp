#include "math/math.h"

#include "gtest/gtest.h"

TEST(MainTestSuite, FirstTest)
{
    HelloWorld();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
