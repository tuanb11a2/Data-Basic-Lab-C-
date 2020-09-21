#include <stdio.h>
#include "request.h"
#include "request_list.h"
#include "seat_queue.h"

queue w_seats;
queue n_seats;
queue c_seats;
list requests;




void showMenu() {
  printf("\nMenu\n");
  printf("1.Add request\n");
  printf("2.Cancel request\n");
  printf("3.Print all requests\n");
  printf("4.Search request\n");
  printf("5.End\n");

}

void initialize() {
  requests = create_list();
  w_seats = create_queue();
  n_seats = create_queue();
  c_seats = create_queue();
  struct Seat seat;
  //Initialization for seats
  for (int i = 1; i<=50; i++) {
    seat.row = i;
    seat.col = 'A';
    enqueue(w_seats,seat);
    seat.row = i;
    seat.col = 'F';
    enqueue(w_seats,seat);
    seat.row = i;
    seat.col = 'B';
    enqueue(n_seats,seat);
    seat.row = i;
    seat.col = 'E';
    enqueue(n_seats,seat);
    seat.row = i;
    seat.col = 'C';
    enqueue(c_seats,seat);
    seat.row = i;
    seat.col = 'D';
    enqueue(c_seats,seat);

  }
}

void makeRequest() {
  struct Request new;
  printf("\nEnter your name: ");
  scanf(" %[^\n]s",new.name);
  printf("\nEnter the quantity of the ticket you'd like to order: ");
  scanf("%d",&new.quantity);
    printf("\nEnter the seat type you want (1 for W, 2 for N and 3 for C): ");
  scanf("%d",&new.seat_type);
  switch(new.seat_type) {
  case 1: if (seatLeft(w_seats) >= new.quantity) {
      for (int i = 0; i< new.quantity ;i++) {
        new.reserved_seats[i] = front(w_seats);
        w_seats = dequeue(w_seats);
      } requests = insert_before (requests, requests, new);
    } else printf("\nNot enough seats left, please try again.");
    break;
  case 2:  if (seatLeft(c_seats) >= new.quantity) {
      for (int i = 0; i< new.quantity ;i++) {
        new.reserved_seats[i] = front(c_seats);
        c_seats = dequeue(c_seats);
      } requests = insert_before (requests, requests, new);
    } else printf("\nNot enough seats left, please try again.");
    break;
  case 3:  if (seatLeft(n_seats) >= new.quantity) {
    for (int i = 0; i< new.quantity ;i++) {
      new.reserved_seats[i] = front(n_seats);
      n_seats = dequeue(n_seats);
    } requests = insert_before (requests, requests, new);
  } else printf("\nNot enough seats left, please try again.");
    break;
  }
}

void cancelRequest() {
  char name[100];
  printf("\nEnter your name: ");
  scanf(" %[^\n]s",name);
  node_t tmp = find(requests,name);
  if (tmp != NULL) {
    switch ((tmp->data).seat_type) {
    case 1: for (int i = 0; i< (tmp->data).quantity; i++) {
        w_seats = enqueue(w_seats,(tmp->data).reserved_seats[i]);
      } break;
    case 2: for (int i = 0; i< (tmp->data).quantity; i++) {
        c_seats = enqueue(c_seats,(tmp->data).reserved_seats[i]);
    } break;
    case 3:  for (int i = 0; i< (tmp->data).quantity; i++) {
        n_seats = enqueue(n_seats,(tmp->data).reserved_seats[i]);
        } break;
    }
    requests = remove_at(requests,tmp);
    printf("\nYour request has been cancelled!");
  } else printf("\nName not found, please try again.");
}

void cleanUp() {
  free_queue(w_seats);
  free_queue(c_seats);
  free_queue(n_seats);
  free_list(requests);
}

void printRequest() {
  node_t p = requests;
  while (p != NULL) {
    printf("\nName: %s\nQuantity:%d\nSeat type: %d\n",p->data.name,p->data.quantity,p->data.seat_type);
    for (int i = 0; i< p->data.quantity; i++) {
      printf("%d%c ",p->data.reserved_seats[i].row,p->data.reserved_seats[i].col);
    }
    p = p->next;
  }
}

void searchRequest() {
  char name[100];
  printf("\nEnter your name: ");
  scanf(" %[^\n]s",name);
  node_t tmp = find(requests,name);
  if (tmp != NULL) {
    while (tmp != NULL) {
      printf("\n%s %d %d\n",tmp->data.name,tmp->data.quantity,tmp->data.seat_type);
      for (int i = 0; i< tmp->data.quantity; i++) {
        printf("%d%c ",tmp->data.reserved_seats[i].row,tmp->data.reserved_seats[i].col);
      }
    }
  } else printf("\nName not found, please try again");
}



int main() {
  int y=0;
  initialize();
  while (y!= 5) {
    showMenu();
    scanf("%d",&y);
    switch (y) {
    case 1: makeRequest(); break;
    case 2: cancelRequest(); break;
    case 3: printRequest(); break;
    case 4: searchRequest(); break;
    case 5: printf("Goodbye\n"); break;
    }
  }
  cleanUp();
  
}
