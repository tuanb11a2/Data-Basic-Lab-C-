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

MonHocDB append_mh (MonHocdb db, char* id, int so_tc, int hk) {
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


