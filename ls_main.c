/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:47:43 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/28 17:10:29 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"
#include <fcntl.h>

t_flags		g_flags;
t_dlist		*g_goals;

int		lol(void *a, void *b)
{
	return(ft_strcmp(a, b));
}

int		main(const int ac, const char **av)
{
	int		status;

	g_flags.general_flags = DRW_MCOL;
	g_goals = 0;
	if ((status = ls_input_parser(&g_flags, &g_goals, ac, av) < 1) && !g_goals)
		g_goals = ft_dlstnew(".", 2);
	ft_dlst_gnsort(&g_goals, &ls_cmp_atime); // NOTE Сортировка по времени работает по размеру тоже и по лексике
	while (g_goals) // продумать всю хуйню
	{
		ft_putendl(g_goals->content);
		ft_dlstshift(&g_goals);
	}
	return (0);
}
