/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fileinfo_cmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:23:50 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 15:08:57 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

/*
** All functions must have this prototype :
** 		int		fname(void *a, void *b);
** Where a - pointer to *a and *b list content.
** It must return 0+ (a > b) ; 0- (a < b) ; 0 (a == b)
*/

int		ls_cmp_dirafter(void *a, void *b)
{
	t_fileinfo		*tfa;
	t_fileinfo		*tfb;

	tfa = a;
	tfb = b;
	if (tfa->filetype == directory)
		return (1);
	if (tfb->filetype == directory)
		return (-1);
	return (0);
}

int		ls_cmp_lex(void *a, void *b)
{
	t_fileinfo		*tfa;
	t_fileinfo		*tfb;

	tfa = a;
	tfb = b;
	return (ft_strcmp(tfa->filename, tfb->filename));
}

int		ls_cmp_atime(void *a, void *b)
{
	struct stat		sa;
	struct stat		sb;

	sb = ((t_fileinfo *)b)->s_stat;
	sa = ((t_fileinfo *)a)->s_stat;
	if (sa.st_atimespec.tv_sec > sb.st_atimespec.tv_sec)
		return (-1);
	else if (sa.st_atimespec.tv_sec < sb.st_atimespec.tv_sec)
		return (1);
	return (0);
}

int		ls_cmp_mtime(void *a, void *b)
{
	struct stat		sa;
	struct stat		sb;

	sb = ((t_fileinfo *)b)->s_stat;
	sa = ((t_fileinfo *)a)->s_stat;
	if (sa.st_mtimespec.tv_sec > sb.st_mtimespec.tv_sec)
		return (-1);
	else if (sa.st_mtimespec.tv_sec < sb.st_mtimespec.tv_sec)
		return (1);
	return (0);
}

int		ls_cmp_size(void *a, void *b)
{
	struct stat		sa;
	struct stat		sb;

	sb = ((t_fileinfo *)b)->s_stat;
	sa = ((t_fileinfo *)a)->s_stat;
	if (sa.st_size > sb.st_size)
		return (-1);
	else if (sa.st_size < sb.st_size)
		return (1);
	return (0);
}
