/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_putfiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:49:27 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 17:21:11 by hgranule         ###   ########.fr       */
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
	t_dlist				*put;
	char				*tmp;
	char				buff[1024 * 1024 * 2];
	struct s_1col_f		frmt;

	ls_st_1col_f_scan(&frmt);
	put = g_files;
	buff[0] = '\0';
	tmp = buff;
	if (frmt.bmax)
		tmp = ls_cattotal(tmp, frmt.total);
	while (put)
	{
		if (frmt.imax)
			tmp = ls_catind(frmt.imax, tmp, (t_fileinfo *)put->content);
		if (frmt.bmax)
			tmp = ls_catbsz(frmt.bmax, tmp, (t_fileinfo *)put->content);
		tmp = ls_catcolor(tmp, (t_fileinfo *)put->content);
		tmp = ls_strcat(tmp, ((t_fileinfo *)put->content)->filename);
		tmp = ls_strcat(tmp, "\033[0m");
		tmp = ls_cattypesym(tmp, (t_fileinfo *)put->content);
		tmp = ls_strcat(tmp, "\n");
		put = put->next;
	}
	ft_putstr(buff);
}

static void			ls_putfiles_mcol(void)
{
}

static void			ls_putfiles_lcol(void)
{
	t_dlist				*put;
	char				*tmp;
	char				buff[1024 * 1024 * 2];
	struct s_lcol_f		frmt;

	ls_long_init_f(&frmt);
	put = g_files;
	buff[0] = '\0';
	tmp = buff;
	if (frmt.bmax)
		tmp = ls_cattotal(tmp, frmt.total);
	while (put)
	{
		if (frmt.imax)
			tmp = ls_catind(frmt.imax, tmp, (t_fileinfo *)put->content);
		if (frmt.bmax)
			tmp = ls_catbsz(frmt.bmax, tmp, (t_fileinfo *)put->content);
		tmp = ls_catcolor(tmp, (t_fileinfo *)put->content);
		tmp = ls_strcat(tmp, ((t_fileinfo *)put->content)->filename);
		tmp = ls_strcat(tmp, "\033[0m");
		tmp = ls_cattypesym(tmp, (t_fileinfo *)put->content);
		tmp = ls_strcat(tmp, "\n");
		put = put->next;
	}
	ft_putstr(buff);
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
/*
** inode  bs  access   lns  uid      gid   bytes data          name
** 837165 8 -rw-r--r--_ 1 hgranule  2019   975B 28 May 14:27 ft_toupper.c
*/
