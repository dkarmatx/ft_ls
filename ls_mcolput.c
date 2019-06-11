/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_mcolput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 07:43:39 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 13:11:53 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

static char	*ls_cattabs(char *st, t_fileinfo *fl, struct s_mcol_f *f)
{
	int		len;

	len = 0;
	len += ft_strlen(fl->filename);
	(g_flags.ctm_flgs & CUSTM_FB) && !(\
	!(fl->filetype == regular && (fl->s_stat.st_mode & 0111))) &&\
	fl->filetype != chardev && fl->filetype != blockdev ? ++len : 0;
	g_flags.ctm_flgs & CUSTM_I_ ? len += (f->imax + 1) : 0;
	g_flags.ctm_flgs & CUSTM_S_ ? len += (f->bmax + 1) : 0;
	len = (len / 8) * 8;
	len = (f->wtmax - len) / 8;
	len += 1;
	while (--len > 0)
		st = ls_strcat(st, "\t");
	return (st);
}

void		ls_putarray_mcl(t_dlist **array, struct s_mcol_f *f, char *buff)
{
	int				i;
	int				j;
	t_fileinfo		*fl;
	char			*st;

	st = buff;
	i = -1;
	while (++i < f->crow && (j = -1))
		while (++j < f->ccol)
		{
			if (i + f->crow * j >= f->count)
				break ;
			fl = array[i + f->crow * j]->content;
			st = ls_catind(f->imax, st, fl);
			st = ls_catbsz(f->bmax, st, fl);
			st = ls_catcolor(st, fl);
			st = ls_strcat(st, fl->filename);
			g_flags.ctm_flgs & CUSTM_GB ? (st = ls_strcat(st, "\033[0m")) : 0;
			st = ls_cattypesym(st, fl);
			if (j + 1 < f->ccol && (i + ((j + 1) * f->crow) < f->count))
				st = ls_cattabs(st, fl, f);
			else
				st = ls_strcat(st, "\n");
		}
}
