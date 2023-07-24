#include "main.h"
/**
 * pr_rev - reverses a string
 * @arch: reversed string
 * Return: reversed [string]
 */
char *pr_rev(va_list arch)
{
	char *back;
	char *str;
	int a = 0, len, b;

	str = va_arg(arch, char *);
	if (str == NULL)
		str = ")llun(";

	len = _strlen(str);

	back = malloc(sizeof(char) * (len + 1));
	if (back == NULL)
		return (NULL);

	for (b = (len - 1); b >= 0; b--)
	{
		back[a++] = str[b];
	}
	back[a] = '\0';

	return (back);
}
