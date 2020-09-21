#include <stdio.h>
#include "dllist.h"

int main() {

  dllist l = create_list();
  node_t p;

  l = insert_before(l,l,1);
  printf("%d\n",length(l));
  l = insert_before(l,l,2);
   printf("%d\n",length(l));
  l = insert_before(l,l,3);
   printf("%d\n",length(l));
  for (p = l; p != NULL; p = p->next)
    printf("%d,", p->data);
  printf("\n");

  if (find(l, 2) != NULL) {
    printf("Correct1!\n");
  }

  if (find(l, 4) == NULL) {
    printf("Correct2!\n");
  }

  if (nth(l, 2) != NULL)
    printf("Correct3 %d\n", (nth(l, 2))->data);
      
  if (nth(l, 4) == NULL)
    printf("Correct4\n");
  
  return 0;
}
