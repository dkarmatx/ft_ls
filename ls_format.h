/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 10:37:01 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 15:33:50 by hgranule         ###   ########.fr       */
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
};

void		ls_putfiles(void);
void		ls_putdir(void);
int			ls_get_decs(size_t num);
void		ls_st_1col_f_scan(struct s_1col_f *frmt);
void		ls_long_init_f(struct s_lcol_f *f);
char		*ls_strcat(char *a, const char *b);
char		*ls_n2s_rformat(size_t a, int len, char filler);
char		*ls_catind(int len, char *start, t_fileinfo *file);
char		*ls_catbsz(int len, char *start, t_fileinfo *file);
char		*ls_cattotal(char *start, int total);
char		*ls_catcolor(char *start, t_fileinfo *file);
char		*ls_cattypesym(char *start, t_fileinfo *file);

#endif
