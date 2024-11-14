/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:07:10 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/14 16:09:21 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		i;
	size_t		my_len;

	my_len = ft_strlen(s);
	if (start > my_len)
		len = 0;
	else if (len > my_len - start)
		len = my_len - start;
	result = (char *)malloc(len + 1 * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (start < my_len)
	{
		while (s[start + i] != '\0' && i < len)
		{
			result[i] = s[start + i];
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}
