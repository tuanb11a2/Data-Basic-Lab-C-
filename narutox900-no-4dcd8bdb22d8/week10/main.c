#include "stdlib.h"
#include "stdio.h"
#include "listAdd.h"

list l;

void showMenu() {
  printf("\n__________________MENU___________________\n");
  printf("Choose an option to perform:\n");
  printf("1. Read data \n");
  printf("2. Sort by name\n");
  printf("3. Print all data\n");
  printf("4. Sort by name with quick_sort\n");
  printf("0. Exit\n");
}

int main() {
    int flag= 1;
    while (flag!=0) {
    showMenu();
    scanf("%d",&flag);
    switch (flag) {
    case 1: l= read_data(l);
      break;
    case 2: l = selection_sort(l); break;
    case 3: print_list(l) ; break;
    case 4: quickSort(l,0,length(l));break;
    case 0: break;
    }
  }


}