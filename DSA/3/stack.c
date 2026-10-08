#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, Element item) {
    if (isFull(s)) {
        printf("Error: Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = item;
}

Element pop(Stack *s) {
    if (isEmpty(s)) {
        return (Element)0; // Return dummy on underflow; handle error in client
    }
    return s->data[(s->top)--];
}

Element peek(Stack *s) {
    if (isEmpty(s)) return (Element)0;
    return s->data[s->top];
}

void clearStack(Stack *s) {
    s->top = -1;
}