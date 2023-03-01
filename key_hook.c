/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:53:25 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/26 13:15:43 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_mlx *cub3d)
{
	if (keycode == KEY_ESC)
		game_exit(cub3d, EXIT_SUCCESS);
	return (0);
}

void	key_hook_event(t_mlx *cub3d)
{
	mlx_hook(cub3d->win_ptr, KEY_PRESS, 0, key_hook, cub3d);
	mlx_loop_hook(cub3d->mlx_ptr, game_loop, cub3d);
	mlx_loop(cub3d->mlx_ptr);
}
