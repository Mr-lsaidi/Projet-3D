/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:34:30 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/08 22:27:49 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = NULL;
	if (s)
	{
		if ((res = (char *)malloc((1 + ft_strlen(s)) * sizeof(char))))
		{
			i = 0;
			while (s[i])
			{
				res[i] = (*f)(i, s[i]);
				i++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}
