#include <string>

#ifndef NODE_HPP
#define NODE_HPP

template <typename K, typename V>
class KeyValue {
  public:
    KeyValue(K key, V value);

    K key;
    V value;
    KeyValue<K, V> *next;

};

template class KeyValue<std::string, int>;

#endif
