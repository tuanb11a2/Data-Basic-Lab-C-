#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAcc.h"

int main(){
    char filename[50];
    int n;
    AccountDB exist_node,exist_node1,exist_node2;
    tree account_tree;
    struct Account new_account,account1,account2;
    account_tree = (tree)NULL;
    printf("\t\t\tMENU\n\n");
    printf("\t1-Nhap du lieu tu tep tin\n\t2-Sap xep\n\t3-add new\n\t4-data analysis\n\t5-Thoat chuong trinh\n");
    while (1)
    {
        printf("Nhap su lua chon cua ban\n");
		scanf("%d",&n);
        while(n<0||n>5){
        printf("Nhap lai su lua chon cua ban\n");
		scanf("%d",&n);
	    }
        if(0<=n&&n<=5)
		{
            if(n==1){
                printf("Enter the name of the file:\n");
                scanf("%s",filename);
                account_tree = read_account(filename);
                //DPS_InOrder(account_tree);
            }
            if(n==2){
                DPS_InOrder(account_tree);
            }
            if(n==3){
                printf("Enter id:");
                scanf("%s",new_account.id);
                printf("Enter name:");
                scanf("%s",new_account.name);
                int i,status = 0;
                for(i = 0; i < strlen(new_account.name);i ++){
                    if(new_account.name[i] == '@'){
                        status = 1;
                    }
                }
                if(status == 1){
                    printf("Enter again:");
                    scanf("%s",new_account.name);
                }
                printf("Enter electronic cost:");
                scanf("%ld",&new_account.elec_cost);
                while(new_account.elec_cost < 0){
                    printf("Enter again:");
                    scanf("%ld",new_account.elec_cost);
                }
                printf("Enter fashion cost:");
                scanf("%ld",&new_account.fashion_cost);
                while(new_account.fashion_cost < 0){
                    printf("Enter again:");
                    scanf("%ld",new_account.fashion_cost);
                }
                if(findNodebyname(account_tree,new_account.id) != NULL){
                    account_tree = appendTreeNode(account_tree,new_account);
                    printf("Success!");
                }else{
                    account_tree = insertNode(account_tree,new_account);
                    printf("Success!");
                }

            }
            
            if(n==4){
                long int totalPaymentFas(tree t,long int cost) {
					int i;
					if (isNullTree(t))
						return 0;
					for(i = 0;i< t->total;i++){
						cost = cost + t->accounts[i].fashion_cost;
					}
					return (cost + totalPaymentFas(t->left,0) + totalPaymentFas(t->right,0));

                    }
                long int totalPaymentElec(tree t,long int cost) {
					int i;
					if (isNullTree(t))
						return 0;
					for(i = 0;i< t->total;i++){
						cost = cost + t->accounts[i].elec_cost;
					}
					return (cost + totalPaymentFas(t->left,0) + totalPaymentFas(t->right,0));

                    }
                int totalElecNum(tree t){
                    if(isNullTree(t))
                        return 0;
                    return(t->elec_num + totalElecNum(t->left) + totalElecNum(t->right));
                }
                int totalFashionNum(tree t){
                    if(isNullTree(t))
                        return 0;
                    return(t->fashion_num + totalFashionNum(t->left) + totalFashionNum(t->right));
                }
				printf("Fashion payment:%d\n",totalPaymentFas(account_tree,0));
                printf("Electric payment:%d\n",totalPaymentElec(account_tree,0));
                printf("Total electric number:%d\n",totalElecNum(account_tree));
                printf("Total fashion number:%d\n",totalFashionNum(account_tree));
			}   
        
            if(n==5){
                deleteAccTree(account_tree);
                printf("Ban da thoat chuong trinh!\n");
                break;
            }

        }
        printf("\t\t\tMENU\n\n");
        printf("\t1-Nhap du lieu tu tep tin\n\t2-Sap xep\n\t3-add new\n\t4-data analysis\n\t5-Thoat chuong trinh\n");

    }
    return 0;
}