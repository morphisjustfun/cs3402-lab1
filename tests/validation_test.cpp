#include <gtest/gtest.h>

#include "NumberMatcher.hpp"

using namespace utec::compilers;

TEST(SimpleTest, basicTest) {
  NumberMatcher instance;

  EXPECT_TRUE(instance.match("-2.7E4"));
  EXPECT_TRUE(instance.match("1.e-2"));
  EXPECT_FALSE(instance.match("e-2"));
  EXPECT_TRUE(instance.match("-121."));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
