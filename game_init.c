/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:24:22 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/24 21:55:53 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_exit(t_mlx *cub3d, int flag)
{
	if (cub3d && cub3d->img.img)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.img);
	if (cub3d && cub3d->win_ptr)
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	if (cub3d && cub3d->mlx_ptr)
		free(cub3d->mlx_ptr);
	if (cub3d)
	{
		free_all(cub3d->arg);
		free(cub3d);
	}
	if (flag)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

t_mlx	*game_init(t_mlx *cub3d, t_arg *arg, char *name)
{
	cub3d = malloc(sizeof(t_mlx));
	cub3d->arg = arg;
	if (!cub3d)
		game_exit(cub3d, EXIT_FAILURE);
	cub3d->mlx_ptr = mlx_init();
	if (!cub3d->mlx_ptr)
		game_exit(cub3d, EXIT_FAILURE);
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, cub3d->arg->res.width, \
			cub3d->arg->res.height, name);
	if (!cub3d->win_ptr)
		game_exit(cub3d, EXIT_FAILURE);
	cub3d->img.img = mlx_new_image(cub3d->mlx_ptr, cub3d->arg->res.width, \
			cub3d->arg->res.height);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, \
			&cub3d->img.bits_per_pixel, &cub3d->img.line_size, \
			&cub3d->img.endian);
	return (cub3d);
}
