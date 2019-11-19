/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 06:28:06 by bscussel          #+#    #+#             */
/*   Updated: 2019/11/17 06:31:00 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt			make_point(int x, int y, t_fdf *fdf)
{
	t_pnt		point;
	int			i;

	i = (y * fdf->map->width + x);
	point.x = x;
	point.y = y;
	point.z = fdf->map->z_arr[i];
	if (fdf->map->c_arr[i] == -1)
		point.col = fdf->map->default_c;
	else
		point.col = fdf->map->c_arr[i];
	return (depth(point, fdf));
}

/*
	* i is the current location in the data_address string
	* first block is the red value
	* then the green
	* and finally the blue
	* I don't touch the alpha channel
*/

void			light_pixel(t_fdf *fdf, int x, int y, int color)
{
	int			i;

	if (x < fdf->win_w && x >= 0 && y >= 0 && y < fdf->win_h)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

/*
	* [I use the terms "drive" and "passive" to describe 3 things in draw_line]
	* [1: the increment values for either 'x' or 'y']
	* [2: The greater of the of the delta values]
	*	[because the can be swapped if not initially in the "correct order"]
	* [3: the main vector value being altered.]
	*	[if x is bigger than y, x is the drive, and x is "cur" value that will always change]
	*
	* 'da' DRIVE()  is the direction the value increments(+, -, undefined (0))
	* if error is greater than -1, decrease error by: 2 * Driving Value
	* 	then increment the passive value
	* if error is less than 0, increase by: 2 * Passive
	*	 then increment Driving Value
*/

static void		draw_line(t_pnt a, t_pnt b, t_fdf *fdf)
{
	t_pnt		delta;
	t_pnt		cur;
	t_pnt		da;
	int			es[2];

	delta.x = ABSOL(b.x - a.x);
	delta.y = ABSOL(b.y - a.y);
	cur = a;
	da.x = DRIVE(b.x - a.x);
	da.y = DRIVE(b.y - a.y);
	es[1] = 0;
	if (delta.y > delta.x)
		es[1] = ft_swap(&delta.x, &delta.y);
	es[0] = 2 * (delta.y - delta.x);
	while (cur.x != b.x || cur.y != b.y)
	{
		light_pixel(fdf, cur.x, cur.y, make_color(a, b, cur));
		while (es[0] >= 0)
		{
			es[0] -= (2 * delta.x);
			(es[1] == 1) ? (cur.x += da.x) : (cur.y += da.y);
		}
		es[0] += (2 * delta.y);
		(es[1] == 1) ? (cur.y += da.y) : (cur.x += da.x);
	}
}

/*
	* zero out the data address to win_h * win_w * 2 (4 bits per pixel)
	* cast the data_add (a sting of chars) to an int* (still a string of numbers)
	* alternate the pixel color to dark grey every tenth (just because)
*/

static void		draw_background(t_fdf *fdf)
{
	int			*img;
	int			i;

	i = 0;
	ft_bzero(fdf->data_addr, fdf->win_h * fdf->win_w *
			(fdf->bits_per_pixel / 8));
	img = (int *)(fdf->data_addr);
	while (i < (fdf->win_h * fdf->win_w))
	{
		img[i] = (i % 10 == 0) ? CLR_K1 : CLR_K2;
		i++;
	}
}

/*
	* point (0,0) in a digital space is the top left corner
	* from that starting position two lines radiate out to the next points
	* should we be on the second row, we cast another line diagonally backwards
	*	to create a triangle
*/

void			draw(t_fdf *fdf)
{
	int			xy[2];

	draw_background(fdf);
	xy[0] = 0;
	xy[1] = 0;
	while (xy[1] < fdf->map->height)
	{
		if (xy[0] != fdf->map->width - 1)
			draw_line(make_point(xy[0], xy[1], fdf),
					make_point(xy[0] + 1, xy[1], fdf), fdf);
		if (xy[1] != fdf->map->height - 1)
			draw_line(make_point(xy[0], xy[1], fdf),
					make_point(xy[0], xy[1] + 1, fdf), fdf);
		if (xy[0] >= 1 && xy[1] >= 1)
			draw_line(make_point(xy[0], xy[1], fdf),
					make_point(xy[0] - 1, xy[1] - 1, fdf), fdf);
		if (xy[0] == fdf->map->width - 1)
		{
			xy[0] = 0;
			xy[1]++;
		}
		else
			xy[0]++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
