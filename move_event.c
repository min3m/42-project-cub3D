/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:10:29 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/12 23:30:53 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_event(int keycode, t_mlx *cub3d)
{
	double	dx;
	double	dy;

	dx = cub3d->cam.dir_x / sqrtf(powf(cub3d->cam.dir_x, 2)
			+ powf(cub3d->cam.dir_y, 2));
	dy = cub3d->cam.dir_y / sqrtf(powf(cub3d->cam.dir_x, 2)
			+ powf(cub3d->cam.dir_y, 2));
	if (keycode == KEY_W)
		move_forward(&cub3d, dx, dy);
	else if (keycode == KEY_S)
		move_back(&cub3d, -dx, -dy);
	else if (keycode == KEY_A)
		move_left(&cub3d, dy, -dx);
	else if (keycode == KEY_D)
		move_right(&cub3d, -dy, dx);
}

void	move_forward(t_mlx **cub3d, double dx, double dy)
{
	double	vec_x;
	double	vec_y;

	vec_x = dx * (*cub3d)->cam.move_speed;
	vec_y = dy * (*cub3d)->cam.move_speed;
	if (!((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val))
		(*cub3d)->cam.pos_x += vec_x;
	if (!((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
				* 1.1)][(int)((*cub3d)->cam.pos_x)]).val)
		(*cub3d)->cam.pos_y += vec_y;
}

void	move_back(t_mlx **cub3d, double dx, double dy)
{
	double	vec_x;
	double	vec_y;

	vec_x = dx * (*cub3d)->cam.move_speed;
	vec_y = dy * (*cub3d)->cam.move_speed;
	if (!((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val))
		(*cub3d)->cam.pos_x += vec_x;
	if (!((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
				* 1.1)][(int)((*cub3d)->cam.pos_x)]).val)
		(*cub3d)->cam.pos_y += vec_y;
}

void	move_left(t_mlx **cub3d, double dx, double dy)
{
	double	vec_x;
	double	vec_y;

	vec_x = dx * (*cub3d)->cam.move_speed;
	vec_y = dy * (*cub3d)->cam.move_speed;
	if (!((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val))
		(*cub3d)->cam.pos_x += vec_x;
	if (!((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
				* 1.1)][(int)((*cub3d)->cam.pos_x)]).val)
		(*cub3d)->cam.pos_y += vec_y;
}

void	move_right(t_mlx **cub3d, double dx, double dy)
{
	double	vec_x;
	double	vec_y;

	vec_x = dx * (*cub3d)->cam.move_speed;
	vec_y = dy * (*cub3d)->cam.move_speed;
	if (!((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val))
		(*cub3d)->cam.pos_x += vec_x;
	if (!((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
				* 1.1)][(int)((*cub3d)->cam.pos_x)]).val)
		(*cub3d)->cam.pos_y += vec_y;
}
