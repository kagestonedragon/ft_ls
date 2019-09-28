#include "ft_ls.h"

t_ls				*parsing_directory(char fpath[PATH_MAX], uint16_t options)
{
	t_ls			*ls;
	DIR				*directory;
	struct dirent	*entry;

	(void)options;
	ls = NULL;
	if (!(directory = opendir(fpath)))
		ls_log(ERROR_ERRNO, "folder");
	else
	{
		while ((entry = readdir(directory)))
			if (entry->d_name[0] != '.' || (options & OPTION_A))
				parsing_entry(&ls, fpath, entry->d_name);
		closedir(directory);
	}
	return (ls);
}