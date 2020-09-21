#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack-array.h"

char *reverse(char *str) {
  char *p1, *p2;
  if (!str || !*str)
    return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
      *p1 ^= *p2;
      *p2 ^= *p1;
      *p1 ^= *p2;
    }
  return str;
}

stack convert(char *str) {
  str = reverse(str);
  stack s = create_stack();
  int x = atoi(str);
  while (x > 0) {
    int num = x%10;
    s = push(s,num);
    x=x/10;
  }
  return s;
}

stack addStack(stack s1, stack s2) {
  stack s = create_stack();
  int sum = 0, sur = 0; 
  while ((!is_empty(s1)) || (!is_empty(s2)) ) {
      if (!is_empty(s1)) {
        sum += top(s1);
        pop(s1);
      }
      if (!is_empty(s2)) {
        sum += top(s2);
        pop(s2);
      }
      sum += sur;
      sur = 0;
      if (sum >= 10) {
        sum -= 10;
        sur +=1;
      }
      push(s,sum);
      sum = 0;
    }
  if (sur != 0 ) push(s,sur); 
  return s;
}

int main(int argc, char* argv[]) {
  int result, err;
  
  if (argc != 3) {
    printf("Syntax error|\nUsage: evaluate [exp]\n");
    exit(0);
  }
  stack s1,s2,s;
  s1 = convert(argv[1]);
  s2 = convert(argv[2]);
  s = addStack(s1,s2);
  printf("\n");
  while (!is_empty(s)) {
    printf("%d",top(s));
    pop(s);
  }
  printf("\n"); 

}
