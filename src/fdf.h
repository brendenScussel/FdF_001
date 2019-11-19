/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:19:20 by bscussel          #+#    #+#             */
/*   Updated: 2019/11/12 17:02:29 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "macro.h"
# include <math.h>

typedef struct			s_map
{
	int					width;
	int					height;
	int					*z_arr;
	int					*c_arr;
	int					z_min;
	int					z_max;
	ssize_t				index;
	size_t				arr_size;
	int					arg_c;
	int					default_c;
	int					color_count;
}						t_map;

typedef struct			s_camera
{
	int					zoom;
	double				yaw;
	double				roll;
	double				pitch;
	int					x_shift;
	int					y_shift;
	float				z_div;
	int					cam_angle;
}						t_cam;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					win_h;
	int					win_w;
	int					h_flag;
	t_cam				*cam;
	t_map				*map;
}						t_fdf;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					col;
}						t_pnt;

t_map					map_init(void);
void					read_map(int fd, t_map *map);
t_fdf					*fdf_init(t_map *map);
t_cam					*cam_init(t_fdf *fdf);
void					draw(t_fdf *fdf);
t_pnt					make_point(int x, int y, t_fdf *fdf);
t_pnt					depth(t_pnt p, t_fdf *fdf);
int						make_color(t_pnt start, t_pnt end, t_pnt cur);
int						key_input(int key, t_fdf *param);
void					default_color(int key, t_fdf *fdf, t_map *map);
void					zoom(int key, t_fdf *fdf);
void					pan(int key, t_fdf *fdf);
void					rot(int key, t_fdf *fdf);
void					scale(int key, t_fdf *fdf);
void					proj(int key, t_fdf *fdf);
void					iso(int	*x, int *y, int z);
void					rot_x(int *y, int *z, double pitch);
void					rot_y(int *x, int *z, double yaw);
void					rot_z(int *x, int *y, double roll);

#endif
