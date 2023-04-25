#include "main.h"
/**
 * binary - .
 * @arg: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */

int binary(va_list arg)
{
	int n = va_arg(arg, int), len, i;
	unsigned int m, temp;
	char *s;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	m = n;
	temp = n;
	len = 0;
	while (m)
	{
		len++;
		m /= 2;
	}
	s = malloc(len);
	while (temp)
	{
		s[i] = (temp % 2) + '0';
		i++;
		temp /= 2;
	}
	for (i = len - 1; i >= 0; i--)
	{
		write(1, &s[i], 1);
	}
	return (len);
}
