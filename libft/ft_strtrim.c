/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:59:17 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/04 14:12:37 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		s_len;

	if (s1 == 0 || set == 0)
		return (0);
	s_len = ft_strlen(s1);
	while (s_len != 0 && ft_strchr(set, *s1) != 0 && *s1 != 0)
	{
		s1++;
		s_len--;
	}
	while (*s1 != 0)
		s1++;
	s1--;
	while (s_len != 0 && ft_strchr(set, *s1) != 0 && *s1 != 0)
	{
		s1--;
		s_len--;
	}
	s1 -= s_len - 1;
	res = (char *)malloc(s_len + 1);
	if (res == 0)
		return (0);
	ft_strlcpy(res, s1, s_len + 1);
	return (res);
}
