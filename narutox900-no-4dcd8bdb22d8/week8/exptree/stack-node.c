#include <stdio.h>
#include <stdlib.h>
#include "stack-node.h"
#include "exp.h"

stackN create_stackN()
{
  stackN s = (stackN)malloc(sizeof(stackN));
  s->next = NULL;
  return s;
}

int is_emptyN(stackN s)
{
  return (s == NULL);
}

int is_fullN(stackN s)
{
  return 0;
}

element_n topN(stackN s)
{
  if (!is_emptyN)
    return s->data;
  else
    printf("you got bug");
  // exit(0);
}

stackN pushN(stackN s, element_n x)
{
  if (is_emptyN(s))
    {
      stackN new = create_stackN();
      new->data = x;
      return new;
    }

  stackN new = create_stackN();
  new->data = x;
  new->next = s;

  return new;
}

stackN popN(stackN s)
{
  if (is_emptyN(s))
    {
      printf("StackN underflow!\n");
      exit(1);
    }

  stackN tmp = s;
  s = s->next;
  tmp->next=NULL;
  //if (s != NULL)
  //printf("%d\n", tmp->data);
  free(tmp);

  return s;
}

void free_stackN(stackN s)
{
  do
    {
      s = popN(s);
    } while (s != NULL);
  //free(s);
}
