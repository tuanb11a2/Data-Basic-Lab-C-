#include <stdlib.h>
#include <stdio.h>
#include "dllist.h"

dllist make_node(element_t x) {
	dllist n = (dllist)malloc(sizeof(dllist));
	n->data =x;
	n->next = NULL;
	n->prev = NULL;
}

// create new empty list
dllist create_list() {
  return NULL;
}

// check whether a list is empty
int is_empty(dllist l) {
  return (l == NULL);
}


// insert new element after a specific node 
dllist insert_after(dllist l, node_t p, element_t x) {
	node_t n = make_node(x);
	if (l == NULL) 
		return n;
	else {
		n-> next = p-> next; 
		n-> prev = p;
		if (n->next != NULL)
			n-> next-> prev = n;
		p-> next = n;
		return l;
	}
}


// insert new element before a specific node 
dllist insert_before(dllist l, node_t p, element_t x) {
	dllist n = make_node(x);
	if (l == NULL)
		return n;
	else {
		n-> next = p;
		n-> prev = p-> prev;
		if (n->prev != NULL)
			n-> prev-> next = n;
		else l = n;
		p-> prev = n;
		return l;
	}
}


// remove an element
dllist remove_at(dllist l, node_t p) {
	node_t n;
	if (l == NULL)
		return NULL;
	else if (l == p){
		l = p->next;
		l-> prev = NULL;
		free(p);
		return l;
	} else {
		for (n = l; n->next != p ; n = n->next);
		n->next = p-> next;
		free(p);
		return l;
	}
}


// search
node_t find(dllist l, element_t x) {
	node_t p = l;
	while ((p!= NULL) && (p-> data !=x))
		p = p->next;
	return p;
}


// first node
node_t first(dllist l) {
	return l;
}


// last node
node_t last(dllist l) {
	node_t p = l;
	while ((p!= NULL) && (p->next != NULL))
		p = p->next;
	return p;

}




// length
int length(dllist l) {
	int i= 0;
	node_t p = l;
	while (p!= NULL) {
		p = p->next;
		i++;
	}
	return i;
}

// nth node
node_t nth(dllist l, int n) {
	node_t p = l;
	if (n > length(l)) {
		//printf("No %dth node\n",n);
		return NULL;
	} else {
		for (int i =0; i<n;i++)
			p = p->next;
		return p;
	}
		
	
}
// free a list
void free_list(dllist l) {

	node_t cur = l ;
	node_t tmp = cur -> next;
	while (cur != NULL) {
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}

}

