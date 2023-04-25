#include "main.h"
/**
 * binary - .
 * @arg: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */

int binary(va_list arg)
{
	int n = va_arg(arg, int), len, i, flag = 0;
	unsigned int m, temp;
	char *s;

	len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		flag = 1;
		n *= -1;
		write(1, "-", 1);
	}
	i = 0;
	m = n;
	temp = n;
	while (m)
	{
		len++;
		m /= 2;
	}
	s = malloc(len);
	for (i = len - 1; temp; i--)
	{
		s[i] = (temp % 2) + '0';
		temp /= 2;
	}
	for (i = 0; i < len; i++)
		write(1, &s[i], 1);
	if (flag)
		len++;
	return (len);
}
