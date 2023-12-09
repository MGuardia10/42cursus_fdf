/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:00:01 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/09 11:57:54 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_count_words(char **split)
{
	int	i;

	i = 0;
	while (split[i] && ft_isprint(split[i][0]))
		i++;
	return (i);
}

void	get_map_name(char *file, t_all *data)
{
	char	*name;

	name = ft_strrchr(file, '/') + 1;
	if (!name)
		data->map.name = file;
	else
		data->map.name = name;
}

void	get_z_values(int x, int y, int z_value, t_all *data)
{
	data->fdf[y][x].z = z_value;
	if (z_value > data->map.max_z)
		data->map.max_z = z_value;
	if (z_value < data->map.min_z)
		data->map.min_z = z_value;
}

float	get_percentage(int nbr, int min_value, int max_value)
{
	float	res;

	res = ((float)(nbr - min_value)) / ((float)(max_value - min_value));
	return (res);
}

int	ft_max_value(float x, float y)
{
	if (x > y)
		return ((int) x);
	else
		return ((int) y);
}
