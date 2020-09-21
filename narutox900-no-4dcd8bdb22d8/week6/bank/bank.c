#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue q1;
queue q2;

void showMenu() {
  printf("\nMenu\n");
  printf("1.Add guest\n");
  printf("2.Print all guest and time\n");
  printf("3.End\n");

}

void addGuest() {
  // read guest data from file
  FILE *fin;
  char c[100];
  if ((fin = fopen("data.txt","r")) == NULL)
    {
      printf("Can not open data.txt");
      return;
    }
  int i = 0,n = 0;
  while (fscanf(fin," %[^\n]s",c) == 1)
    {
      n++;
    }
  rewind(fin);
  struct timepoint *point = malloc(n*sizeof(struct timepoint));
  while (fscanf(fin," %[^\n]s",c) == 1) {
    sscanf(c, "%d %d %d",
           &((point+i)->tpoint.hour),
           &((point+i)->tpoint.mins),
           &((point+i)->num));
    printf("%d:%d %d\n", (point+i)->tpoint.hour, (point+i)->tpoint.mins, (point+i)->num);
    i++;
  }
  printf("\n");

  // add to queue
  i = 0;
  int s1 = 0 , s2 =0;
  for (int i=0;i < n;i++){
      for (int x=0; x < (point+i)->num; x++) {
        if (s1 <= s2) {
          struct wait_time wt;
          wt.time_serve = (point+i)->tpoint;
          wt.time_wait = calWait(q1,wt);
          wt.time_serve = addTime(wt.time_serve,wt.time_wait);
          q1 = enqueue(q1,wt);
          s1++;
        } else {
          struct wait_time wt;
          wt.time_serve = (point+i)->tpoint;
          wt.time_wait = calWait(q2,wt);
          wt.time_serve = addTime(wt.time_serve,wt.time_wait);
          q2 = enqueue(q2,wt);
          s2++;
        }
      }
    }
  free(point);
  fclose(fin);
  return ;
}

void printInfo() {
  int wt =0,num =0;
  float avg;
  printf("\nQueue 1:\n");
  while (!is_empty(q1)) {
    printf("Serve: %d:%d  Wait: %d\n",front(q1).time_serve.hour, front(q1).time_serve.mins,front(q1).time_wait);
    wt += front(q1).time_wait;
    num++;
    dequeue(q1);
  }
  printf("\nQueue 2:\n");
  while (!is_empty(q2)) {
    printf("Serve: %d:%d  Wait: %d\n",front(q2).time_serve.hour, front(q2).time_serve.mins,front(q2).time_wait);
    wt+= front(q2).time_wait;
    num++;
    dequeue(q2);
  }
  avg = wt/num;
  printf("\nTotal number of guests: %d\nTotal wait time: %d\nAverage wait time: %.2f",num,wt,avg);

}



int main() {
  int sel=0;
  q1 = create_queue();
  q2 = create_queue();
  while (sel != 3) {
    showMenu();
    scanf("%d",&sel);
    switch (sel) {
    case 1: addGuest(); break;
    case 2: printInfo(); break;
    case 3: printf("Goodbye\n"); break;
    }

  }
}
