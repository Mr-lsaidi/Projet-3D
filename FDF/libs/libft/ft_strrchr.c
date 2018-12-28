/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:05:19 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/08 19:26:35 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		i;
	char		*k;

	k = NULL;
	i = 0;
	if (str[i] == c)
	{
		k = (char *)&str[i];
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			k = (char *)&str[i];
		i++;
	}
	if (k)
		return (k);
	if (c == '\0')
		return ((char *)(&str[i]));
	return (NULL);
}
