#ifndef _LISTADD_H_
#define _LISTADD_H_

typedef struct mobileaddress
{
    char name[10];
    char num[10];
    char mail[20];
} element_t;


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

list append(list l,element_t x) ;

// insert new element after a specific node 
list insert_after(list l, node_t p, element_t x);

// insert new element before a specific node 
list insert_before(list l, node_t p, element_t x);

// remove an element
list remove_at(list l, node_t p);

// search
node_t find(list l, char* name);

// find length
int length(list l);

// reverse
node_t reverse (list l);

// find nth node
node_t nth (list l, int n);

list read_data(list l);

list selection_sort(list l);

void swapNode(node_t node1,node_t node2);

node_t findNodeatIndex(list l,int n);

int partition(list l,int low, int high);

void quickSort(list l, int low, int high);

void print_list(list l);
#endif
