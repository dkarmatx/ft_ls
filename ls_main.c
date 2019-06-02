/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:47:43 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/02 10:35:03 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"
#include <fcntl.h>

int		main(const int ac, const char **av)
{
	int			status;
	t_dlist		*cur;
	t_fileinfo	dotfile;

	g_flags.view_flags = DRW_MCOL;
	g_args = 0;
	if ((status = ls_input_parser(ac, av) < 1) && !g_args)
	{
		ls_get_fileinfo(&dotfile, "", ".");
		g_args = ft_dlstnew(&dotfile, sizeof(t_fileinfo));
	}
	cur = g_args;
	ft_dlst_rgnsort(&g_args, &ls_cmp_lex);
	ft_dlst_gnsort(&g_args, &ls_cmp_dirafter);
	while (cur)
	{
		
	}
	return (0);
}
