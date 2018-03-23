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

TEST(HEAP, extractMax) {
  Heap<int> heap;

  heap.insert(1);
  heap.insert(0);
  heap.insert(2);
  heap.insert(4);
  heap.insert(3);
  heap.insert(5);

  EXPECT_EQ(heap.extractMax(), 5);
  EXPECT_EQ(heap.extractMax(), 4);
  EXPECT_EQ(heap.extractMax(), 3);
  EXPECT_EQ(heap.extractMax(), 2);
  EXPECT_EQ(heap.extractMax(), 1);
  EXPECT_EQ(heap.extractMax(), 0);
  EXPECT_TRUE(heap.isEmpty());
}

TEST(HEAP, remove) {
  Heap<int> heap;

  heap.insert(5);
  heap.insert(2);
  heap.insert(3);
  heap.insert(1);
  heap.insert(0);

  heap.remove(3);

  EXPECT_EQ(heap.getSize(), 4);
  EXPECT_EQ(heap.extractMax(), 5);
  EXPECT_EQ(heap.extractMax(), 2);
  EXPECT_EQ(heap.extractMax(), 1);
  EXPECT_EQ(heap.extractMax(), 0);
}

TEST(HEAP, constructFromArray) {
  int *data = new int[6];
  data[0] = 5;
  data[1] = 3;
  data[2] = -1;
  data[3] = 2;
  data[4] = 0;
  data[5] = 42;
  Heap<int> heap(data, 6);

  EXPECT_EQ(heap.getSize(), 6);
  EXPECT_EQ(heap.extractMax(), 42);
  EXPECT_EQ(heap.extractMax(), 5);
  EXPECT_EQ(heap.extractMax(), 3);
  EXPECT_EQ(heap.extractMax(), 2);
  EXPECT_EQ(heap.extractMax(), 0);
  EXPECT_EQ(heap.extractMax(), -1);
}

TEST(HEAP, sort) {
  int *data = new int[6];
  data[0] = 5;
  data[1] = 3;
  data[2] = -1;
  data[3] = 2;
  data[4] = 0;
  data[5] = 42;
  Heap<int> heap(data, 6);

  data = heap.heapSort();
  EXPECT_EQ(data[0], -1);
  EXPECT_EQ(data[1], 0);
  EXPECT_EQ(data[2], 2);
  EXPECT_EQ(data[3], 3);
  EXPECT_EQ(data[4], 5);
  EXPECT_EQ(data[5], 42);

  delete[] data;
}
