#include "SearchTree.hpp"
#include <sstream>
#include "gtest/gtest.h"

TEST(BST, insertsElements) {
  SearchTree<int> bst;
  bst.insert(1);
  bst.insert(2);
}

TEST(BST, countsElements) {
  SearchTree<int> bst;
  EXPECT_EQ(bst.get_node_count(), 0);
  bst.insert(1);
  bst.insert(2);
  bst.insert(2);
  EXPECT_EQ(bst.get_node_count(), 2);
}

TEST(BST, printsElements) {
  SearchTree<int> bst;
  bst.insert(1);
  bst.insert(3);
  bst.insert(2);
  std::stringstream ss;
  bst.print_values(&ss);
  EXPECT_EQ(ss.str(), "1 2 3 ");
}

TEST(BST, deletesTree) {
  SearchTree<int> bst;
  bst.insert(1);
  bst.insert(3);
  bst.insert(2);
  bst.delete_tree();
  EXPECT_EQ(bst.get_node_count(), 0);
}

TEST(BST, searchesForValue) {
  SearchTree<int> bst;
  EXPECT_FALSE(bst.is_in_tree(1));

  bst.insert(1);
  bst.insert(3);
  bst.insert(2);
  EXPECT_TRUE(bst.is_in_tree(1));
  EXPECT_TRUE(bst.is_in_tree(2));
  EXPECT_FALSE(bst.is_in_tree(0));
}

TEST(BST, getsMinimalValue) {
  SearchTree<int> bst;
  auto result = bst.get_min();
  EXPECT_FALSE(result.success);

  bst.insert(1);
  bst.insert(3);
  bst.insert(2);
  result = bst.get_min();
  EXPECT_TRUE(result.success);
  EXPECT_EQ(result.value, 1);

  bst.insert(0);
  result = bst.get_min();
  EXPECT_TRUE(result.success);
  EXPECT_EQ(result.value, 0);
}

TEST(BST, getsMaximalValue) {
  SearchTree<int> bst;
  auto result = bst.get_max();
  EXPECT_FALSE(result.success);

  bst.insert(1);
  bst.insert(3);
  bst.insert(2);
  result = bst.get_max();
  EXPECT_TRUE(result.success);
  EXPECT_EQ(result.value, 3);

  bst.insert(5);
  result = bst.get_max();
  EXPECT_TRUE(result.success);
  EXPECT_EQ(result.value, 5);
}
