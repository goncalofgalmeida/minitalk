/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:56:22 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/20 11:59:46 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*substr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while ((end > start) && ft_strchr(set, s1[end - 1]))
		end--;
	substr = (char *)malloc((end - start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s1[start], end - start + 1);
	return (substr);
}
