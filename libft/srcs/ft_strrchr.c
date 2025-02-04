/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:57 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/05 14:30:52 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if (*s == (char)c)
		ptr = (char *)s;
	return (ptr);
}

/* int	main(void)
{
	char	str[100];
	char	c;

	printf("Enter a string: ");
	scanf("%99s", str);
	printf("Enter a character: ");
	scanf(" %c", &c);
	printf("%s\n", ft_strrchr(str, c));
	return (0);
}
 */