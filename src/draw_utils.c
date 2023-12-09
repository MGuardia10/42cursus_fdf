/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:15:40 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/09 20:46:14 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_color(float *fcoords, int x1, int y1, t_all *data)
{
	int	x;
	int	y;

	x = (int)fcoords[0];
	y = (int)fcoords[1];
	if (data->map.color_theme == DEFAULT)
	{
		data->map.curr_colors[0] = data->fdf[y][x].default_color;
		data->map.curr_colors[1] = data->fdf[y1][x1].default_color;
	}
	else if (data->map.color_theme == INVERT)
	{
		data->map.curr_colors[0] = data->fdf[y][x].invert_color;
		data->map.curr_colors[1] = data->fdf[y1][x1].invert_color;
	}
	else if (data->map.color_theme == LAND)
	{
		data->map.curr_colors[0] = data->fdf[y][x].land_color;
		data->map.curr_colors[1] = data->fdf[y1][x1].land_color;
	}
}

void	set_zoom(float *fcoords, float *x, float *y, int zoom)
{
	fcoords[0] *= zoom;
	fcoords[1] *= zoom;
	*x *= zoom;
	*y *= zoom;
}

void	isometric(float *x, float *y, t_all *data)
{
	int	z;
	int	coord_x;
	int	coord_y;

	coord_x = (int)(*x / data->map.zoom);
	coord_y = (int)(*y / data->map.zoom);
	z = data->fdf[coord_y][coord_x].z;
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - (z);
}

void	put_last_pixel(float x, float y, t_all *data)
{
	int	color;

	if (data->map.color_theme == DEFAULT)
		color = data->fdf[(int)y][(int)x].default_color.rgb;
	else if (data->map.color_theme == INVERT)
		color = data->fdf[(int)y][(int)x].invert_color.rgb;
	else if (data->map.color_theme == LAND)
		color = data->fdf[(int)y][(int)x].land_color.rgb;
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
