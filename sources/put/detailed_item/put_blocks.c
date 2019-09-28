#include "ft_ls.h"

int 	put_blocks(t_ls *ls, int align)
{
	int length;
	int spaces;

	length = get_integer_length(ls->stats.blocks);
	if ((spaces = (align - length)) > 0)
		while (spaces--)
			write(1, " ", 1);
	ft_putnbr(ls->stats.blocks);
	write(1, " ", 1);
	return (0);
}