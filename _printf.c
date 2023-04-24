#include "main.h"
/**
 * printdecimal - .
 *@len: .
 *@args: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int printdecimal(int n)
{
    int len = 0;
	unsigned int m, d, count;

	if (n == 0)
	{
		putchar(48);
		return (++len);
	}
	if (n < 0)
	{
		putchar(45);
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
		putchar(((m / count) % 10) + 48);
		len++;
		count /= 10;
	}
	return (len);
}
/**
 * string - .
 *@len: .
 *@s: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int string(int len, char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		len += 6;
	}
	else
	{
		len += (int)strlen(s);
		write(1, s, ((int)strlen(s)));
	}
	return (len);
}
/**
 * ch - .
 *@len: .
 *@s: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int ch(int len, char s)
{
	len++;
	write(1, &s, 1);
	return (len);
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

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (format[i] && format)
	{
		if ((format[i] == '%'))
		{
			if (format[i + 1] == '\0')
				return (-1);
			else if (format[i + 1] == 's')
			{
				len = string(len, (va_arg(arg, char*)));
				i += 2;
			} else if (format[i + 1] == 'c')
			{
				len = ch(len, (va_arg(arg, int)));
				i += 2;
			} else if ((format[i + 1] == '%'))
			{
				len++;
				write(1, "%", 1);
				i += 2;
			} else if ((format[i + 1] == 'd') || (format[i + 1] == 'i'))
			{
				len += printdecimal(va_arg(arg, int));
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
