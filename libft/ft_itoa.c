/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:04:37 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/05 15:00:54 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long	ft_recursive_power(long nb, int power)
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

static char	*negative_itoa(char *res, int res_len, long n)
{
	res[res_len + 1] = 0;
	res[0] = '-';
	while (res_len > 0)
	{
		res[res_len] = ((n % 10) + 48);
		n /= 10;
		res_len--;
	}
	return (res);
}

static char	*positive_itoa(char *res, int res_len, int n)
{
	res[res_len] = 0;
	res_len--;
	while (res_len >= 0)
	{
		res[res_len] = ((n % 10) + 48);
		n /= 10;
		res_len--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		res_len;
	char	*res;

	res_len = 1;
	while (n / ft_recursive_power(10, res_len))
		res_len++;
	if (n < 0)
		res = (char *)malloc(res_len + 2);
	else
		res = (char *)malloc(res_len + 1);
	if (res == 0)
		return (NULL);
	if (n < 0)
		return (negative_itoa(res, res_len, (long)n * -1));
	else
		return (positive_itoa(res, res_len, n));
}
