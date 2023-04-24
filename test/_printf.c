#include "main.h"
/**
 * printdecimal - .
 *@len: .
 *@args: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int int_length(int number) {
    int length = 0;
    if (number < 0) {
        number = -number;
    }

    while (number > 0) {
        length++;
        number /= 10;
    }

    return length;
}
/**
 * printdecimal - .
 *@len: .
 *@args: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
void intToStr(int num, char *str) {
	int i;
	int j;
	int k;
	int is_negative = 0;

	if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    i = 0;
    while (num > 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }

    if (is_negative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    for (j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}
/**
 * printdecimal - .
 *@len: .
 *@args: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int printdecimal(int len, va_list args)
{
	int n = va_arg(args, int);
	char *s;
	s = malloc(int_length(n));
	intToStr(n, s);
	write(1, s, int_length(n));
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
				len = printdecimal(len, arg);
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
