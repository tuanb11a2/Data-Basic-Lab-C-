//BTVN
#include <stdio.h>
#include "stack-list.h"
int count = 0;

//Operator "+","-" are level 0
//Operator "*","/" are level 1
//Operator "^" are level 2
//"()" are level 3

void stack_traversal_level_0(stack s,element_t x){
    char c;
    stack tmp;
    tmp = s->next;
    if(is_empty(s)){
        push(s,x);
    }else{
        while(tmp != NULL){
            switch(tmp->data){
                case '+':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '-':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '*':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '/':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '(':
                    push(s,x);
                    tmp = NULL;
                    break;
                case '^':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                default:
                    break;
            } 
        }
        if(is_empty(s)){
            push(s,x);
        }
    }
}

void stack_traversal_level_1(stack s,element_t x){
    char c;
    stack tmp;
    tmp = s->next;
    if(is_empty(s)){
        push(s,x);
    }else{
        while(tmp != NULL){
            switch(tmp->data){
                case '+':
                    push(s,x);
                    tmp=tmp->next;
                    break;
                case '-':
                    push(s,x);
                    tmp=tmp->next;
                    break;
                case '*':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '/':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '(':
                    push(s,x);
                    tmp = NULL;
                    break;
                case '^':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                default:
                    break;
            } 
        }
        if(is_empty(s)){
            push(s,x);
        }
    }
}

void stack_traversal_level_3(stack s,element_t x){
    char c;
    stack tmp;
    tmp = s->next;
    if(is_empty(s)){
        push(s,x);
    }else{
        while(tmp != NULL){
            switch(tmp->data){
                case '+':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '-':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '*':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '/':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                case '(':
                    pop(s);
                    tmp = tmp->next;
                    count--;
                    break;
                case '^':
                    printf("%c",tmp->data);
                    tmp = tmp->next;
                    pop(s);
                    count--;
                    break;
                default:
                    break;
            } 
        }
    }
}

int main(void) {
    char str[20];
    char c;
    int ch;
    int n = 0;
    int i;
    int a,b;
    stack s = create_stack(); //Operator stack

    printf("Nhap 1 bieu thuc:");
    while ((c = getchar()) != '\n' && n < 20) {
      str[n] = c;
      n++;
    }

    printf("Bieu thuc hau to:");
    for (i = 0; i < n; i++){
        ch = str[i];
        c = str[i];
        if(ch > 47 && ch < 58){
            printf("%c",str[i]);
            count++;
        }else{
            switch (c)
            {
            case '+':
                stack_traversal_level_0(s,str[i]);
                break;
            case '-':
                stack_traversal_level_0(s,str[i]);
                break;
            case '*':
                stack_traversal_level_1(s,str[i]);
                break;
            case '/':
                stack_traversal_level_1(s,str[i]);
                break;
            case '(':
                push(s,str[i]);
                break;
            case ')':
                stack_traversal_level_3(s,str[i]);
                break;
            case '^':
                push(s,str[i]);
                break;
            default:
                printf("Invalid operator!");
                break;
            }
        }
    }

    while(!is_empty(s) && count>1){
        c = top(s);
        printf("%c",c);
        pop(s);
        count--;
    }

    //printf("\nCount:%d",count);
     
    if(is_empty(s)){
        printf("\nOk!\n");
    }else{
        printf("\nInvalid input!");
    }
    return 0;

}
