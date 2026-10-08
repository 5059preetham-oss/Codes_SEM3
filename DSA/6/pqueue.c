#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

void initQueue(PriorityQueue* pq) {
    pq->front = NULL;
}

void enqueue(PriorityQueue* pq, int jobId, int depth, int traffic) {
    JobNode* newNode = (JobNode*)malloc(sizeof(JobNode));
    newNode->jobId = jobId;
    newNode->depth = depth;
    newNode->traffic = traffic;
    newNode->priority = depth + traffic; 
    newNode->next = NULL;

    if (pq->front == NULL || pq->front->priority < newNode->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        JobNode* current = pq->front;
        while (current->next != NULL && current->next->priority >= newNode->priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("Job %d added with priority %d.\n", jobId, newNode->priority);
}

void dequeue(PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("No pending jobs.\n");
        return;
    }
    JobNode* temp = pq->front;
    printf("Processing Job %d (Depth %d, Traffic = %d, Priority = %d)\n", 
           temp->jobId, temp->depth, temp->traffic, temp->priority);
    pq->front = pq->front->next;
    free(temp);
}

void displayQueue(PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("No pending jobs.\n");
        return;
    }
    printf("JobID\tDepth\tTraffic\tPriority\n");
    JobNode* current = pq->front;
    while (current != NULL) {
        printf("%d\t%d\t%d\t%d\n", current->jobId, current->depth, current->traffic, current->priority);
        current = current->next;
    }
}