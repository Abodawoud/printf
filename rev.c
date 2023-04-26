#include "main.h"
/**
 * reverse - Function that reverse string
 * @arg: Variadic Arguments from user [String]
 * Return: Length of string
 */
int reverse(va_list arg)
{
	int i, len;
	char *s = va_arg(arg, char*);

	len = (int)strlen(s);
	if (s == NULL)
		return (0);
	for (i = len - 1; i >= 0; i--)
	{
		write(1, &(s[i]), 1);
	}
	return (len);
}
