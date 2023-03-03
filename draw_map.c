/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:19:56 by youngmin          #+#    #+#             */
/*   Updated: 2023/03/03 18:09:18 by youngmch         ###   ########.fr       */
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

// void	draw_square(t_mlx *cub3d, int x, int y, int color)
// {
// 	int	dx;
// 	int	dy;
// 	int	title_x;
// 	int	title_y;

// 	title_x = (WIDTH / cub3d->arg->x_size);
// 	title_y = (HEIGHT / cub3d->arg->y_size);
// 	dy = -1;
// 	while (++dy < title_y)
// 	{
// 		dx = -1;
// 		while (++dx < title_x)
// 			my_pixel_put(&(cub3d->img), dx + x, dy + y, color);
// 	}
// }

// void	draw_squares(t_mlx *cub3d)
// {
// 	int	x;
// 	int	y;
// 	int	title_x;
// 	int	title_y;

// 	title_x = (WIDTH / cub3d->arg->x_size);
// 	title_y = (HEIGHT / cub3d->arg->y_size);
// 	y = -1;
// 	while (++y < cub3d->arg->y_size)
// 	{
// 		x = -1;
// 		while (++x < cub3d->arg->x_size)
// 		{
// 			if (cub3d->arg->map[y][x].val == 1)
// 				draw_square(cub3d, title_x * x, title_y * y, 0x0000FF);
// 			else
// 				draw_square(cub3d, title_x * x, title_y * y, 0xFFFFFF);
// 		}
// 	}
// }
