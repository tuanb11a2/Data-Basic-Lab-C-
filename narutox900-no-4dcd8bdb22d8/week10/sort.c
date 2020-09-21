#include <stdio.h>
#include <stdlib.h>

void insertionSort(int a[],int n) {
    int j;
    for (int i = 1; i < n; i++) {
        int tmp = a[i];
        j = i-1;
        while (j>=0 && a[j] > tmp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
    }
}

void swap (int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int a[], int n) {
    int i,j,min;

    for (i = 0; i<n-1 ;i++) {
        min = i;
        for (j= i+1; j<n;j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(&a[i],&a[min]);
    }
}


int main() {
    int a[10] = {4,2,6,3,1,7,5,8,9,0};
    //insertionSort(a,10);
    selectionSort(a,10);
    for (int i = 0 ; i<10;i++) {
        printf ("%d ",a[i]);
    }
    printf("\n");
}
