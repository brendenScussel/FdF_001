/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:17:52 by bscussel          #+#    #+#             */
/*   Updated: 2019/11/17 06:53:04 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		default_color(int key, t_fdf *fdf, t_map *map)
{
	if (key == KEY_0 || key == NUM_0)
		map->color_count++;
	(map->color_count > 9) ? map->color_count = 0 : 0;
	(map->color_count == 0) ? map->default_c = CLR_G : 0;
	(map->color_count == 1) ? map->default_c = CLR_B : 0;
	(map->color_count == 2) ? map->default_c = CLR_P : 0;
	(map->color_count == 3) ? map->default_c = CLR_R : 0;
	(map->color_count == 4) ? map->default_c = CLR_O : 0;
	(map->color_count == 5) ? map->default_c = CLR_Y : 0;
	(map->color_count == 6) ? map->default_c = CLR_W1 : 0;
	(map->color_count == 7) ? map->default_c = CLR_C : 0;
	(map->color_count == 8) ? map->default_c = CLR_M : 0;
	(map->color_count == 9) ? map->default_c = CLR_K2 : 0;
	draw(fdf);
}

void		color_separate(int color, int **rgb)
{
	int		r;
	int		g;
	int		b;

	r = ((color >> 16) & 0xFF);
	g = ((color >> 8) & 0xFF);
	b = ((color) & 0xFF);
	rgb[0][0] = r;
	rgb[0][1] = g;
	rgb[0][2] = b;
}

/*
    * given the two colors, and the resulting percentage
	* the individual rgb values are applied to two int arrays
	* 'iv[]' (individual values) are the resulting combonation of each value of red, green, and blue
	* the 'iv[]'s are bit-shift combined into an interger
	*	(iv[0] (red) is shifted to the first 8 points, iv[1] (green) is shifted to the middle 8 points,
	*		iv[2] (blue) doesn't need to be shifted)
*/

int			gradient(double percent, int color1, int color2)
{
	int		*rgb1;
	int		*rgb2;
	int		iv[3];

	rgb1 = (int *)malloc(sizeof(int) * 3);
	rgb2 = (int *)malloc(sizeof(int) * 3);
	color_separate(color1, &rgb1);
	color_separate(color2, &rgb2);
	iv[0] = ((int)((1 - percent) * rgb1[0]) + (percent * rgb2[0]));
	iv[1] = ((int)((1 - percent) * rgb1[1]) + (percent * rgb2[1]));
	iv[2] = ((int)((1 - percent) * rgb1[2]) + (percent * rgb2[2]));
	free(rgb1);
	free(rgb2);
	rgb1 = NULL;
	rgb2 = NULL;
	return ((iv[0] << 16) | (iv[1] << 8) | iv[2]);
}

/*
    * given either the 'x' or 'y' values of 'a', 'b', and 'cur'
    * the percentage returned is value of the current location (cur - a) divide by the difference between 'a' and 'b'
*/

double		grad_perc(int a, int b, int cur)
{
	double	loc;
	double	dist;

	loc = cur - a;
	dist = b - a;
	return ((dist == 0) ? 1.0 : (loc / dist));
}

/*
    * given the three point parameter
    *   (x, y, and color of 'a' and 'b', with 'cur' representing the current pixel in between)
    * if the absolute difference of (b->x - a->x) is greater than the 'y' equivelent, find the percentage of 'cur' to 'b'
    * the actual color will be the return value of percentage of 'a->color' and 'b->color'
*/

int			make_color(t_pnt a, t_pnt b, t_pnt cur)
{
	double	perc;
	int		color_average;
	t_pnt	delta;

	delta.x = ABSOL(b.x - a.x);
	delta.y = ABSOL(b.y - a.y);
	if (delta.x > delta.y)
		perc = grad_perc(a.x, b.x, cur.x);
	else
		perc = grad_perc(a.y, b.y, cur.y);
	color_average = gradient(perc, a.col, b.col);
	return (color_average);
}
