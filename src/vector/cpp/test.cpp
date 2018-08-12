#include "Vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, storesData) {
  Vector<int> v;
  v.push(1);
  v.push(2);
}
