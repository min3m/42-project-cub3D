/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:02:37 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/13 22:15:58 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprite(t_mlx **cub3d)
{
	int			x;
	int			y;
	t_sprite	temp;

	x = -1;
	while (++x < (*cub3d)->sprite_num)
	{
		y = x;
		while (++y < (*cub3d)->sprite_num)
		{
			if ((*cub3d)->sprite[x].dist > (*cub3d)->sprite[y].dist)
			{
				temp = (*cub3d)->sprite[x];
				(*cub3d)->sprite[x] = (*cub3d)->sprite[y];
				(*cub3d)->sprite[y] = temp;
			}
		}
	}
}

void	init_draw_sprite(t_cam cam, t_sprite sprite, t_draw_sprite *draw)
{
	double	inv_det;

	inv_det = 1.0 / (cam.plane_x * cam.dir_y - cam.dir_x * cam.plane_y);
	draw->sp_x = sprite.pos_x - cam.pos_x;
	draw->sp_y = sprite.pos_y - cam.pos_y;
	draw->trans_x = inv_det * (cam.dir_y * draw->sp_x - cam.dir_x * draw->sp_y);
	draw->trans_y = inv_det * (-cam.plane_y * draw->sp_x
			+ cam.plane_x * draw->sp_y);
	draw->sp_screen = (int)(WIDTH / 2 * (1 + draw->trans_x / draw->trans_y));
	draw->sp_height = abs((int)(HEIGHT / draw->trans_y));
	draw->start_y = -draw->sp_height / 2 + HEIGHT / 2;
	if (draw->start_y < 0)
		draw->start_y = 0;
	draw->end_y = draw->sp_height / 2 + HEIGHT / 2;
	if (draw->end_y >= HEIGHT)
		draw->end_y = HEIGHT - 1;
	draw->sp_width = abs((int)(HEIGHT / draw->trans_y));
	draw->start_x = -draw->sp_width / 2 + draw->sp_screen;
	if (draw->start_x < 0)
		draw->start_x = 0;
	draw->end_x = draw->sp_height / 2 + draw->sp_screen;
	if (draw->end_x >= WIDTH)
		draw->end_x = WIDTH - 1;
}

void	draw_sprites(t_mlx *cub3d, t_tex tex)
{
	int				i;
	int				j;
	t_draw_sprite	draw;

	(void) tex;
	sort_sprite(&cub3d);
	i = -1;
	while (++i < cub3d->sprite_num)
	{
		init_draw_sprite(cub3d->cam, cub3d->sprite[i], &draw);
	}
}
