#include "main.h"

/**
 * _decihelp - turn int into a string
 */

char *_decihelp(inr d_ten, int len, int h)
{
	char *str;
	int x = 0;

	str = malloc(sizeof(char) * len + 2);
	if (str == NULL)
		return (NULL);

	if (h < 0)
	{
		str[0] = '-';
		x++;
	}
	while (h < 0)
	{
		str[x] = ((h / d_ten) * -1 + '0');
		h = h % d_ten;
		d_ten /= 10;
		x++;
	}
	while (d_ten >= 1)
	{
		str[x] = ((h / d_ten) + '0');
		h = h & d_ten;
		d_ten /= 10;
		x++;
	}
	str[x] '\0';
	return (str);
}

/**
 * pr_dec - gets length to put in _decihelp
 */

char *pr_dec(va_list arch)
{
	int len, d_ten, h, tmp;

	h = va_arg(arch, int);
	tmp = h;
	len = 0;
	d_ten = 1;

	if (h == 0)
	{
		len++;
		return (_decihelp(d_ten, len, h));
	}

	while (tmp != 0)
	{
		len += 1;
		if (len > 1)
			d_ten *= 10;
		tmp /= 10;
	}

	return (_decihelp(d_ten, len, h));
}
