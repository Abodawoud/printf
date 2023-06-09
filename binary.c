#include "main.h"
/**
 * binary - Function that convert decimal to binary
 * @arg: Variadic Arguments from user [Int]
 * Return: length digits
 */

int binary(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int), len, i, m, temp;
	char *s;

	len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	m = n;
	temp = n;
	while (m)
	{
		len++;
		m /= 2;
	}
	s = malloc(len + 1);
	if (s == NULL)
		return (0);
	for (i = len - 1; temp != 0; i--)
	{
		s[i] = (temp % 2) + '0';
		temp /= 2;
	}
	s[len] = '\0';
	for (i = 0; i < len; i++)
		write(1, &s[i], 1);
	free(s);
	return (len);
}
