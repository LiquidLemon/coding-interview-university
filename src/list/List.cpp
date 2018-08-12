#include "List.hpp"

template <typename T>
List<T>::List() : head(nullptr) { }

template <typename T>
bool List<T>::empty() {
  return head == nullptr;
}

template <typename T>
size_t List<T>::size() {
  size_t size = 0;
  Node<T> *node = head;
  while (node != nullptr) {
    size++;
    node = node->next;
  }
  return size;
}

template <typename T>
void List<T>::pushFront(T value) {
  Node<T> *newHead = new Node<T>(value);
  newHead->next = head;
  head = newHead;
}

template <typename T>
T List<T>::popFront() {
  if (head != nullptr) {
    T value = head->value;
    Node<T> *oldHead = head;
    head = head->next;
    delete oldHead;
    return value;
  }
}

template <typename T>
void List<T>::pushBack(T value) {
}
