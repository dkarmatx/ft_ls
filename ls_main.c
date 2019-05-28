/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:47:43 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/28 09:48:19 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"
#include <fcntl.h>

t_flags		g_flags;
t_dlist		*g_filestack;

int		main(const int ac, const char **av)
{
	g_flags.general_flags = DRW_MCOL;
	g_filestack = 0;
	ls_input_parser(&g_flags, &g_filestack, ac, av);
	return (0);
}
