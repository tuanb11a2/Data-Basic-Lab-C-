#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tuyenxe.h"

int main() {
    DiemDoDB diemdo_new;
    TuyenXeDB tuyenxe_new;
    DiemDoDB diemdo_list,tmp_diemdo;
    TuyenXeDB tuyenxe_list,tmp_tuyenxe;
    int n,i;
    char diemdo_id[10];
    char filename[50];
    printf("\t\t\tMENU\n\n");
    printf("\t1-Nhap du lieu tu tep tin\n\t2-Them 1 diem den moi\n\t3-Them 1 tuyen xe moi\n\t4-Tim tuyen xe theo diem do\n\t5-Tim sach theo nam xuat ban\n\t6-Ghi ra mot van ban moi\n\t7-Thoat chuong trinh\n");
	while(1){
		printf("Nhap su lua chon cua ban\n");
		scanf("%d",&n);
		while(n<0||n>7)
		{
            printf("Nhap lai su lua chon cua ban\n");
		    scanf("%d",&n);
		}
		if(0<=n&&n<=7)
		{
		    if(n==1){ 
                printf("Nhap ten file diem do:\n");
                scanf("%s",filename);
                diemdo_list = read_dddb(filename);
                tmp_diemdo = diemdo_list;
                //print_dd(diemdo_list);
                printf("Nhap ten file tuyen xe:\n");
                scanf("%s",filename);
                tuyenxe_list = read_txdb(filename);
                tmp_tuyenxe = tuyenxe_list;
                //print_tx(tuyenxe_list);
                printf("DiemDo\t\tToa do\n");
                printf("------------------------------------------------------\n");
                while(tmp_diemdo != NULL){
                    printf("%s\t\t(%d,%d)\n",tmp_diemdo->id,tmp_diemdo->x,tmp_diemdo->y);
                    tmp_diemdo = tmp_diemdo->next;
                }
                printf("------------------------------------------------------\n");
                while(tmp_tuyenxe != NULL){
                    printf("%s\t\t",tmp_tuyenxe->id);
                    for(i = 0;i< tmp_tuyenxe->soDiemDo;i++){
                        printf("%s -",tmp_tuyenxe->dsDiemDo[i].id);
                    }
                    printf("\n");
                    tmp_tuyenxe = tmp_tuyenxe->next;
                }
            }
		    	
			if(n==2){
                diemdo_new = (DiemDoDB)malloc(sizeof(struct DiemDoNode));
                printf("Enter the id:");
                scanf(" %[^\n\t]s",diemdo_new->id);
                while(1){
                    if(find_dd_by_id(diemdo_list,diemdo_new->id) != NULL){
                        printf("Already exists!\n");
                        printf("Enter again:\n");
                        scanf(" %[^\n\t]s",diemdo_new->id);
                    }
                    else{
                        break;
                    }
                }
                printf("Enter x:");
                scanf("%d",&diemdo_new->x);
                printf("Enter y:");
                scanf("%d",&diemdo_new->y);
                diemdo_list = append_dd(diemdo_list,diemdo_new);
                print_dd(diemdo_list);
               
            }
			
			if(n==3){
                tuyenxe_new = (TuyenXeDB)malloc(sizeof(struct TuyenXeNode));
                printf("Enter the id:");
                scanf(" %[^\n\t]s",tuyenxe_new->id);
                while(1){
                    if(find_tx_by_id(tuyenxe_list,tuyenxe_new->id) != NULL){
                        printf("Already exists!\n");
                        printf("Enter again:");
                        scanf(" %[^\n\t]s",tuyenxe_new->id);
                    }
                    else{
                        break;
                    }
                }
                printf("Enter the number:");
                scanf("%d",&tuyenxe_new->soDiemDo);
                for(i = 0;i< tuyenxe_new->soDiemDo;i++){
                    printf("Enter diem den");
                    scanf(" %[^\n\t]s",tuyenxe_new->dsDiemDo[i].id);
                    while(1){
                        if(find_dd_by_id(diemdo_list,tuyenxe_new->dsDiemDo[i].id) == NULL){
                            printf("Not exists!\n");
                            printf("Enter again:");
                            scanf(" %[^\n\t]s",tuyenxe_new->dsDiemDo[i].id);
                        }
                        else{
                            break;
                        }
                    }
                }
                tuyenxe_list = append_tx(tuyenxe_list,tuyenxe_new);
                print_tx(tuyenxe_list);
            }
			
			if(n==4){
                printf("Nhap 1 ma diem do: ");
                scanf(" %[^\n\t]s",diemdo_id);
                if(find_dd_by_id(diemdo_list,diemdo_id) == NULL){
                    printf("Khong tim thay diem do!");
                }else{
                    printf("Tuyen xe co diem do nay la:\n");
                    tmp_tuyenxe = tuyenxe_list;
                    while(tmp_tuyenxe != NULL){
                        for(i = 0;i< tmp_tuyenxe->soDiemDo;i++){
                            if(strcmp(tmp_tuyenxe->dsDiemDo[i].id,diemdo_id) == 0){
                                printf("%s\n",tmp_tuyenxe->id);
                            }
                        }
                        tmp_tuyenxe = tmp_tuyenxe->next;
                    }
                }
            }
			
			if(n==5){

            }
			
			if(n==6){
				// printf("Enter the file name:\n");
                // scanf("%s",filename);
                // list = write_db(filename,list);			
			}

            if(n==7){
			printf("Ban da thoat chuong trinh\n");
			break;					
			}

	    printf("\t\t\tMENU\n\n");
	    printf("\t1-Nhap du lieu tu tep tin\n\t2-Them 1 diem den moi\n\t3-Them 1 tuyen xe moi\n\t4-Tim tuyen xe theo diem do\n\t5-Tim sach theo nam xuat ban\n\t6-Ghi ra mot van ban moi\n\t7-Thoat chuong trinh\n");
	    }
    }
  
  return 0;
}
