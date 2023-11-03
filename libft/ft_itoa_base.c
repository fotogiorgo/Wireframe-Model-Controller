/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:04:37 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/29 19:50:05 by jofoto           ###   ########.fr       */
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

static char	*negative_itoa(char *res, long n, int base, int alph)
{
	int	i;
	int	res_len;

	res_len = 1;
	while (n / ft_recursive_power(base, res_len))
		res_len++;
	res[res_len + 1] = 0;
	res[0] = '-';
	while (res_len > 0)
	{
		i = n % base;
		res[res_len] = i + alph - 10;
		n /= base;
		res_len--;
	}
	return (res);
}

static char	*positive_itoa(char *res, int n, int base, int alph)
{
	int	res_len;
	int	i;

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

char	*ft_itoa_base(int n, int base, int alph)
{
	int		res_len;
	char	*res;

	res_len = 1;
	while (n / ft_recursive_power(base, res_len))
		res_len++;
	if (n < 0)
		res = (char *)malloc(res_len + 2);
	else
		res = (char *)malloc(res_len + 1);
	if (res == 0)
		return (NULL);
	if (n < 0)
		return (negative_itoa(res, (long)n * -1, base, alph));
	else
		return (positive_itoa(res, n, base, alph));
}
