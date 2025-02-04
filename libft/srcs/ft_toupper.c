/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:57:26 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/23 14:02:47 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

/* int	main(void)
{
	char	c;

	printf("Enter a character: ");
	scanf("%c", &c);
	printf("Converted char (if previously lowercase): %c\n", ft_toupper(c));
	return (0);
}
 */