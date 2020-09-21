#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exp.h"
#include "stack-list.h"
#include "stack-node.h"

exp createNullExp() {
  return (exp)NULL;
}

exp createExp(element_t x, exp l, exp r) {
  exp t = (exp)malloc(sizeof(struct ExpNode));
  t->data = x;
  t->left = l;
  t->right = r;
  return t;
}

exp createArg(element_t x) {
  return createExp(x, createNullExp(), createNullExp());
}

int isNullExp(exp t) {
  return (t == NULL);
}

int isArg(exp t) {
  return ((t != NULL) &&
	  (t->left == NULL) &&
	  (t->right == NULL)); 
}

int sizeOfExp(exp t) {
  if (isNullExp(t))
    return 0;
  else
    return (1 + sizeOfExp(t->left) + sizeOfExp(t->right));
}

int sumOfExp(exp t) {
  if (isNullExp(t))
    return 0;
  else
    return (t->data + sumOfExp(t->left) + sumOfExp(t->right));
}

//char* expToString(exp t) {
//  char *result;
//  char *left;
//  char *right;
//  if (isNullExp(t)) {
//    result = (char*)malloc(4);
//    strcpy(result, "Nil");
//    return result;
//  } else {
//    left = expToString(t->left);
//    right = expToString(t->right);
//    result = (char*)malloc(40 + strlen(left) + strlen(right));
//    sprintf(result, "node(%d,%s,%s)", value(t), left, right);
//    free(left);
//    free(right);
//    return result;
//  }
//}

char* expToString(exp e) {
  char *result;
  char *l;
  char *r;
  if (isNullExp(e)) {
    // Bieu thuc rong
    result = (char*)malloc(1);
    strcpy(result, "");
    return result;
  } else if (isArg(e)) {
    // Toan hang
    result = (char*)malloc(4);
    sprintf(result, "%d", value(e));
    return result;
  } else if (right(e) == NULL) {
    // Toan tu mot ngoi
    l = expToString(left(e));
    result = (char*)malloc(4 + strlen(l));
    sprintf(result, "%c%s", value(e), l);
  } else {
    // Toan tu hai ngoi
    l = expToString(left(e));
    r = expToString(right(e));
    result = (char*)malloc(4 + strlen(l) + strlen(r));
    sprintf(result, "%s %c %s", l, value(e), r);
    free(l);
    free(r);
    return result;
  }
}


int evaluate(exp e) {
  if (isNullExp(e)) return 0;
  if (!isArg(e)) {
    if (right(e) == NULL) {
      if (value(e) == '!') {
        int result = 1;
        for (int i =1; i<= evaluate(e->left); i++) {
          result *= i;
        }
        return result;
      } else {
        printf("Invalid\n");
        return 0;
      }
    }
    switch(value(e)) {
    case '+' : return evaluate(e->left) +evaluate(e->right); break;
    case '-' : return evaluate(e->left) - evaluate(e->right); break;
    case '*' : return evaluate(e->left) * evaluate(e->right); break;
    case '/' : return evaluate(e->left) / evaluate(e->right); break;
    default: return 0;
    }
  }
  if (isArg(e)) return (int)(value(e)-0);
}



exp left(exp t) {
  if (isNullExp(t))
    return NULL;
  else return t->left;
}

exp right(exp t) {
  if (isNullExp(t))
    return NULL;
  else return t->right;
}

element_t value(exp t) {
  if (isNullExp(t))
    return 0;
  else return t->data;
}

struct ExpNode* leftMost(exp t) {
  struct ExpNode *n = t;
  if (isNullExp(t)) return NULL;
  while (!isNullExp(left(n)))
    n = left(n);
  return n;
}

struct ExpNode* rightMost(exp t) {
  struct ExpNode *n = t;
  if (isNullExp(t)) return NULL;
  while (!isNullExp(right(n)))
    n = right(n);
  return n;
}

exp addToLeftMost(exp t, element_t x) {
  exp n = leftMost(t);
  if (isNullExp(t))
    return createArg(x);
  else {
    n->left = createArg(x);
    return t;
  }
}

exp addToRightMost(exp t, element_t x) {
  exp n = rightMost(t);
  if (isNullExp(t))
    return createArg(x);
  else {
    n->right = createArg(x);
    return t;
  }
}

int height(exp t) {
  if (isNullExp(t))
    return 0;
  int left = height(t->left);
  int right = height(t->right);
  if (left>=right)
    return left+1;
  else return right+1;
}


int leavesCount(exp t) {
  int count =0;
  if (isNullExp(t)) return 0;
  if (isArg(t)) return 1;
  int left = leavesCount(t->left);
  int right = leavesCount(t->right);
  return left +right;
}

int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
    return 1;
	else if (c == '(' || c == ')')
    return 0;
  else return -1;
}
int isOperand(char c) {
	return ((c >= '0') && ( c<= '9') );// || (c>= 'A' && c <= 'Z');
}


exp stringToExp(char* s) {
  stackN sN = create_stackN();
  stack sO = create_stack();
  exp t;
  exp t1,t2;
  for (int i = 0 ;s[i]; i++) {
    if (s[i] == '(') {
      sO = push(sO,s[i]);
    }
    else if (isOperand(s[i])) {
      t = createArg(s[i]);
      sN = pushN(sN,t);
    }
    else if (prec(s[i]) > 0) {
      while (!is_empty(sO) && top(sO)!= '('
             && ((s[i] != '^' && prec(top(sO)) >= prec(s[i])) )
             || (s[i] == '^' && prec(top(sO)) > prec(s[i]) ) ) {

        //get and remove the 2 top elements from the node stack
        t1 = topN(sN);
        sN = popN(sN);
        t2 = topN(sN);
        sN = popN(sN);

        //get and remove the top element from the operator stack
        t = createExp(top(sO), t2,t1);
        sO = pop(sO);

        sN = pushN(sN, t);
      }
      sO = push(sO,s[i]);
    }
    else if (s[i] == ')') {
      while (!is_empty(sO) && top(sO) != '(') {
        t1 = topN(sN);
        sN = popN(sN);
        t2 = topN(sN);
        sN = popN(sN);
        t = createExp(top(sO),t2,t1);
        sO = pop(sO);

        sN = pushN(sN,t);
      }
      sO = pop(sO);
    }
  }
  t= topN(sN);
  return t;
}
