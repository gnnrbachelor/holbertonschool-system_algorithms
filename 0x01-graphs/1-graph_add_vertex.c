#include "graphs.h"

/**
 * vertex_init - Initializes graph
 * @str: str
 * Return: pointer to new node
 *
 */

vertex_t *vertex_init(const char *str)
{
	vertex_t *node = malloc(sizeof(vertex_t));

	if (!node)
		return (NULL);

	node->content = strdup(str);
	node->nb_edges = 0;
	node->edges = NULL;
	node->next = NULL;

	return (node);

}

/**
 * graph_add_vertex - Adds vertex
 * @graph: pointer to graph
 * @str: str
 * Return: pointer to new node
 *
 */



vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{

	vertex_t *n_vert, *trav;

	if (!graph || !str)
		return (NULL);

	for (trav = graph->vertices; trav && trav->next; trav = trav->next)
	{
		if (!strcmp(trav->content, str))
			return (NULL);

	}

	n_vert = vertex_init(str);
	graph->nb_vertices++;

	if (!trav)
	{
		n_vert->index = 0;
		graph->vertices = n_vert;
	}
	else
	{
		n_vert->index = trav->index + 1;
		trav->next = n_vert;
	}

	return (n_vert);

}
