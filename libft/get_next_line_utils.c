/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:53:54 by jofoto            #+#    #+#             */
/*   Updated: 2023/01/22 13:44:54 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	strcpy_cat(char *dst, char *s1, char *s2, size_t dstsize)
{
	while (s1 != 0 && *s1 != 0)
	{
		*dst = *s1;
		dst++;
		s1++;
		dstsize--;
	}
	while (*s2 != 0 && dstsize - 1 > 0)
	{
		*dst = *s2;
		dst++;
		s2++;
		dstsize--;
	}
	*dst = 0;
}

char	*strjoin(char *s1, int s1_len, char *s2, int s2_len)
{
	char	*res;

	res = (char *)malloc(s1_len + s2_len + 1);
	if (res == 0)
		return (0);
	if (s1_len == 0 && s1 != 0)
		strcpy_cat(res, 0, s2, s2_len + s1_len + 1);
	else
		strcpy_cat(res, s1, s2, s2_len + s1_len + 1);
	if (s1 != 0)
		free(s1);
	return (res);
}
