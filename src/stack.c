#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack {
  int *data; //Puntero al array [,,,,]
  size_t size;
  size_t cap; //Capacidad maxima del array 0-50
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
  free (s -> data);
  free (s);
  s = NULL;
}

int stack_pop(stack_t* s, int* out){
  
  if (!s || s->size == 0) // si la pila no existia o si estaba vacia
    return -1;

  if (!out)
    s->size -= 1;
    return 0;
  else
    *out = s->data[s->size - 1];
  return 0;
}

void stack_top(const stack_t* s, int* out){
  if (!s || !out)
    return;
  return;
}

size_t stack_size(const stack_t* s){
  if (!s)
    return -1;
  return 0;
}

bool stack_is_empty(const stack_t* s){
  if (!s) // null o 0 
    return true;
  return false;
}

void stack_print(const stack_t* s) {
  if (!s)
    return;
  for (int i = 0; i < s -> size; i++) {
    printf ("%d\n", s -> (data + i));
  }
}
