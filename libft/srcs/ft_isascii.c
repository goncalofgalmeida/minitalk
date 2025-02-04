/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:09 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/23 14:01:57 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* int	main(void)
{
	char	c;

	printf("Enter a character: ");
	scanf("%c", &c);
	if (ft_isascii(c) == 1)
		printf("'%c' is an ASCII character!\n", c);
	else if (ft_isascii(c) == 0)
		printf("'%c' is NOT an ASCII character!\n", c);
	return (0);
}
 */