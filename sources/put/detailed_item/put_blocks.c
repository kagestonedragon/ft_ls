/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:25:10 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 13:26:36 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		put_blocks(t_ls *ls, int align)
{
	int	length;
	int	spaces;

	length = get_integer_length(ls->stats.blocks);
	if ((spaces = (align - length)) > 0)
		while (spaces--)
			write(1, " ", 1);
	ft_putnbr(ls->stats.blocks);
	write(1, " ", 1);
	return (0);
}
