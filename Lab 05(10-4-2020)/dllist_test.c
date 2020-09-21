#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

int main() {

  dllist l = create_list();
  node_t p;

  l = insert_before(l,l,1);
  l = insert_before(l,l,2);
  l = insert_before(l,l,3);

  for (p = l; p != NULL; p = p->next){
    printf("%d,", p->data);
  }
  printf("\n");

  if (find(l, 2) != NULL) {
    printf("Correct!\n");
  }

  if (find(l, 4) == NULL) {
    printf("Correct!\n");
  }

  l = remove_at(l,l);

  for (p = l; p != NULL; p = p->next){
    printf("%d,", p->data);
  }
  printf("\n");

  // if (nth(l, 2) != NULL)
  //   printf("%d\n", (nth(l, 2))->data);
      
  // if (nth(l, 4) == NULL)
  //   printf("Correct\n");

  printf("Length:%d\n",length(l));

  l = free_list(l);
  if(is_empty(l)){
    printf("List free!\n");
  }
  
  return 0;
}
