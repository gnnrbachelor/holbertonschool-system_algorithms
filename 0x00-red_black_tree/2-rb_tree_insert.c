#include "rb_trees.h"


/**
 * rotr - Rotates right
 * @tree - Tree
 * @node - Node
 * Return: Void
 */
void rotr(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *child = node->left;

	if (!child)
		return;

	node->left = child->right;
	if (child->right)
		child->right->parent = node;
	child->parent = node->parent;
	if (!node->parent)
		*tree = child;
	else if (node == node->parent->right)
		node->parent->right = child;
	else
		node->parent->left = child;
	child->right = node;
	node->parent = child;

}


/**
 * rotl - Rotates left
 * @tree - Tree
 * @node - Node
 * Return: Void
 */

void rotl(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *child = node->right;

	if (!child)
		return;
	node->right = child->left;
	if (child->left)
		child->left->parent = node;
	child->parent = node->parent;
	if (!node->parent)
		*tree = child;
	else if (node == node->parent->left)
		node->parent->left = child;
	else
		node->parent->right = child;
	child->left = node;
	node->parent = child;
}


/**
 * fix_left_unc - Fixes color
 * @tree: Tree
 * @node: Node
 * Return: Void
 */

rb_tree_t *fix_left_unc(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *gp, *uncle = node->parent->parent->left;

	if (uncle && uncle->color == RED)
	{
		node->parent->color = BLACK;
		uncle->color = BLACK;
		gp = node->parent->parent;
		gp->color = RED;
		node = gp;
	}
	else
	{
		if (node == node->parent->left)
		{
			node = node->parent;
			rotr(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		rotl(tree, node->parent->parent);
	}
	return (node);
}





/**
 * fix_right_unc - Fixes color
 * @tree: Tree
 * @node: Node
 * Return: Void
 */

rb_tree_t *fix_right_unc(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *gp, *uncle = node->parent->parent->right;

	if (uncle && uncle->color == RED)
	{
		node->parent->color = BLACK;
		uncle->color = BLACK;
		gp = node->parent->parent;
		gp->color = RED;
		node = gp;
	}
	else
	{
		if (node == node->parent->right)
		{
			node = node->parent;
			rotl(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		rotr(tree, node->parent->parent);
	}
	return (node);
}


/**
 * fix_color = Fixes color
 * @tree: Tree
 * @node: Node
 * Return: Void
 */

void fix_color(rb_tree_t **tree, rb_tree_t *node)
{
	while (node->parent && node->parent->color == RED)
	{
		if (node->parent->parent && node->parent ==
				node->parent->parent->left)
			node = fix_right_unc(tree, node);
		else
			node = fix_left_unc(tree, node);
	}
	(*tree)->color = BLACK;
}






/**
 * bst_insert - Inserts in BST
 * @tree: tree
 * @value: Value
 * Return: Void
 */
rb_tree_t *bst_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *cur, *prev, *n_node;

	prev = NULL;
	cur = *tree;
	while (cur)
	{
		prev = cur;
		if (value < cur->n)
			cur = cur->left;
		else if (value > cur->n)
			cur = cur->right;
		else
			return (NULL);
	}
	n_node = rb_tree_node(NULL, value, RED);
	if (!n_node)
		return (NULL);
	n_node->parent = prev;
	if (!prev)
		*tree = n_node;
	else if (n_node->n < prev->n)
		prev->left = n_node;
	else
		prev->right = n_node;
	return (n_node);
}


/**
 * rb_tree_insert - Inserts in RB Tree
 * @tree: Tree
 * @value: Value
 * Return: pointer to new node
 */

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{

	rb_tree_t *n_node;

	if (!tree)
		return (NULL);

	n_node = bst_insert(tree, value);

	if (n_node)
		fix_color(tree, n_node);
	return (n_node);

}
