#include <stdio.h>
#include "stack-list.h"

int main(void) {
    char str[10];
    char c;
    int ch;
    int n = 0;
    int i;
    int a,b;
    stack s = create_stack();

    printf("Nhap 1 bieu thuc:");
    while ((c = getchar()) != '\n' && n < 5) {
      str[n] = c;
      n++;
    }

    for (i = 0; i < n; i++){
        ch = str[i];
        if(ch > 47 && ch < 58){
            push(s,str[i]-'0');
        }else{
            a = top(s);
            pop(s);
            b = top(s);
            pop(s);
            ch = str[i];
            switch (ch)
            {
            case 43:
                a = a+b;
                push(s,a);
                break;
            case 45:
                a = b-a;
                push(s,a);
                break;
            case 42:
                a = a*b;
                push(s,a);
                break;
            case 47:
                a = b/a;
                push(s,a);
                break;
            default:
                printf("Invalid operator!");
                break;
            }
        }
    }

    a = top(s);
    pop(s);
    if(is_empty(s)){
        printf("The result:%d",a);
    }else{
        printf("Invalid input!");
    }
    
     
    return 0;

}
