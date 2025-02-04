/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:06:04 by g24force          #+#    #+#             */
/*   Updated: 2024/10/31 11:19:33 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strptr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!strptr)
		return (NULL);
	ft_strlcpy(strptr, s1, s1_len + 1);
	ft_strlcat(strptr, s2, s1_len + s2_len + 1);
	return (strptr);
}

/* int	main(void)
{
	char	s1[30];
	char	s2[30];

	printf("Enter the strings you wish to concatenate.\n");
	printf("String 1: ");
	scanf("%29s", s1);
	printf("String 2: ");
	scanf("%29s", s2);
	printf("Concatenated string: %s\n", ft_strjoin(s1, s2));
	return (0);
}
 */