/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:01:21 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/25 20:14:45 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_projection(t_fdf *f, t_point *p, t_vect2d q, double z)
{
	if (f->i)
	{
		if (f->i == 2 || f->i == 3)
		{
			p->x = (q.x - q.y) * cos(f->iso) + f->u.x;
			p->y = -z + (q.y + q.x) * sin(f->iso) + f->u.y;
		}
		else if (f->i == 4)
		{
			p->x = (q.x - q.y) * tan(f->iso) + f->u.x;
			p->y = -z + (q.y + q.x) * tan(f->iso) + f->u.y;
		}
		else
		{
			p->x = q.x + 1.0 * z + f->u.x;
			p->y = q.y + 0.5 * z + f->u.y;
		}
	}
	else
	{
		p->x = q.x + f->u.x;
		p->y = q.y + f->u.y;
	}
}

int		main(int argc, char *argv[])
{
	t_fdf	f;

	if (argc != 2)
	{
		ft_putendl("usage : ./fdf file_name");
		exit(EXIT_SUCCESS);
	}
	ft_fdf_init(&f, argv);
	ft_update_event(&f);
	ft_fdf_draw(&f);
	mlx_loop(f.ptr.mlx_ptr);
	return (0);
}
