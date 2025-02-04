/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:45:12 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/25 10:06:17 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*conv1;
	unsigned char	*conv2;
	size_t			i;

	conv1 = (unsigned char *)s1;
	conv2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (conv1[i] != conv2[i])
			return (conv1[i] - conv2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	s1[30];
	char	s2[30];
	int		size;
	int		return_val;

	printf("Enter the strings you wish to compare.\n");
	printf("String 1: ");
	scanf("%29s", s1);
	printf("String 2: ");
	scanf("%29s", s2);
	printf("Enter the number of bytes to compare: ");
	scanf("%i", &size);
	return_val = ft_memcmp(s1, s2, size);
	//PARA COMPARAR ARRAYS
	//int arr1[5] = {1, 2, 3, 4, 5};
	//int arr2[5] = {1, 2, 3, 6, 5};
	//printf("Comparing integer arrays...\n");
	//printf("Enter the number of bytes to compare: ");
	//scanf("%i", &size);
	//return_val = ft_memcmp(arr1, arr2, size);
	if (return_val > 0)
		printf("Array 1 is greater than Array 2");
	else if (return_val == 0)
		printf("Array 1 is equal to Array 2");
	else
		printf("Array 1 is less than Array 2");
	return (0);
}
 */