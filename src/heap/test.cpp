#include "Heap.hpp"
#include "gtest/gtest.h"

TEST(HEAP, constructor) {
  Heap<int> heap;
}

TEST(HEAP, isEmpty) {
  Heap<int> heap;
  EXPECT_TRUE(heap.isEmpty());

  heap.insert(1);
  EXPECT_FALSE(heap.isEmpty());
}

TEST(HEAP, getMax) {
  Heap<int> heap;

  heap.insert(1);
  EXPECT_EQ(heap.getMax(), 1);

  heap.insert(0);
  EXPECT_EQ(heap.getMax(), 1);

  heap.insert(2);
  EXPECT_EQ(heap.getMax(), 2);
}
