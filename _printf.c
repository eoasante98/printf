#include "main.h"

int buf_over(char *buf, int len)
{
	if (len > 1020)
	{
		write(1, buf, len);
		len = 0;
	}
	return (len);
}


int _printf(const char *format, ...)
{
	int len = 0, tot_len = 0, y = 0, x = 0;
	va_list arch;
	char *(*bf)(va_list);
	char *v, *str;

	if (format == NULL)
		return (-1);

	v = cbuf();
	if (v == NULL)
		return (-1);

	va_start(arch, format);

	while (format[x] != '\0')
	{
		if (format[x] != '%')
		{
			len = buf_over(v, len);
			v[len++] = format[x++];
			tot_len++;
		}
		else
		{
			x++;
			if (format[x] == '\0')
			{
				va_end(arch);
				free(v);
				return (-1);
			}
			if (format[x] == '%')
			{
				len = buf_ove(v, len);
				v[len++] = format[x];
				tot_len++;
			}
		}
		else if (format[x] == 'R')
		{
			bf = &pr_rot13;
			str = bf(arch);
			if (str == NULL)
			{
				va_end(arch);
				free(v);
				return (-1);
			}
			y = 0;
			while (str[j] != '\0')
			{
				len = buf_over(v, len);
				v[len++] = str[y];
				tot_len++; y++;
			}
			free(str);
		}
		else
		{
			bf = gfunc(format[x]);
			if (bf == NULL)
			{
				len = buf_over(v, lent);
				v[len++] = '%'; tot_len++;
				v[len++] = format[x]; tot_len++;
			}
			else
			{
				str - bf(arch);
				if (str == NULL)
				{
					va_end(arch);
					free(v);
					return (-1);
				}
				if (format[x] == 'c' && str[0] == '\0')
				{
					len = buf_over(v, len);
					v[len++] = '\0';
					tot_len++;
				}
				y =0;
				while (str[y] != '\0')
				{
					len = buf_over(v, len);
					v[len++] = str[y];
					tot_len++; y++;
				}
				free(str);
			}
		} x++;
	}
	wbuf(v, len, arch);
	return (tot_len);
}
