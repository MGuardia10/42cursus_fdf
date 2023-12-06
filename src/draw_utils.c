/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:15:40 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/06 16:34:00 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_last_pixel(float x, float y, t_all *data)
{
	int	color;

	if (data->map.color_theme == DEFAULT)
		color = data->fdf[(int)y][(int)x].default_color;
	else if (data->map.color_theme == INVERT)
		color = data->fdf[(int)y][(int)x].invert_color;
	else if (data->map.color_theme == BETIS)
		color = data->fdf[(int)y][(int)x].betis_color;
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
