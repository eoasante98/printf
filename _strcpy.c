#include "main.h"
/**
 * _strcpy - copies something
 * @des: ...
 * @src: ...
 * Return: maybe array?
 */
char *_strcpy(char *des, char *src)
{
	int w = 0;

	while (src[w] != '\0')
	{
		des[w] = src[w];
		w++;
	}

	des[w] = src[w];
	return (des);
}
