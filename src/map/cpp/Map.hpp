#include <string>
#include <cstddef>
#include "KeyValue.hpp"

#ifndef MAP_HPP
#define MAP_HPP

template <typename T>
class Map {
  public:
    Map(size_t size);
    int hash(std::string key, size_t size);
    bool add(std::string key, T value);
    bool exists(std::string key);
    T get(std::string key);
    bool remove(std::string key);

  private:
    KeyValue<std::string, T> **values;
    size_t size;
};

template class Map<int>;
#endif
