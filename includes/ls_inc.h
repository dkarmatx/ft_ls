/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_inc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:31:48 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 14:09:53 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_INC_H
# define LS_INC_H

# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <errno.h>
# include <sys/ioctl.h>

# include "libft.h"
# include "ls_flags.h"
# include "ls_input.h"
# include "ls_error.h"
# include "ls_sort.h"
# include "ls_fileinfo.h"
# include "ls_format.h"

t_flags				g_flags;
t_dlist				*g_args;
t_dlist				*g_files;
int					g_mf;
struct winsize		term;

#endif
