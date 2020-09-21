#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#define MAX 10000000

tree t;

void createData() {
  t = freeTree(&t);
  srand(time(NULL));
  for (int i = 0; i< 1000000;i++) {
    t = insertBST(t,rand() % MAX);
  }
}

void searchData() {
  int num;
  printf("Enter the number you want to search: ");
  scanf("%d",&num);
  searchBST(t,num,0);
}

void printAll() {
  inorderTravel(t);
}

void showMenu() {
  printf("\n__________________MENU___________________\n");
  printf("Choose an option to perform:\n");
  printf("1. Create data \n");
  printf("2. Search for number\n");
  printf("3. Print all data\n");
  printf("0. Exit\n");
}


int main() {
  int flag= 1;
  while (flag!=0) {
    showMenu();
    scanf("%d",&flag);
    switch (flag) {
    case 1: createData();
      break;
    case 2: searchData(); break;
    case 3: printAll() ; break;
    case 0: break;
    }
  }

}
