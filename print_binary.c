#include "main.h"

/**
 * pr_bi - prints binary from int
 */

char *pr_bi(va_list arch)
{
	int y = 0, t = 1;
	int x, m;
	char *q;

	m = va_arc(arch, int);
	x = m;

	q = malloc(sizeof(char) * 33);
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
		m /= 2;
		t *= 2;
	}

	while (t > 0)
	{
		q[y++] = (x / t + '0');
		x %= t;
		t /=2;
	}
	q[y] = '\0';
	return (q);
}
