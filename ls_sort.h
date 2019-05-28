/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:28:54 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/28 17:04:46 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_SORT_H
# define LS_SORT_H

# include "ls_inc.h"

int		ls_cmp_lex(void *a, void *b);
int		ls_cmp_mtime(void *a, void *b);
int		ls_cmp_atime(void *a, void *b);
int		ls_cmp_size(void *a, void *b);

#endif