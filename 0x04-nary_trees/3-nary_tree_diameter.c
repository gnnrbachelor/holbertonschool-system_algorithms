#include "nary_trees.h"

static int max_d;

/**
 * get_diameter - Gets diamater
 * @root: Root
 * Return: Diameter
 *
 */

static int get_diameter(nary_tree_t *root)
{
	nary_tree_t *child = NULL;
	int max1 = 0, max2 = 0;
	int cur = 0, diameter = 0;

	if (!root)
		return (EXIT_FAILURE);

	for (child = root->children; child; child = child->next)
	{
		diameter = get_diameter(child);
		if (cur > diameter)
			cur = cur;
		else
			cur = diameter;

		if (diameter > max1)
		{
			max2 = max1;
			max1 = diameter;
		}
		else if (diameter > max2)
			max2 = diameter;

	}
	if ((max1 + max2 + 1) > max_d)
		max_d = max1 + max2 + 1;

	return (cur + 1);

}

/**
 * nary_tree_diameter - Gets diameter
 * @root: Root
 * Return: Diameter
 *
 */


size_t nary_tree_diameter(nary_tree_t const *root)
{
	if (!root)
		return (EXIT_FAILURE);

	get_diameter((nary_tree_t *)root);
	return (max_d);
}
