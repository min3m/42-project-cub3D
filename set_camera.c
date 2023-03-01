/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:09:00 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/25 19:37:44 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dir(t_cam *cam, int val)
{
	if (val == NORTH)
	{
		cam->dirX = 0.0;
		cam->dirY = -1.0;
	}
	else if (val == SOUTH)
	{
		cam->dirX = 0.0;
		cam->dirY = 1.0;
	}
	else if (val == WEST)
	{
		cam->dirX = -1.0;
		cam->dirY = 0.0;
	}
	else if (val == EAST)
	{
		cam->dirX = 1.0;
		cam->dirY = 0.0;
	}
}

void	set_cam(t_mlx **cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*cub3d)->arg->y_size)
	{
		j = -1;
		while (++j < (*cub3d)->arg->x_size)
		{
			if ((*cub3d)->arg->map[i][j].val >= NORTH)
			{
				(*cub3d)->cam.posX = (double)j;
				(*cub3d)->cam.posY = (double)i;
				(*cub3d)->arg->map[i][j].val = 0;
				set_dir(&((*cub3d)->cam), (*cub3d)->arg->map[i][j].val);
			}
		}
	}
	(*cub3d)->cam.planeX = 0.0;
	(*cub3d)->cam.planeY = 0.66;
	(*cub3d)->cam.move_speed = 0.5;
	(*cub3d)->cam.rot_speed = 0.5;
}
