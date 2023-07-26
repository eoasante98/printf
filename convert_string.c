#include "main.h"


/**
 * conv_s - converts ...
 * @args: va_list ...
 * @flgs: flag ...
 * @prec: precision ...
 * @out: buff_t struct ...
 * @len: length...
 * @wth: ...
 * Return: number of bytes to buffer
 */
unsigned int conv_s(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int sz;
	unsigned int t = 0;

	(void)flgs;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(out, null, 6));

	for (sz = 0; *(str + sz);)
		sz++;

	t += pr_str_wth(out, flgs, wth, prec, sz);

	prec = (prec == -1) ? sz : prec;
	while (*str != '\0' && prec > 0)
	{
		t += _memcpy(out, str, 1);
		prec--;
		str++;
	}

	t += pr_nwth(out, t, flgs, wth);

	return (t);
}

/**
 * conv_S - converts ...
 * @flgs: flags ...
 * @prec: precision
 * @args: va_list pointer ..
 * @wth: width ...
 * @len: length
 * @out: buff_t struct ..
 *
 * Return: number of bytes in buffer
 */

unsigned int conv_S(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int sz, ind;
	unsigned int t = 0;

	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(out, null, 6));

	for (sz = 0; str[sz];)
		sz++;

	t += pr_str_wth(out, flgs, wth, prec, sz);

	prec = (prec == -1) ? sz : prec;
	for (ind = 0; *(str + ind) != '\0' && ind < prec; ind++)
	{
		if (*(str + ind) < 32 || *(str + ind) >= 127)
		{
			t += _memcpy(out, hex, 2);
			if (*(str + ind) < 16)
				t += _memcpy(out, &zero, 1);
			t += conv_ubase(out, *(str + ind),
					"0123456789ABCDEF", flgs, 0, 0);
			continue;
		}
		t += _memcpy(out, (str + ind), 1);
	}
	t += pr_nwth(out, t, flgs, wth);

	return (t);
}

/**
 * conv_r - reverses ...
 * @flgs: flag ...
 * @args: va_list ...
 * @wth: ...
 * @prec: precision ...
 * @out: buff_t ...
 * @len: length ...
 * Return: number of bytes ...
 */

unsigned int conv_r(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int sz, end, x;
	unsigned int t = 0;

	(void)flgs;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(out, null, 6));

	for (sz = 0; *(str + sz);)
		sz++;

	t += pr_str_wth(out, flgs, wth, prec, sz);

	end = sz - 1;
	prec = (prec == -1) ? sz : prec;
	for (x = 0; end >= 0 && x < prec; x++)
	{
		t += _memcpy(out, (str + end), 1);
		end--;
	}

	t += pr_nwth(out, t, flgs, wth);

	return (t);
}

/**
 * conv_R - converts rot13 ...
 * @flgs: flag ...
 * @prec: precision ...
 * @args: va_list ...
 * @len: length ...
 * @out: buff_t struct ...
 * Return: number of bytes ...
 */
unsigned int conv_R(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	char *lett = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int x, y, sz;
	unsigned int t = 0;

	(void)flgs;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(out, null, 6));

	for (sz = 0; *(str + sz);)
		sz++;

	t += pr_str_wth(out, flgs, wth, prec, sz);

	prec = (prec == -1) ? sz : prec;
	for (x = 0; *(str + x) != '\0' && x < prec; x++)
	{
		for (y = 0; y < 52; y++)
		{
			if (*(str + x) == *(lett + y))
			{
				t += _memcpy(out, (rot13 + y), 1);
				break;
			}
		}
		if (y == 52)
			t += _memcpy(out, (str + x), 1);
	}

	t += pr_nwth(out, t, flgs, wth);

	return (t);
}
