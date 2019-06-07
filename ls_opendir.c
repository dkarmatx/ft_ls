/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:22:45 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 08:00:37 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

static void	ls_it_stk(t_dlist *before, t_dlist **begin, t_dlist *inject)
{
	if (!(*begin))
		*begin = inject;
	else if (!before)
		ft_dlstpush(begin, inject);
	else if (before == *begin)
		ft_dlstunshift(begin, inject);
	else if (inject)
	{
		inject->prev = before->prev;
		inject->next = before;
		before->prev = inject;
		inject->prev->next = inject;
	}
}

static void	ls_rdir_looker(t_dlist **files, t_dlist **insert, \
struct dirent *cur_f, char *path)
{
	t_fileinfo		finfo;

	ft_strcpy(finfo.path, path);
	if (*(ls_ret_base_from_path(path)) != '\0')
		ft_strcat(finfo.path, "/");
	ft_strcat(finfo.path, cur_f->d_name);
	ls_get_fileinfo(&finfo, cur_f->d_name, finfo.path);
	if (!(g_flags.custom_flags & (CUSTM_A_ | CUSTM_AB)) && \
	finfo.filename[0] == '.')
		return ;
	if (!(g_flags.custom_flags & CUSTM_A_) && \
	(!ft_strcmp(finfo.filename, ".") || !ft_strcmp(finfo.filename, "..")))
		return ;
	if (g_flags.general_flags == RECUR_LS && finfo.filetype == directory \
	&& ft_strcmp(finfo.filename, ".") && ft_strcmp(finfo.filename, ".."))
		ls_it_stk(*insert, &g_args, ft_dlstnew(&finfo, sizeof(t_fileinfo)));
	ft_dlstpush(files, ft_dlstnew(&finfo, sizeof(t_fileinfo)));
}

t_dlist		*ls_get_filelist(char *path)
{
	t_dlist			*files;
	t_dlist			*insert;
	DIR				*dir;
	struct dirent	*cur_f;

	if ((dir = opendir(path)) == 0)
	{
		ls_errno(ls_ret_base_from_path(path));
		return (0);
	}
	insert = g_args;
	files = 0;
	while ((cur_f = readdir(dir)))
		ls_rdir_looker(&files, &insert, cur_f, path);
	closedir(dir);
	return (files);
}
