#include "huffman.h"

/**
 * huffman_extract_and_insert - Extracts and inserts
 * @priority_queue: Queue
 * Return: 1 or 0
 */

int huffman_extract_and_insert(heap_t *priority_queue)
{
	symbol_t *sym = NULL, *sym1 = NULL, *sym2 = NULL;
	binary_tree_node_t *child1 = NULL, *child2 = NULL, *nest = NULL;

	if (!priority_queue || priority_queue->size < 2)
		return (0);

	child1 = heap_extract(priority_queue);
	child2 = heap_extract(priority_queue);

	if (!child1 || !child2)
		return (0);

	sym1 = (symbol_t *)child1->data;
	sym2 = (symbol_t *)child2->data;
	sym = symbol_create(-1, sym1->freq + sym2->freq);
	if (!sym)
		return (0);

	nest = binary_tree_node(NULL, sym);
	if (!nest)
		return (free(sym), 0);

	nest->left = child1;
	nest->right = child2;
	child1->parent = nest;
	child2->parent = nest;

	if (heap_insert(priority_queue, nest))
		return (1);
	return (0);
}

