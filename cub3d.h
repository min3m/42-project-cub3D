/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:28:18 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/23 21:04:42 by youngmch         ###   ########.fr       */
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

# define NORTH 3
# define SOUTH 4
# define WEST 5
# define EAST 6

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
	t_list	*map_str;
	int		x_size;
	int		y_size;
	t_files	root;
	t_res	res;
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

/* path_parsing1.c */

void	path_parsing(t_arg *arg, int fd);
bool	get_path(char *tmp, t_arg **arg);
bool	check_arg(t_arg *arg);
t_arg	*init_arg(t_arg *arg);

/* path_parsing2.c */

bool	get_res(char *w, char *h, t_arg **arg);
int		get_rgb(char *tmp);

/* map_parsing.c */

void	map_parsing(t_arg *arg, int fd);
t_arg	*malloc_map(t_list *map_list, t_arg *arg);
t_map	**init_map(t_list *map_list, t_arg *arg);
bool	map_atoi(char c, int *value);

/* utils.c */

void	free_all(t_list *list, t_arg *arg);
bool	free_split(char **split, int flag);
void	free_arg(t_arg *arg);
int		rgb_atoi(char **nptr);
void	print_struct(t_arg arg); //

#endif
