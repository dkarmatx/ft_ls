/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_putfiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:49:27 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 13:13:32 by hgranule         ###   ########.fr       */
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
		tmp = ls_catind(frmt.imax, tmp, (t_fileinfo *)put->content);
		tmp = ls_catbsz(frmt.bmax, tmp, (t_fileinfo *)put->content);
		tmp = ls_catcolor(tmp, (t_fileinfo *)put->content);
		tmp = ls_strcat(tmp, ((t_fileinfo *)put->content)->filename);
		g_flags.ctm_flgs & CUSTM_GB ? (tmp = ls_strcat(tmp, "\033[0m")) : 0;
		tmp = ls_cattypesym(tmp, (t_fileinfo *)put->content);
		tmp = ls_strcat(tmp, "\n");
		put = put->next;
	}
	ft_putstr(buff);
}

static void			ls_putfiles_mcol(void)
{
	t_dlist				*put;
	char				*tmp;
	char				buff[1024 * 1024 * 2];
	struct s_mcol_f		frmt;
	t_dlist				**array;

	ls_multi_init_f(&frmt);
	put = g_files;
	buff[0] = '\0';
	tmp = buff;
	tmp = ls_cattotal(tmp, frmt.total);
	array = (t_dlist **)malloc(sizeof(t_dlist *) * (frmt.count + 1));
	while (put)
	{
		*array = put;
		put = put->next;
		++array;
	}
	*array = 0;
	array -= frmt.count;
	ls_putarray_mcl(array, &frmt, tmp);
	free(array);
	ft_putstr(buff);
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
	tmp = ls_cattotal(tmp, frmt.total);
	while (put)
	{
		tmp = ls_putfile_lcol(tmp, put->content, &frmt);
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
