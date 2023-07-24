#include "main.h"
/**
 * _strlen - prints string length
 * @s: string to function
 * Return: ...
 */
int _strlen(char *s)
{
	int t = 0;

	while (s[t] != '0')
		t++;

	return (t);
}
