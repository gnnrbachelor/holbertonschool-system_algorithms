#include "pathfinding.h"

char **make_copy(char **map, char **map_copy, int rows, int cols)
{
	int i;

	map_copy = malloc(rows * sizeof(char *));
	if (!map_copy)
		exit(1);

	for (i = 0; i < rows; i++)
	{
		map_copy[i] = malloc(cols + 1);
		if (!map_copy[i])
			exit(1);
		strcpy(map_copy[i], map[i]);
	}
	return (map_copy);

}


queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target)
{
	queue_t *path;
	char **map_copy = NULL;
	int i, val;

	if (!map || !*map || !start || !target || !rows || !cols)
		return (NULL);

	map_copy = make_copy(map, map_copy, rows, cols);

	path = queue_create();
	if (!path)
		return (0);

	val = backtrack_rec(map_copy, start->x, start->y, rows, cols, start, target, &path);

	if (!val)
		queue_delete(path), path = NULL;

	for (i = 0; i < rows; i++)
		free(map_copy[i]);

	free(map_copy);

	return (path);
}

point_t *make_point(int x, int y)
{
	point_t *point = malloc(sizeof(point_t));

	if (!point)
		return (NULL);

	point->x = x;
	point->y = y;

	printf("Checking coordinates [%i, %i]\n", x, y);

	return (point);

}

int backtrack_rec(char **map, int x, int y, int rows, int cols, point_t const *start, point_t const *target, queue_t **path)
{
	int r = 0, b = 0, l = 0, t = 0;
	point_t *point = NULL;

	point = make_point(x, y);

	map[y][x] = '1';

	if (target->x == x && target->y == y)
	{
		queue_push_front(*path, point);
		return (1);
	}

	if (RIGHT < cols)
		if (map[y][RIGHT] == '0')
			r = backtrack_rec((char **)map, x + 1, y, rows, cols, start, target, path);

	if (BOTTOM < rows)
		if (map[BOTTOM][x] == '0' && r != 1)
			b = backtrack_rec((char **)map, x, y + 1, rows, cols, start, target, path);
	if (LEFT >= 0)
		if (map[y][LEFT] == '0' && r != 1 && b != 1)
			l = backtrack_rec((char **)map, x - 1, y, rows, cols, start, target, path);
	if (TOP >= 0)
		if (map[TOP][x] == '0' && r != 1 && b != 1 && l != 1)
			t = backtrack_rec((char **)map, x, y - 1, rows, cols, start, target, path);

	if (r == 0 && b == 0 && l == 0 && t == 0)
	{
		free(point);
		return (0);
	}
	queue_push_front(*path, point);
	return (1);

}

