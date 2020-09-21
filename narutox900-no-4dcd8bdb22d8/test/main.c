#include <stdio.h>
#include <stdlib.h>
#include "dangky.h"
#include <string.h>

MonHocDB mhdb;
DangKyDB dkdb;

void inputMH(){
  int flag =1;
  char id[10];
  int so_tc;
  int hk;
  do {
    flag =1;
    printf("Enter mon hoc ID: ");
    scanf(" %s",id);
    printf("Enter so tin chi: ");
    scanf("%d",&so_tc);
    printf("Enter hoc ky: ");
    scanf("%d",&hk);
    MonHocDB tmp = mhdb;
    while (tmp!= NULL) {
      if (strcmp(tmp->id,id)==0) {
        break;
      }
      else tmp = tmp->next;
    }
    if (tmp != NULL) {
      flag =0;
      printf("Mon hoc bi trung ID\n");
    }

  //if (tmp == NULL) {}
  //else {
  //  flag = 0;
  // printf("Mon hoc bi trung ID, yeu cau nhap lai!\n");
  //}
  } while(flag == 0);
  mhdb = append_mh(mhdb,id,so_tc,hk);
}

void inputSV(){
  int flag = 1;
  char id[10];
  int soMH;
  char id2[10];
  MonHocDB head = NULL;
  do {
    flag = 1;
    printf("Enter sinh vien ID: ");
    scanf(" %s",id);
    printf ("Enter ma mon hoc: ");
    scanf(" %s",id2);
    DangKyDB dk = dkdb;
    while (dk!= NULL) {
      if (strcmp(dk->id,id) == 0) {
        break;
      }
      else dk = dk->next;
    }
    if (dk!= NULL) {
      head = mhdb;
      while (head != NULL) {
        if (strcmp(head->id,id2)==0) {
          break;
        }
        else head =head->next;
      }
      if (head != NULL) {
        dk->dsmh= append_mh(dk->dsmh,id2,head->so_tc,head->hk);
      } else {
        printf("Mon hoc khong ton tai\n");
        flag =0;
      }
    } else {
      printf("Sinh vien khong ton tai\n");
      flag =0;
    }
  } while (flag ==0 );
}


void findSV(){
  char id[10];
  int flag = 0;
  printf("Enter mon hoc id: ");
  scanf(" %s",id);
  MonHocDB tmp = mhdb;
  DangKyDB tmp1 =dkdb;
  while (tmp->next != NULL && strcmp(id,tmp->id) != 0) {
    tmp = tmp ->next;
  }
  if (strcmp(id,tmp->id) == 0) {
    while (tmp1 != NULL) {
      MonHocDB tmp2 = tmp1->dsmh;
      while (tmp2->next != NULL && strcmp(id,tmp2->id) != 0) {
        tmp2 = tmp2 ->next;
      }
      if (strcmp(id,tmp2->id) == 0){
        printf("%-10s",tmp1->id);
      }
      tmp1=tmp1->next;
    }
  }  else {
    printf("Khong ton tai mon hoc\n");
  }
  printf("\n");
}

void calTC(){
  DangKyDB tmpdk = NULL;
  char id[10];
  printf("Enter ma sinh vien: ");
  scanf(" %s",id);
  tmpdk = find_dk_by_id(dkdb,id);
  if (tmpdk!=NULL) {
      MonHocDB tmpmh = tmpdk->dsmh;
      int ky1=0;
      int ky2=0;
      while (tmpmh!=NULL) {
        if (tmpmh->hk == 1) {
          ky1 += tmpmh->so_tc;
        } else ky2 += tmpmh->so_tc;
        tmpmh= tmpmh->next;
      }
      printf("Ky 1: %d\nKy 2: %d\n",ky1,ky2);
    }
}


void showMenu() {
  printf("\n__________________MENU___________________\n");
  printf("Choose an option to perform:\n");
  printf("1. Read data \n");
  printf("2. Input mon hoc\n");
  printf("3. Input sinh vien\n");
  printf("4. Print all info\n");
  printf("5. Tim sinh vien theo mon hoc\n");
  printf("6. Tinh so tin chi\n");
  printf("0. Exit\n");
}

int main() {
  int flag= 1;
  while (flag!=0) {
    showMenu();
    scanf("%d",&flag);
    switch (flag) {
    case 1: mhdb = read_mb("MONHOC.txt");
      dkdb = read_dk("DANGKY.txt",mhdb);
      break;
    case 2:inputMH(); break;
    case 3:inputSV(); break;
    case 4: printMonHoc(mhdb);
      printDangKy(dkdb);
      break;
    case 5: findSV();
      break;
    case 6: calTC();
    case 0: break;
    }
  }
}
