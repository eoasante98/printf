#include "main.h"

/**
 * pr_octal - change int to actal
 * @arch: int to change
 * Return: string with octal
 */

char *pr_octal(va_list arch)
{
	int y = 0, infin = 1;
	int x, m;
	char *q;

	m = va_arg(arch, int);
	x = m;

	q = malloc(sizeof(char) * 12);
	if (q == NULL)
		return (NULL);

	if (m < 0)
	{
		q[0] = 1 + '0';
		y++;
		m *= -1;
		x *= -1;
	}

	while (m > 1)
	{
		m /= 8;
		infin *= 8;
	}

	while (infin > 0)
	{
		q[y++] = (x / infin + '0');
		x %= infin;
		infin /= 8;
	}
	q[y] = '\0';

	return (q);
}
