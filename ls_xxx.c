/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_xxx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:43:07 by hgranule          #+#    #+#             */
/*   Updated: 2019/06/11 13:30:18 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_inc.h"

char					*ls_catxattr(char *st, t_fileinfo *fl)
{
	char	keys[2048];
	char	*it;
	ssize_t	klen;
	ssize_t	vlen;

	klen = listxattr(fl->path, keys, 2048, XATTR_NOFOLLOW);
	it = keys;
	while (1)
	{
		st = ls_strcat(st, "\t");
		st = ls_strcat(st, it);
		st = ls_strcat(st, "\t");
		vlen = getxattr(fl->path, it, 0, 0, 0, XATTR_NOFOLLOW);
		st = ls_n2s_rformat(vlen, ls_get_decs((size_t)vlen), ' ', st);
		st = ls_strcat(st, "\n");
		it = ft_memchr(it, 0, klen);
		++it;
		if ((it - keys) == klen)
			break ;
	}
	return (st);
}

static inline char		*ls_catacl_ex(char *st, char *acl_text, \
ssize_t vlen, int *ko)
{
	char	*it[2];

	*ko = 0;
	it[0] = ft_memchr(acl_text, '\n', vlen) + 1;
	while (1)
	{
		st = ls_n2s_rformat(*ko, ls_get_decs((size_t)(*ko)) + 1, ' ', st);
		st = ls_strcat(st, ": ");
		it[1] = ft_memchr(it[0], ':', vlen) + 1;
		st = ft_memccpy(st, it[0], ':', vlen);
		it[1] = ft_memchr(it[1], ':', vlen) + 1;
		st = ft_memccpy(st, it[1], ':', vlen);
		*(st - 1) = ' ';
		it[1] = ft_memchr(it[1], ':', vlen) + 1;
		it[1] = ft_memchr(it[1], ':', vlen) + 1;
		st = ft_memccpy(st, it[1], ':', vlen);
		*(st - 1) = ' ';
		it[1] = ft_memchr(it[1], ':', vlen) + 1;
		st = ft_memccpy(st, it[1], '\n', vlen);
		++(*ko);
		it[0] = ft_memchr(it[1], '\n', vlen) + 1;
		*st = 0;
		if (it[0][0] == 0)
			return (st);
	}
}

char					*ls_catacl(char *st, t_fileinfo *fl)
{
	char		*acl_text;
	acl_t		acl;
	ssize_t		vlen;
	int			ko;

	acl = acl_get_file(fl->path, ACL_TYPE_EXTENDED);
	acl_text = acl_to_text(acl, &vlen);
	st = ls_catacl_ex(st, acl_text, vlen, &ko);
	free((void *)acl_text);
	acl_free((void *)acl);
	return (st);
}
