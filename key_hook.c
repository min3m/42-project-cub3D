/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:53:25 by youngmin          #+#    #+#             */
/*   Updated: 2023/03/01 18:49:19 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	click_exit(t_mlx *cub3d)
{
	game_exit(cub3d, EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_mlx *cub3d)
{
	if (keycode == KEY_ESC)
		game_exit(cub3d, EXIT_SUCCESS);
	return (0);
}

void	key_hook_event(t_mlx *cub3d)
{
	mlx_hook(cub3d->win_ptr, KEY_PRESS, 0, key_hook, cub3d);
	mlx_hook(cub3d->win_ptr, KEY_EXIT, 0, click_exit, cub3d);
	mlx_loop_hook(cub3d->mlx_ptr, game_loop, cub3d);
	mlx_loop(cub3d->mlx_ptr);
}
