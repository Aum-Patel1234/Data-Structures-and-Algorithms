#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"

#define INITIAL_CAPACITY 5
typedef struct {
  void* data;
  size_t size;
  size_t capacity;
  size_t elem_size;
} Vec;

// sizeof(ptr) * no. of units
static inline void vec_init_data(Vec* vec) { vec->data = malloc(vec->capacity * vec->elem_size); }
static inline Vec vec_init(size_t elem_size) {
  Vec vec = (Vec){.data = NULL, .size = 0, .capacity = INITIAL_CAPACITY, .elem_size = elem_size};
  vec_init_data(&vec);
  return vec;
}

static inline void vec_expand(Vec* vec) {
  vec->capacity <<= 1;
  vec->data = realloc(vec->data, vec->capacity * vec->elem_size);
}

static inline void vec_add_element(Vec* vec, void* element) {
  if (vec->size == vec->capacity) vec_expand(vec);

  void* dest = (char*)vec->data + (vec->size * vec->elem_size);
  memcpy(dest, element, vec->elem_size);
  vec->size++;
}

static inline void vec_free(Vec* vec) {
  free(vec->data);
  vec->data = NULL;
  vec->size = 0;
  vec->capacity = 0;
}
