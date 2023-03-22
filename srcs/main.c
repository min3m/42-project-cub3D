/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:27:14 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/22 21:58:14 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	game_loop(t_mlx *cub3d)
{
	if (!cub3d->engine && cub3d->mouse == -1 && !cub3d->door
		&& !cub3d->sprite_num)
		return (1);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
		cub3d->img.img, 0, 0);
	if (cub3d->mouse == 1)
		move_mouse(cub3d);
	get_engine(cub3d);
	draw_background(cub3d);
	render_map(cub3d);
	return (0);
}

bool	check_filename(char *filename)
{
	char	*temp;

	temp = ft_strchr(filename, '.');
	if (temp == 0 || ft_strncmp(temp, ".cub", 5))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_arg		arg;
	t_mlx		*cub3d;

	cub3d = NULL;
	if (argc != 2)
		exit (ft_putendl_fd("Error : Wrong argument", 1));
	if (!check_filename(argv[1]))
		exit (ft_putendl_fd("Error : Wrong File name", 1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(ft_putendl_fd("File open error!", 1));
	path_parsing(&arg, fd);
	map_parsing(&arg, fd);
	check_valid(&arg);
	cub3d = game_init(cub3d, &arg, argv[1]);
	set_cam(&cub3d);
	key_hook_event(cub3d);
	return (0);
}
