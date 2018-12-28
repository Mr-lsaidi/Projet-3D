/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:28:23 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/08 21:04:13 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	while (i < len && str[i] != '\0')
	{
		j = 0;
		temp = i;
		while (i < len && find[j] && str[i] == find[j])
		{
			i++;
			j++;
		}
		if (j == ft_strlen(find))
			return (char *)(&str[temp]);
		i = temp + 1;
	}
	if (*str == '\0' && *str == *find)
		return ((char *)str);
	return (NULL);
}
