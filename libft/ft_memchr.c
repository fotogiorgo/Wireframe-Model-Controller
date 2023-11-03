/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:16:21 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/08 20:24:29 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)str == (unsigned char)c)
			return ((void *)str);
		n--;
		str++;
	}
	return (0);
}
