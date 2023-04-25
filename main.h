#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
/**
 * struct choose - .
 *
 * @c: .
 * @ptr: .
 */
typedef struct choose
{
	char c;
	int (*ptr)(va_list arg);
} choose_t;
int _putchar(char c);
int _printf(const char *format, ...);
int printdecimal(va_list arg);
int ch(va_list arg);
int string(va_list arg);
int after_percent(char s, va_list arg, int len, int i);
int if_specifier(choose_t choose_specifier[], char s);
int reverse(va_list arg);

#endif
