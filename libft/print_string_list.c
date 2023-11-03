/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:37:00 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/29 19:37:04 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	print_string_list(t_list *root)
{
	while (root)
	{
		if (root->is_char)
			write(1, root->content, 1);
		else
			ft_putstr_fd(root->content, 1);
		root = root->next;
	}
}
