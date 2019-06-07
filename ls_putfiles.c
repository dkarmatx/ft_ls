/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_putfiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:49:27 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 08:04:00 by hgranule         ###   ########.fr       */
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
	char				buff[1024 * 1024];
	struct s_1col_f		frmt;

	ls_st_1col_f_scan(&frmt);
	put = g_files;
	buff[0] = '\0';
	tmp = buff;
	if (frmt.bmax)
		tmp = ls_cattotal(tmp, frmt.total);
	while (put)
	{
		if (frmt.indmax)
			tmp = ls_catind(frmt.indmax, tmp, (t_fileinfo *)put->content);
		if (frmt.bmax)
			tmp = ls_catbsz(frmt.bmax, tmp, (t_fileinfo *)put->content);
		tmp = ls_strcat(tmp, ((t_fileinfo *)put->content)->filename);
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
