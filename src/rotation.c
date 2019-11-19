/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 06:48:47 by bscussel          #+#    #+#             */
/*   Updated: 2019/11/17 06:49:08 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rot_x(int *y, int *z, double pitch)
{
	int		last_y;

	last_y = *y;
	*y = last_y * cos(pitch) + *z * sin(pitch);
	*z = -last_y * sin(pitch) + *z * cos(pitch);
}

void		rot_y(int *x, int *z, double yaw)
{
	int		last_x;

	last_x = *x;
	*x = last_x * cos(yaw) + *z * sin(yaw);
	*z = -last_x * sin(yaw) + *z * cos(yaw);
}

void		rot_z(int *x, int *y, double roll)
{
	int		last_x;
	int		last_y;

	last_x = *x;
	last_y = *y;
	*x = last_x * cos(roll) - last_y * sin(roll);
	*y = last_x * sin(roll) + last_y * cos(roll);
}

void		iso(int *x, int *y, int z)
{
	int		last_x;
	int		last_y;

	last_x = *x;
	last_y = *y;
	*x = (last_x - last_y) * cos(0.5);
	*y = -z + (last_x + last_y) * sin(0.5);
}

/*
	* the 3 location values are initialized to their distance from the viewport
	* standard rotation algorithms are applied, making the initial image flat
	* isometric rotation is applied
	* x/y positions are applied (the 2D panning movements)
*/

t_pnt		depth(t_pnt p, t_fdf *fdf)
{
	p.x *= fdf->cam->zoom;
	p.y *= fdf->cam->zoom;
	p.z *= fdf->cam->zoom / fdf->cam->z_div;
	p.x -= (fdf->map->width * fdf->cam->zoom) / 2;
	p.y -= (fdf->map->height * fdf->cam->zoom) / 2;
	rot_x(&p.y, &p.z, fdf->cam->pitch);
	rot_y(&p.x, &p.z, fdf->cam->yaw);
	rot_z(&p.x, &p.y, fdf->cam->roll);
	if (fdf->cam->cam_angle == 0)
		iso(&p.x, &p.y, p.z);
	p.x += (fdf->win_w) / 2 + fdf->cam->x_shift;
	p.y += (fdf->win_h + fdf->map->height * fdf->cam->zoom) / 2
										+ fdf->cam->y_shift;
	return (p);
}
