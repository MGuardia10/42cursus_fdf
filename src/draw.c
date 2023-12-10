/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:55:34 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 20:35:16 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

static void	draw_background(t_all *data)
{
	int	*img;
	int	i;

	ft_bzero(data->addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	img = (int *)(data->addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < MENU_WIDTH)
			img[i] = MENU_COLOR;
		else
			img[i] = BG_COLOR;
		i++;
	}
}

static void	set_properties(float *fcoords, float *x1, float *y1, t_all *data)
{
	set_color(fcoords, (int)*x1, (int)*y1, data);
	if (data->map.proyection == ISO)
	{
		isometric(&fcoords[0], &fcoords[1], data);
		isometric(x1, y1, data);
	}
	else
		set_zoom(fcoords, x1, y1, data->map.zoom);
}

static void	print_pixel(float max, float *fcoords, t_color *color, t_all *data)
{
	static float	ratio;
	float			step;
	int				gradient;

	if (data->map.is_line_finish == true)
	{
		ratio = 0;
		data->map.is_line_finish = false;
	}
	gradient = set_gradient(color[0], color[1], ratio);
	step = 1 / max;
	ratio += step;
	if (fcoords[0] + data->map.init_x <= MENU_WIDTH)
		my_mlx_pixel_put(data, fcoords[0] + data->map.init_x, fcoords[1] + \
			data->map.init_y, add_shade(0.9, gradient));
	else
		my_mlx_pixel_put(data, fcoords[0] + data->map.init_x, fcoords[1] + \
			data->map.init_y, gradient);
}

static void	bresenham(float *coords, float x1, float y1, t_all *data)
{
	float	*fcoords;
	float	step_x;
	float	step_y;
	int		max;

	fcoords = ft_calloc(2, sizeof(float));
	if (!fcoords)
		return (malloc_err(data));
	ft_memcpy(fcoords, coords, 2 * sizeof(float));
	set_properties(fcoords, &x1, &y1, data);
	step_x = x1 - fcoords[0];
	step_y = y1 - fcoords[1];
	max = ft_max_value(fabs(step_x), fabs(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(fcoords[0] - x1) || (int)(fcoords[1] - y1))
	{
		print_pixel(max, fcoords, data->map.curr_colors, data);
		fcoords[0] += step_x;
		fcoords[1] += step_y;
	}
	data->map.is_line_finish = true;
	free(fcoords);
}

void	draw(t_all *data)
{
	float	coords[2];

	draw_background(data);
	coords[1] = 0;
	while (coords[1] < data->map.max_y)
	{
		coords[0] = 0;
		while (coords[0] < data->map.max_x)
		{
			if (coords[0] < data->map.max_x - 1)
				bresenham(coords, coords[0] + 1, coords[1], data);
			if (coords[1] < data->map.max_y - 1)
				bresenham(coords, coords[0], coords[1] + 1, data);
			coords[0]++;
		}
		coords[1]++;
	}
	put_last_pixel(--coords[0], --coords[1], data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	draw_menu(data);
}
