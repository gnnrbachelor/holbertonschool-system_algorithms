#include "graphs.h"


size_t breadth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *v, size_t depth))
{
	size_t depth, step, next;
	vertex_t **vertices;
	char *visited;
	edge_t *p;
	int i, j;

	if (!graph || !action || graph->nb_vertices == 0)
		return (0);

	visited = calloc(graph->nb_vertices, sizeof(char));
	vertices = calloc(graph->nb_vertices + 1, sizeof(vertex_t *));

	vertices[0] = graph->vertices;

	visited[0] = 1;
	depth = 0;
	j = 1;
	step = 1;
	next = 0;

	for (i = 0; vertices[i]; i++)
	{
		action(vertices[i], depth);

		for (p = vertices[i]->edges; p; p = p->next)
		{
			if (visited[p->dest->index] == 0)
			{
				vertices[j++] = p->dest;
				visited[p->dest->index] = 1;
				next += 1;
			}
		}

		if (--step == 0)
		{
			depth++;
			step = next;
			next = 0;
		}
	}
	free(visited);
	free(vertices);
	return (depth - 1);
}
