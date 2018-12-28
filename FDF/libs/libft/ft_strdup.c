/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:20:08 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/07 14:19:35 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	char	*p;

	dest = NULL;
	if ((dest = (char *)malloc((1 + ft_strlen(str)) * sizeof(char))))
	{
		p = dest;
		while ((*p++ = *str++))
			;
	}
	return (dest);
}
