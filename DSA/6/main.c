#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    Queue q;
    queueInit(&q);
    int choice, val;

    while (1) {
        printf("\nQueue (implemented using Deque)\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                queueEnqueue(&q, val);
                break;
            case 2:
                queueDequeue(&q);
                break;
            case 3:
                queueDisplay(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}