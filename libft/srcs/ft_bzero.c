/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:57:44 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/23 14:00:04 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/* int	main(void)
{
	char	s1[30];
	char	c;
	int		size;
	int		i;

	printf("Enter the number of bytes you wish to erase data from: ");
	scanf("%i", &size);
	while (size > 30)
	{
		printf("Error: Number exceeds array length, type a value under 30.\n");
		printf("Enter the number of bytes you wish to erase data from: ");
		scanf("%i", &size);
	}
	ft_memset(s1, 'c', 30);
	ft_bzero(s1, size);
	i = 0;
	while (i < 30)
	{
		printf("%c, ", s1[i]);
		i++;
	}
	return (0);
}
 */