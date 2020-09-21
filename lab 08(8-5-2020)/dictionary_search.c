#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct address_t
{
    char name[50];
    char phone[20];
    char email[50];
}address;

int count = 0;
address dictionary[100];

void add_new(){
    if(count < 100)
    {
        printf("Number %d\n",count+1);
        printf("New name:");
        scanf(" %[^\n\t]s",dictionary[count].name);
        printf("New name is:%s\n",dictionary[count].name);

        printf("New phone:");
        scanf(" %[^\n\t]s",dictionary[count].phone);
        printf("New phone is:%s\n",dictionary[count].phone);

        printf("New email:");
        scanf(" %[^\n\t]s",dictionary[count].email);
        printf("New email is:%s\n",dictionary[count].email);

        count ++;
    }
}

void search(char* key){
    int i,state;
    i = state = 0;
    while (i < count)
    {
        if(strcmp(key,dictionary[i].name) == 0){
            printf("Found!\n");
            printf("The info:\n");
            printf("Name is:%s\n",dictionary[i].name);
            printf("Phone is:%s\n",dictionary[i].phone);
            printf("Email is:%s\n",dictionary[i].email);
            state = 1;
            break;
        }else{
            i++;
        }
    }
 
    if(state == 0){
        printf("Not found!");
    }
}

int main(void)
{
    int n;
    char key[50];
    printf("Number of new:");
    scanf("%d",&n);
    while (n > 0)
    {
        add_new();
        n--;
    }

    printf("Enter the key for searching:");
    scanf("%s",key);
    search(key);
    
}
