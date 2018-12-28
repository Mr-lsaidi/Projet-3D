/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:58:43 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/24 19:14:15 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_mlx_draw_octant1(int *data, t_point start, t_point p2)
{
	t_point		dp;
	t_vect2d	pincr;
	t_point		p1;
	int			tab[2];

	tab[0] = -1;
	p1.x = start.x;
	p1.y = start.y;
	pincr.x = (p1.x < p2.x) ? 1 : -1;
	pincr.y = (p1.y < p2.y) ? 1 : -1;
	p1.color = start.color;
	dp.x = abs(p2.x - p1.x);
	dp.y = abs(p2.y - p1.y);
	tab[1] = dp.x / 2;
	while (++tab[0] <= dp.x)
	{
		p1.x += pincr.x;
		tab[1] += dp.y;
		if (tab[1] > dp.x)
		{
			tab[1] -= dp.x;
			p1.y += pincr.y;
		}
		ft_put_pixel(data, p1.x, p1.y, ft_get_color(p1, start, p2, dp));
	}
}

void		ft_mlx_draw_octant2(int *data, t_point start, t_point p2)
{
	t_point		dp;
	t_vect2d	pincr;
	t_point		p1;
	int			tab[2];

	tab[0] = -1;
	p1.x = start.x;
	p1.y = start.y;
	pincr.x = (p1.x < p2.x) ? 1 : -1;
	pincr.y = (p1.y < p2.y) ? 1 : -1;
	p1.color = start.color;
	dp.x = abs(p2.x - p1.x);
	dp.y = abs(p2.y - p1.y);
	tab[1] = dp.y / 2;
	while (++tab[0] <= dp.y)
	{
		p1.y += pincr.y;
		tab[1] += dp.x;
		if (tab[1] > dp.y)
		{
			tab[1] -= dp.y;
			p1.x += pincr.x;
		}
		ft_put_pixel(data, p1.x, p1.y, ft_get_color(p1, start, p2, dp));
	}
}

void		ft_mlx_draw_line(int *data, t_point p1, t_point p2)
{
	ft_put_pixel(data, p1.x, p1.y, ft_get_color(p1, p1, p1, p1));
	ft_put_pixel(data, p2.x, p2.y, ft_get_color(p2, p2, p2, p2));
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		ft_mlx_draw_octant1(data, p1, p2);
	else
		ft_mlx_draw_octant2(data, p1, p2);
}
