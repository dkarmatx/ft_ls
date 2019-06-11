/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:47:43 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 13:04:32 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"
#include <fcntl.h>

static void				ls_recursive_power(void)
{
	t_dlist		*insert;
	t_dlist		*cur;
	t_fileinfo	*finfo;

	insert = g_args;
	cur = g_files;
	while (cur)
	{
		finfo = cur->content;
		if (g_flags.general_flags == RECUR_LS && finfo->filetype == directory \
		&& ft_strcmp(finfo->filename, ".") && ft_strcmp(finfo->filename, ".."))
			ls_it_stk(insert, &g_args, ft_dlstnew(finfo, sizeof(t_fileinfo)));
		cur = cur->next;
	}
}

static inline void		ls_g_files_init(void)
{
	g_files = g_args;
	while (g_args && ((t_fileinfo *)g_args->content)->filetype != directory)
		g_args = g_args->next;
	g_files == g_args ? g_files = 0 : g_files;
	if (g_args)
		if (g_args->prev)
		{
			g_args->prev->next = 0;
			g_args->prev = 0;
		}
}

static inline void		ls_putfoldername(void)
{
	if (g_mf)
	{
		ft_putstr(((t_fileinfo *)g_args->content)->path);
		ft_putendl(":");
	}
	g_mf = 1;
}

static inline void		ls_mainloop(void)
{
	char		path[1024];

	ls_putfoldername();
	ft_strcpy(path, ((t_fileinfo *)g_args->content)->path);
	ft_dlstrmelem(&g_args);
	g_files = ls_get_filelist(path);
	if (g_files)
	{
		ls_sort_files();
		ls_recursive_power();
		ls_putfiles();
	}
	ft_dlstdel(&g_files, (size_t)-1);
	if (g_args)
		ft_putchar('\n');
}

int						main(const int ac, const char **av)
{
	t_fileinfo	dotfile;

	g_flags.view_flags = DRW_MCOL;
	ioctl(0, TIOCGWINSZ, &term);
	g_args = 0;
	g_mf = 1;
	if ((ls_input_parser(ac, av) < 1) && !g_args)
	{
		ls_get_fileinfo(&dotfile, ".", ".");
		g_args = ft_dlstnew(&dotfile, sizeof(t_fileinfo));
	}
	if (g_args && g_args->next == 0 && g_args->prev == 0)
		g_mf = 0;
	ls_sort_arguments();
	ls_g_files_init();
	if (g_files)
	{
		ls_sort_files();
		ls_putfiles();
		g_args ? ft_putstr("\n") : 0;
	}
	while (g_args)
		ls_mainloop();
	return (0);
}
