/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_inc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:31:48 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/27 10:57:54 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_INC_H
# define LS_INC_H

# include "ls_flags.h"
# include "libft.h"

# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <uuid/uuid.h>

# define FINFO_XATTR 0b01;
# define FINFO_ACL 0b10;

typedef enum		e_filetype
{
	unknown = 0,
	fifo = S_IFIFO,
	chardev = S_IFCHR,
	directory = S_IFDIR,
	blockdev = S_IFBLK,
	regular = S_IFREG,
	slink = S_IFLNK,
	socket = S_IFSOCK,
	whiteout = S_IFWHT
}					t_filetype;

typedef struct		s_fileinfo
{
	struct stat		s_stat;
	char			filename[256];
	t_filetype		filetype;
	int				is_xattr_acl;
}					t_fileinfo;

#endif
