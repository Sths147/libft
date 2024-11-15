/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:21:57 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/12 13:28:41 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;
	char	chr;

	chr = (char)c;
	s1 = (char *)s;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s1[i] == chr)
			return (&s1[i]);
		i--;
	}
	return (NULL);
}
