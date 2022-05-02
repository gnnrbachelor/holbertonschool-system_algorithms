#include "heap.h"

/**
 * heap_extract - Extract node
 * @heap: heap
 * Return: pointer to node or NULL
 *
 */

void *heap_extract(heap_t *heap)
{
	void *data = NULL;
	binary_tree_node_t *last = NULL;
	binary_tree_node_t *parent = NULL;
	size_t path = 0;

	if (!heap || !heap->size)
		return (NULL);

	if (heap->size == 1)
	{
		data = heap->root->data;
		free(heap->root);
		heap->root = NULL;
		heap->size--;
		return (data);
	}

	path = find_sig(heap->size);
	for (last = heap->root; path; path >>= 1)
		if (path & heap->size)
			last = last->right;
		else
			last = last->left;

	data = heap->root->data;
	heap->root->data = last->data;
	parent = last->parent;
	free(last);
	if (heap->size-- & 1)
		parent->right = NULL;
	else
		parent->left = NULL;

	heapify(heap);
	return (data);
}

/**
 * heapify - Fixes heap
 * @heap: Heap
 * Return: Void
 */

void heapify(heap_t *heap)
{
	binary_tree_node_t *node = heap->root;
	binary_tree_node_t *child = NULL;
	void *temp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			if (heap->data_cmp(node->left->data, node->right->data) <= 0)
				child = node->left;
			else
				child = node->right;
		if (heap->data_cmp(node->data, child->data) < 0)
			break;
		temp = node->data;
		node->data = child->data;
		child->data = temp;
		node = child;
	}
}

