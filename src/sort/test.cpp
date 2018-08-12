#include "sort.hpp"
#include "gtest/gtest.h"

TEST(SORT, quicksort) {
  int data[] = { 5, 1, 0, -4, -1, 12, 45, 5 };
  int expected[] = { -4, -1, 0, 1, 5, 5, 12, 45 };
  size_t size = sizeof(data)/sizeof(int);
  quicksort(data, size);

  for (size_t i = 0; i < size; i++) {
    EXPECT_EQ(data[i], expected[i]);
  }
}

TEST(SORT, quicksortEmpty) {
  int data[] = {};
  quicksort(data, 0);
}

TEST(SORT, insertsort) {
  int data[] = { 1, -2, 5, 6, -3, 15, 0 };
  int expected[] = { -3, -2, 0, 1, 5, 6, 15 };
  size_t size = sizeof(data)/sizeof(int);
  insertsort(data, size);

  for (size_t i = 0; i < size; i++) {
    EXPECT_EQ(data[i], expected[i]);
  }
}

TEST(SORT, selectsort) {
  int data[] = { 1, -2, 5, 6, -3, 15, 0 };
  int expected[] = { -3, -2, 0, 1, 5, 6, 15 };
  size_t size = sizeof(data)/sizeof(int);
  selectsort(data, size);

  for (size_t i = 0; i < size; i++) {
    EXPECT_EQ(data[i], expected[i]);
  }
}

TEST(SORT, customComparator) {
  int data[] = { 1, -2, 5, 6, -3, 15, 0 };
  int expected[] = { 15, 6, 5, 1, 0, -2, -3 };
  size_t size = sizeof(data)/sizeof(int);

  Comparator<int> reverseComparator = [](const int& a, const int& b) {
    if (a == b) return Ordering::EQ;
    if (a < b) return Ordering::GT;
    return Ordering::LT;
  };

  quicksort(data, 0, size - 1, reverseComparator);

  for (size_t i = 0; i < size; i++) {
    EXPECT_EQ(data[i], expected[i]);
  }
}

TEST(SORT, mergeSort) {
  int data[] = { 1, -2, 5, 6, -3, 15, 0 };
  int expected[] = { -3, -2, 0, 1, 5, 6, 15 };
  size_t size = sizeof(data)/sizeof(int);
  mergesort(data, size);

  for (size_t i = 0; i < size; i++) {
    EXPECT_EQ(data[i], expected[i]);
  }
}
