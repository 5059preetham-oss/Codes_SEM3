#include "josephus.h"

int josephus_remove_kth(CList *list, size_t k, Node **removed)
{
    size_t steps;
    size_t i;

    if (removed != NULL)
        *removed = NULL;

    if (list == NULL || list->size == 0 || k == 0)
        return 0;

    steps = (k - 1) % list->size;

    for (i = 0; i < steps; i++)
        list->current = list->current->next;

    return clist_remove_after(list, removed);
}
