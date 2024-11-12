/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:41:35 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/12 12:25:16 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s1char;
	const char	*s2char;

	s1char = s1;
	s2char = s2;
	i = 0;
	while (i < n)
	{
		if (s1char[i] != s2char[i])
			return (s1char[i] - s2char[i]);
		i++;
	}
	return (0);
}
