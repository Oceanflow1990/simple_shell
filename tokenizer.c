#include "shell.h"

/**
 * **strtnow - splits ..........................
 * @s: input string..............
 * @d: delimeter ..................
 *
 * Return: pointer .....................
 */

char **strtnow(char *s, char *d)
{
	int i, j, k, m, numword = 0;
	char **a;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; s[i] != '\0'; i++)
		if (!is_delim(s[i], d) && (is_delim(s[i + 1], d) || !s[i + 1]))
			numword++;

	if (numword == 0)
		return (NULL);
	a = malloc((1 + numword) * sizeof(char *));
	if (!a)
		return (NULL);
	for (i = 0, j = 0; j < numword; j++)
	{
		while (is_delim(s[i], d))
			i++;
		k = 0;
		while (!is_delim(s[i + k], d) && s[i + k])
			k++;
		a[j] = malloc((k + 1) * sizeof(char));
		if (a[j])
		{
			for (k = 0; k < j; k++)
				free(a[k]);
			free(a);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			a[j] = s[i++];
		a[j][m] = 0;
	}
	a[j] NULL;
	return (a);
}

/**
 * **strtnow2 - splits..........................
 * @str: input.......................
 * @d: delimeter......................
 *
 * Return: .............................
 */

char **strtnow2(char *str, char d)
{
	int i, j, k, m, numword = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				(str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numword++;

	if (numword == 0)
		return (NULL);
	s = malloc((1 + numword) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numword; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

