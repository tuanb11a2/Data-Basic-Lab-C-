#include <stdio.h>
#include <stdlib.h>
#include "seat_queue.h"

queue create_queue() {
  queue q = (queue) malloc(sizeof(queue));
  q->f = q->r = -1;
  return q;
}

int is_empty(queue q) {
  return (q->f == -1);
}

int is_full(queue q) {
  return ((q->f == 0) && (q->r == (MAX_LEN - 1)) ||
	  (q->f == (q->r + 1)));
}

queue enqueue(queue q, element_t x) {
  if (q->f == -1) {
    q->data[0] = x;
    q->f = q->r = 0;
  } else if (is_full(q)) {
    printf("Overflow!\n");
  } else {
    q->r++;
    if (q->r >= MAX_LEN) q->r = 0;
    q->data[q->r] = x;
  }
  return q;
}

queue dequeue(queue q) {
  if (q->f == -1) {
    printf("Underflow!\n");
  } else if (q->f == q->r) {
    q->f = q->r = -1;
  } else {
    q->f++;
    if (q->f >= MAX_LEN) q->f = 0;
  }
  return q;
}

element_t front(queue q) {
  if (q->f == -1) {
    printf("Underflow!\n");
    exit(0);
  } else {
    return q->data[q->f];
  }
}

element_t rear(queue q) {
  if (q->f == -1) {
    printf("Underflow!\n");
    exit(0);
  } else {
    return q->data[q->r];
  }
}

void free_queue(queue q) {
  free(q);
}
