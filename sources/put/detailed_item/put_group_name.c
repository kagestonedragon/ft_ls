/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_group_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:25:26 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:56:38 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			put_group_name(t_ls *ls, int align)
{
	int		length;
	int		spaces;

	length = ft_strlen(getgrgid(ls->stats.gid)->gr_name);
	spaces = (align - length) + 2;
	ft_putstr(getgrgid(ls->stats.gid)->gr_name);
	while (spaces--)
		write(1, " ", 1);
	return (0);
}
