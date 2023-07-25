#include "main.h"

/**
 * reverse - reverses a string
 * @arch: reversed string
 * Return: reversed [string]
 */
char *pr_rev(va_list arch)
{
	char *back;
	char *str;
	int x = 0, len, y;

	str = va_arg(arch, char *);
	if (str == NULL)
		str = ")llun(";

	len = _strlen(str);

	back = malloc(sizeof(char) * (len + 1));
	if (back == NULL)
		return (NULL);

	for (y = (len - 1); y >= 0; y--)
	{
		back[x++] = str[y];
	}
	back[x] = '\0';

	return (back);
}
