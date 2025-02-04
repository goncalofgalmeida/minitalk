/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:22:59 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/08 10:14:40 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	str[100];
	char	c;
	int	size;

	printf("Enter a string: ");
	scanf("%99s", str);
	printf("Enter a character: ");
	scanf(" %c", &c);
	printf("Enter the amount of bytes you wish to search: ");
	scanf(" %i", &size);
	printf("%s\n", (char *)ft_memchr(str, c, size));
	return (0);
}
 */