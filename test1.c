//TEST
#include<stdio.h>
int main(){
    char c;
    printf("Nhap 1 chu:");
    scanf("%c",&c);
    switch(c){
        case "a","b":
            printf("a va b\n");
            break;
        default:
            printf("Khong phai a va b");
            break;
    }
    return 0;
}