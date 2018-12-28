/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:00:10 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/07 03:13:46 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nbrlen(int n)
{
	int		i;

	i = (n > 0) ? 0 : 1;
	n = (n > 0) ? n : (-n);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	int		ft_power(int n, int puiss)
{
	if (puiss >= 0)
	{
		if (puiss == 0)
			return (1);
		else if (puiss == 1)
			return (n);
		else
			return (n * ft_power(n, puiss - 1));
	}
	return (0);
}

char			*ft_itoa(int n)
{
	char	*tab;
	int		i;
	int		k;

	if (n == -2147483648)
		return (tab = ft_strdup("-2147483648"));
	tab = NULL;
	if ((tab = (char *)malloc(sizeof(char) * (1 + ft_nbrlen(n)))))
	{
		i = 0;
		if (n < 0)
			tab[i++] = '-';
		k = ft_nbrlen(n) - i;
		n = (n > 0) ? n : (-n);
		while (k)
		{
			tab[i++] = n / ft_power(10, k - 1) + '0';
			n -= (n / ft_power(10, k - 1)) * ft_power(10, k - 1);
			k--;
		}
		tab[i] = '\0';
	}
	return (tab);
}
