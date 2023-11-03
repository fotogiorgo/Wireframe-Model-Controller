/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:42:07 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/29 19:40:55 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if (s1 == NULL)
		return (ft_strdup("(null)"));
	dup = (char *)malloc(ft_strlen(s1)+1);
	if (dup)
		ft_strlcpy(dup, s1, ft_strlen(s1) + 1);
	return (dup);
}
