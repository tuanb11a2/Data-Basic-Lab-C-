#ifndef _STACK_NODE_H_
#define _STACK_NODE_H_
#include "exp.h"
typedef exp element_n;

struct NodeN {
  element_n data;
  struct NodeN *next;
};

typedef struct NodeN* stackN;

// create new empty stackN
stackN create_stackN();

int is_emptyN(stackN s);

int is_fullN(stackN s);

element_n topN(stackN s);

stackN pushN(stackN s, element_n x);

stackN popN(stackN s);

void free_stackN(stackN s);
#endif
