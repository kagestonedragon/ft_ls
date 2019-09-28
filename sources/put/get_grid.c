#include "ft_ls.h"

static int	put_grid(t_ls *lst, t_index row_col, t_index maxlen, uint16_t flags)
{
	int				tmp_column;
	int				tmp_row;
	t_ls			*lst_tmp;
	int				counter;
	int 			length;

	counter = row_col.y;
	while (lst && counter--)
	{
		tmp_column = row_col.x;
		lst_tmp = lst->next;
		while (lst && tmp_column--)
		{
			(void)flags;
			//display_name(lst, flags, maxlen.y);
			ft_putstr(lst->name);
			if (tmp_column)
			{
				length = MAX(maxlen.x - ft_strlen(lst->name), 0);
				while (length-- > 0)
					write(1, " ", 1);
			}
			tmp_row = row_col.y;
			while (lst && tmp_row--)
				lst = lst->next;
		}
		ft_putchar('\n');
		lst = lst_tmp;
	}
	return (1);
}

int			get_blocks_length(t_ls *lst, int *total)
{
	int				maxlen;

	maxlen = 0;
	while (lst)
	{
		maxlen = MAX(get_integer_length(lst->stats.blocks), maxlen);
		*total += lst->stats.blocks;
		lst = lst->next;
	}
	return (maxlen);
}

int	display_basic_list(t_ls *lst, uint16_t options)
{
	t_index			maxlen;
	struct ttysize	ts;
	t_index			i;
	t_ls			*tmp_lst;
	int				total;

	total = 0;
	maxlen.x = get_max_name(lst);
	maxlen.y = (options & OPTION_S) ? get_blocks_length(lst, &total) : 0;
	if (options & OPTION_S)
	{
		write(1, "total ", 6);
		ft_putnbr(total);
		write(1, "\n", 1);
	}
	ioctl(0, TIOCGWINSZ, &ts);
	i.x = (!(options & 128)) ? ts.ts_cols / (maxlen.x + maxlen.y) : 1;
	i.y = 0;
	tmp_lst = lst;
	while (tmp_lst)
	{
		++i.y;
		tmp_lst = tmp_lst->next;
	}
	if (!(options & 128))
		i.y = (i.y % i.x ? 1 : 0) + (i.y / i.x);
	put_grid(lst, i, maxlen, options);
	return (1);
}