#include "stack.h"

#include <stdlib.h>
struct stack {
  int *data; //Puntero al array
  size_t size;
  size_t cap;
};

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

int stack_push(stack_t * s, int value) {
  if (!s) return -1; //Pointer guards!
  if (s->size == s->cap) return -1;

  s->data[s->size++] = value;
  return 0;
}

void stack_destroy(stack_t* s)
{
  if (!s)
    return;
}

int stack_pop(stack_t* s, int* out){
  if (!s || !out)
    return -1;
  return 0;
}

int stack_top(const stack_t* s, int* out){
  if (!s || !out)
    return -1;
  return 0;
}

size_t stack_size(const stack_t* s){
  if (!s)
    return -1;
  return 0;
}

bool stack_is_empty(const stack_t* s){
  if (!s)
    return false;
  return true;
}

void stack_print(const stack_t* s) {
  if (!s)
    return;
}
