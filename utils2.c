/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:54:08 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/15 19:51:08 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_map(t_arg *arg, t_list *map_list)
{
	free_arg(arg);
	free_list(map_list);
	exit(ft_putendl_fd("Map error!", 1));
}

void	free_tex(t_mlx *cub3d)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (cub3d->tex[i].texture)
			free(cub3d->tex[i].texture);
	}
	free(cub3d->tex);
}

void	ft_exit(t_arg *arg, int flag)
{
	free_all(arg);
	if (flag == MAP)
		exit(ft_putendl_fd("Map error!", 1));
}

void	my_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = (char *)img->addr + (y * img->line_size
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
