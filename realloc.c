#include "shell.h"

/**
* _memset - memory with constant byte value
* @s: ptr to memory area
* @b: byte fill *s
* @n: amount of bytes need to be filled
* Return: [s] ptr to the memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
* ffree - frees str. of str.
* @pp: str. of str.
*/
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
* _realloc - re-allocate block of memory
* @ptr: ptr to previous malloc
* @old_size: byte sz of previous
* @new_size: byte sz of new
* Return: ptr to the old block
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
