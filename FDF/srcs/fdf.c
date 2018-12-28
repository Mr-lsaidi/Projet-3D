/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:44:21 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/26 00:25:34 by lsaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_rotate_x(t_vect2d *u, double *z, double angle)
{
	int		prev_x;
	int		prev_y;
	double	prev_z;

	prev_x = u->x;
	prev_y = u->y;
	prev_z = *z;
	u->x = prev_x * cos(angle) - prev_y * sin(angle);
	u->y = prev_x * sin(angle) + prev_y * cos(angle);
}

void	ft_rotate_y(t_vect2d *u, double *z, double angle)
{
	int		prev_x;
	int		prev_y;
	double	prev_z;

	prev_x = u->x;
	prev_y = u->y;
	prev_z = *z;
	u->y = prev_y * cos(angle) - prev_z * sin(angle);
	*z = prev_y * sin(angle) + prev_z * cos(angle);
}

void	ft_rotate_z(t_vect2d *u, double *z, double angle)
{
	int		prev_x;
	int		prev_y;
	double	prev_z;

	prev_x = u->x;
	prev_y = u->y;
	prev_z = *z;
	u->x = prev_x * cos(angle) + prev_z * sin(angle);
	*z = -prev_x * sin(angle) + prev_z * cos(angle);
}

int		ft_fdf_init(t_fdf *f, char *argv[])
{
	t_vect2d	scr;

	ft_read_file(&f->map, argv);
	scr.x = (f->map.w * 25) + 200;
	scr.y = (f->map.h * 25) + 400;
	f->scr_h = (scr.y > SCR_HEIGHT) ? SCR_HEIGHT : scr.y;
	f->scr_w = (scr.x > SCR_WIDTH || scr.y == SCR_HEIGHT) ? SCR_WIDTH : scr.x;
	f->k = (scr.y == SCR_WIDTH || scr.x == SCR_WIDTH) ? 1 : 10;
	f->z = (scr.y == SCR_WIDTH || scr.x == SCR_WIDTH) ? 0.1 : 10.0;
	f->u.x = (f->scr_w / 2);
	f->u.y = (f->scr_h / 2);
	f->angle = 0.53936;
	f->opt = 4;
	f->c = 0;
	f->h = 1;
	f->i = 0;
	f->delta = 0.0;
	f->iso = ISO2;
	f->ptr.mlx_ptr = mlx_init();
	f->ptr.mlx_win = mlx_new_window(f->ptr.mlx_ptr, f->scr_w, f->scr_h, "42");
	f->ptr.img.img_ptr = mlx_new_image(f->ptr.mlx_ptr, SCR_WIDTH, SCR_HEIGHT);
	f->ptr.img.data = (int *)mlx_get_data_addr(f->ptr.img.img_ptr, \
			&f->ptr.img.bpp, &f->ptr.img.size_len, &f->ptr.img.endian);
	return (0);
}

void	ft_fdf_draw(t_fdf *f)
{
	int		i;
	int		j;
	t_point	p;

	i = -1;
	ft_clear_pixels(f->ptr.img.data);
	while ((++i < f->map.h - 1) && (j = -1))
	{
		while ((++j < f->map.w - 1))
		{
			p = ft_iso(j, i, f);
			if (j < f->map.w - 1)
				ft_mlx_draw_line(f->ptr.img.data, p, ft_iso(j + 1, i, f));
			if (i < f->map.h - 1)
				ft_mlx_draw_line(f->ptr.img.data, p, ft_iso(j, i + 1, f));
		}
	}
	mlx_put_image_to_window(f->ptr.img.data, f->ptr.mlx_win,
			f->ptr.img.img_ptr, 0, 0);
	ft_display_usage(f);
}
