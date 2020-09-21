#include <stdio.h>

#define MAX_SIZE 1000
typedef struct {
  int key;
} element;

int binsearch(element list[], int x, int low, int high) {
  if (low > high) return -1;
  int mid = (low + high )/2 ;
  if (list[mid].key < x ) return binsearch (list,x,mid+1,high);
  else if (list[mid].key > x ) return binsearch (list,x,low,mid-1);
  else return mid;
  return -1;
}

int searchInOne (element l1[], element l2[], int s1,int s2) {
  int count = 0;
  for (int i=0 ; i<s1 ; i++) {
    if (binsearch(l2,l1[i].key,0,s2) == -1) {
      count =1;
      printf("Element %d: %d\n",i,l1[i].key);
    }
  }
  if (count == 0) printf("abc\n");
  return count;
}

int searchSame (element l1[], element l2[], int s1, int s2) {
  int count = 0;
  for (int i=0 ; i<s1 ; i++) {
    if (binsearch(l2,l1[i].key,0,s2) != -1) {
      count =1;
      printf("Element %d: %d\n",i,l1[i].key);
    }
  }
  if (count == 0) printf("cba\n");
  return count;
}


int main() {
  element list1[MAX_SIZE];
  element list2[MAX_SIZE];
  int n1 =0;
  int n2 =0;
  printf("How many element in list1: ");
  scanf("%d",&n1);
  for (int i = 0; i<n1; i++) {
    scanf("%d",&list1[i].key);
  }
  printf("How many element in list2: ");
  scanf("%d",&n2);
  for (int i = 0; i<n2; i++) {
    scanf("%d",&list2[i].key);
  }
  searchInOne(list1,list2,n1,n2);
  searchInOne(list2,list1,n2,n1);
  searchSame(list1,list2,n1,n2);
}
