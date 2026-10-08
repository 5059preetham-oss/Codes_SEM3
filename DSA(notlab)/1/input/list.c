#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head_ = NULL;
}

void deinit_list(list_t *ptr_list)
{
	node_t *pres = ptr_list->head_;
	while (pres != NULL)
	{
		node_t *next = pres->next_;
		free(pres);
		pres = next;
	}
	ptr_list->head_ = NULL;
}

void disp(list_t *ptr_list)
{
	node_t* pres = ptr_list->head_;
	while(pres != NULL)
	{
		disp_term(&pres->term_);
		if (pres->next_ != NULL)
			printf(" ");
		pres = pres->next_;
	}
	printf("\n");
}

void insert(list_t* ptr_list, term_t term)
{
	node_t* temp;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->term_ = term;
	temp->next_ = NULL;
	
	// 1. empty list 
	if(ptr_list->head_ == NULL)
	{
		ptr_list->head_ = temp;
		temp->next_ = NULL;
	}
	else // find the position
	{
		node_t* prev = NULL; 
		node_t* pres = ptr_list->head_;
		while(pres != NULL && compare_exponents(&pres->term_, &temp->term_) > 0)
		{
			prev = pres;
			pres = pres->next_;
		}
		// beginning 
		if(prev == NULL)
		{
			ptr_list->head_ = temp;
			temp->next_ = pres;
		}
		else // middle or end 
		{
			prev->next_ = temp;
			temp->next_ = pres;
		}
	}
}

void delete(list_t* ptr_list, int expo)
{
	node_t *prev = NULL;
	node_t *pres = ptr_list->head_;
	while (pres != NULL && pres->term_.expo_ != expo)
	{
		prev = pres;
		pres = pres->next_;
	}
	if (pres == NULL)
		return;
	if (prev == NULL)
		ptr_list->head_ = pres->next_;
	else
		prev->next_ = pres->next_;
	free(pres);
}











