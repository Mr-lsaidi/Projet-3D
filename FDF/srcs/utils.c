/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:23:43 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/25 20:10:46 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_error(const char *s1, const char *s2)
{
	ft_putendl(s1);
	ft_putendl(s2);
}

void		ft_put_pixel(int *data, int x, int y, int color)
{
	if (x >= 0 && x < SCR_WIDTH && y >= 0 && y < SCR_HEIGHT)
		data[y * SCR_WIDTH + x] = color;
}

void		ft_clear_pixels(int *data)
{
	int		i;

	i = -1;
	while (++i < SCR_WIDTH * SCR_HEIGHT)
		data[i] = 0x00;
}

t_vect2d	ft_vector(int x, int y)
{
	t_vect2d p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point		ft_iso(int i, int j, t_fdf *f)
{
	t_vect2d	q;
	double		z;
	t_point		p;

	z = f->z * f->map.coord[j][i].z;
	q = ft_vector(f->k * i, f->k * j);
	if (f->opt == 0)
		ft_rotate_x(&q, &z, f->angle);
	else if (f->opt == 1)
		ft_rotate_y(&q, &z, f->angle);
	else if (f->opt == 2)
		ft_rotate_z(&q, &z, f->angle);
	p.color = f->c ? ft_range_color(z) : f->map.coord[j][i].color;
	ft_projection(f, &p, q, z);
	return (p);
}
