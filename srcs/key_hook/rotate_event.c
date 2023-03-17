/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:15:06 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/17 19:47:58 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rotate_left(t_mlx **cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = (*cub3d)->cam.dir_x;
	(*cub3d)->cam.dir_x = (*cub3d)->cam.dir_x * cos((*cub3d)->cam.rot_speed)
		- (*cub3d)->cam.dir_y * sin((*cub3d)->cam.rot_speed);
	(*cub3d)->cam.dir_y = old_dir_x * sin((*cub3d)->cam.rot_speed)
		+ (*cub3d)->cam.dir_y * cos((*cub3d)->cam.rot_speed);
	old_plane_x = (*cub3d)->cam.plane_x;
	(*cub3d)->cam.plane_x = old_plane_x * cos((*cub3d)->cam.rot_speed)
		- (*cub3d)->cam.plane_y * sin((*cub3d)->cam.rot_speed);
	(*cub3d)->cam.plane_y = old_plane_x * sin((*cub3d)->cam.rot_speed)
		+ (*cub3d)->cam.plane_y * cos((*cub3d)->cam.rot_speed);
}

void	rotate_right(t_mlx **cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = (*cub3d)->cam.dir_x;
	(*cub3d)->cam.dir_x = (*cub3d)->cam.dir_x * cos(-(*cub3d)->cam.rot_speed)
		- (*cub3d)->cam.dir_y * sin(-(*cub3d)->cam.rot_speed);
	(*cub3d)->cam.dir_y = old_dir_x * sin(-(*cub3d)->cam.rot_speed)
		+ (*cub3d)->cam.dir_y * cos(-(*cub3d)->cam.rot_speed);
	old_plane_x = (*cub3d)->cam.plane_x;
	(*cub3d)->cam.plane_x = old_plane_x * cos(-(*cub3d)->cam.rot_speed)
		- (*cub3d)->cam.plane_y * sin(-(*cub3d)->cam.rot_speed);
	(*cub3d)->cam.plane_y = old_plane_x * sin(-(*cub3d)->cam.rot_speed)
		+ (*cub3d)->cam.plane_y * cos(-(*cub3d)->cam.rot_speed);
}

void	rotate_event(int keycode, t_mlx *cub3d)
{
	if (keycode == KEY_LEFT)
		rotate_right(&cub3d);
	else if (keycode == KEY_RIGHT)
		rotate_left(&cub3d);
}
