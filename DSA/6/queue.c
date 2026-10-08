#include <stdio.h>
#include "queue.h"

void queueInit(Queue* q) {
    dequeInit(&(q->dq));
}

int queueIsEmpty(Queue* q) {
    return dequeIsEmpty(&(q->dq));
}

void queueEnqueue(Queue* q, int val) {
    insertRear(&(q->dq), val);
}

void queueDequeue(Queue* q) {
    if (queueIsEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int val = deleteFront(&(q->dq));
    printf("Dequeued value: %d\n", val);
}

void queueDisplay(Queue* q) {
    dequeDisplay(&(q->dq));
}