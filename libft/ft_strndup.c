/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:42:07 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/29 19:40:30 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*dup;

	if (ft_strlen(s1) < len)
	{
		dup = (char *)malloc(ft_strlen(s1) + 1);
		if (dup)
			ft_strlcpy(dup, s1, ft_strlen(s1) + 1);
	}
	else
	{
		dup = (char *)malloc(len);
		if (dup)
			ft_strlcpy(dup, s1, len);
	}
	return (dup);
}
