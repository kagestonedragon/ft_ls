/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:25:17 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 13:27:06 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			put_fname(t_ls *ls)
{
	char	buffer[NAME_MAX + 1];

	ft_putstr(ls->name);
	if (S_ISLNK(ls->stats.mode))
	{
		ft_bzero(buffer, NAME_MAX + 1);
		readlink(ls->fpath, buffer, NAME_MAX);
		write(1, " -> ", 4);
		ft_putstr(buffer);
	}
	return (0);
}
