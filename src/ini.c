/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:43:54 by bscussel          #+#    #+#             */
/*   Updated: 2019/09/06 18:27:41 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		map_init(void)
{
	t_map	map;

	map.width = 0;
	map.height = 0;
	map.z_arr = NULL;
	map.c_arr = NULL;
	map.z_min = MIN_INT;
	map.z_max = MAX_INT;
	map.index = 0;
	map.default_c = CLR_G;
	map.color_count = 0;
	return (map);
}

t_fdf		*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		err_prog(ERR_MLX_INIT);
	if (!(fdf->mlx = mlx_init()))
		err_prog(ERR_MLX_INIT);
	fdf->win_h = ((map->height * map->width) / 2 >= 100) ? WIN_H1 : WIN_H2;
	fdf->win_w = ((map->height * map->width) / 2 >= 100) ? WIN_W1 : WIN_W2;
	if (!(fdf->win = mlx_new_window(fdf->mlx, fdf->win_w, fdf->win_h, "FdF")))
		err_prog(ERR_MLX_INIT);
	if (!(fdf->img = mlx_new_image(fdf->mlx, fdf->win_w, fdf->win_h)))
		err_prog(ERR_MLX_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
				&(fdf->size_line), &(fdf->endian));
	fdf->h_flag = 0;
	fdf->map = map;
	return (fdf);
}

t_cam		*cam_init(t_fdf *fdf)
{
	t_cam	*camera;
	int		zoom_wd;
	int		zoom_ht;

	zoom_wd = (fdf->win_w / fdf->map->width / 2);
	zoom_ht = (fdf->win_h / fdf->map->height / 2);
	if (!(camera = (t_cam *)ft_memalloc(sizeof(t_cam))))
		err_prog(ERR_CAM_INIT);
	camera->zoom = (zoom_wd < zoom_ht) ? zoom_wd : zoom_ht;
	camera->yaw = 0;
	camera->roll = 0;
	camera->pitch = 0;
	camera->x_shift = 0;
	camera->y_shift = 0;
	camera->z_div = 1;
	return (camera);
}
