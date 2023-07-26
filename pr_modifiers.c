#include "main.h"

/**
 * pr_wth - stores width modifier
 * @out: contains a character array
 * @printed: ...
 * @flgs: ...
 * @wth: ...
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
 * pr_str_wth - ...
 * @out: ...
 * @flgs: ..
 * @wth: ...
 * @prec: ...
 * @sz: ...
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
 * pr_nwth - ...
 * @out: ...
 * @printed: ....
 * @flgs: ...
 * @wth: ...
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
