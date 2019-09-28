#include "ft_ls.h"

int 	put_link(t_ls *ls, int align)
{
	int length;
	int spaces;

	length = get_integer_length(ls->stats.nlink);
	spaces = (align - length) + 1;
	while (spaces--)
		write(1, " ", 1);
	ft_putnbr(ls->stats.nlink);
	return (0);
}