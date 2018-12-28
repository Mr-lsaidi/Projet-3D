/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:24:05 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/25 19:00:52 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char		*ft_capitalize(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return (str);
}

static	int	ft_atoi_col_16(char *str)
{
	int		i;
	int		number;
	int		color;

	i = 2;
	number = 0;
	color = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			number += str[i] - '0';
		else
			number += (10 + str[i] - 'A');
		if (ft_isdigit(str[i + 1]) || (str[i] >= 'A' && str[i + 1] <= 'F'))
			number *= 16;
		++i;
	}
	return (number);
}

void		ft_fill_map(t_map *map, char *line, int y)
{
	int		i;
	char	*temp;
	char	**tab;

	i = -1;
	tab = ft_strsplit(line, ' ');
	while (tab[++i])
	{
		map->coord[y][i].z = (double)ft_atoi(tab[i]);
		temp = ft_strstr(tab[i], "0x");
		if (temp)
			map->coord[y][i].color = ft_atoi_col_16(ft_capitalize(temp));
		else
			map->coord[y][i].color = 0xFFFFFF;
		temp = NULL;
	}
	if (!map->w && i)
		map->w = i;
	if (map->w && map->w != i)
	{
		ft_error("Error ", "Bad Map");
		exit(EXIT_FAILURE);
	}
}

void		ft_read_file(t_map *map, char *argv[])
{
	int		fd;
	char	*line;
	int		y;

	fd = open(argv[1], O_RDONLY);
	y = 0;
	map->w = 0;
	if (ft_get_next_line(fd, &line) == 1 && line)
	{
		ft_fill_map(map, line, y++);
		while (ft_get_next_line(fd, &line))
			ft_fill_map(map, line, y++);
		map->h = y;
		if (!map->w || !map->h)
		{
			ft_error("Error ", "Bad Map");
			exit(EXIT_FAILURE);
		}
		map->sc = 25;
	}
	else
	{
		ft_error("Error ", "Bad Map");
		exit(EXIT_FAILURE);
	}
}
