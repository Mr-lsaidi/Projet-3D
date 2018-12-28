/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:47:51 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/08 22:31:08 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	dest = NULL;
	if (s)
	{
		if ((dest = (char *)malloc((len + 1))))
		{
			i = 0;
			while (i < len && s[i])
			{
				dest[i] = s[i + start];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (dest);
}
