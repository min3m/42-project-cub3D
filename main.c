/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:27:14 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/15 22:25:41 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_mlx *cub3d)
{
	static int	count = 0;

	count++;
	if (count <= 100)
		return (1);
	count = 0;
	draw_background(cub3d);
	render_map(cub3d);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
		cub3d->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_arg		arg;
	t_mlx		*cub3d;

	cub3d = NULL;
	if (argc != 2)
		exit (ft_putendl_fd("Error : Wrong argument", 1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(ft_putendl_fd("File open error!", 1));
	path_parsing(&arg, fd);
	map_parsing(&arg, fd);
	check_valid(&arg);
	cub3d = game_init(cub3d, &arg, argv[1]);
	set_cam(&cub3d);
	sprite_init(&cub3d);
	key_hook_event(cub3d);
	return (0);
}
