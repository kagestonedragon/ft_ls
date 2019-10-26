/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_basic_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:29:45 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 13:47:51 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					put_basic_blocks(t_ls *ls, int blocks_len)
{
	int				lenght;

	if (blocks_len)
	{
		lenght = MAX(blocks_len - get_integer_length(ls->stats.blocks), 0);
		while (lenght-- > 0)
			write(1, " ", 1);
		ft_putnbr(ls->stats.blocks);
		write(1, " ", 1);
	}
	return (0);
}

static int			kostil2_norme(t_ls *ls, int maxlenx)
{
	int				spaces;

	spaces = MAX(maxlenx - ft_strlen(ls->name), 0);
	while (spaces-- > 0)
		write(1, " ", 1);
	return (0);
}

static int			put_columns(t_ls *ls, t_index row_col,
		uint16_t options, t_index maxlen)
{
	int				tmp_column;
	int				tmp_row;
	t_ls			*lst_tmp;
	int				counter;

	counter = row_col.y;
	while (ls && counter--)
	{
		tmp_column = row_col.x;
		lst_tmp = ls->next;
		while (ls && tmp_column--)
		{
			(options & OPTION_S) ? put_basic_blocks(ls, maxlen.y) : 0;
			ft_putstr(ls->name);
			if (tmp_column)
				kostil2_norme(ls, maxlen.x);
			tmp_row = row_col.y;
			while (ls && tmp_row--)
				ls = ls->next;
		}
		ft_putchar('\n');
		ls = lst_tmp;
	}
	return (1);
}

int					get_max_block(t_ls *lst, int *total)
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

int					put_basic_list(t_ls *ls, uint16_t options)
{
	t_index			maxlen;
	struct ttysize	ts;
	t_index			i;
	t_ls			*tmp_ls;
	int				total;

	total = 0;
	maxlen.x = get_max_name(ls) + 4;
	maxlen.y = (options & OPTION_S) ? get_max_block(ls, &total) : 0;
	put_total(options, total);
	ioctl(0, TIOCGWINSZ, &ts);
	i.x = (!(options & OPTION_ONE)) ? ts.ts_cols / (maxlen.x + maxlen.y) : 1;
	i.y = 0;
	tmp_ls = ls;
	while (tmp_ls)
	{
		++i.y;
		tmp_ls = tmp_ls->next;
	}
	if (!(options & OPTION_ONE))
		i.y = (i.y % i.x ? 1 : 0) + (i.y / i.x);
	put_columns(ls, i, options, maxlen);
	return (1);
}
