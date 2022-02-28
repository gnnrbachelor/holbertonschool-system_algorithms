#include "rb_trees.h"

/**
 * rb_tree_node - Inits node
 * @parent: Parent
 * @value: Value
 * @color: Color
 * Return: Pointer to new node
 */

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *n_node;


	n_node = malloc(sizeof(rb_tree_t));
	if (n_node == NULL)
		return (NULL);
	n_node->n = value;
	n_node->color = color;
	n_node->left = NULL;
	n_node->right = NULL;
	n_node->parent = parent;

	return (n_node);

}
