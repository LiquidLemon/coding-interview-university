#include "Vector.hpp"
#include <cstring>

template <typename T>
Vector<T>::Vector() {
  this->maxLength = 16;
  this->length = 0;
  this->items = new T[this->maxLength];
}

template<typename T>
size_t Vector<T>::size() {
  return this->length;
}

template<typename T>
size_t Vector<T>::capacity() {
  return this->maxLength;
}

template<typename T>
bool Vector<T>::is_empty() {
  return length == 0;
}

template<typename T>
T Vector<T>::at(size_t index) {
  return items[index];
}

template<typename T>
void Vector<T>::push(T item) {
  if (length == maxLength) {
    resize(length + 1);
  }
  items[length++] = item;
}

template<typename T>
void Vector<T>::insert(size_t index, T item) {
  if (length == maxLength) {
    resize(length + 1);
  }
  std::memcpy(items + index + 1, items + index, sizeof(T) * (length - index));
  items[index] = item;
  length++;
}

template<typename T>
void Vector<T>::prepend(T item) {
  if (length == maxLength) {
    resize(length + 1);
  }
  std::memcpy(items + 1, items, sizeof(T) * (length));
  items[0] = item;
  length++;
}

template<typename T>
T Vector<T>::pop() {
  T value = items[--length];
  return value;
}

template<typename T>
T Vector<T>::delete_at(size_t index) {
  T value = items[index];
  length--;
  std::memcpy(items + index, items + index + 1, sizeof(T) * (length - index));
  return value;
}

template<typename T>
int Vector<T>::remove(T value) {
  int count = 0;
  for (int i = length - 1; i >= 0; i--) {
    if (items[i] == value) {
      delete_at(i);
      count++;
    }
  }
  return count;
}

template<typename T>
int Vector<T>::find(T value) {
  for (int i = 0; i < length; i++) {
    if (items[i] == value) {
      return i;
    }
  }
  return -1;
}

template<typename T>
size_t Vector<T>::resize(size_t size) {
  size_t actualSize = 1;
  while (actualSize < size) {
    size <<= 1;
  }
  T *resized = new T[actualSize];
  std::memcpy(resized, items, length * sizeof(T));
  delete[] items;
  items = resized;
  maxLength = size;
}
