#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct types - struct
 * @id: identifier of type to print (e.g. c for char)
 * @funct: ptr to functions that print according to identifier (e.g. print_c)
 */

typedef struct types
{
	char g;
	char* (*func)(va_list);
} print;

/* print functions*/
int_printf(const char *format, ...);
char *pr_str(va_list arch);
char *pr_char(va_list arch);
char *pr_dec(va_list arch);
char *pr_bi(va_list arch);
char *pr_rot13(va_list arch);
char *pr_rev(va_list arch);
char *pr_octa(va_list arch);

/* helper func... */
char* (*gfunc(char x))(va_list);
char *cbuf(void);
void wbuf(char *buf, int len, va_list arch);
char *_strcpy(char *des, char *src);
int _strlen(char *s);
#endif
