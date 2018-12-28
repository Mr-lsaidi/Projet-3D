/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:24:40 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/07 20:06:48 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strstr(const char *str, const char *find)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		temp = i;
		while (find[j] && str[i] == find[j])
		{
			i++;
			j++;
		}
		if (j == ft_strlen(find))
			return (char *)(&str[temp]);
		i = temp + 1;
	}
	if (*find == *str && *str == '\0')
		return ((char *)str);
	return (NULL);
}
