#ifndef _EXP_H_
#define _EXP_H_

typedef char element_t;

struct ExpNode {
  element_t data;
  struct ExpNode *left;
  struct ExpNode *right;
};

typedef struct ExpNode* exp;

exp createNullExp();
exp createArg(element_t x);
exp createExp(element_t x, exp l, exp r);

exp left(exp t);
exp right(exp t);
element_t value(exp t);


int isNullexp(exp t);
int isArg(exp t);

int sizeOfexp(exp t);
int sumOfexp(exp t);
char* expToString(exp t);
exp stringToExp(char* s);

struct ExpNode* leftMost(exp t);
struct ExpNode* rightMost(exp t);

exp addToLeftMost(exp t, element_t x);
exp addToRightMost(exp t, element_t x); 

int height(exp t);
int leavesCount(exp t);
int innerNodeCount(exp t);
int rightChildCount(exp t);

int evaluate(exp e);

#endif
