/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:19:17 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/03 18:18:03 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	print_struct(t_mlx *cub3d)
// {
// 	int	i = 0;
// 	int	j = 0;

// 	printf("WIDTH : %d\n", WIDTH);
// 	printf("HEIGHT : %d\n", HEIGHT);
// 	printf("NO : %s\n", cub3d->arg->root.no);
// 	printf("SO : %s\n", cub3d->arg->root.so);
// 	printf("WE : %s\n", cub3d->arg->root.we);
// 	printf("EA : %s\n", cub3d->arg->root.ea);
// 	printf("S : %s\n", cub3d->arg->root.item);
// 	printf("F : %d\n", cub3d->arg->floor_rgb);
// 	printf("C : %d\n", cub3d->arg->ceiling_rgb);
// 	printf("x_size : %d\n", cub3d->arg->x_size);
// 	printf("y_size : %d\n", cub3d->arg->y_size);
// 	while (i < cub3d->arg->y_size)
// 	{
// 		j = 0;
// 		while (j < cub3d->arg->x_size)
// 		{
// 			if (cub3d->arg->map[i][j].val != -1)
// 				printf(" ");
// 			printf("%d", cub3d->arg->map[i][j].val);
// 			j++;
// 		}
// 		i++;
// 		printf("\n");
// 	}
// 	printf("posX : %f\n", cub3d->cam.posX);
// 	printf("posY : %f\n", cub3d->cam.posY);
// 	printf("dirX : %f\n", cub3d->cam.dirX);
// 	printf("dirY : %f\n", cub3d->cam.dirY);
// 	printf("planeX : %f\n", cub3d->cam.planeX);
// 	printf("planeX : %f\n", cub3d->cam.planeY);
// 	printf("move_speed : %f\n", cub3d->cam.move_speed);
// 	printf("rot_speed : %f\n", cub3d->cam.rot_speed);
// }

int	rgb_atoi(char **nptr)
{
	int				nbr;
	int				sign;
	unsigned int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	if ((*nptr)[i] == '-')
		sign = -1;
	if ((*nptr)[i] == '-' || (*nptr)[i] == '+')
		i++;
	while ((*nptr)[i] >= '0' && (*nptr)[i] <= '9')
	{
		nbr = (nbr * 10) + ((*nptr)[i++] - '0') * sign;
		if (nbr > 255)
			return (-1);
		if (nbr < 0)
			return (-1);
	}
	*nptr = *nptr + i;
	return (nbr);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->str);
		free(list);
		list = tmp;
	}
}

void	free_all(t_arg *arg)
{
	int		i;

	i = -1;
	while (++i < arg->y_size)
		free(arg->map[i]);
	free(arg->map);
	free_arg(arg);
}

void	free_arg(t_arg *arg)
{
	if (arg->root.no)
		free(arg->root.no);
	if (arg->root.so)
		free(arg->root.so);
	if (arg->root.we)
		free(arg->root.we);
	if (arg->root.ea)
		free(arg->root.ea);
	if (arg->root.item)
		free(arg->root.item);
}

bool	free_split(char **split, int flag)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	if (flag)
		return (true);
	return (false);
}
