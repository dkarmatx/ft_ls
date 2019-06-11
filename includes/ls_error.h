/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 01:57:04 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/07 08:06:34 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_ERROR_H
# define LS_ERROR_H

# include "ls_inc.h"

# define STDERR_FD STDERR_FILENO

void		ls_errno_exit(void);
void		ls_puterror_exit(const char *strerr);
void		ls_perrno_exit(char const *strerr);
void		ls_errno(const char *strerr);

#endif
