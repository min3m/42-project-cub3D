/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:01:59 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/13 21:34:25 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*malloc_sprite(t_mlx **cub3d)
{
	int			x;
	int			y;
	int			count;
	t_sprite	*sprite;

	y = -1;
	count = 0;
	while (++y < (*cub3d)->arg->y_size)
	{
		x = -1;
		while (++x < (*cub3d)->arg->x_size)
			if ((*cub3d)->arg->map[y][x].val == 2)
				count++;
	}
	sprite = malloc(sizeof(t_sprite) * count);
	if (!sprite)
		game_exit(*cub3d, EXIT_FAILURE);
	return (sprite);
}

void	sprite_init(t_mlx **cub3d)
{
	int	x;
	int	y;
	int	index;

	(*cub3d)->sprite = malloc_sprite(cub3d);
	index = 0;
	y = -1;
	while (++y < (*cub3d)->arg->y_size)
	{
		x = -1;
		while (++x < (*cub3d)->arg->x_size)
		{
			if ((*cub3d)->arg->map[y][x].val == 2)
			{
				(*cub3d)->sprite[index].pos_x = x;
				(*cub3d)->sprite[index].pos_y = y;
				(*cub3d)->sprite[index].dist = (pow((*cub3d)->cam.pos_x - x, 2)
						+ pow((*cub3d)->cam.pos_y - y, 2));
				index++;
			}
		}
	}
	(*cub3d)->sprite_num = index;
}
