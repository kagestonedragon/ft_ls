#include "ft_ls.h"

int 		ls_log(int error, char *string) {
	if (error == ERROR_OPTIONS)
	{
		write(1, "ft_ls: illegal option -- ", 25);
		write(1, string, 1);
		write(1, "\n", 1);
		write(1, "usage: ft_ls [-Ralrt] [file...]\n", 32);
	}
	else if (error == ERROR_ERRNO)
	{
		write(1, "ft_ls: ", 7);
		ft_putstr(string);
		ft_putendl(strerror(errno));
	}
	else if (error == ERROR_INPUT)
	{
		write(1, "ft_ls: ", 7);
		ft_putstr(string);
		write(1, ": No such file or directory\n", 28);
	}
	if (error == ERROR_OPTIONS || error == ERROR_MALLOC)
		exit(EXIT_FAILURE);
	return (0);
}