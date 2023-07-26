#include "main.h"

unsigned int conv_x(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_X(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);

/**
 * conv_x - converts unsigned int to hex
 * @out: output
 * @wth: width
 * @flgs: flags
 * @args: arguments
 * @len: length
 * @prec: precision
 *
 * Return: number of bytes in buffer
 */
unsigned int conv_x(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int t = 0;
	char *ld = "0x";

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLG == 1 && num != 0)
		t += _memcpy(out, ld, 2);

	if (!(num == 0 && prec == 0))
		t += conv_ubase(out, num, "0123456789abcdef", flgs, wth, prec);

	t += pr_nwth(out, t, flgs, wth);

	return (t);
}

/**
 * conv_X - converts unsigned int to hex
 * @out: output
 * @prec: precision
 * @args: arguments
 * @flgs: flags
 * @wth: width
 * @len: length
 * Return: number bytes in buffer
 */
unsigned int conv_X(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int t = 0;
	char *ld = "0x";

	if (len == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLG == 1 && num != 0)
		t += _memcpy(out, ld, 2);

	if (!(num == 0 && prec == 0))
		t += conv_ubase(out, num, "0123456789ABCDEF", flgs, wth, prec);

	t += pr_nwth(out, t, flgs, wth);

	return (t);
}
