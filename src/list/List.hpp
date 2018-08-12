#include <cstddef>
#include "Node.hpp"

#ifndef LIST_HPP
#define LISH_HPP

template <typename T>
class List {
  private:
  Node<T> *head;

  public:
  List();

  size_t size();
  bool empty();
  void pushFront(T value);
  T popFront();
};

template class List<int>;
#endif
