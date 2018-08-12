#include <stdlib.h>
#include <string.h>
#include "vector.h"

Vector *vector_new(size_t element_size, int (*compare)(void *, void *)) {
  Vector *vector = malloc(sizeof(Vector));

  vector->_size = 0;
  vector->_capacity = 16;
  vector->_items = malloc(sizeof(void *) * vector->_capacity);
  vector->element_size = element_size;
  vector->compare = compare;
  return vector;
}

size_t vector_size(Vector *vector) {
  return vector->_size;
}

size_t vector_capacity(Vector *vector) {
  return vector->_capacity;
}

bool vector_is_empty(Vector *vector) {
  return vector->_size == 0;
}

void *vector_at(Vector *vector, size_t index) {
  return vector->_items + index;
}

void vector_push(Vector *vector, void *item) {
  if (vector->_size == vector->_capacity) {
    _vector_resize(vector, vector->_capacity + 1);
  }
  void **ptr = vector->_items + (vector->_size++);
  *ptr = item;
}

void vector_insert(Vector *vector, size_t index, void *item) {
  if (vector->_size == vector->_capacity) {
    _vector_resize(vector, vector->_capacity + 1);
  }
  void **ptr = vector->_items + index;
  memcpy(ptr + 1, ptr, vector->_size - index);
  *ptr = item;
  vector->_size++;
}

void vector_prepend(Vector *vector, void *item) {
  if (vector->_size == vector->_capacity) {
    _vector_resize(vector, vector->_capacity + 1);
  }

  memcpy(vector->_items + 1, vector->_items, vector->_size);
  *vector->_items = item;
  vector->_size++;
}

void *vector_pop(Vector *vector) {
  void *item = vector->_items[--vector->_size];

  return item;
}

void *vector_delete_at(Vector *vector, size_t index) {
  void *item = vector->_items[index];

  void **ptr = vector->_items + index;
  memcpy(ptr, ptr + 1, --vector->_size);

  return item;
}

int vector_remove(Vector *vector, void *item) {
  int count = 0;
  for (int i = vector->_size - 1; i >= 0; i--) {
    if (vector->compare(vector->_items[i], item)) {
      vector_delete_at(vector, i);
      count++;
    }
  }

  return count;
}

int vector_find(Vector *vector, void *item) {
  for (int i = 0; i < vector->_size; i++) {
    if (vector->compare(vector->_items[i], item)) {
      return i;
    }
  }

  return -1;
}
