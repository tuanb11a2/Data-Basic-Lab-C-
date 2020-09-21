//Not done function print

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct address_t
{
    char name[50];
    char phone[50];
    char email[50];
}address;
int count =0;
address address_array[100];

void add_new(){
    int tmp;
    printf("Enter the number of new you want:");
    scanf("%d",&tmp);
    if(count < 100){
    while(tmp > 0){
        printf("Enter new name:");
        scanf("%s",address_array[count].name);
        printf("New name is:%s\n",address_array[count].name);

        printf("Enter new phone:");
        scanf("%s",address_array[count].phone);
        printf("New phone is:%s\n",address_array[count].phone);

        printf("Enter new email:");
        scanf("%s",address_array[count].email);
        printf("New email is:%s\n",address_array[count].email);

        printf("Done add new!\n");
        count ++;
        tmp --;
    }
    }
    
}

void print(){
    int i;
    for(i = 0;i< count;i++){
        print("address %d\n",i+1);
        printf("Name is:%s\n",address_array[i].name);
        printf("phone is:%s\n",address_array[i].phone);
        printf("email is:%s\n",address_array[i].email);
    }
}

int search(char* key_name){
    int i;
    while (key_name != address_array[i].name)
    {
        if(i < count){
            if(key_name == address_array[i].name){
                break;
            }else{
                i++;
        }}else{
            i = -1;
            break;
        }
        
    }
    return i;
}

int main(void){
    add_new();
    print();
    search("tuan");
    
}
