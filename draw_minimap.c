/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:19:56 by youngmin          #+#    #+#             */
/*   Updated: 2023/03/16 23:52:02 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_lines(t_mlx *cub3d)
// {
// 	int	x;
// 	int	y;
// 	int	title_x;
// 	int	title_y;

// 	title_x = (WIDTH / cub3d->arg->x_size);
// 	title_y = (HEIGHT / cub3d->arg->y_size);
// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		y = -1;
// 		while (++y < HEIGHT)
// 			my_pixel_put(&(cub3d->img), x, y, 0xC0C0C0);
// 		x += title_x;
// 	}
// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		x = -1;
// 		while (++x < WIDTH)
// 			my_pixel_put(&(cub3d->img), x, y, 0xC0C0C0);
// 		y += title_y;
// 	}
// }

void	draw_player(t_mlx *cub3d, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = -1;
	while (++dy < cub3d->mini_ret)
	{
		dx = -1;
		while (++dx < cub3d->mini_ret)
			my_pixel_put(&(cub3d->img), dx + x, dy + y, color);
	}
}

void	draw_square(t_mlx *cub3d, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = -1;
	while (++dy < cub3d->mini_ret)
	{
		dx = -1;
		while (++dx < cub3d->mini_ret)
			my_pixel_put(&(cub3d->img), dx + x, dy + y, color);
	}
}

void	draw_minimap(t_mlx *cub3d)
{
	int	x;
	int	y;
	int	ret;

	ret = cub3d->mini_ret;
	y = -1;
	while (++y < cub3d->arg->y_size)
	{
		x = -1;
		while (++x < cub3d->arg->x_size)
		{
			if ((int)cub3d->cam.pos_x == x && (int)cub3d->cam.pos_y == y)
				draw_player(cub3d, x * ret, y * ret, 0x000000);
			else if (cub3d->arg->map[y][x].val == -1)
				draw_square(cub3d, x * ret, y * ret, 0xCCCC99);
			else if (cub3d->arg->map[y][x].val == 1)
				draw_square(cub3d, x * ret, y * ret, 0x0000FF);
			else if (cub3d->arg->map[y][x].val == 0)
				draw_square(cub3d, x * ret, y * ret, 0xCC66FF);
			else if (cub3d->arg->map[y][x].val == 2)
				draw_player(cub3d, x * ret, y * ret, 0xFFFFFF);
			else if (cub3d->arg->map[y][x].val >= DOOR_C)
				draw_player(cub3d, x * ret, y * ret, 0x999999);
		}
	}
}
