#include "main.h"
/**
 * percent - .
 *@len: .
 *@s: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int percent(int len, char *s)
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
 * _printf - .
 *@format: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int len, i;
	char c;

	if (format == NULL)
		return (-1);
	len = (int)strlen(format);
	va_start(arg, format);
	i = 0;
	while (format[i] && format)
	{
		if ((format[i] == '%') )
		{
			if (format[i + 1] == 's')
				len = percent(len, (va_arg(arg, char*)));
			if (format[i + 1] == 'c')
			{
				len -= 2;
				len++;
				c = va_arg(arg, int);
				write(1, &c, 1);
			}
			if ((format[i + 1] == '%'))
			{
				i += 2;
				len--;
				write(1, "%", 1);
				continue;
			}
		}
		else if ((format[i - 1] == '%') && ((format[i] == 's') || (format[i] == 'c')))
		{
			i++;
			continue;
		}
		else
			write(1, &(format[i]), 1);
		i++;
	}
	return (len);
}
