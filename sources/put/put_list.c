#include "ft_ls.h"

void		display_name(t_ls *ls, int blocks_len)
{
	int 	lenght;

	if (blocks_len)
	{
		lenght = MAX(blocks_len - get_integer_length(ls->stats.blocks), 0);
		while (lenght-- > 0)
			write(1, " ", 1);
		ft_putnbr(ls->stats.blocks);
		write(1, " ", 1);
	}
}

static int	lst_column(t_ls *lst, t_index row_col, uint16_t options, t_index maxlen)
{
	int				tmp_column;
	int				tmp_row;
	t_ls			*lst_tmp;
	int				counter;
	int 			spaces;

	counter = row_col.y;
	while (lst && counter--)
	{
		tmp_column = row_col.x;
		lst_tmp = lst->next;
		while (lst && tmp_column--)
		{
			(options & OPTION_S) ? display_name(lst, maxlen.y) : 0;
			ft_putstr(lst->name);
			if (tmp_column)
			{
				spaces = MAX(maxlen.x - ft_strlen(lst->name), 0);
				while (spaces-- > 0)
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

int			lst_blocks_len(t_ls *lst, int *total)
{
	int				maxlen;

	*total = 0;
	maxlen = 0;
	while (lst)
	{
		maxlen = MAX(get_integer_length(lst->stats.blocks), maxlen);
		*total += lst->stats.blocks;
		lst = lst->next;
	}
	return (maxlen);
}

static int	display_basic_list(t_ls *lst, uint16_t flags)
{
	t_index			maxlen;
	struct ttysize	ts;
	t_index			i;
	t_ls			*tmp_lst;
	int 			total;

	maxlen.x = get_max_name(lst) +  4;
	maxlen.y = (flags & OPTION_S) ? lst_blocks_len(lst, &total) : 0;
	if (flags & OPTION_S)
	{
		write(1, "total ", 6);
		ft_putnbr(total);
		write(1, "\n", 1);
	}
	ioctl(0, TIOCGWINSZ, &ts);
	i.x = (!(flags & OPTION_ONE)) ? ts.ts_cols / (maxlen.x + maxlen.y) : 1;
	i.y = 0;
	tmp_lst = lst;
	while (tmp_lst)
	{
		++i.y;
		tmp_lst = tmp_lst->next;
	}
	if (!(flags & OPTION_ONE))
		i.y = (i.y % i.x ? 1 : 0) + (i.y / i.x);
	lst_column(lst, i, flags, maxlen);
	return (1);
}
/*
static int	get_total(t_ls **ls)
{
	t_ls	*temporary;
	int 	total;

	temporary = *ls;
	total = 0;
	while (temporary)
	{
		total += temporary->stats.blocks;
		temporary = temporary->next;
	}
	return (total);
}
*/
static int 	put_list_option_m(t_ls **ls, uint16_t *options)
{
	t_ls			*temporary;
	int 			total;

	lst_blocks_len(*ls, &total);
	temporary = *ls;
	if (*options & OPTION_S)
	{
		write(1, "total ", 6);
		ft_putnbr(total);
		write(1, "\n", 1);
	}
	while (temporary)
	{
		if (*options & OPTION_S)
		{
			ft_putnbr(temporary->stats.blocks);
			write(1, " ", 1);
		}
		ft_putstr(temporary->name);
		if ((temporary = temporary->next))
			write(1, ", ", 2);
	}
	return (0);
}
/*
static int 	put_default(t_ls **ls, uint16_t *options)
{
	t_ls	*temporary;

	temporary = *ls;
	if (*options & OPTION_S)
	{
		ft_putstr("total ");
		ft_putnbr(get_total(ls));
		write(1, "\n", 1);
	}
	while (temporary)
	{
		if (*options & OPTION_S)
		{
			ft_putnbr(temporary->stats.blocks);
			write(1, " ", 1);
		}
		ft_putstr(temporary->name);
		write(1, " ", 1);
		temporary = temporary->next;
	}
	return (0);
}
*/
int 		put_list(t_ls **ls, uint16_t *options, int level, int parent_mode)
{
	sorting(ls, *options);
	*options |= OPTION_ITER;
	if (*options & OPTION_L)
		put_detailed_list(*ls, *options, level, parent_mode);
	else if (*options & OPTION_M)
		put_list_option_m(ls, options);
	else
		display_basic_list(*ls, *options);
	if ((*options & OPTION_M) || (*options & OPTION_L))
		write(1, "\n", 1);
	return (0);
}