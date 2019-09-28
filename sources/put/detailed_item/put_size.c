#include "ft_ls.h"

int		put_size(t_ls *ls, int align)
{
	int length;
	int spaces;

	length = get_integer_length(ls->stats.size);
	spaces = (align - length) + 2;
	while (spaces--)
		write(1, " ", 1);
	if (!S_ISCHR(ls->stats.mode) && !S_ISBLK(ls->stats.mode))
		ft_putnbr(ls->stats.size);
	else
	{
		ft_putnbr(major(ls->stats.size));
		ft_putnbr(minor(ls->stats.size));
	}
	ft_putchar(' ');
	return (0);
}