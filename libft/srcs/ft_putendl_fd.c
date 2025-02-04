/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:17:42 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/10/25 10:25:35 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/* int	main(void)
{
	char	str[100];
	int		fd;

	printf("Enter a string: ");
	scanf("%99s", str);
	printf("Type the file descriptor on which to write: ");
	scanf("%i", &fd);
	ft_putendl_fd(str, fd);
	return (0);
}
 */