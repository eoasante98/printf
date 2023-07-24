#include "main.h"

/**
 * pr_rot13 - encrypts string with rot 13
 * @arch: string to change
 * Return: modified string
 */
char *pr_rot13(va_list arch)
{
	int x = 0;
	char *pstr;
	char *str;

	str = va_arg(arch, char *);
	/*access va_arg once*/
	pstr = malloc(sizeof(char) * (_strlen(str) + 1));
	if (pstr == NULL)
		return (NULL);

	while (str[x] != '\0')
	{
		if ((str[x] >= 'a' && str[x] <= 'm') || (str[x] >=
					'A' && str[x] <= 'M'))
			pstr[x] = str[x] + 13;

		else if ((str[x] >= 'n' && str[x] <= 'z') || (str[x] >=
					'N' && str[x] <= 'Z'))
			pstr[x] = str[x] - 13;

		else
			(pstr[x] = str[x]);
		x++;
	}
	pstr[x] = '\0';

	return (pstr);
}
