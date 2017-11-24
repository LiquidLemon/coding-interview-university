#include <cstddef>

#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class Vector {
  private:
  size_t maxLength;
  size_t length;
  T *items;

  size_t resize(size_t);

  public:
  Vector();
  Vector(size_t);

  size_t size();
  size_t capacity();
  bool is_empty();
  T at(size_t); // replace with []
  void push(T);
  void insert(size_t, T);
  void prepend(T);
  T pop();
  T delete_at(size_t);
  int remove(T);
  int find(T);
};

template class Vector<int>;
#endif
