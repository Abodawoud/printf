#include "main.h"

/**
 * un_int - .
 * @arg: Variadic Arguments from user [Int]
 * Return: length digits
 */

int un_int(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int), m, i, len;
	char *s;

	len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (++len);
	}
	m = n;
	while(n)
	{
		len++;
		n /= 10;
	}
	s = malloc(len + 1);
	i = len - 1;
	while (m)
	{
		s[i] = (m % 10) + '0';
		m /= 10;
		i--;
	}
	for (i = 0; i < len; i++)
		write(1, &s[i], 1);
	s[len] = '\0';

	free(s);
	return(len);
}
