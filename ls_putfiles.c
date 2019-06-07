/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_putfiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:49:27 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 04:24:07 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

int					ls_get_decs(size_t a)
{
	int		b;

	b = 1;
	while (a > 9)
	{
		a /= 10;
		++b;
	}
	return (b);
}

static void			ls_putfiles_1col(void)
{
	t_dlist				*putter;
	char				*tmp;
	char				buff[1024 * 1024];
	struct s_1col_f		frmt;

	ls_st_1col_f_scan(&frmt);
	putter = g_files;
	buff[0] = '\0';
	tmp = buff;
	if (frmt.blocks_max)
		tmp = ls_cattotal(tmp, frmt.total);
	while (putter)
	{
		if (frmt.inode_max)
			tmp = ls_catinode(frmt.inode_max, tmp, (t_fileinfo *)putter->content);
		if (frmt.blocks_max)
			tmp = ls_catblcksize(frmt.blocks_max, tmp, (t_fileinfo *)putter->content);
		tmp = ls_strcat(tmp, ((t_fileinfo *)putter->content)->filename);
	//	if (g_flags.custom_flags & CUSTM_GB)
	//		tmp = ls_catcolor(tmp, putter->content);
		tmp = ls_strcat(tmp, "\n");
		putter = putter->next;
	}
	ft_putstr(buff);
}

static void			ls_putfiles_mcol(void)
{
	
}

static void			ls_putfiles_lcol(void)
{
	
}

void				ls_putfiles(void)
{
	if (g_flags.view_flags == DRW_1COL)
		ls_putfiles_1col();
	else if (g_flags.view_flags == DRW_MCOL)
		ls_putfiles_mcol();
	else if (g_flags.view_flags == DRW_LCOL)
		ls_putfiles_lcol();
}
