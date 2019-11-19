/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_and_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 06:26:10 by bscussel          #+#    #+#             */
/*   Updated: 2019/11/17 06:27:42 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		help_message(t_fdf *fdf)
{
	int		x;
	int		y;
	int		shift;

	x = (fdf->win_w / 2) - 50;
	y = (fdf->win_h / 3) - 50;
	shift = (fdf->win_h == WIN_H1) ? 30 : 25;
	mlx_string_put(fdf->mlx, fdf->win, x, y, CLR_W2, CONTROL1);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W1, CONTROL2);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W2, CONTROL3);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W1, CONTROL4);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W2, CONTROL5);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W1, CONTROL6);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W2, CONTROL7);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W1, CONTROL8);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W2, CONTROL9);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W1, CONTROL10);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W2, CONTROL11);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_W1, CONTROL12);
	mlx_string_put(fdf->mlx, fdf->win, x, y += shift, CLR_R, CONTROL13);
}

static void		help_prompt(t_fdf *fdf)
{
	int			x;
	int			y;

	y = fdf->win_h / 10;
	if (fdf->h_flag == 0)
	{
		fdf->h_flag = 1;
		mlx_clear_window(fdf->mlx, fdf->win);
		while (y++ < fdf->win_h - (fdf->win_h / 12))
		{
			x = fdf->win_w / 8;
			while (x++ < fdf->win_w - (fdf->win_w / 8))
				mlx_pixel_put(fdf->mlx, fdf->win, x, y, CLR_K1);
		}
		help_message(fdf);
	}
	else if (fdf->h_flag == 1)
	{
		fdf->h_flag = 0;
		mlx_clear_window(fdf->mlx, fdf->win);
		draw(fdf);
	}
}

static void		fdf_exit(t_fdf *fdf)
{
	fdf->map = NULL;
	free(fdf->cam);
	fdf->cam = NULL;
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf);
	fdf = NULL;
	ft_putendl("closing FdF...");
	exit(0);
}

int				key_input(int key, t_fdf *param)
{
	if (key == KEY_ESC)
		fdf_exit(param);
	(key == KEY_PLUS || key == KEY_MINS || key == NUM_PLUS || key == NUM_MINS)
		? zoom(key, param) : 0;
	(key == KEY_LFT || key == KEY_RGH || key == KEY_DWN || key == KEY_UP ||
		key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D) ?
		pan(key, param) : 0;
	(key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4 ||
		key == KEY_5 || key == KEY_6 || key == NUM_1 || key == NUM_2 ||
		key == NUM_3 || key == NUM_4 || key == NUM_5 || key == NUM_6) ?
		rot(key, param) : 0;
	(key == KEY_0 || key == NUM_0) ? default_color(key, param, param->map) : 0;
	(key == KEY_Q || key == KEY_E) ? proj(key, param) : 0;
	(key == KEY_DOT || key == KEY_COM) ? scale(key, param) : 0;
	(key == KEY_H) ? help_prompt(param) : 0;
	return (0);
}
