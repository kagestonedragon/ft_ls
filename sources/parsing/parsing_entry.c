/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:22:07 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 15:03:45 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls			*create_new(char fpath[PATH_MAX],
		char *name, struct stat *stats)
{
	t_ls			*new;

	if (!(new = (t_ls *)ft_memalloc(sizeof(t_ls))) ||
			!(new->name = ft_strdup(name)))
		ls_log(ERROR_MALLOC, name);
	ft_strcpy(new->fpath, fpath);
	new->stats.mode = stats->st_mode;
	new->stats.blocks = stats->st_blocks;
	new->stats.nlink = stats->st_nlink;
	new->stats.uid = stats->st_uid;
	new->stats.gid = stats->st_gid;
	new->stats.size = stats->st_size;
	new->stats.dev = stats->st_rdev;
	new->stats.time = stats->st_mtimespec.tv_sec;
	new->stats.ntime = stats->st_mtimespec.tv_nsec;
	return (new);
}

int					parsing_entry(t_ls **ls, char path[PATH_MAX], char *name)
{
	char			fpath[PATH_MAX];
	struct stat		stats;

	get_fpath(fpath, path, name);
	if (lstat(fpath, &stats) == -1)
	{
		ls_log(ERROR_INPUT, name);
		return (-1);
	}
	if (!*ls)
		*ls = create_new(fpath, name, &stats);
	else
	{
		while ((*ls)->next)
			ls = &((*ls)->next);
		(*ls)->next = create_new(fpath, name, &stats);
	}
	return (0);
}
