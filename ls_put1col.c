/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_put1col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:46:19 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 08:04:59 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

void		ls_st_1col_f_scan(struct s_1col_f *frmt)
{
	t_dlist				*put;
	int					flag;

	put = g_files;
	ft_bzero(frmt, sizeof(struct s_1col_f));
	flag = 0;
	(g_flags.custom_flags & (CUSTM_I_ | CUSTM_S_)) ? flag = 1 : flag;
	while (put && flag)
	{
		if (g_flags.custom_flags & CUSTM_I_)
			if (frmt->indmax < ((t_fileinfo *)put->content)->s_stat.st_ino)
				frmt->indmax = ((t_fileinfo *)put->content)->s_stat.st_ino;
		if (g_flags.custom_flags & CUSTM_S_)
		{
			frmt->total += ((t_fileinfo *)put->content)->s_stat.st_blocks;
			if (frmt->bmax < ((t_fileinfo *)put->content)->s_stat.st_blocks)
				frmt->bmax = ((t_fileinfo *)put->content)->s_stat.st_blocks;
		}
		put = put->next;
	}
	if (g_flags.custom_flags & CUSTM_I_)
		frmt->indmax = ls_get_decs(frmt->indmax);
	if (g_flags.custom_flags & CUSTM_S_)
		frmt->bmax = ls_get_decs(frmt->bmax);
}

char		*ls_catind(int len, char *start, t_fileinfo *file)
{
	const char	*inode = ls_n2s_rformat(file->s_stat.st_ino, len, ' ');

	start = ls_strcat(start, inode);
	start = ls_strcat(start, " ");
	free((void *)inode);
	return (start);
}

char		*ls_catbsz(int len, char *start, t_fileinfo *file)
{
	const char	*size = ls_n2s_rformat(file->s_stat.st_blocks, len, ' ');

	start = ls_strcat(start, size);
	start = ls_strcat(start, " ");
	free((void *)size);
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
