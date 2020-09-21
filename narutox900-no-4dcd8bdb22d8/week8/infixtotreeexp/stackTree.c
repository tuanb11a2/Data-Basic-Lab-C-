#include <stdio.h>
#include <stdlib.h>
#include "stackTree.h"

stackTree create_stack_t(stackTree s)
{
    s = (stackTree)malloc(sizeof(struct Node_t));
    return s;
}

int is_empty_t(stackTree s)
{
    return s == NULL;
}

int is_full_t(stackTree s)
{
    return 0;
}

element top_t(stackTree s)
{
    return s->data;
}

stackTree push_t(stackTree s, element x)
{
    if (is_empty_t(s))
    {
        stackTree new = create_stack_t(s);
        new->data = x;
        new->next = NULL;
        return new;
    }

    stackTree new = create_stack_t(s);
    new->data = x;
    new->next = s;

    return new;
}

stackTree pop_t(stackTree s)
{
    if (is_empty_t(s))
    {
        return NULL;
    }

    stackTree tmp = s;
    s = s->next;
    free(tmp);

    return s;
}

void free_stack_t(stackTree s)
{
    do
    {
        s = pop_t(s);
    } while (s != NULL);
    free(s);
}