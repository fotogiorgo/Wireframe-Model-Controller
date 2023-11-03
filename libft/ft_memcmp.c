/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:24:50 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/03 16:09:12 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int	result;

	result = 0;
	while (result == 0 && n > 0)
	{
		result += *(unsigned char *)str1 - *(unsigned char *)str2;
		n--;
		str1++;
		str2++;
	}
	return (result);
}
