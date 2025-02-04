/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:41:18 by g24force          #+#    #+#             */
/*   Updated: 2024/11/05 12:26:31 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = start;
	size = 0;
	while (s[i] != '\0' && size < len)
	{
		size++;
		i++;
	}
	substr = (char *)malloc((size + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, size + 1);
	return (substr);
}

/* int	main(void)
{
	char	s1[30];
	int		start;
	int		len;

	printf("Enter a string: ");
	scanf("%29s", s1);
	printf("Index to start copying from: ");
	scanf("%i", &start);
	printf("Maximum length of substring: ");
	scanf("%i", &len);
	printf("Substring: %s\n", ft_substr(s1, start, len));
	return (0);
}
 */