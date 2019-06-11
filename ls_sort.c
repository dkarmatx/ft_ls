/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 05:40:05 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 13:34:20 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

static void	spasibo_norminettete(void)
{
	ft_dlst_gnsort(&g_args, &ls_cmp_lex);
	if (g_flags.sort_flags & SORTI_SB)
		ft_dlst_gnsort(&g_args, &ls_cmp_size);
	else if ((g_flags.sort_flags & SORTI_T_) && \
	!(g_flags.sort_flags & SORTI_U_))
		ft_dlst_gnsort(&g_args, &ls_cmp_mtime);
	else if (g_flags.sort_flags & SORTI_U_)
		ft_dlst_gnsort(&g_args, &ls_cmp_atime);
}

void		ls_sort_arguments(void)
{
	if (!(g_flags.sort_flags & SORTI_F_))
	{
		if (g_flags.sort_flags & SORTI_R_)
		{
			spasibo_norminettete();
		}
		else
		{
			ft_dlst_rgnsort(&g_args, &ls_cmp_lex);
			if (g_flags.sort_flags & SORTI_SB)
				ft_dlst_rgnsort(&g_args, &ls_cmp_size);
			else if ((g_flags.sort_flags & SORTI_T_) && \
				!(g_flags.sort_flags & SORTI_U_))
				ft_dlst_rgnsort(&g_args, &ls_cmp_mtime);
			else if (g_flags.sort_flags & SORTI_U_)
				ft_dlst_rgnsort(&g_args, &ls_cmp_atime);
		}
	}
	ft_dlst_gnsort(&g_args, &ls_cmp_dirafter);
}

void		ls_sort_files(void)
{
	if (!(g_flags.sort_flags & SORTI_F_))
	{
		if (g_flags.sort_flags & SORTI_R_)
		{
			ft_dlst_rgnsort(&g_files, &ls_cmp_lex);
			if (g_flags.sort_flags & SORTI_SB)
				ft_dlst_rgnsort(&g_files, &ls_cmp_size);
			else if ((g_flags.sort_flags & SORTI_T_) && \
				!(g_flags.sort_flags & SORTI_U_))
				ft_dlst_rgnsort(&g_files, &ls_cmp_mtime);
			else if (g_flags.sort_flags & SORTI_U_)
				ft_dlst_rgnsort(&g_files, &ls_cmp_atime);
		}
		else
		{
			ft_dlst_gnsort(&g_files, &ls_cmp_lex);
			if (g_flags.sort_flags & SORTI_SB)
				ft_dlst_gnsort(&g_files, &ls_cmp_size);
			else if ((g_flags.sort_flags & SORTI_T_) && \
			!(g_flags.sort_flags & SORTI_U_))
				ft_dlst_gnsort(&g_files, &ls_cmp_mtime);
			else if (g_flags.sort_flags & SORTI_U_)
				ft_dlst_gnsort(&g_files, &ls_cmp_atime);
		}
	}
}
