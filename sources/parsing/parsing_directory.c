/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_directory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:21:32 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:56:15 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls				*parsing_directory(char fpath[PATH_MAX], uint16_t options)
{
	t_ls			*ls;
	DIR				*directory;
	struct dirent	*entry;

	ls = NULL;
	if (!(directory = opendir(fpath)))
		ls_log(ERROR_ERRNO, "folder");
	else
	{
		while ((entry = readdir(directory)))
		{
			if (entry->d_name[0] != '.' ||
					((options & OPTION_A) || options & OPTION_AA))
			{
				if ((!ft_strcmp(entry->d_name, ".") ||
							!ft_strcmp(entry->d_name, "..")) &&
						(options & OPTION_AA))
					continue ;
				else
					parsing_entry(&ls, fpath, entry->d_name);
			}
		}
		closedir(directory);
	}
	return (ls);
}
