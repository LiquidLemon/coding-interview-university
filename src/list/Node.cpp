#include "Node.hpp"

template <typename T>
Node<T>::Node() : next(nullptr) { }

template <typename T>
Node<T>::Node(T value) : next(nullptr), value(value) { }
