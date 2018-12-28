/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:36:53 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/06 18:26:24 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	car;
	unsigned char	*p;

	p = (unsigned char *)s;
	car = (unsigned char)c;
	while (n--)
	{
		if (*p == car)
			return (p);
		p++;
	}
	return (NULL);
}
