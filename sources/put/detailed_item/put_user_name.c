#include "ft_ls.h"

int 		put_user_name(t_ls *ls, int align)
{
	int 	length;
	int 	spaces;


	length = ft_strlen(getpwuid(ls->stats.uid)->pw_name);
	spaces = (align - length) + 1;
	while (spaces--)
		write(1, " ", 1);
	ft_putstr(getpwuid(ls->stats.uid)->pw_name);
	return (0);
}