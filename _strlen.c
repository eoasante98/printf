#include "main.h"

/**
 * _strlen - length of string
 * @s: string
 * Return: w
 */
int _strlen(char *s)
{
	int w = 0;

	while (s[w] != '\0')
		w++;

	return (w);
}
