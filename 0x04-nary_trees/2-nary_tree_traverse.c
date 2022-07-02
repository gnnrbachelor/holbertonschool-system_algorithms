#include "nary_trees.h"

size_t nary_tree_traverse(nary_tree_t const *root, void (*action)(nary_tree_t const *node, size_t depth))
{
	if (!root || !action)
		return (0);

	return dfs(root, action, 0);

}

size_t dfs(nary_tree_t const *root, void (*action)(nary_tree_t const *node, size_t depth), size_t depth)
{
	size_t cur, maxd = 0;
	nary_tree_t *temp;

	if (!root)
		return (depth - 1);

	action(root, depth);		

	for (temp = root->children; temp; temp = temp->next)
	{
		cur = dfs(temp, action, depth + 1);
		maxd = max(cur, maxd);
	}
	return (max(maxd, depth));

}
