#include "main.h"
/**
 * octal - Function that convert decimal to octal
 * @arg: Variadic Arguments from user [Int]
 * Return: length digits
 */

int octal(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int), len, i, m, temp;
	char *s;

	len = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = 0;
	m = n;
	temp = n;
	while (m)
	{
		len++;
		m /= 8;
	}
	s = malloc(len + 1);
	if (s == NULL)
		return (0);
	for (i = len - 1; temp != 0; i--)
	{
		if ((temp % 8) < 10)
			s[i] = (temp % 8) + '0';
		temp /= 8;
	}
	s[len] = '\0';
	for (i = 0; i < len; i++)
		write(1, &s[i], 1);
	free(s);
	return (len);
}
