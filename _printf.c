#include "main.h"

void wipe(va_list args, buff_t *out);
int r_printf(const char *format, va_list args, buff_t *out);
int _print(const char *format, ...);

/**
 * wipe - cleans operations
 * @args: va_list of arguments
 * @out: buff_t struct
 */
void wipe(va_list args, buff_t *out)
{
	va_end(args);
	write(1, out->st, out->len);
	free_buff(out);
}

/**
 * r_printf - scans format string
 * @format: character string
 * @out: buff_t struct buffer
 * @args: va_list arguments
 * Return: ...
 */
int r_printf(const char *format, va_list args, buff_t *out)
{
	int x, wth, prec, t = 0;
	char tmpo;
	unsigned char flgs, len;
	unsigned int (*f)(va_list, buff_t *, unsigned char, int, int,
			unsigned char);

	for (x = 0; *(format + x); x++)
	{
		len = 0;
		if (*(format + x) == '%')
		{
			tmpo = 0;
			flgs = h_flgs(format + x + 1, &tmpo);
			wth = h_wth(args, format + x + tmpo + 1, &tmpo);
			prec = h_p(args, format + x + tmpo + 1, &tmpo);
			len = h_length(format + x + tmpo + 1, &tmpo);

			f = h_spec(format + x + tmpo + 1);
			if (f != NULL)
			{
				x += tmpo + 1;
				t += f(args, out, flgs, wth, prec, len);
				continue;
			}
			else if (*(format + x + tmpo + 1) == '\0')
			{
				t = -1;
				break;
			}

		}
		t += _memcpy(out, (format + x), 1);
		x += (len != 0) ? 1 : 0;
	}
	wipe(args, out);
	return (t);
}

/**
 * _printf - prints a datatype
 * @format: char string
 * Return: char to print
 */
int _printf(const char *format, ...)
{
	buff_t *out;
	va_list args;
	int t;

	if (format == NULL)
		return (-1);
	out = init_buff();
	if (out ==  NULL)
		return (-1);

	va_start(args, format);

	t = r_printf(format, args, out);

	return (t);
}
