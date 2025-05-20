/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:07:31 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/20 11:59:23 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*ptr;
	char		*conv;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (dest);
	ptr = src;
	conv = dest;
	i = 0;
	while (i < n)
	{
		conv[i] = ptr[i];
		i++;
	}
	return (dest);
}
