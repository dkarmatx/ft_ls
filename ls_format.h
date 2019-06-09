/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 10:37:01 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/09 13:19:53 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FORMAT_H
# define LS_FORMAT_H

# include "ls_inc.h"

# define TABSIZE 8;

struct		s_1col_f
{
	int		imax;
	int		bmax;
	int		total;
};

struct		s_lcol_f
{
	int		imax;
	int		bmax;
	int		total;
	int		gmax;
	int		umax;
	int		smax;
	int		lmax;
};

void		ls_putfiles(void);
void		ls_putdir(void);
int			ls_get_decs(size_t num);
void		ls_st_1col_f_scan(struct s_1col_f *frmt);
void		ls_long_init_f(struct s_lcol_f *f);
char		*ls_strcat(char *a, const char *b);
char		*ls_n2s_rformat(size_t a, int len, char filler, char *st);
char		*ls_catind(int len, char *start, t_fileinfo *file);
char		*ls_catbsz(int len, char *start, t_fileinfo *file);
char		*ls_cattotal(char *start, int total);
char		*ls_catcolor(char *start, t_fileinfo *file);
char		*ls_cattypesym(char *start, t_fileinfo *file);
char		*ls_putfile_lcol(char *st, t_fileinfo *fl, struct s_lcol_f *f);
char		*ls_cataccess(char *st, t_fileinfo *file);
char		*ls_catnlinks(int len, char *st, int nlinks);
char		*ls_strcat_lfrt(char *st, int len, char filler, char *str);
char		*ls_catbytes(char *st, int maxl, t_fileinfo *fl);
char		*ls_cattime(char *st, t_fileinfo *fl);
char		*ls_catlinkinfo(char *st, t_fileinfo *fl);

#endif
