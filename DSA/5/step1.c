#include "josephus.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    CList list;
    size_t n, k, i, round;

    clist_init(&list);

    printf("Enter number of people (n): ");
    if (scanf("%zu", &n) != 1 || n < 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter the count k [kth element is removed]: ");
    if (scanf("%zu", &k) != 1 || k < 1) {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        if (!clist_append(&list, (int)i, NULL)) {
            printf("Memory allocation failed.\n");
            clist_destroy(&list);
            return 1;
        }
    }

    printf("\nElimination order:\n");

    for (round = 1; round < n; round++) {
        Node *removed = NULL;

        if (!josephus_remove_kth(&list, k, &removed)) {
            printf("Removal failed.\n");
            clist_destroy(&list);
            return 1;
        }

        printf("Round %zu: person #%d executed\n", round, removed->number);
        free(removed);
    }

    printf("Survivor -> person #%d\n", list.current->number);

    clist_destroy(&list);
    return 0;
}
