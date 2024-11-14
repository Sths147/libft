/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:54:20 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/14 16:13:23 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set [i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	i = 0;
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && ft_is_in_set(s1[j], set))
		j--;
	result = (char *)malloc((j - i + 2) * sizeof(char));
	if (!result)
		return (NULL);
	k = 0;
	while (k <= (j - i))
	{
		result[k] = s1[k + i];
		k++;
	}
	result[k] = '\0';
	return (result);
}
