#ifndef _TREE_H_
#define _TREE_H_

typedef int element_t;

struct TreeNode {
  element_t data;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode* tree;

tree createNullTree();
tree createLeaf(element_t x);
tree createTree(element_t x, tree l, tree r);

int isNullTree(tree t);
int isLeaf(tree t);

tree left(tree t);
tree right(tree t);
element_t value(tree t);

int sizeOfTree(tree t);
int sumOfTree(tree t);
char* treeToString(tree t);

struct TreeNode* leftMost(tree t);
struct TreeNode* rightMost(tree t);

int height(tree t);
int leavesCount(tree t);
int innerNodeCount(tree t);
int rightChildCount(tree t);

tree addToLeftMost(tree t, element_t x);
tree addToRightMost(tree t, element_t x); 

#endif
