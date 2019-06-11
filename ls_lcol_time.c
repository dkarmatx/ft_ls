/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lcol_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:19:36 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 04:35:07 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

static char	*ls_cat_oldtime(char *st, time_t tm)
{
	char		time_buff[26];

	ctime_r(&tm, time_buff);
	st[4] = time_buff[8];
	st[5] = time_buff[9];
	st[6] = ' ';
	st[0] = time_buff[4];
	st[1] = time_buff[5];
	st[2] = time_buff[6];
	st[3]= ' ';
	st[7] = ' ';
	st[8] = time_buff[20];
	st[9] = time_buff[21];
	st[10] = time_buff[22];
	st[11] = time_buff[23];
	st[12] = ' ';
	st[13] = 0;
	return (st + 13);
}

static char	*ls_cat_newtime(char *st, time_t tm)
{
	char		time_buff[26];

	ctime_r(&tm, time_buff);
	st[4] = time_buff[8];
	st[5] = time_buff[9];
	st[6] = ' ';
	st[0] = time_buff[4];
	st[1] = time_buff[5];
	st[2] = time_buff[6];
	st[3]= ' ';
	st[7] = time_buff[11];
	st[8] = time_buff[12];
	st[9] = ':';
	st[10] = time_buff[14];
	st[11] = time_buff[15];
	st[12] = ' ';
	st[13] = 0;
	return (st + 13);
}

char		*ls_cattime(char *st, t_fileinfo *fl)
{
	time_t		tm;
	time_t		cur_tm;

	if (g_flags.sort_flags & SORTI_U_)
		tm = fl->s_stat.st_atimespec.tv_sec;
	else
		tm = fl->s_stat.st_mtimespec.tv_sec;
	time(&cur_tm);
	cur_tm -= 15768000;
	if (cur_tm > tm)
		return (ls_cat_oldtime(st, tm));
	return (ls_cat_newtime(st, tm));
}

char		*ls_catlinkinfo(char *st, t_fileinfo *fl)
{
	char	path[2048];
	ssize_t	len;

	if (fl->filetype != slink)
		return (st);
	st = ls_strcat(st, " -> ");
	len = readlink(fl->path, path, 2048);
	path[len] = 0;
	st = ls_strcat(st, path);
	return (st);
}
