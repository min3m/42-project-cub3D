/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:22:21 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/24 20:12:55 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid(t_arg *arg)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arg->y_size)
	{
		j = -1;
		while (++j < arg->x_size)
		{
			if (arg->map[i][j].value != 1 && arg->map[i][j].value != -1)
			{
				if (i == 0 || j == 0)
					ft_exit(arg, MAP);
				else if (i == arg->y_size - 1 || j == arg->x_size - 1)
					ft_exit(arg, MAP);
				else if (arg->map[i - 1][j].value == -1
					|| arg->map[i + 1][j].value == -1)
					ft_exit(arg, MAP);
				else if (arg->map[i][j - 1].value == -1
					|| arg->map[i][j + 1].value == -1)
					ft_exit(arg, MAP);
			}
		}
	}
}
