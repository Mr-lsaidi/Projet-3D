/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:28:35 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/22 18:30:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strns(char const *s, char c)
{
	int		i;
	int		number;

	i = 0;
	number = 0;
	while (s[i + 1])
	{
		if (s[i] != c && s[i + 1] == c)
			number++;
		i++;
	}
	if (s[i] != c)
		number++;
	return (number);
}
