#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void compare_list(list list1,list list2){
    node_t tmp1,tmp2;
    tmp1 = list1;
    tmp2 = list2;
    printf("The common node:");
    while (tmp1 != NULL)
    {   
        while (tmp2 != NULL)
        {
            if(tmp1->data == tmp2->data){
                printf("\n%d",tmp1->data);
                break;
            }else{
                tmp2 = tmp2->next;
            }
        }
        tmp2 = list2;
        tmp1 = tmp1->next;
    }
}

int main(void){
    list list1 = create_list();
    list list2 = create_list();

    list1 = insert_after(list1,list1,22);
    list1 = insert_after(list1,list1,9);
    list1 = insert_after(list1,list1,2019);

    list2 = insert_after(list2,list2,22);
    list2 = insert_after(list2,list2,9);
    list2 = insert_after(list2,list2,1996); 

    compare_list(list1,list2);
}

