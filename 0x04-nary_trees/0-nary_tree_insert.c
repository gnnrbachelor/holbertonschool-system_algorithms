#include "nary_trees.h"

/**
 * nary_tree_insert - Inserts
 * @parent: Parent
 * @str: Content
 * Return: pointer to to new node
 */

nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{

	nary_tree_t *n_node;

	n_node = malloc(sizeof(nary_tree_t));
	if (!n_node)
		return (NULL);

	n_node->content = strdup(str);
	if (!n_node->content)
		return (NULL);

	n_node->parent = parent;
	n_node->nb_children = 0;
	n_node->children = NULL;

	if (parent)
	{
		++parent->nb_children;
		n_node->next = parent->children;
		parent->children = n_node;
	}
	else
		n_node->next = NULL;

	return (n_node);

}


