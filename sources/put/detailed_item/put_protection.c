/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_protection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:25:43 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:01:39 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

static int	get_acl(char fpath[PATH_MAX])
{
	acl_t	temporary;

	if (listxattr(fpath, NULL, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	else if ((temporary = acl_get_link_np(fpath, ACL_TYPE_EXTENDED)))
	{
		acl_free(temporary);
		return ('+');
	}
	return (' ');
}

int			put_protection(int mode, char fpath[PATH_MAX])
{
	char	protection[12];

	protection[0] = get_file_type(mode);
	protection[1] = (S_IRUSR & mode) ? 'r' : '-';
	protection[2] = (S_IWUSR & mode) ? 'w' : '-';
	protection[3] = (S_IXUSR & mode) ? 'x' : '-';
	protection[4] = (S_IRGRP & mode) ? 'r' : '-';
	protection[5] = (S_IWGRP & mode) ? 'w' : '-';
	protection[6] = (S_IXGRP & mode) ? 'x' : '-';
	protection[7] = (S_IROTH & mode) ? 'r' : '-';
	protection[8] = (S_IWOTH & mode) ? 'w' : '-';
	protection[9] = (S_IXOTH & mode) ? 'x' : '-';
	protection[10] = get_acl(fpath);
	protection[11] = '\0';
	if (S_ISUID & mode)
		protection[3] = protection[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		protection[6] = protection[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		protection[9] = protection[9] == '-' ? 'T' : 't';
	ft_putstr(protection);
	return (0);
}
