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

struct TreeNode* minBST(tree t) {
  struct TreeNode *n = t;
  
  if (isNullTree(t)) return NULL;
  while (!isNullTree(left(n)))
    n = left(n);
  return n;
}

struct TreeNode* maxBST(tree t) {
  struct TreeNode *n = t;
  
  if (isNullTree(t)) return NULL;
  while (!isNullTree(right(n)))
    n = right(n);
  return n;
}

// tree addToLeftMost(tree t, element_t x) {
//   tree n = leftMost(t);
  
//   if (isNullTree(t))
//     return createLeaf(x);
//   else {
//     n->left = createLeaf(x);
//     return t;
//   }
// }

// tree addToRightMost(tree t, element_t x) {
//   tree n = rightMost(t);
  
//   if (isNullTree(t))
//     return createLeaf(x);
//   else {
//     n->right = createLeaf(x);
//     return t;
//   }
// }

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
  if (t == NULL)
    return 0;
  int count = 0;
  if (t->right != NULL)
    count = 1;
  return (count + rightChildCount(t->left) + rightChildCount(t->right));
}

struct TreeNode *searchBST(tree t, element_t x) {
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

tree reverseBST(tree t) {
  if (t == NULL) return t;
  if (isLeaf(t)) return t;
  tree tmp;
  tmp = t->right;
  t->right = t->left;
  t->left= tmp;
  //free(tmp); 
  t->left = reverseBST(t->left);
  t->right = reverseBST(t->right);
  return t;
}

void inorderTravel(tree t){
  if (t == NULL) {
    //printf("Nil ");
    return;
  }
  if (isLeaf(t)) {
    printf("%d ",value(t));
    return;
  }
  inorderTravel(t->left);
  printf("%d ",value(t));
  inorderTravel(t->right);
}