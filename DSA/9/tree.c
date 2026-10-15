#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

// node functions 
static void disp_recursive(tree_node_t* temp)
{
	if(temp)
	{
		disp_recursive(temp->left_);
		printf("%d ", temp->key_);
		disp_recursive(temp->right_);
	}
}

static tree_node_t* insert_recursive(tree_node_t* root, tree_node_t* temp)
{
	if(root == NULL)
	{
		root = temp;
	}
	else if(root->key_ > temp->key_)
	{
		root->left_ = insert_recursive(root->left_, temp);
	}
	else 
	{
		root->right_ = insert_recursive(root->right_, temp);
	}
	return root;
}

static void deinit_recursive(tree_node_t* root)
{
	if(root)
	{
		deinit_recursive(root->left_);
		deinit_recursive(root->right_);
		free(root);
	}
}

// tree functions 
void init(tree_t *ptr_tree)
{
	ptr_tree->root_ = NULL;
}

void deinit(tree_t *ptr_tree)
{
	deinit_recursive(ptr_tree->root_);
	ptr_tree->root_ = NULL;
}

void disp(tree_t *ptr_tree)
{
	printf("Tree : ");
	disp_recursive(ptr_tree->root_);
	printf("\n");
}

void insert(tree_t *ptr_tree, int key)
{
	tree_node_t *temp = (tree_node_t*)malloc(sizeof(tree_node_t));
	temp->key_ = key;
	temp->left_ = temp->right_ = NULL;
	ptr_tree->root_ = insert_recursive(ptr_tree->root_, temp);
}

void level_order(tree_t *ptr_tree)
{
    queue_t q;
    init_queue(&q);
 
    printf("Level order : ");
    enqueue(&q, ptr_tree->root_);                 
    while(! is_empty(&q))                      
    {
        tree_node_t* temp = dequeue(&q);   
        if(temp != NULL)
        {
            printf("%d ", temp->key_);       
            enqueue(&q, temp->left_);         
            enqueue(&q, temp->right_);       
        }
    }
    printf("\n");
    deinit_queue(&q);
}