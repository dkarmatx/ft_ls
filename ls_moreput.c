/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_moreput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:47:30 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 13:19:55 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

char					*ls_cattypesym(char *start, t_fileinfo *file)
{
	if (g_flags.ctm_flgs & CUSTM_FB)
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

static inline void		ls_long_post_init_f(struct s_lcol_f *f)
{
	if (g_flags.ctm_flgs & CUSTM_S_)
		f->bmax = ls_get_decs(f->bmax);
	else
		f->bmax = 0;
	if (g_flags.ctm_flgs & CUSTM_I_)
		f->imax = ls_get_decs(f->imax);
	else
		f->imax = 0;
	f->smax = ls_get_decs(f->smax);
	f->lmax = ls_get_decs(f->lmax);
}

void					ls_long_init_f(struct s_lcol_f *f)
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
		(int)fl->s_stat.st_ino > f->imax ? f->imax = fl->s_stat.st_ino : 0;
		len = ft_strlen(pass->pw_name);
		(int)len > f->umax ? f->umax = len : 0;
		len = ft_strlen(grp->gr_name);
		(int)len > f->gmax ? f->gmax = len : 0;
		(int)fl->s_stat.st_size > f->smax ? f->smax = fl->s_stat.st_size : 0;
		(int)fl->s_stat.st_nlink > f->lmax ? f->lmax = fl->s_stat.st_nlink : 0;
		f->total += fl->s_stat.st_blocks;
		put = put->next;
	}
	ls_long_post_init_f(f);
}

static void				ls_multi_after_f(struct s_mcol_f *f)
{
	(g_flags.ctm_flgs & CUSTM_I_) ? f->imax = ls_get_decs(f->imax) : 0;
	(g_flags.ctm_flgs & CUSTM_S_) ? f->bmax = ls_get_decs(f->bmax) : 0;
	(g_flags.ctm_flgs & CUSTM_FB) ? f->wmax += f->cym : 0;
	(g_flags.ctm_flgs & CUSTM_I_) ? f->wmax += (f->imax + 1) : 0;
	(g_flags.ctm_flgs & CUSTM_S_) ? f->wmax += (f->bmax + 1) : 0;
	f->wtmax = 8 - (f->wmax % 8);
	f->wtmax += f->wmax;
	f->ccol = term.ws_col / f->wtmax;
	while ((f->crow = f->count / (f->ccol - 1)) < f->count % (f->ccol - 1))
	{
		--f->ccol;
		if (f->ccol == 0)
		{
			f->ccol = 1;
			f->crow = f->count;
			break ;
		}
	}
	!(f->count % (f->ccol - 1)) ? --(f->ccol) : 0;
}

void					ls_multi_init_f(struct s_mcol_f *f)
{
	t_dlist			*put;
	size_t			len;
	t_fileinfo		*fl;

	put = g_files;
	ft_bzero(f, sizeof(struct s_mcol_f));
	while (put)
	{
		fl = put->content;
		(int)fl->s_stat.st_blocks > f->bmax ? f->bmax = fl->s_stat.st_blocks\
		: 0;
		(int)fl->s_stat.st_ino > f->imax ? f->imax = fl->s_stat.st_ino : 0;
		len = ft_strlen(fl->filename);
		(int)len > f->wmax ? f->wmax = len : 0;
		((g_flags.ctm_flgs & CUSTM_FB) && !(fl->filetype == regular && \
		(fl->s_stat.st_mode & 0111)) && fl->filetype != chardev && \
		fl->filetype != blockdev) ? (f->cym = 1) : 0;
		f->total += fl->s_stat.st_blocks;
		++f->count;
		put = put->next;
	}
	ls_multi_after_f(f);
}
