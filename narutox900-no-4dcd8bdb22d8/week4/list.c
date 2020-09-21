#include <stdlib.h>
#include <stdio.h>

#include "list.h"

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
node_t find(list l, element_t x) {
  node_t p = l;

  while ((p != NULL) && (p->data != x))
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
