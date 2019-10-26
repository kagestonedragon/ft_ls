/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:01:41 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:54:40 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
** libft.h - libc
** stdint.h - uint8_t
** limits.h - PATH_MAX
** unistd - write
** stdlib - malloc, free, exit, NULL
** errno - global errno
** sys/stat.h - statistic
** dirent.h - directory reading
** pwd.h - user name
** grp.h - group name
*/

# include "libft.h"
# include <stdint.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>

# define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
# define ABS(X) ((X) > 0) ? (X) : (-X)

# define ERROR_OPTIONS		1000
# define ERROR_INPUT		1001
# define ERROR_ERRNO		1002
# define ERROR_MALLOC		1003

# define AVAILABLE_OPTIONS	"Ralrt1msAg"
# define OPTION_RR			1
# define OPTION_A			2
# define OPTION_L			4
# define OPTION_R			8
# define OPTION_T			16
# define OPTION_ONE			32
# define OPTION_M			64
# define OPTION_S			128
# define OPTION_AA			256
# define OPTION_G			512
# define OPTION_ITER		1024
# define OPTION_NAME		2048
# define OPTION_INPUT		4096

typedef struct				s_index{
	int						x;
	int						y;
}							t_index;

typedef struct				s_stats{
	blkcnt_t				blocks;
	mode_t					mode;
	nlink_t					nlink;
	uid_t					uid;
	gid_t					gid;
	off_t					size;
	dev_t					dev;
	time_t					time;
	long					ntime;
}							t_stats;

typedef struct				s_ls{
	char					fpath[PATH_MAX];
	char					*name;
	t_stats					stats;
	struct s_ls				*next;
}							t_ls;

/*
** PARSING
*/
int							parsing_options(uint16_t *options,
		int argc, char **argv);
t_ls						*parsing_input(int argc, char **argv,
		uint16_t *options);
t_ls						*parsing_directory(char fpath[PATH_MAX],
		uint16_t options);
int							parsing_entry(t_ls **ls,
		char path[PATH_MAX], char *name);

/*
** DETAILED LIST
*/
int							put_total(uint16_t options, int total);
int							put_basic_blocks(t_ls *ls, int blocks_len);
int							put_blocks(t_ls *ls, int align);
int							put_protection(int mode, char fpath[PATH_MAX]);
int							put_link(t_ls *ls, int align);
int							put_user_name(t_ls *ls, int align);
int							put_group_name(t_ls *ls, int align);
int							put_size(t_ls *ls, int align,
		int a_major, int a_minor);
int							put_time(t_ls *ls);
int							put_fname(t_ls *ls);

/*
** PUT INTO TERMIMAL
*/
int							put(t_ls *ls, uint16_t options, int level);
int							put_input_name(t_ls *ls,
		uint16_t *options, int level);
int							put_list(t_ls **ls,
		uint16_t *options, int level, int parent_mode);
int							put_basic_list(t_ls *lst, uint16_t options);
int							put_detailed_list(t_ls *ls,
		uint16_t options, int level, int parent_mode);

/*
** LS_FREE
*/
int							ls_free(t_ls **ls);

/*
** MISCELLANEOUS
*/
int							sorting(t_ls **ls, int options);
int							ft_strchr_index(char *string, char character);
int							get_fpath(char fpath[PATH_MAX],
		char path[PATH_MAX], char *name);
int							get_integer_length(int n);
int							get_max_name(t_ls *lst);
int							get_max_block(t_ls *lst, int *total);

/*
** LOG
*/
int							ls_log(int error, char *string);

#endif
