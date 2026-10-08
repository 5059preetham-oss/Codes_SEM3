#include "clist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clist_init(CList *list)
{
    list->current = NULL;
    list->size = 0;
}

int clist_append(CList *list, int number, const char *name)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
        return 0;

    new_node->number = number;

    if (name != NULL) {
        strncpy(new_node->name, name, NAME_LEN - 1);
        new_node->name[NAME_LEN - 1] = '\0';
    } else {
        new_node->name[0] = '\0';
    }

    if (list->current == NULL) {
        new_node->next = new_node;
        list->current = new_node;
    } else {
        new_node->next = list->current->next;
        list->current->next = new_node;
        list->current = new_node;
    }

    list->size++;
    return 1;
}

int clist_remove_after(CList *list, Node **removed)
{
    Node *temp;

    if (list == NULL || list->current == NULL || list->size == 0)
        return 0;

    temp = list->current->next;

    if (list->size == 1)
        list->current = NULL;
    else
        list->current->next = temp->next;

    list->size--;

    if (removed != NULL)
        *removed = temp;
    else
        free(temp);

    return 1;
}

void clist_display(const CList *list)
{
    Node *p;

    if (list == NULL || list->current == NULL || list->size == 0) {
        printf("List is empty.\n");
        return;
    }

    p = list->current->next;

    do {
        if (p->name[0] != '\0')
            printf("%d (%s)", p->number, p->name);
        else
            printf("%d", p->number);

        p = p->next;

        if (p != list->current->next)
            printf(" -> ");
    } while (p != list->current->next);

    printf("\n");
}

void clist_destroy(CList *list)
{
    Node *p;
    Node *next;

    if (list == NULL || list->current == NULL)
        return;

    p = list->current->next;

    while (p != list->current) {
        next = p->next;
        free(p);
        p = next;
    }

    free(list->current);
    list->current = NULL;
    list->size = 0;
}
