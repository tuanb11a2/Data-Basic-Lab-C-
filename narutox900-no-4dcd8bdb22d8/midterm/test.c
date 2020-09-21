#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

BookDB db;

void readFromFile()
{
  printf("Enter the file name: \n");
  char name[20];
  scanf("%s", name);
  getchar();
  db = read_db(name);
  print_db(db);
}

void input() //pass
{
}
void removeat() {
  char id[10];
  printf("Enter the ID you want to remove: ");
  scanf("%s",id);
  removeDB(db,id);
}
void swapBook()
{
  printf("Enter the id of book 1: \n");
  char id1[10];
  scanf("%s", id1);
  getchar();
  BookDB b1 = find_by_id(db, id1);

  printf("Enter the id of book 2: \n");
  char id2[10];
  scanf("%s", id2);
  getchar();
  BookDB b2 = find_by_id(db, id2);

  swap(db, b1, b2);
  print_db(db);
}

void countYear()
{
}

void writeFile()
{
  printf("Enter the file name: \n");
  char name[20];
  scanf("%s", name);
  getchar();
  write_db(name, db);
}

int main(int argc, char const *argv[])
{
  int isRunning = 1;
  int a;
  while (isRunning)
    {
      printf("\n__________________MENU___________________\n");
      printf("Choose an option to perform:\n");
      printf("1. Read \n");
      printf("2. Input\n");
      printf("3. Swap\n");
      printf("4. printdb\n");
      printf("5. writeFile\n");
      printf("6. Exit\n");
      scanf("%d", &a);
      getchar();
      switch (a)
        {
        case 1:
          readFromFile();
          break;
        case 2:
          input();
          break;
        case 3:
          swapBook();
          break;
        case 4:
          print_db(db);
          break;
        case 5:
          writeFile();
          break;
        case 6:
          isRunning = 0;
          break;
        default:
          printf("Invalid operation!!!\n");
          break;
        }
    }

  return 0;
}
