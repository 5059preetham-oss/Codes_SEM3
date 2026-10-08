#ifndef LIST_H
#define LIST_H
#include "term.h"

struct node 
{
	term_t term_;
	struct node *next_;
};
typedef struct node node_t;

struct list 
{
	node_t* head_;
};
typedef struct list list_t;

void init_list(list_t* ptr_list);
void deinit_list(list_t* ptr_list);
void insert(list_t* ptr_list, term_t term);
void delete(list_t* ptr_list, int expo);
void disp(list_t* ptr_list);

#endif