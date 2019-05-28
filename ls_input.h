/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_input.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 01:52:41 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/28 08:50:02 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_INPUT_H
# define LS_INPUT_H

# include "ls_inc.h"

# define SUPPORTED_FALGS_COUNT 23

int		ls_input_parser(t_flags *flags, t_dlist **file, const int argc, const char **sav);

#endif
