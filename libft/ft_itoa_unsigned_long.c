/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:04:37 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/29 20:02:19 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long	ft_recursive_power(unsigned long nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	else if (power == 0 || nb == 1)
	{
		return (1);
	}
	else
	{
		if (nb <= 0)
		{
			return (0);
		}
		return (ft_recursive_power(nb, power - 1) * nb);
	}
}

static char	*positive_itoa(char *res, unsigned long long n, int base, int alph)
{
	int					res_len;
	unsigned long long	i;

	res_len = 1;
	while (n / ft_recursive_power(base, res_len))
		res_len++;
	res[res_len] = 0;
	res_len--;
	while (res_len >= 0)
	{
		i = n % base;
		if (i < 10)
			res[res_len] = i + 48;
		else
			res[res_len] = i + alph - 10;
		n /= base;
		res_len--;
	}
	return (res);
}

char	*ft_itoa_unsigned_long(unsigned long long n, int base, int alph)
{
	int		res_len;
	char	*res;

	res_len = 1;
	while (n / ft_recursive_power(base, res_len))
		res_len++;
	res = (char *)malloc(res_len + 1);
	if (res == 0)
		return (NULL);
	return (positive_itoa(res, n, base, alph));
}
