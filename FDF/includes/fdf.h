/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:28:53 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/25 20:10:39 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SCR_WIDTH 1800
# define SCR_HEIGHT 1200
# define MAX_SIZE 500
# define N_COLORS 24
# define ISO1 0.523599
# define ISO2 0.46373398
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_keycode.h"

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_len;
	int		endian;
}				t_img;

typedef	struct	s_ptr
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
}				t_ptr;

typedef	struct	s_point
{
	int		x;
	int		y;
	int		color;
}				t_point;

typedef	struct	s_vect2d
{
	int		x;
	int		y;
}				t_vect2d;

typedef	struct	s_dot
{
	double		z;
	int			color;
}				t_dot;

typedef	struct	s_map
{
	t_dot		coord[MAX_SIZE][MAX_SIZE];
	int			sc;
	int			w;
	int			h;
}				t_map;

typedef	struct	s_fdf
{
	int			scr_w;
	int			scr_h;
	int			k;
	int			c;
	int			i;
	int			h;
	double		z;
	double		angle;
	double		iso;
	double		delta;
	int			opt;
	t_point		u;
	t_map		map;
	t_ptr		ptr;
}				t_fdf;

t_vect2d		ft_vector(int x, int y);

void			ft_display_usage(t_fdf *f);
char			*ft_itoaf(long double nb, int precision);
double			ft_pow(double nb, int puiss);
char			*ft_projection_text(int n);
void			ft_fill_map(t_map *map, char *line, int y);
void			ft_read_file(t_map *map, char *argv[]);
int				ft_fdf_init(t_fdf *fdf, char *argv[]);
void			ft_fdf_draw(t_fdf *f);
void			ft_update_event(t_fdf *fdf);

double			ft_percent(int start, int end, int current);
int				ft_get_light(int start, int end, double percentage);
int				ft_get_color(t_point c, t_point s, t_point e, t_point d);
void			ft_rotate_x(t_vect2d *u, double *z, double angle);
void			ft_rotate_y(t_vect2d *u, double *z, double angle);
void			ft_rotate_z(t_vect2d *u, double *z, double angle);
t_point			ft_iso(int i, int j, t_fdf *f);
void			ft_projection(t_fdf *f, t_point *p, t_vect2d q, double z);
int				ft_range_color(double z);

void			ft_put_pixel(int *data, int x, int y, int color);
void			ft_clear_pixels(int *data);
void			ft_mlx_draw_octant1(int	*data, t_point start, t_point p2);
void			ft_mlx_draw_octant2(int *data, t_point start, t_point p2);
void			ft_mlx_draw_line(int *data, t_point p1, t_point p2);

int				ft_key_pressed(int keycode, void *params);
int				ft_key_released(int keycode, void *params);
int				ft_mouse_pressed(int button, int x, int y, void *params);
int				ft_mouse_released(int button, int x, int y, void *params);
int				ft_mouse_move(int x, int y, void *params);

void			ft_error(const char *s, const char *c);
int				ft_close(void);
#endif
