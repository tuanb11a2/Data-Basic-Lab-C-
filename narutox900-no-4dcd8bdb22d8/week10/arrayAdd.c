#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arrayAdd.h"

element_t* read_data(element_t* a){
    FILE* fin = fopen("data.txt","r+");
    element_t* db;
    char buf[100];
	int i = 0,n = 0;
	while (fgets(buf,100,fin))
	{
		n++;
	}
	rewind(fin);
    db = (element_t*)malloc(n*sizeof(element_t));
    while (fgets(buf,100,fin)) {
        sscanf(buf," %[^\n]s",db[i].name);
        printf("%s\n",db[i].name);
        fgets(buf,100,fin);
        sscanf(buf," %[^\n]s",db[i].num);
        printf("%s\n",db[i].num);
        fgets(buf,100,fin);
        sscanf(buf," %[^\n]s",db[i].mail);
        printf("%s\n",db[i].mail);
        i++;
    }
    fclose(fin);
    return db;
}

int length() {
    FILE* fin = fopen("data.txt","r+");
    element_t* db;
    char buf[100];
	int i = 0,n = 0;
	while (fgets(buf,100,fin))
	{
		n++;
	}
	rewind(fin);
    fclose(fin);
    return n;
}

void printAll(element_t* db,int n){
    for (int i = 0; i<n ; i++) {
        printf("%s %s %s\n",db[i].name,db[i].num,db[i].mail);
    }
}

element_t* heapSort(element_t* a,int n) {
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(a, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(&a[0], &a[i]); 
  
        // call max heapify on the reduced heap 
        heapify(a, i, 0); 
    } 
    return a;
}

void heapify(element_t* a, int n, int i){
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && strcmp(a[l].name,a[largest].name)>0) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && strcmp(a[r].name,a[largest].name)>0) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(&a[i], &a[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(a, n, largest); 
    } 

}

void swap(element_t* a, element_t* b) {
    element_t tmp = *a;
    *a = *b;
    *b = tmp;
}