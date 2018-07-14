#include "chainbase.hpp"
#include "TestChainBase.h"


ChainBaseTest::ChainBaseTest()
{
}

TEST_F(ChainBaseTest, SampleTest1) {
    EXPECT_EQ(true, true);
}

TEST_F(ChainBaseTest, SampleTest2) {
    EXPECT_EQ(false, false);
}

TEST_F(ChainBaseTest, SampleTest3) {
    EXPECT_EQ(true, false);
}
