#include "shell.h"

/**
* bfree - frees ptr and NULLs addr.
* @ptr: addr. of ptr to be freed
* Return: 1 if successul, else 0.
*/
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
