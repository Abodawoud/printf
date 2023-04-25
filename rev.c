#include "main.h"
/**
 * reverse - .
 * @arg: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int reverse(va_list arg)
{
	int i;
	char *s = va_arg(arg, char*), temp;

	if (s == NULL)
		return (0);
		for (i = 0; i < ((int)strlen(s)) / 2; i++)
		{
			temp = s[i];
			s[i] = s[(int)strlen(s) - 1 - i];
			s[(int)strlen(s) - 1 - i] = temp;
		}
		for (i = 0; i < (int)strlen(s); i++)
			write(1, &s[i], 1);
	return ((int)strlen(s));
}
