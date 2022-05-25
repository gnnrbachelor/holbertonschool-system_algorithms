#include "pathfinding.h"

static char *visited;
static queue_t *path;
static vertex_t const *target_node;
graph_t *global_graph;

static int depth_first(vertex_t const *vertex)
{
	char *city;
	edge_t *edge;

	if (visited[vertex->index])
		return (0);

	printf("Checking %s\n", vertex->content);
	visited[vertex->index] = 1;
	city = strdup(vertex->content);
	if (!city)
		exit(1);

	queue_push_front(path, city);
	if (vertex == target_node)
		return (1);

	for (edge = vertex->edges; edge; edge = edge->next)
		if (depth_first(edge->dest))
			return (1);

	free(dequeue(path));
	return (0);
}



queue_t *backtracking_graph(graph_t *graph, vertex_t const *start, vertex_t const *target)
{
	queue_t *rev = NULL;

	if (!graph || !start || !target)
		return (NULL);

	setbuf(stdout, NULL);
	visited = calloc(graph->nb_vertices, sizeof(*visited));
	path = queue_create();
	if (!visited || !path)
		exit(1);

	target_node = target;
	global_graph = graph;

	if (depth_first(start))
	{
		char *city;
		rev = queue_create();
		if (!rev)
			exit(1);

		for (city = dequeue(path); city; city = dequeue(path))
			if (!queue_push_front(rev, city))
				exit(1);
	}
	queue_delete(path);
	free(visited);
	return (rev);
}


