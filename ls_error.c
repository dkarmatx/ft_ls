/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 01:58:59 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/28 09:24:25 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

void	ls_errno_exit(void)
{
	const char *errtext = strerror(errno);
	ft_putstr_fd("ft_ls: ", STDERR_FD);
	ft_putendl_fd(errtext, STDERR_FD);
	exit(errno);
}

void	ls_perrno_exit(char const *strerr)
{
	const char *errtext = strerror(errno);
	ft_putstr_fd(strerr, STDERR_FD);
	ft_putstr_fd(" :", STDERR_FD);
	ft_putendl_fd(errtext, STDERR_FD);
	exit(errno);
}

void	ls_puterror_exit(const char *strer)
{
	ft_putstr_fd("ft_ls: ", STDERR_FD);
	ft_putendl_fd(strer, STDERR_FD);
	exit(-1);
}

void	ls_errno(const char *strer)
{
	const char *errtext = strerror(errno);
	ft_putstr_fd("ft_ls: ", STDERR_FD);
	ft_putstr_fd(strer, STDERR_FD);
	ft_putstr_fd(": ", STDERR_FD);
	ft_putendl_fd(errtext, STDERR_FD);
}
