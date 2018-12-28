/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:01:21 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/06 02:15:44 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	i;

	tab = NULL;
	if (size && (tab = (char *)malloc(size)))
	{
		i = 0;
		while (i < size)
		{
			tab[i] = '\0';
			i++;
		}
	}
	return ((void *)tab);
}
