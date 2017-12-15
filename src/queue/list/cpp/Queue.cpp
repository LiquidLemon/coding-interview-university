#include "Queue.hpp"

template <typename T>
Queue<T>::Queue() {
  head = nullptr;
  tail = nullptr;
}

template <typename T>
void Queue<T>::enqueue(T item) {
  if (empty()) {
    tail = head = new Node<T>(item);
  } else {
    auto node = new Node<T>(item);
    tail->next = node;
    tail = node;
  }
}

template <typename T>
T Queue<T>::dequeue() {
  T value = head->value;
  Node<T> *next = head->next;
  delete head;
  head = next;

  return value;
}

template <typename T>
bool Queue<T>::empty() {
  return head == nullptr;
}
