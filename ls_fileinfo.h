/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fileinfo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:36:50 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 08:09:46 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FILEINFO_H
# define LS_FILEINFO_H

# include "ls_inc.h"

# define FINFO_XATTR 0b01;
# define FINFO_ACL 0b10;

typedef enum		e_filetype
{
	unknown,
	fifo,
	chardev,
	argdir,
	blockdev,
	regular,
	slink,
	socket,
	whiteout,
	directory
}					t_filetype;

typedef struct		s_fileinfo
{
	char			path[1024];
	char			filename[256];
	struct stat		s_stat;
	ssize_t			isxattr;
	int				isacl;
	t_filetype		filetype;
}					t_fileinfo;

t_filetype			ls_get_filetype(mode_t mode);
int					ls_get_fileinfo(t_fileinfo *info, char *name, char *path);
t_dlist				*ls_get_filelist(char *path);
char				*ls_ret_base_from_path(char *path);

#endif
