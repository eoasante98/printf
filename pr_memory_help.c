#include "main.h"

unsigned int _memcpy(buff_t *out, const char *src, unsigned int n);
void free_buff(buff_t *out);
buff_t *init_buff(void);
/**
 * _memcpy - bytes of memory copied from src
 * @out: buffer_t struct
 * @src: source pointer
 * @n: number of bytes
 * Return: copied bytes
 */
unsigned int _memcpy(buff_t *out, const char *src, unsigned int n)
{
	unsigned int ind;

	for (ind = 0; ind < n; ind++)
	{
		*(out->buff) = *(src + ind);
		(out->len)++;

		if (out->len == 1024)
		{
			write(1, out->st, out->len);
			out->buff = out->st;
			out->len = 0;
		}

		else
			(out->buff)++;
	}
	return (n);
}

/**
 * free_buff - Frees 1 buff_t struct
 * @out: The buff_t struct to be freed
 */
void free_buff(buff_t *out)
{
	free(out->st);
	free(out);
}

/**
 * init_buff - starts a struct type buff_t variable
 *
 * Return: pointer to buff_t
 */
buff_t *init_buff(void)
{
	buff_t *out;

	out = malloc(sizeof(buff_t));
	if (out == NULL)
		return (NULL);

	out->buff = malloc(sizeof(char) * 1024);
	if (out->buff == NULL)
	{
		free(out);
		return (NULL);
	}
	out->st = out->buff;
	out->len = 0;

	return (out);
}
