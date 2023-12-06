/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:55:34 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/06 13:14:31 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_zoom(float *x, float *y, float *x1, float *y1, int zoom)
{
	*x *= zoom;
	*x1 *= zoom;
	*y *= zoom;
	*y1 *= zoom;
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
	*y = (*x + *y) * sin(0.8) - (z * data->map.zoom);
}

void	set_proyection(float *x, float *y, float *x1, float *y1, t_all *data)
{
	if (data->map.proyection == ISO)
	{
		isometric(x, y, data);
		isometric(x1, y1, data);
	}
}

int	*set_color(int x, int y, int x1, int y1, t_all *data)
{
	int	*color;

	color = malloc(sizeof(int) * 2);
	if (data->map.color_theme == DEFAULT)
	{
		color[0] = data->fdf[y][x].default_color;
		color[1] = data->fdf[y1][x1].default_color;
	}
	else if (data->map.color_theme == INVERT)
	{
		color[0] = data->fdf[y][x].invert_color;
		color[1] = data->fdf[y1][x1].invert_color;
	}
	else if (data->map.color_theme == BETIS)
	{
		color[0] = data->fdf[y][x].betis_color;
		color[1] = data->fdf[y1][x1].betis_color;
	}
	return (color);
}

void	bresenham(float x, float y, float x1, float y1, t_all *data)
{
	float	add_x;
	float	add_y;
	int		max;
	int		*color;

	color = set_color(x, y, x1, y1, data);
	set_zoom(&x, &x1, &y, &y1, data->map.zoom);
	set_proyection(&x, &y, &x1, &y1, data);
	add_x = x1 - x;
	add_y = y1 - y;
	max = ft_max_value(fabs(add_x), fabs(add_y));
	add_x /= max;
	add_y /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (x + data->map.init_x <= MENU_WIDTH)
			my_mlx_pixel_put(data, x + data->map.init_x, y + data->map.init_y, \
								add_shade(0.9, (unsigned int)color[0]));
		else
			my_mlx_pixel_put(data, x + data->map.init_x, y + data->map.init_y, \
								color[0]);
		x += add_x;
		y += add_y;
	}
	free(color);
}

void	draw(t_all *data)
{
	int	x;
	int	y;

	draw_background(data);
	y = 0;
	while (y < data->map.max_y)
	{
		x = 0;
		while (x < data->map.max_x)
		{
			set_betis_colors(data, x, y);
			// printf("betis color --> %d\n", data->fdf[y][x].betis_color);
			if (x < data->map.max_x - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data ->map.max_y - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	draw_menu(data);
}