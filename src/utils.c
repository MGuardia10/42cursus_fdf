/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:00:01 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/05 09:16:42 by mguardia         ###   ########.fr       */
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

int	ft_max_value(float x, float y)
{
	if (x > y)
		return ((int) x);
	else
		return ((int) y);
}
