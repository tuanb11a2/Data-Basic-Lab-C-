#include<stdio.h>
#include<stdlib.h>
//#include "seat_queue.h"
#include "request_list.h"

int main(void){
    list request = create_list();
    int qty,n,type;
    char s[100];
    element_t x;
    node_t tmp;
    

    while(1){
        printf("\t\tMENU\n");
        printf("\t1.Add a ticker\n");
        printf("\t2.Cancel a ticker\n");
        printf("\t3.Modify a ticker\n");
        printf("\t4.Exit\n");
        printf("Choose your option:\n");
        scanf("%d",&n);
        if(n == 1){
            printf("\t\tEnter the information:\n");
            printf("\tName:");
            scanf("%s",x.name);
            printf("%s\n",x.name);
            printf("\tQuantity:");
            scanf("%d",&x.quantity);
            printf("%d\n",x.quantity);
            printf("\tSeat type:");
            scanf("%d",&x.seat_type);
            printf("%d\n",x.seat_type);
            insert_after(request,request,x);
            while (!is_empty(request))
            {
                request = request->next;
                printf("Name:%s\n",request->data.name);
                printf("Quantity:%d\n",request->data.quantity);
                printf("Seat_type:%d\n",request->data.seat_type);
            }
            
        }
        if(n == 2){
            printf("\tEnter your name for ticket:");
            scanf("%s",s);
            if(find(request,s)){
                tmp = find(request,s);
                remove_at(request,tmp);
            }
        }
        if(n == 3){
            printf("\tEnter your name for ticket:");
            scanf("%s",s);
            if(find(request,s)){
                tmp = find(request,s);
                modify_at(request,tmp);
            }
        }
        if(n == 4){
            break;
        }
    }
    return 0;
}