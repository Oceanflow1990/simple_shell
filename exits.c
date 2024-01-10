#include "shell.h"

/**
 * _strcpy - copies a string
 * @de: destination
 * @src: source string to copy
 * @m: amount of characters to copy
 *
 * Return: concatinated string
 */

char *_strcpy(char *de, char *src, int m)
{
	int i, j;
	char *s = de;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		de[i] = src[i];
		i++;
	}
	if (i < m)
	{
		j = i;
		while (j < m)
		{
			de[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *_strncat - concatenates two strings
 * @de: first string
 * @src: secnod string
 * @m: amount of byes to be used
 * Return: concatenated string
 */

char *_strncat(char *de, char *src, int m)
{
	int i, j;
	char *s = de;

	i = 0;
	j = 0;
	j = 0;
	while (de[i] != '\0')
		i++;
	while (src[j] != '\0' && j < m)
	{
		de[i] = src[j];
		i++;
		j++;
	}
	if (j < m)
		de[i] = '\0';
	return (s);
}

/**
 * _strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 *
 * Return: (s) a pointerto the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
