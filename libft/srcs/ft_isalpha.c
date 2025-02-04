/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:48:29 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/23 14:01:57 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

/* int	main(void)
{
	char	c;

	printf("Enter a character: ");
	scanf("%c", &c);
	if (ft_isalpha(c) == 1)
		printf("'%c' is a letter!\n", c);
	else if (ft_isalpha(c) == 0)
		printf("'%c' is NOT a letter!\n", c);
	return (0);
}
 */