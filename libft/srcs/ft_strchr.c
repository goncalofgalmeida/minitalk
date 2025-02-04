/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:02:41 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/05 13:32:31 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/* int	main(void)
{
	char	str[100];
	char	c;

	printf("Enter a string: ");
	scanf("%99s", str);
	printf("Enter a character: ");
	scanf(" %c", &c);
	printf("%s\n", ft_strchr(str, c));
	return (0);
}
 */