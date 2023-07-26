#include "main.h"

/**
 * pr_wth - stores width modifier
 * @out: contains a character array
 * @printed: current number of characters already printed to output for a given number specifier
 * @flgs: flag modifier
 * @wth: width modifier
 * Return: number of bytes in buffer
 */

unsigned int pr_wth(buff_t *out, unsigned int printed,
		unsigned char flgs, int wth)
{
	unsigned int t = 0;
	char bth = ' ';

	if (NEG_FLG == 0)
	{
		for (wth -= printed; wth > 0;)
			t += _memcpy(out, &bth, 1);
	}

	return (t);
}

/**
 * pr_str_wth - stores leading spaces to a buffer for a width mod
 * @out: character array container
 * @flgs: flag modifier
 * @wth: width modifier
 * @prec: precision modifier
 * @sz: string size
 * Return: number of bytes in buffer
 */

unsigned int pr_str_wth(buff_t *out, unsigned char flgs,
		int wth, int sz, int prec)
{
	unsigned int t = 0;
	char bth = ' ';

	if (NEG_FLG == 0)
	{
		wth -= (prec == -1) ? sz : prec;
		for (; wth > 0; wth--)
			t += _memcpy(out, &bth, 1);
	}

	return (t);
}

/**
 * pr_nwth - stores trailing spaces to a buffer for a '-' flag
 * @out: character array container
 * @printed: number of bytes already stored to output for a given specifier
 * @flgs: flag modifiers
 * @wth: width modifier
 * Return: number of bytes in buffer
 */

unsigned int pr_nwth(buff_t *out, unsigned int printed,
		unsigned char flgs, int wth)
{
	unsigned int t = 0;
	char bth = ' ';

	if (NEG_FLG == 1)
	{
		for (wth -= printed; wth > 0; wth--)
			t += _memcpy(out, &bth, 1);
	}

	return (t);
}
