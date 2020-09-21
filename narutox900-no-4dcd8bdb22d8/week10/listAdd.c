#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listAdd.h"

node_t make_node(element_t x) {
  node_t n = (node_t)malloc(sizeof(struct Node));
  n->data = x;
  n->next = NULL;
  return n;
}

// create new empty list
list create_list() {
  return NULL;
}

// check whether a list is empty
int is_empty(list l) {
  return (l == NULL);
}

list append(list l,element_t x) {
    node_t n = make_node(x);
    if (l== NULL) {
        l = n;
        return l;
    }
    node_t tmp = l;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp ->next = n;
    return l;
}

// insert new element after a specific node 
list insert_after(list l, struct Node *p, element_t x) {
  node_t n = make_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    p->next = n;
    return l;
  }
}

// insert new element before a specific node 
list insert_before(list l, struct Node *p, element_t x) {
  node_t n = make_node(x);
  node_t prev;
  
  if (l == NULL) {
    return n;
  } else if (l == p) {
    n->next = l;
    return n;
  } else {
    for (prev = l; prev->next != p; prev = prev->next);
    n->next = p;
    prev->next = n;
    return l;
  }
}

// remove an element
list remove_at(list l, struct Node *p) {
  node_t prev;
  
  if (l == NULL)
    return NULL;
  else if (l == p) {
    l = p->next;
    free(p);
    return l;
  } else {
    for (prev = l; prev->next != p; prev = prev->next);
    prev->next = p->next;
    free(p);
    return l;
  }
}

// search
node_t find(list l, char* name) {
  node_t p = l;

  while ((p != NULL) && (strcmp(p->data.name,name)!=0))
    p = p->next;

  return p;
}

// return first node
node_t first_node(list l) {
	return l;
}

//return last node
node_t last_node(list l) {
	if (l = NULL) return NULL;
	node_t p = l;
	while (p != NULL) {
		if (p->next = NULL)
			return p;
		else p = p->next;
	}
}

// find length
int length(list l) {
	int i=0;
	node_t p = l;

	while(p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

// find nth node
node_t nth(list l, int n) {
	node_t p = l;
	int num = length(l);
	if (n> num) return NULL;
	for (int i = 0; i<n-1; i++)
	       p = p->next;
	return p;	
}


// reverse a linked list
node_t reverse(list l) {
	node_t cur,prev,next;
	cur = l;
	prev = NULL;
	next = NULL;
	while (cur != NULL) {
		next = cur->next;
		cur->next =prev;
		prev = cur;
		cur =next;
	}
	l = prev;
	return l;
}

// free a list
void free_list(list l) {
  node_t p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

list read_data(list l){
    FILE *fin = fopen("data.txt","r+");
    element_t tmp;
    char buf[100];
    while (fgets(buf,100,fin)) {
        sscanf(buf," %[^\n]s",tmp.name);
        printf("%s\n",tmp.name);
        fgets(buf,100,fin);
        sscanf(buf," %[^\n]s",tmp.num);
        printf("%s\n",tmp.num);
        fgets(buf,100,fin);
        sscanf(buf," %[^\n]s",tmp.mail);
        printf("%s\n",tmp.mail);
        l = append(l,tmp);
    }
    fclose(fin);
    return l;
}

list selection_sort(list l) {
    int n = length(l);
    node_t tmp = l;
    while (tmp != NULL)
    {
        node_t min = tmp;
        node_t r = tmp->next;
        while (r!=NULL) {
            if (strcmp(r->data.name,min->data.name)<0)
                min = r;
            r = r->next;
        }
        element_t x = tmp->data;
        tmp->data = min->data;
        min->data = x;
        tmp= tmp->next;
    }
    return l;
}

node_t findNodeatIndex(list l,int n){
  node_t tmp;
  tmp = l;
  while(tmp != NULL){
    if(n == 0){
      break;
    }else{
      n--;
      tmp = tmp->next;
    }
  }
  return tmp;
}

void swapNode(node_t node1,node_t node2){
  node_t tmp;
  tmp = node1;
  node1->data = node2->data;
  node2->data = tmp->data;

}

int partition (list l, int low, int high) 
{ 
    int j;
    node_t pivot = findNodeatIndex(l,high);    // pivot for last element 
    int i = (low - 1);  // Index of smaller element 
  
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (strcmp(findNodeatIndex(l,j)->data.name,pivot->data.name) < 0) 
        { 
            i++;    // increment index of smaller element 
            swapNode(findNodeatIndex(l,i), findNodeatIndex(l,j)); 
        } 
    }
    swapNode(findNodeatIndex(l,i+1),findNodeatIndex(l,high)); 
    return (i + 1); 
}

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(list l, int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(l, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(l, low, pi - 1); 
        quickSort(l, pi + 1, high); 
    } 
} 


void print_list(list l) {
    node_t tmp = l;
    while (tmp != NULL)
    {
        printf("%s\n%s\n%s\n",tmp->data.name,tmp->data.num,tmp->data.mail);
        tmp=tmp->next;
    }
    
}

