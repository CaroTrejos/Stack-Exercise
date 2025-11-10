#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
  stack_t* s = stack_create(0);
  if (!s){ fprintf(stderr, "error: sin memoria\n"); return 1; }

  char line[128];
  int x;

  puts("Menu:");
  puts(" 1) push <n>");
  puts(" 2) pop");
  puts(" 3) top");
  puts(" 4) size");
  puts(" 5) print");
  puts(" 0) quit");

  for(;;){
    printf("> ");
    if (!fgets(line, sizeof(line), stdin)) break;

    /* push <n> */
    if (sscanf(line, "1 %d", &x) == 1 || sscanf(line, "push %d", &x) == 1){
      if (stack_push(s, x) != 0) puts("error: OOM");
      continue;
    }

    /* pop */
    if (line[0]=='2' || line[0]=='p'){
      int v;
      if (stack_pop(s, &v) != 0) puts("(empty)"); else printf("%d\n", v);
      continue;
    }

    /* top */
    if (line[0]=='3' || line[0]=='t'){
      int v;
      if (stack_top(s, &v) != 0) puts("(empty)"); else printf("%d\n", v);
      continue;
    }

    /* size */
    if (line[0]=='4' || line[0]=='s'){
      printf("%zu\n", stack_size(s));
      continue;
    }

    /* print */
    if (line[0]=='5'){
      stack_print(s);
      continue;
    }

    /* quit */
    if (line[0]=='0' || line[0]=='q'){
      break;
    }

    puts("comandos: '1 n' (push), '2' (pop), '3' (top), '4' (size), '5' (print), '0' (quit)");
  }

  stack_destroy(s);
  return 0;
}

