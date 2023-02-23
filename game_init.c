/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:24:22 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/23 18:20:35 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_exit(t_mlx *cub3d)
{
	if (cub3d)
		free(cub3d);
}

t_mlx	*game_init(t_mlx *cub3d, char *name)
{
	cub3d = malloc(sizeof(t_mlx));
	if (!cub3d)
		exit(ft_putendl_fd("Malloc error!", 1));
	cub3d->mlx_ptr = mlx_init();
	if (!cub3d->mlx_ptr)
		game_exit(cub3d);
	cub3d->win_ptr = mlx_new_window(cub3d->win_ptr, cub3d->arg->res.width,
			cub3d->arg->res.height, name);
}
