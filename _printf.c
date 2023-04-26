#include "main.h"
/**
 * if_specifier - Function that compare the specifier to get
 * the function of the specifier
 * @choose_specifier: character argument
 * @s: character argument
 * Return: i to get the first index from the choose_specifier[i]
 */
int if_specifier(choose_t choose_specifier[], char s)
{
	int i;

	for (i = 0; i < 8; i++)
	{
		if (s == choose_specifier[i].c)
			return (i);
	}
	return (-5);
}
/**
 * decimal - Function that print Numbers.
 *@arg: Variadic Arguments from user [Int]
 * Return: Length of digits
 */
int decimal(va_list arg)
{
	int n = va_arg(arg, int);
	int len = 0;
	unsigned int m, d, count;

	if (n == 0)
	{
		write(1, "0", 1);
		return (++len);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		m = n * -1;
	}
	else
	{
		m = n;
	}
	d = m;
	count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}
	while (count >= 1)
	{
		char s = ((m / count) % 10) + '0';

		write(1, &s, 1);
		len++;
		count /= 10;
	}
	return (len);
}
/**
 * string - Function that print String.
 *@arg: Variadic Arguments from user [String]
 * Return: Length of string
 */
int string(va_list arg)
{
	char *s = va_arg(arg, char*);

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		write(1, s, ((int)strlen(s)));
	}
	return ((int)strlen(s));
}
/**
 * ch - Function that print characters.
 *@arg: Variadic Arguments from user [character]
 * Return: Length 1 that equal one character
 */
int ch(va_list arg)
{
	char s = va_arg(arg, int);

	write(1, &s, 1);
	return (1);
}
/**
 * _printf - Function that print the format with handling the specifier.
 *@format: Fixed argument that take specifier
 * Return: Length of format
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int len = 0, i = 0;
	int spec_idx;

	choose_t choose_specifier[] = {{'c', ch}, {'s', string},
	{'d', decimal}, {'i', decimal}, {'r', reverse}, {'R', rot13},
	{'b', binary}, {'p', pointer}};
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (format[i] && format)
	{
		spec_idx = if_specifier(choose_specifier, format[i + 1]);
		if ((format[i] == '%'))
		{
			if (format[i + 1] == '\0')
				return (-1);
			else if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				len++;
				i += 2;
			} else if (spec_idx >= 0)
			{
				len += choose_specifier[spec_idx].ptr(arg);
				i += 2;
			} else
			{
				len++;
				write(1, &(format[i]), 1);
				i++;
			}
		} else
		{
			len++;
			write(1, &(format[i]), 1);
			i++;
		}
	}
	return (len);
}
