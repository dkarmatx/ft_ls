/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_put1col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:46:19 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 00:23:16 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

void		ls_st_1col_f_scan(struct s_1col_f *frmt)
{
	t_dlist				*putter;
	int					flag;

	putter = g_files;
	frmt->blocks_max = 0;
	frmt->inode_max = 0;
	frmt->total = 0;
	flag = 0;
	(g_flags.custom_flags & (CUSTM_I_ | CUSTM_S_)) ? flag = 1 : flag;
	while (putter && flag)
	{
		if (g_flags.custom_flags & CUSTM_I_)
			if (frmt->inode_max < ((t_fileinfo *)putter->content)->s_stat.st_ino)
				frmt->inode_max = ((t_fileinfo *)putter->content)->s_stat.st_ino;
		if (g_flags.custom_flags & CUSTM_S_)
		{
			frmt->total += ((t_fileinfo *)putter->content)->s_stat.st_blocks;
			if (frmt->blocks_max < ((t_fileinfo *)putter->content)->s_stat.st_blocks)
				frmt->blocks_max = ((t_fileinfo *)putter->content)->s_stat.st_blocks;
		}
		putter = putter->next;
	}
	if (g_flags.custom_flags & CUSTM_I_)
		frmt->inode_max = ls_get_decs(frmt->inode_max);
	if (g_flags.custom_flags & CUSTM_S_)
		frmt->blocks_max = ls_get_decs(frmt->blocks_max);
}

char		*ls_catinode(int len, char *start , t_fileinfo *file)
{
	const char	*inode = ls_n2s_rformat(file->s_stat.st_ino, len, ' ');

	start = ls_strcat(start, inode);
	start = ls_strcat(start, " ");
	free((void *)inode);
	return (start);
}

char		*ls_catblcksize(int len, char *start , t_fileinfo *file)
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
