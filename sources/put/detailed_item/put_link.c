/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:25:35 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 13:26:50 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		put_link(t_ls *ls, int align)
{
	int	length;
	int	spaces;

	length = get_integer_length(ls->stats.nlink);
	spaces = (align - length) + 1;
	while (spaces--)
		write(1, " ", 1);
	ft_putnbr(ls->stats.nlink);
	return (0);
}
