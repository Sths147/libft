/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:05:43 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/12 16:31:50 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_letters(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		count = 1;
	else
	{
		while (n > 0)
		{
			n /= 10;
			count++;
		}
	}
	return (count);
}

static char	*ft_alloc_itoa(int n)
{
	int		i;
	int		count;
	char	*result;

	count = ft_count_letters(n);
	result = (char *)malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
		result[i++] = 'S';
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			count;
	int			i;
	long int	n1;

	n1 = (long)n;
	result = ft_alloc_itoa(n);
	count = ft_count_letters(n) - 1;
	i = 0;
	if (n1 < 0)
	{
		result[0] = '-';
		n1 *= -1;
		i++;
	}
	while (count >= i)
	{
		result[count--] = n1 % 10 + 48;
		n1 /= 10;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n;

	n = -2147483648;
	printf("%s\n", ft_itoa(n));
	return (0);
}*/
