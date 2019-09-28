#include "ft_ls.h"

int 		put_group_name(t_ls *ls, int align)
{
	int 	length;
	int 	spaces;

	length = ft_strlen(getgrgid(ls->stats.gid)->gr_name);
	spaces = (align - length) + 2;
	while (spaces--)
		write(1, " ", 1);
	ft_putstr(getgrgid(ls->stats.gid)->gr_name);
	return (0);
}