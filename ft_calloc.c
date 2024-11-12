/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:19:09 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/12 12:23:14 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*array;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	return (array);
}
/*	i = 0;
	while (i < nmemb)
	{
		array[i] = malloc(size);
		if (!array[i])
			return (NULL);
		i++;
	}*/
