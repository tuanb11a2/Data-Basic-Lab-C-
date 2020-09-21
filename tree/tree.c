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

tree left(tree t){
  if(isNullTree(t)){
    return NULL;
  }else{
    return t->left;
  }
};

tree right(tree t){
  if(isNullTree(t)){
    return NULL;
  }else{
    return t->right;
  }
};

element_t value(tree t){
  if(isNullTree(t)){
    return 0;
  }else{
    return t->data;
  }
};


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

struct TreeNode* leftMost(tree t){
  struct TreeNode* tmp;
  tmp = t;
  if(isNullTree(t)){
    return NULL;
  }else{
    while(tmp->left != NULL){
      tmp = tmp->left;
    }
    return tmp;
  }
};

struct TreeNode* rightMost(tree t){
  struct TreeNode* tmp;
  tmp = t;
  if(isNullTree(t)){
    return NULL;
  }else{
    while(right(tmp) != NULL){
      tmp = tmp->right;
    }
    return tmp;
  }
};

tree addToLeftMost(tree t, element_t x){
  struct TreeNode* tmp;
  struct TreeNode* new;
  new = createLeaf(x);
  tmp = leftMost(t);
  tmp->left = new;
  return t;

};
tree addToRightMost(tree t, element_t x){
  struct TreeNode* tmp;
  struct TreeNode* new;
  new = createLeaf(x);
  tmp = rightMost(t);
  tmp->right = new;
  return t;
};

int height(tree t){
  if(isNullTree(t)){
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

int leavesCount(tree t){
  int count = 0;
  if(isNullTree(t)){
    return 0;
  }
  if(isLeaf(t)){
    return 1;
  }
  int leavesCountLeft = leavesCount(t->left);
  int leavesCountRight = leavesCount(t->right);

  return leavesCountLeft + leavesCountRight;
  };

tree searchBST(tree t, element_t x) {
  if (isNullTree(t))
    return NULL;
  
  if (value(t) == x)
    return t;
  else if (value(t) < x)
    return searchBST(right(t),x);
  else
    return searchBST(left(t),x);
}

tree insertBST(tree t, element_t x) {
  if (isNullTree(t))
    return createLeaf(x);

  if (value(t) == x)
    return t;
  else if (value(t) > x) {
    t->left = insertBST(t->left, x);
    return t;
  } else {
    t->right = insertBST(t->right, x);
    return t;
  }
}

//Xoa node
tree removeBST(tree t, element_t x) {
  tree p, tmp;
  
  if (isNullTree(t))
    return NULL;

  if (t->data == x)
    return removeRootBST(t);

  p = NULL;
  tmp = t;
  while ((tmp != NULL) && (tmp->data != x)) 
    if (tmp->data > x) {
      p = tmp;
      tmp = tmp->left;
    } else {
      p = tmp;
      tmp = tmp->right;
    }

  if (tmp != NULL) {
    if (p->left == tmp) {
      p->left = removeRootBST(tmp);
    }
    else {
      p->right = removeRootBST(tmp);
    }
  }
  return t;
}

// xoa nut goc va tra ve cay BST sau khi da xoa
tree removeRootBST(tree t) {
  tree p, tmp;
  
  if (isNullTree(t))
    return NULL;
  // Xoa nut la
  if (isLeaf(t)) {
    free(t);
    return NULL;
  }
  // Xoa nut co 1 con phai
  if (left(t) == NULL) {
    tmp = right(t);
    free(t);
    return tmp;
  }
  // Xoa nut co 1 con trai
  if (right(t) == NULL) {
    tmp = left(t);
    free(t);
    return tmp;
  }
  // Xoa nut co hai con
  p = t;
  tmp = right(t);
  while (left(tmp) != NULL) {
    p = tmp;
    tmp = left(tmp);
  }

  t->data = tmp->data;
  tmp = removeRootBST(tmp);
  if (p == t)
    p->right = tmp;
  else
    p->left = tmp;
  return t;
}

//Reverse tree 
tree reverse_tree(tree t){
  tree tmp;
  if(isNullTree(t)){
    return NULL;
  }

  if(isLeaf(t)){
    return t;
  }

  tmp = t->left;
  t->left = t->right;
  t->right = tmp;

  t->left = reverse_tree(t->left);
  t->right = reverse_tree(t->right);
  return t;
}

void inorderPrint(tree t){
  tree tmp;
  if(!isNullTree(t)){
    if(isLeaf(t)){
      printf("%d-",t->data);
    }else{
    inorderPrint(t->left);
    printf("%d-",value(t));
    inorderPrint(t->right);
    }
  }
  
  

};

void postorderPrint(tree t){

};

void prefixorderPrint(tree t){

};

int innerNodeCount(tree t){

};

int rightChildCount(tree t){

};

 