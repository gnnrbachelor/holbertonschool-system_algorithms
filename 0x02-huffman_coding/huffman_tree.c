#include "huffman.h"

/**
 * huffman_tree - Creates huffman tree
 * @data: Data
 * @freq: freq
 * @size: size
 * Return: Pointer to root or NULL
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *queue = NULL;
	binary_tree_node_t *root = NULL;

	queue = huffman_priority_queue(data, freq, size);
	setbuf(stdout, NULL);
	if (!queue)
		return (NULL);

	while (1)
		if (!huffman_extract_and_insert(queue))
			break;

	root = queue->root->data, free(queue->root), free(queue);
	return (root);
}

