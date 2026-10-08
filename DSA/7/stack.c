#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init_stack(stack_t *ptr_stack)
{
	ptr_stack->top_ = -1;
}

void deinit_stack(stack_t *ptr_stack)
{
	ptr_stack->top_ = -1;
}

int push(stack_t *ptr_stack, int index)
{
	if(! is_full(ptr_stack))
	{
		ptr_stack->index_[++ptr_stack->top_] = index;
		return 1;
	}
	return 0;
}
int pop(stack_t *ptr_stack)
{
	if(! is_empty(ptr_stack))
	{
		return ptr_stack->index_[ptr_stack->top_--];
	}
	return -1;
}
int is_empty(stack_t *ptr_stack)
{
	return ptr_stack->top_ == -1;
}
int is_full(stack_t *ptr_stack)
{
	return ptr_stack->top_ + 1 == MAXSIZE;
}