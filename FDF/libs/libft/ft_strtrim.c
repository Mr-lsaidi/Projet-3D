/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 22:09:44 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/08 22:33:59 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isblank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static	size_t	ft_strlen_sp(char const *s)
{
	int			i;
	int			j;
	int			flag;

	i = 0;
	j = (int)ft_strlen(s) - 1;
	flag = 1;
	while (i < j && flag)
	{
		flag = 0;
		if (ft_isblank(s[i]))
		{
			i++;
			flag = 1;
		}
		if (ft_isblank(s[j]))
		{
			j--;
			flag = 1;
		}
	}
	return ((j - i >= 0) ? (j - i + 1) : 0);
}

char			*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	char		*buffer;

	buffer = NULL;
	i = 0;
	if (s)
	{
		while (ft_isblank(s[i]))
			i++;
		if ((buffer = (char *)malloc(sizeof(char) * (1 + ft_strlen_sp(s)))))
		{
			j = 0;
			while (s[i] && j < ft_strlen_sp(s))
				buffer[j++] = s[i++];
			buffer[j] = '\0';
		}
	}
	return (buffer);
}
