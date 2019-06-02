/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 10:37:01 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/02 13:57:58 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FORMAT_H
# define LS_FORMAT_H

# include "ls_inc.h"

# define TABSIZE 8;

void		ls_putfile(t_fileinfo *file);
void		ls_putdir(t_fileinfo *dir);

#endif