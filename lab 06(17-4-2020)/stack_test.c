#include <stdio.h>
#include "stack-list.h"

int main() {

  stack s = create_stack();

  s = push(s, 1);
  s = push(s, 2);
  s = push(s, 3);

  while (!is_empty(s)) {
    printf("%d\n", top(s));
    s = pop(s);
  }

  if(is_full(s) == 0){
    printf("Not full!\n");
  }
  
  free_stack(s);

  return 0;
}
