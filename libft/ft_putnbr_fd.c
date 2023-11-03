/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:40:58 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/07 14:40:42 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_power(int nb, int power)
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

static void	prints(int i, int nb, int fd)
{
	int	output;
	int	const_i;

	const_i = i;
	while (i >= 0)
	{
		output = nb / ft_recursive_power(10, i);
		if (nb < 0)
		{
			if (const_i == i)
			{
				ft_putchar_fd('-', fd);
			}
			ft_putchar_fd(-output + 48, fd);
		}
		else
		{
			ft_putchar_fd(output + 48, fd);
		}
		nb = nb - output * ft_recursive_power(10, i);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	dummy_nb;
	int	i;

	i = 0;
	dummy_nb = n;
	while (dummy_nb / 10 != 0)
	{
		dummy_nb /= 10;
		i++;
	}
	prints(i, n, fd);
}
