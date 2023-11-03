/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:57:32 by jofoto            #+#    #+#             */
/*   Updated: 2023/01/22 13:45:55 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct variables {
	int			ret_size;
	char		*buf;
	char		*ret;
	int			line_bytes;
	int			found_nl;
	int			bytes_read;
}				t_vars;

char	*strjoin(char *s1, int s1_len, char *s2, int s2_len);
#endif