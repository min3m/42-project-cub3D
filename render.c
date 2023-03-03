/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:07:40 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/03 18:50:33 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map(t_mlx *cub3d, t_ray *ray, int x)
{
	t_draw	draw;
	int		color;
	int		y;

	init_draw(cub3d, &draw);
	y = draw.draw_start - 1;
	if (cub3d->arg->map[ray->map_y][ray->map_x].val == 1)
		color = 0x000000FF;
	else if (cub3d->arg->map[ray->map_y][ray->map_x].val == 2)
		color = 0x0000FF00;
	if (ray->hit_side == 1)
		color /= 2;
	while (++y < draw.draw_end)
		my_pixel_put(&(cub3d->img), x, y, color);
}

void	render_map(t_mlx *cub3d)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		init_ray(cub3d, &(cub3d->ray), x);
		where_hit(cub3d, &(cub3d->ray));
		draw_map(cub3d, &(cub3d->ray), x);
		// printf("%f\n",cub3d->ray.perpdist);
		// printf("%f\n",cub3d->cam.dir_x);
		// printf("%f\n",cub3d->cam.dir_y);
		// printf("%f\n",cub3d->ray.cam_x);
		// printf("%f\n",cub3d->ray.raydir_x);
		// printf("%f\n",cub3d->ray.raydir_y);
	}
}
