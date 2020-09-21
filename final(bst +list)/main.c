#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transaction.h"

int main(){
    char filename[50];
    int n;
    AccountDB exist_node,exist_node1,exist_node2;
    tree account_tree;
    struct Account new_account,account1,account2;
    account_tree = (tree)NULL;
    printf("\t\t\tMENU\n\n");
    printf("\t1-Nhap du lieu tu tep tin\n\t2-Them 1 account moi\n\t3-Tim kiem thong tin tai khoan\n\t4-Chuyen tien\n\t5-Xoa account\n\t6-Ghi ra mot van ban moi\n\t7-Thoat chuong trinh\n");
    while (1)
    {
        printf("Nhap su lua chon cua ban\n");
		scanf("%d",&n);
        while(n<0||n>7){
        printf("Nhap lai su lua chon cua ban\n");
		scanf("%d",&n);
	    }
        if(0<=n&&n<=7)
		{
            if(n==1){
                printf("Enter the name of the file:\n");
                scanf("%s",filename);
                account_tree = read_account(filename);
                DPS_InOrder(account_tree);
            }
            // if(n==2){
            //     printf("Enter new name:");
            //     fflush(stdin);
            //     scanf("%[^\n]%*c",new_account.name);
            //     printf("Enter new phone number:");
            //     scanf("%s",new_account.telephone);
            //     if(findNodebyname(account_tree,new_account.name) != NULL){
            //         exist_node = findNodebyname(account_tree,new_account.name);
            //         int i,status;
            //         status = 0;
            //         for(i=0;i<exist_node->total;i++){
            //             if(strcmp(exist_node->accounts[i].telephone,new_account.telephone) == 0){
            //                 printf("Duplicator error!\n");
            //                 status = 1;
            //             }
            //         }
            //         if(status == 0){
            //             printf("Enter new balance:");
            //             scanf("%lf",&new_account.balance);
            //             account_tree = appendTreeNode(account_tree,new_account);
            //         }
            //     }else{
            //         printf("Enter new balance:");
            //         scanf("%lf",&new_account.balance);
            //         account_tree = insertNode(account_tree,new_account);
            //     }
            //     DPS_InOrder(account_tree);
            // }
            // if(n==3){
            //     printf("Enter the name:");
            //     fflush(stdin);
            //     scanf("%[^\n]%*c",new_account.name);
            //     if(findNodebyname(account_tree,new_account.name) != NULL){
            //         printf("Enter the phone number:");
            //         scanf("%s",new_account.telephone);
            //         exist_node = findNodebyname(account_tree,new_account.name);
            //         int i,status;
            //         status = 0;
            //         for(i=0;i<exist_node->total;i++){
            //             if(strcmp(exist_node->accounts[i].telephone,new_account.telephone) == 0){
            //                 printf("Name:%s\n",exist_node->accounts[i].name);
            //                 printf("Phone:%s\n",exist_node->accounts[i].telephone);
            //                 printf("Balance:%.2f\n",exist_node->accounts[i].balance);
            //                 status = 1;
            //             }
            //         }
            //         if(status == 0){
            //             printf("Incorrect information!\n");
            //         }
            //     }else{
            //         printf("Not found that name in db!\n");
            //     }
                
            // }
            // if(n==4){
            //     int i1,i2;
            //     double balance;
            //     printf("Enter first name:");
            //     fflush(stdin);
            //     scanf("%[^\n]%*c",account1.name);
            //     if(findNodebyname(account_tree,account1.name) != NULL){
            //         int i,status;
            //         status = 0;
            //         exist_node1 = findNodebyname(account_tree,account1.name);
            //         if(exist_node1->total>1){
            //             printf("Enter first phone number:");
            //             scanf("%s",account1.telephone);
                        
            //             for(i=0;i<exist_node1->total;i++){
            //                 if(strcmp(exist_node1->accounts[i].telephone,account1.telephone) == 0){
            //                     i1 = i;
            //                     status = 1;
            //                 }
            //             }
            //         }else{
            //             i1 = 0;
            //             status = 1;
            //         }
                    
            //         if(status == 0){
            //             printf("Incorrect information!\n");
            //         }else{
            //             //Second identity
            //     printf("Enter second name:");
            //     fflush(stdin);
            //     scanf("%[^\n]%*c",account2.name);
            //     if(findNodebyname(account_tree,account2.name) != NULL){
            //         exist_node2 = findNodebyname(account_tree,account2.name);
            //         status = 0;
            //         if(exist_node2->total>1){
            //             printf("Enter second phone number:");
            //             fflush(stdin);
            //             scanf("%[^\n]%*c",account2.telephone);
                        
            //             for(i=0;i<exist_node2->total;i++){
            //                 if(strcmp(exist_node2->accounts[i].telephone,account2.telephone) == 0){
            //                     i2 = i;
            //                     status = 1;
            //                 }
            //             }
            //         }else{
            //             i2 = 0;
            //             status = 1;
            //         }
            //         if(status == 0){
            //             printf("Incorrect information!\n");
            //         }else{
            //             //The balance
            //             printf("Enter the balance");
            //             scanf("%lf",&balance);
            //             if(balance > exist_node1->accounts[i1].balance){
            //                 printf("Not enough money!\n");
            //             }else{
            //                 exist_node1->accounts[i1].balance -= balance;
            //                 exist_node2->accounts[i2].balance += balance;
            //             }
            //         }
            //     }else{
            //         printf("Not found that name in db!\n");
            //     }
            //         }
            //     }else{
            //         printf("Not found that name in db!\n");
            //     };
            //     DPS_InOrder(account_tree);
                
            // }
            // if(n==5){
            //     printf("Enter delete name:");
            //     fflush(stdin);
            //     scanf("%[^\n]%*c",new_account.name);
            //     if(findNodebyname(account_tree,new_account.name) != NULL){
            //         exist_node = findNodebyname(account_tree,new_account.name);
            //         account_tree = deleteNode(account_tree,exist_node);
            //     }else{
            //         printf("Not found that name in db!\n");
            //     }
            //     DPS_InOrder(account_tree);
            // }
            // if(n==6){
            //     printf("Enter the name of the file:\n");
            //     scanf("%s",filename);
            //     account_tree = write_account(account_tree,filename);
            // }
            if(n==7){
                printf("Ban da thoat chuong trinh!\n");
                break;
            }

        }
        printf("\t\t\tMENU\n\n");
        printf("\t1-Nhap du lieu tu tep tin\n\t2-Them 1 account moi\n\t3-Tim kiem thong tin tai khoan\n\t4-Chuyen tien\n\t5-Xoa account\n\t6-Ghi ra mot van ban moi\n\t7-Thoat chuong trinh\n");

    }
    return 0;
}