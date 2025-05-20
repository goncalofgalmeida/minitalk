/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:13:34 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/20 11:59:42 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_str;
	int		i;

	ret_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ret_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret_str[i] = f(i, s[i]);
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
