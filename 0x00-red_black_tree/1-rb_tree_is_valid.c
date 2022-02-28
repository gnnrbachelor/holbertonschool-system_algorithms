#include "rb_trees.h"

/**
 * rb_tree_is_valid - Checks for  red black tree
 * @tree: Pointer to root of tree
 *
 */

int rb_tree_is_valid(const rb_tree_t *tree)
{

	size_t left = 0, right = 0;
	static int rec_switch = 0;

	if (rec_switch == 0 && tree->color != BLACK)
		return (0);

	rec_switch = 1;

	if (!tree)
		return (0);
	if (tree->color != RED && tree->color != BLACK)
		return (0);

	if (tree->color == RED && tree->right && tree->right->color != BLACK)
		return (0);
	if (tree->color == RED && tree->left && tree->left->color != BLACK)
		return (0);

	right = rb_tree_is_valid(tree->right);
	left = rb_tree_is_valid(tree->left);

	if (right != left)
		return (0);
	if (right == left && tree->color == BLACK)
		return (1);

	if (right == left && tree->color == RED)
		return (left);
	return (0);
}
