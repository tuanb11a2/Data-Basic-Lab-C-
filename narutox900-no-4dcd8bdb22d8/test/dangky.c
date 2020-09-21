#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dangky.h"

MonHocDB read_mb (char* filename) {
  FILE *fin = fopen(filename,"r+");
  int n = (int)fgetc(fin) - 48;
  fgetc(fin);
  char id[10];
  int tc,hk;
  MonHocDB head = NULL;
  while(n != 0){
    fscanf(fin,"%s %d %d\n",id,&tc,&hk);
    head = append_mh(head,id,tc,hk);
    n--;
  }
  printMonHoc(head);
  return head;

}

MonHocDB append_mh (MonHocDB db, char* id, int so_tc, int hk) {
  MonHocDB n = (struct MonHocNode*) malloc (sizeof(struct MonHocNode));
  MonHocDB head = db;
  n->next = NULL;
  strcpy(n->id,id);
  n->so_tc = so_tc;
  n->hk = hk;
  if (db == NULL)
    return n;
  while (db-> next != NULL)
    db = db->next;
  db->next = n;
  return head;
}

void printMonHoc(MonHocDB db) {
  printf("%-10s%-10s%-10s\n","Ma mon","Tin chi","Hoc ky");
  while (db!=NULL) {
    printf("%-10s%-10d%-10d\n",db->id,db->so_tc,db->hk);
    db= db->next;
  }
}

DangKyDB read_dk(char* filename, MonHocDB monhocDB) {
  FILE *fin = fopen(filename,"r+");
  DangKyDB head = NULL;
  int n = (int)fgetc(fin) - 48;
  fgetc(fin);
  char id[10];
  int soMonHoc;
  while(n != 0){
    MonHocDB dsMonHoc = NULL;
    char *input = (char *) malloc(sizeof(char) *100);
    fgets(input,100,fin);
    input = strtok(input," ");
    strcpy(id,input);
    input = strtok(NULL," ");
    soMonHoc = atoi(input);
    for(int i = 0 ; i < soMonHoc ; i++){
      input = strtok(NULL," ");
      if(strlen(input) != 3)
      input[strlen(input) - 1] = '\0';
      MonHocDB new = find_mh_by_id(monhocDB,input);
      dsMonHoc = append_mh(dsMonHoc,input,new->so_tc,new->hk);
    }
    head = append_dd(head,id,dsMonHoc);
    n--;
  }
  printDangKy(head);
  return head;

}

DangKyDB append_dd(DangKyDB db, char* id, MonHocDB dsMonHoc) {
  DangKyDB n = (struct DangKyNode*) malloc(sizeof(struct DangKyNode));
  DangKyDB head = db;
  n->next = NULL;
  strcpy(n->id,id);
  n->dsmh = dsMonHoc;
  if (head == NULL)
    return n;
  while(db->next != NULL)
    db = db->next;
  db->next = n;
  return head;
}

struct MonHocNode *find_mh_by_id(MonHocDB db, char* id){
  while (db->next != NULL & strcmp(id,db->id) !=0 ) {
      db = db->next;
  }
  if (strcmp(id,db->id) == 0)
    return db;
  else return NULL;
}

void printDangKy(DangKyDB db){
  printf("%-10s%s\n","Ma sv","Dang ky");
  DangKyDB t = db;
  while(t != NULL){
    printf("%-10s",t->id);
    MonHocDB tmp = t->dsmh;
    printf("[");
    while(tmp != NULL){
      printf("%s",tmp->id);
      if(tmp->next != NULL)
        printf(",");
      tmp = tmp->next;
    }
    printf("]\n");
    t = t->next;
  }
}

struct DangKyNode *find_dk_by_id(DangKyDB db, char *id) {
  while (db->next != NULL & strcmp(id,db->id) !=0 ) {
    db = db->next;
  }
  if (strcmp(id,db->id) == 0)
    return db;
  else return NULL;
}

