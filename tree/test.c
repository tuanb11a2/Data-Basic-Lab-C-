#include <stdio.h>
#include "tree.h"

int main() {
  tree tmp;
  tree t = createLeaf(3);
  t = insertBST(t,2);
	t =	insertBST(t,1);   
	t = insertBST(t,4);
  t = insertBST(t,5); 
  char *s;
  printf("size = %d\n", sizeOfTree(t));
  printf("sum = %d\n", sumOfTree(t));
  s = treeToString(t);
  printf("%s\n", s);

  printf("left most:%d\n", value(leftMost(t)));
  printf("right most:%d\n", value(rightMost(t)));

  t = insertBST(t,10);
  t = insertBST(t,100);
  t = insertBST(t,7);
  printf("size = %d\n", sizeOfTree(t));
  printf("sum = %d\n", sumOfTree(t));
  s = treeToString(t);
  printf("%s\n", s);

  tmp = t;
  printf("Height:%d\n",height(t));
  t = tmp;

  tmp = t;
  printf("Leaves count:%d\n",leavesCount(t));
  t = tmp;

  insertBST(t,10);
  printf("size = %d\n", sizeOfTree(t));
  printf("sum = %d\n", sumOfTree(t));
  s = treeToString(t);
  printf("%s\n", s);


  t = removeBST(t,100);
  printf("size = %d\n", sizeOfTree(t));
  printf("sum = %d\n", sumOfTree(t));
  s = treeToString(t);
  printf("%s\n", s);

  printf("Min:%d\n",value(leftMost(t)));
  printf("Max:%d\n",value(rightMost(t)));

  t = reverse_tree(t);
  s = treeToString(t);
  printf("%s\n", s);
  inorderPrint(t);
  printf("\n");



  return 0;
}
