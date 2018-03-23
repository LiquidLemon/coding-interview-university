#pragma once
#include <cstddef>
#include <algorithm>
#include <cstring>
#include <stdexcept>

template <typename T>
class Heap {
  private:
    T *data;
    std::size_t capacity;
    std::size_t size;

    void resize(std::size_t size) {
      // no-op
      if (size == capacity) {
        return;
      }

      T *newData = new T[size];
      memcpy(newData, data, std::min(size, capacity));

      delete[] data;
      data = newData;
    }

    inline T& item(std::size_t index) {
      return data[index-1];
    }

    void siftUp(std::size_t index) {
      while (index > 1 && item(index) > item(index / 2)) {
        std::swap(item(index), item(index / 2));
        index /= 2;
      }
    }

    void siftDown(std::size_t index = 1) {
      while (index * 2 <= size && item(index * 2) > item(index)) {
        if (index * 2 <= size && item(index * 2 + 1) > item(index * 2)) {
          std::swap(item(index), item(index * 2 + 1));
          index = index * 2 + 1;
        } else {
          std::swap(item(index), item(index * 2));
          index *= 2;
        }
      }
    }

    /*
     * Frees up data for use outside of the Heap
     */
    void empty() {
      data = nullptr;
      size = 0;
      capacity = 0;
    }

  public:
    Heap(std::size_t capacity) :
      capacity(capacity),
      size(0)
    {
      data = new T[capacity];
    }

    Heap() : Heap(8) { }

    Heap(const Heap& other) :
      capacity(other.capacity),
      size(other.size)
    {
      data = new T[size];
      memcpy(data, other.data, size);
    }

    // copy-swap?
    Heap& operator=(const Heap& other) {
      Heap tmp = other;
      std::swap(data, tmp.data);
      std::swap(size, tmp.size);
      std::swap(capacity, tmp.capacity);

      return *this;
    }

    Heap(Heap&& other) {
      data = other.data;
      capacity = other.capacity;
      size = other.size;

      other.data = nullptr;
      other.capacity = 0;
      other.size = 0;
    }

    Heap& operator=(Heap&& other) {
      Heap tmp = std::move(other);

      std::swap(data, tmp.data);
      std::swap(capacity, tmp.capacity);
      std::swap(size, tmp.size);

      return *this;
    }

    ~Heap() {
      if (data != nullptr) {
        delete[] data;
      }
    }

    /*
     * Creates a Heap using the array for data storage.
     * The array will be managed by the Heap
     */
    Heap(T *data, std::size_t size) {
      capacity = size;
      this->size = size;
      this->data = data;

      for (std::size_t i = size; i > 0; i--) {
        siftUp(i);
      }
    }

    void insert(T value) {
      if (size == capacity) {
        resize(capacity * 2);
      }

      data[size] = value;
      size++;
      if (size > 1) {
        siftUp(size);
      }
    }

    T getMax() {
      if (size == 0) {
        throw std::length_error("Heap is empty");
      }
      return data[0];
    }

    std::size_t getSize() {
      return size;
    }

    bool isEmpty() {
      return size == 0;
    }

    T extractMax() {
      if (size == 0) {
        throw std::length_error("Heap is empty");
      }

      T value = std::move(data[0]);
      data[0] = std::move(data[size-1]);
      size--;

      if (size > 1) {
        siftDown();
      }
      return value;
    }

    void remove(std::size_t index) {
      item(index) = item(size);
      size--;
      siftDown(index);
    }

    /*
     * Sorts the internal array and frees it from the Heap
     */
    T* heapSort() {
      while (size != 0) {
        T value = extractMax();
        data[size] = std::move(value);
      }

      T *array = data;
      empty();

      return array;
    }
};
