#ifndef PQUEUE_H
#define PQUEUE_H

typedef struct JobNode {
    int jobId;
    int depth;
    int traffic;
    int priority;
    struct JobNode* next;
} JobNode;

typedef struct {
    JobNode* front;
} PriorityQueue;

void initQueue(PriorityQueue* pq);
void enqueue(PriorityQueue* pq, int jobId, int depth, int traffic);
void dequeue(PriorityQueue* pq);
void displayQueue(PriorityQueue* pq);

#endif