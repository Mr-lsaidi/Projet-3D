/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:22:15 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/25 18:41:26 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		ft_get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		ft_get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = ft_percent(start.x, end.x, current.x);
	else
		percentage = ft_percent(start.y, end.y, current.y);
	red = ft_get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = ft_get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = ft_get_light((start.color & 0xFF), end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | (blue));
}

int		ft_range_color(double z)
{
	int		k;
	int		tab[N_COLORS];

	k = ((int)z) % N_COLORS;
	tab[0] = 0xFFFFFF;
	tab[1] = 0x362312;
	tab[2] = 0x311432;
	tab[3] = 0x222021;
	tab[4] = 0x420D09;
	tab[5] = 0x3E424B;
	tab[6] = 0x544C4A;
	tab[7] = 0x363636;
	tab[8] = 0x48494A;
	tab[9] = 0x043927;
	tab[10] = 0x4B5320;
	tab[11] = 0x81007F;
	tab[12] = 0x2B1700;
	tab[13] = 0x000080;
	tab[14] = 0xFF0090;
	tab[15] = 0xFFFDD0;
	tab[16] = 0xFCD12A;
	tab[17] = 0x98FB98;
	if (k <= 17)
		return (tab[k]);
	return (0xFF00FF);
}
