#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

node_t make_node(element_t x){
  node_t new = (node_t)malloc(sizeof(struct Node));
  new->next = new->prev = NULL;
  new->data = x;
  return new;
}

// create new empty list
dllist create_list() {
  return NULL;
}

// check whether a list is empty
int is_empty(dllist l) {
  return (l == NULL);
}

//insert at the beginning
dllist insert_head(dllist l,element_t x){
  node_t new = make_node(x);
  l->prev = new;
  new->next = l;
  l = new;
  return l;
}


//insert new element after a specific node 
dllist insert_after(dllist l, node_t p, element_t x) {
  node_t new = make_node(x);
  if(is_empty(l)){
    return new;
  }else{
    new->next = p->next;
    new->prev = p;
    (p->next)->prev = new;
    p->next = new;
    return l;
  }
}


// insert new element before a specific node 
dllist insert_before(dllist l, node_t p, element_t x) {
  node_t new = make_node(x);
  if(is_empty(l)){
    l = new;
  }
  else if(l == p && l != NULL){
    l = insert_head(l,x);
  }else{
    new->next = p;
    new->prev = p->prev;
    (p->prev)->next = new;
    p->prev = new;
  }
  return l;
  
}


// remove an element
dllist remove_at(dllist l, node_t p) {
  node_t tmp;
  tmp = l;
  if(l == NULL){
    return NULL;
  }else if(l == p){
    l = p->next;
    free(p);
    return l;
  }else{
    while (tmp != NULL)
    {
      if(tmp->next == p){
        tmp->next = p->next;
        p->next->prev = tmp;
        free(p);
        break;
      }else{
        tmp = tmp->next;
      }
    }    
    return l;
  }
}


// search
node_t find(dllist l, element_t x) {
  node_t p = l;

  while ((p != NULL) && (p->data != x))
    p = p->next;

  return p;
}


// first node
node_t first(dllist l) {
  return l;
}


// last node
node_t last(dllist l) {
  node_t tmp;
  tmp = l;
  while(tmp != NULL){
    if(tmp->next == NULL){
      break;
    }else{
      tmp = tmp->next;
    }
  }
  return tmp;
}


// nth node
node_t nth(dllist l, int n) {
  //  TODO
}


// length
int length(dllist l) {
  node_t p = l;
  int count = 0;

  while (p != NULL) {
    count ++;
    p = p->next;
  }
  return count;
}

// free a list
dllist free_list(dllist l) {
  node_t p = l;

  while (l != NULL) {
    p = l->next;
    free(l);
    l = p;
  }
  return l;
}

