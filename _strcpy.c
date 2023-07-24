#include "main.h"

/**
 * _strcpy - copies something
 * @des: destination
 * @src: source
 * Return: array
 */
char *_strcpy(char *des, char *src)
{
	int v = 0;

	while (src[v] != '\0')
	{
		des[v] = src[v];
		v++;
	}

	des[v] = src[v];
	return (des);
}
