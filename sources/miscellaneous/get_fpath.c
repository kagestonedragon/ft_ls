#include "ft_ls.h"

int 		get_fpath(char fpath[PATH_MAX], char path[PATH_MAX], char *name)
{
	int 	i;

	i = -1;
	while (path[++i])
		fpath[i] = path[i];
	if (i && i < PATH_MAX && !(path[0] == '/' && path[1] == '\0'))
		fpath[i++] = '/';
	while (i < PATH_MAX && *name)
		fpath[i++] = *name++;
	if (i < PATH_MAX)
	{
		fpath[i] = '\0';
		return (0);
	}
	else
	{
		errno = ENAMETOOLONG;
		return (1);
	}
}