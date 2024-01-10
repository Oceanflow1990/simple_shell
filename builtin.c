#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: sturcture containingpotential argument. used to
 * maintain constant fuction prototype.
 *
 * Return: (0) if info.argv[0] != "exit"
 */

int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "illegal number:");
			_eputs(intfo->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = erratooi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes current directory of the process
 * @info: structure containing potential argument, used to maintain
 * constant function prototype
 *
 * Return: 0
 */

int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcdw faillure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /*TODO: what should thi be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_petenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /*TODO: what should this be?*/
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : '/');
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't do to ");
		_eput(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD"));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changethe current directory of the process
 * @info: structure containing potential arguemnt
 *
 * Return: 0 always
 */

int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. function not yet implemented \n");
	if (0)
		_puts("arg_array");
	return (0);
}
