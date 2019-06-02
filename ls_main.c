/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:47:43 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/02 14:03:41 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"
#include <fcntl.h>

int		main(const int ac, const char **av)
{
	int			status;
	t_dlist		*cur;
	t_fileinfo	*cur_f;
	t_fileinfo	dotfile;

	g_flags.view_flags = DRW_MCOL;
	ioctl(0, TIOCGWINSZ, &term);
	g_args = 0;
	if ((status = ls_input_parser(ac, av) < 1) && !g_args)
	{
		ls_get_fileinfo(&dotfile, "", ".");
		g_args = ft_dlstnew(&dotfile, sizeof(t_fileinfo));
	}
	ft_dlst_rgnsort(&g_args, &ls_cmp_lex);
	ft_dlst_gnsort(&g_args, &ls_cmp_dirafter);
	while (g_args)
	{
		cur_f = (t_fileinfo *)g_args->content;
		if (cur_f->filetype != directory)
			ls_putfile(cur_f); // выводим файл если тип не directory
		else
			ls_putdir(cur_f); // выводим путь к папке и читаем папку и применяем ls_putfile к каждому файлу в ней
		cur = ft_dlstshift(&g_args);
		ft_dlstrmelem(&cur);
	}
	return (0);
}
