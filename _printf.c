#include "main.h"

/**
 * if_specifier - .
 * @choose_specifier: .
 * @s: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int if_specifier(choose_t choose_specifier[], char s)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (s == choose_specifier[i].c)
			return (i);
	}
	return (-5);

}
/**
 * decimal - .
 *@arg: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
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
 * string - .
 *@arg: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
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
 * ch - .
 *@arg: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int ch(va_list arg)
{
	char s = va_arg(arg, int);

	write(1, &s, 1);
	return (1);
}
int reverse(va_list arg)
{
	int i;
	char *s = va_arg(arg, char*), temp;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		for (i = 0; i < ((int)strlen(s)) / 2; i++)
		{
			temp = s[i];
			s[i] = s[(int)strlen(s) - 1 - i];
			s[(int)strlen(s) - 1 - i] = temp;
		}
		for (i = 0; i < (int)strlen(s); i++)
		{
			write(1, &s[i], 1);
		}
		
	}
	return ((int)strlen(s));
}
/**
 * _printf - .
 *@format: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int len = 0, i = 0;
	int spec_idx;

	choose_t choose_specifier[] = {{'c', ch}, {'s', string},
	{'d', decimal}, {'i', decimal}, {'r', reverse}};

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
