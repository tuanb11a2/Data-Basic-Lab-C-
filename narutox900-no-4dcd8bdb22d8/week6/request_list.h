#ifndef _REQUEST_LIST_H_
#define _REQUEST_LIST_H_

typedef struct Request element_t1;

struct Node {
  element_t1 data;
  struct Node *next;
};

typedef struct Node* list;
typedef struct Node* node_t;

// create new empty list
list create_list();

// check whether a list is empty
int rl_is_empty(list l);

// insert new element after a specific node 
list insert_after(list l, node_t p, element_t1 x);

// insert new element before a specific node 
list insert_before(list l, node_t p, element_t1 x);

// remove an element
list remove_at(list l, node_t p);

// search
node_t find(list l, char* name);

// first node - TODO
node_t first(list l);

// last node - TODO
node_t last(list l);

// nth node - TODO
node_t nth(list l, int n);

// length - TODO
int length(list l);

// nth node - TODO
list reverse(list l);


// free a list
void free_list(list l);


#endif
