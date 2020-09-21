#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue create_queue() {
  queue q = (queue) malloc(sizeof(struct Queue));
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

int minusTime(time t1, time t2){
  time t;
  t1 = addTime(t1,15);
  t.hour = t2.hour - t1.hour;
  if ((t2.mins - t1.mins) >= 0)
    t.mins = t2.mins-t1.mins+t.hour*60;
  else t.mins = 60*t.hour - (t1.mins - t2.mins);
  return t.mins;
}

time addTime(time t1, int x) {
  time t;
  if ((t1.mins + x) >= 60) {
    t.mins = t1.mins + x -60;
    t.hour = t1.hour +1;
  } else {
    t.mins = t1.mins + x;
    t.hour = t1.hour;
  }
  return t;
}

int calWait(queue q,struct wait_time wt) {
  if (is_empty(q)) return 0;
  else {
    int wait = minusTime(q->data[q->r].time_serve , wt.time_serve);
    if (wait <= 0) return -(wait);
    else return 0;
  }
}
