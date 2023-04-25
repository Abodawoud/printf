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
	len = _printf("%R\n","{1NNnn2}");
	printf("len %d\n", len);

	len = _printf("%r","Hello");
	len2 = printf("");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	len = _printf("%b\n", 2);
	printf("len %d\n", len);
	len = _printf("%b\n", -98);
	printf("len %d\n", len);
	len = _printf("%b\n", -1);
	printf("len %d\n", len);
    return (0);
/*	int len, len2;

	len = _printf("%r","Hello");
	len2 = printf("");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	
	len = _printf("%s\n", "emad");
	len2 = printf("%s\n", "emad");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	len = _printf("%%\n");
	len2 = printf("%%\n");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	
	len = _printf(NULL);
	len2 = printf(NULL);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf(NULL, NULL);
	len2 = printf(NULL, NULL);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);


	len = _printf("%s %c %%\n", NULL);
	len2 = printf("%s %c %%\n", NULL);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf("%s  %%%s ff \n", NULL, "jj");
	len2 = printf("%s  %%%s ff \n", NULL, "jj");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf("%s  %%%%s ff \n", NULL, "jj");
	len2 = printf("%s  %%%%s ff \n", NULL, "jj");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	
	len = _printf("%s  %%% s ff \n", NULL, "jj");
	len2 = printf("%s  %%% s ff \n", NULL, "jj");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf("%s  %%%  % ff \n", NULL, "jj");
	len2 = printf("%s  %%%  % ff \n", NULL, "jj");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf("%");
	len2 = printf("%");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	
	len = _printf("len %i\n", -INT_MAX-1);
	len2 = printf("len %i\n", -INT_MAX-1);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf("len %i\n", INT_MAX);
	len2 = printf("len %i\n", INT_MAX);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf("Length:[%d, %i]\n", len, len);
    len2 = printf("Length:[%d, %i]\n", len2, len2);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

    len = _printf("Negative:[%d]\n", -762534);
    len2 = printf("Negative:[%d]\n", -762534);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len =_printf("Len:[%d]\n", len);
    len2 =printf("Len:[%d]\n", len2);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);




	len = _printf("len %d\n", 0377);
	len2 = printf("len %d\n", 0377);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);*/
	
	return 0;
}
