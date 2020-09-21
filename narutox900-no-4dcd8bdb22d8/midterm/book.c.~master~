#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#define MAX 100


struct BookNode* make_node(char* id, char* title, char* author, int published_years) {
  struct BookNode* node = malloc(sizeof(struct BookNode));
  strcpy(node->id,id);
  strcpy(node->title,title);
  strcpy(node->author,author);
  node->published_year = published_years;
  node->next = NULL;
  return node;
}

BookDB append(BookDB db, struct BookNode *b)
{
  if (db == NULL)
    {
      return b;
    }

  b->next = db;
  return b;
}

BookDB read_db(char* filename) {
  FILE *fin;
  if ((fin = fopen(filename, "r")) == NULL)
    {
      printf("Can't read from %s\n",filename);
      return NULL;
    }
  int n;
  BookDB list = NULL;
  char buf[MAX];
  fgets(buf,MAX,fin);
  sscanf(buf,"%d",&n);
  printf("%d\n",n);
  while(fgets(buf,MAX,fin)){
    BookDB new = malloc(sizeof(struct BookNode));
    sscanf(buf,"%[^\n]s",new->id);
    printf("%s\n",new->id);
    fgets(buf,MAX,fin);
    sscanf(buf,"%[^\n]s",new->title);
    printf("%s\n",new->title);
    fgets(buf,MAX,fin);
    sscanf(buf,"%[^\n]s",new->author);
    printf("%s\n",new->author);
    fgets(buf,MAX,fin);
    sscanf(buf,"%d",&new->published_year);
    printf("%d\n",new->published_year);
    new->next = NULL;
    list = append(list,new);
  }
  fclose(fin);
  return list;
}
void print_db(BookDB db)
{
  printf("\n\n");
  printf("%-10s%-50s%-20s%-5s\n", "id", "title", "author", "year");
  for (BookDB i = db; i != NULL; i = i->next)
    {
      print_book(i);
    }
}
void print_book(struct BookNode *b)
{
  if (b == NULL)
    return;
  printf("%-10s%-50s%-20s%-5d\n", b->id, b->title, b->author, b->published_year);
}

BookDB removeDB(BookDB db, char *id){
  if (db == NULL)
    return NULL;
  BookDB tmp = db;
  if (strcmp(db->id,id) == 0) {
    db = db->next;
    free(tmp);
    return db;
  }
  while(tmp->next != NULL) {
    if (strcmp(tmp->next->id,id) == 0) {
      BookDB i = tmp->next;
      tmp->next = tmp->next->next;
      free(i);
      return db;
    }
    tmp = tmp->next;
  }
  return db;
}

void write_db(char* filename, BookDB db) {
  FILE* f;
  if ((f = fopen(filename,"w")) == NULL) {
    printf("Can't open %s\n",filename);
    return ;
  }
  printf("\n\n");
  for (BookDB i = db; i != NULL; i = i->next) {
      fprintf(f, "%s\n%s\n%s\n%d\n",i->id,i->title,i->author,i->published_year);
    }
  fclose(f);
}

BookDB swap(BookDB db, struct BookNode *b1, struct BookNode *b2)
{
    if (b1 == b2)
        return db;

    BookDB prevb1 = NULL, currb1;
    for (currb1 = db; currb1 != b1 && currb1 != NULL; currb1 = currb1->next)
        prevb1 = currb1;

    BookDB prevb2 = NULL, currb2;
    for (currb2 = db; currb2 != b2 && currb2 != NULL; currb2 = currb2->next)
        prevb2 = currb2;

    if (currb1 == NULL || currb2 == NULL)
        return db;

    if (prevb1 != NULL)
        prevb1->next = currb2;
    else
        db = currb2;

    if (prevb2 != NULL)
        prevb2->next = currb1;
    else
        db = currb1;

    BookDB temp = currb2->next;
    currb2->next = currb1->next;
    currb1->next = temp;
    return db;
}

struct BookNode *find_by_id(BookDB db, char *id)
{
  for (BookDB i = db; i != NULL; i = i->next)
    {
      if (strcmp(id, i->id) == 0)
        {
          return i;
        }
    }

  return NULL;
}




