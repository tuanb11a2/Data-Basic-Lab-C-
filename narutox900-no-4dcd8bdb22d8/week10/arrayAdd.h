#ifndef _ARRAYADD_H_
#define _ARRAYADD_H_

typedef struct mobileaddress
{
    char name[10];
    char num[10];
    char mail[20];
} element_t;

element_t* read_data(element_t* a);

void printAll(element_t* a,int n);
int length();

element_t* heapSort(element_t* a, int n);
void heapify(element_t* a, int n, int i);
void swap(element_t* a, element_t* b);
#endif