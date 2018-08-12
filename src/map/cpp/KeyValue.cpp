#include "KeyValue.hpp"

template <typename K, typename V>
KeyValue<K, V>::KeyValue(K key, V value) :
  key(key),
  value(value),
  next(nullptr) {

}
