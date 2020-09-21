#include <stdio.h>
#include <string.h>

int checkSubstring (char str[], char sub[]) {
  char *p1 = str;
  char *p2 = sub;
  if (*p1 == *p2) {
    for (int j = 0; j<strlen(sub);j++) {
      if (*(p1+j) == *(p2+j));
      else return -1;
    }
  } else return -1;
  return 0;
}

int main(){
  printf("\n%d\n",checkSubstring("cabc","a"));
}
