/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:44:08 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/23 14:02:11 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	src_length = 0;
	while (src[src_length] != '\0')
		src_length++;
	return (src_length);
}

/* int	main(void)
{
	char	src[100];
	char	dst[100];
	int		size;
	int		length;

	printf("Enter the string you wish to copy: ");
	scanf("%s", src);
	printf("Enter the size you wish to copy: ");
	scanf("%i", &size);
	length = ft_strlcpy(dst, src, size);
	printf("Total length of the source string: %i\n", length);
	printf("Copied string: %s\n", dst);
	return (0);
}
 */