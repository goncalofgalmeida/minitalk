/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:07:31 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/04 12:42:41 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* int	main(void)
{
	char	s1[30];
	char	s2[30];
	int		size;
	int		i;

	printf("Enter the source string: ");
	scanf("%29s", s2);
	printf("Enter the destination string: ");
	scanf("%29s", s1);
	printf("Enter the number of bytes to copy: ");
	scanf("%i", &size);
	ft_memcpy(s1, s2, size);
	i = 0;
	while (s1[i])
	{
		printf("%c, ", s1[i]);
		i++;
	}
	return (0);
}
 */