/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:32:48 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/25 20:12:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_projection_text(int n)
{
	char	*text;

	text = ft_strdup("Projection Used : ");
	if (n == 0)
		text = ft_strjoin(text, "NONE ");
	else if (n == 1)
		text = ft_strjoin(text, "PARRALLEL ");
	else if (n == 2)
		text = ft_strjoin(text, "TRUE ISOMETRIC ");
	else if (n == 3)
		text = ft_strjoin(text, "2:1 ISOMETRIC ");
	else
		text = ft_strjoin(text, "UNKNOWN ISOMETRIC ");
	return (text);
}

double	ft_pow(double nb, int puiss)
{
	double	res;

	res = 1.0;
	if (puiss == 0)
		return (1);
	if (puiss == 1)
		return (nb);
	if (puiss < 0)
	{
		puiss = -puiss;
		nb = 1.0 / nb;
	}
	while (puiss)
	{
		if (puiss & 1)
			res *= nb;
		puiss >>= 1;
		nb *= nb;
	}
	return (res);
}

char	*ft_itoaf(long double nb, int precision)
{
	int				n;
	int				i;
	char			*temp;

	i = 0;
	n = nb;
	temp = ft_strdup(ft_itoa(n));
	nb = nb > 0 ? nb - n : -(nb - n);
	temp = ft_strjoin(temp, ".");
	while (nb < 0.1 && nb > -0.1 && i < precision - 1)
	{
		nb *= 10;
		i++;
	}
	n = nb * ft_pow(10, precision - i);
	n = (nb * ft_pow(10, precision - i) - n > 0.01) ? n + 1 : n;
	temp = ft_strjoin(temp, ft_itoa(n));
	return (temp);
}

void	ft_display_usage(t_fdf *f)
{
	char	*text;

	if (f->h)
	{
		text = ft_strdup("Use Mouse Button Left, Right ....");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.mlx_win, 5, 2, 0x9DC183, text);
		text = ft_strdup("Use Keys Left, Right ....");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.mlx_win, 5, 22, 0xFC6600, text);
		text = ft_strdup("Use Pad Plus, Minus ....");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.mlx_win, 5, 42, 0x4F7942, text);
		text = ft_strdup("Use A, SPACE, F keys F1, F2 ....");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.mlx_win, 5, 62, 0x5097A4, text);
		text = ft_strdup("And H For Help : -> Enjoy ....");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.mlx_win, 5, 82, 0xDE3163, text);
		text = ft_strdup("Autors : Fdf By Lahcen and Raphael");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.mlx_win, 5, 102, 0xFF00FF, text);
	}
	text = ft_projection_text(f->i);
	text = ft_strjoin(text, ft_itoaf(f->iso, 6));
	mlx_string_put(f->ptr.mlx_ptr, f->ptr.mlx_win, f->scr_w / 2 - f->k *
			ft_strlen(text) / 2, f->scr_h - 30, 0x0018F9, text);
}

void	ft_update_event(t_fdf *fdf)
{
	mlx_hook((fdf)->ptr.mlx_win, 2, 0, ft_key_pressed, fdf);
	mlx_hook((fdf)->ptr.mlx_win, 4, 0, ft_mouse_pressed, fdf);
	mlx_hook((fdf)->ptr.mlx_win, 17, 0, ft_close, fdf);
}
