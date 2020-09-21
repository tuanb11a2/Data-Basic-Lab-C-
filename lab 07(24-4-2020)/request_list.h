#ifndef _REQUEST_LIST_H_
#define _REQUEST_LIST_H_

#define MAX_REQUEST_SEATS 20

//Ticket queue.h
#define ST_W 1
#define ST_C 2
#define ST_N 3

struct Seat {
  int row;   // [1-50]
  char col;  // [A,B,C,D,E,F]
};

struct Request {
  char name[100];
  int quantity;
  int seat_type;
  struct Seat reserved_seats[MAX_REQUEST_SEATS];
};

typedef struct Request element_t; 

//Request list.h
struct Node {
  struct Request data;
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
node_t find(list l, char* name);

// first node - TODO
node_t first(list l);

// last node - TODO
node_t last(list l);

// nth node - TODO
node_t nth(list l, int n);

// length - TODO
node_t length(list l);

//modify node
list modify_at(list l,node_t p);

// nth node - TODO
list reverse(list l);


// free a list
void free_list(list l);


#endif
