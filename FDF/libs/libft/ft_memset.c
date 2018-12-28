/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:13:41 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/06 02:22:03 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(const void *tampon, int caractere, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)tampon;
	while (i < n)
	{
		p[i] = caractere;
		i++;
	}
	return ((void *)p);
}
