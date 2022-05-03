#include "huffman.h"

/**
 * symbol_create - Creates symbol
 * @data: Data
 * @freq: frequency
 * Return: Pointer to new symbol or NULL
 */

symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *symbol = malloc(sizeof(*symbol));

	if (!symbol)
		return (NULL);

	symbol->data = data;
	symbol->freq = freq;

	return (symbol);
}
