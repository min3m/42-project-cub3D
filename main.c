/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:27:14 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/23 20:54:04 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_arg	arg;
	// t_mlx	*cub3d;

	if (argc != 2)
		exit (ft_putendl_fd("Error : Wrong argument", 1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(ft_putendl_fd("File open error!", 1));
	path_parsing(&arg, fd);
	map_parsing(&arg, fd);
	print_struct(arg);
	// cub3d = game_init(cub3d, argv[1]);
	return (0);
}
