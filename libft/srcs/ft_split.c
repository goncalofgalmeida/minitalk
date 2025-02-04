/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:42:56 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/02/04 16:52:42 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	word_count(const char *str, char c)
{
	int	wc;

	wc = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			wc++;
		while (*str != c && *str)
			str++;
	}
	return (wc);
}

static void	*ft_free(char **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	return (NULL);
}

static int	ft_fill_word(const char *s, char c, char **str)
{
	int	len;

	len = 0;
	if (!ft_strchr(s, c))
		len = ft_strlen(s);
	else
		len = ft_strchr(s, c) - s;
	*str = ft_substr(s, 0, len);
	if (!(*str))
		return (0);
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**strs_arr;
	int		len;
	int		i;

	strs_arr = (char **)malloc(((word_count(s, c)) + 1) * sizeof(char *));
	if (!s || !strs_arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			len = ft_fill_word(s, c, &strs_arr[i]);
			if (!len)
				return (ft_free(strs_arr, i));
			i++;
			s = s + len;
		}
	}
	strs_arr[i] = NULL;
	return (strs_arr);
}
