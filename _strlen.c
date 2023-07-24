#include "main.h"
/**
 * _strlen - prints string length
 * @s: string to function
 * Return: a
 */
int _strlen(char *s)
{
	int w = 0;

	while (s[w] != '0')
		w++;

	return (w);
}
