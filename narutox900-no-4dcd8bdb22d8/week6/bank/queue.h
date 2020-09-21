#ifndef __QUEUE__H__
#define __QUEUE__H__

#define MAX_LEN 100

typedef struct time_t {
  int hour;
  int mins;
} time;

struct timepoint {
  time tpoint;
  int num;
};

struct  wait_time {
  time time_serve;
  int time_wait;
};

typedef struct wait_time element_t;

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
int minusTime(time t1,time t2);
time addTime(time t1,int x);
int calWait(queue q,struct wait_time tp);
void free_queue(queue q);

#endif
