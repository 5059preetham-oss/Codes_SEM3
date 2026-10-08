#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_SIZE 100

typedef double Element;

typedef struct {
    Element data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s);
bool isEmpty(Stack *s);
bool isFull(Stack *s);
void push(Stack *s, Element item);
Element pop(Stack *s);
Element peek(Stack *s);
void clearStack(Stack *s);

#endif