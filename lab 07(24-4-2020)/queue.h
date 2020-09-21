#ifndef __QUEUE__H__
#define __QUEUE__H__

#define MAX_LEN 100

typedef int element_t;
struct Queue {
  element_t data[MAX_LEN];
  int f, r;
};

typedef struct Queue* queue;
  
queue create_queue();
int is_empty(queue q);
int is_full(queue q);

queue enqueue(queue q, element_t x);
queue dequeue(queue q);
element_t front(queue q);
element_t rear(queue q);

void free_queue(queue q);

#endif
