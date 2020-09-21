#include "stdlib.h"
#include "stdio.h"
#include "arrayAdd.h"

element_t* a;
int n;
void showMenu() {
  printf("\n__________________MENU___________________\n");
  printf("Choose an option to perform:\n");
  printf("1. Read data \n");
  printf("2. Sort by name\n");
  printf("3. Print all data\n");
  printf("0. Exit\n");
}


int main() {
    int flag= 1;
    while (flag!=0) {
    showMenu();
    scanf("%d",&flag);
    switch (flag) {
    case 1: a= read_data(a);
            int n= length()/3;
            printf("%d\n",n);
      break;
    case 2: a = heapSort(a,n);break;
    case 3: printAll(a,n) ; break;
    case 0: break;
    }
  }


}