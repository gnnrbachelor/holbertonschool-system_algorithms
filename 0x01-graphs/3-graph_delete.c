#include "graphs.h"

/**
 * graph_delete - Deletes graph
 * @graph: Pointer to graph
 * Return: Void
 */

void graph_delete(graph_t *graph)
{
	vertex_t *temp_vert;
	edge_t *temp_edge;

	if (!graph)
		return;

	while (graph->vertices)
	{
		while (graph->vertices->edges)
		{
			temp_edge = graph->vertices->edges;
			graph->vertices->edges = graph->vertices->edges->next;
			free(temp_edge);
		}
		temp_vert = graph->vertices;
		graph->vertices = graph->vertices->next;
		free(temp_vert->content);
		free(temp_vert);
		graph->nb_vertices -= 1;
	}
	free(graph);
}
