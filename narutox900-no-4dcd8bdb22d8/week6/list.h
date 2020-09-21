#ifndef _LIST_H_
#define _LIST_H_

typedef int element_t;

struct Node {
  element_t data;
  struct Node *next;
};

typedef struct Node* list;
typedef struct Node* node_t;

// create new empty list
list create_list();

// check whether a list is empty
int is_empty(list l);

// insert new element after a specific node 
list insert_after(list l, node_t p, element_t x);

// insert new element before a specific node 
list insert_before(list l, node_t p, element_t x);

// remove an element
list remove_at(list l, node_t p);

// search
node_t find(list l, element_t x);

// find length
int length(list l);

// reverse
node_t reverse (list l);

// find nth node
node_t nth (list l, int n);

#endif
