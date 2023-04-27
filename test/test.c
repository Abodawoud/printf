#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;
	/*int len, len2;
	len = _printf("%R\n","{1NNnn2}");
	printf("len %d\n", len);

	len = _printf("%r","Hello");
	len2 = printf("");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);*/
	
	
	len =_printf("%p\n", (void *)NULL);
	printf("len %d\n", len);
	len2 = printf("%p\n", (void *)NULL);
	printf("len %d\n", len2);

	len =_printf("%p, %p\n", (void *)0x7fff5100b6f8, (void *)0x7fff5100b6f8);
	printf("len %d\n", len);
	len2 = printf("%p, %p\n", (void *)0x7fff5100b6f8, (void *)0x7fff5100b6f8);
	printf("len %d\n", len2);
    return (0);
}
