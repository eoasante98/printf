#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>

/* length modify */
#define LONG 2
#define SHORT 1

/* Flags */
#define NEG 16
#define SPACE 2
#define ZERO 8
#define PLUS 1
#define HASH 4
#define ZERO_FLG ((flgs >> 3) & 1)
#define SPACE_FLG ((flgs >> 1) & 1)
#define PLUS_FLG (flgs & 1)
#define NEG_FLG ((flgs >> 4) & 1)
#define HASH_FLG ((flgs >> 2) & 1)

/**
 * struct buff_s - define buffer struct
 * @buff: ...
 * @st: ...
 * @len: ...
 */

typedef struct buff_s
{
	char *buff;
	char *st;
	unsigned int len;
} buff_t;

/**
 * struct convert_s - define converter struct
 * @specifier: ..
 * @bf: ...
 * Parameters:
 * - va_list: va_list argument
 * - int: integer
 * - int: integer
 * - int: integer
 */
typedef struct convert_s
{
	unsigned char specifier;
	unsigned int (*bf)(va_list, buff_t *, unsigned char,
			int, int, unsigned char);
} convert_t;

/**
 * struct flg_s - define flags struct
 * @flg: ...
 * @val: ...
 */

typedef struct flg_s
{
	unsigned char flg;
	unsigned char val;
} flg_t;

int _printf(const char *format, ...);

/* conversions*/
unsigned int conv_c(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_s(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_percent(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_u(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_di(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_b(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_X(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_x(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_o(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_p(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_S(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_R(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);
unsigned int conv_r(va_list args, buff_t *out, unsigned char flgs,
		int wth, int prec, unsigned char len);

/* helpers */
void free_buff(buff_t *out);
unsigned int conv_sbase(buff_t *out, long int num, char *base,
		unsigned char flgs, int wth, int prec);
buff_t *init_buff(void);
unsigned int conv_ubase(buff_t *out, unsigned long int num, char *base,
		unsigned char flgs, int wth, int prec);
unsigned int _memcpy(buff_t *out, const char *src, unsigned int n);

/* handling */
/**
 * h_spec - handle specifier
 */
int _strlen(char *s);
int h_p(va_list args, const char *modifier, char *ind);
unsigned char h_flgs(const char *flgs, char *ind);
int h_wth(va_list args, const char *modifier, char *ind);
unsigned char h_length(const char *modifier, char *ind);
unsigned int (*h_spec(const char *spec))(va_list, buff_t *,
		unsigned char, int, int, unsigned char);

/* modifiers */
unsigned int pr_str_wth(buff_t *out, unsigned char flgs, int wth,
		int prec, int sz);
unsigned int pr_wth(buff_t *out, unsigned int printed,
		unsigned char flgs, int wth);
unsigned int pr_nwth(buff_t *out, unsigned int printed,
		unsigned char flgs, int wth);

#endif /* MAIN_H */
