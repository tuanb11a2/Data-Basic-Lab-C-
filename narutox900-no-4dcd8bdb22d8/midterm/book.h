#ifndef _BOOK_H_
#define _BOOK_H_

struct BookNode {
  char id[10];
  char title[50];
  char author[20];
  int published_year;
  struct BookNode *next;
};

typedef struct BookNode *BookDB;


BookDB read_db(char* filename);

void write_db(char* filename,BookDB db);

struct BookNode* make_node(char *id, char *tittle, char *author, int published_years);

BookDB append(BookDB db, struct BookNode *b);

struct BookNode *find_by_id(BookDB db, char *id);

BookDB removeDB(BookDB db, char *id);

BookDB swap(BookDB db, struct BookNode *b1, struct BookNode *b2);

void print_book(struct BookNode *b);

void print_db(BookDB db);

#endif
