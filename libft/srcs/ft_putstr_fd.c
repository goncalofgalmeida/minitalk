/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:10:32 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/29 20:57:07 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/* int	main(void)
{
	char	str[100];
	int		fd;

	printf("Enter a string: ");
	scanf("%99s", str);
	printf("Type the file descriptor on which to write: ");
	scanf("%i", &fd);
	ft_putstr_fd(str, fd);
	return (0);
}
 */