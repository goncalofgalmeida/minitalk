/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:23:59 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/29 11:29:18 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int	main(void)
{
	char	c;

	printf("Enter a character: ");
	scanf("%c", &c);
	if (ft_isprint(c) == 1)
		printf("'%c' is printable!\n", c);
	else if (ft_isprint(c) == 0)
		printf("'%c' is NOT printable!\n", c);
	return (0);
}
 */