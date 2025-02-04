/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:27:33 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/29 11:33:38 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/* int	main(void)
{
	char	str[100];
	int		count;

	printf("Enter a string: ");
	scanf("%s", str);
	count = ft_strlen(str);
	printf("Number of characters: %i\n", count);
	return (0);
}
 */