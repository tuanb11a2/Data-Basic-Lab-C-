#include <stdio.h>

int sqSearch(int list[],int x,int n){
	int count = 0;
	int i = 0;
	while (list[i] != x && i<n) {
		count+=2;
		i++;
	}
	if (i < n) {
		count++; 
		printf("Found!\nCount = %d\n",count);
		return i;
	} else {
		count++;
		printf("Not found!\nCount = %d\n",count);
		return  -1;
	}
}

int seSearch(int list[], int x, int n){
	int count = 0;
	int i =0;
	list[n] = x;
	while (list[i] !=x ) {
		count++;
		i++;
	}
	if (i<n) {
		count++;
		printf("Found!\nCount = %d\n",count);
		return i;
	} else {
		count++;
		printf("Not found!\nCount = %d\n",count);
		return -1;
	}
}

int bcount;

int binSearch(int list[], int x, int low, int high) {
	if (low > high) {
		bcount++;
		printf("Not found!\nCount = %d\n",bcount);
		return -1;
	}
	bcount++;
	int mid = (low+high)/2;
	if (list[mid] < x) {
		bcount++;
		return binSearch(list,x,mid+1,high);
	} else if (list[mid] > x) {
	        bcount +=2;
       		return binSearch(list,x,low,mid-1);
	} else {
		bcount +=2;
		printf("Found!\nCount = %d\n",bcount);
		return mid;
	}
}

int main() {
	int list[100];
	for (int i =0; i <100 ; i++) {
		list[i] = i+1;
	}
	printf("Search for 3\n");
	printf("Sequential search : ");
	sqSearch(list,3,100);
	printf("Sentinel search : ");
	seSearch(list,3,100);
	printf("Binary search : ");
	bcount = 0;
	binSearch(list,3,0,99);	

	printf("Search for 57\n");
	printf("Sequential search : ");
	sqSearch(list,57,100);
	printf("Sentinel search : ");
	seSearch(list,57,100);
	printf("Binary search : ");
	bcount = 0;
	binSearch(list,57,0,99);

	printf("Search for 101\n");
	printf("Sequential search : ");
	sqSearch(list,101,100);
	printf("Sentinel search : ");
	seSearch(list,101,100);
	printf("Binary search : ");
	bcount = 0;
	binSearch(list,101,0,99);
}


