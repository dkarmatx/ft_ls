/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 10:37:01 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 00:19:42 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FORMAT_H
# define LS_FORMAT_H

# include "ls_inc.h"

# define TABSIZE 8;

struct		s_1col_f
{
	int		inode_max;
	int		blocks_max;
	int		total;
};

struct		s_mcol_f
{
	int		elem_max_len;
};


void		ls_putfiles(void);
void		ls_putdir(void);
int			ls_get_decs(size_t);
void		ls_st_1col_f_scan(struct s_1col_f *frmt);
char		*ls_strcat(char *a, const char *b);
char		*ls_n2s_rformat(size_t a, int len, char filler);
char		*ls_catinode(int len, char *start , t_fileinfo *file);
char		*ls_catblcksize(int len, char *start , t_fileinfo *file);
char		*ls_cattotal(char *start, int total);

#endif
