#include "main.h"

/**
 * h_flgs - correspond values to flags
 * @flg: pointer to flag
 * @ind: index
 *
 * Return: flag char, 0 otherwise
 */

unsigned char h_flgs(const char *flg, char *ind)
{
	int x, y;
	unsigned char t = 0;
	flg_t flgs[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (x = 0; flg[x]; x++)
	{
		for (y = 0; flgs[y].flg != 0; y++)
		{
			if (flg[x] == flgs[y].flg)
			{
				(*ind)++;
				if (t == 0)
					t = flgs[y].val;
				else
					t |= flgs[y].val;
				break;
			}
		}
		if (flgs[y].val == 0)
			break;
	}
	return (t);
}

/**
 * h_length - corresponds value to length of modifiers
 * @modifier: pointer ...
 * @ind: ...
 * Return: length modifier value, 0 otherwise
 */
unsigned char h_length(const char *modifier, char *ind)
{
	if (*modifier == 'h')
	{
		(*ind)++;
		return (SHORT);
	}
	else if (*modifier == 'l')
	{
		(*ind)++;
		return (LONG);
	}
	return (0);
}

/**
 * h_wth - ...
 * @args: va_list ...
 * @modifier: pointer ...
 * @ind: index ...
 * Return: width ...
 */
int h_wth(va_list args, const char *modifier, char *ind)
{
	int val = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*ind)++;

		if (*modifier == '*')
		{
			val = va_arg(args, int);
			if (val <= 0)
				return (0);
			return (val);
		}

		val *= 10;
		val += (*modifier - '0');
		modifier++;
	}
	return (val);
}

/**
 * h_p - precision modifier ...
 * @args: va_list ...
 * @modifier: pointer ...
 * @ind: index ...
 * Return: precision modifier ....
 */
int h_p(va_list args, const char *modifier, char *ind)
{
	int val = 0;

	if (*modifier != '.')
		return (-1);

	modifier++;
	(*ind)++;

	if ((*modifier <= '0' || *modifier > '9') && *modifier != '*')
	{
		if (*modifier == '0')
			(*ind)++;
		return (0);
	}
	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*ind)++;

		if (*modifier == '*')
		{
			val = va_arg(args, int);
			if (val <= 0)
				return (0);
			return (val);
		}
		val *= 10;
		val += (*modifier - '0');
		modifier++;
	}
	return (val);
}

/**
 * h_spec - conversion specifier ...
 * @specifier: pointer ...
 * - int: integer
 * - char: character
 * Return: convertion pointer ...
 */
unsigned int (*h_spec(const char *specifier))(va_list, buff_t *,
		unsigned char, int, int, unsigned char)
{
	int x;
	convert_t converts[] = {
		{'c', conv_c},
		{'s', conv_s},
		{'i', conv_di},
		{'d', conv_di},
		{'%', conv_percent},
		{'u', conv_u},
		{'b', conv_b},
		{'x', conv_x},
		{'X', conv_X},
		{'o', conv_o},
		{'R', conv_R},
		{'S', conv_S},
		{'p', conv_p},
		{'r', conv_r},
		{0, NULL}
	};

	for (x = 0; converts[x].bf; x++)
	{
		if (converts[x].specifier == *specifier)
			return (converts[x].bf);
	}
	return (NULL);
}
