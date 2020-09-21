#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree t;

void find(){
  char email[25];
  printf("Enter email you want to find: ");
  scanf(" %s",email);
  struct TreeNode *node = searchBST(t,email);
  if (node != NULL) {
    printf("Email found!");
    FILE *fout = fopen("emailout.txt","w+");
    fprintf(fout,"%s",node->data.email);
  } else
    printf("Email not found!");
}

int main() {
  t = createNullTree();
  t = readData(t,"address.txt");
  printf("\n\n\n");
  inorderTravel(t);
  printf("\n");
  find();
  return 0;
}

