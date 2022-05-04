#include "huffman.h"

/**
 * huffman_priority_queue - Sets up priority queue
 * @data: data
 * @freq: Frequency
 * @size: Size
 * Return: Pointer to new heap or NULL
 */

heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *heap = NULL;
	symbol_t *symbol = NULL;
	binary_tree_node_t *n_node = NULL;
	size_t i;

	if (!data || !freq || !size)
		return (NULL);

	heap = heap_create(cmp);

	if (!heap)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		symbol = symbol_create(data[i], freq[i]);
		if (!symbol)
			return (NULL);
		n_node = heap_insert(heap, binary_tree_node(NULL, symbol));
		if (!n_node)
			return (NULL);
	}
	return (heap);


}

/**
 * cmp - Compares two freq
 * @node1: node 1
 * @node2: node 2
 * Return: Diff
 */

int cmp(void *node1, void *node2)
{
	symbol_t *symbol1, *symbol2;

	symbol1 = ((binary_tree_node_t *)node1)->data;
	symbol2 = ((binary_tree_node_t *)node2)->data;
	return (symbol1->freq - symbol2->freq);
}
