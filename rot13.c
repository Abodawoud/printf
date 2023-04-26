#include "main.h"
/**
 * rot13 - Function that rotate 13
 * @arg: Variadic Arguments from user [string]
 * Return: Length of string
 * Example : A => N , B => O
 */
int rot13(va_list arg)
{
	int len = 0, i;
	char *s = va_arg(arg, char *);
	char str;

	if (s == NULL)
	{
		return (0);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		if ((*(s + i) >= 'a' && *(s + i) <= 'z') ||
		(*(s + i) >= 'A' && *(s + i) <= 'Z'))
		{
			if ((*(s + i) >= 'a' && *(s + i) <= 'm') ||
			(*(s + i) >= 'A' && *(s + i) <= 'M'))
			{
				str = (*(s + i) + 13);
				write(1, &str, 1);
				len++;
			}
			else
			{
				str = (*(s + i) - 13);
				write(1, &str, 1);
				len++;
			}
		}
		else
		{
			write(1, (s + i), 1);
			len++;
		}
	}
	return (len);
}
