#include "main.h"

int _strlen(char *s)
{
	int w = 0;

	while (s[w] != '\0')
		w++;

	return (w);
}
