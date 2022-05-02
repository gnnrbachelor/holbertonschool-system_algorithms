#include "heap.h"

/**
 * recursive_delete - Recursive Delete
 * @node: pointer to root
 * @free_data: oointer to func to free data
 * Return: Void
 */

void recursive_delete(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (!node)
		return;

	recursive_delete(node->left, free_data);
	recursive_delete(node->right, free_data);
	if (free_data)
		free_data(node->data);

	free(node);
}

/**
 * heap_delete - Deletes Heap
 * @heap: Heap
 * @free_data: pointer to free function
 * Return: void
 */

void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;

	recursive_delete(heap->root, free_data);
	free(heap);
}
