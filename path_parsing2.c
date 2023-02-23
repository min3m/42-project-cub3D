/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:17:56 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/23 18:08:26 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgb(char *tmp)
{
	int	r;
	int	g;
	int	b;
	int	rgb;

	r = rgb_atoi(&tmp);
	if (r < 0 || *tmp != ',')
		return (-1);
	tmp++;
	g = rgb_atoi(&tmp);
	if (g < 0 || *tmp != ',')
		return (-1);
	tmp++;
	b = rgb_atoi(&tmp);
	if (b < 0 || *tmp != '\n')
		return (-1);
	rgb = (r << 16 | g << 8 | b);
	return (rgb);
}

bool	get_res(char *w, char *h, t_arg **arg)
{
	if (!ft_atoi(w, &((*arg)->res.width)))
		return (false);
	if (!ft_atoi(h, &((*arg)->res.height)))
		return (false);
	return (true);
}
