#include "main.h"

/**
 * buf_over - if writing over buffer space, print and reset to 0
 * @buf: buffer
 * @len: position
 * Return: length of position
 */

int buf_over(char *buf, int len)
{
	if (len > 1020)
	{
		write(1, buf, len);
		len = 0;
	}
	return (len);
}

/**
 * hold_con - handles conversin specifiers in _printf
 * @format: string format
 * @arch: va_list
 * @v: buffer
 * @len: lenght
 * @tot_len: total length
 * Return: length of output, -1 otherwise
 */

int hold_con(const char *format, va_list arch, char *v, int len, int tot_len)
{
	int x = 0, y = 0;
	char *str;
	char *(*bf)(va_list);

	while (format[x] != '\0')
	{
		if (format[x] != '%') /*copy format into buffer until '%'*/
		{
			v[len++] = format[x++];
			tot_len++;
		}
		else /*if %, find function*/
		{
			x++;
			if (format == '\0')
				return (-1);
			if (format[x] == '%') /*handles double %x*/
			{
				v[len++] = format[x];
				tot_len++;
			}
			else if (format[x] == 'R')
			{
				bf = &pr_rot13; /*use pr_rot13 functions*/
				str = bf(arch); /*call the function*/
				if (str == NULL)
					return (-1);
				while (str[y])
				{
					v[len++] = str[y++];
					tot_len++;
				}
				free(str);
			}
			else
				return (x);
			x++;
		}
	}
	return (x);
}

/**
 * hold_reg_chars - Handles regular characters in _printf
 * @format: string format
 * @v: buffer
 * @len: length of buffer
 * @tot_len: total length
 */

void hold_reg_chars(const char *format, char *v, int len, tot_len)
{
	while (format && format != '%')
	{
		len = buf_over(v, len);

		v[len] = format++;
		len++;
		tot_len++;
	}
}

/**
 * _printf - mini printf version
 * @format: initial string
 * Return: strings
 */

int _printf(const char *format, ...)
{
	va_list arch;
	char *v;
	int len = 0, tot_len = 0;

	len = buf_over(v, len);

	if (!format)
		return (-1);

	v = cbuf();
	if (!v)
		return (-1);

	va_start(arch, format);

	res = hold_con(format, arch, v, &len, &tot_len);
	if (res == -1)
	{
		va_end(arch);
		free(v);
		return (-1);
	}

	hold_reg_char(fomat + res, v, &len, $tot_len);

	wbuf(v, len, arch);

	va_end(arch);
	return (tot_len);
}
