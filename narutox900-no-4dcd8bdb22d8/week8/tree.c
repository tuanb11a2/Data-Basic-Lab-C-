#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

tree createNullTree() {
  return (tree)NULL;
}

tree createTree(element_t x, tree l, tree r) {
  tree t = (tree)malloc(sizeof(struct TreeNode));
  t->data = x;
  t->left = l;
  t->right = r;
  return t;
}

tree createLeaf(element_t x) {
  return createTree(x, createNullTree(), createNullTree());
}

int isNullTree(tree t) {
  return (t == NULL);
}

int isLeaf(tree t) {
  return ((t != NULL) &&
	  (t->left == NULL) &&
	  (t->right == NULL)); 
}

int sizeOfTree(tree t) {
  if (isNullTree(t))
    return 0;
  else
    return (1 + sizeOfTree(t->left) + sizeOfTree(t->right));
}

int sumOfTree(tree t) {
  if (isNullTree(t))
    return 0;
  else
    return (t->data + sumOfTree(t->left) + sumOfTree(t->right));
}

char* treeToString(tree t) {
  char *result;
  char *left;
  char *right;
  if (isNullTree(t)) {
    result = (char*)malloc(4);
    strcpy(result, "Nil");
    return result;
  } else {
    left = treeToString(t->left);
    right = treeToString(t->right);
    result = (char*)malloc(40 + strlen(left) + strlen(right));
    sprintf(result, "node(%d,%s,%s)", t->data, left, right);
    free(left);
    free(right);
    return result;
  }
}

tree left(tree t) {
  if (isNullTree(t))
    return NULL;
  else return t->left;
}

tree right(tree t) {
  if (isNullTree(t))
    return NULL;
  else return t->right;
}

element_t value(tree t) {
  if (isNullTree(t))
    return 0;
  else return t->data;
}

struct TreeNode* leftMost(tree t) {
  struct TreeNode *n = t;
  if (isNullTree(t)) return NULL;
  while (!isNullTree(left(n)))
    n = left(n);
  return n;
}

struct TreeNode* rightMost(tree t) {
  struct TreeNode *n = t;
  if (isNullTree(t)) return NULL;
  while (!isNullTree(right(n)))
    n = right(n);
  return n;
}

tree addToLeftMost(tree t, element_t x) {
  tree n = leftMost(t);
  if (isNullTree(t))
    return createLeaf(x);
  else {
    n->left = createLeaf(x);
    return t;
  }
}

tree addToRightMost(tree t, element_t x) {
  tree n = rightMost(t);
  if (isNullTree(t))
    return createLeaf(x);
  else {
    n->right = createLeaf(x);
    return t;
  }
}

int height(tree t) {
  if (isNullTree(t))
    return 0;
  int left = height(t->left);
  int right = height(t->right);
  if (left>=right)
    return left+1;
  else return right+1;
}
int leavesCount(tree t) {
  int count =0;
  if (isNullTree(t)) return 0;
  if (isLeaf(t)) return 1;
  int left = leavesCount(t->left);
  int right = leavesCount(t->right);
  return left +right;


}
int innerNodeCount(tree t) {
  if(isNullTree(t)) return 0;
  if (isLeaf(t)) return 0;
  if (!isLeaf(t)) return (innerNodeCount(t->left) + innerNodeCount(t->right) +1);
}
int rightChildCount(tree t) {
  // TODO
}
