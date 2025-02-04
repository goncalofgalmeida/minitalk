/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:03:51 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/29 16:20:47 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* int	main(void)
{
	int		return_val;
	char	s1[30];
	char	s2[30];

	printf("Enter the strings you wish to compare.\n");
	printf("String 1: ");
	scanf("%29s", s1);
	printf("String 2: ");
	scanf("%29s", s2);
	printf("Enter the max number of chars to compare: ");
	scanf("%i", return_val);
	return_val = ft_strncmp(s1, s2, return_val);
	if (return_val > 0)
		printf("String 1 is greater than String 2");
	else if (return_val == 0)
		printf("String 1 is equal to String 2");
	else
		printf("String 1 is less than String 2");
	return (0);
}
 */