#ifndef CLIST_H
#define CLIST_H

#include <stddef.h>

#define NAME_LEN 100

typedef struct Node {
    int number;
    char name[NAME_LEN];
    struct Node *next;
} Node;

typedef struct {
    Node *current;
    size_t size;
} CList;

void clist_init(CList *list);
int clist_append(CList *list, int number, const char *name);
int clist_remove_after(CList *list, Node **removed);
void clist_display(const CList *list);
void clist_destroy(CList *list);

#endif
