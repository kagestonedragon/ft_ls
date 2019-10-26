/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:16:51 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:48:40 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_log(int error, char *string)
{
	if (error == ERROR_OPTIONS)
	{
		write(2, "ft_ls: illegal option -- ", 25);
		write(2, string, 1);
		write(2, "\n", 1);
		write(2, "usage: ft_ls [-Ralrt1msAg] [file...]\n", 32);
	}
	else if (error == ERROR_ERRNO)
	{
		write(2, "ft_ls: ", 7);
		ft_putstr_fd(string, 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	else if (error == ERROR_INPUT)
	{
		write(2, "ft_ls: ", 7);
		ft_putstr_fd(string, 2);
		write(2, ": No such file or directory\n", 28);
	}
	if (error == ERROR_OPTIONS || error == ERROR_MALLOC)
		exit(EXIT_FAILURE);
	return (0);
}
