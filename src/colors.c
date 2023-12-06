/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:03:37 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/06 13:57:31 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_betis_colors(t_all *data, int x, int y)
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
			data->fdf[y][x].betis_color = color;
			return ;
		}
		if (color == GREEN_BETIS)
			color = WHITE_BETIS;
		else
			color = GREEN_BETIS;
		count += step;
	}
}

int	invert_color(unsigned int color)
{
	unsigned int	invert_r;
	unsigned int	invert_g;
	unsigned int	invert_b;

	invert_r = 255 - ((color >> 16) & 0xFF);
	invert_g = 255 - ((color >> 8) & 0xFF);
	invert_b = 255 - (color & 0xFF);
	return ((invert_r << 16) | (invert_g << 8) | (invert_b));
}

int	add_shade(float transparency, unsigned int color)
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (transparency > 1)
		transparency = 1;
	else if (transparency < 0)
		transparency = 0;
	t = (unsigned int)(255 * transparency);
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	return ((t << 24) | (r << 16) | (g << 8) | b);
}
