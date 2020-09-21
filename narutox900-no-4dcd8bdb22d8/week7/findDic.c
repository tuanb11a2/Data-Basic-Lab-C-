#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 240000

typedef struct dictionary {
  char key[30];
} dict_t;

dict_t dict[MAX];

int checkSubstring (char str[], char sub[]) {
  char tmp[30];
  strcpy(tmp, str);
  tmp[0] = tolower(tmp[0]);
  char *p1 = tmp;
  char *p2 = sub;
  if (*p1 == *p2) {
      for (int j = 0; j<strlen(sub);j++) {
        if (*(p1+j) == *(p2+j));
        else {
          return -1;
        }
      }
  }  else {
        return -1;
  }
  return 0;
}


int searchDict (char str[]) {
  int flag = 0;
  for (int i=0; i< MAX; i++) {
    if (checkSubstring(dict[i].key,str) == 0) {
      if (flag == 0) flag = 1;
      printf("%d %s\n",i,dict[i].key);
    } else if (flag == 1) {
      break;
  }
  }
}

int main(){
  FILE *fp;
  if ((fp = fopen("dict-data.txt","r")) == NULL) {
    printf("Can not open dict-data.txt!\n");
    return -1;
  }
  int i =0;
  while(fscanf(fp," %[^\n]s",dict[i].key) == 1) {i++;}
  char str[30];
  printf("Enter the word you want to search: ");
  scanf(" %s",str);
  searchDict(str);
  return 0;

}
