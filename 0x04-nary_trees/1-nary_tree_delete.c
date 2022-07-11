#include "nary_trees.h"

/**
 * nary_tree_delete - Deletes tree
 * @tree: Tree
 * Return: Void
 *
 */

void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *next = NULL;
	nary_tree_t *children = NULL;

	if (!tree)
		return;
	children = tree->children;
	while (children)
	{
		nary_tree_delete(children->children);
		free(children->content);
		next = children->next;
		free(children);
		children = next;
	}
	free(tree->content);
	free(tree);
}
