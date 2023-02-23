/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:19:17 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/23 21:38:11 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_struct(t_arg arg)
{
	int	i = 0;
	int	j = 0;

	printf("WIDTH : %d\n", arg.res.width);
	printf("HEIGHT : %d\n", arg.res.height);
	printf("NO : %s\n", arg.root.no);
	printf("SO : %s\n", arg.root.so);
	printf("WE : %s\n", arg.root.we);
	printf("EA : %s\n", arg.root.ea);
	printf("S : %s\n", arg.root.item);
	printf("F : %d\n", arg.floor_rgb);
	printf("C : %d\n", arg.ceiling_rgb);
	printf("x_size : %d\n", arg.x_size);
	printf("y_size : %d\n", arg.y_size);
	while (i < arg.y_size)
	{
		j = 0;
		while (j < arg.x_size)
		{
			printf("%d", arg.map[i][j].value);
			j++;
		}
		i++;
		printf("\n");
	}
}

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

void	free_all(t_list *list, t_arg *arg)
{
	int		i;
	t_list	*tmp;

	i = -1;
	while (list)
	{
		tmp = list->next;
		free(list->str);
		free(list);
		list = tmp;
	}
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
