#include "vec.h"

void	OOM_GUARD(void *p, char *file, int number)
{
	if (p == NULL)
	{
		fprintf(stderr, "%s:%d Out of memory", file, number);
		exit(EXIT_FAILURE);
	}
}

void	*M_OOM_GUARD(void *p)
{
	if (p == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}
	return (p);
}
