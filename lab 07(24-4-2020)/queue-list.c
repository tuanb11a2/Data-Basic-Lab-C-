#include <stdio.h>
#include <stdlib.h>
#include "queue-list.h"

node make_node(element_t x){
  node new=(node)malloc(sizeof(node));
  new->data=x;
  new->next = NULL;
  return new;
}

queue create_queue() {
  queue q = (queue)malloc(sizeof(queue));
  q->f = NULL;
  q->r = NULL;
  return q; 
}

int is_empty(queue q) {
  return (q->f == NULL);
}

int is_full(queue q) {
  return 0;
}

queue enqueue(queue q, element_t x) {
  node new = make_node(x);
  if(is_empty(q)){
    q->f = q->r = new;
  }else{
    q->r->next = new;
    q->r = new;
  }
}

queue dequeue(queue q) {
  if(is_empty(q)){
    printf("Underflow!");
  }else{
    q->f = q->f->next;
  }
}

element_t front(queue q) {
  if(is_empty(q)){
    printf("Underflow!");
    return 0;
  }else{
    return (q->f->data); 
  }
}

element_t rear(queue q) {
  if(is_empty(q)){
    printf("Underflow");
    return 0;
  }else{
    return (q->r->data);
  }

}

void free_queue(queue q) {
  while(!is_empty(q)){
    dequeue(q);
  }
}
