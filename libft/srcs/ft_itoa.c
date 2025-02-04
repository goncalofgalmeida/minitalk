/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:22:31 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/08 12:22:11 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_fill_arr(char *arr, int n, int size)
{
	arr[size] = '\0';
	size--;
	if (n == 0)
		arr[size] = '0';
	if (n < 0)
	{
		arr[0] = '-';
		n = -n;
	}
	while (size >= 0 && n > 0)
	{
		arr[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_get_size(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_fill_arr(str, n, size);
	return (str);
}

/* int	main(void)
{
	int	counter = 0;
	int	num;
	char	*ret;

	printf("Enter a number: ");
	scanf("%i", &num);
	ret = ft_itoa(num);
	if (ret)
	{
		printf("%s\n", ret);
		free(ret);	
	}
	return (0);
}
 */