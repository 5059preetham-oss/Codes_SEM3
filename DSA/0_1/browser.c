#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[256];
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int count;
} Browser;

void OpenPage(Browser* b, const char* u) {
    Node* n = (Node*)malloc(sizeof(Node));
    strcpy(n->url, u);
    n->prev = NULL;
    n->next = NULL;

    if (b->head == NULL) {
        b->head = n;
        b->tail = n;
    } else {
        n->next = b->head;
        b->head->prev = n;
        b->head = n;
    }
    b->count++;

    if (b->count > 8) {
        Node* temp = b->tail;
        b->tail = b->tail->prev;
        b->tail->next = NULL;
        free(temp);
        b->count--;
    }
    printf("Opened %s\n", b->head->url);
}

void goBack(Browser* b) {
    if (b->head == NULL || b->head->next == NULL) {
        printf("Can't go back\n");
        return;
    }
    
    Node* temp = b->head;
    b->head = b->head->next;
    b->head->prev = NULL;
    free(temp);
    b->count--;
    
    printf("Went back to %s\n", b->head->url);
}

int main() {
    Browser b;
    b.head = NULL;
    b.tail = NULL;
    b.count = 0;

    OpenPage(&b, "google.com");
    OpenPage(&b, "wikipedia.org");
    OpenPage(&b, "github.com");
    OpenPage(&b, "stackoverflow.com");
    OpenPage(&b, "youtube.com");
    OpenPage(&b, "reddit.com");
    OpenPage(&b, "pes.edu");
    OpenPage(&b, "freecodecamp.org");
    
    OpenPage(&b, "mail.google.com");

    goBack(&b);
    goBack(&b);
    
    OpenPage(&b, "falstad.com");

    return 0;
}