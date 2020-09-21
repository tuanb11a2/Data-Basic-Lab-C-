#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"

struct BookNode *make_node(char *id, char *tittle, char *author, int published_years)
{
    BookDB tmp = (BookDB)malloc(sizeof(struct BookNode));
    strcpy(tmp->id, id);
    strcpy(tmp->tittle, tittle);
    strcpy(tmp->author, author);
    tmp->published_year = published_years;
    tmp->next = NULL;

    return tmp;
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

BookDB read_db(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Can not open file!\n");
        return NULL;
    }
    BookDB list = NULL;
    char num[5];
    if (fgets(num, 5, f) == NULL)
    {
        printf("File is empty!\n");
        return NULL;
    }
    int a = atoi(num);
    printf("%d\n", a);

    char buf[50];
    while (fgets(buf, 50, f))
    {
        BookDB new = (BookDB)malloc(sizeof(struct BookNode));
        sscanf(buf, "%[^\n]s", new->id);
        fgets(buf, 50, f);
        sscanf(buf, "%[^\n]s", new->tittle);
        fgets(buf, 50, f);
        sscanf(buf, "%[^\n]s", new->author);
        fgets(buf, 50, f);
        sscanf(buf, "%d", &new->published_year);
        new->next = NULL;

        list = append(list, new);
    }

    fclose(f);
    return list;
}

void write_db(char *filename, BookDB db)
{
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Can not open file!\n");
        return;
    }

    for (BookDB i = db; i != NULL; i = i->next)
    {
        fwrite(i->id, sizeof(char), 10, f);
        fwrite(i->tittle, sizeof(char), 50, f);
        fwrite(i->author, sizeof(char), 20, f);
        fprintf(f, "%d\n", i->published_year);
    }

    fclose(f);
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

BookDB removeAt(BookDB db, char *id)
{
    if (db == NULL)
        return NULL;

    BookDB prev = NULL;
    for (BookDB i = db; i != NULL; i = i->next)
    {
        if (strcmp(id, i->id) == 0)
        {
            if (i == db)
            {
                db = i->next;
                free(i);
                return db;
            }
            prev->next = i->next;
            free(i);

            return db;
        }

        prev = i;
    }

    return db; // cant find that id
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

void print_book(struct BookNode *b)
{
    if (b == NULL)
        return;
    printf("%-10s%-50s%-20s%-5d\n", b->id, b->tittle, b->author, b->published_year);
}

void print_db(BookDB db)
{
    printf("%-10s%-50s%-20s%-5s\n", "id", "tittle", "author", "year");
    for (BookDB i = db; i != NULL; i = i->next)
    {
        print_book(i);
    }
}