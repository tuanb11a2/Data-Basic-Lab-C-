#ifndef __SEAT_QUEUE__H__
#define __SEAT_QUEUE__H__

#define MAX_LEN 100
#include "request.h"

typedef struct Seat element_t;
struct SeatQueue {
  element_t data[MAX_LEN];
  int f, r;
};

typedef struct SeatQueue* queue;
  
queue create_queue();
int is_empty(queue q);
int is_full(queue q);

queue enqueue(queue q, element_t x);
queue dequeue(queue q);
element_t front(queue q);
element_t rear(queue q);
int seatLeft(queue q); 
void free_queue(queue q);

#endif
