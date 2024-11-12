/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:35:36 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/12 14:37:26 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_direction(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (&dest[0] == &src[i])
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*src1;
	int			dir;

	dest1 = dest;
	src1 = src;
	dir = ft_direction(dest, src, n);
	if (dir == 0)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n >= 0)
		{
			dest1[n] = src1[n];
			n--;
		}
	}
	return (dest1);
}
