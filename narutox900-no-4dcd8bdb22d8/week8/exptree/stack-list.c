#include <stdio.h>
#include <stdlib.h>
#include "stack-list.h"

stack create_stack()
{
  stack s = (stack)malloc(sizeof(stack));
  s->next = NULL;
  return s;
}

int is_empty(stack s)
{
  return (s == NULL);
}

int is_full(stack s)
{
  return 0;
}

element_t top(stack s)
{
  if (!is_empty)
    return s->data;
  //else exit(0);
}

stack push(stack s, element_t x)
{
  if (is_empty(s))
    {
      stack new = create_stack();
      new->data = x;
      return new;
    }

  stack new = create_stack();
  new->data = x;
  new->next = s;

  return new;
}

stack pop(stack s)
{
  if (is_empty(s))
    {
      printf("Stack underflow!\n");
      exit(1);
    }

  stack tmp = s;
  s = s->next;
  tmp->next=NULL;
  //if (s != NULL)
  //printf("%d\n", tmp->data);
  free(tmp);

  return s;
}

void free_stack(stack s)
{
  do
    {
      s = pop(s);
    } while (s != NULL);
  //free(s);
}
