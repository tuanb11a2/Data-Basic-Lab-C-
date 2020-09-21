#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exp.h"

exp createNullexp() {
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
  return createExp(x, createNullexp(), createNullexp());
}

exp left(exp t){
  if(isNullexp(t)){
    return NULL;
  }else{
    return t->left;
  }
};

exp right(exp t){
  if(isNullexp(t)){
    return NULL;
  }else{
    return t->right;
  }
};

element_t value(exp t){
  if(isNullexp(t)){
    return 0;
  }else{
    return t->data;
  }
};


int isNullexp(exp t) {
  return (t == NULL);
}

int isArg(exp t) {
  return ((t != NULL) &&
	  (t->left == NULL) &&
	  (t->right == NULL)); 
}

int sizeOfexp(exp t) {
  if (isNullexp(t))
    return 0;
  else
    return (1 + sizeOfexp(t->left) + sizeOfexp(t->right));
}

int sumOfexp(exp t) {
  if (isNullexp(t))
    return 0;
  else
    return (t->data + sumOfexp(t->left) + sumOfexp(t->right));
}

char* expToString(exp t) {
  char *result;
  char *left;
  char *right;
  
  if (isNullexp(t)) {
    result = (char*)malloc(4);
    strcpy(result, "Nil");
    return result;
  } else {
    left = expToString(t->left);
    right = expToString(t->right);
    
    result = (char*)malloc(40 + strlen(left) + strlen(right));
    sprintf(result, "node(%d, %s, %s)", t->data, left, right);
    free(left);
    free(right);
    return result;
  }
}

struct ExpNode* leftMost(exp t){
  struct ExpNode* tmp;
  tmp = t;
  if(isNullexp(t)){
    return NULL;
  }else{
    while(tmp->left != NULL){
      tmp = tmp->left;
    }
    return tmp;
  }
};

struct ExpNode* rightMost(exp t){
  struct ExpNode* tmp;
  tmp = t;
  if(isNullexp(t)){
    return NULL;
  }else{
    while(right(tmp) != NULL){
      tmp = tmp->right;
    }
    return tmp;
  }
};

exp addToLeftMost(exp t, element_t x){
  struct ExpNode* tmp;
  struct ExpNode* new;
  new = createArg(x);
  tmp = leftMost(t);
  tmp->left = new;
  return t;

};
exp addToRightMost(exp t, element_t x){
  struct ExpNode* tmp;
  struct ExpNode* new;
  new = createArg(x);
  tmp = rightMost(t);
  tmp->right = new;
  return t;
};

int height(exp t){
  if(isNullexp(t)){
    return 0;
  }else{
    int leftDepth = height(t->left);
    int rightDepth = height(t->right);

    if(leftDepth > rightDepth){
      return leftDepth + 1;
    }else{
      return rightDepth + 1;
    }
  }
};

int leavesCount(exp t){
  int count = 0;
  if(isNullexp(t)){
    return 0;
  }
  if(isArg(t)){
    return 1;
  }
  int leavesCountLeft = leavesCount(t->left);
  int leavesCountRight = leavesCount(t->right);

  return leavesCountLeft + leavesCountRight;
  };

int evaluate(exp e){
    exp tmp;
    tmp = e;
    if(isArg(tmp)){
         return (int)(tmp->data - 0);
    }
    if(isNullexp(tmp)){
        return 0;
    }else{
    switch (tmp->data)
    {
    case '+':
        return  evaluate(tmp->left) + evaluate(tmp->right);
        break;
    case '-':
        return  evaluate(tmp->left) - evaluate(tmp->right);;
        break;
    case '*':
        return  evaluate(tmp->left) * evaluate(tmp->right);
        break ;
    case '/':
        return  evaluate(tmp->left) / evaluate(tmp->right);
        break;
    default:
        break;
    }
    }
}

int innerNodeCount(exp t){

};

int rightChildCount(exp t){

};

 