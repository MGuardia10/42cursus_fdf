/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:55:34 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/07 13:10:56 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	set_proyection(float *fcoords, float *x, float *y, t_all *data)
{
	if (data->map.proyection == ISO)
	{
		isometric(&fcoords[0], &fcoords[1], data);
		isometric(x, y, data);
	}
}

int	*set_color(float *fcoords, int x1, int y1, t_all *data)
{
	int	*color;
	int	x;
	int	y;

	color = malloc(sizeof(int) * 2);
	x = (int)fcoords[0];
	y = (int)fcoords[1];
	if (data->map.color_theme == DEFAULT)
	{
		color[0] = data->fdf[y][x].default_color.rgb;
		color[1] = data->fdf[y1][x1].default_color.rgb;
	}
	else if (data->map.color_theme == INVERT)
	{
		color[0] = data->fdf[y][x].invert_color.rgb;
		color[1] = data->fdf[y1][x1].invert_color.rgb;
	}
	else if (data->map.color_theme == BETIS)
	{
		color[0] = data->fdf[y][x].betis_color.rgb;
		color[1] = data->fdf[y1][x1].betis_color.rgb;
	}
	return (color);
}

void	print_pixel(int max, float *fcoords, int *color, t_all *data)
{
	// int	gradient;
	(void)max;

	// if (color[0] == color[1])
	// {
		if (fcoords[0] + data->map.init_x <= MENU_WIDTH)
			my_mlx_pixel_put(data, fcoords[0] + data->map.init_x, fcoords[1] + \
				data->map.init_y, add_shade(0.9, (unsigned int)color[0]));
		else
			my_mlx_pixel_put(data, fcoords[0] + data->map.init_x, fcoords[1] + \
				data->map.init_y, color[0]);
	// }
	// else
	// {

	// }
}

void	bresenham(float *coords, float x1, float y1, t_all *data)
{
	float	*fcoords;
	float	add_x;
	float	add_y;
	int		max;
	int		*color;

	fcoords = ft_calloc(2, sizeof(float));
	ft_memcpy(fcoords, coords, 2 * sizeof(float));
	color = set_color(fcoords, x1, y1, data);
	set_zoom(fcoords, &x1, &y1, data->map.zoom);
	set_proyection(fcoords, &x1, &y1, data);
	add_x = x1 - fcoords[0]; // 2
	add_y = y1 - fcoords[1]; // 1
	max = ft_max_value(fabs(add_x), fabs(add_y)); // 2
	add_x /= max; // 1
	add_y /= max; // 0.5
	while ((int)(fcoords[0] - x1) || (int)(fcoords[1] - y1))
	{
		print_pixel(max, fcoords, color, data);
		fcoords[0] += add_x;
		fcoords[1] += add_y;
	}
	free(fcoords);
	free(color);
}


//[4, 12][2, 13]