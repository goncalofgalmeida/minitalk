/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:54:11 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/29 11:25:56 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/* int	main(void)
{
	char	c;

	printf("Enter a character: ");
	scanf("%c", &c);
	if (ft_isalnum(c) == 1)
		printf("'%c' is a letter or a number!\n", c);
	else if (ft_isalnum(c) == 0)
		printf("'%c' is NOT a letter or a number!\n", c);
	return (0);
}
 */