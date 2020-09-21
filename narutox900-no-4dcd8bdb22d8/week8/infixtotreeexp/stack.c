#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack create_stack(stack s)
{
    s = (stack)malloc(sizeof(struct Node));
    return s;
}

int is_empty(stack s)
{
    return s == NULL;
}

int is_full(stack s)
{
    return 0;
}

element_t top(stack s)
{
    return s->data;
}

stack push(stack s, element_t x)
{
    if (is_empty(s))
    {
        stack new = create_stack(s);
        new->data = x;
        new->next = NULL;
        return new;
    }

    stack new = create_stack(s);
    new->data = x;
    new->next = s;

    return new;
}

stack pop(stack s)
{
    if (is_empty(s))
    {
        return NULL;
    }

    stack tmp = s;
    s = s->next;
    free(tmp);

    return s;
}

void free_stack(stack s)
{
    do
    {
        s = pop(s);
    } while (s != NULL);
    free(s);
}