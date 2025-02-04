/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:34:14 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/23 14:01:48 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	char	s1[30];
	char	c;
	int		size;
	int		i;

	printf("Enter the character you wish to fill the memory area with: ");
	scanf(" %c", &c);
	printf("Enter the number of bytes to fill: ");
	scanf("%i", &size);
	while (size > 30)
	{
		printf("Error: Size exceeds array length, type a value under 30.\n");
		printf("Enter the number of bytes to fill: ");
		scanf("%i", &size);
	}
	
	ft_memset(s1, c, size);
	i = 0;
	while (i < size)
	{
		printf("%c, ", s1[i]);
		i++;
	}
	return (0);
}
 */