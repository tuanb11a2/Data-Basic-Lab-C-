#include <stdio.h>
#include <stdlib.h>
#include "queue-list.h"

queue create_queue() {
  queue q = (queue) malloc(sizeof(queue));
  q->f = q-> r = NULL;
  return q;
}

int is_empty(queue q) {
  return (q->f == NULL);
}

int is_full(queue q) {
  
}

queue enqueue(queue q, element_t x) {
  if (q->f == NULL) {
    q->f = malloc(sizeof(struct Node));
    q->f->data = x;
    q->r = q->f;
    return q;
  } else {
    struct Node* new =malloc(sizeof(struct Node));
    new->data = x;
    new->next = NULL;
    q->r->next = new;
    q->r = new;
    return q;
  }
}

queue dequeue(queue q) {
  if (q->f == NULL) {
    printf("System underflow!\n");
    exit(1);
  } else if (q->f == q->r) {
    free (q->f);
  } else {
    struct Node* tmp = q->f;
    q->f = q->f->next;
    free(tmp);
    return q;
  }
}

element_t front(queue q) {
  if (q->f == NULL) {
    printf("Underflow\n");
    exit(1);
  } else {
    return q->f->data;
  }
}

element_t rear(queue q) {
  if (q->f == NULL) {
    exit(1);
  } else {
    return q->r->data;
  }
}

void free_queue(queue q) {
  while (q->f != NULL) {
    struct Node* tmp = q->f;
    q->f = q->f->next;
    free(tmp);
  }
}
