#include "josephus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void read_name(char *name)
{
    int ch;

    if (fgets(name, NAME_LEN, stdin) == NULL) {
        name[0] = '\0';
        return;
    }

    if (strchr(name, '\n') == NULL) {
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    name[strcspn(name, "\n")] = '\0';
}

int main(void)
{
    CList list;
    size_t n, k, i, round;
    char name[NAME_LEN];

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

    while (getchar() != '\n')
        ;

    for (i = 1; i <= n; i++) {
        printf("Enter name for person #%zu: ", i);
        read_name(name);

        if (name[0] == '\0') {
            printf("Name cannot be empty.\n");
            i--;
            continue;
        }

        if (!clist_append(&list, (int)i, name)) {
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

        printf("Round %zu: %s (person #%d) executed\n",
               round, removed->name, removed->number);
        free(removed);
    }

    printf("Survivor -> %s (person #%d)\n",
           list.current->name, list.current->number);

    clist_destroy(&list);
    return 0;
}
