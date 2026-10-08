#ifndef LIST_H
#define LIST_H

#include "rect.h"

struct node
{
	rect_t rectangle;
	struct node* next;
};
typedef struct node node_t;

struct list
{
	node_t* head;
};
typedef struct list list_t;

void init_list(list_t*);
int insert_list(list_t*, int length, int breadth);
void display_list(const list_t*);
double total_value(const list_t*, double unit_area_value);
const rect_t* highest_length(const list_t*);
const rect_t* least_breadth(const list_t*);
void free_list(list_t*);

#endif