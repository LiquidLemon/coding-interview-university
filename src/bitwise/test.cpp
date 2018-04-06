#include "bitwise.hpp"
#include "gtest/gtest.h"

TEST(bitwise, abs) {
  EXPECT_EQ(binaryAbs(-5), 5);
  EXPECT_EQ(binaryAbs(5), 5);
}

TEST(bitwise, roundsUpToPowerOfTwo) {
  EXPECT_EQ(roundUpToPowerOf2(1), 1);
  EXPECT_EQ(roundUpToPowerOf2(2), 2);
  EXPECT_EQ(roundUpToPowerOf2(3), 4);
  EXPECT_EQ(roundUpToPowerOf2(100), 128);
}

TEST(bitwise, swapsValues) {
  int a = 5;
  int b = 13;
  xorSwap(a, b);
  EXPECT_EQ(a, 13);
  EXPECT_EQ(b, 5);
}

TEST(bitwise, countsBits) {
  EXPECT_EQ(countBits(0b101), 2);
  EXPECT_EQ(countBits(0b1000), 1);
  EXPECT_EQ(countBits(0b1011), 3);
}
