#include "ft_ls.h"

int 		put_time(t_ls *ls)
{
	char	*ls_time;

	ls_time = ctime(&(ls->stats.time));
	write(1, &ls_time[4], 12);
	ft_putchar(' ');
	return (0);
}