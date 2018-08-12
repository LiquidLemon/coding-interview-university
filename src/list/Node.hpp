#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
  public:

  Node();
  Node(T value);

  T value;
  Node *next;
};

template class Node<int>;
#endif
