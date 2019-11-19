/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:28:39 by bscussel          #+#    #+#             */
/*   Updated: 2019/09/11 15:03:06 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	* basic file extention check
	* needs improvement as it does not account for directories
*/

void	file_extention(const char *file, const char *ext)
{
	char	*dot;

	if ((dot = ft_strchr(file, '.')) != NULL)
	{
		if (!(ft_strcmp(dot, ext) == 0))
		{
			ft_putendl_fd(ERR_FILE, 2);
			ft_putendl_fd(ERR_USAGE, 2);
			exit(0);
		}
	}
}

int		main(int ac, char **av)
{
	t_fdf			*fdf;
	t_map			map;
	int				fd;

	if (ac == 2 || ac == 3)
	{
		file_extention(av[1], ".fdf");
		((fd = open(av[1], O_RDONLY)) < 0) ? err_prog(ERR_OPEN) : 0;
		map = map_init();
		read_map(fd, &map);
		close(fd);
		fdf = fdf_init(&map);
		fdf->cam = cam_init(fdf);
		draw(fdf);
		mlx_key_hook(fdf->win, key_input, fdf);
		mlx_loop(fdf->mlx);
	}
	ft_putendl_fd(ERR_USAGE, 2);
	return (0);
}
