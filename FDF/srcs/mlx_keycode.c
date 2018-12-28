/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:47:34 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/25 20:12:21 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_rotate_input(int *keycode, void *params)
{
	t_fdf		*fdf;

	fdf = (t_fdf *)(params);
	if (*keycode == MLX_SCANCODE_ESCAPE)
		ft_close();
	if ((*keycode == MLX_SCANCODE_F1) && (fdf->opt = 2))
		fdf->delta = -0.05;
	else if ((*keycode == MLX_SCANCODE_F2) && (fdf->opt = 2))
		fdf->delta = +0.05;
	else if ((*keycode == MLX_SCANCODE_F3) && (fdf->opt = 1))
		fdf->delta = -0.05;
	else if ((*keycode == MLX_SCANCODE_F4) && (fdf->opt = 1))
		fdf->delta = +0.05;
	else if ((*keycode == MLX_SCANCODE_F5) && !(fdf->opt = 0))
		fdf->delta = -0.05;
	else if ((*keycode == MLX_SCANCODE_F6) && !(fdf->opt = 0))
		fdf->delta = +0.05;
	else
		fdf->opt = 5;
	if (fdf->opt >= 0 && fdf->opt < 3)
		fdf->angle += fdf->delta;
}

int		ft_key_pressed(int keycode, void *params)
{
	t_fdf		*f;

	f = (t_fdf *)(params);
	ft_rotate_input(&keycode, f);
	if (keycode == MLX_SCANCODE_PAD_ADD)
		f->k = (f->k <= 400) ? f->k + 1 : 400;
	if (keycode == MLX_SCANCODE_PAD_SUB)
		f->k = (f->k >= 2) ? f->k - 1 : 1;
	if (keycode == MLX_SCANCODE_DOWN)
		f->u.y = (f->u.y < f->scr_h) ? f->u.y + 2 : f->scr_h;
	if (keycode == MLX_SCANCODE_UP)
		f->u.y = (f->u.y > 0) ? f->u.y - 2 : 2;
	if (keycode == MLX_SCANCODE_RIGHT)
		f->u.x = (f->u.x < f->scr_w) ? f->u.x + 2 : f->scr_w;
	if (keycode == MLX_SCANCODE_LEFT)
		f->u.x = (f->u.x > 0) ? f->u.x - 2 : 2;
	if (keycode == MLX_SCANCODE_SPACEBAR)
		f->c = (++f->c % 2);
	if (keycode == MLX_SCANCODE_A)
		f->iso += 0.1;
	if (keycode == MLX_SCANCODE_H)
		f->h = f->h ? 0 : 1;
	ft_fdf_draw(f);
	return (0);
}

int		ft_mouse_pressed(int button, int mousex, int mousey, void *params)
{
	t_fdf			*f;

	f = (t_fdf *)(params);
	if (button == MLX_BUTTON_RIGHT)
	{
		f->i = (++f->i) % 5;
		if (f->i == 2)
			f->iso = ISO1;
		else if (f->i == 3)
			f->iso = ISO2;
		else
			f->iso = f->angle;
	}
	if (button == MLX_BUTTON_LEFT)
	{
		f->u.x = mousex - f->k * f->map.w / 2;
		f->u.y = mousey - f->k * f->map.h / 2;
	}
	if (button == MLX_BUTTON_UP)
		f->z += 0.5;
	if (button == MLX_BUTTON_DOWN)
		f->z -= 1.0;
	ft_fdf_draw(f);
	return (0);
}

int		ft_close(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
