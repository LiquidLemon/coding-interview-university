#include "Node.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue {
  public:
    Queue();

    void enqueue(T item);
    T dequeue();
    bool empty();

  private:
    Node<T> *head;
    Node<T> *tail;
};

template class Queue<int>;
#endif
