#include <stdio.h>
#include <string.h>

#define MAX 101

typedef struct Address {
  char name [20];
  char num [20];
  char email [20];
} add_t;


int n;
add_t addbook[MAX];

void readFromText () {
  FILE *fin;
  char c[MAX],*p;
	if ((fin = fopen("addbook.txt","r")) == NULL)
    {
      printf("Can not open %s.\n", "addbook.txt");
      return;
    }
  int i =0;
  printf("\n");
  while (fscanf(fin," %[^\n]s",c) == 1) {
    p = strtok(c,",");
    strcpy(addbook[i].name,p);
    p = strtok(NULL,",");
    strcpy(addbook[i].num,p);
    p = strtok(NULL,",");
    strcpy(addbook[i].email,p);
    printf("%s %s %s\n",addbook[i].name,addbook[i].num,addbook[i].email);
    i++;
  }
  n = i;
  fclose(fin);
  return;
}

void findByName(){
  char c[20];
  int i;
  printf("Enter the name you want to find: ");
  scanf(" %[^\n]s",c);
  for (i = 0;i <n && strcmp(addbook[i].name,c)!=0 ;i++); 
  if (strcmp(addbook[i].name, c) == 0){
    printf("\n%s %s %s\n",addbook[i].name,addbook[i].num,addbook[i].email);
    add_t temp = addbook[i];
    for (int j = i-1;j>=0;j--) addbook[j+1]=addbook[j];
    addbook[0] = temp;
   	return;
  }

  printf("Name does not exist\n");
}

void printAll(){
	for (int i=0;i<n;i++) {
		 printf("%s %s %s\n",addbook[i].name,addbook[i].num,addbook[i].email);

	}
}

int main() {
  readFromText();
  findByName();
  printAll();
}
