#include "main.h"

/**
 * gfunc - gets needed function
 * @x: identifierof functino
 * Return: pointer to function
 */

char* (*gfunc(char x))(va_list)
{
	int m = 0;

	print these[] = {
		{'c', pr_char}
		{'s', pr_str}
		{'d', pr_dec}
		{'i', pr_dec}
		{'b', pr_bi}
		{'R', pr_rot13}
		{'r', pr_rev}
		{'o', pr_octal}
		{'\0', NULL}
	};

	while (these[m].g != '\0')
	{
		if (these[m].g == x)
			return (these[m].bf);
		m++;
	}
	return (NULL);
}

/**
 * cbuf - hold string in buffer
 * Return: pointer to buffer
 */
char *cbuf(void)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);
		if (buf == NULL)
			return (NULL);
		return (buf);
}

/**
 * wbuf - print buffer, then frees it and frees va_list
 * @buf: buffer
 * @len: length of printeable string
 * @arch: va_list
 */
void wbuf(char *buf, int len, va_list arch)
{
	char *v;

	v = realloc(buf, len);
	write(1, buf, len);

	free(buf);
	va_end(arch);
}
