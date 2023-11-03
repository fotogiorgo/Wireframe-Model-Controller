/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:20:53 by jofoto            #+#    #+#             */
/*   Updated: 2023/01/04 19:59:47 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_line_and_create_variables(t_vars *variables)
{
	int	i;

	i = 0;
	while (i < (*variables).bytes_read)
	{
		if (((*variables).buf)[i] == '\n' || ((*variables).buf)[i] == '\0')
		{
			(*variables).found_nl = 1;
			i++;
			break ;
		}
		i++;
	}
	(*variables).ret = strjoin((*variables).ret,
			(*variables).ret_size, (*variables).buf, i);
	(*variables).ret_size += i;
	return (i);
}

static int	is_leftover_enough(char **leftover, t_vars *variables)
{
	if (*leftover == 0)
		return (0);
	if (**leftover != 0)
	{
		(*variables).bytes_read = ft_strlen(*leftover);
		(*variables).buf = *leftover;
		read_line_and_create_variables(variables);
		if ((*variables).found_nl)
		{
			*leftover = strjoin(*leftover, 0, *leftover + (*variables).ret_size,
					(*variables).bytes_read - (*variables).ret_size);
			return (1);
		}
	}
	free(*leftover);
	*leftover = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	t_vars		variables;
	static char	*leftover;

	ft_bzero(&variables, sizeof(variables));
	if (!is_leftover_enough(&leftover, &variables))
	{
		variables.buf = (char *)malloc(BUFFER_SIZE);
		if (variables.buf == 0)
			return (NULL);
		while (!variables.found_nl)
		{
			variables.bytes_read = read(fd, variables.buf, BUFFER_SIZE);
			if (variables.bytes_read <= 0)
				break ;
			if (variables.bytes_read < BUFFER_SIZE)
				variables.found_nl = 1;
			variables.line_bytes = read_line_and_create_variables(&variables);
		}
		if (variables.line_bytes < variables.bytes_read)
			leftover = strjoin(leftover, 0,
					variables.buf + variables.line_bytes,
					variables.bytes_read - variables.line_bytes);
		free(variables.buf);
	}
	return (variables.ret);
}
