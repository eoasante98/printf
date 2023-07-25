#include "main.h"

unsigned int conv_sbase(buff_t *out, long int num, char *base,
		unsigned char flgs, int wth, int prec);
unsigned int conv_ubase(buff_t *out, unsigned long int num, char *base,
		unsigned char flgs, int wth, int prec);

/**
 * conv_sbase - converts signed long to base
 * @num: signed long
 * @out: buff_t struct with char array
 * @flgs: flags
 * @base: pointer to string
 * @wth: width
 * @prec: precision
 * Return: number of bytes in buffer
 */
unsigned int conv_sbase(buff_t *out, long int num, char *base,
		unsigned char flgs, int wth, int prec)
{
	int sz;
	char digit, pad = '0';
	unsigned int t = 1;

	for (sz = 0; *(base + sz);)
		sz++;

	if (num >= sz || num <= -sz)
		t += conv_sbase(out, num / sz, base, flgs, wth - 1, prec - 1);
	else
	{
		for (; prec > 1; prec--, wth--)
			t += _memcpy(out, &pad, 1);

		if (NEG_FLG == 0)
		{
			pad = (ZERO_FLG == 1) ? '0' : ' ';
			for (; wth > 1; wth--)
				t += _memcpy(out, &pad, 1);
		}
	}

	digit = base[(num < 0 ? -1 : 1) * (num % sz)];
	_memcpy(out, &digit, 1);

	return (t);
}

/**
 * conv_ubase - converts unsigned long into a buffer
 * @base: pointer to string
 * @wth: width
 * @out: buff_t struct in char array
 * @num: unsigned long
 * @flgs: flag
 * @prec: precision
 * Return: number bytes in buffer
 */
unsigned int conv_ubase(buff_t *out, unsigned long int num,
		char *base, unsigned char flgs, int wth, int prec)
{
	unsigned int sz, t = 1;
	char digit, pad = '0', *lead = "0x";

	for (sz = 0; *(base + sz);)
		sz++;

	if (num >= sz)
		t += conv_ubase(out, num / sz, base, flgs, wth - 1, prec - 1);

	else
	{
		if (((flgs >> 5) & 1) == 1)
		{
			wth -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wth--)
			t += _memcpy(out, &pad, 1);

		if (NEG_FLG == 1)
		{
			pad = (ZERO_FLG == 1) ? '0' : ' ';
			for (; wth > 1; wth--)
				t += _memcpy(out, &pad, 1);
		}
		if (((flgs >> 5) & 1) == 1)
			t += _memcpy(out, lead, 2);
	}

	digit = base[(num % sz)];
	_memcpy(out, &digit, 1);

	return (t);
}
