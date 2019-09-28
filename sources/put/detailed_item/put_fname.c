#include "ft_ls.h"

int 		put_fname(t_ls *ls)
{
	char 	buffer[NAME_MAX + 1];

	ft_putstr(ls->name);
	if (S_ISLNK(ls->stats.mode))
	{
		ft_bzero(buffer, NAME_MAX + 1);
		readlink(ls->fpath, buffer, NAME_MAX);
		write(1, " -> ", 4);
		ft_putstr(buffer);
	}
	return (0);
}