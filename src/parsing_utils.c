/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:04:45 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/07 15:05:08 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_rgb_color(t_color *color)
{
	color->r = (color->rgb >> 16) & 0xFF;
	color->g = (color->rgb >> 8) & 0xFF;
	color->b = color->rgb & 0xFF;
}

void	set_invert_color(t_color *def, t_color *invert)
{
	invert->r = 255 - def->r;
	invert->g = 255 - def->g;
	invert->b = 255 - def->b;
	invert->rgb = ((invert->r << 16) | (invert->g << 8) | invert->b);
}

void	set_betis_color(t_all *data, int x, int y)
{
	float	step;
	float	count;
	int		color;

	step = data->map.max_x / 7;
	color = GREEN_BETIS;
	count = step;
	while (count <= data->map.max_x)
	{
		if (x <= count)
		{
			data->fdf[y][x].betis_color.rgb = color;
			set_rgb_color(&data->fdf[y][x].betis_color);
			return ;
		}
		if (color == GREEN_BETIS)
			color = WHITE_BETIS;
		else
			color = GREEN_BETIS;
		count += step;
	}
	data->fdf[y][x].betis_color.rgb = GREEN_BETIS;
	set_rgb_color(&data->fdf[y][x].betis_color);
}
