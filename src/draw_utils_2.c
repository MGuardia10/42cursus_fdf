/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:56:29 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/07 20:59:08 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_last_pixel(float x, float y, t_all *data)
{
	int	color;

	if (data->map.color_theme == DEFAULT)
		color = data->fdf[(int)y][(int)x].default_color.rgb;
	else if (data->map.color_theme == INVERT)
		color = data->fdf[(int)y][(int)x].invert_color.rgb;
	else if (data->map.color_theme == BETIS)
		color = data->fdf[(int)y][(int)x].betis_color.rgb;
	x *= data->map.zoom;
	y *= data->map.zoom;
	if (data->map.proyection == ISO)
		isometric(&x, &y, data);
	if (x + data->map.init_x <= MENU_WIDTH)
		my_mlx_pixel_put(data, x + data->map.init_x, y + data->map.init_y, \
						add_shade(0.9, (unsigned int)color));
	else
		my_mlx_pixel_put(data, x + data->map.init_x, y + data->map.init_y, \
								color);
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
