/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:17:04 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/06 18:36:26 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p;
	char	*q;
	char	*temp;

	q = (char *)src;
	p = (char *)dest;
	if ((temp = (char *)malloc(sizeof(char) * n)))
	{
		i = 0;
		while (i < n)
		{
			temp[i] = q[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			p[i] = temp[i];
			i++;
		}
	}
	return (dest);
}
