#include <stdio.h>
#include "tree.h"

static int insert_recursive(node_t elem[], int root, int index)
{
	if (root == -1)
		return index;

	if (elem[index].key_ < elem[root].key_)
		elem[root].left_ = insert_recursive(elem, elem[root].left_, index);
	else
		elem[root].right_ = insert_recursive(elem, elem[root].right_, index);

	return root;
}

static void display_recursive(const node_t elem[], int root)
{
	if (root == -1)
		return;

	display_recursive(elem, elem[root].left_);
	printf("%d ", elem[root].key_);
	display_recursive(elem, elem[root].right_);
}

static int find_minimum(const node_t elem[], int root)
{
	while (elem[root].left_ != -1)
		root = elem[root].left_;
	return root;
}

static int delete_recursive(tree_t *ptr_tree, int root, int key, int *deleted)
{
	int removed_index;

	if (root == -1)
		return -1;

	if (key < ptr_tree->elem_[root].key_) {
		ptr_tree->elem_[root].left_ =
			delete_recursive(ptr_tree, ptr_tree->elem_[root].left_, key, deleted);
		return root;
	}

	if (key > ptr_tree->elem_[root].key_) {
		ptr_tree->elem_[root].right_ =
			delete_recursive(ptr_tree, ptr_tree->elem_[root].right_, key, deleted);
		return root;
	}

	*deleted = 1;
	if (ptr_tree->elem_[root].left_ == -1) {
		removed_index = root;
		root = ptr_tree->elem_[root].right_;
	} else if (ptr_tree->elem_[root].right_ == -1) {
		removed_index = root;
		root = ptr_tree->elem_[root].left_;
	} else {
		int successor = find_minimum(ptr_tree->elem_, ptr_tree->elem_[root].right_);
		ptr_tree->elem_[root].key_ = ptr_tree->elem_[successor].key_;
		ptr_tree->elem_[root].right_ =
			delete_recursive(ptr_tree, ptr_tree->elem_[root].right_,
			                 ptr_tree->elem_[root].key_, deleted);
		return root;
	}

	if (!push(&ptr_tree->free_indices_, removed_index))
		*deleted = 0;
	else
		--ptr_tree->count_;

	return root;
}

void init(tree_t *ptr_tree)
{
	int index;

	ptr_tree->root_ = -1;
	ptr_tree->count_ = 0;
	init_stack(&ptr_tree->free_indices_);
	for (index = 0; index < MAXSIZE; ++index)
		push(&ptr_tree->free_indices_, index);
}

int insert(tree_t *ptr_tree, int key)
{
	int index = pop(&ptr_tree->free_indices_);

	if (index == -1)
		return 0;

	ptr_tree->elem_[index].key_ = key;
	ptr_tree->elem_[index].left_ = -1;
	ptr_tree->elem_[index].right_ = -1;
	ptr_tree->root_ = insert_recursive(ptr_tree->elem_, ptr_tree->root_, index);
	++ptr_tree->count_;
	return 1;
}

void disp(tree_t *ptr_tree)
{
	display_recursive(ptr_tree->elem_, ptr_tree->root_);
	printf("\n");
}

int delete_key(tree_t *ptr_tree, int key)
{
	int deleted = 0;

	if (ptr_tree->root_ != -1)
		ptr_tree->root_ =
			delete_recursive(ptr_tree, ptr_tree->root_, key, &deleted);
	return deleted;
}

int main(void)
{
	tree_t tree;
	int choice;
	int key;

	init(&tree);
	do {
		printf("\n1. Insert\n2. Delete\n3. Display (inorder)\n4. Exit\n");
		printf("Enter choice: ");
		if (scanf("%d", &choice) != 1)
			return 1;

		switch (choice) {
		case 1:
			printf("Enter key: ");
			if (scanf("%d", &key) != 1)
				return 1;
			if (!insert(&tree, key))
				printf("Memory manager is full; cannot insert.\n");
			break;
		case 2:
			printf("Enter key: ");
			if (scanf("%d", &key) != 1)
				return 1;
			if (!delete_key(&tree, key))
				printf("Key not found.\n");
			break;
		case 3:
			disp(&tree);
			break;
		case 4:
			break;
		default:
			printf("Invalid choice.\n");
		}
	} while (choice != 4);

	return 0;
}
