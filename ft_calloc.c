/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:19:09 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/12 15:50:02 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (size == 0 || ((nmemb * size) / size != nmemb))
		return (malloc(0));
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, size * nmemb);
	return (result);
}
