#include <stdio.h>
#include "tree.h"

tree t;

void findWord(){
  
}

void inputWord(){
  dict tmp;
  printf("Enter the word: ");
  scanf(" %s",tmp.word);
  printf("Enter the meaning: ");
  scanf(" %[^\n]s",tmp.trans);
  t = insertBST(t,tmp);
  printf("Word has been inserted!\n");
}

void delWord(){
  dict tmp;
  printf("Enter the word you want to delete: ");
  scanf(" %s",tmp.word);
  removeBST(t,tmp);
  printf("Word has been deleted!\n");
}

void printAll() {
  inorderTravel(t);
}

void writeFile() {
  FILE *fout = fopen("output.txt","w+");
  tree tmp = t;
  writeData(t,fout);
  fclose(fout);
}

void showMenu() {
  printf("\n__________________MENU___________________\n");
  printf("Choose an option to perform:\n");
  printf("1. Read data \n");
  printf("2. Input words\n");
  printf("3. Delete words\n");
  printf("4. Print all \n");
  printf("5. Write to file\n");
  printf("6. Find word\n");
  printf("0. Exit\n");
}


int main(){
  int flag= 1;
  while (flag!=0) {
    showMenu();
    scanf("%d",&flag);
    switch (flag) {
    case 1: t = readData(t,"dict.txt");
      break;
    case 2: inputWord(); break;
    case 3: delWord() ; break;
    case 4: printAll();
      break;
    case 5: writeFile();
      break;
    case 6: //calTC();
    case 0: break;
    }
  }
}
