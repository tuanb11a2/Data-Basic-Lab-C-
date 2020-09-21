#include<stdio.h>
#include<stdlib.h>
#include "request_list.h"

//Note that how to implement struct as data

list create_list(){
    list l =(list)malloc(sizeof(list));
    l->next = NULL;
    return l;
}

int is_empty(list l){
    return (l->next == NULL);
}

//search
node_t find(list l,char* name){
    node_t tmp;
    tmp = l->next;
    if(is_empty(l)){
        return NULL;
    }else{
        while(tmp!= NULL){
            if(tmp->data.name == name){
                break;
            }else{
                tmp = tmp->next;
            }
        }
        return tmp;
    }
}


//insert
list insert_after(list l,node_t p, element_t x){
    node_t new = (node_t)malloc(sizeof(node_t));
    new->next = NULL;
    new->data = x;
    if(find(l,p->data.name) != NULL){
        new->next = p->next;
        p->next = new;
    }
    return l;
}

//remove
list remove_at(list l,node_t p){
    node_t tmp;
    tmp = l;
    if(find(l,p->data.name) != NULL){
        while(tmp->next != NULL){
            if(tmp->next == p){
                break;
            }else{
                tmp = tmp->next;
            }
        }

        tmp->next = p->next;
        free(p);
    }else{
        printf("Can't find that node!\n");
    }
    return l;
}

//first node
node_t first(list l){
    if(l->next != NULL){
        return l->next;
    }else{
        return NULL; 
    }
}

//last node
node_t last(list l){
    node_t tmp;
    tmp=l;
    while(tmp != NULL){
        if(tmp->next == NULL){
            return tmp;
            break;
        }else{
            tmp = tmp->next;
        }
    }
}

//modify node
list modify_at(list l,node_t p){
    node_t tmp;
    tmp = l;
    if(find(l,p->data.name) != NULL){
        while(tmp->next != NULL){
            if(tmp == p){
                printf("\t\tEnter the information:");
                printf("\tName:\n");
                scanf("%s",tmp->data.name);
                printf("\tQuantity:");
                scanf("%d",&tmp->data.quantity);
                printf("\tSeat type:");
                scanf("%d",&tmp->data.seat_type);
                printf("Successful change!");
                break;
            }else{
                tmp = tmp->next;
            }
        }
    }else{
        printf("Can't find that node!\n");
    }
    return l;
}