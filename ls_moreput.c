/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_moreput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:47:30 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 17:22:24 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

char		*ls_cattypesym(char *start, t_fileinfo *file)
{
	if (g_flags.custom_flags & CUSTM_FB)
	{
		if (file->filetype == directory || file->filetype == argdir)
			start = ls_strcat(start, "/");
		else if (file->filetype == socket)
			start = ls_strcat(start, "=");
		else if (file->filetype == slink)
			start = ls_strcat(start, "@");
		else if (file->filetype == fifo)
			start = ls_strcat(start, "|");
		else if (file->filetype == whiteout)
			start = ls_strcat(start, "%");
		else if (file->filetype == regular && (file->s_stat.st_mode & 0111))
			start = ls_strcat(start, "*");
	}
	return (start);
}

void		ls_long_init_f(struct s_lcol_f *f)
{
	t_dlist			*put;
	struct passwd	*pass;
	struct group	*grp;
	size_t			len;
	t_fileinfo		*fl;

	put = g_files;
	ft_bzero(f, sizeof(struct s_lcol_f));
	while (put)
	{
		fl = put->content;
		pass = getpwuid(fl->s_stat.st_uid);
		grp = getgrgid(fl->s_stat.st_gid);
		fl->s_stat.st_blocks > f->bmax ? f->bmax = fl->s_stat.st_blocks : 0;
		fl->s_stat.st_ino > f->imax ? f->imax = fl->s_stat.st_ino : 0;
		len = ft_strlen(pass->pw_name);
		len > f->umax ? f->umax = len : 0;
		len = ft_strlen(grp->gr_name);
		len > f->gmax ? f->gmax = len : 0;
		fl->s_stat.st_size > f->smax ? f->smax = fl->s_stat.st_size : 0;
		f->total += fl->s_stat.st_blocks;
		put = put->next;
	}
}
// ПРОДОЛЖАЕМ ДЕЛАТЬ КЛАССНЫЕ ШТУКИ РЕБЯТА.
// СОЗДАЕМ КЛАССНУЮ ХУЙНЮ тут все структруы, короче Димас,
// РАЗБЕРЕШЬСЯ
void		ls_long_post_init_f(struct s_lcol_f *f)
{
	
}
