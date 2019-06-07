/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lib_upd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:01:07 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/06 23:25:06 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ls_strcat(char *a, const char *b)
{
	const size_t		len = ft_strlen(a);
	const size_t		len1 = ft_strlen(b);

	ft_strcpy(&(a[len]), b);
	return (a + len + len1);
}

char	*ls_n2s_rformat(size_t a, int len, char filler)
{
	char	*numberic;
	int		ind;

	if ((numberic = (char *)malloc(len + 1)))
	{
		ind = len;
		ft_memset(numberic, filler, len);
		numberic[ind] = 0;
		if (!a)
			numberic[ind - 1] = '0';
		while (a && --ind > -1)
		{
			numberic[ind] = (a % 10) + 48;
			a /= 10;
		}
	}
	return (numberic);
}
