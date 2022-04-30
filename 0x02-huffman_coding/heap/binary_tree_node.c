#include "heap.h"

/**
 * binary_tree_node - Creates btnode
 * @parent: Parent
 * @data: data
 * Return: NULL or Pointer to node
 */

binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{

	binary_tree_node_t *node = malloc(sizeof(binary_tree_node_t));

	if (!node)
		return (NULL);

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->data = data;

	return (node);

}
