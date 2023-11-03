/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:35:57 by jofoto            #+#    #+#             */
/*   Updated: 2022/11/06 20:02:54 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s != 0)
	{
		while (*s == c && *s != 0)
			s++;
		if (*s != c && *s != 0)
			words++;
		while (*s != c && *s != 0)
			s++;
	}
	return (words);
}

static void	free_2d_array(char **s_arr, int rows)
{
	while (rows > 0)
	{
		rows--;
		free(s_arr[rows]);
	}
	free(s_arr);
}

static int	word_len(const char *s, char c)
{
	int	ret;

	ret = 0;
	while (*s != c && *s != 0)
	{
		s++;
		ret++;
	}
	return (ret);
}

static char	**make_2d_array(char **ret, char const *s, char c, int words)
{
	int	row;

	row = 0;
	while (words)
	{
		while (*s == c)
			s++;
		ret[row] = (char *)malloc(word_len(s, c) + 1);
		if (ret[row] == 0)
		{
			free_2d_array(ret, words + 1);
			return (0);
		}
		ft_strlcpy(ret[row], s, word_len(s, c) + 1);
		while (*s != c && *s != 0)
			s++;
		row++;
		words--;
	}
	ret[row] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ret;

	if (s == 0)
		return (0);
	words = count_words(s, c);
	ret = (char **)malloc((words + 1) * sizeof(char *));
	if (ret == 0)
		return (0);
	ret = make_2d_array(ret, s, c, words);
	if (ret == 0)
		return (0);
	return (ret);
}
