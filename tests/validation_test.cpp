#include <gtest/gtest.h>

#include "NumberMatcher.hpp"

using namespace utec::compilers;

TEST(SimpleTest, basicTest) {
  NumberMatcher instance;

  EXPECT_TRUE(instance.match("-2.7E4"));
  EXPECT_TRUE(instance.match("1.e-2"));
  EXPECT_FALSE(instance.match("e-2"));
  EXPECT_TRUE(instance.match("-121."));
  EXPECT_TRUE(instance.match("1.e-2"));
  EXPECT_FALSE(instance.match("e-2"));
  EXPECT_TRUE(instance.match("-121."));
  EXPECT_FALSE(instance.match("."));
  EXPECT_TRUE(instance.match("1"));
  EXPECT_TRUE(instance.match(".1"));
  EXPECT_FALSE(instance.match("e1"));
  EXPECT_TRUE(instance.match("1e1"));
  EXPECT_TRUE(instance.match("1E1"));
  EXPECT_TRUE(instance.match("+1e1"));
  EXPECT_TRUE(instance.match("-1.E1"));
  EXPECT_TRUE(instance.match("+.1e-1"));
  EXPECT_FALSE(instance.match("-1.E"));
  EXPECT_TRUE(instance.match(".3"));
  EXPECT_TRUE(instance.match("3."));
  EXPECT_FALSE(instance.match("-"));
  EXPECT_FALSE(instance.match("+"));
  EXPECT_FALSE(instance.match("-."));
  EXPECT_FALSE(instance.match("-.e"));
  EXPECT_FALSE(instance.match("-.e12"));
  EXPECT_FALSE(instance.match("-.e-12"));
  EXPECT_FALSE(instance.match("-.e-12"));
  EXPECT_FALSE(instance.match("-.e+12"));
  EXPECT_FALSE(instance.match("-.E"));
  EXPECT_FALSE(instance.match("-.E12"));
  EXPECT_FALSE(instance.match("-.-E12"));
  EXPECT_FALSE(instance.match("-.-E-12"));
  EXPECT_FALSE(instance.match("-.-E+12"));
  EXPECT_FALSE(instance.match("+."));
  EXPECT_FALSE(instance.match("+.e"));
  EXPECT_FALSE(instance.match("+.e12"));
  EXPECT_FALSE(instance.match("+.e-12"));
  EXPECT_FALSE(instance.match("+.e+12"));
  EXPECT_FALSE(instance.match("+.E"));
  EXPECT_FALSE(instance.match("+.E12"));
  EXPECT_FALSE(instance.match("+.E-12"));
  EXPECT_FALSE(instance.match("+.E+12"));
  EXPECT_TRUE(instance.match("+0.E+12"));
  EXPECT_TRUE(instance.match("0.E0"));
  EXPECT_TRUE(instance.match("0.E+0"));
  EXPECT_TRUE(instance.match("+0.0E+12"));
  EXPECT_FALSE(instance.match("+0.0E+"));
  EXPECT_FALSE(instance.match("+0.0E-"));
  EXPECT_TRUE(instance.match("+00000.000000E+12"));
  EXPECT_TRUE(instance.match("+00000.000000E12"));
  EXPECT_TRUE(instance.match("-00000.000000E-12"));
  EXPECT_TRUE(instance.match("-00000.000000E+12"));
  EXPECT_TRUE(instance.match("00000.000000E+12"));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
