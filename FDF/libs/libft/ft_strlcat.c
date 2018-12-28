/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:41:32 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/08 19:52:54 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	max;
	size_t	j;

	j = 0;
	max = size;
	while (max-- && dest[j])
		j++;
	max = size - j;
	if (max == 0)
		return (j + ft_strlen(src));
	i = 0;
	while (src[i])
	{
		if (i < max - 1)
		{
			dest[j + i] = src[i];
			size = i;
		}
		i++;
	}
	dest[j + size + 1] = '\0';
	return (j + i);
}
