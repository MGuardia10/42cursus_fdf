/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:55:34 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/03 20:15:57 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	ft_max_value(float x, float y)
{
	if (x > y)
		return ((int) x);
	else
		return ((int) y);
}

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
	*y = (*x + *y) * sin(0.8) - z;
}

void	set_proyection(float *x, float *y, float *x1, float *y1, t_all *data)
{
	if (data->map.proyection == ISO)
	{
		isometric(x, y, data);
		isometric(x1, y1, data);
	}
	// if (data->map.proyection == PARALLEL)
	// 	parallel();
}

void	bresenham(float x, float y, float x1, float y1, t_all *data)
{
	float	add_x;
	float	add_y;
	int		max;
	long	color;

	color = data->fdf[(int)y][(int)x].og_color;
	set_zoom(&x, &x1, &y, &y1, data->map.zoom);
	set_proyection(&x, &y, &x1, &y1, data);
	add_x = x1 - x;
	add_y = y1 - y;
	max = ft_max_value(fabs(add_x), fabs(add_y));
	add_x /= max;
	add_y /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data, x + data->map.init_x, y + data->map.init_y, \
						color);
		x += add_x;
		y += add_y;
	}
}

void	print_last_pixel(int x, int y, t_all *data)
{
	long	color;

	color = data->fdf[(int)y][(int)x].og_color;
	x *= data->map.zoom;
	y *= data->map.zoom;
	my_mlx_pixel_put(data, x + data->map.init_x, y + data->map.init_y, color);

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
			if (x < data->map.max_x - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data ->map.max_y - 1)
				bresenham(x, y, x, y + 1, data);
			// if (data->fdf[y][x].is_last == true)
			// 	print_last_pixel(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	draw_menu(data);
}