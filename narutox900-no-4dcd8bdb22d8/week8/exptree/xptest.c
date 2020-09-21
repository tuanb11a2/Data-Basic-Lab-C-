#include <stdio.h>
#include <stdlib.h>
#include "exp.h"

int main() {
  exp e = createExp('-',
		    createExp('+',
			      createArg(1),
			      createExp('*', createArg(2), createArg(3))),
		    createArg(4));
  char *s;
  s = expToString(e);
  printf("%s\n", s);
  free(s);

  printf("value of exp:%d\n", evaluate(e));


  printf("\n\nTurn expression into tree:\n");
  char ex[10]="(1+2+3+4)";
  printf("%s",ex);
  exp t;
  t = stringToExp(ex);
  s = expToString(t);
  printf("%s\n", s);
  printf("Value of exp: %d\n", evaluate(t));

  return 0;
}
