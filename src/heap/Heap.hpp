#pragma once
#include <cstddef>
#include <algorithm>
#include <cstring>

// 2 * n     -> smaller
// 2 * n + 1 -> greater
template <typename T>
class Heap {
private:
  T *data;
  size_t capacity;
  size_t size;

  void resize(size_t size) {
    // no-op
    if (size == capacity) {
      return;
    }

    T *newData = new T[size];
    memcpy(newData, data, std::min(size, capacity));

    delete[] data;
    data = newData;
  }

  inline T& getElement(size_t index) {
    return data[index-1];
  }

  void siftUp() {
    int index = size;
    while (getElement(index) > getElement(index / 2)) {
      std::swap(getElement(index), getElement(index / 2));
      index /= 2;
    }
  }

public:
  Heap() :
    capacity(8),
    size(0)
  {
    data = new T[size];
  }

  Heap(const Heap& other) :
    capacity(other.capacity),
    size(other.size)
  {
    data = new T[size];
    memcpy(data, other.data, size);
  }

  ~Heap() {
    delete[] data;
  }

  static Heap heapify(T *array, size_t size); // probably shouldn't be in class

  void insert(T value) {
    if (size == capacity) {
      resize(capacity * 2);
    }

    data[size++] = value;
    if (size > 1) {
      siftUp();
    }
  }

  T getMax() {
    return getElement(size);
  }

  size_t getSize() {
    return size;
  }

  bool isEmpty() {
    return size == 0;
  }

  T extractMax();
  void siftDown();
  void remove(size_t index);
  void heapSort(T *array, size_t size); // should work in place :};
};
