#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strncpy - copies a string
 * @dest: destination
 * @src: source string to copy
 * @n: amount of characters to copy
 *
 * Return: concatinated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *_strncat - concatenates two strings
 * @dest: first string
 * @src: secnod string
 * @n: amount of byes to be used
 * Return: concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strnchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 *
 * Return: (s) a pointerto the memory area s
 */

char *_strnchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
