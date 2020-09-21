#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exp.h"

int main() {
  exp tmp;
  exp e = createExp('-',
            createExp('+',
		      createArg(1),
		      createExp('*',
				 createArg(2),
				 createArg(3))),createArg(4));
  char *s;
  s = expToString(e);
  printf("%s\n", s);
  free(s);

  printf("value of exp:%d\n",evaluate(e));

  

  return 0;
}
