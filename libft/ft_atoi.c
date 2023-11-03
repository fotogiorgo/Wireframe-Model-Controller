/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:16:52 by jofoto            #+#    #+#             */
/*   Updated: 2022/10/29 20:17:08 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	positive_num(char *str)
{
	int			result;
	long long	rslt;

	rslt = 0;
	result = 0;
	while (48 <= *str && *str <= 57)
	{
		result *= 10;
		result += *str - 48;
		rslt *= 10;
		rslt += *str -48;
		str++;
		if (rslt < 0)
		{
			return (-1);
		}
	}
	return (result);
}

int	negative_num(char *str)
{
	int			result;
	long long	rslt;

	rslt = 0;
	result = 0;
	while (48 <= *str && *str <= 57)
	{
		result *= 10;
		result -= *str - 48;
		rslt *= 10;
		rslt -= *str -48;
		str++;
		if (rslt > 0)
		{
			return (0);
		}
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
	{
		str++;
		return (negative_num((char *)str));
	}
	else if (*str == '+')
	{
		str++;
		return (positive_num((char *)str));
	}
	else
	{
		return (positive_num((char *)str));
	}
}
