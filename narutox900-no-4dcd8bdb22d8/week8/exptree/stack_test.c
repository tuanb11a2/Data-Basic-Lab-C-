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
  s = push (s, 'a');
  s = push (s, 'b');
  s = push (s, 'c');
  while (!is_empty(s)) {
	  printf("%c\n", top(s));
	  s = pop(s);
  }
  
  return 0;
}
