#include <stddef.h>
#include <stdbool.h>

typedef struct Vector {
  size_t _capacity;
  size_t _size;
  void **_items;
  size_t element_size;
  int (*compare)(void *, void *);
} Vector;

size_t _vector_resize(Vector *vector, size_t size);

Vector *vector_new(size_t element_size, int (*compare)(void *, void *));
size_t vector_size(Vector *vector);
size_t vector_capacity(Vector *vector);
bool vector_is_empty(Vector *vector);
void *vector_at(Vector *vector, size_t index);
void vector_push(Vector *vector, void *item);
void vector_insert(Vector *vector, size_t index, void *item);
void vector_prepend(Vector *vector, void *item);
void *vector_pop(Vector *vector);
void *vector_delete_at(Vector *vector, size_t index);
int vector_remove(Vector *vector, void *item);
int vector_find(Vector *vector, void *item);
