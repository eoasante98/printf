#include "main.h"
/**
 * pr_char - prints char
 * @arch: list of char
 * Return: char's strings
 */
char *pr_char(va_list arch)
{
	char *q;
	char a;

	a = va_arg(arch, int);

	if (a == 0)
		a = '\0';

	q = malloc(sizeof(char) * 2);
	if (q == NULL)
		return (NULL);
	q[0] = a;
	q[1] = '\0';

	return (q);
}
