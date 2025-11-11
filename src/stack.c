#include "stack.h"

struct stack {
  int *data; //Puntero al array
  size_t size;
  size_t cap;
}

stack_t * stack_create(size_t initial_cap) {
  stack_t *s = (stack_t *) calloc(1, sizeof(*s));
  if (!s) 
    return NULL;

  s->data = (int *)malloc(initial_cap * sizeof(int));
  if (!s->data) {
    free(s);
    return NULL;
  }
  s->cap = initial_cap;
  return s;
}
