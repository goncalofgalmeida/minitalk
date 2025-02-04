/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:08:06 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/23 14:02:27 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] != '\0'
				&& (i + j) < len && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	str[100];
	char	search_str[100];
	int	size;

	printf("Enter a string: ");
	scanf("%s", str);
	printf("Enter the search string: ");
	scanf("%s", search_str);
	printf("Enter the amount of chars you wish to search: ");
	scanf("%i", &size);
	printf("%s\n", ft_strnstr(str, search_str, size));
	return (0);
}
 */