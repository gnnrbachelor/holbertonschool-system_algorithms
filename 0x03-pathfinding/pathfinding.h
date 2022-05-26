#ifndef PATHFINDING_H

#define PATHFINDING_H

#include "queues.h"
#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>


#define RIGHT (x + 1)
#define BOTTOM (y + 1)
#define LEFT (x - 1)
#define TOP (y - 1)
#define STRDUP(x) ((str = strdup(x)) ? str : (exit(1), NULL))



/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
    int x;
    int y;
} point_t;




queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);
int backtrack_rec(char **map, int x, int y, int rows, int cols, point_t const *start, point_t const *target, queue_t **path);

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);

#endif
