#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
  public:
    Node(T value);

    T value;
    Node<T> *next;
};

template class Node<int>;
#endif
