/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:29:41 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/05 12:16:42 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	i;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length + size);
	if (dst_length >= size)
		return (size + src_length);
	i = 0;
	while (src[i] != '\0' && i < size - dst_length - 1)
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}

/* int	main(void)
{
	char	src[100];
	char	dst[100];
	int		size;
	int		length;

	printf("Enter the first string: ");
	scanf("%99s", dst);
	printf("Enter the string you wish to concatenate: ");
	scanf("%99s", src);
	printf("Enter the size limit: ");
	scanf("%i", &size);
	length = ft_strlcat(dst, src, size);
	printf("Total length of both strings: %i\n", length);
	printf("Concated string: %s\n", dst);
	return (0);
}
 */