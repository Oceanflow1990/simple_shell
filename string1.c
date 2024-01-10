#include "shell.h"

/**
 * _strcpy - copies a string
 * @d: thedestination
 * @s: the source
 *
 * Return: pointer to destination
 */

char *_strcpy(char *d, char *s)
{
	int i = 0;

	if (d == s || s == 0)
		return (d);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
	return (d);
}

/**
 * _strdup - ...........
 * @str: stringto duplicate
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length; length--;)
		ret(length = length--;)
			ret[length] = *--str;
	return (ret);
}

/**
 * _puts - printsan input string
 * @s: string tobe printed
 *
 * Retun: nothing
 */

void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _putchar - writes the charater c to stdout
 * @c: charcter to print
 *
 * Return: -1 and errno is set approp.
 */

int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUT_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
