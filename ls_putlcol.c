/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_putlcol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 02:58:28 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 03:29:09 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

char			*ls_cataccess(char *st, t_fileinfo *file)
{
	const mode_t	acs_rts = file->s_stat.st_mode;

	ft_memset(st, '-', 10);
	st[0] = "?pcdb-lswd"[file->filetype];
	acs_rts & S_IRUSR ? st[1] = 'r' : 0;
	acs_rts & S_IWUSR ? st[2] = 'w' : 0;
	acs_rts & S_IXUSR ? st[3] = 'x' : 0;
	acs_rts & S_IRGRP ? st[4] = 'r' : 0;
	acs_rts & S_IWGRP ? st[5] = 'w' : 0;
	acs_rts & S_IXGRP ? st[6] = 'x' : 0;
	acs_rts & S_IROTH ? st[7] = 'r' : 0;
	acs_rts & S_IWOTH ? st[8] = 'w' : 0;
	acs_rts & S_IXOTH ? st[9] = 'x' : 0;
	acs_rts & S_ISUID ? st[3] = 's' : 0;
	acs_rts & S_ISGID ? st[6] = 's' : 0;
	acs_rts & S_ISVTX ? st[9] = 't' : 0;
	st[10] = ' ';
	file->isacl ? st[10] = '+' : 0;
	file->isxattr > 0 ? st[10] = '@' : 0;
	st[11] = ' ';
	return(st + 12);
}

static char		*ls_catdouble(char *st, size_t sz)
{
	double sz_d;

	sz_d = sz;
	sz_d = (sz_d / 1024.0) * 1000.0;
	sz = sz_d;
	(sz % 10 > 5) ? (sz += 10) : (0);
	sz = sz / 10;
	(sz % 10 > 5) ? (sz += 10) : (0);
	sz = sz / 10;
	if (sz < 100)
	{
		st[0] = ' ';
		st[1] = ((sz / 10) % 10) + 48;
		st[2] = '.';
		st[3] = (sz % 10) + 48;
		st[4] = 0;
		st += 3;
	}
	else
		st = ls_n2s_rformat(sz / 10, 4, ' ', st);
	return (st);
}

char			*ls_catnlinks(int len, char *st, int nlinks)
{
	st = ls_n2s_rformat(nlinks, len, ' ', st);
	st = ls_strcat(st, " ");
	return (st);
}

char			*ls_catbytes(char *st, int maxl, t_fileinfo *fl)
{
	const char		*b[5] = {"K", "M", "G", "T", "P"};
	int				rad;
	size_t			sz;
	double			sz_d;

	if (!(g_flags.addlf_flags & ADDLF_H_))
		return (ls_strcat(ls_n2s_rformat \
		(fl->s_stat.st_size, maxl, ' ', st), " "));
	if ((sz = fl->s_stat.st_size) < 1000)
		return (ls_strcat(ls_n2s_rformat(sz, 4, ' ', st), "B "));
	rad = 0;
	while (sz >= 1024000)
	{
		++rad;
		sz /= 1024;
	}
	st = ls_catdouble(st, sz);
	st = ls_strcat(st, b[rad]);
	return (ls_strcat(st, " "));
}

inline char		*ls_putfile_lcol(char *st, t_fileinfo *fl, struct s_lcol_f *f)
{
	st = ls_catind(f->imax, st, fl);
	st = ls_catbsz(f->bmax, st, fl);
	st = ls_cataccess(st, fl);
	st = ls_catnlinks(f->lmax, st, fl->s_stat.st_nlink);
	g_flags.addlf_flags & ADDLF_G_ ? 0 : (st = ls_strcat_lfrt \
	(st, f->umax + 2, ' ', getpwuid(fl->s_stat.st_uid)->pw_name));
	g_flags.addlf_flags & ADDLF_O_ ? 0 : (st = ls_strcat_lfrt \
	(st, f->gmax + 2, ' ', getgrgid(fl->s_stat.st_gid)->gr_name));
	st = ls_catbytes(st, f->smax, fl);
	st = ls_cattime(st, fl);
	st = ls_catcolor(st, fl);
	st = ls_strcat(st, fl->filename);
	g_flags.custom_flags & CUSTM_GB ? (st = ls_strcat(st, "\033[0m")) : 0;
	st = ls_cattypesym(st, fl);
	st = ls_catlinkinfo(st, fl);
	st = ls_strcat(st, "\n");
	(g_flags.addlf_flags & ADDLF_AA) && (fl->isxattr > 0) ?\
		(st = ls_catxattr(st, fl)) : 0;
	(g_flags.addlf_flags & ADDLF_E_) && (fl->isacl) ?\
		(st = ls_catacl(st, fl)) : 0;
	return (st);
}
