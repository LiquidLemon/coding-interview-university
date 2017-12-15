#include "Queue.hpp"
#include <exception>

class QueueEmptyException : public std::exception {
  virtual const char* what() const throw() {
    return "Empty queue";
  }
};

class QueueFullException : public std::exception {
  virtual const char* what() const throw() {
    return "Full queue";
  }
};

template <typename T>
Queue<T>::Queue(size_t size) {
  this->size = size;
  data = new T[size];
  start = data;
  end = data;
}

template <typename T>
void Queue<T>::enqueue(T item) {
  if (end == start - 1 || (end - data == size && start == data)) {
    throw QueueFullException();
  }
  *end = item;
  if (end < data + size) {
    end++;
  } else {
    end = data;
  }
}

template <typename T>
T Queue<T>::dequeue() {
  if (empty()) {
    throw QueueEmptyException();
  }
  T value = *start;
  if (start < data + size) {
    start++;
  } else {
    start = data;
  }
  return value;
}

template <typename T>
bool Queue<T>::empty() {
  return start == end;
}
