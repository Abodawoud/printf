
/**
 * after_percent - .
 * @s: .
 * @arg: .
 * @len: .
 * @i: .
 * Return: on success, .
 *         on error, -1 is returned, and errno is set appropriately
 */
int after_percent(char s, va_list arg, int len)
{
	switch (s)
	{
	case '\0':
		return (-1);
	case 's':
		len += string(len, (va_arg(arg, char*)));
		break;
	case 'c':
		len += ch(len, (va_arg(arg, int)));
		break;
	case '%':
		len++;
		write(1, "%", 1);
		break;
	case 'd':
		len += printdecimal(va_arg(arg, int));
		break;
	case 'i':
		len += printdecimal(va_arg(arg, int));
		i += 2;
		break;
	}
}
