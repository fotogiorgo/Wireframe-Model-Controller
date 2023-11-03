/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:16:21 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/03 18:37:54 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *str, int c)
{
	const char	*result;

	result = NULL;
	while (*str != 0)
	{
		if (*str == (char)c)
			result = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else if (*str == 0 && result == 0)
		return (0);
	return ((char *)result);
}
