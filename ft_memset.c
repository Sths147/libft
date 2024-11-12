/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:38:26 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/12 12:14:16 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <stdlib.h>*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
		p[i++] = c;
	return (p);
}
/*

int	main(void)
{
	char	*s;
	char	*result;
	int	n;
	int	i;
	int c;

	c = 49;
	n = 6;
	i = 0;
	s = (char *)malloc(n * sizeof(char));
	result = ft_memset(s, c, n);
	while (i < n)
	{
		printf("%c\n", result[i]);
		i++;
	}
	return 0;
}
*/
