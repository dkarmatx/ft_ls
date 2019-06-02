/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_input_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 01:49:37 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/02 04:49:28 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

const char		g_applyf[] = "1lCRdrtufSTe@ghnGFLAais";
const t_2b		g_applyv[] = {
	DRW_1COL, DRW_LCOL, DRW_MCOL, RECUR_LS,
	DIR_ASFI, SORTI_R_, SORTI_T_, SORTI_U_,
	SORTI_F_, SORTI_SB, ADDLF_TB, ADDLF_E_,
	ADDLF_AA, ADDLF_G_, ADDLF_H_, ADDLF_N_,
	CUSTM_GB, CUSTM_FB, CUSTM_LB, CUSTM_AB,
	CUSTM_A_, CUSTM_I_, CUSTM_S_ };

static void		ls_apply_flag(const char flag, int off)
{
	if (flag == '1' || flag == 'l' || flag == 'C')
		g_flags.view_flags = (t_1b)g_applyv[off];
	else if (flag == 'd' || flag == 'R')
		g_flags.general_flags = (t_1b)g_applyv[off];
	else if (flag == 'r' || flag == 't' || flag == 'u' || flag == 'f' \
	|| flag == 'S')
		g_flags.sort_flags |= g_applyv[off];
	else if (flag == 'T' || flag == 'e' || flag == '@' || flag == 'g' \
	|| flag == 'h' || flag == 'n')
		g_flags.addlf_flags |= g_applyv[off];
	else if (flag == 'i' || flag == 's' || flag == 'G' || flag == 'F' \
	|| flag == 'L' || flag == 'A' || flag == 'a')
		g_flags.custom_flags |= g_applyv[off];
}

static void		ls_flag_parser(const char *str_flag)
{
	char	*iter;
	char	*off;

	iter = (char *)str_flag;
	while (*(++iter))
		if ((off = (char *)ft_memchr(g_applyf, *iter, SUPPORTED_FALGS_COUNT)))
			ls_apply_flag(*iter, (int)(off - g_applyf));
		else
		{
			ft_putstr_fd("ft_ls: illegal option -- ", STDERR_FD);
			ft_putchar_fd(*iter, STDERR_FD);
			ft_putstr_fd("\nusage: ft_ls [-", STDERR_FD);
			ft_putstr_fd(g_applyf, STDERR_FD);
			ft_putendl_fd("] [file ...]", STDERR_FD);
			exit(-1);
		}
}

static void		ls_file_parser(const char *argv)
{
	t_fileinfo		file;
	int 			status;
	
	status = ls_get_fileinfo(&file, (char *)argv, (char *)argv);
	if (status == 0)
	{
		ls_errno(argv);
		return ;
	}
	ft_dlstpush(&g_args, ft_dlstnew(&file, sizeof(t_fileinfo)));
}

int				ls_input_parser(const int ac, const char **av)
{
	char		**argv;
	int			argc;
	int			retu;

	argv = (char **)av;
	argc = (int)ac;
	retu = 0;
	while (*(++argv) && **(argv) == '-' && *(*(argv) + 1))
		ls_flag_parser(*argv);
	--argv;
	while (*(++argv))
	{
		++retu;
		ls_file_parser(*argv);
	}
	return (retu);
}
