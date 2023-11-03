/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:28:03 by jofoto            #+#    #+#             */
/*   Updated: 2023/01/05 23:22:16 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	countxsize;

	countxsize = count * size;
	if (countxsize / size != count)
		return (0);
	ret = malloc(size * count);
	if (ret)
		ft_bzero(ret, size * count);
	return (ret);
}
