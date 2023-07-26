#include "main.h"

unsigned int conv_di(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_b(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_u(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_o(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);

/**
 * conv_di - converts to singed int
 * @out: output
 * @args: argumetns
 * @flgs: flag
 * @len: length
 * @wth: width
 * @prec: precision
 * Return: number of bytes in buffer
 */
unsigned int conv_di(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	long int e, dup;
	unsigned int t = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (len == LONG)
		e = va_arg(args, long int);
	else
		e = va_arg(args, int);
	if (len == SHORT)
		e = (short)e;

	if (SPACE_FLG == 1 && e >= 0)
		t += _memcpy(out, &space, 1);

	if (prec <= 0 && NEG_FLG == 0)
	{
		if (e == LONG_MIN)
			count += 19;
		else
		{
			for (dup = (e < 0) ? -e : e; dup > 0; dup /= 10)
				count++;
		}
		count += (e == 0) ? 1 : 0;
		count += (e < 0) ? 1 : 0;
		count += (PLUS_FLG == 1 && e >= 0) ? 1 : 0;
		count += (SPACE_FLG == 1 && e >= 0) ? 1 : 0;

		if (ZERO_FLG == 1 && PLUS_FLG == 1 && e >= 0)
			t += _memcpy(out, &plus, 1);

		if (ZERO_FLG == 1 && e < 0)
			t += _memcpy(out, &neg, 1);

		pad = (ZERO_FLG == 1) ? '0' : ' ';
		for (wth -= count; wth > 0; wth--)
			t += _memcpy(out, &pad, 1);
	}

	if (ZERO_FLG == 0 && e < 0)
		t += _memcpy(out, &neg, 1);

	if (ZERO_FLG == 0 && (PLUS_FLG == 1 && e >= 0))
		t += _memcpy(out, &plus, 1);

	if (!(e == 0 && prec == 0))
		t += conv_sbase(out, e, "0123456789", flgs, 0, prec);

	t += pr_nwth(out, t, flgs, wth);

	return (t);
}

/**
 * conv_b  - converts unsigned int argument
 * @out: output
 * @flgs: flags
 * @args: argument
 * @prec: precision
 * @len: length
 * @wth: width
 * Return: number of bytes in buffer
 */
unsigned int conv_b(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)len;

	return (conv_ubase(out, num, "01", flgs, wth, prec));
}

/**
 * conv_o - converts unsigned int to octal
 * @prec: precision
 * @args: arguments
 * @flgs: flags
 * @out: output
 * @len: length
 * @wth: width
 *
 * Return: number bytes in buffer
 */
unsigned int conv_o(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int t = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLG == 1 && num != 0)
		t += _memcpy(out, &zero, 1);

	if (!(num == 0 && prec == 0))
		t += conv_ubase(out, num, "01234567", flgs, wth, prec);

	t += pr_nwth(out, t, flgs, wth);

	return (t);
}

/**
 * conv_u - converts unsigned int to octal
 * @flgs: flags
 * @len: length
 * @args: arguments
 * @wth: width
 * @prec: precision
 * @out: output
 * Return: number of bytes to buffer
 */
unsigned int conv_u(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int t = 0;

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (!(num == 0 && prec == 0))
		t += conv_ubase(out, num, "0123456789", flgs, wth, prec);

	t += pr_nwth(out, t, flgs, wth);

	return (t);
}
