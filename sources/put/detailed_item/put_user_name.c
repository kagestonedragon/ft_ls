/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_user_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:26:19 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:57:50 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			put_user_name(t_ls *ls, int align)
{
	int		length;
	int		spaces;

	length = ft_strlen(getpwuid(ls->stats.uid)->pw_name);
	spaces = (align - length) + 1;
	write(1, " ", 1);
	ft_putstr(getpwuid(ls->stats.uid)->pw_name);
	while (spaces--)
		write(1, " ", 1);
	return (0);
}
