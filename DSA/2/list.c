#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t* list)
{
	list->head = NULL;
}

int insert_list(list_t* list, int length, int breadth)
{
	node_t* new_node = (node_t*)malloc(sizeof(node_t));
	if(new_node == NULL)
	{
		return 0;
	}

	set_rect(&new_node->rectangle, length, breadth);
	new_node->next = NULL;

	node_t* previous = NULL;
	node_t* current = list->head;
	while(current != NULL &&
	      !compare_rect(&new_node->rectangle, &current->rectangle))
	{
		previous = current;
		current = current->next;
	}

	new_node->next = current;
	if(previous == NULL)
	{
		list->head = new_node;
	}
	else
	{
		previous->next = new_node;
	}
	return 1;
}

void display_list(const list_t* list)
{
	const node_t* current = list->head;
	if(current == NULL)
	{
		printf("The list is empty.\n");
		return;
	}

	while(current != NULL)
	{
		display_rect(&current->rectangle);
		current = current->next;
	}
}

double total_value(const list_t* list, double unit_area_value)
{
	double total = 0.0;
	const node_t* current = list->head;
	while(current != NULL)
	{
		total += area_rect(&current->rectangle) * unit_area_value;
		current = current->next;
	}
	return total;
}

const rect_t* highest_length(const list_t* list)
{
	if(list->head == NULL)
	{
		return NULL;
	}

	const node_t* best = list->head;
	for(const node_t* current = best->next; current != NULL; current = current->next)
	{
		if(current->rectangle.length > best->rectangle.length)
		{
			best = current;
		}
	}
	return &best->rectangle;
}

const rect_t* least_breadth(const list_t* list)
{
	if(list->head == NULL)
	{
		return NULL;
	}

	const node_t* best = list->head;
	for(const node_t* current = best->next; current != NULL; current = current->next)
	{
		if(current->rectangle.breadth < best->rectangle.breadth)
		{
			best = current;
		}
	}
	return &best->rectangle;
}

void free_list(list_t* list)
{
	node_t* current = list->head;
	while(current != NULL)
	{
		node_t* next = current->next;
		free(current);
		current = next;
	}
	list->head = NULL;
}