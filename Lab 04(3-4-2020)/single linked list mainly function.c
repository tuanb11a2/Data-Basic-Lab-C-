#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node* next;
};

typedef struct node node_t;

//Function for print the single linked list
void printList(node_t *head){
	node_t *cur = head;
	while(cur != NULL){
		printf("The value is:%d\n",cur->value);
		cur=cur->next;
	}
	printf("\n");
}

//Add a new node to the list
node_t newNode(int value){
	
}

int main(){
	node_t n1,n2,n3;
	node_t *head;
	
	n1.value=12;
	n2.value=20;
	n3.value=30;
	
	//Link them up
	head = &n3;
	n3.next= &n2;
	n2.next= &n1;
	n1.next= NULL;//The end of list
	
	printList(head);
	
	return 0;
}
