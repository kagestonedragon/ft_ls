/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:26:10 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:57:06 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static int	get_year(t_ls *ls)
{
	time_t	current_time;

	time(&current_time);
	if (current_time - ls->stats.time > 15778463)
		return (0);
	return (1);
}

int			put_time(t_ls *ls)
{
	char	*ls_time;

	ls_time = ctime(&(ls->stats.time));
	if (get_year(ls))
		write(1, &ls_time[4], 12);
	else
	{
		write(1, &ls_time[4], 7);
		write(1, " ", 1);
		write(1, &ls_time[20], 4);
	}
	ft_putchar(' ');
	return (0);
}
