/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 06:23:59 by bscussel          #+#    #+#             */
/*   Updated: 2019/11/17 06:25:58 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				word_count(char *line)
{
	int			cnt;
	int			i;
	int			flag;

	cnt = 0;
	i = 0;
	flag = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			flag = 0;
		else if ((!bs_isspace(line[i])) && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int				compare_lines(char **line, t_map *map)
{
	int			line_len;
	int			i;

	i = 0;
	while (i < map->height)
	{
		line_len = word_count(line[i]);
		if (line_len != map->width)
			return (0);
		i++;
	}
	return (1);
}

static void		arr_apply(char *point, t_map *map)
{
	char		**data;

	data = ft_strsplit(point, ',');
	map->z_arr[map->index] = ft_atoi(data[0]);
	map->c_arr[map->index] = (data[1]) ? ft_atoi_base(data[1], 16) : -1;
	map->index++;
	ft_strdel(&data[0]);
	ft_strdel(&data[1]);
	free(data);
	data = NULL;
}

static void		zc_arr(char **line, t_map *map)
{
	int			x;
	int			y;
	int			i;
	char		**tmp_point;

	y = 0;
	(compare_lines(line, map) != 1) ? err_prog(ERR_MAP_SIZE) : 0;
	map->arr_size = map->width * map->height;
	(!(map->z_arr = (int *)malloc(sizeof(int) * map->arr_size)))
		? err_prog(ERR_LST_ARR) : 0;
	(!(map->c_arr = (int *)malloc(sizeof(int) * map->arr_size)))
		? err_prog(ERR_LST_ARR) : 0;
	while (y < map->height)
	{
		x = 0;
		tmp_point = ft_strsplit(line[y], ' ');
		while (x < map->width)
			arr_apply(tmp_point[x++], map);
		i = 0;
		while (i < map->width)
			ft_strdel(&tmp_point[i++]);
		free(tmp_point);
		tmp_point = NULL;
		y++;
	}
}

void			read_map(int fd, t_map *map)
{
	char		**line;
	int			i;

	line = (char **)malloc(sizeof(char *) * 255);
	while ((get_next_line(fd, &line[map->height])) > 0)
		map->width = word_count(line[map->height++]);
	zc_arr(line, map);
	i = 0;
	while (i < map->height)
		ft_strdel(&line[i++]);
	free(line);
	line = NULL;
}
