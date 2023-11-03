/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:13:57 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/06 19:24:12 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sizes[2];

	sizes[0] = 0;
	sizes[1] = ft_strlen(src);
	if (dstsize == 0)
		return (sizes[1]);
	while (*dst != 0 && dstsize != 0)
	{
		dst++;
		sizes[0]++;
		dstsize--;
	}
	if (dstsize)
	{
		while (dstsize - 1 > 0 && *src != 0)
		{
			*dst = *src;
			dst++;
			src++;
			dstsize--;
		}
		*dst = 0;
		dstsize--;
	}
	return (sizes[0] + sizes[1]);
}
