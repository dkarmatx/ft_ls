/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_put1col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:46:19 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 13:12:58 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

char		*ls_catcolor(char *start, t_fileinfo *file)
{
	if (g_flags.ctm_flgs & CUSTM_GB)
	{
		if (file->filetype == directory || file->filetype == argdir)
			start = ls_strcat(start, "\033[1;38;2;0;100;240m");
		else if (file->filetype == socket || file->filetype == fifo)
			start = ls_strcat(start, "\033[1;38;2;255;127;0m");
		else if (file->filetype == slink)
			start = ls_strcat(start, "\033[1;38;2;0;193;0m");
		else if (file->filetype == chardev || file->filetype == blockdev)
			start = ls_strcat(start, "\033[1;38;2;235;218;0m");
		else if (file->filetype == whiteout)
			start = ls_strcat(start, "\033[1;38;2;205;84;174m");
		else if (file->filetype == regular && (file->s_stat.st_mode & 0111))
			start = ls_strcat(start, "\033[1;38;2;230;0;0m");
	}
	return (start);
}

void		ls_st_1col_f_scan(struct s_1col_f *f)
{
	t_dlist				*put;
	int					flag;

	put = g_files;
	ft_bzero(f, sizeof(struct s_1col_f));
	flag = 0;
	(g_flags.ctm_flgs & (CUSTM_I_ | CUSTM_S_)) ? flag = 1 : flag;
	while (put && flag)
	{
		if (g_flags.ctm_flgs & CUSTM_I_)
			if ((size_t)f->imax < ((t_fileinfo *)put->content)->s_stat.st_ino)
				f->imax = ((t_fileinfo *)put->content)->s_stat.st_ino;
		if (g_flags.ctm_flgs & CUSTM_S_)
		{
			f->total += ((t_fileinfo *)put->content)->s_stat.st_blocks;
			if (f->bmax < ((t_fileinfo *)put->content)->s_stat.st_blocks)
				f->bmax = ((t_fileinfo *)put->content)->s_stat.st_blocks;
		}
		put = put->next;
	}
	if (g_flags.ctm_flgs & CUSTM_I_)
		f->imax = ls_get_decs(f->imax);
	if (g_flags.ctm_flgs & CUSTM_S_)
		f->bmax = ls_get_decs(f->bmax);
}

char		*ls_catind(int len, char *start, t_fileinfo *file)
{
	if (g_flags.ctm_flgs & CUSTM_I_)
	{
		start = ls_n2s_rformat(file->s_stat.st_ino, len, ' ', start);
		start = ls_strcat(start, " ");
	}
	return (start);
}

char		*ls_catbsz(int len, char *start, t_fileinfo *file)
{
	if (g_flags.ctm_flgs & CUSTM_S_)
	{
		start = ls_n2s_rformat(file->s_stat.st_blocks, len, ' ', start);
		start = ls_strcat(start, " ");
	}
	return (start);
}

char		*ls_cattotal(char *start, int total)
{
	const char		*totals = ft_itoa(total);

	start = ls_strcat(start, "total ");
	start = ls_strcat(start, totals);
	start = ls_strcat(start, "\n");
	free((void *)totals);
	return (start);
}
