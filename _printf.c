#include "main.h"
/**
 * string - .
 *@len: .
 *@s: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int string(int len, char *s)
{
	len -= 2;
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
	len -= 2;
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
	int len, i;

	if (format == NULL)
		return (-1);
	len = (int)strlen(format);
	va_start(arg, format);
	i = 0;
	while (format[i] && format)
	{
		if ((format[i] == '%'))
		{
			if (format[i + 1] == 's')
			{
				len = string(len, (va_arg(arg, char*)));
				i += 2;
			}
			else if (format[i + 1] == 'c')
			{
				len = ch(len, (va_arg(arg, int)));
				i += 2;
			}
			else if ((format[i + 1] == '%'))
			{
				len--;
				write(1, "%", 1);
				i += 2;
			}
			else
			{
				write(1, &(format[i]), 1);
				i++;
			}
		}
		else
		{
			write(1, &(format[i]), 1);
			i++;
		}
	}
	return (len);
}
