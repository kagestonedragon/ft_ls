/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:25:49 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:57:37 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		put_rdev(t_ls *ls, int a_major, int a_minor)
{
	int			length;
	int			spaces;

	length = get_integer_length(major(ls->stats.dev));
	spaces = (a_major - length);
	ft_putnbr(major(ls->stats.dev));
	while (spaces-- > 0)
		write(1, " ", 1);
	length = get_integer_length(minor(ls->stats.dev));
	spaces = (a_minor - length);
	ft_putnbr(minor(ls->stats.dev));
	while (spaces-- > 0)
		write(1, " ", 1);
	return (0);
}

int				put_size(t_ls *ls, int align, int a_major, int a_minor)
{
	int			length;
	int			spaces;

	length = get_integer_length(ls->stats.size);
	spaces = (align - length) + 2;
	while (spaces--)
		write(1, " ", 1);
	if (!S_ISCHR(ls->stats.mode) && !S_ISBLK(ls->stats.mode))
		ft_putnbr(ls->stats.size);
	else
		put_rdev(ls, a_major, a_minor);
	ft_putchar(' ');
	return (0);
}
