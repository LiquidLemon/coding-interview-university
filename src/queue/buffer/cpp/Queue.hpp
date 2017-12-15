#include <cstddef>

#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue {
  public:
    Queue(size_t size);

    void enqueue(T item);
    T dequeue();
    bool empty();

  private:
    size_t size;
    T *end;
    T *data;
    T *start;
};

template class Queue<int>;
#endif
