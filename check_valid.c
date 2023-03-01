/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:22:21 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/25 19:35:35 by youngmin         ###   ########.fr       */
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
			if (arg->map[i][j].val != 1 && arg->map[i][j].val != -1)
			{
				if (i == 0 || j == 0)
					ft_exit(arg, MAP);
				else if (i == arg->y_size - 1 || j == arg->x_size - 1)
					ft_exit(arg, MAP);
				else if (arg->map[i - 1][j].val == -1
					|| arg->map[i + 1][j].val == -1)
					ft_exit(arg, MAP);
				else if (arg->map[i][j - 1].val == -1
					|| arg->map[i][j + 1].val == -1)
					ft_exit(arg, MAP);
			}
		}
	}
}
