/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 06:23:32 by bscussel          #+#    #+#             */
/*   Updated: 2019/11/17 06:23:47 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(int key, t_fdf *fdf)
{
	(key == KEY_PLUS || key == NUM_PLUS) ? fdf->cam->zoom += 1 : 0;
	(key == KEY_MINS || key == NUM_MINS) ? fdf->cam->zoom -= 1 : 0;
	(fdf->cam->zoom < 1) ? fdf->cam->zoom = 1 : 0;
	draw(fdf);
}

void		pan(int key, t_fdf *fdf)
{
	(key == KEY_UP || key == KEY_W) ? fdf->cam->y_shift -= 5 : 0;
	(key == KEY_LFT || key == KEY_A) ? fdf->cam->x_shift -= 5 : 0;
	(key == KEY_DWN || key == KEY_S) ? fdf->cam->y_shift += 5 : 0;
	(key == KEY_RGH || key == KEY_D) ? fdf->cam->x_shift += 5 : 0;
	draw(fdf);
}

void		rot(int key, t_fdf *fdf)
{
	(key == KEY_1 || key == NUM_1) ? fdf->cam->yaw += 0.25 : 0;
	(key == KEY_2 || key == NUM_2) ? fdf->cam->roll += 0.25 : 0;
	(key == KEY_3 || key == NUM_3) ? fdf->cam->pitch += 0.25 : 0;
	(key == KEY_4 || key == NUM_4) ? fdf->cam->yaw -= 0.25 : 0;
	(key == KEY_5 || key == NUM_5) ? fdf->cam->roll -= 0.25 : 0;
	(key == KEY_6 || key == NUM_6) ? fdf->cam->pitch -= 0.25 : 0;
	draw(fdf);
}

void		proj(int key, t_fdf *fdf)
{
	fdf->cam->yaw = 0;
	fdf->cam->roll = 0;
	fdf->cam->pitch = 0;
	if (key == KEY_Q)
		fdf->cam->cam_angle = 0;
	else if (key == KEY_E)
		fdf->cam->cam_angle = 1;
	draw(fdf);
}

void		scale(int key, t_fdf *fdf)
{
	(key == KEY_COM) ? fdf->cam->z_div += 0.25 : 0;
	(key == KEY_DOT) ? fdf->cam->z_div -= 0.25 : 0;
	(fdf->cam->z_div > 10) ? fdf->cam->z_div = 10 : 0;
	(fdf->cam->z_div < 0.1) ? fdf->cam->z_div = 0.1 : 0;
	draw(fdf);
}
