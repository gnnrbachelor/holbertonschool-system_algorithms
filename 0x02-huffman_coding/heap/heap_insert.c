#include "heap.h"

/**
 * heap_insert - Inserts in heap
 * @heap: Heap
 * @data: data
 * Return: pointer to node or NULL
 */

binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{

	binary_tree_node_t *n_node = NULL, *p = NULL, *index = NULL;
	size_t p_code = 0, p_i = 0;
	void *temp;


	if (!heap)
		return (NULL);

	n_node = binary_tree_node(NULL, data);

	if (!n_node)
		return (NULL);

	p_i = ++heap->size / 2;
	p_code = find_sig(p_i);

	if (!heap->root)
		return (heap->root = n_node);
	for (p = heap->root; p_code; p_code >>= 1)
	{
		if (p_code & p_i)
			p = p->right;
		else
			p = p->left;
	}

	n_node->parent = p;

	if (heap->size & 1)
		p->right = n_node;
	else
		p->left = n_node;

	index = n_node;

	while (index->parent && heap->data_cmp(index->parent->data, index->data) > 0)
	{
		temp = index->data;
		index->data = index->parent->data;
		index->parent->data = temp;
		index = index->parent;
	}

	return (n_node);
}

/**
 * find_sig - Finds most significant bit
 * @num: Number
 * Return: sig bit
 *
 */

size_t find_sig(size_t num)
{
	num |= num >> 1;
	num |= num >> 2;
	num |= num >> 4;
	num |= num >> 8;
	num |= num >> 16;
	num = num + 1;
	return (num >> 2);
}


