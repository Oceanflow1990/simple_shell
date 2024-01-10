#include "shell.h"

/**
 * _erratoi - converts a string to an interger
 * @s: string to be converted
 *
 * Return: 0 otherwise -
 */

int _erratoi(char *s)
{
	int i = 0;
	unsigned long int prod = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			prod *= 10;
			prod += (s[i] - '0');
			if (prod > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (prod);
}

/**
 * print_error - printsan error message
 * @info: paramter
 * @estr: string containing specified error type
 * Return: 0 otherwise -1
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - print a decimal nu.
 * @input: input
 * @fd: file descriptor
 *
 * Return: character printed
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - convert function of itoa clone
 * @n: number
 * @s: base
 * @flag: argument flag
 *
 * Return: string
 */

char *convert_number(long int n, int s, int flag)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n;

	if (!(flags & CONVER_UNSIGED) && n < 0)
	{
		n = -n;
		sign = '-';
	}
	array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % s];
		n /= s;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf:  address of the string
 *
 * Return: 0;
 */

void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
