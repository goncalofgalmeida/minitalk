/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:53:35 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/25 10:03:53 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main(void)
{
	char	c;
	int		fd;

	printf("Enter a character: ");
	scanf(" %c", &c);
	printf("Type the file descriptor on which to write: ");
	scanf("%i", &fd);
	ft_putchar_fd(c, fd);
	return (0);
}
 */