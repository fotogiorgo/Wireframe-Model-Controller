/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:24:50 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/06 19:06:00 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	result;

	result = 0;
	while (n > 0 && result == 0)
	{
		result += *(unsigned char *)str1 - *(unsigned char *)str2;
		if (*str1 == 0 || *str2 == 0)
			break ;
		n--;
		str1++;
		str2++;
	}
	if (result < 0)
		return (-1);
	else if (result > 0)
		return (1);
	else
		return (result);
}
