#include "graphs.h"

int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	vertex_t *temp, *src_vert = NULL, *dest_vert = NULL;

	if (!graph || !src || !dest)
		return (0);

	for (temp = graph->vertices; temp; temp = temp->next)
	{
		if (!src_vert && !strcmp(temp->content, src))
			src_vert = temp;
		if (!dest_vert && !strcmp(temp->content, dest))
			dest_vert = temp;
		if (src_vert && dest_vert)
			break;
	}

	if (!init_edge(graph, src_vert, dest_vert))
		return (0);

	if (type == BIDIRECTIONAL)
		if (!init_edge(graph, dest_vert, src_vert))
			return (0);
	return (1);
}

int init_edge(graph_t *graph, vertex_t *src, vertex_t *dest)
{
	edge_t *tr_edge, *new;

	if (graph == NULL || src == NULL || dest == NULL)
		return (0);

	for (tr_edge = src->edges; tr_edge && tr_edge->next; tr_edge = tr_edge->next)
		;

	new = malloc(sizeof(edge_t));
	if (!new)
		return (0);

	new->dest = dest;
	new->next = NULL;

	if (!tr_edge)
		src->edges = new;
	else
		tr_edge->next = new;

	src->nb_edges += 1;

	return (1);
}
