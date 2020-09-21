#include <stdio.h>
#include <stdlib.h>
#include "stack-list.h"

stack make_node(element_t x){
  stack new=(stack)malloc(sizeof(stack));
  new->data = x;
  new->next = NULL;
  return new;
}

stack create_stack() {
  stack top = (stack)malloc(sizeof(stack));
  top->next=NULL;
  return top;
}

int is_empty(stack s) {
  return (s->next == NULL);
}

int is_full(stack s) {
  return 0;
}

element_t top(stack s) {
  if(s->next == NULL){
    printf("Stack is empty");
    return 0;
  }
  s=s->next;
  return s->data;
}

stack push(stack s, element_t x) {
  stack new=make_node(x);
  new->next = s->next;
  s->next = new;
  return s;
}

stack pop(stack s) {
  stack tmp;
  if(s->next == NULL){
    printf("stack is empty!");
  }else{
    tmp = s->next;
    s->next = tmp->next;
    return s;
  }
}

void free_stack(stack s) {
  while(s->next != NULL){
    pop(s);
  }
  printf("Stack is free!");
}
