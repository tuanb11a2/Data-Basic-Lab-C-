#include "exp.h"

#ifndef _STACK_TREE_LIST_H_
#define _STACK__TREE_LIST_H_

typedef exp element;

struct Node_t
{
    element data;
    struct Node_t *next;
};

typedef struct Node_t *stackTree;

// create new empty stack
stackTree create_stack_t(stackTree s);

int is_empty_t(stackTree s);

int is_full_t(stackTree s);

element top_t(stackTree s);

stackTree push_t(stackTree s, element x);

stackTree pop_t(stackTree s);

void free_stack_t(stackTree s);
#endif
