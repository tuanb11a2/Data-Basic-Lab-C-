#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dangky.h"

int main() {
    MonHocDB monhoc_new;
    DangKyDB dangky_new;
    MonHocDB monhoc_list,tmp_monhoc,monhoc_new_list,tmp_dsmh,tmp_monhoc2;
    DangKyDB dangky_list,tmp_dangky;
    int n,i,hk1,hk2;
    hk1 = hk2 = 0;
    char dangky_id[10];
    char monhoc_id[10];
    char filename[50];
    printf("\t\t\tMENU\n\n");
    printf("\t1-Nhap du lieu tu tep tin\n\t2-Them 1 mon hoc moi\n\t3-Them 1 dang ky moi\n\t4-Tim sinh vien theo mon hoc dang ky\n\t5-Tinh tong tin chi\n\t6-Ghi ra mot van ban moi\n\t7-Thoat chuong trinh\n");
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
                printf("Nhap ten file mon hoc:\n");
                scanf("%s",filename);
                monhoc_list = read_mhdb(filename);
                tmp_monhoc = monhoc_list;
                printf("Nhap ten file dang ky:\n");
                scanf("%s",filename);
                dangky_list = read_dkdb(filename);
                tmp_dangky = dangky_list;
                printf("Mon hoc\tSo tin chi\tHoc ky\n");
                printf("------------------------------------------------------\n");
                while(tmp_monhoc != NULL){
                    printf("%s\t%d\t\t%d\n",tmp_monhoc->id,tmp_monhoc->so_tin_chi,tmp_monhoc->hoc_ky);
                    tmp_monhoc = tmp_monhoc->next;
                }
                printf("------------------------------------------------------\n");
                while(tmp_dangky != NULL){
                    tmp_dsmh = tmp_dangky->dsmh;
                    printf("%s\t\t",tmp_dangky->id);
                    for(i = 0;i< tmp_dangky->so_mon_hoc;i++){
                        while(tmp_dsmh != NULL){
                            printf("%s -",tmp_dsmh->id);
                            tmp_dsmh = tmp_dsmh->next;
                        }
                    }
                    printf("\n");
                    tmp_dangky = tmp_dangky->next;
                }
            }
		    	
			if(n==2){
                monhoc_new = (MonHocDB)malloc(sizeof(struct MonHocNode));
                printf("Enter the id:");
                scanf(" %[^\n\t]s",monhoc_new->id);
                while(1){
                    if(find_mh_by_id(monhoc_list,monhoc_new->id) != NULL){
                        printf("Already exists!\n");
                        printf("Enter again:\n");
                        scanf(" %[^\n\t]s",monhoc_new->id);
                    }
                    else{
                        break;
                    }
                }
                printf("Enter so tin chi:");
                scanf("%d",&monhoc_new->so_tin_chi);
                printf("Enter hoc ky:");
                scanf("%d",&monhoc_new->hoc_ky);
                monhoc_list = append_mh(monhoc_list,monhoc_new);
                tmp_monhoc = monhoc_list;
                tmp_dangky = dangky_list;
                printf("Mon hoc\tSo tin chi\tHoc ky\n");
                printf("------------------------------------------------------\n");
                while(tmp_monhoc != NULL){
                    printf("%s\t%d\t\t%d\n",tmp_monhoc->id,tmp_monhoc->so_tin_chi,tmp_monhoc->hoc_ky);
                    tmp_monhoc = tmp_monhoc->next;
                }
                printf("------------------------------------------------------\n");
                while(tmp_dangky != NULL){
                    tmp_dsmh = tmp_dangky->dsmh;
                    printf("%s\t\t",tmp_dangky->id);
                    for(i = 0;i< tmp_dangky->so_mon_hoc;i++){
                        while(tmp_dsmh != NULL){
                            printf("%s -",tmp_dsmh->id);
                            tmp_dsmh = tmp_dsmh->next;
                        }
                    }
                    printf("\n");
                    tmp_dangky = tmp_dangky->next;
                }


               
            }
			
			if(n==3){
                // monhoc_new = (MonHocDB)malloc(sizeof(struct MonHocNode));
                // monhoc_new_list = create_list_mh();
                // dangky_new = (DangKyDB)malloc(sizeof(struct DangKyNode));
                // printf("Enter the id:");
                // scanf(" %[^\n\t]s",dangky_new->id);
                // if(find_dk_by_id(dangky_list,dangky_new->id) != NULL){
                //     tmp_dangky = dangky_list;
                //     printf("Enter mon hoc:");
                //     scanf(" %[^\n\t]s",monhoc_new->id);
                //     while(1){
                //         if(find_mh_by_id(monhoc_list,monhoc_new->id) == NULL){
                //             printf("Not exists!\n");
                //             printf("Enter again:");
                //             scanf(" %[^\n\t]s",monhoc_new->id);
                //         }
                //         else{
                //             while(tmp_dangky != NULL){
                //                 if(tmp_dangky->id == dangky_new->id){
                //                 tmp_dangky->dsmh = append_mh(tmp_dangky->dsmh,monhoc_new);
                //                 tmp_dangky->so_mon_hoc++;
                //                 break;
                //             }else{
                //                 tmp_dangky = tmp_dangky->next;
                //                 }
                //             }
                //             break;
                //         }
                //     }
                    
                // }
                // else{
                //     printf("Enter mon hoc:");
                //     scanf(" %[^\n\t]s",monhoc_new->id);
                //     while(1){
                //         if(find_mh_by_id(monhoc_list,monhoc_new->id) == NULL){
                //             printf("Not exists!\n");
                //             printf("Enter again:");
                //             scanf(" %[^\n\t]s",monhoc_new->id);
                //         }
                //         else{
                //             monhoc_new_list = append_mh(monhoc_new_list,monhoc_new);
                //             break;
                //         }
                //     }
                //     dangky_list->dsmh = monhoc_new_list;
                //     dangky_list = append_dk(dangky_list,dangky_new);

                // }  
                // tmp_monhoc = monhoc_list;
                // tmp_dangky = dangky_list;
                // printf("Mon hoc\tSo tin chi\tHoc ky\n");
                // printf("------------------------------------------------------\n");
                // while(tmp_monhoc != NULL){
                //     printf("%s\t%d\t\t%d\n",tmp_monhoc->id,tmp_monhoc->so_tin_chi,tmp_monhoc->hoc_ky);
                //     tmp_monhoc = tmp_monhoc->next;
                // }
                // printf("------------------------------------------------------\n");
                // while(tmp_dangky != NULL){
                //     tmp_dsmh = tmp_dangky->dsmh;
                //     printf("%s\t\t",tmp_dangky->id);
                //     for(i = 0;i< tmp_dangky->so_mon_hoc;i++){
                //         while(tmp_dsmh != NULL){
                //             printf("%s -",tmp_dsmh->id);
                //             tmp_dsmh = tmp_dsmh->next;
                //         }
                //     }
                //     printf("\n");
                //     tmp_dangky = tmp_dangky->next;
                // }
            }
			
			if(n==4){
                printf("Nhap 1 mon hoc: ");
                scanf(" %[^\n\t]s",monhoc_id);
                if(find_mh_by_id(monhoc_list,monhoc_id) == NULL){
                    printf("Khong tim thay mon hoc!");
                }else{
                    printf("Sinh vien dang ky mon hoc nay la:\n");
                    tmp_dangky = dangky_list;
                    while(tmp_dangky != NULL){
                        while(tmp_dangky->dsmh != NULL){
                                if(strcmp(tmp_dangky->dsmh->id,monhoc_id) == 0){
                                    printf("%s\n",tmp_dangky->id);
                                    break;
                                }else{
                                    tmp_dangky->dsmh = tmp_dangky->dsmh->next;
                                }
                            }
                        tmp_dangky = tmp_dangky->next;
                    }
                }
            }
			
			if(n==5){
                tmp_dangky = dangky_list;
                printf("Enter sinh vien:");
                scanf(" %[^\n\t]s",dangky_id);
                if(find_dk_by_id(tmp_dangky,dangky_id) == NULL){
                        printf("Dont't exists!\n");
                }else{
                    tmp_monhoc2 = find_dk_by_id(tmp_dangky,dangky_id)->dsmh;
                    while(tmp_monhoc2 != NULL){
                        tmp_monhoc = monhoc_list;
                        while(tmp_monhoc != NULL){
                            if(strcmp(tmp_monhoc->id,tmp_monhoc2->id) == 0){
                                if(tmp_monhoc->hoc_ky == 1){
                                    hk1 = hk1 + tmp_monhoc->so_tin_chi;
                                }else if(tmp_monhoc->hoc_ky == 2){
                                    hk2 = hk2 + tmp_monhoc->so_tin_chi;
                                }
                            }
                            tmp_monhoc = tmp_monhoc->next;
                        }
                        tmp_monhoc2 = tmp_monhoc2->next;
                    }
                }
                printf("Hoc ky 1:%d\n",hk1);
                printf("Hoc ky 2:%d\n",hk2);
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
	    printf("\t1-Nhap du lieu tu tep tin\n\t2-Them 1 mon hoc moi\n\t3-Them 1 dang ky moi\n\t4-Tim sinh vien theo mon hoc dang ky\n\t5-Tinh tong tin chi\n\t6-Ghi ra mot van ban moi\n\t7-Thoat chuong trinh\n");
	    }
    }
  
  return 0;
}
