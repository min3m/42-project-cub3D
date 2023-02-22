/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:28:18 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/22 23:34:11 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				t_data;

typedef struct s_res
{
	int	width;
	int	height;
}				t_res;

typedef struct s_map
{
	int	x;
	int	y;
	int	value;
}				t_map;

typedef struct s_files
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*item;
}				t_files;

typedef struct s_arg
{
	t_map	**map;
	int		x_size;
	int		y_size;
	t_files	*root;
	t_res	*res;
	int		floor_rgb;
	int		ceiling_rgb;
}				t_arg;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	t_arg	*arg;
}				t_mlx;

/* path_parsing.c */

void	path_parsing(t_arg *arg, int fd);
bool	get_path(char *tmp, t_arg **arg);
bool	check_arg(t_arg *arg);
int		get_rgb(char *tmp);
t_arg	*init_arg(t_arg *arg);

/* utils.c */

bool	free_split(char **split, int flag);
void	free_arg(t_arg *arg);
int		rgb_atoi(char **nptr);
void	print_struct(t_arg arg); //

#endif
