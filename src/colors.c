/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:03:37 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/09 11:59:50 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

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

t_color	set_land_color(int max_z, t_point *point)
{
	float	percent_z;

	if (point->z <= 0)
		point->land_color.rgb = BLUE_SEA;
	else
	{
		percent_z = get_percentage(point->z, 0, max_z);
		if (percent_z < 0.15)
			point->land_color.rgb = GREEN_1;
		else if (percent_z < 0.3)
			point->land_color.rgb = GREEN_2;
		else if (percent_z < 0.5)
			point->land_color.rgb = DARK_BROWN;
		else
			point->land_color.rgb = WHITE_LAND;
	}
	set_rgb_color(&point->land_color);
	return (point->land_color);
}

int	set_gradient(t_color color1, t_color color2, float ratio)
{
	t_color	gradient;

	if (color1.rgb == color2.rgb)
		return (color1.rgb);
	if (ratio < 0)
		ratio = 0;
	if (ratio >= 1)
		ratio = 1;
	gradient.r = color1.r + (int)((color2.r - color1.r) * ratio);
	gradient.g = color1.g + (int)((color2.g - color1.g) * ratio);
	gradient.b = color1.b + (int)((color2.b - color1.b) * ratio);
	return ((gradient.r << 16) | (gradient.g << 8) | gradient.b);
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
