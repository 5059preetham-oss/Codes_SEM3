#ifndef DEQUE_H
#define DEQUE_H

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

typedef struct {
    DNode* front;
    DNode* rear;
} Deque;

void dequeInit(Deque* dq);
int dequeIsEmpty(Deque* dq);
void insertRear(Deque* dq, int val);
int deleteFront(Deque* dq);
void dequeDisplay(Deque* dq);

#endif