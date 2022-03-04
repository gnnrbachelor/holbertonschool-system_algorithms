#include "rb_trees.h"

/**
 * array_to_rb_tree - Array to rb_tree
 * @array: Array
 * @size: Size
 * Return: Pointer to root
 */

rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t i;
	rb_tree_t *root;

	root = NULL;
	for (i = 0; array && i < size; ++i)
		rb_tree_insert(&root, array[i]);
	return (root);
}
