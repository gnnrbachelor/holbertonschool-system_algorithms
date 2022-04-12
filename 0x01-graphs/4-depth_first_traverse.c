#include "graphs.h"

size_t depth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *v, size_t depth))
{
	size_t depth = 0;
	size_t *visited;
	vertex_t *current;

	if (graph)
	{
		visited = calloc(graph->nb_vertices, sizeof(size_t));

		current = graph->vertices;
		if (current)
		{
			if (visited[current->index] == 0)
				dfs_recursive(current->index, visited, 0, &depth, graph, action);
			current = current->next;
		}
		free(visited);
	}

	return (depth);
}

void dfs_recursive(int index, size_t *visited, size_t c_depth, size_t *depth, const graph_t *graph, void (*action)(const vertex_t *v, size_t c_depth))
{
	vertex_t *dest, *current;
	edge_t *edge;

	current = get_vertex_by_index(graph, index);

	if (current && visited[index] != 1)
	{

		action(current, c_depth);
		if (c_depth > *depth)
			*depth = c_depth;
		visited[index] = 1;
		edge = current->edges;

		while (edge)
		{
			dest = edge->dest;
			if (visited[dest->index] != 1)
				dfs_recursive(dest->index, visited, c_depth + 1, depth, graph, action);

			edge = edge->next;
		}
	}

}


vertex_t *get_vertex_by_index(const graph_t *graph, size_t index)
{
	vertex_t *node;

	if (index > graph->nb_vertices)
		return (NULL);;

	node = graph->vertices;
	if (!node)
		return (NULL);

	while (node)
	{
		if (node->index == index)
			return (node);
		node = node->next;
	}
	return (NULL);
}

