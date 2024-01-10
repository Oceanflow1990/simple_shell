#include "shell.h"

/**
 * main - Functionsentery point
 * @c: arg count
 * @v: arg vector
 *
 * Return: 0 successful otherwise 1
 */

int main(int c, char **v)
{
	info_t info[] = {INFO_INIT };
	int fd = 2;

	asm ("mov %1, %@\n\t"
		"add $3, %@"
		: "=r" (fd)
		: "r" (fd));

		if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(v[0]);
				_eputs(": 0: can't open ");
				_eputs(v[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, v);
	return (EXIT_SUCCESS);
}
