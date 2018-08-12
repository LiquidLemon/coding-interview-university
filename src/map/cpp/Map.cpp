#include <stdexcept>
#include "Map.hpp"

template <typename T>
Map<T>::Map(size_t size) :
  size(size) {
  values = new KeyValue<std::string, T>*[size];
  for (int i = 0; i < size; i++) {
    values[i] = nullptr;
  }
}

template <typename T>
int Map<T>::hash(std::string key, size_t size) {
  int hash = 0;
  for (int i = 0; i < key.length(); i++) {
    hash = (hash * 31 + key[i]) % size;
  }
  return hash;
}

template <typename T>
bool Map<T>::add(std::string key, T value) {
  int hash = this->hash(key, size);
  KeyValue<std::string, T> *kv = values[hash];
  if (kv == nullptr) {
    values[hash] = new KeyValue<std::string, T>(key, value);
  } else {
    if (kv->key == key) {
      kv->value = value;
      return true;
    }
    // TODO: do { .. } while;
    while (kv->next != nullptr) {
      kv = kv->next;
      if (kv->key == key) {
        kv->value = value;
        return true;
      }
    }
    kv->next = new KeyValue<std::string, T>(key, value);
  }
  return false;
}

template <typename T>
bool Map<T>::exists(std::string key) {
  int hash = this->hash(key, size);
  KeyValue<std::string, T> *kv = values[hash];

  while (kv != nullptr) {
    if (kv->key == key) {
      return true;
    }
    kv = kv->next;
  }

  return false;
}

template <typename T>
T Map<T>::get(std::string key) {
  int hash = this->hash(key, size);
  KeyValue<std::string, T> *kv = values[hash];

  while (kv != nullptr) {
    if (kv->key == key) {
      return kv->value;
    }
    kv = kv->next;
  }

  throw std::runtime_error("Key not found");
}

template <typename T>
bool Map<T>::remove(std::string key) {
  int hash = this->hash(key, size);
  KeyValue<std::string, T> *kv = values[hash];
  if (kv->key == key) {
    delete kv;
    values[hash] = nullptr;
    return true;
  }

  auto prev = kv;
  auto current = kv->next;

  while (current != nullptr) {
    if (current->key == key) {
      prev->next = current->next;
      delete current;
      return true;
    }
    prev = current;
    current = current->next;
  }

  return false;
}
