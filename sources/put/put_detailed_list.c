/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_detailed_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:30:42 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:58:12 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	kostil_norme(t_ls *ls, int align[7])
{
	align[1] = MAX(get_integer_length(ls->stats.nlink), align[1]);
	align[2] = MAX((int)ft_strlen(getpwuid(ls->stats.uid)->pw_name), align[2]);
	align[3] = MAX((int)ft_strlen(getgrgid(ls->stats.gid)->gr_name), align[3]);
	return (0);
}

static int	get_align(t_ls *ls, int align[7], int *blocks)
{
	int		length;

	align[5] = 3;
	align[6] = 3;
	while (ls)
	{
		align[0] = MAX(get_integer_length(ls->stats.blocks), align[0]);
		kostil_norme(ls, align);
		if (!S_ISCHR(ls->stats.mode))
			length = get_integer_length(ls->stats.size);
		else
		{
			align[5] = MAX(get_integer_length(major(ls->stats.dev)), align[5]);
			align[6] = MAX(get_integer_length(minor(ls->stats.dev)), align[6]);
			length = align[5] + align[6] + 2;
		}
		align[4] = MAX(length, align[4]);
		*blocks += ls->stats.blocks;
		ls = ls->next;
	}
	align[5] = MAX(align[4] - align[6] - 1, align[5]);
	return (0);
}

static int	put_detailed_item(t_ls *ls, uint16_t options, int align[7])
{
	(options & OPTION_S) ? put_blocks(ls, align[0]) : 0;
	put_protection(ls->stats.mode, ls->fpath);
	put_link(ls, align[1]);
	if (options & OPTION_G)
		write(1, " ", 1);
	else
		put_user_name(ls, align[2]);
	put_group_name(ls, align[3]);
	put_size(ls, align[4], align[5], align[6]);
	put_time(ls);
	put_fname(ls);
	return (0);
}

int			put_detailed_list(t_ls *ls, uint16_t options,
		int level, int parent_mode)
{
	int		align[7];
	int		blocks;

	ft_bzero(align, sizeof(align));
	blocks = 0;
	get_align(ls, align, &blocks);
	(void)level;
	if (ls && (options & OPTION_L) && (level != 1 || S_ISDIR(parent_mode)))
	{
		write(1, "total ", 6);
		ft_putnbr(blocks);
		write(1, "\n", 1);
	}
	while (ls)
	{
		put_detailed_item(ls, options, align);
		if ((ls = ls->next))
			write(1, "\n", 1);
	}
	return (0);
}
