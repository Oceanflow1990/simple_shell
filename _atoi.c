#include "shell.h"

/**
 * interactive - returns true if shell is interactive note
 * @info: struct address
 *
 * Return: 1ifinteractivenode, 0 otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delmeter
 * @c: char to check
 * @delim: he delimeter sting
 *
 * Return: 1if true,0otherwise
 */

int is_delim(char c, char *delim){
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha  - checks for alphabetic character
 * @c: The characterto input
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c){
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - convertsa tring to an integer
 * @s: the sting to convert
 *
 * Return: 0if number is stting, convert number otherwise
 */

int _atoi(char *s){
	int i, p = 1, flag = 0, m;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			p *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (p == -1)
		m = -result;
	else
		m = result;

	return (m);
}
