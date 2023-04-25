#include "main.h"
/**
 * reverse - .
 * @arg: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
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
