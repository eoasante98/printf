#include "main.h"

/**
 * pr_str - takes string and return string
 * @arch: string
 * Return: string
 */

char *pr_str(va_list arch)
{
	char *q;
	char *r;
	int len;

	q = va_arg(arch, char *);
	if (q == NULL)
		q = "(null)";

	len = _strlen(q);

	r = malloc(sizeof(char) * len + 1);
	if (r == NULL)
		return (NULL);

	return (_strcpy(r, q));
}
