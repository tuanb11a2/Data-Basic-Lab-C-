#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
  int a[] = {3,6,2,7,4};
  int i, n = 5;
  tree t = createNullTree();

  for (i = 0; i < n; i++)
    t = insertBST(t, a[i]);

  printf("Min: %d Max: %d\n",value(minBST(t)),value(maxBST(t)));

  char *s;
  s = treeToString(t);
  printf("%s\n", s);
  free(s);

  // t = removeBST(t, 4);
  // s = treeToString(t);
  // printf("%s\n", s);
  // free(s);

  t = removeBST(t, 6);
  s = treeToString(t);
  printf("%s\n", s);
  free(s);

  // t = removeBST(t, 3);
  // s = treeToString(t);
  // printf("%s\n", s);
  // free(s);

  t= reverseBST(t);
  s = treeToString(t);
  printf("%s\n", s);
  free(s);
  
  inorderTravel(t);



  printf("Height:%d\n", height(t));
  printf("Leaves count:%d\n", leavesCount(t));
  printf("Inner node count:%d\n", innerNodeCount(t));
  printf("Right children count:%d\n", rightChildCount(t));
  return 0;
}
