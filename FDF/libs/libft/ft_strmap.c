/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:24:37 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/08 22:19:36 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	res = NULL;
	if (s)
	{
		if ((res = (char *)malloc(sizeof(char) * (1 + ft_strlen(s)))))
		{
			i = 0;
			while (s[i])
			{
				res[i] = (*f)(s[i]);
				i++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}
