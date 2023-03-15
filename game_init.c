/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:24:22 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/15 21:45:11 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*get_texture(t_mlx *cub3d, char *path, t_data *img, int index)
{
	int	x;
	int	y;
	int	*result;

	img->img = mlx_xpm_file_to_image(cub3d->mlx_ptr, path,
			&img->img_w, &img->img_h);
	if (!(img->img))
		game_exit(cub3d, EXIT_FAILURE);
	cub3d->tex[index].width = img->img_w;
	cub3d->tex[index].height = img->img_h;
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_size, &img->endian);
	result = malloc(sizeof(int) * img->img_w * img->img_h);
	if (!result)
		game_exit(cub3d, EXIT_FAILURE);
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			result[img->img_w * y + x] = img->addr[img->img_w * y + x];
	}
	mlx_destroy_image(cub3d->mlx_ptr, img->img);
	return (result);
}

void	load_texture(t_mlx **cub3d)
{
	t_data	img;

	(*cub3d)->tex = malloc(sizeof(t_tex) * 6);
	if (!(*cub3d)->tex)
		game_exit(*cub3d, EXIT_FAILURE);
	(*cub3d)->tex[0].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.no, &img, 0);
	(*cub3d)->tex[1].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.so, &img, 1);
	(*cub3d)->tex[2].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.we, &img, 2);
	(*cub3d)->tex[3].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.ea, &img, 3);
	(*cub3d)->tex[4].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.sprite1, &img, 4);
	(*cub3d)->tex[5].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.sprite2, &img, 5);
}

void	game_exit(t_mlx *cub3d, int flag)
{
	if (cub3d && cub3d->img.img)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.img);
	if (cub3d && cub3d->win_ptr)
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	if (cub3d && cub3d->mlx_ptr)
		free(cub3d->mlx_ptr);
	if (cub3d)
	{
		free_all(cub3d->arg);
		if (cub3d->sprite)
			free(cub3d->sprite);
		if (cub3d->tex)
			free_tex(cub3d);
		free(cub3d);
	}
	if (flag)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

t_mlx	*game_init(t_mlx *cub3d, t_arg *arg, char *name)
{
	cub3d = malloc(sizeof(t_mlx));
	cub3d->arg = arg;
	if (!cub3d)
		game_exit(cub3d, EXIT_FAILURE);
	cub3d->mlx_ptr = mlx_init();
	if (!cub3d->mlx_ptr)
		game_exit(cub3d, EXIT_FAILURE);
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, WIDTH, HEIGHT, name);
	if (!cub3d->win_ptr)
		game_exit(cub3d, EXIT_FAILURE);
	load_texture(&cub3d);
	cub3d->img.img = mlx_new_image(cub3d->mlx_ptr, WIDTH, HEIGHT);
	cub3d->img.addr = (int *)mlx_get_data_addr(cub3d->img.img, \
			&cub3d->img.bits_per_pixel, &cub3d->img.line_size, \
			&cub3d->img.endian);
	return (cub3d);
}
