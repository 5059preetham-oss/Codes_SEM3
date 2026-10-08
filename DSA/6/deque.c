#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void dequeInit(Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

int dequeIsEmpty(Deque* dq) {
    return dq->front == NULL;
}

void insertRear(Deque* dq, int val) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    
    if (dequeIsEmpty(dq)) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

int deleteFront(Deque* dq) {
    if (dequeIsEmpty(dq)) return -1;
    
    DNode* temp = dq->front;
    int val = temp->data;
    
    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    
    free(temp);
    return val;
}

void dequeDisplay(Deque* dq) {
    if (dequeIsEmpty(dq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front -> ");
    DNode* current = dq->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("<- Rear\n");
}