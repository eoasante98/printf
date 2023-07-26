#include "main.h"

/**
 * pr_rot13 - rot13 type of encryption
 * @args: strings
 * Return: updated string
 */
char *pr_rot13(va_list args)
{
	int x = 0;
	char *str;
	char *pstr;

	/*hold va_arg*/
	str = va_arg(args, char *);

	/*new assignment for rot13 char*/
	pstr = malloc(sizeof(char) * (_strlen(str) + 1));
	if (pstr == NULL)
		return (NULL);
	/*str and rot13 to pstr*/
	while (str[x] != '\0')
	{
		if ((str[x] >= 'a' && str[x] <= 'm') || (str[x] >= 'A' && str[x] <= 'M'))
		{
			pstr[x] = str[x] + 13;
		}
		else if ((str[x] >= 'n' && str[x] <= 'z') || (str[x] >= 'N' && str[x] <= 'Z'))
		{
			pstr[x] = str[x] - 13;
		}
		else
			(pstr[x] = str[x]);
		x++;
	}
	pstr[x] = '\0';

	return (pstr);
}
