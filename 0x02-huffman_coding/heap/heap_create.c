#include "heap.h"

/**
 * heap_create - Creates heap data struct
 * @data_cmp: pointer to func
 * Return: Pointer or NULL
 *
 */

heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap = malloc(sizeof(heap_t));

	heap->size = 0;
	heap->data_cmp = data_cmp;
	heap->root = NULL;

	return (heap);
}

